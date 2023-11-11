/** @file Nodes.hpp
 * @brief This is where all things Node Related are stored
*/

#ifndef EDGES_HPP
#define EDGES_HPP

// Forward Declarations
template <class N, class E>
class Graph;

template <class N>
class Node;

// CPP includes

// GGZ includes
#include "Nodes.hpp"

template <class T>
class Edge{
private:

  template <class N, class E>
  friend class Graph;

  template <class N>
  friend class Node;

  int id;
  T data;
  int sourceNodeId;
  int targetNodeId;
  bool directed; // If true edge is directed
  bool weighted; // If true edge is weighted

  /**
   * @brief Constructor for Unweighted Edges
   * @param source Source Node
   * @param target Target Node
   * @param directed_ Boolean representing if Edge is directed
  */
  Edge(int source, int target, bool directed_ = false){
    // Make sure the edge isn't pointing to the same node
    sourceNodeId = source;
    targetNodeId = target;
    weighted = false;
    directed = directed_;
  }

  /**
   * @brief Constructor for Weighted Edges
   * @param source Source Node
   * @param target Target Node
   * @param data_ Data
  */
  Edge(int source, int target, T data, bool directed_ = false){
    // Make sure the edge isn't pointing to the same node
    sourceNodeId = source;
    targetNodeId = target;
    weighted = true;
    directed = directed_;
  }

};
#endif
