#include <iostream>
#include "ArrayBased_Lists/ArrayStack.cpp"
#include "ArrayBased_Lists/ArrayQueue.cpp"
#include "Linked_Lists/SLList.cpp"
#include "Linked_Lists/DLList.cpp"
#include "HashTables/ChainedHashTable.cpp"

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
    ChainedHashTable<int> chainedHashTable;
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

    return 0;
}
