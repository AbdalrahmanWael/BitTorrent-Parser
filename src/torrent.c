#include "../include/torrent.h"
#include "../include/bencode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* get_string_from_dict(BencodeDict* dict, const char* key) {
    Bencode* value = get_value_by_key(dict, key);
    if (value != NULL && value->type == BENCODE_STRING) {
        return strdup(value->str_val);
    }
    return NULL;
}

static uint64_t get_integer_from_dict(BencodeDict* dict, const char* key) {
    Bencode* value = get_value_by_key(dict, key);
    if (value != NULL && value->type == BENCODE_INTEGER) {
        return (uint64_t)value->int_val;
    }
    return 0;
}
// TODO: FIX BUGS
TorrentMetadata* parse_torrent_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s' for reading.\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* file_content = (char*)malloc(file_size + 1);
    if (file_content == NULL) {
        fclose(file);
        fprintf(stderr, "Error: Failed to allocate memory for file content.\n");
        return NULL;
    }

    size_t bytes_read = fread(file_content, 1, file_size, file);
    file_content[bytes_read] = '\0';
    printf("\nNumber of bytes read %zu\n", bytes_read);
    fclose(file);
    printf("\n\n\nFile Content\n %s \n\n\n", file_content);
    const char* end_pos;
    Bencode* parsed_data = parse_bencode(file_content, &end_pos);
    if (parsed_data == NULL) {
        fprintf(stderr, "\nError: Failed to parse torrent file.\n");
        free(file_content);
        return NULL;
    }
    printf("\nHMMM\n");
    BencodeDict* info_dict = get_value_by_key(parsed_data->dict_val, "info")->dict_val;
    TorrentMetadata* metadata = (TorrentMetadata*)malloc(sizeof(TorrentMetadata));
    if (metadata == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for metadata.\n");
        free_bencode(parsed_data);
        free(file_content);
        return NULL;
    }

    metadata->announce = get_string_from_dict(parsed_data->dict_val, "announce");
    metadata->creation_date = get_integer_from_dict(parsed_data->dict_val, "creation date");
    metadata->comment = get_string_from_dict(parsed_data->dict_val, "comment");
    metadata->created_by = get_string_from_dict(parsed_data->dict_val, "created by");

    metadata->info.piece_length = get_integer_from_dict(info_dict, "piece length");
    metadata->info._private = get_integer_from_dict(info_dict, "private");

    Bencode* name_entry = get_value_by_key(info_dict, "name");
    if (name_entry != NULL && name_entry->type == BENCODE_STRING) {
        metadata->mode = SINGLE_FILE_MODE;
        metadata->single_file.name = strdup(name_entry->str_val);
        metadata->single_file.length = get_integer_from_dict(info_dict, "length");
    } else {
        metadata->mode = MULTI_FILE_MODE;
        metadata->multi_file.name = get_string_from_dict(info_dict, "name");

        BencodeList* files_list = get_value_by_key(info_dict, "files")->list_val;
        int num_files = 0;
        while (files_list != NULL) {
            num_files++;
            files_list = files_list->next;
        }
        metadata->multi_file.num_files = num_files;

        metadata->multi_file.files = (TorrentFile*)malloc(num_files * sizeof(TorrentFile));
        if (metadata->multi_file.files == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for files in multi-file mode.\n");
            free(metadata->multi_file.name);
            free(metadata->announce);
            free(metadata->comment);
            free(metadata->created_by);
            free(metadata);
            free_bencode(parsed_data);
            free(file_content);
            return NULL;
        }

        files_list = get_value_by_key(info_dict, "files")->list_val;
        for (int i = 0; i < num_files; i++) {
            BencodeDict* file_dict = files_list->value->dict_val;
            metadata->multi_file.files[i].length = get_integer_from_dict(file_dict, "length");
            metadata->multi_file.files[i].md5sum = get_string_from_dict(file_dict, "md5sum");
            metadata->multi_file.files[i].name = get_string_from_dict(file_dict, "name");
            files_list = files_list->next;
        }
    }

    free_bencode(parsed_data);
    free(file_content);

    return metadata;
}

void free_torrent_metadata(TorrentMetadata* metadata) {
    if (metadata != NULL) {
        free(metadata->announce);
        free(metadata->comment);
        free(metadata->created_by);

        if (metadata->mode == SINGLE_FILE_MODE) {
            free(metadata->single_file.name);
        } else {
            free(metadata->multi_file.name);
            for (int i = 0; i < metadata->multi_file.num_files; i++) {
                free(metadata->multi_file.files[i].name);
                free(metadata->multi_file.files[i].md5sum);
            }
            free(metadata->multi_file.files);
        }

        free(metadata);
    }
}

void print_torrent_metadata(TorrentMetadata* metadata) {
    if (metadata == NULL) {
        printf("Torrent metadata is NULL.\n");
        return;
    }

    printf("Announce: %s\n", metadata->announce);
    printf("Creation Date: %llu\n", metadata->creation_date);
    printf("Comment: %s\n", metadata->comment);
    printf("Created By: %s\n", metadata->created_by);

    printf("Info:\n");
    printf("  Piece Length: %llu\n", metadata->info.piece_length);
    printf("  Private: %llu\n", metadata->info._private);

    if (metadata->mode == SINGLE_FILE_MODE) {
        printf("  Mode: Single File\n");
        printf("  Name: %s\n", metadata->single_file.name);
        printf("  Length: %llu\n", metadata->single_file.length);
    } else {
        printf("  Mode: Multi-File\n");
        printf("  Name: %s\n", metadata->multi_file.name);
        printf("  Number of Files: %zu\n", metadata->multi_file.num_files);
        for (size_t i = 0; i < metadata->multi_file.num_files; i++) {
            printf("    File %zu:\n", i + 1);
            printf("      Name: %s\n", metadata->multi_file.files[i].name);
            printf("      Length: %llu\n", metadata->multi_file.files[i].length);
            printf("      MD5sum: %s\n", metadata->multi_file.files[i].md5sum);
        }
    }
}
