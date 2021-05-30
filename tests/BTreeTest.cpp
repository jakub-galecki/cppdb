#include "../nextdb/db/include/BTree.h"
#include "../nextdb/db/include/BTreeNode.h"


int main(){

    auto t = new BTree("test.txt");
    t->insertToTree(1, "1");
    t->insertToTree(12, "12");
    t->insertToTree(4, "4");
    t->insertToTree(23, "2");
    t->insertToTree(30, "30");
    t->insertToTree(13, "5aaaa");
    t->insertToTree(5, "5");
    t->insertToTree(121, "121");
    t->insertToTree(333, "333");
    t->insertToTree(111, "111");

    std::cout << t->search(123) << std::endl;
    std::cout << t->search(111) << std::endl;
    std::cout << t->search(121) << std::endl;
    std::cout << t->search(23) << std::endl;
    std::cout << t->search(5) << std::endl;


    return 0;
}
