// 2901232 2008-05-09 15:56:40 Accepted 1012 C++ 00:01.16 1528K ���͵����� 

// 4WA...���ѵ�ģ���⣬����Ģ����û�������Ŀ����������
// �������˷�������Ҫ�ļ��㣬ʣ�¾���С�ĵ������� 

/*
PS1: ����ʵ��һ���򵥵�ģ����,��Ҫ����Ŀ���ȽϷѾ�,��Ҫ���������byelaw�ͺ���. 
1. ��m��CPU,n����ڴ�;
2. ���ն����Ŷ�˳����;
3. ����Ji��Ҫa��CPUb����ڴ�,Ԥ��ʼʱ��ΪTi,Ҫ����Uiʱ���,��ɹ���Ji�񱨳�Vi,ÿ��ǰһ����λʱ����ɽ���Wi,ÿ�Ӻ�һ��λʱ����ɳͷ�Xi;
4. �ѷ����һ��������CPU��Memory��Դ����ͬʱ�ٷ���������Ĺ���,ֻ�еȴ��˹�������˲��Ǹ��ͷ���Դ,��������ʣ����Դ��������һ������������,�����ͬʱ�������һ������;
5. ÿһ��������Ҫ1����λʱ�����;
6. �����ǰû�й���,ϵͳ���ȴ�;
7. ����ж������ͬʱ��Ԥ����ʼʱ��,V����ȿ�ʼ,�ٶ�������i,j��Vi!=Vj ;
8. ���ϵͳ��Դ������һ��������ִ��,�����������ȴ�����,��1����λʱ����ټ��ϵͳ��Դ(����ԭʼ�Ĺ����������,�������);
9. �����������ȴ�,�ȵȴ����ȼ��.
PS2: 
         1. ���Ui>F,���ҹ������ܱ�ִ��,��ͳ��;
         2. �������������,���ǳ�����deadline,��Ҫ����ͷ�;
         3. �������û�б���,��deadline<=timeline,ҲҪ����ͷ�,���Ҵ�ʱ����������Ļر�(reward),������Ȼ��,��Ϊ��û���������.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct Run {

    int     A,  B,  T,  U,  V,  W,  X;
    
    void input() { cin >> A >> B >> T >> U >> V >> W >> X; }
};

bool icmp( const Run& r1, const Run& r2 ) {
    return  r1.T < r2.T || r1.T == r2.T && r1.V > r2.V;
}

int main() {

    int     F,  N,  T = 1;
    int     CPU,    MEM,    income;
    
    vector<Run>     all,    running;
    list<Run>       waiting;
    list<Run>::iterator iter;
    
    while( ( cin >> F ) && F ) {
        
        cin >> CPU >> MEM >> N;
        
        all.resize( N );
        for( int i = 0; i < N; ++i )
            all[i].input();
            
        sort( all.begin(), all.end(), icmp );
        income = 0;
        running.clear();
        waiting.clear();
        
        for( int i = 0, pos = 0; i <= F; ++i ) {

            while( !running.empty() ) {
                income += running.back().V;
                if( i < running.back().U )
                    income += ( running.back().U - i ) * running.back().W;
                else
                    income += ( running.back().U - i ) * running.back().X;
                CPU += running.back().A;
                MEM += running.back().B;
                running.pop_back();
            }
            
            if( i == F ) {
                for( iter = waiting.begin(); iter != waiting.end(); ++iter )
                    if( i > iter -> U )
                        income += ( iter -> U - i ) * iter -> X;
                break;
            }
            
            while( pos < N && all[pos].T == i )
                waiting.push_back( all[pos++] );

            for( iter = waiting.begin(); iter != waiting.end(); ) {
                if( CPU >= iter -> A && MEM >= iter -> B ) {
                    running.push_back( *iter );
                    CPU -= iter -> A;
                    MEM -= iter -> B;
                    iter = waiting.erase( iter );
                }
                else    ++iter;
            }
            
        }
        
        cout << "Case " << T++ << ": " << income << endl << endl;
        
    }

}
