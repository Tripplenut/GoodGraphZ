/** @file Nodes.hpp
 * @brief This is where all things Node Related are stored
*/

#ifndef NODES_HPP
#define NODES_HPP

// Forward Declarations
template <class N, class E>
class Graph;

template <class E>
class Edge;

// CPP includes
#include <set>

// GGZ includes
#include "Graphs.hpp"
#include "Edges.hpp"


template <class T>
class Node {
private:
  template <class N, class E>
  friend class Graph;

  template <class E>
  friend class Edge;

  // Member Variables
  int id;
  T data;
  bool weighted;
  std::set<int> Edges;

  // Constructors, Destructors, and Assignment Operators
  /**
   * @brief Weighted Node Constructor
   * @param id_ Unique Id for Node
   * @param data_ Data of Node
  */
  Node(int id_){
    id = id_;
    weighted = false;
  }

  /**
   * @brief Weighted Node Constructor
   * @param id_ Unique Id for Node
   * @param data_ Data of Node
  */
  Node(int id_, T data_){
    id = id_;
    data = data_;
    weighted = true;
  }
};

#endif