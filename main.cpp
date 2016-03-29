#include <iostream>
#include <fstream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

using namespace std;

int main(int argc, char *argv[]){

  BinSearchTree *tree = new BinSearchTree();
  
  BinSearchTree *tree2 = new BinSearchTree();
  int v;
  int x;
  while (cin >> v){
      tree->insert(v);
      tree2->insert(v);
  }

  
  cout << "Size is: " << tree->size() << endl;
  
  cout << "Depth is:" << tree->maxDepth() << endl;

  cout << "inOrderDump" << endl;
  tree->inorderDump();
  tree2->inorderDump();
  cout << "LevelOrderDump: " << endl;
  tree->levelOrderDump();

  cout << "findRootTreeSum: " << endl;
  bool sum =  tree->hasRootToLeafSum(27);
    if(!sum){
         cout << "No Path found" << endl;
             }
     if(sum){
            cout << "Path found" << endl;
             }

     cout << "Value per level" << endl;
     tree->valuesAtLevel(2);
       cout << endl;

       cout << "Value Per level iterative" << endl;
       tree->iterValuesAtLevel(1);
       cout << endl;
       
  cout << "kthSmallest: " << endl;
  cout << tree->kthSmallest(3) << endl;

  cout << "Iter Max Depth" << endl;
  cout << tree->iterMaxDepth() << endl;
  // cout << "Delete: " << endl;
  
  //tree->remove(1);

  // tree->inorderDump();

  BinSearchTree *iTree = tree->intersectWith(tree2);
 cout << "Intersect dump: " << endl;
  iTree->inorderDump();

 cout << "Identical? " << endl;
  bool identical = tree->areIdentical(tree2);

  if(identical){
    cout << "Trees are identical" << endl;
  }
  if(!identical){
    cout << "Trees are not identical" << endl;
  }

  tree->insert(7);
  tree->insert(30);

  tree2->insert(8);

  
  cout << "Union: " << endl;
  BinSearchTree *unionTree = tree->unionWith(tree2);
  unionTree->inorderDump();

  cout << "Difference:  " << endl;

  BinSearchTree* diffTree = tree->differenceOf(tree2);
  diffTree->inorderDump();

  return 0;
}

