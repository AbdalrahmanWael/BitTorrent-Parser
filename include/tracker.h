
#ifndef TRACKER_H
#define TRACKER_H

#include "peer.h" 

// Structure to represent a tracker response
typedef struct TrackerResponse {
    int interval;            // Interval (in seconds) at which the client should re-request the tracker
    int complete;            // Number of seeders (peers with the complete file)
    int incomplete;          // Number of leechers (peers with an incomplete file)
    int num_peers;           // Number of peers in the response
    PeerInfo* peers;         // Array of peers in the response
} TrackerResponse;

// Function to send an announce request to the tracker
TrackerResponse* announce_to_tracker(const char* announce_url, const char* info_hash,
                                     const char* peer_id, uint64_t downloaded,
                                     uint64_t uploaded, uint64_t left, int port);

// Function to parse a tracker response
TrackerResponse* parse_tracker_response(const char* response);

// Function to free memory allocated for a tracker response
void free_tracker_response(TrackerResponse* response);

#endif 

