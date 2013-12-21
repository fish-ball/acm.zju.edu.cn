// 2903787 2008-05-10 14:13:37 Accepted 1960 C++ 00:00.31 2644K ���͵����� 

// �ǳ����͵� STL �⣡��
// ע�����(���һ��)��"and print equal words only once"
// ��ˣ�Ҫ�� multiset ���������ִ������������������ʱ��������������ͬԪ�� 

#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline bool icmp( const map<string, multiset<string> >::iterator& iter1,
                  const map<string, multiset<string> >::iterator& iter2 ) {
    if( iter1 -> second.size() > iter2 -> second.size() ) return  true;
    if( iter1 -> second.size() < iter2 -> second.size() ) return  false;
    return  *iter1 -> second.begin() < *iter2 -> second.begin();
}

void disp( const map<string, multiset<string> >::iterator& iter ) {
    cout << "Group of size " << iter -> second.size() << ": ";
    string  forward = "";
    for( multiset<string>::iterator it = iter -> second.begin();
         it != iter -> second.end(); ++it ) {
        if( *it != forward )
            cout << *it << ' ';
        forward = *it;
    }
    cout << ".\n";
}

int main() {
    
    string  s1, s2;
    map<string, multiset<string> >    M;
    
    map<string, multiset<string> >::iterator iter;
    
    vector<map<string, multiset<string> >::iterator >    V;
    
    while( cin >> s1 ) {
        s2 = s1;
        sort( s2.begin(), s2.end() );
        M[s2].insert( s1 );
    }
    
    for( iter = M.begin(); iter != M.end(); ++iter )
        V.push_back( iter );
        
    sort( V.begin(), V.end(), icmp );
    
    for( int i = 0; i < 5 && i < V.size(); ++i )    disp( V[i] );
    
//    system( "pause" );
    
}
