#include <iostream>
#include "ArrayBased_Lists/ArrayStack.cpp"
#include "ArrayBased_Lists/ArrayQueue.cpp"
#include "Linked_Lists/SLList.cpp"
#include "Linked_Lists/DLList.cpp"
#include "HashTables/ChainedHashTable.cpp"
#include "BSTNode.h"
#include "BST.cpp"
#include "Treap.cpp"
#include "AdjacencyMatrix.h"

using namespace std;

int main()
{

    cout << "------------------------ ArrayStack ------------------------" << endl;
    ArrayStack<int> arrayStack;
    arrayStack.add(0, 1);
    cout << arrayStack << endl;
    arrayStack.add(1, 2);
    cout << arrayStack << endl;
    arrayStack.add(2, 3);
    cout << arrayStack << endl;
    arrayStack.add(3, 4);
    cout << arrayStack << endl;
    arrayStack.set(2, 5);
    cout << arrayStack << endl;
    arrayStack.remove(1);
    cout << arrayStack << endl;

    ArrayStack<int> arrayStack1(3, 0);
    cout << arrayStack1 << endl;
    arrayStack1.set(0, 1);
    arrayStack1.set(1, 2);
    arrayStack1.add(arrayStack1.size(), 10);
    arrayStack1.add(arrayStack1.size(), 10);
    arrayStack1.add(arrayStack1.size(), 10);
    cout << arrayStack1 << endl;

    ArrayStack<ArrayStack<int>> arrayStack2;
    arrayStack2.add(arrayStack2.size(), arrayStack);
    arrayStack2.add(arrayStack2.size(), arrayStack1);
    cout << arrayStack2[0] << endl << arrayStack2[1] << endl;

    cout << "------------------------ ArrayQueue ------------------------" << endl;
    ArrayQueue<int> arrayQueue;
    arrayQueue.add(5);
    cout << arrayQueue << endl;
    arrayQueue.add(6);
    cout << arrayQueue << endl;
    arrayQueue.add(7);
    cout << arrayQueue << endl;
    arrayQueue.add(8);
    cout << arrayQueue << endl;
    arrayQueue.add(9);
    cout << arrayQueue << endl;
    arrayQueue.remove();
    cout << arrayQueue << endl;

    cout << "------------------------ SLList ------------------------" << endl;
    SLList<int> slList;
    slList.push(5);
    cout << slList << endl;
    slList.push(6);
    cout << slList << endl;
    slList.push(7);
    cout << slList << endl;
    slList.pop();
    cout << slList << endl;
    slList.add(4);
    cout << slList << endl;
    slList.remove();
    cout << slList << endl;
    slList.remove();
    cout << slList << endl;

    cout << "------------------------ DLList ------------------------" << endl;
    DLList<int> dlList;
    dlList.add(0, 5);
    cout << dlList << endl;
    dlList.add(1, 6);
    cout << dlList << endl;
    dlList.add(2, 7);
    cout << dlList << endl;
    dlList.add(0, 4);
    cout << dlList << endl;
    dlList.remove(0);
    cout << dlList << endl;
    dlList.remove(1);
    cout << dlList << endl;
    dlList.remove(1);
    cout << dlList << endl;
    dlList.remove(0);

    cout << "------------------------ ChainedHashTable ------------------------" << endl;
    ChainedHashTable<int> chainedHashTable(8);
    cout << "Add 1" << endl;
    chainedHashTable.add(1);
    cout << "Find 1: " << chainedHashTable.find(1) << endl;
    cout << "Add 2" << endl;
    chainedHashTable.add(2);
    cout << "Find 2: " << chainedHashTable.find(2) << endl;
    cout << "Add 3" << endl;
    chainedHashTable.add(3);
    cout << "Find 3: " << chainedHashTable.find(3) << endl;
    cout << "Find 4: " << chainedHashTable.find(4) << endl;
    cout << "Remove 3" << endl;
    chainedHashTable.remove(3);
    cout << "Find 3: " << chainedHashTable.find(3) << endl;
    cout << "Add 1" << endl;
    chainedHashTable.add(1);
    cout << "Find 1: " << chainedHashTable.find(1) << endl;
    cout << "Remove 1" << endl;
    chainedHashTable.remove(1);
    cout << "Find 1: " << chainedHashTable.find(1) << endl;
    chainedHashTable.remove(1);
    cout << "Find 1: " << chainedHashTable.find(1) << endl;
    cout << "Hash 3: " << chainedHashTable.hash(3) << endl;
    cout << "Hash 2: " << chainedHashTable.hash(2) << endl;
    cout << "Hash 1000000: " << chainedHashTable.hash(1000000) << endl;
    cout << "Hash 1000: " << chainedHashTable.hash(1000) << endl;

    cout << "------------------------ ChainedHashTable (Check Resize) ------------------------" << endl;
    ChainedHashTable<int> ch(3);
    cout << "Add 1" << endl;
    ch.add(1);
    cout << "Add 2" << endl;
    ch.add(2);
    cout << "Add 3" << endl;
    ch.add(3);
    cout << "Add 4" << endl;
    ch.add(4);
    cout << "Add 5" << endl;
    ch.add(5);
    cout << "Add 6" << endl;
    ch.add(6);
    cout << "Add 7" << endl;
    ch.add(7);
    cout << "Hash 1 (Before resize): " << ch.hash(1) << endl;
    cout << "Hash 2 (Before resize): " << ch.hash(2) << endl;
    cout << "Hash 3 (Before resize): " << ch.hash(3) << endl;
    cout << "Hash 4 (Before resize): " << ch.hash(4) << endl;
    cout << "Add 8" << endl;
    ch.add(8);
    cout << "Add 9" << endl;
    ch.add(9);
    cout << "Add 10" << endl;
    ch.add(10);
    cout << "Add 11" << endl;
    ch.add(11);
    cout << "Hash 1 (After resize): " << ch.hash(1) << endl;
    cout << "Find 1: " << ch.find(1) << endl;
    cout << "Find 2: " << ch.find(2) << endl;
    cout << "Find 3: " << ch.find(3) << endl;
    cout << "Find 4: " << ch.find(4) << endl;
    cout << "Find 5: " << ch.find(5) << endl;
    cout << "Find 6: " << ch.find(6) << endl;
    cout << "Find 7: " << ch.find(7) << endl;
    cout << "Find 8: " << ch.find(8) << endl;
    cout << "Find 9: " << ch.find(9) << endl;
    cout << "Find 10: " << ch.find(10) << endl;
    cout << "Find 11: " << ch.find(11) << endl;
    cout << "Find 12: " << ch.find(12) << endl;

    cout << "------------------------ BinarySearchTree ------------------------" << endl;
    BST<BSTNode<int>, int> bst;
    cout << "Add 3" << endl;
    bst.add(3);
    cout << "Add 1" << endl;
    bst.add(1);
    cout << "Add 2" << endl;
    bst.add(2);
    cout << "Find 1: " << bst.find(1) << endl;
    cout << "Find 2: " << bst.find(2) << endl;
    cout << "Find 3: " << bst.find(3) << endl;
    cout << "Find 4: " << bst.find(4) << endl;
    cout << "Add 4" << endl;
    bst.add(4);
    cout << "Add 8" << endl;
    bst.add(8);
    cout << "Add 5" << endl;
    bst.add(5);
    cout << "Root: " << bst.r->data
         << ", Left Root: " << bst.r->left->data
         << ", Right Root: " << bst.r->right->data
         << ", Left Right Root: " << bst.r->left->right->data
         << ", Right Right Root: " << bst.r->right->right->data
         << ", Right Right Left Root: " << bst.r->right->right->left->data << endl;
    cout << "Root Height: " << bst.height(bst.r) << endl;
    cout << "Root Depth: " << bst.depth(bst.r) << endl;
    cout << "5 Depth: " << bst.depth(bst.findLast(5)) << endl;
    cout << "8 Height: " << bst.height(bst.findLast(8)) << endl;
    cout << "Size: " << bst.size(bst.r) << endl;
    cout << "Add -7" << endl;
    bst.add(-7);
    cout << "Add -8" << endl;
    bst.add(-8);
    cout << "Add -6" << endl;
    bst.add(-6);
    cout << "Remove 4" << endl;
    bst.remove(bst.findLast(4));
    cout << "Root: " << bst.r->data
         << ", Left Root: " << bst.r->left->data
         << ", Right Root: " << bst.r->right->data
         << ", Left Right Root: " << bst.r->left->right->data
         << ", Right Left Root: " << bst.r->right->left->data
         << ", Left Left Root: " << bst.r->left->left->data << endl;
    cout << "Remove 1" << endl;
    bst.remove(bst.findLast(1));
    cout << "Root: " << bst.r->data
         << ", Left Root: " << bst.r->left->data
         << ", Right Root: " << bst.r->right->data
         << ", Right Left Root: " << bst.r->right->left->data
         << ", Left Left Root: " << bst.r->left->left->data << endl;

    cout << "------------------------ Treap ------------------------" << endl;
    Treap<int> treap;
    cout << "Add 3" << endl;
    treap.add(3);
    cout << "Add 1" << endl;
    treap.add(1);
    cout << "Add 2" << endl;
    treap.add(2);
    cout << "Add 5" << endl;
    treap.add(5);
    cout << "Add 8" << endl;
    treap.add(8);
    cout << "Add 4" << endl;
    treap.add(4);
    cout << "Traverse" << endl;
    cout << treap << endl;
    cout << "Remove 3" << endl;
    treap.remove(3);
    cout << "Traverse" << endl;
    cout << treap << endl;
    // TODO: BFS implementation for BT
    // TODO: Red-Black Tree implementation

    cout << "------------------------ Graph(AdjacencyMatrix) ------------------------" << endl;
    AdjacencyMatrix aM(4);
    aM.addEdge(1, 2);
    aM.addEdge(2, 3);
    aM.addEdge(0, 1);
    cout << aM;
    aM.removeEdge(1, 2);
    aM.addEdge(3, 2);
    cout << aM;
    vector<unsigned int> u = aM.inEdges(3);
    cout << "u.size() = " << u.size() << ", u[0] = " << u[0] << endl;
    cout << aM;
    u = aM.outEdges(2);
    cout << "u.size() = " << u.size() << ", u[0] = " << u[0] << endl;
    return 0;
}
