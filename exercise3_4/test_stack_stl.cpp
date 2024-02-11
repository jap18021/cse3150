#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack_stl.h"

TEST_CASE("Test push and pop from stack and queue") {
    SUBCASE("Positive values") {
        std::stack<MyStruct> myStack;
        std::queue<MyStruct> myQueue;
        pushToStack(myStack, "data_pos.txt");
        pushToQueue(myQueue, "data_pos.txt");
        popFromStack(myStack);
        popFromQueue(myQueue);
        CHECK(myStack.empty());
        CHECK(myQueue.empty());
    }

    SUBCASE("Negative sum exceptions") {
        std::stack<MyStruct> myStack;
        std::queue<MyStruct> myQueue;
        pushToStack(myStack, "data_negpos.txt");
        pushToQueue(myQueue, "data_negpos.txt");
        CHECK_THROWS_AS(popFromStack(myStack), std::runtime_error);
        CHECK_THROWS_AS(popFromQueue(myQueue), std::runtime_error);
    }
}
