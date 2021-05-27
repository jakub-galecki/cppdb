//
// Class that stores the user's data
//

#ifndef NEXTDB_CONTENT_H
#define NEXTDB_CONTENT_H

#include "iostream"
#include "types.h"
#include "string.h"

// Implement comparison operators
typedef struct {
    // generate hash based on the key
    Key key;
    Value value;
} Content;


#endif //NEXTDB_CONTENT_H
