// 2901232 2008-05-09 15:56:40 Accepted 1012 C++ 00:01.16 1528K 呆滞的慢板 

// 4WA...不难的模拟题，就是蘑菇，没读清楚题目就死翘翘了
// 还好有人翻译了重要的几点，剩下就是小心的事情了 

/*
PS1: 这其实是一道简单的模拟题,主要是题目理解比较费劲,主要理解好里面的byelaw就好了. 
1. 有m个CPU,n大的内存;
2. 按照队列排队顺序工作;
3. 工作Ji需要a个CPUb大的内存,预开始时间为Ti,要求在Ui时完成,完成工作Ji获报酬Vi,每提前一个单位时间完成奖励Wi,每延后一单位时间完成惩罚Xi;
4. 已分配给一个工作的CPU和Memory资源不能同时再分配给其它的工作,只有等待此工作完成了才那个释放资源,但是若有剩余资源能满足下一个工作的需求,则可以同时分配给下一个工作;
5. 每一个工作需要1个单位时间完成;
6. 如果当前没有工作,系统将等待;
7. 如果有多个工作同时到预定开始时间,V大的先开始,假定对任意i,j有Vi!=Vj ;
8. 如果系统资源不满足一个工作的执行,这个工作进入等待序列,在1个单位时间后再检查系统资源(不管原始的工作序列如何,先做检查);
9. 如果多个工作等待,先等待的先检查.
PS2: 
         1. 如果Ui>F,并且工作不能被执行,则不统计;
         2. 如果工作被做了,但是超过了deadline,则要计算惩罚;
         3. 如果工作没有被做,但deadline<=timeline,也要计算惩罚,并且此时不计算任务的回报(reward),这是显然的,因为并没有完成任务.
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
