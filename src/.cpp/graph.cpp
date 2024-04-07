//
// Created by Tomás Rodrigues on 07/04/2024.
//

#include "../.h/graph.h"

#include <limits>
#include <algorithm>
#define INF std::numeric_limits<double>::max()

//Algorithms functions only
//all the data structure in graph.h

void graph::testVisit(std::queue<vertex*> &q, edge *e, vertex *w, double residual){
    if (!w->isVisited()&&residual>0){
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}


bool graph::findAugmentingPath(graph *g, vertex *s, vertex *t){
    for (auto v:g->getVertexSet()){
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<vertex*> q;
    q.push(s);
    while (!q.empty() && ! t->isVisited()){
        auto v=q.front();
        q.pop();
        for (auto e: getOutgoingEdges(g, v)){
            testVisit(q, e, findVertex(e->getTargetVertexCode()), e->getCapacity() -e->getFlow());
        }
        for (auto e: getIncomingEdges(g, v)){
            testVisit(q, e, findVertex(e->getSourceVertexCode()), e->getFlow());
        }
    }
    return t->isVisited();
}


double graph::findminResidAlongPath(vertex *s, vertex *t){
    double f = INF;
    for (auto v=t; v!=s;){
        auto e=v->getPath();
        if (findVertex(e->getTargetVertexCode())==v){
            f=std::min(f,e->getCapacity() - e->getFlow());
            v= findVertex(e->getSourceVertexCode());
        }
        else{
            f=std::min(f, e->getFlow());
            v= findVertex(e->getTargetVertexCode());
        }
    }
    return f;
}

void graph::augmentFlowAlongPath(vertex *s, vertex *t, double f){
    for (auto v=t; v!=s;) {
        auto e= v->getPath();
        double flow= e->getFlow();
        if (findVertex(e->getTargetVertexCode())==v) {
            e->setFlow(flow+f);
            v = findVertex(e->getSourceVertexCode());
        }
        else{
            e->setFlow(flow-f);
            v=findVertex(e->getTargetVertexCode());
        }
    }
}

double graph::edmondskarp(graph *g, std::string source, std::string target){
    vertex* s = g->findVertex(source);
    vertex* t = g->findVertex(target);
    double f;

    if ( s==nullptr || t==nullptr || s==t){
        throw std::logic_error("Invalid source and&or target");
    }

    for (auto v:g->getVertexSet()){
        for (auto e: getOutgoingEdges(g, v)){
            e->setFlow(0);
        }
    }

    while(findAugmentingPath(g, s, t)){
        double f= findminResidAlongPath(s, t);
        augmentFlowAlongPath(s,t,f);
    }
    double sum=0;
    for(const auto e: getIncomingEdges(g, t)){
        sum+=e->getFlow();
    }
    return sum;
}