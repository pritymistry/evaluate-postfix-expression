#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int stack[25],top=-1;
void push(int num)
{
    stack[++top]=num;
}
int pop()
{
    return stack[top--];
}

int evaluatePostfix(char str[],int n)
{
    int a,b,c;
    for(int i=0;i<n;i++)
    {
            if(isdigit(str[i]))
            {
                push(str[i]-'0');
            }
            else
            {
                a=pop();
                b=pop();
                if(str[i]=='+')
                {
                    c=b+a;
                }
                else if(str[i]=='-')
                {
                    c=b-a;
                }
                else if(str[i]=='*')
                {
                    c=b*a;
                }
                else if(str[i]=='/')
                {
                    c=b/a;
                }
                else if(str[i]=='^')
                {
                    c=pow(b,a);
                }
                push(c);
            }

    }
    if(top==0)
    return (pop());
}
int main()
{
    char expn[25];
    int l,result;
    printf("enter a postfix expression :\n");
    scanf("%s",&expn);
    l=strlen(expn);
    result=evaluatePostfix(expn,l);
    printf("answer is :%d",result);
    return 0;
}
