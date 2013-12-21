// ��ģ��С�� DFS��û����ô��֦������Ҫ�ľ��Ǻϲ���С��Ԫ��
// ��� map �õó�ˬ
// 2886372 2008-05-03 13:21:42 Accepted 1711 C++ 00:00.00 840K ���͵�����  

#include <iostream>
#include <functional>
#include <map>
using namespace std;

map<int, int, greater<int> >   M;
typedef map<int, int>::iterator Iter;
int     N,  K,  T;
int     A[12],  top;

bool DFS( Iter it, const int& remain ) {
    
    if( it == M.end() || remain < 0 )
        return  false;
    
    if( !remain ) {
        cout << *A;
        for( int i = 1; i < top; ++i )
            cout << '+' << A[i];
        cout << endl;
        return  true;
    }
    
    if( !it -> second )
        return  DFS( ++it, remain );
    
    it -> second --;
    A[top++] = it -> first;
    bool    ret = DFS( it, remain - it -> first );
    top--;
    it -> second ++;

    return  DFS( ++it, remain ) || ret;
    
    
}

int main() {
    
    while( ( cin >> N >> K ) && N ) {
        
        M.clear();
        
        while( K-- ) {
            cin >> T;
            ++M[T];
        }
        
        cout << "Sums of " << N << ":\n";
        top = 0;
        if( !DFS( M.begin(), N ) )
            puts( "NONE" );
        
    }

}
