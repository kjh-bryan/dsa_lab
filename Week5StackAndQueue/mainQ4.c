#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void in2Post(char* infix, char* postfix)
{
 //Write your code here

    Stack s;
    s.head = NULL;
    s.size = 0;

    while(*infix != '\0')
    {
        char c = *infix++;

        if(isalpha(c) || isdigit(c))
        {
            *postfix = c;
            postfix++;
        }
        else {
            if(isEmptyStack(s))
            {
                push(&s,c);
            }
            else{
                if(c == '(')
                {
                    push(&s,c);
                }
                else if(c == ')')
                {
                    while(!isEmptyStack(s) && peek(s) != '(')
                    {
                        *postfix = peek(s);
                        postfix++;
                        pop(&s);
                    }
                    pop(&s);
                }
                else if(c == '+' || c == '-')
                {
                    char peekC = peek(s);
                    while(!isEmptyStack(s) && ((peekC == '*' || peekC == '/' || peekC == '-' || peekC == '+')))
                    {
                        *postfix = peek(s);
                        postfix++;
                        pop(&s);
                    }
                    push(&s,c);
                }
                else if(c == '*' || c == '/')
                {
                    push(&s,c);
                }
            }
        }
    }
    while(!isEmptyStack(s))
        {
            *postfix = peek(s);pop(&s);
            postfix++;
        }
        *postfix = '\0';
}
