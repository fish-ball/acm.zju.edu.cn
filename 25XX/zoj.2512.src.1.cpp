// 2893096 2008-05-06 14:47:03 Accepted 2512 C++ 00:00.01 872K ���͵����� 

// �ַ�������δ��ѭ��Ѱַ�����Ŀ��������ַ����Լ��������ݣ����� 
// rrb -> rrbrrbrrb
//           ^^
// Ȼ��ӵڶ�������ʼ���������������� L/2 �����б�ɹ�������
// �����Ĵ������˱����Ѷ� 

#include <iostream>
#include <string>
using namespace std;

string  proc;
int     L;

bool check1( const int& k ) {
    for( int i = 1; i <= L / 2; ++i )
        if( proc[k + i] != proc[k - i] )
            return  false;
    return  true;
}

bool check2( const int& k ) {
    for( int i = 0; i < L / 2; ++i )
        if( proc[k - i] != proc[k + 1 + i] )
            return  false;
    return  true;
}

int main() {

    string  input;

    while( cin >> input ) {

        L = input.size();

        proc = input + input + input;
        
        int pos,    symmetry = 0;
        for( pos = 0; pos <= L / 2; ++pos ) {
            if( check1( L + pos ) ) {
                symmetry = 1;
                break;
            }
            if( check2( L + pos ) ) {
                symmetry = 2;
                break;
            }
        }

        if( !symmetry )
            puts( "Not symmetric" );
        else {
            puts( "Symmetric" );
            if( symmetry == 1 )
                cout << pos + 1 << endl;
            else
                cout << pos + 1 << '-' << pos + 2 << endl;
        }

    }
    
}
