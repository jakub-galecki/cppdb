//
// Created by batman on 5/24/21.
//

#ifndef NEXTDB_DBINTERFACE_H
#define NEXTDB_DBINTERFACE_H

#include "types.h"

class DBInterface {
    virtual bool insert(Key k, Value v) = 0;
    virtual bool update(Key k, Value v) = 0;
    virtual bool find(Key k) = 0;
    virtual bool remove(Key k) = 0;
    virtual std::string get(Key k) = 0 ;
};

#endif //NEXTDB_DBINTERFACE_H
