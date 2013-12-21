// 3013007 2008-07-29 21:11:46 Accepted 1913 C++ 00:00.00 840K ���͵����� 

// ���ģ��ұ���㣬���������� gcd �Ĺ��̣�շת����� 
// ����:
    
// m  n     div     status 
// 24 15    1       lose
// 15 9     1       win
// 9  6     1       lose
// 6  3     2       win
// 3  0     -       lose(initial) 

// m  n     div     status
// 34 12    1       win
// 12 10    1       lose
// 10 2     5       win
// 2  0     -       lose(initial) 

// �㷨���̣���շת�������ʱ����һ��ջ������� m / n ��ֵ 
// ����λ���� lose_pose����Ϊ�Ѿ�������ȡ���ˣ� 
// Ȼ����ǰ�ƣ����һ��λ������ > 1����ô���� win_pose��
//   ��Ϊ���������ɾ���������һ�ֵ�λ�ã�ȡ���ʣһ����
// ������λ������ == 1����ô������һ��λ�õķ���

// ��˵��ƻ�ȥ���������ջ�յ�ʱ��״ֵ̬��Ҳ���ǿ�ʼ���������� pose 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;

int     M,  N,  R;

bool    win;

int main() {
    
    while( cin >> M >> N && M ) {
        
        if( N > M ) swap( N, M );
        V.clear();
        
        while( N ) {
            V.push_back( M / N );
            R = M % N;
            M = N;
            N = R;
        }
        
        V.pop_back();
        win = true;
        while( V.size() ) {
            if( V.back() == 1 )
                win ^= 1;
            else win = true;
            V.pop_back();
        }
       
        puts( win ? "Stan wins" : "Ollie wins" );
        
    }
    
}
