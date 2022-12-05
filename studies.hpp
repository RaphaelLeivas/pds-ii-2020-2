#include <iostream>

#ifndef PI
#define PI 3.1415

typedef unsigned char uint_8;
typedef unsigned int uint_16;
typedef int int_32;
typedef bool bit;

typedef enum {
    NO_ERROR = 0,
    TIMEOUT_ERROR = 1,
    BUFFER_OVERFLOW = 2,
    NO_RESPONSE = 3
} erro_t;

typedef struct {
    uint_8 address;
    erro_t getAddress(uint_8* address) {
        *address = this->address;
        return;
    }
} data_t;

#endif

