// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: Anagrams by Stack

#include <iostream>
#include <string>
#define MAXLEN 200 
using namespace std;

class Stack
{ public:
    Stack(){}
    void init();                // ��׼������������������ַ� 
    void recvr();               // �ָ���ջ��ջ��������ɵ�Ӱ�� 
    bool push();                // Դ����ջһ���ַ� 
    bool pop();                 // Ŀ�괮����һ���ַ� 
    bool proc(char*);           // ���ܲ����ַ���������"io"�������� 
    bool check();               // ���Ŀ�괮��Ҫ����ַ����Ƿ���� 
    void display();
  private:
    char a[MAXLEN];
    char at[MAXLEN], *p1;
    char b[MAXLEN];
    char bt[MAXLEN], *p2;
    char s[MAXLEN], *top;
    int count;
};

int main()
{ Stack word[10];
  int i=0; 
  while(1) 
  { word[i].init(); i++;
   if(cin.eof()) break; 
  }
  for(int j=0;j<=i-2;j++) word[j].display();
   return 0;
}

void Stack::init()
{ cin>>a; strcpy(at,a);
  cin>>b; strcpy(bt,"");
  count=(strlen(a)==strlen(b))?strlen(a):0;
  p1=at; p2=bt;
  *s='\0', top=s;
}
void Stack::recvr()
{ strcpy(at,a); strcpy(bt,"");
  p1=at; p2=bt; *s='\0', top=s;
}
bool Stack::push()
{ if(!(*p1)) return 0;
  *(top++)=*(p1++);
  *top='\0';
  return 1;
}
bool Stack::pop()
{ if(top==s) return 0;
  *(p2++)=*(--top);
  *top=*p2='\0';
  return 1;
}
bool Stack::proc(char* t)
{ for(char *tp=t;*tp;tp++)
  { if(*tp=='i') if(!push()) return 0;
    if(*tp=='o') if(!pop()) return 0;
  }
  return 1;
}
bool Stack::check()
{ return !strcmp(b,bt);} 
void Stack::display()
{ cout<<"["<<endl;
  int i=count,o=count,k; 
  char io[MAXLEN*2]="";
  bool mark[MAXLEN*2]={}; 
  while(1)
  { // ����һ��io 
    while(o>0)
    { if(i==o) { mark[2*count-i-o]=0; io[2*count-(i--)-o]='i'; } 
      else if(i==0) { mark[2*count-i-o]=0; io[2*count-i-(o--)]='o'; }
      else if(o>i&&mark[2*count-i-o]) 
      { mark[2*count-i-o]=0; io[2*count-i-(o--)]='o'; }
      else if(o>i&&!mark[2*count-i-o]) 
      { mark[2*count-i-o]=1; io[2*count-(i--)-o]='i'; }  
    }
    // ���һ��io 
    recvr(); 
    proc(io);
    if(check())
    { for(k=0;k<2*count;k++) cout<<io[k]<<" "; cout<<endl; }
    // ����Ƿ���������� 
    bool end=1; 
    for(k=2*count-1;k>=0;k--) 
    { if(mark[k]==1) { end=0; break; } 
      else { if(io[k]=='i') i++; else o++; }
    }
    if(io[k]=='i') i++; else o++;
    if(end) break;  
  } 
  cout<<"]"<<endl;
}
