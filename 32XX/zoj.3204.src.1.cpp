// 1882479 2009-05-24 01:41:38 Accepted  3204 C++ 320 416 ���͵����� 

// ��΢��ǿ����С�������ˣ��� Kruscal����Ԥ�����ʱ��Ҳ���ֵ����Ⱥ��ǽ�ȥ�����ˡ�

////////////////////////////////////////////////////
//              ���鼯ģ��(UFS) v1.2              //
////////////////////////////////////////////////////
//                                                //
// 1. SZ:         ���鼯���Ԫ������(ģ�����);   //
// 2. make_set:   ��ʼ�� N ��Ԫ�صĲ��鼯;        //
// 3. find_set:   �ҳ�ĳ��Ԫ�����ڵļ���;         //
// 4. union_set:  �ϲ���������;                   // 
// 5. get_sets:   ���ز��鼯�Ӽ��ĸ���;           //
// 6. get_size:   ����Ԫ�������Ӽ��Ĵ�С;         //
//                                                //
// v1.2 �����ԣ�                                  // 
//   ����ʽ���ԣ� ���Ⱥϲ���·��ѹ��              //
//   �����ӿڣ�   �Ӽ��������Ӽ���С              // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class UFS {

    int p[SZ+1], rank[SZ+1], size[SZ+1], sets; 

public:
    
    void make_set( int sz ) {
        for( int i = 0; i <= sz; ++i ) {
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
        sets = sz;
    }
    
    int find_set( int x ) {
        if( x != p[x] )
            p[x] = find_set( p[x] );
        return  p[x];
    }

    bool union_set( int x, int y ) {
        x = find_set( x );
        y = find_set( y );
        if( x == y )    return  false;
        --sets;
        if( rank[x] > rank[y] ) {
            size[x] += size[y];
            p[y] = x;
        }
        else {
            size[y] += size[x];
            p[x] = y;
        }
        if( rank[x] == rank[y] )
            ++rank[y];
        return  true;
    }
    
    int get_sets() const { return sets; }
    
    int get_size( int x ) { return size[find_set( x )]; }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int m, n, l;
    Edge(int m, int n, int l) : m(m), n(n), l(l) {}
};

bool operator <(const Edge& lhs, const Edge& rhs) {
    if(lhs.l < rhs.l) return true;
    if(lhs.l > rhs.l) return false;
    if(lhs.m < rhs.m) return true;
    if(lhs.m > rhs.m) return false;
    return lhs.n < rhs.n;
}

int G[100][100], T, N;

UFS<100> ufs;

vector<pair<int, int> > V;
vector<Edge> E;

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> G[i][j];
        E.clear();
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                if(G[i][j] != 0)
                    E.push_back(Edge(i, j, G[i][j]));
        sort(E.begin(), E.end());
        ufs.make_set(N);
        V.clear();
        for(int i = 0; i < E.size(); ++i) {
            if(ufs.find_set(E[i].m) == ufs.find_set(E[i].n)) continue;
            V.push_back(make_pair(E[i].m+1, E[i].n+1));
            ufs.union_set(E[i].m, E[i].n);
        }
        if(ufs.get_sets() != 1) puts("-1");
        else {
            sort(V.begin(), V.end());
            for(int i = 0; i < V.size(); ++i) {
                if(i) putchar(' ');
                cout << V[i].first << ' ' << V[i].second;
            }
            cout << endl;
        }
    }
}
