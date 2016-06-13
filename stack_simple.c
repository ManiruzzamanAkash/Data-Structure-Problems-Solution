/** CODE BY MANIRUZZAMAN AKASH -->PSTU(CSE 12th Batch) **/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//create a stack
struct stack{
    int data[MAX];
    int top;
};

typedef struct stack Stack;         //create instance of the stack
Stack s;

//Declaring functions which I will use in the code...If I give the method after main then
//we have to initialize it first ...It is  a good programming
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

//push method just push a value in the stack that means push in the stack's top
void push(int value){
    s.top++;
    s.data[s.top] = value;
    printf("\tValue inserted successfully\n");
}


//pop method --> pop the top value from the stack
int pop(){
    int popValue;
    popValue = s.data[s.top];
    printf("The element %d is popped from the stack successfully\n", popValue);
    s.top--;
    return popValue;
}


//display the stack all values from index 0 to index top
void display(){
    int printvalue, i;
    printf("The total stack is : ");
    for(i = 0; i <= s.top; i++){
        printvalue = s.data[i];
        printf("%d\t", printvalue);
    }
    printf("\n");
}


//same as display method just  make a new count variable and increment it and finally get the total count
int getCount(){
    int count = 0, i;
    for(i = s.top; i >=0; i--){
        s.data[i];
        count++;
    }
    printf("%d\n", count);
    return count;
}
