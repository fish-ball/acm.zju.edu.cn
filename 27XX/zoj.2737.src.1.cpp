// 2937877 2008-05-31 00:50:39 Accepted 2737 C++ 00:00.01 916K ���͵����� 

// �ַ���ƥ�䣬û��ô����Ч�ʣ������Ҹ���� 

#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int main() {
    
    map<string, int>    M;
    set<string>         S;
    string  s1, s2;
    
    while( cin >> s1 >> s2 ) {
        
        int N1 = s1.size(),
            N2 = s2.size();
        
        s2 += s2;
        
        M.clear();
        S.clear();
        
        for( int i = 0; i <= N1 - N2; ++i )
            ++M[s1.substr( i, N2 )];
        
        for( int i = 0; i < N2; ++i )
            S.insert( s2.substr( i, N2 ) );

        int tot = 0;

        for( set<string>::iterator iter = S.begin();
             iter != S.end(); ++iter )
            tot += M[*iter];
        
        cout << tot << endl;
        
    }
    
    
}
