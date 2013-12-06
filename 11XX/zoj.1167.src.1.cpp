// 2917585 2008-05-16 09:46:03 Accepted 1167 C++ 00:00.01 852K ���͵����� 

// ��ʵ���ý����ģ�ֻ��Ҫ��·���ַ�������
// �̵ķ�ǰ��(�ȼ���)��Ȼ���ֵ���С�ķ�ǰ��(���)
// �б���������нڵ�ĸ��ڵ��Ƿ���ڣ�
// �ڼ�����������ǰ�ڵ�ɾ�����һ��·�����ʣ�ಿ��
// ����������ˣ��Ǿ��ǲ��Ϸ�
// ���⣬�����ʱ��������·���ַ����Ƿ��Ѿ����� 

/*
(1,) (2,L) (3,LR) (4,LRL) (5,LRLL) ()

Output:
1 2 3 4 5
*/

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef map<string, string>::iterator  MIter;

inline bool icmp( const MIter& it1, const MIter& it2 ) {
    if( it1 -> first.size() < it2 -> first.size() ) return  true;
    if( it1 -> first.size() > it2 -> first.size() ) return  false;
    return  it1 -> first < it2 -> first;
}

int main() {
    
    string  input,  seq,    val;
    
    int     pos;
    
    map<string, string>    M;
    vector<MIter>       V;

    while( cin >> input ) {
        
        M.clear();

        bool    complete = true;

        while( 1 ) {

            if( input == "()" ) break;
            pos = input.find( ',' );
            val = input.substr( 1, pos - 1 );
            seq = input.substr( pos + 1, input.size() - pos - 2 );
            if( M.find( seq ) != M.end() )
                complete = false;
            else    M.insert( make_pair( seq, val ) );

            cin >> input;

        }
        
        V.clear();
        
        if( !complete ) {
            puts( "not complete" );
            continue;
        }
        
        if( M.empty() ) {
            puts( "" );
            continue;
        }
        
        for( MIter iter = M.begin(); iter != M.end(); ++iter ) {
            
            V.push_back( iter );
            if( iter -> second == "" ||
                iter -> first != "" &&
                M.find( iter -> first.substr( 0,
                        iter -> first.size() - 1 )
                      ) == M.end() 
              ) {
                complete = false;
                break;
            }

        }

        if( !complete ) {
            puts( "not complete" );
            continue;
        }

        sort( V.begin(), V.end(), icmp );

        for( int i = 0; i < V.size(); ++i ) {
            cout << V[i] -> second;
            if( i != V.size() - 1 )
                putchar( ' ' );
            else
                putchar( '\n' );
        }
        
    }
    
}
