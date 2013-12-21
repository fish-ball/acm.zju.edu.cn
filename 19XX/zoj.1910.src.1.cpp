// 2942203 2008-06-04 20:14:14 Accepted 1910 C++ 00:00.02 832K ���͵����� 

// ����ö�٣�����Ҫ�뵱Ȼ�������п��ܵ������Ҫö�ٳ������� 

#include <iostream>
using namespace std;

int main() {
    
    int T,  V,  S,  M,  x,  y,  z,  s;

    for( cin >> T; T--; ) {
        
        cin >> V;
        
        if( !V ) {
            cout << 0 << endl;
            continue;
        }
        
        S = 0x7FFFFFFF;
        for( M = 1; M * M * M < V; ++M );
        
        for( x = 1; x <= V; ++x ) {
            for( y = V / x; y > 0; --y ) {
                if( V % ( x * y ) )
                    continue;
                s = x*y + V/x + V/y;
                S = s < S ? s : S;
            }
        }
        
        cout << S * 2 << endl;
        
    }

}
