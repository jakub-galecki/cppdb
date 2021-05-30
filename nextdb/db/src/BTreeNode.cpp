#include "../include/BTreeNode.h"
#include "../include/Content.h"
#include "../include/types.h"

BTreeNode::BTreeNode(int degree, bool leaf, int keys_number) {
    this->leaf = leaf;
    this->keys_number = keys_number;
    this->degree = degree;
    this->data = new Content[2 * this->degree - 1];
    this->children = new BTreeNode*[2 * this->degree];
}

void BTreeNode::spiltChild(int i, BTreeNode *y) {
    auto *z = new BTreeNode(y->degree, y->leaf, this->degree - 1);

    for (int j = 0; j < this->degree - 1; j++) {
        z->data[j] = y->data[j + this->degree];
    }

    if (!y->leaf) {
        for (int j = 0; j < this->degree; j++){
            z->children[j] = y->children[j + this->degree];
        }
    }
    y->keys_number = this->degree - 1;

    for(int j = this->keys_number; j >= i + 1; j--){
        this->children[j + 1] = this->children[j];
    }
    this->children[i + 1] = z;

    for(int j = this->keys_number; j >= i; j--){
        this->data[j + 1] = this->data[j];
    }

    this->data[i] = y->data[this->degree - 1];
    this->keys_number += 1;
}

void BTreeNode::insertNonFull(Content c){
    int i = this->keys_number - 1;
    if (this->leaf) {
        while (i >= 0 &&  this->data[i].key > c.key){
            this->data[i + 1] = this->data[i];
            i -= 1;
        }
        this->data[i + 1] = c;
        this->keys_number += 1;
    } else {
        while (i >= 0 && this->data[i].key > c.key){
            i -= 1;
        }
        i += 1;
        if(this->children[i]->keys_number == 2 * (this->degree - 1)){
            this->spiltChild(i,this->children[i]);
            if (this->data[i].key < c.key){
                i += 1;
            }
        }
        this->children[i]->insertNonFull(c);
    }
}


void BTreeNode::traverse() {
    int i;
    for(i = 0; i < this->keys_number; i++){
        if (!this->leaf){
            this->children[i]->traverse();
        }

        std::cout << this->data[i].key << " " << this->data[i].value << std::endl;
    }

    if (!this->leaf){
        this->children[i]->traverse();
    }
}

Value BTreeNode::search(Key k) {
    int i = 0;
    while(i < this->keys_number && this->data[i].key < k) {
        i += 1;
    }

    if(this->data[i].key == k){
        return this->data[i].value;
    }

    if (this->leaf){
        return "";
    }

    return this->children[i]->search(k);
}
