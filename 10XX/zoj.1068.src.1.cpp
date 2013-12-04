// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: P,MTHBGWB(PROBLEM_B)

// Refactored on 2008-5-21

#include <iostream>
#include <string>
using namespace std;

// ����� 
string code[]={ ".-",   "-...", "-.-.", "-..",  ".",
                "..-.", "--.",  "....", "..",   ".---",
                "-.-",  ".-..", "--",   "-.",   "---",
                ".--.", "--.-", ".-.",  "...",  "-",
                "..-",  "...-", ".--",  "-..-", "-.--",
                "--..", "..--", "---.", ".-.-", "----" };

// ԭ�ַ��� 
char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.,?";

// ����γ��ȱ� 
int list[]={ 2, 4, 4, 3, 1,
             4, 3, 4, 2, 4,
             3, 4, 2, 2, 3,
             4, 4, 3, 3, 1,
             3, 4, 3, 4, 4,
             4, 4, 4, 4, 4 };

// �������鷴ת 
void reverse( int* segment, int len ) {
    int     a[100];
    for( int i = 0; i < len; i++ ) a[len - 1 - i] = segment[i];
    for( int i = 0; i < len; i++ ) segment[i] = a[i]; 
}

// ԭ�ַ�����������봮 
string encrypt( const string& a ) {

    string  s( "" );

    for( int j = 0; j < a.length(); j++ ) {

        for( int i = 0; i < 30; i++ ) {

            if( letter[i]==a[j] ) {
                s += code[i];
                break;
            }

        }

    }
    
    return s;

}

// ԭ�ַ�����������ֶα� 
void seg( string a, int b[] ) {
    
    for( int j = 0; j < a.length(); j++ ) {
    
        for( int i = 0; i < 30; i++ ) {
    
            if( letter[i] == a[j] ) {
                b[j] = list[i];
                break;
            }
    
        }
    
    }
    
}

// �����봮ǰ����ȡn���ַ� 
string cut( string &a, int n ) {
    
    string  b = a.substr( 0, n );
    
    a.erase( 0, n );
    
    return b;

}

// �������뷭�� 
char reset(string a) {
    
    for( int i = 0; i < 30; i++ )
    
        if( a == code[i] )
    
            return letter[i];

}

// �����봮�ͷֶα�ԭԭ�ַ��� 
string recover( int b[], string &code, int n ) {
    
    string  a( "" );
    
    for( int i = 0; i < n; i++ )
    
        a += reset( cut( code, b[i] ) );
    
    return a;

}

int main() {
    
    string  buf,    code,   text;
    
    int line,   b[100];
    
    cin >> line;
    
    for( int i = 1; i <= line; ++i ) {
    
        cin >> buf;

        code = encrypt( buf );

        seg( buf, b );

        reverse( b, buf.length() );
        
        text = recover( b, code, buf.length() );

        cout << i << ": " << text << endl;

    }

}
