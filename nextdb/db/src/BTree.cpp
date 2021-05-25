#include "../include/BTree.h"
#include "../include/BTree.h"

#include <utility>
#include "../include/BTreeNode.h"
#include "../include/Content.h"

BTree::BTree(std::string file_name, int degree) {
    BTreeNode *bTreeNode = new BTreeNode(degree, true, 0);
    this->root = bTreeNode;
    this->file_name = std::move(file_name);
    this->degree = degree;
}


Value BTree::search(Key k, BTreeNode *start = nullptr) {
    if (start) {
        return start->search(k);
    }
    return this->root ? this->root->search(k) : "";
}

bool BTree::insert(Key k, Value v) {

}