/**
 * @file Graphs.hpp
 * @author Anthony Fabius
 * @brief This is where all things Graph related are stored
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef GRAPHS_HPP
#define GRAPHS_HPP

// CPP includes

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// GGZ includes

#include "Nodes.hpp"
#include "Edges.hpp"

/**
 * @brief The main graph class
 * @tparam N The weight type for Nodes
 * @tparam E The weight type for Edges
 */
template<class N, class E>
class Graph {

private:

bool directed;
std::unordered_map<std::string, Node<N>*> Nodes;
std::unordered_set<Edge<E>*> Edges;

public:

  //TODO - Create Constructors, Destructors, and Assignment Operators
  
  /**
   * @brief Graph Constructor
   * @param isDirected Sets if the graph is directed or not
  */
  Graph(bool isDirected = false){
    directed = isDirected;
  }

  /**
   * @brief Graph Destructor
  */
  ~Graph(){
    for(auto iter = Nodes.begin(); iter != Nodes.end(); iter++){
      delete iter->second;
    }
    Nodes.clear();

    for(auto iter = Edges.begin(); iter!= Edges.end(); iter++){
      delete *iter;
    }
    Edges.clear();
  }

  //TODO - Node and Edge Deletion

  /**
   * @brief Adds a node to the graph
   * @param id_ The id of the node
  */
  void addNode(std::string id_){
    // Check if Nodes already exist
    if(Nodes.count(id_) != 0)
      return;
    Node<N>* newNode = new Node<N>(id_,directed);
    Nodes.emplace(id_,newNode);
  }

  /**
   * @brief Adds an edge to the graph.
   * If the nodes don't already exist they will be added
   * @param sourceNode The source node
   * @param targetNode The target node
   * @return true If edge was added
   * @return false If edge wasn't added
  */
  bool addEdge(std::string sourceNode, std::string targetNode){
    // Check if Nodes already exist, if not create them
    if(Nodes.count(sourceNode) == 0)
      addNode(sourceNode);
    if(Nodes.count(targetNode) == 0)
      addNode(targetNode);

    // Check if Edge already exists
    if(Nodes[sourceNode]->Edges.count(targetNode) != 0){
      std::cout << "edge exists\n";
      return false;
    }

    Edge<E>* newEdge = new Edge<E>(Edges.size(), sourceNode, targetNode, directed);
    Edges.insert(newEdge);
    Nodes[sourceNode]->addEdge(targetNode,newEdge->id);
    Nodes[targetNode]->addEdge(sourceNode,newEdge->id);
  }

  //TODO - Node and Edges Getters and Setters
  
  /**
   * @brief Get the node being searched
   * @param src The node id
   */
  Node<N>& getNode(std::string& src){ return Nodes[src]; }


  //Edge<E>& getEdge(std::string& src, std::string& dest){}

  
  /**
   * @brief Get the edges of a node
   * @param src The node id
   * @return std::vector<Edge<E>&> 
   */
  //std::vector<Edge<E>&> getEdges(std::string& src){}


  /**
   * @brief Get the the incoming edges of a node
   * @param src The node id
   * @return std::vector<Edge<E>&> 
   */
  //std::vector<Edge<E>&> getIncomingEdges(std::string src){}


  /**
   * @brief Get the outgoing edges of a node
   * @param src The node id
   * @return std::vector<Edge<E>&>
   */
  //std::vector<Edge<E>&> getOutgoingEdges(std::string src){}


  //TODO - Graph Data
  /**
   * @brief Get the total number of nodes in the graph
   * @return int The number of nodes
   */
  int getTotalNodes(){ return Nodes.size(); }

  /**
   * @brief Gets the total number of edges in the graph
   * @return int The number of edges
   */
  int getTotalEdges(){ return Edges.size(); }

  //TODO - Create an Alert System
  // For example check if there are mixture of weighted and unweighted node or edges

};

#endif