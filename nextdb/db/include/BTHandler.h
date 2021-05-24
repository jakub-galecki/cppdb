//
// Class supposed to interact with the DB file
//

#ifndef NEXTDB_BTHANDLER_H
#define NEXTDB_BTHANDLER_H

#include <fstream>
#include "types.h"
#include "BTree.h"
#include "DBInterface.h"

class BTHandler : DBInterface {
    bool insert(Key k, Value v);
    bool update(Key k, Value v);
    bool find(Key k);
    bool remove(Key k);
    std::string get(Key k);
    BTHandler(std::string file_name);
    ~BTHandler();

private:
    BTree *btree;
    std::fstream file;
};

#endif //NEXTDB_BTHANDLER_H
