/** @file Graphs.hpp
 * @brief This is where all things Graph related are stored
*/

#ifndef GRAPHS_HPP
#define GRAPHS_HPP

// CPP includes
#include <set>

// GGZ includes
#include "Nodes.hpp"
#include "Edges.hpp"

template<class N, class E>
class Graph {

private:

std::set<Node<N>> Nodes;
std::set<Edge<E>> Edges;

public:

  //TODO - Create Constructors, Destructors, and Assignment Operators

  //TODO - Node and Edge Creation and Deletion

  //TODO - Node and Edges Getters and Setters

  //TODO - Create an Alert System
  // For example check if there are mixture of directed and undirected Edges

};

#endif