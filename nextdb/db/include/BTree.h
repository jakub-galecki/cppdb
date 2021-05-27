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
    BTreeNode *root;
    std::string file_name;
    int degree;
public:
    BTree(std::string, int);
    void insertToTree(Key, Value); // TODO: change to bool?
    Value search(Key, BTreeNode *);
    Value search(Key);
    void printTree();

};


#endif //NEXTDB_BTREE_H
