/** CODE BY MANIRUZZAMAN AKASH **/

#include<stdio.h>
#include<string.h>
#define MAX 50

    char stack[MAX];
    int top=-1;

    char pop();
    void push(char item);

//As the algorithm that all of the elements which has higher precedence will be pop from the stack and add it to Postfix
// for that first need to check the precedence of the scanned character
//And precedence is : (+ - = 1), (* / = 2), (^ = 3) ,((#) = 0)
int getPrecedence(char symbol){
    switch(symbol){

        case '+':
        case '-':return 1;
            break;

        case '*':
        case '/':return 2;
            break;

        case '^': return 3;
            break;

        case '(':
        case ')':
        case '#':return 0;
            break;
    }
}

//For check in the convertInfix2Postfix() algorithm..-->
//I have to check if the scanned character is operator or operand
int isoperator(char symbol){
    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
            break;

        default:
            return 0;
    }
}

//Method for converting infix to postfix using the full algorithm of infix to postfix
void convertInfix2Postfix(char infix[],char postfix[]){
    int i,symbol,j=0;
    stack[++top]='#';
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(isoperator(symbol)==0)
        {
        postfix[j]=symbol;
        j++;
        }
        else{
            if(symbol=='(')push(symbol);
            else if(symbol==')')
            {
                while(stack[top]!='(')
                {
                    postfix[j]=pop();
                    j++;
                }
            pop();//pop out (.
            }
            else{
                if(getPrecedence(symbol)>getPrecedence(stack[top]))
                    push(symbol);
                else{
                    while(getPrecedence(symbol)<=getPrecedence(stack[top]))
                    {
                        postfix[j]=pop();
                        j++;
                    }
                push(symbol);
                }//end of else.
            }//end of else.
        }//end of else.
    }//end of for.
    while(stack[top]!='#'){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';//null terminate string.
}

 void main(){
    char infix[50],postfix[50];
    printf("Enter a valid infix expression :\n");
    gets(infix);
    convertInfix2Postfix(infix,postfix);
    printf("The postfix expression is :\n");
    puts(postfix);

}

//simple push method of stack
void push(char item){
    top++;
    stack[top]=item;
}

//simple pop method of stack
char pop(){
    char a;
    a=stack[top];
    top--;
    return a;
}
