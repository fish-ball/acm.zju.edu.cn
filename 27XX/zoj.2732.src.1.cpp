// 2957043 2008-06-27 01:04:07 Accepted 2732 C++ 00:00.12 972K ���͵����� 

// Խ��Խ����ģ���� = Ӣ���Ķ���
// Ϊ�˶�������⣬���˺ܶ��ʱ�䣬������Ҫ��ķ��� 

// ��һϵ�е��ʼ�������Ӧ���� N ���ʼ����ɵ�һ������
// �ʼ�����������Ϣ�������� poster���ʼ��� title
// ���У��ʼ�������������ǰ׺��"Re:" �� "O:"
//     ͨ��ȫ�ĺ󣬷������û�� 

// ������һϵ���ʼ������з����ˣ�������һ����ʼ�ķ��� 50
// ����Ҫ�����ֲ�����
// 1. ���뷢��������������������з�����
//    ��������˲����ڣ���� not exist
// 2. ����һ���ļ���ţ���ͷ��ʼ�� i ������ 1 ��ʼ�� 
//    ��һ�� b ������b �����������£�
//      1> ��һ���ַ�Ϊ b û��
//      2> �ڶ����ַ�Ϊ 1 �� 2: 
//         1 ��ʾ���������뵱ǰ��ŵ��ʼ�ͬ�ʼ�����;
//         2 ��ʾ���������뵱ǰ��ŵ��ʼ�ͬ�����˵�;
//      3> �������ַ�Ϊ 1 �� 6:
//         1 ɾ���������õ��ʼ���ÿ���ʼ��ķ����˿� 1 ��
//         6 ɾ���������õ��ʼ��������˿� 2 ��
//      4> �������ַ�Ϊ y �� n:
//         y ��ʾ�������ͷ��ʼ;
//         n ��ʾ������ӵ�ǰ�ʼ���ʼ;
//    ����ļ����̫����� 0
//    ���򣬴�������ɾ�����ļ�����

// ������ͺ������ˣ��ø�������������

// ע����� PE �����ģ������� PE!!
// д������!! ��ʵ���ǣ�ÿ������(����ÿ����ѯ)�����һ������ 
// Print a blank after each test case.


#include <list>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// RE �ˣ������� 

int     N;

typedef pair<string, string>    Mail;

list<Mail>  L;
list<Mail>::iterator        l_iter;
map<string, int>    M;
map<string, int>::iterator  m_iter;

int main() {
    
    while( cin >> N && N ) {
    
        string  S;
        getline( cin, S );
        
        M.clear();
        L.clear();
        
        while( N-- ) {
            
            getline( cin, S );
            
            int pos = S.find( ' ' );
            M[S.substr( 0, pos )] = 50;
            if( S[14] == 'O' )
                L.push_back( make_pair( S.substr( 0, pos ),
                                        S.substr( 16 ) ) );
            else
                L.push_back( make_pair( S.substr( 0, pos ),
                                        S.substr( 18 ) ) );
        }
        
        for( cin >> N >> ws; N--; ) {
            
            getline( cin, S );
            
            int pos = S.find( ' ' );
            
            if( pos == string::npos ) {
                m_iter = M.find( S );
                if( m_iter == M.end() )
                    cout << "not exist" << endl;
                else
                    cout << m_iter -> second << endl;
            }
            
            else {
                int x = atoi( S.c_str() );
                if( x > L.size() ) {
                    cout << 0 << endl; 
                    continue;
                }
                
                for( l_iter = L.begin(); --x; )
                    ++l_iter;
                    
                string  poster = l_iter -> first;
                string  title = l_iter -> second;
                int proc = 0;
                S.erase( 0, pos + 1 );
                if( S[3] == 'y' )
                    l_iter = L.begin();
                if( S[1] == '2' ) {
                    while( l_iter != L.end() ) {
                        if( l_iter -> first == poster ) {
                            if( S[2] == '1' )
                                M[l_iter -> first] -= 1;
                            else
                                M[l_iter -> first] -= 2;
                            l_iter = L.erase( l_iter );
                            ++proc;
                        }
                        else    ++l_iter;
                    }
                }

                else {
                    while( l_iter != L.end() ) {
                        if( l_iter -> second == title ) {
                            ++proc;
                            if( S[2] == '1' )
                                M[l_iter -> first] -= 1;
                            else
                                M[l_iter -> first] -= 2;
                            l_iter = L.erase( l_iter );
                        }
                        else    ++l_iter;
                    }
                }
                
                cout << proc << endl;

            }
            
        }
        
        cout << endl; 
    
    }
    
} 
