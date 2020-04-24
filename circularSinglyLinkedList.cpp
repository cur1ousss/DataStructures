#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;


struct node *display(struct node *start){

    struct node *ptr=start;
    cout<<"\n Printing List\t";
    while(ptr->next!=start){    // ptr reaches end node pointing to end node
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
        cout<<ptr->data;    // for last node since excluded in above 
// since in above while loop if write ptr->next above print then skip first node print so sacrifice and write extra for either first node or last node
            /*  OR could write as below

            cout<<  first node data
    while(ptr->next!=start){
        ptr=ptr->next;
        cout<<ptr->data<<" -> ";    // this cout also prints last node data //since above cout is before shifting ptr sacrifice cannot print last node data in above method
    }*/
    
    return start;   
}

struct node *create(struct node *start){

cout<<"\n Enter -1 to end";
cout<<"\n Enter data of Node ";
int data;

while(1){

cin>>data;
if(data==-1)
    break;

    if(start==NULL){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;
        start=new_node;
        new_node->next=new_node;
    }
    else{
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;

    struct node *ptr=start;

        while(ptr->next!=start){
        ptr=ptr->next;
        }

        ptr->next=new_node;
        new_node->next=start;
    }

}
display(start);
    return start;
}

// works for mulitple occ
struct node *search_list(struct node *start){

struct node *ptr=start;

    cout<<"\n enter number to search";
    int data;
    cin>>data;

int node=1;

    while(ptr->next!=start){
        if(ptr->data==data)
            cout<<"\n found at postion node "<<node;
        node++;
        ptr=ptr->next;
    }

    return start;
}


struct node *insert_beg(struct node *start){

    struct node *ptr=start;

struct node *new_node=(struct node *)malloc(sizeof(struct node));

int data;
cout<<"\n Enter data";
cin>>data;
new_node->data=data;

new_node->next=start;

    while(ptr->next!=start)
        ptr=ptr->next;

ptr->next=new_node;
start=new_node;

/************************Creates seg fault********************************************************************
    
     // why wrong why not implicitly last elemnet updated??
     LESSON >>      // because start at the time of creation the last node next was fixed to ex first node 
             as start hence not updated since create() func called in the past

  struct node *insert_beg(struct node *start){

    struct node *ptr=start;

struct node *new_node=(struct node *)malloc(sizeof(struct node));

int data;
cout<<"\n Enter data";
cin>>data;
new_node->data=data;

 new_node->next=start;

start=new_node;

display(start);

    return start;
}*/

display(start);

    return start;
}

struct node *insert_end(struct node *start){

    struct node *ptr=start;

    while(ptr->next!=start){
        ptr=ptr->next;
    }    

    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    cout<<"\n enter data";
    int data;
    cin>>data;

    new_node->data=data;
    
    ptr->next=new_node;
    new_node->next=start;

   display(start);
return start;
}

//?? EDGE CASE >>   delete beg and end stable if only one elemnet in list?
        // SOLVE using 
        /*  
        struct node *ptr=start;
            if(ptr->next==start)
                cout<<"\n only one node present deleting that"
                start=NULL
        */

struct node *delete_beg(struct node *start){


struct node *ptr=start;
struct node *tmp=start;

while(tmp->next!=start){
    tmp=tmp->next;
}

ptr=ptr->next;
start=ptr;
tmp->next=ptr;

    return start;
}

struct node *delete_end(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=start;

while(ptr->next!=start){
    pre_ptr=ptr;
    ptr=ptr->next;
}

pre_ptr->next=start;

ptr->next=NULL;
display(start);
    return start;
}


struct node *delete_node(struct node *start){

    struct node *ptr=start;

    struct node *org_start=start;

    struct node *pre_ptr=ptr;
    int data;
    cout<<"\n enter node to delete";
    cin>>data;

struct node *traverse=start;
int countNodes=0;
while(traverse->next!=start){
    if(traverse->data==data)
        countNodes++;

    traverse=traverse->next;
}

struct node *changed_start;

for(int i=0;i<countNodes;i++){

cout<<"\n For loop count "<<i;

while(ptr->next!=start){

    cout<<"\n entering while loop   ";
        struct node *tmp=org_start;

    if(ptr==org_start && ptr->data==data){
        
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start->next;
        free(start);
        start=start->next;
        changed_start=start;
    }
    else if(ptr->data==data){
        // pre_ptr->next=ptr->next; // also works
        pre_ptr->next=pre_ptr->next->next;   
        free(ptr);
        // ptr=ptr->next;
    }
pre_ptr=ptr;
// ptr=pre_ptr->next;
ptr=ptr->next;
}
// for last eleement
if(ptr->data==data){
    pre_ptr->next=ptr->next;
    free(ptr);
    start=pre_ptr->next;
    changed_start=start;

}

start=org_start;

}
start=changed_start;

display(start);

return start;
}
/**************************************************************
        * DELETES all mulitple Occurence but inserts 2 garbage for 4 conitnious deletions
struct node *delete_node(struct node *start){

    struct node *ptr=start;

    struct node *org_start=start;

    struct node *pre_ptr=ptr;
    int data;
    cout<<"\n enter node to delete";
    cin>>data;

struct node *traverse=start;
int countNodes=0;
while(traverse->next!=start){
    if(traverse->data==data)
        countNodes++;

    traverse=traverse->next;
}

struct node *changed_start;



while(ptr->next!=start){

    cout<<"\n entering while loop   ";
        struct node *tmp=org_start;

    if(ptr==org_start && ptr->data==data){
        
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start->next;
        free(start);
        start=start->next;
//        changed_start=start;
    }
    else if(ptr->data==data){
        // pre_ptr->next=ptr->next; // also works
        pre_ptr->next=pre_ptr->next->next;   
        free(ptr);
        // ptr=ptr->next;
    }
pre_ptr=ptr;
// ptr=pre_ptr->next;
ptr=ptr->next;
}
// for last eleement
if(ptr->data==data){
    pre_ptr->next=ptr->next;
    free(ptr);
    start=pre_ptr->next;
  //  changed_start=start;

}

//start=changed_start;

display(start);

return start;
}
/***************************************************************
 * CodeForWin.org website refereed    >>      WORKS flawlessly
 *          https://codeforwin.org/2018/06/c-program-to-delete-element-from-circular-linked-list.html
 * Delete all occurrence of an element by key from a 
 * given circular linked list.
 *
void deleteAll(struct node ** head, int key)
{
    int i, count;
    struct node *prev, *cur;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    count = 0;
    cur   = *head;
    prev  = cur;


    // Find node before head node
    printf("\n before while loop    ");
    while (prev->next != *head) 
    {   
        printf("\n traversiong all node data is %d  ",prev->data);
        prev = prev->next;
        count++;    // counting nodes
    }
printf("\n total Num of NODES   %d",count);
    // Iterate till first node
    i = 0;
    while (i <= count)
    {
        if (cur->data == key){
            // Link prev node with next node of current
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;  //deleting first node

            // Adjust head node if needed
            if (cur == *head)
                *head = prev->next;

            // Delete current node
            free(cur);

            // Move current node ahead
            if (prev != NULL) 
                cur = prev->next;
            else
                cur = NULL;
        }
        else{
            prev = cur;
            cur  = cur->next;
        }


        i++;

    }
}
*/
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

*****************************also puts delted element at last ****************************************************************
        SOLVED      // caused due to multiple start pointers fallacy

while(ptr->next!=start){

    // cout<<"\n initial value of start"<<start;

    if(ptr==start && ptr->data==data){
        struct node *tmp=start;
        start=start->next;          // here start definition changed also affects below while loop therefore puts first node deleted while priniting at last
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start;
    }
    else if(ptr->data==data){
        pre_ptr->next=ptr->next;
    }

pre_ptr=ptr;
ptr=ptr->next;
}

*/



int main(){
cout<<"\n\n";

int choice=0;

do{

cout<<"\n *************Cicrcular Linked List*******************";
cout<<"\n 1.create";
cout<<"\n 2.display";
cout<<"\n 3.insert beg";
cout<<"\n 4.insert end";
cout<<"\n 5.delete beg";
cout<<"\n 6.delete end";
cout<<"\n 7.search Node";
cout<<"\n 8.delete node";
cout<<"\n 9.insert after";
cout<<"\n 10.insert before";


cout<<"\n Enter choice\n";
cin>>choice;


    switch(choice){
        case 1:
            start=create(start);
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            start=insert_beg(start);
            break;
        case 4:
            start=insert_end(start);
            break;
        case 5:
            start=delete_beg(start);
            break;
        case 6:
            start=delete_end(start);
            break;
        case 7:
            start=search_list(start);
            break;
        case 8:
            start=delete_node(start);
            break;
                
            
    }

}while(choice!=13);


cout<<"\n\n";
return 0;
}



// /**************************************************************
        //  REVISIOIN 1 -> using recursino to delte all isntances of nodes

// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node *next;
// };

// struct node *start=NULL;


// struct node *display(struct node *start){

//     struct node *ptr=start;
//     cout<<"\n Printing List\t";
//     while(ptr->next!=start){
//         cout<<ptr->data<<" -> ";
//         ptr=ptr->next;
//     }
//         cout<<ptr->data;    // for last node since excluded in above 
// // since in above while loop if write ptr->next above print then skip first node print so sacrifice and write extra for either first node or last node
//             /*  OR could write as below

//             cout<<  first node data
//     while(ptr->next!=start){
//         ptr=ptr->next;
//         cout<<ptr->data<<" -> ";    // this cout also prints last node data //since above cout is before shifting ptr sacrifice cannot print last node data in above method
//     }*/
    
//     return start;   
// }

// struct node *create(struct node *start){

// cout<<"\n Enter -1 to end";
// cout<<"\n Enter data of Node ";
// int data;

// while(1){

// cin>>data;
// if(data==-1)
//     break;

//     if(start==NULL){
//         struct node *new_node=(struct node *)malloc(sizeof(struct node));
//         new_node->data=data;
//         start=new_node;
//         new_node->next=new_node;
//     }
//     else{
//         struct node *new_node=(struct node *)malloc(sizeof(struct node));
//         new_node->data=data;

//     struct node *ptr=start;

//         while(ptr->next!=start){
//         ptr=ptr->next;
//         }

//         ptr->next=new_node;
//         new_node->next=start;
//     }

// }
// display(start);
//     return start;
// }

// // works for mulitple occ
// struct node *search_list(struct node *start){

// struct node *ptr=start;

//     cout<<"\n enter number to search";
//     int data;
//     cin>>data;

// int node=1;

//     while(ptr->next!=start){
//         if(ptr->data==data)
//             cout<<"\n found at postion node "<<node;
//         node++;
//         ptr=ptr->next;
//     }

//     return start;
// }


// struct node *insert_beg(struct node *start){

//     struct node *ptr=start;

// struct node *new_node=(struct node *)malloc(sizeof(struct node));

// int data;
// cout<<"\n Enter data";
// cin>>data;
// new_node->data=data;

// new_node->next=start;

//     while(ptr->next!=start)
//         ptr=ptr->next;

// ptr->next=new_node;
// start=new_node;

// /************************Creates seg fault********************************************************************
    
//      // why wrong why not implicitly last elemnet updated??
//      LESSON >>      // because start at the time of creation the last node next was fixed to ex first node 
//              as start hence not updated since create() func called in the past

//   struct node *insert_beg(struct node *start){

//     struct node *ptr=start;

// struct node *new_node=(struct node *)malloc(sizeof(struct node));

// int data;
// cout<<"\n Enter data";
// cin>>data;
// new_node->data=data;

//  new_node->next=start;

// start=new_node;

// display(start);

//     return start;
// }*/

// display(start);

//     return start;
// }

// struct node *insert_end(struct node *start){

//     struct node *ptr=start;

//     while(ptr->next!=start){
//         ptr=ptr->next;
//     }    

//     struct node *new_node=(struct node *)malloc(sizeof(struct node));

//     cout<<"\n enter data";
//     int data;
//     cin>>data;

//     new_node->data=data;
    
//     ptr->next=new_node;
//     new_node->next=start;

//    display(start);
// return start;
// }

// //?? EDGE CASE >>   delete beg and end stable if only one elemnet in list?
//         // SOLVE using 
//         /*  
//         struct node *ptr=start;
//             if(ptr->next==start)
//                 cout<<"\n only one node present deleting that"
//                 start=NULL
//         */

// struct node *delete_beg(struct node *start){


// struct node *ptr=start;
// struct node *tmp=start;

// while(tmp->next!=start){
//     tmp=tmp->next;
// }

// ptr=ptr->next;
// start=ptr;
// tmp->next=ptr;

//     return start;
// }

// struct node *delete_end(struct node *start){

//     struct node *ptr=start;

//     struct node *pre_ptr=start;

// while(ptr->next!=start){
//     pre_ptr=ptr;
//     ptr=ptr->next;
// }

// pre_ptr->next=start;

// ptr->next=NULL;
// display(start);
//     return start;
// }


// int OccurencesExist(struct node *start,int find){

// int termExists=1;

// struct node *ptr=start;

// while(ptr->next!=start){

//     if(ptr->data==find){
//         termExists=1;
//     }
//     else{
//         termExists=0;
//     }

// ptr=ptr->next;

// // not necessary since end delteable?
//   if(ptr->data==find){
//         termExists=1;
//     }
//     else{
//         termExists=0;
//     }
    
// }
//    return termExists;
// }

// struct node *delete_node(struct node *start){

//     struct node *ptr=start;

//     struct node *org_start=start;

//     struct node *pre_ptr=ptr;
//     int data;
//     cout<<"\n enter node to delete";
//     cin>>data;

//     struct node *tmp=start;

// while(ptr->next!=start){

//     if(ptr==start && ptr->data==data){
        
//         while(tmp->next!=start){
//             tmp=tmp->next;
//         }
//         tmp->next=start->next;
//         start=start->next;
//     }
//     else if(ptr->data==data){
//         pre_ptr->next=ptr->next; // also works
//         // pre_ptr->next=pre_ptr->next->next;   
//         ptr=ptr->next;
//     }
// pre_ptr=ptr;
// ptr=pre_ptr->next;
// // ptr=ptr->next;
// }
// // for last eleement
// if(ptr->data==data){
//     pre_ptr->next=ptr->next;
//     start=pre_ptr->next;

// }
// int termExists=OccurencesExist(org_start,data);


// if(termExists==0)
//     display(start);
// else if(termExists==1)
//    delete_node(org_start);

//     return start;
// }

// /*****************************************************************
//                         // ??? some repetitions not deleted 
//     // between 2 unique nums if 2 mulitple occ 1 left behind all else occs deleted
//     // between 2 unique nums if 3 mulitple occ 2 left behind all else occs deleted
//                                 4 >> 2
// struct node *delete_node(struct node *start){

//     struct node *ptr=start;

//     struct node *pre_ptr=ptr;
//     int data;
//     cout<<"\n enter node to delete";
//     cin>>data;

//     struct node *tmp=start;

// while(ptr->next!=start){

//     if(ptr==start && ptr->data==data){
        
//         while(tmp->next!=start){
//             tmp=tmp->next;
//         }
//         tmp->next=start->next;
//         start=start->next;
//     }
//     else if(ptr->data==data){
//         pre_ptr->next=ptr->next;
//     }

// pre_ptr=ptr;
// ptr=ptr->next;
// }
// // for last eleement
// if(ptr->data==data){
//     pre_ptr->next=ptr->next;
//     start=pre_ptr->next;
// }

// display(start);
//     return start;
// }

// *****************************also puts delted element at last ****************************************************************
//         SOLVED      // caused due to multiple start pointers fallacy

// while(ptr->next!=start){

//     // cout<<"\n initial value of start"<<start;

//     if(ptr==start && ptr->data==data){
//         struct node *tmp=start;
//         start=start->next;          // here start definition changed also affects below while loop therefore puts first node deleted while priniting at last
//         while(tmp->next!=start){
//             tmp=tmp->next;
//         }
//         tmp->next=start;
//     }
//     else if(ptr->data==data){
//         pre_ptr->next=ptr->next;
//     }

// pre_ptr=ptr;
// ptr=ptr->next;
// }

// */



// int main(){
// cout<<"\n\n";

// int choice=0;

// do{

// cout<<"\n *************Cicrcular Linked List*******************";
// cout<<"\n 1.create";
// cout<<"\n 2.display";
// cout<<"\n 3.insert beg";
// cout<<"\n 4.insert end";
// cout<<"\n 5.delete beg";
// cout<<"\n 6.delete end";
// cout<<"\n 7.search Node";
// cout<<"\n 8.delete node";
// cout<<"\n 9.insert after";
// cout<<"\n 10.insert before";


// cout<<"\n Enter choice\n";
// cin>>choice;


//     switch(choice){
//         case 1:
//             start=create(start);
//             break;
//         case 2:
//             start=display(start);
//             break;
//         case 3:
//             start=insert_beg(start);
//             break;
//         case 4:
//             start=insert_end(start);
//             break;
//         case 5:
//             start=delete_beg(start);
//             break;
//         case 6:
//             start=delete_end(start);
//             break;
//         case 7:
//             start=search_list(start);
//             break;
//         case 8:
//             start=delete_node(start);
//             break;
                
            
//     }

// }while(choice!=13);


// cout<<"\n\n";
// return 0;
// }
