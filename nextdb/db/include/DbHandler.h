//
// Created by batman on 5/24/21.
//

#ifndef NEXTDB_DBHANDLER_H
#define NEXTDB_DBHANDLER_H

#include "DBInterface.h"

class DBHandler : DBInterface {
    bool insert(Key k, Value v);
    bool update(Key k, Value v);
    bool find(Key k);
    bool remove(Key k);
    std::string get(Key k);
};

#endif //NEXTDB_DBHANDLER_H
