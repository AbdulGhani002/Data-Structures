#ifndef GRAPH_H
#define GRAPH_H

#define MAX_ITERATIONS 1000

namespace data_structures{
template <class T>
  class Graph{
 protected:
  
 };

 template <class T>
   class Node{
 public:
   T data;
   Node* connected_nodes[MAX_ITERATIONS] = {NULL};

   Node(){
     std::cout<<"Node Initialized"<<std::endl;
   }

     void show_neighbouring_nodes(void){
    for (int i=0;i<MAX_ITERATIONS;i++){
      if(Node::connected_nodes[i] == NULL){
	return;
      }
      std::cout<<connected_nodes[i]->data<<"  "<<std::endl;
    }
  }


  void connect_to(Node* node){
    for(int i=0;i<MAX_ITERATIONS;i++){
      if(connected_nodes[i] == NULL){
	connected_nodes[i] = node;
	return;
      }
    }
  }
   
 };



};


#endif //GRAPH_H
