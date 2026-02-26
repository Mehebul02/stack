#include <stdio.h>
#define MAX 5

int mystack[MAX], top =-1;

void push (int mystack[], int val)
{
    if (top == MAX-1)
    {
        printf("\n STACK IS EMPTY");
    }
    else
    {
        top ++;
        mystack[top]=val;
    }
}

