// 2151670 2010-04-10 19:46:07 Accepted  3317 C++ 20 184 ���͵����� 

// �Ƶ궩�����Ȱѽ����¼����˳��¼��ֲ𿪷ŵ�һ���������ʱ���Ⱥ�����
// Ȼ��ֱ��ģ�⼴�ɡ� 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while(cin >> N >> M && N) {
        pair<int, int> EV[200] = {};
        int AS[100] = {};
        bool RM[100] = {};
        for(int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            EV[2*i] = make_pair(2*x+1, i);
            EV[2*i+1] = make_pair(2*y, i);
        }
        sort(EV, EV + 2 * N);
        for(int i = 0; i < 2 * N; ++i) {
            int x = EV[i].first, y = EV[i].second;
            if(x % 2) {
                for(int j = 0; j < M; ++j) {
                    if(!RM[j]) {
                        RM[j] = true;
                        AS[y] = j + 1;
                        break;
                    }
                }
            }
            else {
                if(AS[y]) {
                    RM[AS[y]-1] = false;
                }
            }
        }
        for(int i = 0; i < N; ++i) {
            cout << AS[i] << endl;
        }
    }
}
