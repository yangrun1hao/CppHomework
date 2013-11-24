#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

typedef struct Node
{
        int data;
        struct Node * next;
}*ListNodeptr,ListNode;

class Stack
{
public:
        void popi();
        void pushi(int value);
        void showi();
        Stack(int cap)
        {
                ListNodeptr p,q;
                int i=cap-1;
                q=(ListNodeptr)malloc(sizeof(ListNode));
                q->next=NULL;
                while(i>=0)
                {
                        p=(ListNodeptr)malloc(sizeof(ListNode));
                        if(!p)
                        {
                                cout<<"内存分配失败\n";
                        }
                        else
                        {
                            p->data=0;
                            p->next=q->next;
                            q->next=p;
                        }
                        i--;
                }
                *top=q;
                count=cap;
        }
        ~Stack()
        {
             ListNodeptr p=(*top),q=p->next;
                 while(q)
                 {
                         p->next=q->next;
                         free(q);
                         q=p->next;
                 }
        }
private:
        ListNodeptr *top;
        int count;
};

void Stack::popi()
{
        if((*top)->next)
        {
                ListNodeptr q=(*top)->next;
                (*top)->next=q->next;
                free(q);
                count--;
        }
        else
                cout<<"Unseccessful! There are no elements remains!"<<endl;
}

void Stack::pushi(int value)
{
    
        ListNodeptr p=(ListNodeptr)malloc(sizeof(ListNode));
                        if(!p)
                        {
                                cout<<"内存分配失败\n";
                        }
                        else
                        {
                            p->data=value;
                            p->next=(*top)->next;
                            (*top)->next=p;
                            count++;
                        }
}

void Stack::showi()
{
        ListNodeptr p=*top;
        while(p->next)
        {
                ListNodeptr q=p->next;
                cout<<q->data<<" ";
        }
        cout<<endl;
}

int main()
{
        Stack *st = new Stack(10);
        (*st).showi();
        for(int i=0;i<9;i++)
           (*st).pushi(i);
        (*st).showi();
        (*st).popi();
        (*st).showi();
        return 0;
}
