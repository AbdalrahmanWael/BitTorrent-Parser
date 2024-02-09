#ifndef TORRENT_H
#define TORRENT_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define MAX_PATH_LENGTH 256
#define MAX_MD5_LENGTH 33

// Enumeration for file modes
typedef enum {
    SINGLE_FILE_MODE,
    MULTI_FILE_MODE
} FileMode;

// Define structures for torrent metadata
typedef struct {
    // piece length: number of bytes in each piece (integer)
    uint64_t piece_length;             
    // pieces: string consisting of the concatenation of all 20-byte SHA1 hash values,
    // one per piece (byte string, i.e. not urlencoded)
    char* pieces;                      
    // private: (optional) this field is an integer. If it is set to "1", the client MUST publish its presence 
    // to get other peers ONLY via the trackers explicitly described in the metainfo file. If this field is set to "0" 
    // or is not present, the client may obtain peer from other means, e.g. PEX peer exchange, dht.
    // Here, "private" may be read as "no external peer source".
    uint64_t _private;
} TorrentInfo;

typedef struct {
    // name: the filename. This is purely advisory. (string)
    char* name;                     
    
    // length: length of the file in bytes (integer)
    uint64_t length;                
    
    // md5sum: (optional) a 32-character hexadecimal string corresponding to the MD5 sum of the file.
    // This is not used by BitTorrent at all, but it is included by some programs for greater compatibility.
    char* md5sum;                   
} TorrentFile;

typedef struct {
    // name: the name of the directory in which to store all the files. This is purely advisory. (string)
    char* name;                     
    
    // number of files in the multi-file mode
    size_t num_files;               
    
    // a list of dictionaries, one for each file
    TorrentFile* files;            
} MultiFileInfo;

typedef struct {
    // announce: The announce URL of the tracker (string)
    char* announce;                 
    
    // announce-list: (optional) this is an extension to the official specification,
    // offering backwards-compatibility. (list of lists of strings)
    char*** announce_list;          
    
    // number of announce URLs in the announce-list
    size_t num_announce;            
    
    // creation date: (optional) the creation time of the torrent, in standard UNIX epoch format
    // (integer, seconds since 1-Jan-1970 00:00:00 UTC)
    time_t creation_date;           
    
    // comment: (optional) free-form textual comments of the author (string)
    char* comment;                  
    
    // created by: (optional) name and version of the program used to create the .torrent (string)
    char* created_by;               
    
    // encoding: (optional) the string encoding format used to generate the pieces part of the info dictionary 
    // in the .torrent metafile (string)
    char* encoding;                 
    
    // Info Dictionary (common to both single and multi-file modes)
    TorrentInfo info;               
    
    // file mode: either SINGLE_FILE_MODE or MULTI_FILE_MODE
    FileMode mode;                  
    
    // Info in Single File Mode
    union {
      // Info in Single File Mode
      TorrentFile single_file;

      // Info in Multiple File Mode
      MultiFileInfo multi_file;
    };                   
   
} TorrentMetadata;

TorrentMetadata* parse_torrent_file(const char* filename);
void free_torrent_metadata(TorrentMetadata* metadata);
void print_torrent_metadata(TorrentMetadata* metadata);

#endif
