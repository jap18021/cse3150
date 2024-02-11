#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <stdexcept>
#include "stack_stl.h"

void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File could not be open.");
    }
    int value;
    while (file >> value) {
        MyStruct data = {value};
        myStack.push(data);
    }
    file.close();
}


void popFromStack(std::stack<MyStruct>& myStack) {
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top().value;
        myStack.pop();
    }
    if (sum < 0) {
        throw std::runtime_error("[STACK] Negaive sum detected after popping.");
    }
}


void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File could not be open.");
    }
    int value;
    while (file >> value) {
        MyStruct data = {value};
        myQueue.push(data);
    }
    file.close();
}


void popFromQueue(std::queue<MyStruct>& myQueue) {
    int sum = 0;
    while (!myQueue.empty()) {
        sum += myQueue.front().value;
        myQueue.pop();
    }
    if (sum < 0) {
        throw std::runtime_error("[QUEUE] Negative sum detected after popping.");
    }
}
