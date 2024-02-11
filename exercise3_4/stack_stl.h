#ifndef STACK_QUEUE_OPERATIONS_H
#define STACK_QUEUE_OPERATIONS_H

#include <stack>
#include <queue>
#include <string>

struct MyStruct {
    int value;
};

void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename);
void popFromStack(std::stack<MyStruct>& myStack);
void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename);
void popFromQueue(std::queue<MyStruct>& myQueue);

#endif // STACK_QUEUE_OPERATIONS_H
