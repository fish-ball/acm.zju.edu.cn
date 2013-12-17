// 1831446 2009-04-12 18:48:00 Accepted  1409 C++ 50 184 ���͵����� 

// ����Ѵ���۸�ȣ����д���Ϊ��������Ĵ�����Сֵ��
// �۸�Ϊ��������۸��ܺͣ���̰�ļ��ɣ�
// ��¼���п��ܵĴ���Ȼ��ö�ٴ��������ż۸�ֵ��ֱ��̰�ĵõ���ʱ�ı����������ֵ�� 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    
    int T, N;
    
    for(cin >> T; T--;) {
        
        set<int> bands;
        
        cin >> N;
        
        vector<vector<pair<int, int> > > V(N);
        
        for(int i = 0, K; i < N; ++i) {
            cin >> K;
            V[i].resize(K);
            for(int j = 0; j < K; ++j) {
                cin >> V[i][j].first >> V[i][j].second;
                bands.insert(V[i][j].first);
            }
        }
        
        double best = 0;
        
        for(set<int>::iterator it = bands.begin(); it != bands.end(); ++it) {
            int low = *it;
            int sum = 0;
            for(int i = 0; i < N; ++i) {
                int price = INT_MAX;
                for(int j = 0; j < V[i].size(); ++j) {
                    if(V[i][j].first >= low)
                        price = min(price, V[i][j].second);
                }
                if(price == INT_MAX) {
                    low = -1;
                    break;
                }
                else sum += price;
            }
            if(low == -1) continue;
            else best = max(best, double(low) / double(sum));
        } 
        
        printf("%.3lf\n", best);
        
    } 
    
}
