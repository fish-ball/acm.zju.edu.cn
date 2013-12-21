// 1860297 2009-05-08 18:51:49 Accepted  2157 C++ 0 184 ���͵����� 

// һ����ʣ����б߶���ˮƽ������ֱ�ġ�
// �������еĹ��������꣬����ʵĳ��ȡ�
// �����ԣ�����ͬһ x ����ĵ��� 2k �������ǵ� y ����������� y[1..2k] 
// ��ô������ y2-y1 �϶�����ʣ� y4-y3 �϶�����ʣ��������ƣ��������
// ����ƽ�� x �����ʳ��ȡ��編���Ƽ������ƽ�� y ����һ���ֵġ� 

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    for(int N; cin >> N && N;) {
        map<int, vector<int> > X, Y;
        while(N--) {
            int x, y;
            scanf("%d%d", &x, &y);
            X[x].push_back(y);
            Y[y].push_back(x);
        }
        int ans = 0;
        for(map<int, vector<int> >::iterator it = X.begin();
                it != X.end(); ++it) {
            if(it->second.size() % 2) while(1) puts("OLE!!!");
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i < it->second.size(); i += 2)
                ans += it->second[i+1] - it->second[i];
        }
        for(map<int, vector<int> >::iterator it = Y.begin();
                it != Y.end(); ++it) {
            if(it->second.size() % 2) while(1) puts("OLE!!!");
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i < it->second.size(); i += 2)
                ans += it->second[i+1] - it->second[i];
        }
        printf("The length of the fence will be %d units.\n", ans);
    }
}
