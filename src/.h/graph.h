//
// Created by Tomás Rodrigues on 07/04/2024.
//

#ifndef DA_PROJECT1_GRAPH_H
#define DA_PROJECT1_GRAPH_H

#include <string>
#include <vector>
#include <queue>
#include "Data.h"

class edge;

class vertex {
private:
    std::string code;
    bool visited;
    double dist=0;
    edge *path= nullptr;
public:
    vertex(std::string code){
        this->code=code;
        visited=false;
    }

    std::string getCode(){return this->code;}
    bool isVisited(){return this->visited;}
    double getDist(){return this->dist;}

    void setVisited(bool v){
        this->visited=v;
    }
    void setDist(double dist){
        this->dist=dist;
    }

    edge *getPath() const{
        return this->path;
    }

    void setPath(edge *path){
        this->path=path;
    }
};



class edge {
private:
    std::string sourceVertexCode;
    std::string targetVertexCode;
    double capacity;
    double flow;
    bool selected;
public:
    edge(std::string source, std::string target, double capacity){
        this->sourceVertexCode=source;
        this->targetVertexCode=target;
        this->capacity=capacity;
        selected=false;
    }

    const std::string& getSourceVertexCode() const{return sourceVertexCode;}
    const std::string& getTargetVertexCode(){return targetVertexCode;}
    double getCapacity(){return this->capacity;}
    double getFlow(){return this->flow;}
    bool isSelected(){return this->selected;}

    void setSelected(bool s){
        this->selected=s;
    }
    void setFlow(double f){
        this->flow=f;
    }
};



class graph {
private:
    std::vector<vertex*> vertexSet;
    std::vector<edge*> edgeSet;
public:
    graph(){
        Data data;
        for (auto r: data.getReservoirs()){
            vertex* v = new vertex(r.getCode());
            vertexSet.push_back(v);
        }
        for (auto s:data.getStations()){
            vertex* v = new vertex(s.getCode());
            vertexSet.push_back(v);
        }
        for (auto c:data.getCities()){
            vertex* v = new vertex(c.getCode());
            vertexSet.push_back(v);
        }
        for (auto p:data.getPipes()) {
            edge* e = new edge(p.getSpA(), p.getSpB(), p.getCapacity());
            edgeSet.push_back(e);
            if (p.getDirection() == 0) {
                edge* e2 = new edge(p.getSpB(), p.getSpA(), p.getCapacity());
                edgeSet.push_back(e2);
            }
        }
    }

    void addEdge(std::string source, std::string target, double capacity, bool direction){
        edge* e= new edge(source, target, capacity);
        edgeSet.push_back(e);
        if (direction==0){
            edge* e2= new edge(target, source, capacity);
            edgeSet.push_back(e2);
        }
    }
    bool removeEdge(edge e){
        for (int i=0; i<edgeSet.size(); i++){
            if (edgeSet[i]->getSourceVertexCode() == e.getSourceVertexCode() && edgeSet[i]->getTargetVertexCode() == e.getTargetVertexCode() && edgeSet[i]->getCapacity()==e.getCapacity()){
                edgeSet.erase(edgeSet.begin()+i);
            }
        }
    }

    vertex* findVertex(std::string c) const{
        for (vertex* v : vertexSet){
            if (v->getCode() == c){
                return v;
            }
        }
        return nullptr;
    }

    std::vector<edge*> getIncomingEdges(graph *g, vertex *v){
        std::vector<edge*> result;
        for (auto e: edgeSet){
            if (e->getTargetVertexCode()==v->getCode()){
                result.push_back(e);
            }
        }
        return result;
    }
    std::vector<edge*> getOutgoingEdges(graph *g, vertex *v){
        std::vector<edge*> result;
        for (auto e: edgeSet){
            if (e->getSourceVertexCode()==v->getCode()){
                result.push_back(e);
            }
        }
        return result;
    }

    std::vector<vertex*> getVertexSet(){return vertexSet;}
    std::vector<edge*> getEdgeSet(){return edgeSet;}

    //for Edmonds Karp Algorithm
    void testVisit(std::queue<vertex*> &q, edge *e, vertex *w, double residual);
    bool findAugmentingPath(graph *g, vertex *s, vertex *t);
    double findminResidAlongPath(vertex *s, vertex *t);
    void augmentFlowAlongPath(vertex *s, vertex *t, double f);
    double edmondskarp(graph *g, std::string source, std::string target);

};


#endif //DA_PROJECT1_GRAPH_H
