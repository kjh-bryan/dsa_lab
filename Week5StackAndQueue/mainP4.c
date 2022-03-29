#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);
int precedence(char c);

void in2Pre(char*, char*);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Pre(infix,prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

char peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if(s.size == 0) return 1;
    else return 0;
}

int precedence(char c)
{
    if(c == '*' || c == '/')
        return 1;
    return 0;
}

void in2Pre(char* infix, char* prefix)
{
//Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;
    char* toReverse = prefix;
    infix = strrev(infix);
    int i = 0;

    while(*infix != '\0')
    {
        char c = *infix++;

        if(isalpha(c) || isdigit(c))
        {
            *toReverse = c;
            toReverse++;
        }
        else
        {
            if(isEmptyStack(s))
            {
                push(&s,c);
            }
            else
            {
                if(c == '(')
                {
                    push(&s,c);
                }
                else if(c == ')')
                {
                    while(!isEmptyStack(s) && peek(s) != '(')
                    {
                        *toReverse = peek(s);
                        toReverse++;
                        pop(&s);
                    }
                    pop(&s);
                }
                else if(c == '+' || c == '*' || c == '/' || c == '-')
                {
                    if(!isEmptyStack(s) && precedence(peek(s)) > precedence(c))
                    {
                        while(!isEmptyStack(s))
                        {
                            *toReverse = peek(s);
                            toReverse++;
                            pop(&s);
                        }
                        push(&s,c);
                    }
                    else
                    {
                        push(&s,c);
                    }
                }
            }
        }
    }

    if(!isEmptyStack(s))
    {
        *toReverse = peek(s);
        pop(&s);
        toReverse++;
    }

    prefix  = strrev(toReverse);
}
