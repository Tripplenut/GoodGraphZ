/**
 * @file Matrix.hpp
 * @author Anthony Fabius
 * @brief This is where all things matrix related are stored
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
*/

//! Switch from bool returns to exception throws

#ifndef MATRIX_HPP
#define MATRIX_HPP

// CPP Includes
#include <iostream>
#include <vector>

// GGZ Includes
#include "../Tools/exceptions.hpp"

class Matrix{

private:

  std::vector<std::vector<int>> data;
  int size;

public:

  /**
   * @brief Creates a new Matrix object
   * @param size_ The size of the matrix
   */
  Matrix(int size_){
    if(size_ < 1){
      throw SizeException("Matrix must have size greater than 0.");
    }
    data.resize(size_);
    for(int r=0; r<size_; r++){
      data[r].resize(size_);
      for(int c=0; c<size_; c++){
        data[r][c] = 0;
      }
    }
    size = size_;
  }

  /**
   * @brief Creates a copy of another Matrix
   * @param other The matrix you want to copy
   */
  Matrix(Matrix& other){
    int size_ = other.getSize();
    data.resize(size_);
    for(int r=0; r<size_; r++){
      data[r].resize(size_);
      for(int c=0; c<size_; c++){
        data[r][c] = other.getWeight(r,c);
      }
    }
    size = size_;
  }

  /**
   * @brief Assignment Operator
   * @param other The matrix you want to copy
   * @return Matrix& The current matrix
   */
  Matrix& operator=(Matrix& other){
    data.clear();
    int size_ = other.getSize();
    data.resize(size_);
    for(int r=0; r<size_; r++){
      data[r].resize(size_);
      for(int c=0; c<size_; c++){
        data[r][c] = other.getWeight(r,c);
      }
    }
    size = size_;
    return *this;
  }

  /**
   * @brief Adds a edge to the graph
   * @param source Index of source node
   * @param target Index of target node
   * @param both If you want target to add an edge to source
   * @return true If edge successfully added
   * @return false If edge unsuccessfully added
   */
  bool addEdge(int source, int target, bool both = false){
    if(size < source || size < target || source < 0 || target < 0 || source == target)
      return false;
    data[source][target] = 1;
    if(both)
      data[target][source] = 1;
    return true;
  }

  /**
   * @brief Removes a edge to the graph
   * @param source Index of source node
   * @param target Index of target node
   * @param both If you want target to add an edge to source
   * @return true If edge successfully removed
   * @return false If edge unsuccessfully removed
   */
  bool removeEdge(int source, int target, bool both = false){
    if(size < source || size < target || source < 0 || target < 0 || source == target)
      return false;
    data[source][target] = 0;
    if(both)
      data[target][source] = 0;
    return true;
  }

  /**
   * @brief Checks if an edge exists
   * @param source Index of source node
   * @param target Index of target node
   * @return true If edge exists
   * @return false If edge does not exist
   */
  bool hasEdge(int source, int target){
    if(size < source || size < target || source < 0 || target < 0)
      return false;
    return data[source][target];
  }

  /**
   * @brief Get the neighbors of a node
   * @param node Index of the node
   * @return std::vector<int>& Vector off all neighbors of node
   */
  std::vector<int> getNeighbors(int node){
    std::vector<int> res;
    for(int c = 0; c < size; c++){
      if(data[node][c] != 0)
        res.push_back(c);
    }
    return res;
  }

  /**
   * @brief Gets the weight of an edge
   * @param source Index of source node
   * @param target Index of target node
   * @return int 
   */
  int getWeight(int source, int target){
    if(size < source || size < target || source < 0 || target < 0)
      return 0;
    return data[source][target];
  }

  /**
   * @brief Set the weight of an edge
   * @param source Index of source node
   * @param target Index of target node
   * @param weight weight assigned to edge
   * @return true If weight was set
   * @return false If weight was not set
   */
  bool setWeight(int source, int target, int weight){
    if(size < source || size < target || source < 0 || target < 0 || source == target)
      return false;
    data[source][target] = weight;
    return true;
  }


  /**
   * @brief Returns the size of the matrix 
   * @return int 
   */
  int getSize(){
    return size;
  }

  void Transpose(){
    for(int r = 0; r < size; r++){
      for(int c = 0; c < r; c++){
        int temp = data[r][c];
        data[r][c] = data[c][r];
        data[c][r] = temp;
      }
    }
  }

  /**
   * @brief Displays the matrix to the console
   */
  void display(){
    std::cout << "  ";
    for(int c = 0; c<size; c++){
      std::cout << c << " ";
    }
    std::cout << "\n";
    for(int r = 0; r<size; r++){
      std::cout << r << " ";
      for(int c = 0; c<size; c++){
        std::cout << data[r][c] << " ";
      }
      std::cout << "\n";
    }
  }

};

#endif