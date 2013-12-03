// PERFORMER: ELF
// DATE: Dec. 18th, 2007
// TITLE: Crashing Balloon
#include <iostream>
#define MAXLINE 2000 
using namespace std;

class Stack
{ public:
    Stack():top(0){}
    // ������ջ
    void reset(){ top=0; } 
    // ������ջ 
    void push(int num){ data[top++]=num; }
    // ���ݳ�ջ
    void pop(int &a){ a=data[--top]; }
    // ���һ�����Ƿ���ջ�� 
    bool offuse(int num)
    {for(int i=0;i<top;i++)if(num==data[i])return 1;return 0;} 
    // ��ջ�Ƿ�Ϊ��
    bool empty(){ return top==0; } 
    // ��ջ������ʾ 
    void disp(){ for(int i=0;i<top;i++)cout<<data[i]<<endl; } 
    // ���һ�����Ƿ�����ջ����������������ʽ 
    bool exist(int num);
  private:
    int data[5];
    int top;
};
bool Stack::exist(int num)
{ int i,temp; 
  Stack buf;
  temp=num;
  buf.push(2);
  while(1)
  { int t;
    for(buf.pop(i);i<=100;i++)
    { if(offuse(i)) continue; 
      if(temp%i==0) { temp/=i; buf.push(i); }
      if(temp==1) return 1;
    }
    if(buf.empty()) return 0; 
    buf.pop(t);
    temp*=t;
    buf.push(t+1);
  } 
} 

bool isprime(int a)
{ Stack buf;
  return !buf.exist(a); 
}

void judge(int a,int b)
{ if(a==0) {cout<<b<<endl; return;}
  if(b==0) {cout<<a<<endl; return;} 
  if(isprime(b)) {cout<<a<<endl; return;}
  if(isprime(a)) {cout<<b<<endl; return;}
  int i,j=0; 
  Stack buf;
  int temp=a; 
  buf.push(2); 
  while(1)
  { bool flag=0; 
    int t; 
    for(buf.pop(i);i<=100;i++)
    { if(temp%i==0) { temp/=i; buf.push(i); }
      if(temp==1) { flag=1; break; }
    }
    if(flag&&buf.exist(b)) {cout<<a<<endl; return;} 
    if(buf.empty()) break; 
    buf.pop(t);
    temp*=t; 
    buf.push(t+1);
  } 
  cout<<b<<endl; 
}

int main()
{ int a,b;
  while(cin>>a>>b)
  { if(a>b) judge(a,b);
    else judge(b,a); 
  } 
  return 0; 
} 

