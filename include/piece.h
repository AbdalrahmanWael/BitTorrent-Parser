#ifndef PIECE_H
#define PIECE_H

#include <stdbool.h>
#include <stdint.h>

// Structure to represent a piece of the torrent file
typedef struct Piece {
    uint32_t index;         // Index of the piece
    uint32_t length;        // Length of the piece
    uint8_t* data;          // Data of the piece
} Piece;

// Function to create a new piece
Piece* create_piece(uint32_t index, uint32_t length);

// Function to destroy a piece and free memory
void destroy_piece(Piece* piece);

// Function to check if a piece is complete
bool is_piece_complete(const Piece* piece);

// Function to write data to a piece
bool write_to_piece(Piece* piece, uint32_t offset, const uint8_t* data, uint32_t size);

// Function to read data from a piece
bool read_from_piece(const Piece* piece, uint32_t offset, uint8_t* buffer, uint32_t size);

#endif 

