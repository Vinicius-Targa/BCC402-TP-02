//10247 Complete Tree Labeling!

/*
A complete k-ary tree is a k-ary tree in which all leaves have same depth and all internal nodes have degree k. This k is also known as the branching factor of a tree. It is very easy to determine the number of nodes of such a tree. Given the depth and branching factor of such a tree, you will have to determine in how many different ways you can number the nodes of the tree so that the label of each node is less that that of its descendants. You should assume that for numbering a tree with N nodes you have the (1, 2, 3, N − 1, N) labels available.
*/

#include <iostream>

using namespace std;

int treeLabeling(int k, int d){
  return 0;
}


//entrada
int main(){
  int k, d, res;

  while(cin>>k>>d){
    res = treeLabeling(k, d);

    cout<<res<<endl;
  }
  return 0;
}
