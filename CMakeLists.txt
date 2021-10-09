cmake_minimum_required(VERSION 3.20)
project(Data-Structures)

set(CMAKE_CXX_STANDARD 14)

#Set your directories.  The dot representes the root application folder.
#Thus my the path to my domain folder:
set(ArrayBased "ArrayBased_Lists")
set(LinkedLists "Linked_Lists")

#Include the directories and now your cpp files will recognize your headers
include_directories(${ArrayBased} ${LinkedLists})

set(Headers ${ArrayBased}/Array.h ${ArrayBased}/ArrayStack.h ${ArrayBased}/ArrayQueue.h ${LinkedLists}/Node.h)
set(Sources ${ArrayBased}/ArrayStack.cpp ${ArrayBased}/ArrayQueue.cpp)

add_executable(Data-Structures main.cpp ${Sources} ${Headers})