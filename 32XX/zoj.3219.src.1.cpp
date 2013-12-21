// 1914705 2009-07-11 10:48:47 Accepted  3219 C++ 10 264 ���͵����� 

// ����ĸ�˹��Ԫ�����ݸ���ת�ƽ������Է����飬����Ԫ��⡣
// ״̬һ�� A+B+1 �֣����� X(K) �� javaman ���� K ��ƻ��ʱӮ�ĸ��ʣ�
// ��ô���� p �ĸ���ת�Ƶ� X(K-C) ���״̬��
// �� 1-p �ĸ���ת�Ƶ� X(K+D) ���״̬��
// ���Զ������� K>A+B���� X(K) = 1��
// ������ K<0 ���ߣ����� X(K) = 0�� 
// ��˿����г����̣�X(K) = p * X(K-C) + (1-p) * X(K+D)
// ���ֶ��б�һ�� K-C �� K+D����� > A+B ���� < 0 ���ɳ���
// �ɴ˼��ɹ������Է�������󣬴Ӷ���Ԫ��⡣ 

#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;

/*
TEST CASES:
    
100
5 5 3 2 0.6
5 5 6 4 0.6
5 5 2 4 0.6
5 5 1 0 0.6
5 5 0 1 0.6

*/

const int MAXN = 100;
const double EPS = 1e-10; 

int T, A, B, C, D, N;

double G[MAXN][MAXN+1];

double p;

// ��˹��Ԫ���� K*K+1 ��������� 
bool Gaussian_Elimination(double M[][MAXN+1], int K) {
    // ��������Ԫ 
    for(int r = 0; r < K; ++r) {
        // �������Ԫϵ��Ϊ�� 
        if(-EPS <= M[r][r] && M[r][r] < EPS) {
            // ִ���е���
            int idx = -1;
            for(int r2 = r + 1; r2 < K && idx == -1; ++r2)
                if(M[r2][r] < -EPS || M[r2][r] >= EPS)
                    idx = r2;
            // ���ȫ��Ϊ�㣬�����޽� 
            if(idx == -1) return false; 
            // ����ִ���е��� 
            for(int c = r; c <= K; ++c)
                swap(M[r][c], M[idx][c]);
        }
        // ���й�һ��
        for(int c = K; c >= r; --c)
            M[r][c] /= M[r][r];
        // �����·����� 
        for(int c = K; c >= r; --c)
            for(int r2 = r + 1; r2 < K; ++r2)
                M[r2][c] = M[r2][c] - M[r][c] * M[r2][r];
    }
    // ��������Ԫ
    for(int r = K - 1; r >= 0; --r) {
        for(int r2 = r - 1; r2 >= 0; --r2) {
            M[r2][K] -= M[r][K] * M[r2][r];
            M[r2][r] -= M[r2][r];
        }
    } 
    return true;
}

int main() {
    for(cin >> T; T--;) {
        scanf("%d%d%d%d%lf", &A, &B, &C, &D, &p);
        N = A + B + 1;
        memset(G, 0, sizeof(G));
        for(int X = 0; X <= A + B; ++X) {
            G[X][X] = 1; 
            if(X + D > A + B)
                G[X][A+B+1] += 1-p;
            else
                G[X][X+D] += p-1;
            if(X >= C)
                G[X][X-C] += -p;
        }
        if(!Gaussian_Elimination(G, A+B+1))
            while(1) puts("OLE!!");
        printf("%.2lf\n", G[A][A+B+1]);
    }
}
