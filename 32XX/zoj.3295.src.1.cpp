// 2084959 2010-01-31 23:47:25 Accepted  3295 C++ 30 188 ���͵����� 

// �����⣬��һ�� 2^N ��ѡ�ֵ�ȫ��̭����һ��������������Ӯ���پ֣��㷨��˵������ 

#include <iostream>
using namespace std;

int N, K;
int A[1024];

int main() {
    while(cin >> N >> K) {
        for(int i = 0; i < (1<<N); ++i) {
            cin >> A[i];
        }
        int above = 0, below = 0;
        int mx, mn;
        for(int i = 0; i < (1<<N); ++i) {
            if(A[i] > A[K]) above++;
            else if(A[i] < A[K]) below++;
        }
        if(above > 0) mn = 0;
        else mn = N;
        mx = 0;
        while((1<<mx)-1 <= below) ++mx;
        cout << mn << " " << mx - 1 << endl;
    }
} 
