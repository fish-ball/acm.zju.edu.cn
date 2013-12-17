// 2895475 2008-05-07 12:13:40 Accepted 1360 C++ 00:00.15 888K ���͵����� 

// �����̰���⣡����ע���Ȼ WA
// �����ҾͲ��Լ�д�ˣ�����һ�λ���

/*      ������������ ϣ������ ĳλ���ֵĲ���
 
��Ŀ��������x��Ϊ�߽磬x������Ϊ��������Ϊ��½��
        �������ж���㣬�������λ�á�
        ������ⷶΧ��Բ�ε��״��Χ�뾶d
        ������Ҫ���ٸ��״���ܰѺ�����ĵ�ȫ��ͬʱ��⡣

��Ŀ������
1��̰��
2���Ӽ��˵������ʼ̰�ģ��Ӷ��������Ž⡣
3���ص��ڣ���Ӧÿ���㣬��������״�Բ�ϡ�����Բ������ʱ��Բ�ĵ����ꡣ
        ����Щ�״�Բ���е�x����˵�Բ��Ϊ��㣨��x��С��������̰�ġ�

��������
1��������ר��ѵ����֪���˸�̰�Ķ�̰�ģ�����֪���Ļ���ƾ�о�����
2���Ӽ��������ʼ̰�ġ�
        ֱ�����ǰѵ㰴x�������Լ��˵ĵ��������ȷ��̰�ĵ���㡣
        �����������������غ����˶Ե��y����Ĺ�ע��

///////////  ��ˣ�����׼��Ӧ��Ϊһ����Բ�뺣���߽��� X ����  ////////////// 

�ܽ᣺̰���㷨���󵨼��裬С����֤~������ף�ʵ�����ѣ�һ������WA�����~ */ 

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point { int  x,  y; double pos; };

double dist( const double& X, const Point& p ) {
    return  hypot( double( p.x ) - X, double( p.y ) );
}

bool operator < ( const Point& p1, const Point& p2 ) {
    return  p1.pos < p2.pos;
}

int main() {

    vector<Point>   V;
    int     N,  D,  C,  T = 0;
    double  X;

    while( ( cin >> N >> D ) && ( D || N ) ) {

        V.resize( N );

        bool valid = true;
        
        for( int i = 0; i < N; ++i ) {
            cin >> V[i].x >> V[i].y;
            if( V[i]. y > D )  valid = false;
            V[i].pos = double( V[i].x ) + sqrt( double( D * D - V[i].y * V[i].y ) );
        }
        
        cout << "Case " << ++T << ": ";
        
        if( !valid ) { puts( "-1" ); continue; }

        sort( V.begin(), V.end() );

        C = 1;
        X = V[0].pos;
        
        for( int i = 1; i < N; ++i ) {
            
            if( dist( X, V[i] ) > double( D ) + 1e-5 ) {
                ++C;
                X = V[i].pos;
            }
            
        }

        cout << C << endl;

    }
    
}
