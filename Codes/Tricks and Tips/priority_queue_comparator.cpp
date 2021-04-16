#include <iostream>
#include <queue>
#include <vector>

int main () {


    // So the default priority queue is a max heap
    // Now in case we build a priority queue of pair objects or custom class objects, we have to pass a comparator to it
    // Simply passing the comparator doesn't do the job, there are some other thigs we need to as well


    // Step 1. Define a comparator
    // I am assumping I will have pair objects in priority queue, therefore a lambda comparing pair objects
    auto lamb = [](std::pair<int, char> l, std::pair<int, char> r) {

        // Let's assume we are going to put pairs in priority queue, and we wanna compare them on the basis of frequency count
        
        // This is just simple ternary condition saying if we have same frequency, put give us the lower character
        // Else give us higher frequency one
        return l.first == r.first ? r.second < l.second : r.first > l.first;
    };

    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, decltype(lamb)> pq(lamb);
}