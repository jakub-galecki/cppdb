//
// Based on: Thomas H. Cormen,
// Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. 2009.
// Introduction to Algorithms, Third Edition (3rd. ed.). The MIT Press.
//

#ifndef NEXTDB_BTREENODE_H
#define NEXTDB_BTREENODE_H

#include "types.h"
#include "vector"
#include "BTree.h"
#include "Content.h"

class BTreeNode {
public:
    BTreeNode(int, bool, int);
    Value search(Key k);
    void spiltChild(int, BTreeNode*);
    void insertNonFull(Content c);
    void traverse();
    Content *data;
    BTreeNode **children;
private:
    int degree = 4;
    int keys_number;
    bool leaf;

    friend class BTree;
};

#endif //NEXTDB_BTREENODE_H
