
/* 
 * File:   BinSearchTree.hpp
 * Author: Sean Moloney
 * Assignment: Lab 4 Part C
 * 
 */

#ifndef BINSEARCHTREE_HPP
#define BINSEARCHTREE_HPP
#include "TreeNode.hpp"
#include <vector>
#include <queue>

class TreeNode;

class BinSearchTree {
public:
    void insert( int v); // working
    bool find(int v); // working
    bool iterFind( int v); // working
    bool remove(int v);
    
    int size(); // working
    
    void inorderDump(); // working
    void levelOrderDump(); // working
    
    int maxDepth(); // working
    int iterMaxDepth(); // working
    int kthSmallest(int k); // working
    
    void valuesAtLevel(int k); // working
    void iterValuesAtLevel( int k); // working
    
    bool hasRootToLeafSum (int sum); // working
    
    bool areIdentical(BinSearchTree *bst);
    
    BinSearchTree *intersectWith(BinSearchTree *bst);
    BinSearchTree *unionWith (BinSearchTree *bst);
    BinSearchTree  *differenceOf(BinSearchTree *bst);

    
private:
    TreeNode *local_insert(TreeNode *, int);
    TreeNode *root;
  int maxValue(TreeNode *n);

  
  bool findHelper(TreeNode *tree, int v);
  int sizeHelper(TreeNode *tree);
  
  void print(TreeNode *tree);
  
  void levelOrderDumpHelp(TreeNode *tree);
  void perLevelDump(TreeNode *tree, int k);
  bool erase(TreeNode * tree, int v);
  void swapValues(TreeNode *node, TreeNode *node2);
  
  int findKth(TreeNode *tree, int k);
  bool findRootTreeSum(TreeNode *tree, int sum);
  int findIterDepth(TreeNode *tree);
  bool compareTrees(TreeNode *node1, TreeNode *node2);
  BinSearchTree *findIntersection(TreeNode *n1, TreeNode * n2, BinSearchTree *iTree);
  void  findUnion(TreeNode *node, TreeNode *node2, BinSearchTree *unionTree);
 
  void findValueatLevel(TreeNode *node, int k);
  void *findDifference(TreeNode *node, TreeNode *node2, BinSearchTree *diffTree);
};

#endif /* BINSEARCHTREE_HPP */

