#include <iostream>
#include "../.h/Data.h"
#include "../.h/reservoirs.h"
#include "../.h/stations.h"
#include "../.h/pipes.h"
#include "../.h/cities.h"
#include "../.h/graph.h"

int main() {
    Data data1;
    graph* g1 = new graph();
    for (auto c : data1.getCities()){
        std::cout << c.getCity() << "       " << g1->vertexMaxFlow(g1, c.getCode())<< std::endl;
    }

    std::cout << g1->TotalFlow(g1);

    g1->vertexRemovalFailures(g1, "PS_1");
    return 0;
}
