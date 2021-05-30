include_path = ../nextdb/db/include/
src_path = ../nextdb/db/src/
btree_test_files = ${include_path}BTreeNode.h ${include_path}BTree.h ${src_path}BTreeNode.cpp ${src_path}BTree.cpp 


test_tree:
	g++ BTreeTest.cpp -o btree_test.out ${btree_test_files}
	./btree_test.out


clean:
	rm -rf *.out


