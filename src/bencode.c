// bencode.c
#include "../include/bencode.h"
#include <stdbool.h>
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
        new_element->length = 0;    
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

// Temporarily Using to check if it's a dictionary

bool is_bencoded_list(const char* str, int length) {
  length = 0;
  while (str[length] != 'e') {
    length++;
  }

  if(str[0] != 'l'){
    return false;
  }
  //if(str[length - 1] != 'e'){
    //return false;
  //}

  return true;
}

// Temporarily Using to check if it's a dictionary
bool is_bencoded_dict(const char* str, int length) {
  length = 0;
  while (str[length] != 'e') {
    length++;
  }
  
  if(str[0] != 'd'){
    return false;
  }
  //if(str[length - 1] != 'e'){
  //  return false;
  //}

  return true;
}

bool iis_bencoded_dict(const char* str) {
    // TODO: FIX
    if (str == NULL || *str != 'd') {
        // Invalid or empty input or not starting with 'd'
        printf("Invalid or empty input or not starting with 'd'\n");
        return false;
    }

    int length = strlen(str);
    if (length < 2 || str[length - 1] != 'e') {
        // Dictionary doesn't end with 'e'
        printf("Dictionary doesn't end with 'e'\n");
        return false;
    }

    // Iterate through the string to ensure correct format
    const char* ptr = str + 1; // Skip the 'd' at the beginning
    while (*ptr != 'e') {
        // Each key must be a bencoded string
        if (!is_digit(*ptr)) {
            printf("Each key must be a bencoded string\n");
            return false;
        }

        // Find the end of the key
        const char* colon = strchr(ptr, ':');
        if (colon == NULL) {
            // Colon not found
            printf("Colon not found\n");
            return false;
        }

        // Extract the length of the key
        int key_length = atoi(ptr);
        if (key_length <= 0) {
            // Invalid key length
            printf("Invalid key length\n");
            return false;
        }

        // Move the pointer to the beginning of the key
        ptr = colon + 1;
        //printf("\n Start of the key %s\n", ptr);
        // Move the pointer to the end of the key
        ptr += key_length ;
        //printf("\nEnd of the key %s\n", ptr);

        // Move the pointer to the value
        // ptr++;

        // Recursively check if the value is valid
        if (!is_bencoded_dict(ptr,0) && !is_bencoded_list(ptr,0) && !is_bencoded_integer(ptr) && !is_digit(*ptr)) {
            printf("Invalid value\n");
            printf("\n THE VALUE: %s \n", ptr);
            return false;
        }

        // Move the pointer to the next key or 'e' if it's the last element
        while (*ptr != 'e' && !is_digit(*ptr)) {
            ptr += key_length;
        }
    }

    // If we reach here, the dictionary format is correct
    printf("Dictionary format is correct\n");
    return true;
}



// Function to parse any Bencode type from the input data

Bencode* parse_bencode(const char* data, const char** end, int length) {
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
    else if (is_bencoded_list(data, length)) {
      // printf("\nLIST HAS BEEN HIT \n");
      return parse_bencode_list(data, end, length);
      //printf("\nLIST HAS BEEN Closed \n");
    }
    else if (is_bencoded_dict(data, length)){
      // printf("\nDict Has Been Hit\n");
      return parse_bencode_dict(data, end, length);
      
    }
    else {
      printf("UNSUPPORTED TYPE\n");
      printf("%s\n", data);
      return NULL;
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
    // printf("length %d\n", length);
    const char* colon_index = strchr(bencoded_value, ':');
    if (colon_index == NULL){
      free(result);
      return NULL;
    }
    
    result->type = BENCODE_STRING;
    if (length == 0){
      result->length = 0;
      if (end != NULL) {
        *end = colon_index + 1;
      }

      return result;
    }
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
    // printf("string parsed: %s \n", result->str_val);
    return result;
}


Bencode* parse_bencode_list(const char* data, const char** endpos, int length) {
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
        Bencode* element = parse_bencode(data, &element_end, length);
        if (element == NULL) {
            // Parsing error, free allocated memory
            free_bencode(result);
            return NULL;
        }

        // Add the element to the list
        add_to_bencode_list(&(result->list_val), element);
        result->length++;
        data = element_end;
        length = length - (end - data);
    }

    // Move past 'e'
    data++;
    if(endpos != NULL) {
      *endpos = data;
    }
    return result;
}

Bencode* parse_bencode_dict(const char* data, const char** end, int length) {
   
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
        const char* element_end = NULL;
        
        // Parse the key
        char* key = NULL;
        Bencode* element = parse_bencode_string(data, &element_end);
        
        data = element_end;
        key = element->str_val;
        if (key == NULL) {
            // Parsing error, free allocated memory
            free_bencode(result);
            return NULL;
        }
        length = length - (element_end - data);

        // Parse the value
        Bencode* value = parse_bencode(data, &element_end, length);
        if (value == NULL) {
            // Parsing error, free allocated memory
            free(key);
            free_bencode(result);
            return NULL;
        }

        // Add key-value pair to the dictionary
        add_to_bencode_dict(&(result->dict_val), key, value);
        
        data = element_end;  
        length = length - (element_end - data);
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
            if(element->length == 0){
              printf("NULL String\n");
            }else {
              printf("%s\n", element->str_val);
            }
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

size_t get_list_length(BencodeList* list) {
    size_t length = 0;
    while (list != NULL) {
        length++;
        list = list->next;
    }
    return length;
}
