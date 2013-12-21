// 3013467 2008-07-30 10:30:48 Accepted 1900 C++ 00:00.00 860K ���͵����� 

// P ���ˣ�T ����������һ�����ϣ�˵ �� i �������� �� j ����
// ����Щ�����治ͬ�Ĵ��ж����� 

#include <set>
#include <iostream>
#include <string>
using namespace std;

set<int>        S[101];
set<set<int> >  M;

int     T,  P,  x,  y;

string  eol;

int main() {
    
    while( cin >> P >> T ) {
        
        getline( cin, eol );
        
        for( int i = 1; i <= P; ++i )
            S[i].clear();
        
        while( isdigit( cin.peek() ) ) {
            cin >> x >> y;
            getline( cin, eol );
            S[x].insert( y );
        }
        
        M.clear();
        
        for( int i = 1; i <= P; ++i )
            M.insert( S[i] );
        
        cout << M.size() << endl;
        
    }
    
}
