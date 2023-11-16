/**
 * @file Edges.hpp
 * @author Anthony Fabius
 * @brief This is where all things Edge related are stored
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

/*****************************************************************************/

/**
 * @brief The parent Edge class
 * @tparam T The weight type
 */
template<class T>
class Edge {
private:
  template <class N, class E>
  friend class Graph;

  template <class N>
  friend class Node;

  int id;

  /**
   * @brief Constructs an unweighted Edge
   * @param id_ Id of the Edge
   */
  Edge(int id_){
    id = id_;
    weight = NULL;
  }

  /**
   * @brief Constructs a weighted Edge
   * @param id_ Id of the Edge
   * @param weight_ The weight of the Edge
   */
  Edge(int id_, T weight_){
    id = id_;
    weight = weight_;
  };

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

};

/*****************************************************************************/

/**
 * @brief The undirected edge class
 * @tparam T The weight type
 */
template<class T>
class UndirectedEdge : private Edge<T> {
private:

  using Edge<T>::Edge;

  //! May need to include friends, idk yet

  std::string node1Id;
  std::string node2Id;

  /**
   * @brief Construct an Undirected Edge
   * @param id_ Id of the Edge
   * @param node1_ The id of Node1
   * @param node2_ The id of Node2
   */
  UndirectedEdge(int id_, std::string node1_, std::string node2_) : Edge(id_) {
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
  UndirectedEdge(int id_, T weight_, std::string node1_, std::string node2_){
    id = id;_
    weight = weight_;
    node1Id = node1Id_;
    node2Id = node2Id_;
  }

public:

  /**
   * @brief Retrieves id of node1
   * @return std::string& 
   */
  std::string& getNode1() const {
    return node1Id;
  }

  /**
   * @brief Retrieves id of node2
   * @return std::string& 
   */
  std::string& getNode2() const {
    return node2Id;
  }

};

/*****************************************************************************/

// Todo Directed Edge Child Class goes here


#endif
