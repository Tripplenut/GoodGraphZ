/**
 * @file Nodes.hpp
 * @author Anthony Fabius
 * @brief This is where all things Node Related are stored
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef NODES_HPP
#define NODES_HPP

// Forward Declarations
template <class N, class E>
class Graph;

template <class E>
class Edge;

// CPP includes
#include <string>
#include <unordered_map>

// GGZ includes
#include "Graphs.hpp"
#include "Edges.hpp"

/**
 * @brief The main Node class
 * @tparam T The weight type
 */
template <class T>
class Node {
private:
  template <class N, class E>
  friend class Graph;

  template <class E>
  friend class Edge;

  // Member Variables
  std::string id;
  T data;
  bool directed;
  bool weighted;
  std::unordered_map<std::string,int> Edges;
  std::unordered_map<std::string,int> InEdges;
  std::unordered_map<std::string,int> OutEdges;
  // Either Edges is used or InEdges and OutEdges

  // Constructors, Destructors, and Assignment Operators
  /**
   * @brief Weighted Node Constructor
   * @param id_ Id for Node
   * @param isDirected Sets if node is directed or not
  */
  Node(std::string id_, bool isDirected){
    id = id_;
    weighted = false;
    directed = isDirected;
  }

  /**
   * @brief Weighted Node Constructor
   * @param id_ Id for Node
   * @param data_ Data of Node
   * @param isDirected Sets if node is directed or now
  */
  Node(std::string id_, T data_, bool isDirected){
    id = id_;
    data = data_;
    weighted = true;
    directed = isDirected;
  }

  /**
   * @brief Adds edge info to node
   * @param otherNodeId The id of the node connected to
   * @param EdgeId The id of the edge in the graphs set
   */
  void addEdge(std::string otherNodeId, int EdgeId){
    //! Add implementation for directed graphs
    Edges.emplace(otherNodeId,EdgeId);
  }

public:


  // Overloaded Operators
  /**
   * @brief Overloaded Dereference Operator for Nodes
  */
  //std::string* operator->() { return &id; }

  /**
   * @brief Overloaded Equivalence Operator for Nodes
   * @param other The other Node
   */
  bool operator==(const Node& other) const { return id = other.id; }

};

#endif