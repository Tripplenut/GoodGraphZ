/**
 * @file UndirectedGraph.hpp
 * @author Anthony Fabius
 * @brief This is where all things Undirected Graph related are stored
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef UNDIRECTEDGRAPHS_HPP
#define UNDIRECTEDGRAPHS_HPP

#include "stddef.h"

// CPP includes
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// GGZ includes
#include "UndirectedNode.hpp"
#include "UndirectedEdge.hpp"


/**
 * @brief The Undirected Graph class
 * @tparam N The weight type for Nodes
 * @tparam E The weight type for Edges
 */
template <class N, class E>
class UndirectedGraph {
private:

  std::unordered_map<std::string, UndirectedNode<N>*> Nodes;
  std::unordered_map<int, UndirectedEdge<E>*> Edges;

  bool weighted;

public:

  /**
   * @brief Constructs an Undirected Graph
   * @param weighted_ Sets if graph is weighted
   */
  UndirectedGraph(bool weighted_ = false){
    weighted = weighted_;
  }

  /**
   * @brief Destroys an Undirected Graph
   */
  ~UndirectedGraph(){
    for(auto iter = Nodes.begin(); iter != Nodes.end(); iter++){
      delete iter->second;
    }

    for(auto iter = Edges.begin(); iter != Edges.end(); iter++){
      delete iter->second;
    }
  }

  /**
   * @brief Adds a node to the graph
   * @param nodeId The name of the node
   * @param weight Optional weight for the node
   * @return true If node was successfully added
   * @return false If node could not be added
   */
  bool addNode(std::string nodeId){
    //! Gonna need some error checking
    if (Nodes.count(nodeId) != 0) // make sure nodes don't already exist
      return false;
    
    Nodes[nodeId] = new UndirectedNode<N>(nodeId);
    return true;
  }

  //TODO add weighted nodes

  /**
   * @brief Adds an edge to the graph
   * @param node1Id The id of the first node
   * @param node2Id The id of the second node
   * @return true If edge was successfully added
   * @return false If edge could not be added
   */
  bool AddEdge(std::string node1Id, std::string node2Id){
    //! Gonna need a bunch of error checking (edge doesn't already exist)
    if(node1Id == node2Id) // Make sure nodes don't point to themselves
      return false;
    
    addNode(node1Id);
    addNode(node2Id);

    Edges[Edges.size()] = new UndirectedEdge<E>(Edges.size(), node1Id, node2Id);

    return true;
  }

  //TODO add weighted edges

};

#endif