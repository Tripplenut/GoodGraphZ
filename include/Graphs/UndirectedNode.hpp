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

  //! Store Edges
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


#endif