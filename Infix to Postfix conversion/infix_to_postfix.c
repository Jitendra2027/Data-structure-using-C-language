#include<stdio.h>
void stackpush(char);
char stackpop();
char stackpeek();
void stackdisplay();
int priority(char);
void pushoutput(char);
void displayoutput();
char stack[30]={'\0'};
char output[30]={'\0'};
int stacktop=-1;
int outputtop=-1;
int main()
{
    char infix[30]={'\0'};
    char item;
    int i=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        //printf("Inside while\n");
        if(infix[i]=='(')
        {
                stackpush(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stackpeek()!='(')
            {
                item=stackpop();
                pushoutput(item);
            }
            if(stacktop!=-1 && stackpeek()!='(')
                printf("Invalid expression\n");
            stackpop();
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
        {
           if(stacktop>=0)
           {
               while(priority(stackpeek())>=priority(infix[i]) && stacktop!=-1)
               {
                   //associativity is left to right then pop the peek item and insert into output array
                   if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
                   {
                        item=stackpop();
                        pushoutput(item);
                   }
                   //associativity is right to left then directly push the item in the stack
                   else
                   {
                       stackpush(infix[i]);
                   }
               }
           }
           stackpush(infix[i]);
        }
        else
        {
            pushoutput(infix[i]);
        }
        i++;
        //stackdisplay();
        //printf("\t");
        //displayoutput();
    }
    if(stacktop!=-1)
    {
        while(stacktop!=-1)
        {
            item=stackpop();
            pushoutput(item);
        }
    }
    printf("Your postfix expression is:");
    printf("%s",output);
    return 0;
}
void stackpush(char item)
{
    if(stacktop==29)
        printf("Operator stack is full\n");
    else
    {
        stacktop++;
        stack[stacktop]=item;
    }
}
char stackpop()
{
    char item;
    if(stacktop==-1)
        printf("Operator stack is empty\n");
    else
    {
        item=stack[stacktop];
        stacktop--;
    }
    return item;
}
char stackpeek()
{
    if(stacktop==-1)
        printf("Operator stack is empty\n");
    else
        return stack[stacktop];
}
int priority(char item)
{
    switch(item)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return -1;
}
void stackdisplay()
{
    if(stacktop==-1)
        printf("Operator stack is empty\n");
    else
        for(int i=0;i<=stacktop;i++)
            printf("| %c",stack[i]);
}
void displayoutput()
{
    if(outputtop==-1)
        printf("Output stack is empty\n");
    else
    {
        for(int i=0;i<=outputtop;i++)
            printf("| %c",output[i]);
    }
}
void pushoutput(char item)
{
    if(outputtop==29)
        printf("Output stack is full\n");
    else
    {
            outputtop++;
            output[outputtop]=item;
    }
}
