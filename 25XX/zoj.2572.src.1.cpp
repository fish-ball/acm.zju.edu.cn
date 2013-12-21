// 2959007 2008-06-30 23:12:00 Accepted 2572 C++ 00:00.21 1412K ���͵����� 

// С��̬��ģ���⣬������һ�� DFS������� DFS �����ˣ���������ˣ�ûɶ�ѵ�

// ע�����������ʽ�Լ� PE �����⣬����ע�ͱ��ˣ��������� PE 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool    visited[100][100];
bool    agree[128][128];
int     color[100][100];
int     N,  M,  Q,  X,  Y,  C;
vector<string>  V;

const int D[8][2] = {
    { -1, 0 },
    { 1, 0 },
    { 0, 1 },
    { 0, -1 },
    { -1, 1 },
    { 1, -1 },
    { 1, 1 },
    { -1, -1 }
};

const char* T = "||--//\\\\";

inline bool isValid( int x, int y ) {
    return  x >= 0 && x < N &&
            y >= 0 && y < V[x].size();
}

void paint( int x, int y, const int& c, char type ) {

    if( !agree[type][V[x][y]] ) return;

    visited[x][y] = true;

    color[x][y] = c;
    
    int i,  j;
    
    switch( V[x][y] ) {
        case '|':   i = 0;  j = 1;  break;
        case '-':   i = 2;  j = 3;  break;
        case '/':   i = 4;  j = 5;  break;
        case '\\':  i = 6;  j = 7;  break;
        case '+':   i = 0;  j = 3;  break;
        case 'X':   i = 4;  j = 7;  break;
        case '*':   i = 0;  j = 7;  break;
    }
    
    while( i <= j ) {
        int dx = x + D[i][0],
            dy = y + D[i][1];
        if( isValid( dx, dy ) && !visited[dx][dy] )
            paint( dx, dy, c, T[i] );
        ++i;
    }
    
}

void draw() {
    
    string  temp;
    int     clr;
    
    for( int i = 0; i < V.size(); ++i ) {
        
        temp.erase();
        clr = -1;
        for( int j = 0; j < V[i].size(); ++j ) {
            if( color[i][j] == clr )
                temp += V[i][j];
            else {
                if( clr == -1 )
                    cout << temp;
                else
                    cout << "[m" << clr << temp << "m]";
                clr = color[i][j];
                temp.erase();
                temp += V[i][j];
            }
        }
        if( clr == -1 )
            cout << temp;
        else
            cout << "[m" << clr << temp << "m]";
        cout << endl;
    }
    
//    cout << endl;
    
}

int main() {

    memset( agree, 0, sizeof( agree ) );
    agree['-']['-'] = agree['-']['+'] = agree['-']['*'] =
    agree['|']['|'] = agree['|']['+'] = agree['|']['*'] =
    agree['\\']['\\'] = agree['\\']['X'] = agree['\\']['*'] =
    agree['/']['/'] = agree['/']['X'] = agree['/']['*'] =
    agree['+']['+'] = agree['+']['-'] = agree['+']['|'] = agree['+']['*'] =
    agree['X']['X'] = agree['X']['/'] = agree['X']['\\'] = agree['X']['*'] =
    agree['*']['*'] = agree['*']['+'] = agree['*']['X'] =
    agree['*']['-'] = agree['*']['|'] = agree['*']['/'] =
    agree['*']['\\'] = true;
    

    while( cin >> N >> M ) {
        
        V.resize( N );
        getline( cin, V[0] );
        
        for( int i = 0; i < N; ++i ) {
            getline( cin, V[i] );
// �ҿ�������ط�������ԭ���ͺã���ͼ�Ķ��κ��йؿո����Ϊֻ�ᵼ���޾��� PE 
//            V[i].erase( V[i].find_last_not_of( ' ' ) + 1 );
        }
        
        // You can assume that no character will be colored twice.
        // ˵����ÿ����������Ϳɫһ�Σ�����ֻ��ʼ��һ�η��ʱ�Ǽ��� 
        memset( color, -1, sizeof( color ) );
        memset( visited, 0, sizeof( visited ) );
        
        for( cin >> Q; Q--; ) {
            cin >> X >> Y >> C;
            if( isValid( X, Y ) )
                paint( X, Y, C, V[X][Y] );
        }
        
        draw();
        
    }

}


