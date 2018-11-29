cmake_minimum_required(VERSION 3.12)
project(algorithms_implementation)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_implementation main.cpp Stack/Stack.cpp Stack/Stack.h Queue/Queue.cpp
        Queue/Queue.h Stack/LinkedStack.cpp Stack/LinkedStack.h Queue/LinkedQueue.cpp Queue/LinkedQueue.h
        Lists/SequencedList.cpp Lists/SequencedList.h Lists/LinkedList.cpp Lists/LinkedList.h
        Mathematics/Polynom.cpp Mathematics/Polynom.h Trees/Heap.h Trees/Heap.cpp)