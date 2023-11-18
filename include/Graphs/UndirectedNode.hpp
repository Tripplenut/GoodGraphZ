/**
 * @file UndirectedNode.hpp
 * @author Anthony Fabius
 * @brief This is where all things Undirected Node related are stored
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef UNDIRECTEDNODES_HPP
#define UNDIRECTEDNODES_HPP

// Forward Declarations
template <class N, class E>
class Graph;

template <class E>
class Edge;

// CPP includes
#include <string>
#include <unordered_map>

// GGZ includes
#include "UndirectedGraph.hpp"
#include "UndirectedEdge.hpp"

/**
 * @brief The UndirectedNode class
 * @tparam T The Node Type
 */
template <class T>
class UndirectedNode{
private:

  template <class N, class E>
  friend class UndirectedGraph;

  template <class N>
  friend class UndirectedEdge;

  std::unordered_map<std::string, int> Edges;
  std::string id;

  /**
   * @brief Constructs an Undirected Node 
   * @param id_ Id of the Node
   */
  UndirectedNode(std::string& id_){
    id = id_;
  }

  /**
   * @brief Construct a weighted Undirected Node
   * @param id_ Id of the Node
   * @param weight_ Weight of the node
   */
  UndirectedNode(std::string& id_, T& weight_){
    id = id_;
    weight = weight_;
  }

  /**
   * @brief Adds Edge to node
   * @param otherNodeId The id of the other node
   * @param edgeId The id of the edge
   * @return true If edge was successfully added
   * @return false If edge could not be added
   */
  bool addEdge(std::string otherNodeId, int edgeId){
    //! Implement
  }

public:

  T weight;

  /**
   * @brief Gets the weight of the node
   * @return The weight of the node
   */
  T& getWeight() const {
    return weight;
  }

  /**
   * @brief Gets the edge id from a node.
   * Returns -1 if Edge does not exist.
   * @param nodeId The NodeId 
   * @return int 
   */
  int getEdgeId(std::string& nodeId){
    return (Edges.count(nodeId) == 0) ? (-1) : Edges[nodeId];
  }

  /**
   * @brief Gets all the ids of all the edges of a node.
   * Puts them in a vector and returns it.
   * @return std::vector<int> 
   */
  std::vector<int> getEdgesIds(){
    std::vector<int> res;
    for(auto iter = Edges.begin(); iter != Edges.end(); iter++){
      res.push_back(iter->second);
    }
    return res;
  }

  /**
   * @brief Gets all the nodeIds that this node shares an edge with.
   * @return std::vector<std::string> 
   */
  std::vector<std::string> getEdgeNodes(){
    std::vector<std::string> res;
    for(auto iter = Edges.begin(); iter != Edges.end(); iter++){
      res.push_back(iter->first);
    }
    return res;
  }

};


#endif