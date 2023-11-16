/**
 * @file Graphs.hpp
 * @author Anthony Fabius
 * @brief This is where all things Graph related are stored
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef GRAPHS_HPP
#define GRAPHS_HPP

// CPP includes

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// GGZ includes

#include "Nodes.hpp"
#include "Edges.hpp"


/*****************************************************************************/

/**
 * @brief The main graph class
 * @tparam N The weight type for Nodes
 * @tparam E The weight type for Edges
 */
template <class N, class E>
class Graph {
private:

  bool weighted;

  /**
   * @brief Creates a graphs
   * @param weighted_ Sets if graph is weighted
   */
  Graph(bool weighted_ = false){
    weighted = weighed_;
  }

};

/*****************************************************************************/

template <class N, class E>
class UndirectedGraph : private Graph<N,E> {
private:

  std::unordered_map<std::string, UndirectedNode<N>*> Nodes;
  std::unordered_map<std::string, UndirectedEdge<E>*> Edges;

public:

  /**
   * @brief Construct an Undirected Graph
   * @param weighted_ Sets if graph is weighted
   */
  UndirectedGraph(bool weighted_ = false){
    Graph<N,E>(weighted_);
  }

};

/*****************************************************************************/

//! Directed Graph class goes here


/**
 * @brief The main graph class
 * @tparam N The weight type for Nodes
 * @tparam E The weight type for Edges
 */
template<class N, class E>
class Graph {

private:

bool weighted;


};

#endif