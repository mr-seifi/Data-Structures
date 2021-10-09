# ArrayBased Lists
This directory is about the data structures of some interfaces that underlying data is stored in an array, called the __backing
array__.
## Array
> This class is a little better than general array in c++ because we can access the size of the array.
---
## Array-Stack
> This is an implementation of __List__ interface with array-stack data structure.
### Time complexity
* Set operation: O(1)
* Get operation: O(1)
#### List interface
* Add operation: O(n - i)
* Remove operation: O(n - i)
#### Stack interface
* Push operation: O(1)<sup>A</sup>
* Pop operation: O(1)<sup>A</sup>
### Space complexity
* Wasted space: O(n)
---