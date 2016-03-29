

/* 
 * File:   BinSearchTree.cpp
 * Author: Sean Moloney
 * Assignment: Lab 4 part C
 * 
 */

#include <string>
#include<iostream>
#include<algorithm>
#include <queue>
 #include <stack>
#include<vector>
#include "BinSearchTree.hpp"

using namespace std;

TreeNode *BinSearchTree::local_insert( TreeNode *root, int v){
    if (root == nullptr){
        return new TreeNode( v );
        }
    
    if (root->value() < v){
        root->rightSubtree(local_insert(root->rightSubtree(), v));
    }
    else
        root->leftSubtree(local_insert(root->leftSubtree(), v));
    
    return root;
}

void BinSearchTree::insert(int v){
    if(!find(v))
        root = local_insert(root, v);

}


bool BinSearchTree::find(int v){
    
    if(!findHelper(root, v)){
        return false; 
    }
    
    return true;
    
}


bool BinSearchTree::findHelper(TreeNode *tree, int v){
    if(tree == nullptr){
        return false;
    }
    if(tree->value() == v){
        return true;
    }
    if(tree->value() < v){
        return findHelper(tree->rightSubtree(), v);
    }
    else{
        return findHelper(tree->leftSubtree(), v);
    }
}

int BinSearchTree::size(){
    int sizeValue = sizeHelper(root);
    return sizeValue;
}
int BinSearchTree::sizeHelper(TreeNode *tree){
    if(tree == nullptr){
        return 0;
    }
    
    return 1+ sizeHelper(tree->leftSubtree()) + sizeHelper(tree->rightSubtree());
}

void BinSearchTree::inorderDump(){

    print(root);
}

void BinSearchTree::print(TreeNode* tree){
    if(tree == nullptr){
        return;
    }
    
    print(tree->leftSubtree());
     cout << tree->value() << endl;
     
    print(tree->rightSubtree());
    
}

void BinSearchTree::levelOrderDump(){
    levelOrderDumpHelp(root);
}

void BinSearchTree::levelOrderDumpHelp(TreeNode* tree){
    if(tree == nullptr){
        return;
    }
    
    queue<TreeNode *> curr, next;
    
    curr.push(tree);
    while(!curr.empty()){
        TreeNode *fNode = curr.front();
        curr.pop();
        
        if(fNode){
            cout << fNode->value() << " ";
            next.push(fNode->leftSubtree());
            next.push(fNode->rightSubtree());
        }
        
        if(curr.empty()){
            cout << endl;
            swap(curr, next);
        }
    }
    
    
}
void BinSearchTree::valuesAtLevel(int k){
 
  perLevelDump(root, k);
}

void BinSearchTree::iterValuesAtLevel(int k){
    findValueatLevel(root, k);
}

void BinSearchTree::findValueatLevel(TreeNode* node, int k){

  if(node == nullptr){
    return;
  }

  if(k == 1){
    cout << node->value() << endl;
  }
  
  int count = 1;
  queue<TreeNode *> current, next;
  current.push(node);

  while(!current.empty()){
    TreeNode *left = current.front();
    current.pop();
    if(left){
      if(count == k){
	cout << left->value() << endl;
	count = 1;
      }
      next.push(left->rightSubtree());
      count + 1;
    }
  }
}
    
  

void BinSearchTree::perLevelDump(TreeNode* tree, int k){
  if(k == 1){
    cout << tree->value() << endl;
  }

  if(tree->leftSubtree() != nullptr){
    perLevelDump(tree->leftSubtree(), k - 1);
  }
    if(tree->rightSubtree() != nullptr){
      perLevelDump(tree->rightSubtree(), k - 1);
    }


}
  



bool BinSearchTree::remove(int v) {
  bool isRemove = erase(root, v);
  return isRemove;
}


bool BinSearchTree::erase( TreeNode *tree, int v){
  if (tree == nullptr){
    return false;
  }

  else if( tree->value() > v ){
    erase(tree->leftSubtree(), v);
  }

  else if( tree->value() < v){
    erase(tree->rightSubtree(), v);
  }
  // Case 1: No child

  if (tree->leftSubtree() == nullptr && tree->rightSubtree() == nullptr){
    delete tree;
    tree = nullptr;
    return true;

  }

  // Case 2: One Child
  else if(tree->leftSubtree() == nullptr){
    TreeNode *tmp = tree;
    tree = tree->rightSubtree();
    delete tmp;
    return true;

  }
  else if(tree->rightSubtree() == nullptr){
    TreeNode *tmp = tree;
    tree = tree->leftSubtree();
    delete tmp;
    return true;
  }


  // Case 3: 2 Children
  else{
    int treeHeight= maxValue(tree->rightSubtree());
    tree->value() = treeHeight;
    erase(tree->rightSubtree(), treeHeight);
    return true;
  }
  return false;
}

int BinSearchTree::maxDepth(){
    
    int depth = maxValue(root);
    return depth;

}
int BinSearchTree::maxValue(TreeNode *n){
  if(!n) {
    return 0;
  }

  int left_height = maxValue(n->leftSubtree());
  int right_height = maxValue(n->rightSubtree());

  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}


int BinSearchTree::kthSmallest(int k){
  int kTh = findKth(root, k);

  return kTh;

}
int BinSearchTree::findKth(TreeNode* tree, int k){
  if(tree == nullptr){
    return 0;
  }
  int leftSize = sizeHelper(tree->leftSubtree());
  if(k == leftSize + 1){
    return tree->value();
  }
  else if( k > leftSize + 1){
    return findKth(tree->rightSubtree(), k - ( leftSize + 1));
  }
  else{
    return findKth(tree->leftSubtree(), k);
  }
}

int BinSearchTree::iterMaxDepth(){
  return findIterDepth(root);
}

int BinSearchTree::findIterDepth(TreeNode* tree){
  if(tree == nullptr){
    return 0;
  }

  queue<TreeNode *> p;
  p.push(tree);
  int height = 0;
  while(1){
    int nodeCount = p.size();
    if(nodeCount == 0){
      return height;
    }
    height++;

    while(nodeCount > 0){
      TreeNode *node = p.front();
      p.pop();
      if(node->leftSubtree() != nullptr){
	p.push(node->leftSubtree());
      }
      if(node->rightSubtree() != nullptr){
	p.push(node->rightSubtree());
      }
      nodeCount--;
    }
  }
}
bool BinSearchTree::hasRootToLeafSum(int sum){
  if(!findRootTreeSum(root, sum)){
    return false;
  }
  
  return true;
}

bool BinSearchTree::findRootTreeSum(TreeNode* tree, int sum){
  if(tree == nullptr){
    return false;
  }
  
  bool root = false;
  int treeSum = sum - tree->value();
  
  if(sum - tree->value() == 0 && tree->leftSubtree() == nullptr &&
     tree->rightSubtree() == nullptr){
    return true;
  }

  if(tree->leftSubtree()){
    root = root || findRootTreeSum(tree->leftSubtree(), treeSum );
  }

  if(tree->rightSubtree()){   
    root = root || findRootTreeSum(tree->rightSubtree(),treeSum);
  }

  return root;
  
}

bool BinSearchTree::areIdentical(BinSearchTree* bst){
    
    return compareTrees(root, bst->root);
}

bool BinSearchTree::compareTrees(TreeNode *node1, TreeNode *node2){
  if( node1 == nullptr && node2 == nullptr){
    return true;
  }

  else if ((node1 != nullptr && node2 == nullptr) || (node1 == nullptr && node2 != nullptr)){
    return false;
  }

  else if(node1->value() == node2->value()){
      return compareTrees(node1->leftSubtree(), node2->leftSubtree()) &&
	compareTrees(node1->rightSubtree(), node2->rightSubtree());
    }
    else{
      return false;
    }
    
}

BinSearchTree *BinSearchTree::intersectWith(BinSearchTree* bst){

  BinSearchTree *iTree = new BinSearchTree();
  findIntersection(root, bst->root, iTree);
  return iTree;
  
}

BinSearchTree *BinSearchTree::findIntersection(TreeNode* n1, TreeNode* n2, BinSearchTree *iTree){

    if(n1 == nullptr || n2 == nullptr){
        return nullptr;
    }
    if(findHelper(n2, n1->value())){
      iTree->insert(n1->value());
    }
    if(n1->leftSubtree() != nullptr){
      
     
     findIntersection(n1->leftSubtree(), n2, iTree); 
    }

    if(n1->rightSubtree() != nullptr){
      findIntersection(n1->rightSubtree(), n2, iTree);  
    }
    
     return iTree;
}

BinSearchTree *BinSearchTree::unionWith(BinSearchTree *bst){
  BinSearchTree *uTree = new BinSearchTree();
  uTree->findUnion(root, bst->root, uTree);
  return uTree;
}

void BinSearchTree::findUnion(TreeNode *node, TreeNode *node2, BinSearchTree *unionTree){

  if(node == nullptr &&  node2 != nullptr)
    {
      return;

    }

  if(node != nullptr && node2 == nullptr){
    return;
  }

  if(node == nullptr && node2 == nullptr){
    return;
  }

  if(node!= nullptr){ //node2 != nullptr){

    //if(node->leftSubtree() != nullptr ){
      findUnion(node->leftSubtree(), node2, unionTree);
     	unionTree->insert(node->value());
     
	// }

	//if( node->rightSubtree() != nullptr){
      	unionTree->insert(node->value());
      
      findUnion(node->rightSubtree(), node2, unionTree);
    
  }

 
   if(node2 != nullptr){
     // if(node2->leftSubtree() != nullptr){
       findUnion(node2->leftSubtree(), node, unionTree);
       	   unionTree->insert(node2->value());
	   // }
	   //if(node2->rightSubtree() != nullptr){
	findUnion(node2->rightSubtree(), node, unionTree);
	unionTree->insert(node2->value());
	// }
     
     
   }

   else{
     return;
   }
     
}


BinSearchTree *BinSearchTree::differenceOf(BinSearchTree *bst){
  BinSearchTree *diffTree = new BinSearchTree();
 diffTree->findDifference(root, bst->root, diffTree);
  return diffTree;
}

void *BinSearchTree::findDifference(TreeNode *node, TreeNode *node2, BinSearchTree *diffTree){
  if(node == nullptr){
    return node2;
  }

  if(node2 == nullptr){
    return node;
  }

  if(node == nullptr && node2 == nullptr){
    return nullptr;
  }

  if(node != nullptr){
    findDifference(node->leftSubtree(), node2, diffTree);
    
    if(!findHelper(node2, node->value())){
      diffTree->insert(node->value());
    }
  

    findDifference(node->rightSubtree(), node2, diffTree);

  }
  /*
  if( node2 != nullptr ){
    findDifference(node, node2->leftSubtree(), diffTree);
    if(!findHelper(node, node2->value())){
      diffTree->insert(node2->value());
    }

    findDifference(node, node2->rightSubtree(), diffTree);
  }
  */

  else{
    return diffTree;

  }

}
