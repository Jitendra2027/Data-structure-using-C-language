//steps to convert infix notation into prefix
// 1.reverse the infix notation
// 2.interchange the parenthesis
// 3.now find out the postfix notation of the modified expression
// 4.after finding the postfix expression reverse it again and reversed expression will be the prefix expression

#include<stdio.h>
#include<string.h>
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
    char temp[30]={'\0'};
    char item;
    int i=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    //reverse the expression
    for(int j=strlen(infix)-1,i=0;j>=0;j--,i++)
    {
        temp[i]=infix[j];
    }
    printf("Reversed expression is:%s\n",temp);
    strcpy(infix,temp);
    //interchange the parenthesis
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
        i++;
    }
    printf("After interchanging the parenthesis:%s\n",infix);
    i=0;
    //find the postfix expression
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
    //print the reversed postfix expression
    printf("Your postfix expression is:");
    printf("%s",strrev(output));
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
