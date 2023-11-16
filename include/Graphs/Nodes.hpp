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

/*****************************************************************************/

template <class T>
class Node {
private:
  template <class N, class E>
  friend class Graph;

  template <class E>
  friend class Edge;

  std::string id;

  /**
   * @brief Constructs an unweighted Node
   * @param id_ Id of the Node
   */
  Node(std::string& id_){
    id = id_;
    weight = NULL;
  }

  /**
   * @brief Constructs an unweighted Node
   * @param id_ Id of the Node
   * @param T 
   */
  Node(std::string& id_, T& weight){
    id = id_;
    weight = weight;
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

};

/*****************************************************************************/

template <class T>
class UndirectedNode : private Node<T> {
private:

  //! Store Edges

  /**
   * @brief Constructs an Undirected Node 
   * @param id_ 
   */
  UndirectedNode(std::string& id_){
    id = id_;
  }

  /**
   * @brief Construct a weighted Undirected Node
   * @param id_ 
   * @param weight_ 
   */
  UndirectedNode(std::string& id_, T& weight_){
    id = id_;
    weight = weight_;
  }

public:


};

/*****************************************************************************/

// Todo Directed Node Child goes here

#endif