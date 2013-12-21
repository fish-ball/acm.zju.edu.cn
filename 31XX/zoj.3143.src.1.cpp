// 1761822 2009-02-12 21:21:59 Accepted  3143 C++ 50 184 ���͵����� 

// ̰�ģ�����һ�����У���һ����λ�˻�����ǰһ������
// ֱ�ӷֽ�ǰһ����ע��Ҫ�� 9 �� 2 �ֽ⣬ 
// Ȼ�󴮽������͵õ���һ���� 

#include <vector>
using namespace std;

typedef long long i64;

i64 find_next(i64 a) {
    if(a == 1) return 11;
    vector<int> V(0);
    for(int i = 9; i >= 2; --i) {
        while(a % i == 0) {
            a /= i;
            V.push_back(i);
        }
    }
    if(a != 1) return 0;
    if(V.size() == 1) V.push_back(1);
    i64 b = 0;
    while(!V.empty()) {
        b *= 10;
        b += V.back();
        V.pop_back();
    }
    return b;
}

int main() {
    
    int T;
    i64 a;
    vector<i64> V;
    
    for(scanf("%d", &T); T--;) {
        scanf("%lld", &a);
        V.clear();
        V.push_back(a);
        while(V.size() < 10) {
            a = find_next(a);
            if(a == 0) break;
            else V.push_back(a);
        }
        if(V.size() == 1)
            puts("No sequence");
        else {
            for(int i = 0; i < V.size(); ++i) {
                if(i) putchar(' ');
                printf("%lld", V[i]);
            }
            puts("");
        }
    }
    
}
