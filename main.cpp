#include <iostream>
#include "ArrayBased_Lists/ArrayStack.cpp"
#include "ArrayBased_Lists/ArrayQueue.cpp"

using namespace std;

int main() {

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

    return 0;
}
