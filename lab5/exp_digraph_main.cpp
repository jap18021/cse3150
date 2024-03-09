#include <iostream>
#include <istream> 
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <string>
#include <vector>
#include "ints_read_matrix.h"
#include "ints_write.h"
#include "exp_digraph.h"

using namespace std;  

void processFile(const string& filename, vector<vector<int>>& matrix) {
    ifstream in_file;
    in_file.open(filename);
    matrix = ints_read_matrix(in_file);
    in_file.close();
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& my_vector : matrix){
        for (const auto& element : my_vector){
            cout << element << " ";
        }
        cout << endl;
    }
    cout << "--- Proceeding to next file ---" << endl;
}

int main(){
    vector<vector<int>> ZeroDigraph, Pos1Digraph, Neg1Digraph;

    processFile("G0.txt", ZeroDigraph);
    processFile("G1.txt", Pos1Digraph);
    processFile("G-1.txt", Neg1Digraph);

    cout << "G0.txt" << endl;
    printMatrix(ZeroDigraph);

    cout << "G1.txt" << endl;
    printMatrix(Pos1Digraph);

    cout << "G-1.txt" << endl;
    printMatrix(Neg1Digraph);

    expensiveDigraphExactPaths(Neg1Digraph, ZeroDigraph, Pos1Digraph);

    cout << "G0-out" << endl;
    printMatrix(ZeroDigraph);

    cout << "G1-out" << endl;
    printMatrix(Pos1Digraph);

    cout << "G-1-out" << endl;
    printMatrix(Neg1Digraph);
}