#ifndef BENCODE_H
#define BENCODE_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    BENCODE_INTEGER,
    BENCODE_STRING,
    BENCODE_LIST,
    BENCODE_DICT
} BencodeType;

typedef struct Bencode {
    BencodeType type;
    union {
        long long int_val;
        char* str_val;
        struct BencodeList* list_val;
        struct BencodeDict* dict_val;
    };
    int length;
} Bencode;

typedef struct BencodeList {
    Bencode* value;
    struct BencodeList* next;
} BencodeList;

typedef struct BencodeDict {
    char* key;
    Bencode* value;
    char* bencoded_value;
    struct BencodeDict* next;

} BencodeDict;

// Functions for creating Bencode elements
Bencode* create_bencode_integer(long long value);
Bencode* create_bencode_string(const char* value);
Bencode* create_bencode_list(void);
Bencode* create_bencode_dict(void);
BencodeDict* create_bencode_dict_entry(const char* key, Bencode* value);

// Functions for adding elements to lists and dictionaries
void add_to_bencode_list(BencodeList** list, Bencode* value);
void add_to_bencode_dict(BencodeDict** dict, const char* key, Bencode* value);

// Function for retrieving elements from dictionaries
Bencode* get_value_by_key(BencodeDict* dictionary, const char* key);
uint64_t get_integer_from_dict(BencodeDict* dict, const char* key);
char* get_string_from_dict(BencodeDict* dict, const char* key);

// Functions for parsing Bencode from strings
Bencode* parse_bencode(const char* data, const char** end, int length);
Bencode* parse_bencode_integer(const char* bencoded_value, const char** end);
Bencode* parse_bencode_string(const char* bencoded_value, const char** end);
Bencode* parse_bencode_list(const char* data, const char** endpos, int length);
Bencode* parse_bencode_dict(const char* data, const char** end, int length);

// Functions for determining Type of Bencoded value
bool is_bencoded_list(const char* str, int length);

// Memory management functions
void free_bencode(Bencode* element);
void free_bencode_dict(BencodeDict* dict);

// Utility Functions

void print_bencode(Bencode* element);
size_t get_list_length(BencodeList* list);

#endif

