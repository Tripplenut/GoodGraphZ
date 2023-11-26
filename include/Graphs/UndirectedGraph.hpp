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

#include "stddef.h"

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
  std::unordered_map<int, UndirectedEdge<E>*> Edges;
  int currentEdgeId = 0;
  bool weighted;

public:

  /**
   * @brief Constructs an Undirected Graph
   * @param weighted_ Sets if graph is weighted
   */
  UndirectedGraph(bool weighted_ = false){
    weighted = weighted_;
  }

  /**
   * @brief Destroys an Undirected Graph
   */
  ~UndirectedGraph(){
    for(auto iter = Nodes.begin(); iter != Nodes.end(); iter++){
      delete iter->second;
    }

    for(auto iter = Edges.begin(); iter != Edges.end(); iter++){
      delete iter->second;
    }

    Nodes.clear();
    Edges.clear();
  }

  /**
   * @brief Adds a node to the graph
   * @param nodeId The name of the node
   * @param weight Optional weight for the node
   * @return true If node was successfully added
   * @return false If node could not be added
   */
  bool addNode(std::string nodeId){
    //! Gonna need some error checking
    if (Nodes.count(nodeId) != 0) // make sure nodes don't already exist
      return false;
    
    Nodes[nodeId] = new UndirectedNode<N>(nodeId);
    return true;
  }

  //TODO add weighted nodes

  /**
   * @brief Removes a node from the graph
   * @param nodeId The id of the node
   * @return true If node was removed
   * @return false If node could not be removed
   */
  bool removeNode(std::string nodeId){
    if (Nodes.count(nodeId) == 0) // Make sure node exists
      return false;
    std::vector<std::string> otherNodeIds = Nodes[nodeId]->getEdgeNodes();
    std::vector<int> NodeEdgeIds = Nodes[nodeId]->getEdgeIds();

    // Removing all edges from the nodes
    for(int i=0; i < otherNodeIds.size(); i++){
      Nodes[nodeId]->removeEdge(otherNodeIds[i]);
      Nodes[otherNodeIds[i]]->removeEdge(nodeId);
      delete Edges[NodeEdgeIds[i]];
      Edges.erase(NodeEdgeIds[i]);
    }
    
    delete Nodes[nodeId];
    Nodes.erase(nodeId);
    return true;
  }


  /**
   * @brief Adds an edge to the graph
   * @param node1Id The id of the first node
   * @param node2Id The id of the second node
   * @return true If edge was successfully added
   * @return false If edge could not be added
   */
  bool addEdge(std::string node1Id, std::string node2Id){
    //! Gonna need a bunch of error checking (edge doesn't already exist)
    if(node1Id == node2Id) // Make sure nodes don't point to themselves
      return false;
    addNode(node1Id);
    addNode(node2Id);
    if(Nodes.at(node1Id)->getEdgeId(node2Id) != -1) // Makes sure edge doesn't already exist
      return false;
    Edges[Edges.size()] = new UndirectedEdge<E>(currentEdgeId, node1Id, node2Id);
    Nodes.at(node1Id)->addEdge(node2Id,currentEdgeId);
    Nodes.at(node2Id)->addEdge(node1Id,currentEdgeId);
    currentEdgeId++;
    return true;
  }

  //TODO add weighted edges

  //TODO add removing edges

  /**
   * @brief Removes an edge from the graph
   * @param node1Id The id of the first node
   * @param node2Id The id of the second node
   * @return true If edge was successfully removed
   * @return false If edge could not be removed
   */
  bool removeEdge(std::string node1Id, std::string node2Id){
    if(Nodes.count(node1Id) == 0 || Nodes.count(node2Id) == 0) // Make sure nodes exist
      return false;
    int edgeId = Nodes.at(node1Id)->getEdgeId(node2Id);
    if(edgeId == -1) // Make sure edge exists
      return false;
    delete Edges[edgeId];
    Edges.erase(edgeId);
    Nodes.at(node1Id)->removeEdge(node2Id);
    Nodes.at(node2Id)->removeEdge(node1Id);
    return true;
  }

  // Some Getters (mainly for testing rn)

  /**
   * @brief Returns the number of nodes in the graph
   * @return int 
   */
  int NodesSize(){
    return Nodes.size();
  }

  /**
   * @brief Returns the number of edges in the graph
   * @return int 
   */
  int EdgesSize(){
    return Edges.size();
  }
};

#endif