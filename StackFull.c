/** CODE BY MANIRUZZAMAN AKASH -->PSTU(CSE 12th Batch) **/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{

    int data[MAX];
    int top;
};

typedef struct stack Stack;
Stack s;

//Functions
void push(int value);
int pop();
void display();
int getCount();

//main() method starts here
int main( ){
	int chose, pushValue;
	s.top = -1;
	printf("\n\t\t\tStack\t\t\t\n\t\t---------------------\t\t\t");

	printf("\n\t\tPress 1 for Push a value\n\t\tPress 2 for pop a value\n\t\tPress 3 for displaying total values\n\t\tPress 4 for total size\n\t\tPress 0 to exit");
	printf("\n-----------------------------------------------------\n");
	while(1){
		printf("Enter your option : ");
		scanf("%d", &chose);
		switch(chose){
			case 1:
				printf("Enter a value to push in  the stack : ");
				scanf("%d", &pushValue);
				push(pushValue);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;

			case 4:
				printf("The total element  in the stack is : ");
				getCount();
				break;
			case 0:
				printf("Program exited successfully\n\n");
				return 0 ;
				break;
			default:
				printf("Please chose a value from given option\n");

		}
	}
}
//Functions
void push(int value){

		if(s.top == (MAX -1)){
			printf("Sorry stack is full\n");
		}else{
			s.top++;
			s.data[s.top] = value;
			printf("\tValue inserted successfully\n");
		}


	}
	int pop(){
		int popValue, i;
		if(s.top == -1){
			printf("Their is no value to pop\n");
		}else{
			popValue = s.data[s.top];
			  printf("The element %d is popped from the stack successfully\n", popValue);
			  s.top--;
			  return popValue;
		}

	}
	void display(){
		int printvalue, i;
		if(s.top == -1){
			printf("Sorry stack is empty\n");
		}else{
			printf("The total stack is : ");
			for(i = 0; i <= s.top; i++){
				printvalue = s.data[i];
				printf("%d\t", printvalue);
			}
		}
		printf("\n");
	}



	int getCount(){
		int count = 0, i;
		for(i = s.top; i >=0; i--){
				s.data[i];
				count++;
		}
		printf("%d\n", count);
		return count;
	}
