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
  std::cout << "Running tests on undirected graphs\n";
  std::cout << "Testing Unweighted Graphs\n";
  UndirectedGraph<int,int> graph1; // Constructs an unweighted undirected graph

//TODO Start adding tests for node and edge public member functions, ex getWeight should be returning null

  // Node Testing
  assert(graph1.NodesSize() == 0); // assert 0 nodes
  assert(graph1.EdgesSize() == 0); // assert 0 edges
  assert(graph1.node("a") == NULL); // make sure null on non existent node
  assert(graph1.addNode("a") == 1); // node Creation
  assert(graph1.addNode("a") == 0); // adding existing Node
  assert(graph1.NodesSize() == 1); // assert 1 node {a}
  assert(graph1.node("a") != NULL); // make sure node exists

  // Edge creation Testing
  assert(graph1.addEdge("a","b") == 1); // edge Creation
  assert(graph1.addEdge("a","b") == 0); // adding existing Edge
  assert(graph1.addEdge("b","a") == 0); // above flipped
  assert(graph1.addEdge("b","b") == 0); // adding edge to same node
  assert(graph1.addEdge("a","c") == 1); // creating node and edge with existing node
  assert(graph1.NodesSize() == 3); // assert 3 nodes {a,b,c}
  assert(graph1.EdgesSize() == 2); // assert 2 edges {a-b,a-c}

  // Edge removal testing
  assert(graph1.removeEdge("a","b") == 1); // removing edge
  assert(graph1.removeEdge("b","a") == 0); // removing non existent edge
  assert(graph1.removeEdge("a","a") == 0); // removing edge from same node 
  assert(graph1.EdgesSize() == 1); // assert 1 edge {a-c}

  // Node removal testing
  assert(graph1.removeNode("a") == 1); // removing existing node
  assert(graph1.removeNode("a") == 0); // removing non existing node
  assert(graph1.removeEdge("c","a") == 0); // removing edge from non existing node
  assert(graph1.NodesSize() == 2); // assert 2 nodes {b,c}
  assert(graph1.EdgesSize() == 0); // assert 0 edges

  std::cout << "Passed Unweighted Graph Tests!\n";

// TODO clean up the weighted tests and add more (after finishing edge weight implementation)

  std::cout << "Testing Weighted Graphs\n";
  UndirectedGraph<int,int> graph2(true); // Constructs a weighted undirected graph

  // Node Testing
  assert(graph2.NodesSize() == 0); // assert 0 nodes
  assert(graph2.EdgesSize() == 0); // assert 0 edges
  assert(graph2.addNode("a",1) == 1); // node Creation
  assert(graph2.addNode("a",2) == 0); // adding existing Node
  assert(graph2.NodesSize() == 1); // assert 1 node {a}
  assert(graph2.node("a")->getWeight() == 1); // assert weight of a is 1

  // Edge creation Testing
  assert(graph2.addEdge("a","b") == 1); // edge Creation
  assert(graph2.addEdge("a","b") == 0); // adding existing Edge
  assert(graph2.addEdge("b","a") == 0); // above flipped
  assert(graph2.addEdge("b","b") == 0); // adding edge to same node
  assert(graph2.addEdge("a","c") == 1); // creating node and edge with existing node
  assert(graph2.NodesSize() == 3); // assert 3 nodes {a,b,c}
  assert(graph2.EdgesSize() == 2); // assert 2 edges {a-b,a-c}
  // Node and Edge weight manipulation



  std::cout << "Passed Weighted Graphs\n";
  
  std::cout << "Testing Construction, Destruction, Assignment, and Copy\n";
  std::cout << "Finished undirected graph tests\n";

  return 0;
}