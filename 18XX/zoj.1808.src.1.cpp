// ����㷨����׾�ӣ�����Ȼ���
// ��ʱ�򲻰��������̫����Ҳδ������ 
// 2837064 2008-04-10 23:09:38 Accepted 1808 C++ 00:00.00 848K ���͵�����  

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    vector<string>  V;
    string  temp;
    int     T = 1;
    while( cin >> temp ) {
        V.resize( 0 );
        while( temp[0] != '9' ) {
            V.push_back( temp );
            cin >> temp;
        }
        sort( V.begin(), V.end() );
        bool    fail = false;
        for( int i = 1; i < V.size(); i++ ) {
            if( V[i].length() >= V[i-1].length() &&
                V[i].substr( 0, V[i-1].length() ) == V[i-1] ) {
                fail = true;
                break;
            }
        }
        cout << "Set " << T++ << " is ";
        if( fail )  cout << "not ";
        cout << "immediately decodable\n";
    }
}
