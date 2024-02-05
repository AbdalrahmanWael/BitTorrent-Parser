#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bencode.h"  

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s decode <Bencode_string>\n", argv[0]);
        return 1;
    }

    const char *command = argv[1];
    const char *bencodeData = argv[2];

    if (strcmp(command, "decode") == 0) {
        // Parse Bencode data
        Bencode* result = parse_bencode(bencodeData);

        // Check if parsing was successful
        if (result != NULL) {
            // Print the parsed Bencode data
            printf("Parsed Bencode:\n");

            if(result->type == BENCODE_STRING) {
              printf("%s \n", result->str_val);
            }
            else if (result->type == BENCODE_INTEGER) {
              printf("%lld   \n", result->int_val);
            }
            else if (result->type == BENCODE_LIST) {
              printf("LIST PARSED");
            }
            else {
              printf("Unsupported\n");
            }

            free_bencode(result);
        } else {
            printf("Error parsing Bencode data\n");
        }
    } else {
        printf("Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}
