/** CODE BY MANIRUZZAMAN AKASH -->PSTU(CSE 12th Batch)**/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
        int data;
        struct Node *next;
}node;



//push data method until list->next != NULL then after the finishing list then set list ->data = data which is passed by main method
void pushData(node *list, int data)
{
        /* Iterate through the list till we encounter the last node.*/
        while(list->next != NULL)
        {
                list = list -> next;
        }
        /* Allocate memory for the new node and put data in it.*/
        list->next = (node *)malloc(sizeof(node));
        list = list->next;
        list->data = data;
        list->next = NULL;
}

//print the linked list all of the data --> make a while loop until list->next !=NULL and then print each of the data
void printData(node *list)
{
        if(list == NULL)
        {
                printf("Sorry..No entry\n");
                return;
        }else{
            printf("%d ",list->data);
            while(list->next != NULL){
                list = list -> next;
                printf("%d ",list->data);
                }
        }
}

//same as printData method()---> Just make a new count variable and increment that if a data has contain the list and finally print it
void getCount(node *list)
{
    int count = 1;
    if(list == NULL)
    {
        printf("Sorry..No entry\n");
        return;
    }else{
        while(list->next != NULL){
                list = list -> next;
                count++;
            }
    }
    printf("Total size of the linked list is : %d\n", count);
}


//starts main method
int main( ){

    node *head,*temp;
    head = (node *)malloc(sizeof(node));
    temp = head;
    temp -> next = NULL;


	int choose, value;
	printf("\nLinkedList\n");
	printf("----------------------------------\n");
	printf("\tEnter 1 to push data in the linked list : \n\tEnter 2 to see the linked list : \n\tEnter 3 to know the size of linked list : \n\tEnter 0 to exit\n");



	while(1){
		printf("\nEnter your Choose : ");
		scanf("%d", &choose);
		switch(choose){
		case 1:
			printf("Enter a value in the linked list : ");
			scanf("%d", &value);
			pushData(head, value);
			printf("Data inserted successfully..\n");
			break;

		case 2:
				printf("Total element in the linked list : ");
				printData(head -> next);
				printf("\n");
			break;

		case 3:
			getCount(head -> next);
			break;

		case 0:
			printf("Program exits\n");
			return 0;
			break;
		}
	}
}
