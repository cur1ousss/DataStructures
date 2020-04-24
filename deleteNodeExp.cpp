#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node *delete_node(struct node *start){
//  ? Places deleted first node onto last without deletin freeing it
            // use for reversing linked list ?

                // Xor to reverse linked list?


struct node *delete_node(struct node *start){

struct node *ptr=start;

    int data;
    cout<<"\n enter node to delete";
    cin>>data;


while(ptr->next!=start){

    if(ptr==start && ptr->data==data){
        struct node *tmp=start;
        ptr=ptr->next;
        start=ptr;
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=ptr;
    }


ptr=ptr->next;
}
    return start;
}