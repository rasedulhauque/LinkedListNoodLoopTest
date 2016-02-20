/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rased
 *
 * Created on February 20, 2016, 1:30 PM
 */
#include<iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * 
 */
struct Node{
    int data;
    Node* next;
};
bool dataLoopTest(Node* list){
    Node* slow=list;
    Node* fast=list;
    
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node =
          (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_Node->data  = new_data;
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}

int main(int argc, char** argv) {
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    cout<< dataLoopTest(head) <<endl;
    return 0;
}

