//
// Based on: Thomas H. Cormen,
// Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. 2009.
// Introduction to Algorithms, Third Edition (3rd. ed.). The MIT Press.
//

#ifndef NEXTDB_BTREE_H
#define NEXTDB_BTREE_H

#include "string"
#include "types.h"
#include "Content.h"
class BTreeNode;

class BTree {
    BTree(std::string, int);
    bool insert(Key k, Value v);
    Value search(Key, BTreeNode *);
    void insertNonFull(Key);
    std::string file_name;
    int degree;
private:
    BTreeNode *root;

};


#endif //NEXTDB_BTREE_H
