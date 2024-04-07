#include <iostream>
#include "../.h/Data.h"
#include "../.h/reservoirs.h"
#include "../.h/stations.h"
#include "../.h/pipes.h"
#include "../.h/cities.h"
#include "../.h/graph.h"

int main() {
    graph* g1 = new graph();
    for (auto v : g1->getVertexSet()){
        std::cout << v->getCode()<<endl<<endl;
    }
    std::cout << g1->edmondskarp(g1, "R_1", "C_1");
    return 0;
}
