// 2941281 2008-06-04 00:00:18 Accepted 1387 C++ 00:00.95 2188K ���͵����� 

// DP, DP[i] Ϊ Morse ��ǰ׺ i ����ƥ����
// ����һ������¼һ������ Morse ���ۼƵĸ��� M[word]
// ���ɨ�裬��ֵ DP[0] = 1
// �������� DP[i] = 0������
// ������� 0 ���������п�ƥ��ǰ׺�������ݳ˷�ԭ��
// ��������Ҫ���ǰ׺Ϊ word
// DP[i + len(word)] += DP[i] * M[word]
// ���ս��Ϊ DP[len(all)], all Ϊȫ Morse �봮 

#include <iostream>
#include <string>
#include <map>
using namespace std;

const char* Morse[] = {
    ".-",   "-...", "-.-.", "-..",
    ".",    "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..",
    "--",   "-.",   "---",  ".--.",
    "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-",
    "-.--", "--.."
};

string toCode( const string& word ) {
    string  ans( "" );
    for( int i = 0; i < word.size(); ++i )
        ans += Morse[word[i]-'A']; 
    return  ans;
}

int main() {
    
    string  code,   input;
    
    map<string, int>    M;
    
    int DP[10001],  T,  N,  L,  W;
    
    for( cin >> T; T--; ) {
        
        cin >> code;
        L = code.size();
        
        M.clear();
        fill( DP, DP + L + 1, 0 );
        DP[0] = 1;
        
        for( cin >> W; W--; ) {
            cin >> input;
            ++M[toCode( input )];
        }
        
        map<string, int>::iterator  iter;
        
        for( int i = 0; i < L; ++i ) {
            if( DP[i] ) {
                string  temp = code.substr( i );
                iter = M.upper_bound( temp );
                if( iter != M.begin() )
                while( 1 ) {
                    --iter;
                    if( temp.find( iter -> first ) == 0 ) {
                        DP[i+iter->first.size()] += 
                            DP[i] * iter->second;
                    }
                    if( iter == M.begin() ||
                        iter -> first[0] != temp[0] )
                        break;
                }
            }
        }
        
        cout << DP[L] << endl;
        
    }
    
    
}
