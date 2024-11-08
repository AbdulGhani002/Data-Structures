#include<iostream>
#include "Queue.h"
using namespace std;

int main(void){
  Queue<int> queue;
  queue.init(10);
  queue.enque(1);
  queue.enque(3);
  queue.display();
  queue.deque();
  queue.display();
}
