#include <stdio.h>
#include <string.h>
#define MAX 30

char stack[MAX][MAX];//here we take stack as a 2 dimensional array because we will store a whole string
//that can not be stored in a array
int top = -1;

void push(char str[]){
 if(top != MAX-1){
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

void prefix_to_infix(char prefix[], char infix[]){
 char op[2]; //operator string
 char poped1[MAX];//to store first operand
 char poped2[MAX];//to store second operand
 char temp[MAX];
 int i = strlen(prefix);
 op[1] = '\0';
 //right to left scanning
 while(--i != -1){
  if(prefix[i] == ' '){
   continue;
  }
  if(isoperator(prefix[i])){
   pop(poped1);
   pop(poped2);
   op[0] = prefix[i]; //operator
   strcpy(temp, poped1);
   strcat(temp, op);
   strcat(temp, poped2);
   push(temp);//whole expression is pushed in 2*2 stack
  }
  else{
   op[0] = prefix[i]; //operand
   push(op);
  }
 }
 pop(infix);
}

int main(){
 char prefix[MAX] ; //= "+-*^ABCD//EF+GH"; //INFIX :  A^B*C-D+E/F/G+H
 char infix[MAX];
 printf("Enter prefix expression:");
 scanf("%s",prefix);
 prefix_to_infix(prefix,infix);
 printf("Input Prefix  Expression : %s\n",prefix);
 printf("Output Infix  Expression : %s\n",infix);

 return 0;
}
