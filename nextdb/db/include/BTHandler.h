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
    bool write_to_file(Key k, Value v);
    bool set_in_file(Key k, Value v);
    bool find_in_file(Key k);
    bool remove_from_file(Key k);
    std::string get_from_file(Key k);
    BTHandler(std::string file_name);
    ~BTHandler();

private:
    BTree *btree;
    std::fstream file;
};

#endif //NEXTDB_BTHANDLER_H
