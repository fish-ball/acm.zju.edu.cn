// 1684590 2008-10-31 20:00:56 Accepted  2706 C++ 7650 300 ���͵����� 

// ����ģ�⼴�ɣ�ע����������������и����ģ���������ע��ȡ������
// Ч�ʷ��棬��̬ά����ǰ���е��ܺͣ�ÿ����ȡ�������ʱ��Ͳ����������ˡ� 

#include <iostream>
using namespace std;

typedef long long i64;

int N, Q, x, y, A[30000], z;

i64 sum, now, temp;

int main() {
    
    while(scanf("%d%d", &N, &Q) != EOF) {
        sum = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", A + i);
            sum += A[i];
        }
        now = sum;
        while(Q--) {
            scanf("%d%d", &x, &y);
            x -= 1;
            temp = 0;
            for(int i = x; i < y; ++i)
                temp += A[i];
            if(temp % (y - x) == 0) {
                z = temp / (y - x);
            }
            else if(now > sum) {
                z = temp / (y - x);
                if(temp < 0) z -= 1;
                now += z * i64(y - x) - temp;
            }
            else {
                z = temp / (y - x);
                if(temp > 0) z += 1;
                now += z * i64(y - x) - temp;
            }
            for(int i = x; i < y; ++i)
                A[i] = z;
        }
        for(int i = 0; i < N; ++i) {
            if(i) putchar(' ');
            printf("%d", A[i]);
        }
        puts("\n");
    }

}
