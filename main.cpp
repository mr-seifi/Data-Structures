#include <iostream>
#include "Headers/ArrayStack_List.h"

using namespace std;

int main() {

    cout << "------------------------ ArrayStack_List ------------------------" << endl;
    ArrayStack_List<int> arrayStack;
    arrayStack.add(0, 1);
    cout << arrayStack << endl;
    arrayStack.add(1, 2);
    cout << arrayStack << endl;
    arrayStack.add(2, 3);
    cout << arrayStack << endl;
    arrayStack.add(3, 4);
    cout << arrayStack << endl;
    cout << "Set element in index of 2 to 5" << endl;
    arrayStack.set(2, 5);
    cout << arrayStack << endl;
    cout << "Element in index of 1: " << arrayStack.get(1) << endl;
    cout << "Removing element in index of 1..." << endl;
    arrayStack.remove(1);
    cout << arrayStack << endl;

    return 0;
}
