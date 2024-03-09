#include <iostream>
#include <vector>
#include "exp_digraph.h"

using namespace std;

void expensiveDigraphExactPaths(vector<vector<int>>& DNeg1, vector<vector<int>>& DZero, vector<vector<int>>& DPos1) {
    int n = DZero.size();
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (((DNeg1[i][k] + DPos1[k][j]) == 0) || ((DPos1[i][k] + DNeg1[k][j]) == 0)) {
                        DZero[i][j] = 0;
                    }
                    if (((DPos1[i][k] + DPos1[k][j]) == 1) || ((DZero[i][k] + DPos1[k][j]) == 1)) {
                        DPos1[i][j] = 1;
                    }
                    if (((DNeg1[i][k] + DZero[k][j]) == -1) || ((DZero[i][k] + DNeg1[k][j]) == -1)) {
                        DNeg1[i][j] = -1;
                    }
                }
            }
        }
    }
}