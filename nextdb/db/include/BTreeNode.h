#ifndef NEXTDB_BTREENODE_H
#define NEXTDB_BTREENODE_H

#include "types.h"
#include "vector"
#include "BTree.h"

class BTreeNode {
    BTreeNode(int degree, bool leaf);
    BTreeNode *search(Key k);
private:
    int *keys;
    int degree;
    BTreeNode** children;
    int keys_number;
    bool leaf;

    friend class BTree
};

#endif //NEXTDB_BTREENODE_H
