#include <stdio.h>
#include <string.h>
#define MAX 30

char stack[MAX][MAX];//here we take stack as a 2 dimensional array because we will store a whole string
//that can not be stored in a array
int top = -1;

void push(char str[]){
 if(top < MAX){
  strcpy(stack[++top], str);
 }
 else{
  printf("Stack overflow : May be invalid prefix expression\n");
 }
}

void pop(char str[]){
 if(top != -1){
  strcpy(str,stack[top--]);
 }
 else{
  printf("Stack underflow : May be invalid prefix expression\n");
 }
}

int isoperator(char c){
 if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
  return 1;
 return 0;
}

void postfix_to_infix(char postfix[], char infix[]){
 char op[2]; //operator string
 char poped1[MAX];//to store first operand
 char poped2[MAX];//to store second operand
 char temp[MAX];
 int i=0;
 op[1] = '\0';
 //left to right scanning
 while(postfix[i] !='\0')
 {
  if(postfix[i] == ' '){
   continue;
  }
  if(isoperator(postfix[i])){
   pop(poped1);
   pop(poped2);
   op[0] = postfix[i]; //operator
   strcpy(temp, poped2);
   strcat(temp, op);
   strcat(temp, poped1);
   push(temp);//whole expression is pushed in 2*2 stack
  }
  else{
   op[0]=postfix[i]; //operand
   push(op);
  }
 i++;
 }
 pop(infix);
}

int main(){
 char postfix[MAX]={'\0'} ; //= "+-*^ABCD//EF+GH"; //INFIX :  A^B*C-D+E/F/G+H
 char infix[MAX];
 printf("Enter postfix expression:");
 scanf("%s",postfix);
 postfix_to_infix(postfix,infix);
 printf("Input Postfix  Expression : %s\n",postfix);
 printf("Output Infix  Expression : %s\n",infix);

 return 0;
}
