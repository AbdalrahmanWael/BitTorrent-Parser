#include "../include/piece.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h> 

Piece* create_piece(uint32_t index, uint32_t length, const uint8_t* hash) {
    Piece* piece = (Piece*)malloc(sizeof(Piece));
    if (piece == NULL) return NULL;

    piece->index = index;
    piece->length = length;
    piece->data = (uint8_t*)malloc(length);
    if (piece->data == NULL) {
        free(piece);
        return NULL;
    }
    memset(piece->data, 0, length);  // Initialize piece data with zeros

    piece->hash = (uint8_t*)malloc(SHA_DIGEST_LENGTH);
    if (piece->hash == NULL) {
        free(piece->data);
        free(piece);
        return NULL;
    }
    memcpy(piece->hash, hash, SHA_DIGEST_LENGTH);

    piece->is_complete = false;
    piece->is_verified = false;

    return piece;
}

void destroy_piece(Piece* piece) {
    if (piece != NULL) {
        free(piece->data);
        free(piece->hash);
        free(piece);
    }
}

bool is_piece_complete(const Piece* piece) {
    return piece->is_complete;
}

bool is_piece_verified(const Piece* piece) {
    return piece->is_verified;
}

bool write_to_piece(Piece* piece, uint32_t offset, const uint8_t* data, uint32_t size) {
    if (offset + size > piece->length) return false;
    memcpy(piece->data + offset, data, size);
    if (offset + size == piece->length) {
        piece->is_complete = true;
    }
    return true;
}

bool read_from_piece(const Piece* piece, uint32_t offset, uint8_t* buffer, uint32_t size) {
    if (offset + size > piece->length) return false;
    memcpy(buffer, piece->data + offset, size);
    return true;
}

bool validate_piece(const Piece* piece, const uint8_t* expected_hash) {
    if (piece == NULL || piece->data == NULL || expected_hash == NULL) {
        return false;
    }

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(piece->data, piece->length, hash);

    return memcmp(hash, expected_hash, SHA_DIGEST_LENGTH) == 0;
}

void set_piece_verification_status(Piece* piece, bool is_verified) {
    piece->is_verified = is_verified;
}

