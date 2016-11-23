#include<stdio.h>
#include<stdlib.h>
#define MaxSize 99
void translate(char str[],char exp[])  
{
       struct
       {
              char data[MaxSize];
              int top;                 
       }op;                            
       char ch;                    
       int i = 0,t = 0;
       op.top = -1;
       ch = str[i];                      
       i++;
       while(ch != '\0')                 
       {
              switch(ch)
              {
              case '(':                
                   op.top++;op.data[op.top]=ch;
                     break;
              case ')':              
                   while(op.data[op.top] != '(')    
                {
                            exp[t]=op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top--;
                     break;
              case '+':
              case '-':
                     while(op.top != -1&&op.data[op.top] != '(')
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top++;           
                     op.data[op.top] = ch;
                     break;
              case '*':
              case '/':
                     while(op.top == '/'||op.top == '*')      
                     {
                            exp[t] = op.data[op.top];
                            op.top--;
                            t++;
                     }
                     op.top++;
                     op.data[op.top] = ch;
                     break;
              case ' ':                        
                     break;
              default:
                     while(ch >= '0'&&ch <= '9')
                     {
                            exp[t] = ch;t++;
                            ch = str[i];i++;
                     }
                     i--;
                     exp[t] = '#';         
                     t++;
              }
              ch = str[i];
              i++;
       }
       while(op.top != -1)                  
       {
              exp[t] = op.data[op.top];
              t++;
              op.top--;
       }
       exp[t] = '\0';                        
}
float cal_value(char exp[])
{
       struct
       {
              float data[MaxSize];
              int top;
       }st;                               
       float d;
       char ch;
       int t = 0;
       st.top = -1;
       ch = exp[t];
       t++;
       while(ch != '\0')
       {
              switch(ch)                 
              {
               case '+':
                      st.data[st.top-1] = st.data[st.top-1]+st.data[st.top];
                      st.top--;
                      break;
               case '-':
                      st.data[st.top-1] = st.data[st.top-1]-st.data[st.top];
                      st.top--;
                      break;
               case '*':
                      st.data[st.top-1] = st.data[st.top-1]*st.data[st.top];
                      st.top--;
                      break;
               case '/':
                       if(st.data[st.top] != 0)
                              st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
                       else
                       {
                              printf("\n\t除0是错误的");
                              st.data[st.top-1]=-3000;
                       }
                       st.top--;
                       break;
               default:
                      d=0;
                      while(ch >= '0'&&ch <= '9')   
                      {
                             d = 10*d+ch-'0';
                             ch = exp[t];
                             t++;
                      }
                      st.top++;
                      st.data[st.top] = d;
            }
            ch = exp[t];
            t++;
       }
       return st.data[st.top];
}
int main()                                  
{
       char str[MaxSize],exp[MaxSize];      
       printf("请输入一个求值表达式\n");
       printf("表达式:");
       gets(str);                           
       translate(str,exp);                  
       printf("计算结果:%g\n",cal_value(exp));
       system("pause");
       return 0;
}