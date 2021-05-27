#include "../nextdb/db/include/BTree.h"
#include "../nextdb/db/include/BTreeNode.h"


int main(){

    auto t = new BTree("test.txt", 3);
    t->insertToTree(1, "1");
    t->insertToTree(12, "12");
    t->insertToTree(4, "4");
    t->insertToTree(23, "2");
    t->insertToTree(30, "30");
    t->insertToTree(13, "aaa");
    t->insertToTree(5, "5");
    t->printTree();

    return 0;
}