#include <iostream>
#include "Headers/Array.h"

using namespace std;

int main() {

    Array<int> arr(3);
    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 7;

    Array<int> new_arr(4);
    new_arr[0] = 6;
    new_arr[1] = 8;
    new_arr[2] = 10;
    new_arr[3] = 16;

    arr = new_arr;
    cout << arr;
    return 0;
}
