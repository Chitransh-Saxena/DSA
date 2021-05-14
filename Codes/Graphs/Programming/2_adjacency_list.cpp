/*
    Given a graph, create a adjacency list from that

    Graph:  0 - 1 - 3
            \  /
             2

    Approach - Since it is numbered graph, we can treat the vertices as index of an array or vector.
    -> Create a vector<vector<int>> aList.
    -> Since we are not given a graph in any way right now, we are just gonna create the list by looking the picture above
*/

#include <iostream>
#include <vector>

using namespace std;

int main () {

    vector<vector<int>> aList;


    // Considering the index as vertex

    aList.push_back({1,2});
    aList.push_back({0,2,3});
    aList.push_back({0,1});
    aList.push_back({1});

    for(auto v: aList) {

        for(int x: v) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}