// 2924573 2008-05-20 15:27:56 Accepted 2956 C++ 00:00.11 876K ���͵����� 

// �Ƚϱ�������񷽷����Թ���x ����û�ã��� cpg �ı���:

// �Ƚ�ˮ ����һ�� ymin - ymax ������
// ����һ�������� y1 - y2 �����еĵ㶼�� 1
// ����ҵ����Ĵ����Ϳ�����

#include <iostream>
using namespace std;

int cnt[10001], x, y, tot;

int main() {
    
    int     T,  N;
    for( cin >> T; T--; ) {
        memset( cnt, 0, sizeof( cnt ) );
        for( cin >> N; N--; ) {
            cin >> x >> x >> y;
            for( int i = x; i <= y; ++i )
                ++cnt[i];
        }
        tot = 0;
        for( int i = 0; i <= 10000; ++i )
            tot = tot > cnt[i] ? tot : cnt[i];
        cout << tot << endl;
    }
    
}
