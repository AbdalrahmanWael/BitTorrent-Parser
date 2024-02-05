
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_bencoded_integer(const char* str) {
  int length = strlen(str);

  if(str[0] != 'i') {
    return false;
  }

  if (str[length - 1] != 'e'){
    return false;
  }

  if (!(str[1] == '-' || is_digit(str[1])) ) {
    return false;
  }

  for(int i = 2; i < length - 1; i++) {
    if(!is_digit(str[i])){
      return false;
    }
  }

  return true;
}

char* decode_str(const char* bencoded_value) {
  int length = atoi(bencoded_value);
  const char* colon_index = strchr(bencoded_value, ':');
  if (colon_index != NULL) {
    const char* start = colon_index + 1;
    char* decoded_str = (char*)malloc(length + 1);
    strncpy(decoded_str, start, length);
    decoded_str[length] = '\0';
    return decoded_str;
  } else {
    fprintf(stderr, "Invalid encoded value: %s\n", bencoded_value);
    exit(1);
  }
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

char* decode_integer(const char* bencoded_value){

  const char* start = strchr(bencoded_value, 'i') + 1;
  const char* end = strchr(bencoded_value, 'e');

  int len = end - start;

  char* integer_str = malloc(len + 1);

  strncpy(integer_str, start, len);
  integer_str[len] = '\0';

  return integer_str;
}

char* decode_list(const char* bencoded_value) {
  const char* start = strchr(bencoded_value, 'l') + 1;
  const char* end = strchr(start, 'e');

  if(end == NULL) {
    return NULL;
  }
  
  size_t total_length = 2 + (end - start) * 3 + 1;
  char* decoded_str = malloc(total_length);
  
  strcpy(decoded_str, "[");
  char* current_pos = decoded_str + 1;

  while (start < end) {
    printf("start at %s \n", start);
    if (*start == 'i') {
      
      printf("mannn1 \n");
      char* integer_str = decode_integer(start);

      printf("mannn \n");
      sprintf(current_pos, "%s", integer_str);
      free(integer_str);
    } else if (*start == 'l') {
      char* nested_list_str = decode_list(start);
      sprintf(current_pos, "%s", nested_list_str);
      free(nested_list_str);
    } else {
      char* decoded_str = decode_str(start);
      sprintf(current_pos, "\"%s\"", decoded_str);
      free(decoded_str);
    }

    current_pos += strlen(current_pos);
    if (start < end - 1) {
      *current_pos++ = ',';
      *current_pos++ = ' ';
    }

    start += strlen(start) + 1;
  }

  *current_pos++ = ']';
  *current_pos++ = '\0';
  
  return decoded_str;
}

char* decode_bencode(const char* bencoded_value) {
  if (is_digit(bencoded_value[0])) {
    return decode_str(bencoded_value);
  }
  if (is_bencoded_integer(bencoded_value)) {
    return decode_integer(bencoded_value);
  }
  if (is_bencoded_list(bencoded_value)) {
    return decode_list(bencoded_value);
  }

  return NULL;
}

int maaaain(int argc, char* argv[]) {

    if (argc < 3) {
        fprintf(stderr, "Usage: your_bittorrent.sh <command> <args>\n");
        return 1;
    }

    const char* command = argv[1];

    if (strcmp(command, "decode") == 0) {
          
        const char* encoded_str = argv[2];
        char* decoded_str = decode_bencode(encoded_str);
        if(is_bencoded_integer(encoded_str) || is_bencoded_list(encoded_str)){
          printf("%s\n", decoded_str);
          free(decoded_str);
          return 0;
        }

        printf("\"%s\"\n", decoded_str);
        free(decoded_str);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}

