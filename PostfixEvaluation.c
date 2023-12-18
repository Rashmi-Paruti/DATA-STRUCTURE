/*
5 Design, Develop and Implement a Program in C for the following Stack
Applications
a. Evaluation of Suffix expression with single digit operands and operators:
+, -, *, /, %, ^
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum {plus, minus, mul, divi, mod, pwr, eos, operand} precedence;

precedence getToken(char postfix[], int *n, char *symbol);
int eval(char postfix[]);
void push(int stack[], int *top, int ele);
int pop(int stack[], int *top);
int operation(int opr1, int opr2, precedence token);

void main()
{
	char postfix[30];
	printf("Enter Postfix Expression\n");
	gets(postfix);
	printf("The Result after Evaluation is %d", eval(postfix));
}

precedence getToken(char postfix[], int *n, char *symbol)
{
	*symbol = postfix[(*n)++];
	switch(*symbol)
	{
		case '+':	return plus;
		case '-':	return minus;
		case '*':	return mul;
		case '/':	return divi;
		case '%':	return mod;
		case '^':	return pwr;
		case '\0':	return eos;
		default:	return operand;
	}
}

int eval(char postfix[])
{
	int stack[20], top=-1, n=0, opr1, opr2;
	precedence token;
	char symbol;
	for(token = getToken(postfix, &n, &symbol); token != eos; token = getToken(postfix, &n, &symbol))
	{
		if(token == operand)
		{
			push(stack, &top, symbol - '0');
		}
		else
		{
			opr2 = pop(stack, &top);
			opr1 = pop(stack, &top);
			push(stack, &top, operation(opr1, opr2, token));
		}
	}
	return stack[0];
}

void push(int stack[], int *top, int ele)
{
	stack[++(*top)] = ele;
}

int pop(int stack[], int *top)
{
	return stack[(*top)--];
}

int operation(int opr1, int opr2, precedence token)
{
	switch(token)
	{
		case plus:	return opr1+opr2;
		case minus:	return opr1-opr2;
		case mul:	return opr1*opr2;
		case divi:	return opr1/opr2;
		case mod:	return opr1%opr2;
		case pwr:	return pow(opr1, opr2);
	}
}