# Lab 5 - Expensive Digraph Exact Paths
This program creates an algorithm to analyze the nodes of barbell graphs. Similar to greedy algorithms with graphs, it finds all possible connections in order to find a zero-cost path between nodes. We can achieve this by calculating the number of rotations.
# 1 - Initialization
## 1.1 - Clone the repository
Run the following command to clone the repository:

`git clone https://github.com/jap18021/cse3150.git`
## 1.2 - Direct to lab5
Use the following commands to get to the correct directory:

`ls` - ensure that lab5 is here.

`cd cse3150/lab5'

# 2 - Execute the program
## 2.1 - Compile and Run
Use the following command to compile the main program:

`g++ exp_digraph.cpp exp_digraph_main.cpp ints_read_matrix.cpp ints_read_vector.cpp ints_write.cpp -o main`

Afterwards, you should have an executable. Run it with the following:

`./main`

## 2.2 - Compile and Test
Use the following command to compile the unit tests for the program:

`g++ exp_digraph.cpp exp_digraph_utest.cpp ints_read_matrix.cpp ints_read_vector.cpp ints_write.cpp -o test`

Afterwards, you should have an executable. Run it with the following:

`./test`
