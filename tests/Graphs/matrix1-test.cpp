/**
 * @file matrix1-test.cpp
 * @author Anthony Fabius
 * @brief 
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#include <iostream>
#include <cassert>
#include <vector>
#include "../../include/Graphs/Matrix.hpp"

int main(){
  std::cout << "Running tests on matrices\n";

  // Testing Edge and Weight functions
  Matrix m1(5); // Creates a 5x5 matrix
  assert(m1.getSize() == 5); // Assert size of 5
  assert(m1.addEdge(0,1) == 1); // Adds edge from node 0 to 1
  assert(m1.addEdge(1,0) == 1); // Adds edge from 1 to 0
  assert(m1.removeEdge(0,1,1) == 1); // Removes edge from 0 to 1 and 1 to 0
  assert(m1.addEdge(0,1,1) == 1); // Adds edge from 0 to 1 and 1 to  0
  assert(m1.hasEdge(0,1) == 1); // Assert edge from 0 to 1 exists
  assert(m1.hasEdge(1,0) == 1); // Assert edge from 1 to 0 exists
  assert(m1.addEdge(1,1) == 0); // Adding edge to self
  assert(m1.addEdge(-1,3) == 0); // Adding out of bound edge
  assert(m1.addEdge(4,10) == 0); // Adding out of bound edge
  assert(m1.getWeight(2,3) == 0); // Check weight of non existent edge
  assert(m1.getWeight(1,0) == 1); // Check weight of existing edge
  assert(m1.setWeight(1,0,2) == 1); // Set weight of edge
  assert(m1.getWeight(1,0) == 2); // Check weight of existing edge
  assert(m1.setWeight(2,3,5) == 1); // Create edge using weight
  assert(m1.hasEdge(2,3) == 1); // Check if edge exists
  m1.Transpose(); // Transpose matrix
  
  // Checking transposition
  assert(m1.getWeight(3,2) == 5);
  assert(m1.getWeight(2,3) == 0);
  assert(m1.getWeight(0,1) == 2);
  assert(m1.getWeight(1,0) == 1);

  // Testing Assignment and Copy
  Matrix m2(3);
  m2.addEdge(2,1); // Adding edge to see if its deleted upon assignment
  m2 = m1; // Assignment Operator Testing
  assert(m2.getSize() == 5); // Check size change
  assert(m2.getWeight(3,2) == 5); // Checking weight between edge
  assert(m2.hasEdge(2,1) == 0); // Checking if edge was deleted
  Matrix m3(m2); // Copy Constructor Test
  assert(m3.getSize() == 5); // Same tests from m2
  assert(m3.getWeight(3,2) == 5); 
  assert(m3.hasEdge(2,1) == 0);
  m3.addEdge(4,0);
  m1 = m3 = m2; // chained assignment testing
  assert(m1.getSize() == 5); // Same tests from m2
  assert(m1.getWeight(3,2) == 5); 
  assert(m1.hasEdge(2,1) == 0);

  // Testing getNeighbors
  m2.addEdge(3,1,1); // adding another edge to node 3
  std::vector<int> neighbors(m2.getNeighbors(3));
  assert(neighbors.size() == 2); // Only 1 and 2 should be present
  assert(neighbors[0] == 1); // Should be in numerical order
  assert(neighbors[1] == 2);
  std::vector<int> neighbors2(m2.getNeighbors(4));
  assert(neighbors2.size() == 0); // No neighbors should be present

  // Exceptions that can occur:
  // SizeException when Matrix has a size less than 1

  std::cout << "Passed matrices tests!\n";
}