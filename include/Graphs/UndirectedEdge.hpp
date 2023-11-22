/**
 * @file UndirectedEdge.hpp
 * @author Anthony Fabius
 * @brief This is where all things Undirected Edge related are stored
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
*/


//! Give up on the inheritance tbh, there isn't really a point, do the same for the Nodes and Graphs

#ifndef UNDIRECTEDEDGE_HPP
#define UNDIRECTEDEDGE_HPP

// Forward Declarations
template <class N, class E>
class UndirectedGraph;

template <class N>
class UndirectedNode;

// CPP includes
#include <string>

// GGZ includes
#include "UndirectedGraph.hpp"
#include "UndirectedNode.hpp"


/**
 * @brief The undirected edge class
 * @tparam T The weight type
 */
template<class T>
class UndirectedEdge {
private:

  template <class N, class E>
  friend class UndirectedGraph;

  template <class N>
  friend class UndirectedNode;

  int id;
  std::string node1Id;
  std::string node2Id;

  /**
   * @brief Construct an Undirected Edge
   * @param id_ Id of the Edge
   * @param node1_ The id of Node1
   * @param node2_ The id of Node2
   */
  UndirectedEdge(int id_, std::string node1Id_, std::string node2Id_) {
    id = id_;
    node1Id = node1Id_;
    node2Id = node2Id_;
  }

  /**
   * @brief Construct a weighted Undirected Edge
   * @param id_ Id of the Edge
   * @param weight_ The weight of the Edge
   * @param node1_ The id of Node1
   * @param node2_ The id of Node2
   */
  UndirectedEdge(int id_, T weight_, std::string node1Id_, std::string node2Id_){
    id = id_;
    weight = weight_;
    node1Id = node1Id_;
    node2Id = node2Id_;
  }

public:

  T weight;

  /**
   * @brief Sets the weight of the edge
   * @param weight_ 
   */
  void setWeight(T weight_){
    weight = weight_;
  }

  /**
   * @brief Gets the id of the edge
   * @return int 
   */
  int getId() const {
    return id;
  }

  /**
   * @brief Gets the weight of the edge
   * @return The Weight
   */
  T& getWeight() const {
    return weight;
  }

  /**
   * @brief Retrieves id of node1
   * @return std::string& 
   */
  std::string getNode1() const {
    return node1Id;
  }

  /**
   * @brief Retrieves id of node2
   * @return std::string& 
   */
  std::string getNode2() const {
    return node2Id;
  }

};

#endif
