// 1706060 2008-11-21 20:52:15 Accepted  2967 C++ 80 184 ���͵����� 

// ��ջ̰�ķ����Ȱ�б������Ȼ����һ����ջ����һϵ�� "��ֱ��" �� 
// ��ֱ�߱���ֱ�ߺ����һ������ x ֵ��
// Ȼ�����������ջ����ֱ�ߣ�����¼����ֱ����ջ��ֱ�߽���С��ջ�� x����ջ��
// ֱ����ջֻʣһ���������������������µ� x ��ֱ�ߡ�
// ����ջ�Ĵ�С��Ϊ���� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double, double> Line;

const double EPS = 1e-8;

vector<Line> L;
vector<pair<double, Line> > stk;

int T, N;

inline bool lt(double x, double y) {return x < y - EPS;}
inline bool gt(double x, double y) {return y < x - EPS;}
inline bool le(double x, double y) {return x < y + EPS;}
inline bool ge(double x, double y) {return y < x + EPS;}
inline bool eq(double x, double y) {return x < y + EPS && y < x + EPS;}
inline bool ne(double x, double y) {return x > y + EPS || y > x + EPS;}

double intersect(const Line& m, const Line& n) {
    return (m.second - n.second) / (n.first - m.first);
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        L.resize(N);
        for(int i = 0; i < N; ++i)
            scanf("%lf%lf", &L[i].first, &L[i].second);
        sort(L.begin(), L.end());
        for(int i = N = 1; i < L.size(); ++i) {
            if(eq(L[i].first, L[N-1].first)) {
                if(gt(L[i].second, L[N-1].second))
                    swap(L[i], L[N-1]);
            }
            else L[N++] = L[i];
        }
        L.resize(N);
        stk.clear();
        stk.push_back(make_pair(0.0, L[0]));
        for(int i = 1; i < N; ++i) {
            while(1) {
                double x = intersect(L[i], stk.back().second);
                if(stk.size() > 1 && le(x, stk.back().first))
                    stk.pop_back();
                else {
                    stk.push_back(make_pair(x, L[i]));
                    break;
                }
            }
        }
        cout << stk.size() << endl;
    }
    
}
