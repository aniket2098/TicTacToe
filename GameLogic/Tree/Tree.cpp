#include<bits/stdc++.h>
#include "Tree.h"

Tree :: Tree() {

    decisionTree = new tree;
    decisionTree2 = new tree;

}

tree* Tree :: createNodes1(tree* head,int row1,int column1,int row2,int column2,int row3,int column3) {

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

    decisionTree->link = new tree* [5]; 

    for(int i = 0; i<5; i++)
        decisionTree->link[i] = new tree;
        
    createNodes1(decisionTree->link[0],0,1,1,1,2,0);
    createNodes1(decisionTree->link[1],0,2,2,0,2,2);
    createNodes1(decisionTree->link[2],1,2,2,0,1,1);
    createNodes1(decisionTree->link[3],2,2,2,0,0,2);
    createNodes1(decisionTree->link[4],1,1,2,0,-1,-1);

}

tree* Tree :: createNodes2(tree* head, int* row, int* column) {

    tree* temp = head;
    temp->row = row[0];
    temp->column = column[0];
    temp->link = new tree* [1];
    temp->link[0] = new tree;
    temp = temp->link[0];
    temp->row = row[1];
    temp->column = column[1];

    temp->link = new tree* [3];
    for(int i = 0; i <3; i++)
        temp->link[i] = new tree;

    head = temp;

    for(int i = 0; i < 3;i++) {
     
        temp = head->link[0 + i];
        temp->row = row[2 + i];
        temp->column = column[2 + i];
        temp->link = new tree* [1 + i];
        temp->link[0] = new tree;
        temp = temp->link[0];
        temp->row = row[5 + i];
        temp->column = column[5 + i];
        temp->link = new tree* [1];
        temp->link[0] = NULL;
    
    }

    // temp = head->link[1];
    // temp->row = row[3];
    // temp->column = column[3];
    // temp->link = new tree* [1];
    // temp->link[0] = new tree;
    // temp = temp->link[0];
    // temp->row = row[6];
    // temp->column = column[6];
    // temp->link = new tree* [1];
    // temp->link[0] = NULL;

    // temp = head->link[2];
    // temp->row = row[4];
    // temp->column = column[4];
    // temp->link = new tree* [1];
    // temp->link[0] = new tree;
    // temp = temp->link[0];
    // temp->row = row[7];
    // temp->column = column[7];
    // temp->link = new tree* [1];
    // temp->link[0] = NULL;

}

void Tree :: createDecisionTree2() {

    decisionTree2->link = new tree* [3]; 

    for(int i = 0; i <3; i++)
        decisionTree2->link[i] = new tree;
    
    int row1[8] = {1,0,1,2,2,1,2,0};
    int column1[8] = {1,0,0,2,0,2,0,1};
    int row2[8] = {0,1,1,2,2,0,0,2};
    int column2[8] = {0,1,2,2,1,2,1,0};
    int row3[8] = {0,1,1,2,2,0,0,0};
    int column3[8] = {1,1,0,0,1,0,0,0};
    createNodes2(decisionTree2->link[0],row1,column1);
    createNodes2(decisionTree2->link[1],row2,column2);
    createNodes2(decisionTree2->link[2],row3,column3);

}

tree* Tree :: returnHead1() {

    return decisionTree;

}

tree* Tree :: returnHead2() {

    return decisionTree2;

}