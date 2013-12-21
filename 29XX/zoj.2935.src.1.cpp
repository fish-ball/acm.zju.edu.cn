// 1693333 2008-11-08 16:30:59 Accepted  2935 C++ 0 196 ���͵����� 

// ��ͼ���·��ֱ�ӹ�Լ��һ��ͼ Dijkstra�� 

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

MBH<500, int> hp;

int D[500];

vector<pair<int, int> > G[500];

int M, N, K;

int main() {
    while(cin >> M >> N && M) {
        hp.clear();
        K = (M+1) * (N+1);
        memset(D, -1, sizeof(D));
        for(int i = 0; i < K; ++i)
            G[i].clear();
        for(int i = 0, dist; i < N; ++i) {
            char c;
            cin >> dist >> c;
            if(dist == 0) continue;
            dist = 2520 / dist;
            if(c == '>' || c == '*')
                G[0*(N+1)+i].push_back(make_pair(0*(N+1)+i+1, dist));
            if(c == '<' || c == '*')
                G[0*(N+1)+i+1].push_back(make_pair(0*(N+1)+i, dist));
        }
        for(int j = 0; j < M; ++j) {
            for(int i = 0, dist; i <= N; ++i) {
                char c;
                cin >> dist >> c;
                if(dist == 0) continue;
                dist = 2520 / dist;
                if(c == 'v' || c == '*')
                    G[j*(N+1)+i].push_back(make_pair((j+1)*(N+1)+i, dist));
                if(c == '^' || c == '*')
                    G[(j+1)*(N+1)+i].push_back(make_pair(j*(N+1)+i, dist));
            }
            for(int i = 0, dist; i < N; ++i) {
                char c;
                cin >> dist >> c;
                if(dist == 0) continue;
                dist = 2520 / dist;
                if(c == '>' || c == '*')
                    G[(j+1)*(N+1)+i].push_back(make_pair((j+1)*(N+1)+i+1, dist));
                if(c == '<' || c == '*')
                    G[(j+1)*(N+1)+i+1].push_back(make_pair((j+1)*(N+1)+i, dist));
            }
        }
        hp.push(0, 0);
        while(!hp.empty()) {
            int x = hp.top().first;
            int d = hp.top().second;
            D[x] = d;
            hp.pop();
            for(int i = 0; i < G[x].size(); ++i)
                if(D[G[x][i].first] == -1)
                    hp.push(G[x][i].first, d + G[x][i].second);
        }
        if(D[(M+1)*(N+1)-1] == -1) puts("Holiday");
        else printf("%d blips\n", D[(M+1)*(N+1)-1]);
    }
}
