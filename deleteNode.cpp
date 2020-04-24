#include<iostream>
using namespace std;
//some repetitions not deleted 
    // between 2 unique nums if mulitple occ 1 left behind all else occs deleted
    struct node{
        int data;
        struct node *next;
    };
    
    struct node *start=NULL;


struct node *delete_node(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=ptr;
    int data;
    cout<<"\n enter node to delete";
    cin>>data;

    struct node *tmp=start;

while(ptr->next!=start){

    if(ptr==start && ptr->data==data){
        
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start->next;
        start=start->next;
    }
    else if(pre_ptr->data==data){
        pre_ptr->next=ptr->next;
    }
pre_ptr=ptr;
ptr=ptr->next;
}
// for last eleement
if(ptr->data==data){
    pre_ptr->next=ptr->next;
    start=pre_ptr->next;
}

// display(start);
    return start;
}
/*****************************************************************
                        // ??? some repetitions not deleted 
    // between 2 unique nums if 2 mulitple occ 1 left behind all else occs deleted
    // between 2 unique nums if 3 mulitple occ 2 left behind all else occs deleted
                                4 >> 2
struct node *delete_node(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=ptr;
    int data;
    cout<<"\n enter node to delete";
    cin>>data;

    struct node *tmp=start;

while(ptr->next!=start){

    if(ptr==start && ptr->data==data){
        
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start->next;
        start=start->next;
    }
    else if(ptr->data==data){
        pre_ptr->next=ptr->next;
    }

pre_ptr=ptr;
ptr=ptr->next;
}
// for last eleement
if(ptr->data==data){
    pre_ptr->next=ptr->next;
    start=pre_ptr->next;
}

display(start);
    return start;
}

*********************************************************************************************************************************
        Places deleted first node onto last without deletin freeing it
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

*****************************also puts delted element at last ****************************************************************
*/
