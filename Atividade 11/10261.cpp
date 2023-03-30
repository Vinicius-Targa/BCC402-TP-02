// 10261 - Ferry Loading

/*
Before bridges were common, ferries were used to transport cars across rivers.
River ferries, unlike their larger cousins, run on a guide line and are powered
by the river’s current. Two lanes of cars drive onto the ferry from one end, the
ferry crosses the river, and the cars exit from the other end of the ferry. The
cars waiting to board the ferry form a single queue, and the operator directs
each car in turn to drive onto the port (left) or starboard (right) lane of the
ferry so as to balance the load. Each car in the queue has a different length,
which the operator estimates by inspecting the queue. Based on this inspection,
the operator decides which side of the ferry each car should board, and boards
as many cars as possible from the queue, subject to the length limit of the
ferry. Your job is to write a program that will tell the operator which car to
load on which side so as to maximize the number of cars loaded.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> ferryLoading(vector<int> vet, int length){
  
}

// entrada
int main(){ 
  int cases, length, aux;
  vector<int> vet, ans;

  cin>>cases;
  
  for(int i = 0; i < cases; i++){
    cin>>length;
    while(true){
      cin>>aux;
      if(aux == 0)
        break;
      else
        vet.push_back(aux);
    }
    ans = ferryLoading(vet, length);
  }
  return 0; 
}