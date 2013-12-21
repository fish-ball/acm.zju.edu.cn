// 2003013 2009-09-26 18:12:02 Accepted  2254 C++ 220 208 ���͵����� 

// ���䣬LCS ת LIS��ǰ���� LCS ��˫������һ���ȳ����û���
// �� LCS ����û�֮�󣬶������ �û�֮��������� LIS ���ɡ�
// ������������ǰ������ȼ�������Ե�˳��Ȼ���� LCS ���ɡ� 

#include <iostream>
#include <algorithm>
using namespace std;

//�����������,���Ӷ�O(nlogn)
//ע����С���и��Ǻ�����еĶ�Ӧ��ϵ,����
//"define _cp(a,b) ((a)>(b))"�����ϸ�ݼ�����,��
//"define _cp(a,b) (!((a)>(b)))"�����С�ϸ�ݼ����и���
//�ɸ���Ԫ�����ͺͱȽϺ���
#define MAXN 1000
#define _cp(a,b) ((a)>(b))
typedef int elem_t;

int subseq(int n,elem_t* a){
	int b[MAXN],i,l,r,m,ret=0;
	for (i=0;i<n;b[l]=i++,ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			if (_cp(a[b[m]],a[i]))
				l=m+1;
			else
				r=m-1;
	return ret;
}


int N, P[1000], Q[1000];
pair<int, int> A[1000], B[1000];

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }
        sort(A, A + N);
        sort(B, B + N);
        for(int i = 0; i < N; ++i)
            P[A[i].second] = i;
        for(int i = 0; i < N; ++i)
            Q[i] = -P[B[i].second];
        cout << subseq(N, Q) << endl;
    }
}
