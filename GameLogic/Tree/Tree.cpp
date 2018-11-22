#include<bits/stdc++.h>
#include "Tree.h"

Tree :: Tree() {

    decisionTree = new tree;

}

tree* Tree :: createNodes(tree* head,int row1,int column1,int row2,int column2,int row3,int column3) {

    tree* temp = head;
    temp->row = row1;
    temp->column = column1;
    temp->link = new tree* [1];
    temp->link[0] = new tree;
    temp = temp->link[0];
    temp->row = row2;
    temp->column = column2;
    if(row3>=0) {
        temp->link = new tree* [1];
        temp->link[0] = new tree;
        temp = temp->link[0];
        temp->row = row3;
        temp->column = column3;
    }
    temp->link = new tree* [1];
    temp->link[0] = NULL;
}

void Tree :: createDecisionTree1() {

    tree* temp;

    decisionTree->link = new tree* [5]; 

    for(int i = 0; i<5; i++)
        decisionTree->link[i] = new tree;
        
    createNodes(decisionTree->link[0],0,1,1,1,2,0);
    createNodes(decisionTree->link[1],0,2,2,0,2,2);
    createNodes(decisionTree->link[2],1,2,2,0,1,1);
    createNodes(decisionTree->link[3],2,2,2,0,0,2);
    createNodes(decisionTree->link[4],1,1,2,0,-1,-1);

}

tree* Tree :: returnHead() {

    return decisionTree;

}