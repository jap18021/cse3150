#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "header.h"
#include <sstream>

using namespace std;

int main() {
    vector<double_vector> vectors;
    vector<my_distance> all_pairs_distances;

    ifstream in_file;
    in_file.open("vectors.txt");

    int id = 0;
    string line;

    while (getline(in_file, line)) {
        stringstream ss(line);
        double value;
        vector<double> vals;
        while (ss >> value) {
            vals.push_back(value);
        }
        vectors.push_back(double_vector(vals, id));
        id++;
    }
    
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double distance = cosine_distance(vectors[i], vectors[j]);
            all_pairs_distances.push_back(my_distance(i, j, distance));
        }
    }

    sort(all_pairs_distances.begin(), all_pairs_distances.end(), [](const my_distance & left, const my_distance & right) {
        return left.cos_distance < right.cos_distance;
    });

    for (auto dist : all_pairs_distances) {
        cout << " " << dist.id_1 << " " << dist.id_2 << " cos dist = " << dist.cos_distance << endl;
    }

    cout << endl;

    in_file.close();

    return 0;
}