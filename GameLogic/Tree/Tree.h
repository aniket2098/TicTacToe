#include<bits/stdc++.h>
#include "treeNodeStructure.h"

class Tree {
    
    private:
        tree* decisionTree;
        tree* decisionTree2;
    
    public:
        void createDecisionTree1();
        void createDecisionTree2();
        tree* createNodes1(tree*,int,int,int,int,int,int);
        tree* createNodes2(tree*,int*,int*);
        tree* returnHead();
        Tree();
};