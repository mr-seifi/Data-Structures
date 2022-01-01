cmake_minimum_required(VERSION 3.20)
project(Data-Structures)

set(CMAKE_CXX_STANDARD 14)

#Set your directories.  The dot representes the root application folder.
#Thus my the path to my domain folder:
set(ArrayBased "ArrayBased_Lists")
set(LinkedLists "Linked_Lists")
set(HashTables "HashTables")
set(BT "BinaryTrees")
set(GRP "Graphs")
#Include the directories and now your cpp files will recognize your headers
include_directories(${ArrayBased} ${LinkedLists} ${HashTables} ${BT} ${GRP})

set(Headers ${ArrayBased}/Array.h ${ArrayBased}/ArrayStack.h ${ArrayBased}/ArrayQueue.h ${LinkedLists}/Node.h ${LinkedLists}/SLList.h ${LinkedLists}/DLList.h ${HashTables}/ChainedHashTable.h ${HashTables}/LinearHashTable.h ${BT}/BTNode.h ${BT}/BT.h ${BT}/BSTNode.h ${BT}/BST.h ${BT}/Treap.h ${GRP}/AdjacencyMatrix.h)
set(Sources ${ArrayBased}/ArrayStack.cpp ${ArrayBased}/ArrayQueue.cpp ${LinkedLists}/SLList.cpp ${LinkedLists}/DLList.cpp ${HashTables}/ChainedHashTable.cpp ${HashTables}/LinearHashTable.cpp ${BT}/BT.cpp ${BT}/BST.cpp ${BT}/Treap.cpp ${GRP}/AdjacencyMatrix.cpp)

add_executable(Data-Structures main.cpp ${Sources} ${Headers})