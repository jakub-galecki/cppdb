#include "../include/BTreeNode.h"

BTreeNode::BTreeNode(int degree, bool leaf, int keys_number) {
    this->leaf = leaf;
    this->keys_number = keys_number;
    this->degree = degree;
    this->cont = new Content*[2*degree - 1];
    this->children = new BTreeNode*[2 * degree];
}

void BTreeNode::spiltChild(int i, BTreeNode *y) {
    y = this->children[i];
    BTreeNode *z = new BTreeNode(y->degree, y->leaf, y->degree - 1);
    int t = z->degree;
    for (int j = 0; j < t; j++) {
        z->cont[j] = y->cont[j + 1];
    }

    if (!y->leaf) {
        for (int j = 0; j < this->degree - 1; j++){
            z->children[j] = y->children[j+1];
        }
    }
    y->keys_number = this->degree - 1;

    for(int j = this->keys_number; j >= i + 1; j--){
        this->children[j + 1] = this->children[j];
    }
    this->children[i + 1] = z;
    for(int j = this->keys_number; j >= i; j--){
        this->cont[j + 1] = this->cont[j];
    }
    this->cont[i] = y->cont[this->degree];
    this->keys_number++;
}

void BTreeNode::insertNonFull(Key k, Value v){
    int i = this->keys_number;
    if(this->leaf){

    } else{
        while (i >= 1 && k < this->cont[i]->k){
            i -= 1;
        }
        i += 1;
        if(this->children[i]->keys_number == 2 * (this->degree -1)){
            this->spiltChild(i,this->children[i]);
            if (k > this->cont[i]->k){
                i += 1 ;
            }
        }
    }
}



Value BTreeNode::search(Key k) {
    int i = 0;
    while (i < this->keys_number && k > this->cont[i]->k){
        i += 1;
    }
    if (i < this->keys_number && k == this->cont[i]->k){
        return this->cont[i]->v;
    } else if (this->leaf) {
        return "";
    }
    return this->children[i]->search(k);
}