#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
        int data;
        struct Node *next;
}node;


void insert(node *pointer, int data)
{

        while(pointer->next!=NULL)
        {
                pointer = pointer -> next;
        }

        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = NULL;
}


//search method that search if the given data is in the linked list or not
int find(node *pointer, int key)
{
        pointer =  pointer -> next;
        while(pointer != NULL)
        {
                if(pointer->data == key) //key is found.
                {
                        return 1;
                }
                pointer = pointer -> next;//Search in the next node.
        }
        /*Key is not found */
        return 0;
}



void delete(node *pointer, int data)
{

        while(pointer->next!=NULL && (pointer->next)->data != data)
        {
                pointer = pointer -> next;
        }
        if(pointer->next==NULL)
        {
                printf("Element %d is not present in the list\n",data);
                return;
        }

        node *temp;
        temp = pointer -> next;

        pointer->next = temp->next;

        free(temp); //this is the main thing to delete linked list any node by--> free()

        return;
}


void print(node *pointer)
{
        if(pointer==NULL)
        {
                return;
        }
        printf("%d ",pointer->data);
        print(pointer->next);  //using recursion
}


int main()
{

        node *start,*temp;
        start = (node *)malloc(sizeof(node));
        temp = start;
        temp -> next = NULL;

       printf("\t\tLinked List\n-------------------------------------\n");
       printf(" Press 1 to Insert Data in the linked list\n Press 2 Delete data from the linked list\n Press 3 Print data of the linked list\n Press 4 Find data from the linked data from the linked list\n");
       printf(" Press  0 To exit the program\n-------------------------------------\n");
        while(1)
        {
                int option;

                printf("Enter your option: ");
                scanf("%d",&option);
                if(option==1)
                {
                        int data;
                        printf("Enter a value in the linked list : ");
                        scanf("%d",&data);
                        insert(start,data);
                        printf("Value inserted successfully\n");
                }
                else if(option==2)
                {
                        int data;
                        printf("Enter a data do you want to delete from the linked list: ");
                        scanf("%d",&data);
                        delete(start,data);
                }
                else if(option==3)
                {
                        printf("The list is ");
                        print(start->next);
                        printf("\n");
                }
                else if(option==4)
                {
                        int data;
                        scanf("%d",&data);
                        int status = find(start,data);
                        if(status)
                        {
                                printf("Element Found\n");
                        }
                        else
                        {
                                printf("Element Not Found\n");

                        }
                }else if(option == 0){
                	printf("!!!..Program exited successfully..!!!");
                	return 0;
				}else{
                    printf("!!!..Wrong option.. chose a valid option..!!!");
				}

        }

        return 0;
}

