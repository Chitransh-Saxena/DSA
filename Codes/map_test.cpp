#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct{

    map<string, int> *m;
}order;


int main()
{

    order* ord = (order*)calloc(1, sizeof(order));
    // ord->m.insert({1,2});


    ord->m = new map<string, int>();
    ord->m->insert({"one",1});
    auto it = ord->m->find("one");
    cout << it->second << endl;
    
}