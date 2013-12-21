// 2959658 2008-07-02 10:55:54 Accepted 2593 C++ 00:00.69 908K ���͵����� 

// Ģ��Ģ���⣬����Ӣ���Ķ��������֮�����ȽϷ�����ֱ�� OOP �����

// ��������������ʱ�䣬�����ܵ��Ż��������������ʱ�򣬲�Ҫ��שͷ
// ����ģ�ϸ�ľ��ǣ�������һ���Ѷȣ���ıȽ�Ģ�� 

#include <string>
#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>  
using namespace std;

struct Match {
    int     pos,  prob,  penalty;
    int     A[26];
    bool    B[26];
    void reset( int p ) {
        pos = p;
        memset( A, 0, sizeof( A ) ); 
        memset( B, 0, sizeof( B ) ); 
    }
};

inline bool mcmp( Match* m1, Match* m2 ) {
    return  m1 -> prob >  m2 -> prob ||
            m1 -> prob == m2 -> prob && 
            m1 -> penalty < m2 -> penalty; 
} 

struct Team {
    string  name; 
    double  C,  S,  M;
};

inline bool tcmp( Team* t1, Team* t2 ) {
    return  t1 -> M > t2 -> M; 
} 

int main() {

    int     T; 
    char    spc[10];

    Team    teams[101];
    Team*   p_teams[101]; 
    Match   submit[101];
    Match*  p_submit[101];
    map<int, int>   MP;
    
    for( scanf( "%d", &T ); T--; ) {

        // ¼������ʼ��Ϣ 
        int     N;
        scanf( "%d", &N );
        
        // �Ե� N ����Ŀո�ͻس�
        gets( spc );
        
        int     max_len = 0; 
        for( int i = 1; i <= N; ++i ) {
            getline( cin, teams[i].name );
            if( teams[i].name.size() > max_len )
                max_len = teams[i].name.size();
            teams[i].C = teams[i].S = 0.0; 
        }
        
        // ������������ 
        for( int i = 1; i <= N; ++i )
            teams[i].name += string( max_len - teams[i].name.size(), ' ' ); 

        // ��ȡ���б�����Ϣ 
        int     M;
        for( scanf( "%d", &M ); M--; ) {
            
            int     K;
            cin >> K;   // K Ϊ�ܶ��� 
            double  B = K - 2,  A = K + B; 
            
            // ��ò����ӵ���Ϣ 
            MP.clear();
            for( int i = 1; i <= K; ++i ) {
                int x;  scanf( "%d", &x );
                MP[x] = i;
                submit[i].reset( x ); 
            }
            int P;      // P Ϊ������ 
            cin >> P;
            
            // ��ȡһ����������Ϣ 
            int L;
            for( scanf( "%d", &L ); L--; ) {
                char    c[2],   p[2];
                int     x,      t;
                scanf( "%d%s%d%s", &t, p, &x, c );
                t = MP[t];
                if( submit[t].B[*p - 'A'] ) continue;
                if( *c == '-' )
                    submit[t].A[*p - 'A'] += 20;
                else {
                    submit[t].A[*p - 'A'] += x;
                    submit[t].B[*p - 'A'] = true; 
                } 
            }
            
            // ͳ�Ʊ�����Ϣ 
            for( int i = 1; i <= K; ++i ) {
                submit[i].prob = 0;
                submit[i].penalty = 0;
                for( int j = 0; j < P; ++j ) {
                    if( submit[i].B[j] ) {
                        ++submit[i].prob;
                        submit[i].penalty += submit[i].A[j]; 
                    }
                }
            }
            
            // �Ա�����������
            for( int i = 1; i <= K; ++i )
                p_submit[i] = submit + i; 
            sort( p_submit + 1, p_submit + 1 + K, mcmp ); 

            // �Ա������еǼ�
            int PM = p_submit[1] -> prob;
            double  y = 1.0;
            
            for( int i = 1; i <= K; ++i ) {
                
                // ���ǲ��е������y Ϊ�������� 
                if( i > 1 && mcmp( p_submit[i-1], p_submit[i] ) )    y = i;
                double  RS = PM ? double( p_submit[i]->prob ) / double( PM ) : 0.0;

                // �ö��鵵�����ܵ���ĵ���� 
                int index = p_submit[i] -> pos;
                teams[index].S += ( RS * A / ( B + y ) );
                teams[index].C += 1.0; 
                
            }
            
        } 
        
        // ��������ƽ���� 
        for( int i = 1; i <= N; ++i ) {
            if( teams[i].C < 1e-5 )
                    teams[i].M = 0.0;
            else    teams[i].M = teams[i].S / teams[i].C; 
        }
        
        // ��ƽ��������
        for( int i = 1; i <= N; ++i )
            p_teams[i] = teams + i; 
        sort( p_teams + 1, p_teams + 1 + N, tcmp );
        
        // ���
        cout.setf( ios::fixed );
        cout.precision( 4 );
        for( int i = 1; i <= N; ++i )
            cout << p_teams[i] -> name << ' ' << p_teams[i] -> M << endl;

        if( T ) cout << endl;
        
    }
    
} 
