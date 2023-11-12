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
#include <unordered_set>

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
  bool weighted;
  std::unordered_set<int> Edges;
  std::unordered_set<int> InEdges;
  std::unordered_set<int> OutEdges;
  // Either Edges is used or InEdges and OutEdges
  //! Think about redesigning so edge lookup is O(1) instead of O(n)
  //! Maybe hashmap<string,int> where string is the node and int is the edge id

  // Constructors, Destructors, and Assignment Operators
  /**
   * @brief Weighted Node Constructor
   * @param id_ Id for Node
  */
  Node(std::string id_){
    id = id_;
    weighted = false;
  }

  /**
   * @brief Weighted Node Constructor
   * @param id_ Id for Node
   * @param data_ Data of Node
  */
  Node(std::string id_, T data_){
    id = id_;
    data = data_;
    weighted = true;
  }

public:

  // Overloaded Operators
  /**
   * @brief Overloaded Dereference Operator for Nodes
  */
  std::string* operator->() { return &id; }

  /**
   * @brief Overloaded Equivalence Operator for Nodes
   * @param other The other Node
   */
  bool operator==(const Node& other) const { return id = other.id; }

};

#endif