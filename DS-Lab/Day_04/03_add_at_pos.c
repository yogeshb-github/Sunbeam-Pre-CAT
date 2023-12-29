#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
typedef struct node
{
    int data;
    struct node *next; // self ref structure
}node_t;
node_t *head;  // nodt_t *head=NULL;   //struct node* head=NULL;
node_t* create_node(int value);
void add_first(int value);
void display_list();
void add_last(int value);
int count_nodes();
void add_at_pos(int position, int value);
int main(void)
{
    display_list(); // empty
    add_last(10) ;
    display_list();//  10
    add_last(20);
    display_list(); // 10---> 20
    add_last(30);
    display_list();//  10--->20---> 30
    add_last(40);
    display_list();//  10--->20--->30---> 40
    add_last(50);
    display_list();//  10--->20--->30---> 40--> 50

    add_at_pos(1,5);
    display_list();//  5-->10--->20--->30---> 40--> 50

    add_at_pos(7,70);
    display_list();//  5-->10--->20--->30---> 40--> 50--->70

    add_at_pos(3,15);
    display_list();//  5-->10--->15-->20--->30---> 40--> 50 -->70
    
    add_at_pos(8,60);
    display_list();//  5-->10--->15-->20--->30---> 40--> 50 --> 60-->70
    

    return 0;
}
void add_at_pos(int position, int value)
{
    node_t * newnode=NULL, *trav=NULL;
    int i;
    if( position==1) 
    {
        add_first(value);
    }
    else if( position== (count_nodes()+1))
    {
        add_last(value);
    }
    else 
    {
        newnode= create_node(value); // allocate new memory for new node
        trav= head; // store addreess of 1st node into trav pointer
        for( i=1 ; i<position-1 ; i++)
        {
            trav= trav->next; // goto next node in list
        }
        newnode->next= trav->next; // store addrees of next node into next part of new node
        trav->next= newnode;  // store address of new node into next pointer of trav
    }
    return;
}
int count_nodes()
{
    int count=0;
    node_t *trav=NULL;
    trav= head;
    if( trav== NULL)
        printf("\n list is empty \n ");
    else 
    {
        while( trav!=NULL)  // goto NULL of last node
        {
            count++;
            trav= trav->next; // go to next node
        }
        
    }
    return count;
}
void add_last(int value)
{
    node_t *newnode=NULL;
    newnode = create_node(value); // allocate memory for new node
    if( head== NULL) // if list is empty
    {
        head= newnode; // //store address of new node into head pointer (1st node)
    }
    else
    {
        node_t *trav= head;
        while (trav->next!=NULL) // go to last node of list
        {
            trav= trav->next ;// go to next node
        }
        trav->next= newnode ;// store address of new node into next pointer of last node        
    }
    return;
}
void display_list()
{
    node_t *trav=NULL;
    trav= head;
    if( trav== NULL)
        printf("\n list is empty \n ");
    else 
    {
        while( trav!=NULL)  // goto NULL of last node
        {
            printf("%5d-->",trav->data); // print data of trav node
            trav= trav->next; // go to next node
        }
        printf("\n");
    }
    return;
}
void add_first(int value)
{
    node_t *newnode=NULL;
    newnode= create_node(value);// allocate memory for new node
    if( head==NULL) // if list is empty
    {
        head= newnode; //store address of new node into head pointer (1st node)
    }
    else 
    {
        newnode->next= head; // store address of 1st node into next of new node
        head= newnode; //store address of new node into head pointer
    }
    return;
}
node_t* create_node(int value)
{
    node_t *new_node=NULL;  
    new_node=(node_t*) malloc(sizeof(node_t)*1);    // allocate memory
    if( new_node==NULL)
    {
        printf("\n unable to allocate memory");
        exit(0);
    }
    else 
    {
        new_node->data= value; // assign value to data part of node
        new_node->next= NULL; // assign NULL to next part of node
    }
    return new_node;
}