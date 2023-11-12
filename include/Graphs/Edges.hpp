/**
 * @file Edges.hpp
 * @author Anthony Fabius
 * @brief This is where all things Edge related is stored
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef EDGES_HPP
#define EDGES_HPP

// Forward Declarations
template <class N, class E>
class Graph;

template <class N>
class Node;

// CPP includes
#include <string>

// GGZ includes
#include "Nodes.hpp"

/**
 * @brief The main Edge class
 * @tparam T The weight type
 */
template <class T>
class Edge{
private:

  template <class N, class E>
  friend class Graph;

  template <class N>
  friend class Node;

  int id;
  T data;
  std::string sourceNodeId;
  std::string targetNodeId;
  bool directed; // If true edge is directed
  bool weighted; // If true edge is weighted

  /**
   * @brief Constructor for Unweighted Edges
   * @param id_ Id of this edge
   * @param source Source Node
   * @param target Target Node
   * @param isDirected Sets if edge is directed or not
  */
  Edge(int id_, std::string& source, std::string& target, bool isDirected){
    // Make sure the edge isn't pointing to the same node
    id = id_;
    sourceNodeId = source;
    targetNodeId = target;
    weighted = false;
    directed = isDirected;
  }

  /**
   * @brief Constructor for Weighted Edges
   * @param id Id of this edge
   * @param source Source Node
   * @param target Target Node
   * @param data_ Data
   * @param isDirected Sets if edge is directed or not
  */
  Edge(int id_, std::string& source, std::string& target, T data_, bool isDirected){
    // Make sure the edge isn't pointing to the same node
    id = id_;
    sourceNodeId = source;
    targetNodeId = target;
    data = data_;
    weighted = true;
    directed = isDirected;
  }

};
#endif
