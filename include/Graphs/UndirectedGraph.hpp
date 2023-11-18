/**
 * @file UndirectedGraph.hpp
 * @author Anthony Fabius
 * @brief This is where all things Undirected Graph related are stored
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef UNDIRECTEDGRAPHS_HPP
#define UNDIRECTEDGRAPHS_HPP

// CPP includes
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// GGZ includes
#include "UndirectedNode.hpp"
#include "UndirectedEdge.hpp"


/**
 * @brief The Undirected Graph class
 * @tparam N The weight type for Nodes
 * @tparam E The weight type for Edges
 */
template <class N, class E>
class UndirectedGraph {
private:

  std::unordered_map<std::string, UndirectedNode<N>*> Nodes;
  std::unordered_map<std::string, UndirectedEdge<E>*> Edges;

  bool weighted;

public:

  /**
   * @brief Constructs an Undirected Graph
   * @param weighted_ Sets if graph is weighted
   */
  UndirectedGraph(bool weighted_ = false){
    weighted = weighted_;
  }

};

#endif