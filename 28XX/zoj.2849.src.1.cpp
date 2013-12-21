// 1688347 2008-11-03 22:04:08 Accepted  2849 C++ 720 6412 ���͵����� 

// ���͵����· PFS��ÿ���ڵ��һ�����ȶ��У����ȼ���Ϊ��
// ʱ���Ƕ̵����ȣ���α��ֺ�С�����ȡ� 

//////////////////////////////////////////////////////////
//       ӳ����ֶ�(Mapped_Binary_Heap)��ģ�� v1.3      //
//////////////////////////////////////////////////////////
//                                                      //
//                   ģ�����                           //
// 1. SZ:     ӳ����ֶѵ����������;                   //
// 2. T:      ӳ����ֶ��̺�ֵ���ͣ�ȱʡΪ int;         //
// 3. Op:     �Ƚ�׼�� functor��ȱʡΪС��;             // 
//                                                      //
//                     �ӿ�                             //
// 1. clear:  ��ն�;                                   //
// 2. empty:  �п�;                                     // 
// 3. size:   ���ضѴ�С(Ԫ�ظ���);                     //
// 4. top:    ���ضѶ�Ԫ��(������ֵ���);               //
// 5. push:   ����������Ԫ�أ��Զ�ʶ�����Ϊ��Сֵ;     //
// 6. pop:    ɾ����Сֵ;                               //
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <functional>
#include <algorithm>
using namespace std;

template <int SZ, class T = int, class Op = less<T> >
class MBH {

    pair<int, T> heap[SZ + 1];
    int key[SZ + 1], sz;

public:

    void clear() { sz = 0; memset( key, 0, sizeof( key ) ); }
    
    int size() const { return sz; }
    
    bool empty() const { return sz == 0; } 
    
    pair<int, T> top() const { return heap[1]; }
    
    void push( int idx, T val ) {
        if( !key[idx] ) {
            key[idx] = ++sz;
            heap[sz] = make_pair( idx, val );
        }
        else if( Op()( val, heap[key[idx]].second ) )
            heap[key[idx]].second = val;
        for( int pos = key[idx], c;
            ( c = pos >> 1 ) && Op()( val, heap[c].second ); pos = c ) {
            swap( heap[pos], heap[c] );
            key[idx] = c;
            key[heap[pos].first] = pos;
        }
    }
    
    void pop() {
        key[heap[1].first] = 0;
        heap[1] = heap[sz--];
        if( sz == 0 )   return;
        key[heap[1].first] = 1;
        for( int pos = 1, c; ( c = pos<<1 ) <= sz; pos = c ) {
            if( c < sz && Op()( heap[c+1].second, heap[c].second ) ) ++c;
            if( Op()( heap[c].second, heap[pos].second ) ) {
                swap( heap[c], heap[pos] );
                key[heap[c].first] = c;
                key[heap[pos].first] = pos;
            }
            else break;
        }
    }

};

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

const int N1 = 520;

int G[N1][N1], M, N, Q, K;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> cnt;

bool inside(int x, int y) {
    return x >= 0 && x < M &&
            y >= 0 && y < N;
}

MBH<N1*N1, pair<int, int> > hp;

int main() {

    while(scanf("%d%d", &M, &N) != EOF) {
        hp.clear();
        int V = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &G[i][j]);
                if(G[i][j] > 0) {
                    hp.push(i*N1+j, make_pair(1, G[i][j]));
                    V = max(V, G[i][j]);
                }
            }
        }
        while(!hp.empty()) {
            int x = hp.top().first / N1;
            int y = hp.top().first % N1;
            int d = hp.top().second.first;
            int v = hp.top().second.second;
            G[x][y] = v;
            hp.pop();
            for(int i = 0; i < 4; ++i) {
                x += dx[i];
                y += dy[i];
                if(inside(x, y) && G[x][y] < 0)
                    hp.push(x*N1+y, make_pair(max(d, -G[x][y]), v));
                y -= dy[i];
                x -= dx[i];
            }
        }
        cnt.assign(V+1, 0);
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                cnt[G[i][j]] += 1;
        for(scanf("%d", &Q); Q--;) {
            scanf("%d", &K);
            printf("%d\n", cnt[K]);
        }
    }

}
