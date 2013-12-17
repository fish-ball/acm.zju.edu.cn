// 2970876 2008-07-11 10:17:16 Accepted 1374 C++ 00:00.03 864K ���͵����� 

// ����һ���ַ����������һ���ַ�����ʹ�ã�
// �������ľ��񣨲���Ҫ���У�������Ϊÿһ�������ַ���������ִ� 

#include <string>
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int     T,  N;
vector<string>  V; 

bool icmp( const string& s1, const string& s2 ) {
    return  s1.size() < s2.size(); 
} 

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        V.resize( N ); 
        for( int i = 0; i < N; ++i ) 
            cin >> V[i]; 
            
        sort( V.begin(), V.end(), icmp );
        
        int len = V[0].size(); 
        for( ; len >= 1; --len ) {
            bool    found = false; 
            for( int i = 0; i + len <= V[0].size(); ++i ) {
                string  s = V[0].substr( i, len );
                string  sv = s; reverse( sv.begin(), sv.end() ); 
                bool    yes = true;
                for( int j = 1; j < N; ++j ) {
                    if( V[j].find( s ) == string::npos &&
                        V[j].find( sv ) == string::npos ) {
                        yes = false;
                        break; 
                    }
                } 
                if( yes ) {
                    found = true;
                    break;
                } 
            }
            if( found ) break; 
        } 
        cout << len << endl; 
        
    } 
    
} 
