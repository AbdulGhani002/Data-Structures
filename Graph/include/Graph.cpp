#include<iostream>
#include "Graph.h"
using namespace data_structures;

int main(void){
  Node<int> node1;
  node1.data = 5;
  Node<int> node2;
  node2.data = 10;
  Node<int> node3;
  node3.data = 15;
  node1.connect_to(&node2);
  node1.connect_to(&node3);
  node1.show_neighbouring_nodes();
}
