// 1651806 2008-09-29 22:27:37 Accepted  2210 C++ 80 1644 ���͵����� 

// ���· Dijkstra ������ע�� Nemo ��λ�� X, Y ���ܴ��� 200 

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
#include <algorithm>
using namespace std;

const int X = 202, Y = 202;

int WH[210][210], WV[210][210];
int DH[210][210], DV[210][210];
int G[210][210];

MBH<210*210> hp;

int main() {
    
    int N, M, x, y, k, l, px, py;
    double fx, fy;
    while(cin >> N >> M && N != -1) {
        memset(WH, 0, sizeof(WH));
        memset(WV, 0, sizeof(WV));
        memset(DH, 0, sizeof(DH));
        memset(DV, 0, sizeof(DV));
        
        while(N--) {
            cin >> x >> y >> k >> l;
            if(k) while(l--)
                WV[x][y++] = true;
            else while(l--) 
                WH[x++][y] = true;
        }
        while(M--) {
            cin >> x >> y >> k;
            if(k) {DV[x][y] = true; WV[x][y] = false;}
            else {DH[x][y] = true; WH[x][y] = false;}
        }
        cin >> fx >> fy;
        if(fx > X || fy > Y) {
            puts("0");
            continue;
        }
        px = int(fx);
        py = int(fy);
        memset(G, -1, sizeof(G));
        hp.clear();
        hp.push(0, 0);
        while(!hp.empty()) {
            x = hp.top().first % X;
            y = hp.top().first / X;
            k = G[x][y] = hp.top().second;
            if(x == px && y == py) break;
            hp.pop();
            if(x > 0 && !WV[x][y] && G[x-1][y] == -1)
                hp.push(x-1+y*X, k + DV[x][y]);
            if(x + 1 < X && !WV[x+1][y] && G[x+1][y] == -1)
                hp.push(x+1+y*X, k + DV[x+1][y]);
            if(y > 0 && !WH[x][y] && G[x][y-1] == -1)
                hp.push(x+(y-1)*X, k + DH[x][y]);
            if(y + 1 < Y && !WH[x][y+1] && G[x][y+1] == -1)
                hp.push(x+(y+1)*X, k + DH[x][y+1]);
        }
        
        cout << G[px][py] << endl;
    }
    
}
