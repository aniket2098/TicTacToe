#include<bits/stdc++.h>
#include "treeNodeStructure.h"

class Tree {
    
    private:
        tree* decisionTree;
    
    public:
        void createDecisionTree1();
        tree* createNodes(tree*,int,int,int,int,int,int);
        tree* returnHead();
        Tree();
};