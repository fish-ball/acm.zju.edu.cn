// 1658543 2008-10-06 15:04:26 Accepted  2592 C++ 650 4092 ���͵����� 

// ̰�ģ�����ԭ������ A[]��BK[] �Ǵ�β���ۼ����飬FD[] �Ǵ�ͷ���ۼ����� 
// BKMX[] �Ǵ�β���ۼ����ֵ��FDMN[] �Ǵ�ͷ���ۼ���Сֵ
// ö�� j���� k > j������ BK[j]-BK[k] > 0�����Ҫ�� BK[j]-BKMX[j+1] > 0
//         �� k < j������ BK[j]+FD[k] > 0�����Ҫ�� BK[j]+FDMN[j-1] < 0
//         �� k == j��ֻ�� A[j] > 0������Ҫ���ܺ� S > 0, BK[j] > 0
// �������������������� j ��Ϊ�Ϸ������� +1
// ���ɸ����鼰�����Ϊ O(1)����������㷨ʱ��Ч��Ϊ O(1)�� 


#include <iostream>
#include <algorithm>
using namespace std;

int A[200000], FD[200000], BK[200000], S, N, T;
int BKMX[200000], FDMN[200000];

int main() {

    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for(int i = S = 0; i < N; ++i) {
            scanf("%d", A + i);
            S += A[i];
            FD[i] = A[i];
            if(i) FD[i] += FD[i-1];
        }
        for(int i = 0; i < N; ++i)
            BK[i] = S - FD[i] + A[i];
        
        if(S <= 0) {puts("0"); continue;}
        
        BKMX[N-1] = BK[N-1];
        for(int i = N-2; i >= 0; --i)
            BKMX[i] = max(BK[i], BKMX[i+1]);
            
        FDMN[0] = FD[0];
        for(int i = 1; i < N; ++i)
            FDMN[i] = min(FD[i], FDMN[i-1]);
            
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            bool yes = A[i] > 0 && BK[i] > 0;
            if(i < N-1 && BK[i] - BKMX[i+1] <= 0)
                yes = false;
            if(i > 0 && BK[i] + FDMN[i-1] <= 0)
                yes = false;
            ans += yes;
        }
        
        printf("%d\n", ans);

    }
}
