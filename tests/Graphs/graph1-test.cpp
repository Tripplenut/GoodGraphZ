/**
 * @file test_graph1.cpp
 * @author Anthony Fabius
 * @brief Basic Testing of the Graph, Edges, and Node classes
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#include <iostream>
#include <cassert>
#include "../../include/Graphs/UndirectedGraph.hpp"

int main(){
  UndirectedGraph<int,int> graph1;

  std::cout << "Testing Nodes and Edges\n";
  assert(graph1.addNode("a") == 1);
  assert(graph1.addNode("a") == 0);
  assert(graph1.AddEdge("a","b") == 1);
  assert(graph1.AddEdge("a","b") == 0);
  assert(graph1.AddEdge("b","a") == 0);
  assert(graph1.AddEdge("b","b") == 0);
  std::cout << "Passed Nodes and Edge Tests!\n";
  
  return 0;
}