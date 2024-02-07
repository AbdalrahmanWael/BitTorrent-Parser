// bencode.c
#include "../include/bencode.h"
#include <stdlib.h>
#include <string.h>

// Functions for creating Bencode elements

Bencode* create_bencode_integer(long long value) {
    Bencode* new_element = (Bencode*)malloc(sizeof(Bencode));
    if (new_element != NULL) {
        new_element->type = BENCODE_INTEGER;
        new_element->int_val = value;
    }
    return new_element;
}

Bencode* create_bencode_string(const char* value) {
    Bencode* new_element = (Bencode*)malloc(sizeof(Bencode));
    if (new_element != NULL) {
        new_element->type = BENCODE_STRING;
        new_element->str_val = strdup(value);  // Duplicate the string
    }
    return new_element;
}

Bencode* create_bencode_list(void) {
    Bencode* new_element = (Bencode*)malloc(sizeof(Bencode));
    if (new_element != NULL) {
        new_element->type = BENCODE_LIST;
        new_element->list_val = NULL;  // Initialize the list as empty
    }
    return new_element;
}

Bencode* create_bencode_dict(void) {
    Bencode* new_element = (Bencode*)malloc(sizeof(Bencode));
    if (new_element != NULL) {
        new_element->type = BENCODE_DICT;
        new_element->dict_val = NULL;  // Initialize the dictionary as empty
    }
    return new_element;
}

BencodeList* create_bencode_list_entry(Bencode* value) {
    BencodeList* entry = (BencodeList*)malloc(sizeof(BencodeList));
    if (entry != NULL) {
        entry->value = value;
        entry->next = NULL;
        return entry;
    }
    return NULL;
}
BencodeDict* create_bencode_dict_entry(const char* key, Bencode* value) {
    BencodeDict* entry = (BencodeDict*)malloc(sizeof(BencodeDict));
    if (entry != NULL) {
        entry->key = strdup(key);
        entry->value = value;
        entry->next = NULL;
    }
    return entry;
}

// Functions for adding elements to lists and dictionaries

void add_to_bencode_list(BencodeList** list, Bencode* value) {
    if (list == NULL || value == NULL) {
      return;
    }
    if (*list == NULL) {
      *list = create_bencode_list_entry(value);
    }
    else {
        BencodeList* last = *list;
        while (last->next != NULL) {
            last = last->next;
        }

        // Create a new entry
        BencodeList* new_entry = create_bencode_list_entry(value);
        if (new_entry != NULL) {
            // Add the new entry to the end of the list
            last->next = new_entry;
    }
  }
}


void add_to_bencode_dict(BencodeDict** dict, const char* key, Bencode* value) {
    if (dict == NULL || key == NULL || value == NULL) {
        // Invalid input, handle error or return
        return;
    }

    // Check if the dictionary is empty
    if (*dict == NULL) {
        *dict = create_bencode_dict_entry(key, value);
    } else {
        // Find the last entry in the dictionary
        BencodeDict* last = *dict;
        while (last->next != NULL) {
            last = last->next;
        }

        // Create a new entry
        BencodeDict* new_entry = create_bencode_dict_entry(key, value);
        if (new_entry != NULL) {
            // Add the new entry to the end of the dictionary
            last->next = new_entry;
        }
    }
}

// Function for retrieving elements from dictionaries

Bencode* get_value_by_key(BencodeDict* dictionary, const char* key) {
    if (dictionary == NULL || key == NULL) {
        // Invalid input, handle error or return NULL
        return NULL;
    }

    // Traverse the linked list and find the value associated with the key
    BencodeDict* current = dictionary;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Key found, return the associated value
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return NULL;
}

// Functions for determining Type of Bencoded value

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_bencoded_integer(const char* str) {
  char* end = strchr(str, 'e');
  if (end == NULL) {
    return false;
  }
  int len = end - str;

  char* integer_str = malloc(len + 2);

  if(str[0] != 'i') {
    return false;
  }

  if (str[len] != 'e'){
    return false;
  }

  if (!(str[1] == '-' || is_digit(str[1])) ) {
    return false;
  }

  for(int i = 2; i < len; i++) {
    if(!is_digit(str[i])){
      return false;
    }
  }

  return true;
}

bool is_bencoded_list(const char* str) {

  int length = strlen(str);

  if(str[0] != 'l'){
    return false;
  }
  if(str[length - 1] != 'e'){
    return false;
  }

  return true;
}

// Function to parse any Bencode type from the input data

Bencode* parse_bencode(const char* data, const char** end) {
    if (data == NULL || *data == '\0') {
        // Invalid input data
        return NULL;
    }

    Bencode* result = (Bencode*)malloc(sizeof(Bencode));
    if (result == NULL) {
        // Memory allocation failure
        return NULL;
    }

  if (is_digit(data[0])) {
    // printf("\nString Has BEEN HIT\n");
    return parse_bencode_string(data, end);
  }
  else if (is_bencoded_integer(data)) {
    // printf("\nINT HAS BEEN HIT \n");
    return parse_bencode_integer(data, end);
  }
  else if (is_bencoded_list(data)) {
    // printf("\nLIST HAS BEEN HIT \n");
    return parse_bencode_list(data, end);
  }
  else {
    printf("UNSUPPORTED TYPE\n");
    printf("%s\n", data);
  }
  return result;
}


Bencode* parse_bencode_integer(const char* bencoded_value, const char** endpos) {
    Bencode* result = (Bencode*)malloc(sizeof(Bencode));
    if (result == NULL) {
        // Memory allocation failure
        return NULL;
    }
   
    char* start = strchr(bencoded_value, 'i') + 1;
    char* end = strchr(bencoded_value, 'e');
  
    int len = end - start;

    char* integer_str = malloc(len + 2);

    strncpy(integer_str, start, len);
    integer_str[len] = '\0';    
    result->int_val = strtol(integer_str, &end, 10);
    result->type = BENCODE_INTEGER;
  
    if (endpos != NULL) {
        *endpos = start + len + 1;
    }
    return result;
}

Bencode* parse_bencode_string(const char* bencoded_value, const char** end) {
    Bencode* result = (Bencode*)malloc(sizeof(Bencode));
    if (result == NULL) {
        // Handle memory allocation error
        return NULL;
    }
  
    int length = atoi(bencoded_value);
    const char* colon_index = strchr(bencoded_value, ':');
    if (colon_index == NULL || length == 0){
      free(result);
      return NULL;
    }
    result->type = BENCODE_STRING;
  
    const char* start = colon_index + 1;
    char* decoded_str = (char*)malloc(length + 1);
    strncpy(decoded_str, start, length);
    decoded_str[length] = '\0';

    result->str_val = (char*)malloc(length + 1);
    if (result->str_val == NULL) {
        // Handle memory allocation error
        free(result);
        return NULL;
    }
    strncpy(result->str_val, decoded_str, length);
    result->str_val[length] = '\0';
    result->length = length;
    if (result->str_val == NULL) {
        // Handle memory allocation error
        free(result);
        return NULL;
    }
    if (end != NULL) {
      *end = start + result->length;
    }
    return result;
}


Bencode* parse_bencode_list(const char* data, const char** endpos) {
    if (data == NULL || *data != 'l') {
        // Invalid list format
        return NULL;
    }

    // Move past 'l'
    data++;
    
    const char* end = data;

    Bencode* result = create_bencode_list();
    if (result == NULL) {
        // Memory allocation failure
        return NULL;
    }
    
    while (*data != 'e') {
        
        const char* element_end = NULL;
        Bencode* element = parse_bencode(data, &element_end);
        if (element == NULL) {
            // Parsing error, free allocated memory
            free_bencode(result);
            return NULL;
        }

        // Add the element to the list
        add_to_bencode_list(&(result->list_val), element);

        data = element_end;
    }

    // Move past 'e'
    data++;
    if(endpos != NULL) {
      *endpos = data;
    }
    return result;
}

Bencode* parse_bencode_dict(const char* data, BencodeDict** value, const char** end) {
    return NULL;
    // TODO: FIX

     // Mov // Mov
    if (data == NULL || *data != 'd') {
        // Invalid dictionary format
        return NULL;
    }

    // Move past 'd'
    data++;

    Bencode* result = create_bencode_dict();
    if (result == NULL) {
        // Memory allocation failure
        return NULL;
    }

    BencodeDict* current = result->dict_val;

    while (*data != 'e') {
        // Parse the key
        char* key = NULL;
        data = parse_bencode_string(data, NULL)->str_val;

        if (key == NULL) {
            // Parsing error, free allocated memory
            free_bencode(result);
            return NULL;
        }

        // Parse the value
        Bencode* value = parse_bencode(data, NULL);
        if (value == NULL) {
            // Parsing error, free allocated memory
            free(key);
            free_bencode(result);
            return NULL;
        }

        // Add key-value pair to the dictionary
        add_to_bencode_dict(&(result->dict_val), key, value);

        // Move to the next dictionary entry
        current = result->dict_val;

        // Move to the next element in the dictionary
        current = current->next;
    }

    // Move past 'e'
    data++;


    // Set the end pointer if provided
    if (end != NULL) {
        *end = data;
    }

    return result;
}


// Memory management functions

void free_bencode(Bencode* element) {
    if (element != NULL) {
        switch (element->type) {
            case BENCODE_STRING:
                free(element->str_val);
                break;
            case BENCODE_LIST:
                // Implement freeing logic for list elements
                break;
            case BENCODE_DICT:
                free_bencode_dict(element->dict_val);
                break;
            default:
                // No additional memory to free for other types
                break;
        }
        free(element);
    }
}

void free_bencode_dict(BencodeDict* dict) {
    while (dict != NULL) {
        BencodeDict* temp = dict;
        dict = dict->next;

        // Free memory for key and value
        free(temp->key);
        free_bencode(temp->value);

        // Free memory for the dictionary entry
        free(temp);
    }
}

// Utility Functions

void print_bencode(Bencode* element) {
    if (element == NULL) {
        printf("NULL\n");
        return;
    }

    switch (element->type) {
        case BENCODE_INTEGER:
            printf("%lld\n", element->int_val);
            break;
        case BENCODE_STRING:
            printf("%s\n", element->str_val);
            break;
        case BENCODE_LIST: {
            printf("[ ");
            BencodeList* current = element->list_val;
            while (current != NULL) {
                print_bencode(current->value);
                printf(", ");
                current = current->next;
            }
            printf("]\n");
            break;
        }
        case BENCODE_DICT: {
            printf("{ ");
            BencodeDict* current = element->dict_val;
            while (current != NULL) {
                printf("\"%s\": ", current->key);
                print_bencode(current->value);
                printf(", ");
                current = current->next;
            }
            printf("}\n");
            break;
        }
        default:
            printf("Unsupported\n");
    }
}

