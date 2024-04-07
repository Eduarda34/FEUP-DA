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

    /**
     * @return code
     */
    std::string getCode(){return this->code;}
    bool isVisited(){return this->visited;}
    double getDist(){return this->dist;}

    /**
     *
     * @param v
     */
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
        //Vertex

        //Source -> vertex source code= "SOURCE"
        vertex* Source = new vertex("SOURCE");
        vertex* Sink=new vertex("SINK");
        vertexSet.push_back(Source);
        vertexSet.push_back(Sink);

        for (auto r: data.getReservoirs()){
            vertex* v = new vertex(r.getCode());
            vertexSet.push_back(v);
            edge* e= new edge("SOURCE", r.getCode(), r.getMaxDel());
            edgeSet.push_back(e);
        }
        for (auto s:data.getStations()){
            vertex* v = new vertex(s.getCode());
            vertexSet.push_back(v);
        }
        for (auto c:data.getCities()){
            vertex* v = new vertex(c.getCode());
            vertexSet.push_back(v);

            edge* e= new edge(c.getCode(), "SINK", c.getDemand());
            edgeSet.push_back(e);
        }

        //Edges
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

    /**
     * @brief Useful for searching for a specific vertex in a graph using its code as a unique identifier
     * @param c
     * @return nullptr if no vertices are found after traversing the entire set of vertices
     */
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

    /**
     * @brief useful for obtaining all outgoing edges of a specific vertex in a graph facilitating the
     * analysis of the vertex's connectivity with other vertices
     * @param g
     * @param v
     * @return result that contains pointers to all edges leaving vertex v
     */
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

    /**
     * @brief Implements the Edmonds-Karp algorithm to find the maximum flow in
     * a flow network, updating the edge flows until there are no more increasing paths in the graph
     * @param g
     */
    void edmondskarp(graph *g);

    /**
     * @brief Uses the Edmonds-Karp algorithm to calculate the maximum flow int the flow network and then
     * calculates the maximum flow flowing to the specified vertex
     * @param g
     * @param target
     * @return sum that represents the maximum flow flowing to the specified destination vertex
     */
    double vertexMaxFlow(graph *g, std::string target){
        edmondskarp(g);
        vertex* t= findVertex(target);
        double sum=0;
        for(const auto e: getOutgoingEdges(g, findVertex(target))){
            if (e->getTargetVertexCode()=="SINK") {
                sum += e->getFlow();
            }
        }
        return sum;
    }

    /**
     * @brief Uses the vertexMaxFlow() to calculate the maximum flow in each city and then calculates
     * the total flow in all cities by adding que maximum flows in each city
     * @param g
     * @return sum that represents the total flow across all cities
     */
    double TotalFlow(graph *g){
        double sum=0;
        Data data1;
        vector<cities> Cidades = data1.getCities();
        for (auto c:Cidades){
            sum+= vertexMaxFlow(g, c.getCode());
        }
        return sum;
    }
};


#endif //DA_PROJECT1_GRAPH_H
