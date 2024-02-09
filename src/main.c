#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bencode.h"
#include "../include/torrent.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [decode <Bencode_string>] [parse <torrent_file>]\n", argv[0]);
        return 1;
    }
    
    const char *command = argv[1];

    if (strcmp(command, "decode") == 0) {
        if (argc != 3) {
            printf("Usage: %s decode <Bencode_string>\n", argv[0]);
            return 1;
        }
        
        const char *bencodeData = argv[2];

        // Parse Bencode data
        Bencode* result = parse_bencode(bencodeData, NULL, 0);

        // Check if parsing was successful
        if (result != NULL) {
            // Print the parsed Bencode data
            printf("Parsed Bencode:\n");
            print_bencode(result);
            free_bencode(result);
        } else {
            printf("Error parsing Bencode data\n");
        }
    } else if (strcmp(command, "parse") == 0) {
        if (argc != 3) {
            printf("Usage: %s parse <torrent_file>\n", argv[0]);
            return 1;
        }

        const char* torrentFile = argv[2];

        // Parse torrent file
        TorrentMetadata* metadata = parse_torrent_file(torrentFile);

        // Check if parsing was successful
        if (metadata != NULL) {
            // Print the parsed metadata
            printf("Parsed Torrent Metadata:\n");
            print_torrent_metadata(metadata);
            free_torrent_metadata(metadata);
        } else {
            printf("Error parsing torrent file\n");
        }
    } else {
        printf("Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}
