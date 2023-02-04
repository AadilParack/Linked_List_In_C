///HEADER//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
///DEFINE//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///STORAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void storage();

///FUNCTIONS/DECLARTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//linked list//
struct node *insert(struct node *start);
struct node *displayll(struct node *start);
struct node *insertbegin(struct node *start);
struct node *insertbetween(struct node *start);
struct node *deletenode(struct node *start);
struct node *updatecount(struct node *start);
struct node *createll(struct node *start);
struct node *deletebetween(struct node *start);
struct node *insertbefore(struct node *start);
struct node *insertafter(struct node *start);

///STRUCTURES/AND/GLOAL/VARIABLE///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count=0;

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;

///MAIN////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    //linked list
    start=createll(start);
    int k=0;
    while(k!=-1)
    {
    printf("======Linked list======");
    printf("\n1 to insert at the end \n2 to display linked list\n");
    printf("3 to insert at beginning\n4 to insert between two nodes\n");
    printf("5 to prune LL from a node\n6 to show number of nodes in linked list\n7 to delete between two nodes\n");
    printf("8 to enter before a certain value\n9 to insert after a certain value");
    printf("\n-1 to exit\nchoice: ");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        printf("\n=============");
        start=insert(start);
        break;
    case 2:
        printf("\n=============");
        start=displayll(start);
        break;
    case 3:
        printf("\n=============");
        start=insertbegin(start);
        break;
    case 4:
        printf("\n=============");
        start=insertbetween(start);
        break;
    case 5:
        printf("\n=============");
        start=deletenode(start);
        break;
    case 6:
        printf("\n=============");
        start=updatecount(start);
        printf("\n%d nodes found\n",count);
        break;
    case 7:
        printf("\n=============");
        start=deletebetween(start);
        break;
    case 8:
        printf("\n=============");
        start=insertbefore(start);
        break;
    case 9:
        printf("\n=============");
        start=insertafter(start);
        break;
    default:
        k=-1;
        break;
    }
    }
    return 0;
}
///FUNCTION/DEFINITION/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////linked list////
struct node *insertafter(struct node *start){
    struct node *pstptr, *ptr;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int num;
    int val;
    printf("\nenter value to insert after: ");
    scanf("%d",&val);
    printf("\nenter number to be inserted: ");
    scanf("%d",&num);
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
        if(ptr->next==NULL)
            break;
    }
    if(ptr->next==NULL&&ptr->data==val)
    {
        printf("\n%d inserted",num);
        newnode->data=num;
        ptr->next=newnode;
        newnode->next=NULL;
        return start;
    }
    if(ptr->next==NULL&&ptr->data!=val)
    {
        printf("\n%d not found in linked list",num);
        return start;
    }
    pstptr=ptr->next;

    newnode->data=num;
    newnode->next=pstptr;
    ptr->next=newnode;

    return start;
};
////

struct node *insertbefore(struct node *start){
    int val;
    int num;
    printf("\nenter value to insert before: ");
    scanf("%d",&val);
    printf("\nenter number to be inserted: ");
    scanf("%d",&num);

    struct node *ptr,*preptr;
    struct node *newnode;

    newnode=(struct node *)malloc(sizeof(struct node));
    ptr=start;
    preptr=start;

    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
        if(ptr->next==NULL)
            break;
    }

    if(ptr->data!=val)
    {
        printf("\nnumber not found");
        return start;
    }

    newnode->data=num;
    newnode->next=ptr;
    preptr->next=newnode;

    printf("\n%d inserted",num);
    return start;
};
////

struct node *deletebetween(struct node *start){
    struct node *ptr1;
    struct node *ptr2;
    int pos;
    int i=0;
    printf("\nenter which node to delete: \n");
    scanf("%d",&pos);
    ptr1=start;
    ptr2=start;

    for(i=0;i<pos-2;i++){
            ptr1 = ptr1->next;
    }

    for(i=0;i<pos-1;i++){
            ptr2 = ptr2->next;
    }

    ptr1->next=ptr2->next;

    printf("\nnode %d, data as %d deleted\n",pos,ptr2->data);
    return start;
};
////

struct node *createll(struct node *start){

    int num;
    struct node *newnode, *ptr;
    printf("Linked list creation: ");
    printf("\nenter number or -1 to exit: \n");
    scanf("%d",&num);

    //local var = num
    // two pointers newnode and ptr

    while(num!=-1){
            //see if user enter -1
            newnode = (struct node *)malloc(sizeof(struct node));
            //assign memory in heap equal to size of node and assign to pointer newnode
            newnode->data=num;
            //assign num to the data of the memory where newnode is pointing to
            if(start == NULL){
                //see if start is null (if the ll is empty)
                start=newnode;
                //assign newnode address to start
                newnode->next=NULL;
                //newnode's next assigned null
                printf("new linked list started with %d\n",num);
            }
            else
            {
                //if ll is not empty (start is there)
                ptr=start;
                // pointer ptr is assigned start
                while(ptr->next != NULL)
                {
                    //see if the pointer to newnode has any next value
                    ptr=ptr->next;
                    //if node found, assign that address to ptr and loop to see if the next node has any next
                }
                ptr->next=newnode;
                //assign the next of the node pointed by ptr (current node) to the newest node
                newnode->next=NULL;
                //assign the newnode's next as null
                printf("new node inserted as %d\n",num);
            }
    printf("\nenter number or -1 to exit: \n");
    scanf("%d",&num);
    }
    return start;
};
////

struct node *updatecount(struct node *start)
{
    count=0;
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){
            ptr = ptr->next;
            count++;
    }
    return start;
};
////

struct node *deletenode(struct node *start){
    int pos;
    int i=0;
    struct node *ptr;

    printf("\nenter after which node to delete: \n");
    scanf("%d",&pos);

    ptr=start;
    for(i=0;i<pos-1;i++){
            ptr = ptr->next;
    }

    ptr->next=NULL;
    return start;

};
////

struct node *insertbetween(struct node *start){
    int num;
    int pos;
    int i=0;
    struct node *newnode,*ptr;

    printf("\nenter number or -1 to exit: \n");
    scanf("%d",&num);

    printf("\nenter after which node to enter: \n");
    scanf("%d",&pos);

    if(num!=-1){

    ptr=start;
    //put start in ptrn
    for(i=0;i<pos-1;i++){
            ptr = ptr->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=ptr->next;
    ptr->next=newnode;
    }
    return start;
};
////

struct node *insertbegin(struct node *start){
    int num;
    struct node *newnode;

    printf("\nenter number or -1 to exit: \n");
    scanf("%d",&num);

    if(num!=-1){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next = start;
    start=newnode;
    }
    printf("\n%d inserted at beginning\n",num);
    return start;
};
////

struct node *insert(struct node *start){
    int num;
    struct node *newnode, *ptr;
    printf("\nenter number or -1 to exit: \n");
    scanf("%d",&num);

    //local var = num
    // two pointers newnode and ptr

    if(num!=-1){
            //see if user enter -1
            newnode = (struct node *)malloc(sizeof(struct node));
            //assign memory in heap equal to size of node and assign to pointer newnode
            newnode->data=num;
            //assign num to the data of the memory where newnode is pointing to

                //if ll is not empty (start is there)
                ptr=start;
                // pointer ptr is assigned start
                while(ptr->next != NULL)
                {
                    //see if the pointer to newnode has any next value
                    ptr=ptr->next;
                    //if node found, assign that address to ptr and loop to see if the next node has any next
                }
                ptr->next=newnode;
                //assign the next of the node pointed by ptr (current node) to the newest node
                newnode->next=NULL;
                //assign the newnode's next as null
                printf("new node inserted as %d\n",num);

    }
    return start;
};
////

struct node *displayll(struct node *start){
    printf("\nLinked list: ");
    struct node *ptr;
    //pointer ptr
    ptr=start;
    //put start in ptrn
    while(ptr!=NULL){
            //check if any nodes are there
            printf("\n%d",ptr->data);
            //print value of the node currently pointed to by the ptr
            ptr = ptr->next;
            //assign ptr to the next node
    }
    printf("\n");
    return start;
};
////

///STORAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void storage()
{
}
////
