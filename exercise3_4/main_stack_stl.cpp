#include <iostream>
#include <stack>
#include <queue>
#include "stack_stl.h"

int main() {
    std::stack<MyStruct> myStack;
    std::queue<MyStruct> myQueue;
    const std::string filename = "data.txt";

    try {
        pushToStack(myStack, filename);
        pushToQueue(myQueue, filename);
        popFromStack(myStack);
        popFromQueue(myQueue);

        std::cout << "Sum is non-negative" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
