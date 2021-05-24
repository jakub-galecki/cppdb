#ifndef NEXTDB_BTREE_H
#define NEXTDB_BTREE_H

#include "string"

class BTreeNode;

class BTree {
    std::string file_name;
    int degree;
private:
    BTreeNode *head;

};


#endif //NEXTDB_BTREE_H
