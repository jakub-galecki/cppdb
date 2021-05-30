#include "../include/BTree.h"
#include "../include/BTree.h"

#include <utility>
#include "../include/BTreeNode.h"
#include "../include/Content.h"

BTree::BTree(std::string file_name) {
    BTreeNode *bTreeNode = nullptr;
    this->root = bTreeNode;
    this->file_name = std::move(file_name);
}


void BTree::printTree(){
    this->root->traverse();
}

Value BTree::search(Key k) {
    return this->root ? this->root->search(k) : "";
}

Value BTree::search(Key k, BTreeNode *start ) {
    return start->search(k);
}

void BTree::insertToTree(Key k, Value v) {
    Content c {k, v};

    if (this->root == nullptr){
        this->root = new BTreeNode(this->degree, true, 0);
        this->root->data[0] = c;
        this->root->keys_number = 1;
    } else {
        if (this->root->keys_number == 2 * (this->root->degree - 1)){
            auto *s = new BTreeNode(this->degree, false, 0);

            s->children[0] = this->root;
            s->spiltChild(0, this->root);

            int i = 0;
            if(s->data[0].key < c.key){
                i += 1;
            }
            s->children[i]->insertNonFull(c);
            this->root = s;
        } else {
            this->root->insertNonFull(c);
        }
    }
}
