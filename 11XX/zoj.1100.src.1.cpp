// 1693679 2008-11-08 22:01:27 Accepted  1100 C++ 840 13384 ���͵����� 

// ���䣬״̬ѹ�� DP��DP[i][j][k] ��ʾ i �㣬j ĩ״̬��
// ���㻹���� k λ֮��ӵķ�������ע��ö�ٵĴ��򣬴� 1 λ�ٵĵ���ġ� 

//////////////////////////////////////////////////////////
//               ������ģ�壨ֻ֧��������v1.0           //
//////////////////////////////////////////////////////////

#ifndef BIG_NUM_XPER
#define BIG_NUM_XPER

#include <iostream>
#include <string>
#include <algorithm>
 
const std::size_t BSZ = 10; 

struct BigNum {
    int s[BSZ];
    BigNum(int x = 0);
    int& operator[](int p) { return s[p]; }
    const int& operator[](int p) const { return s[p]; }
    void put() {
        printf("%d", s[s[0]]);
        for(int i = s[0] - 1; i; i--)
            printf("%04d", s[i]);
    }
}; 

BigNum::BigNum(int x) {
    memset(s, 0, sizeof(s));
    for(s[0] = 1; x > 0; s[0]++) {
        s[s[0]] = x % 10000;
        x /= 10000;
    }
    while(!s[s[0]] && s[0] > 1) s[0]--;
}

std::istream& operator>>(std::istream& is, BigNum& x) {
    char    buf[4*BSZ+1];
    int     i,  j,  len;
    memset(x.s, 0, sizeof(x.s));
    is >> buf;
    x[0] = strlen(buf); 
    std::reverse(buf, buf + x[0]);
    len = x[0] = (x[0] + 3) / 4;
    for(j = strlen(buf); j < x[0] * 4; buf[j++] = '0');
    for(i = 1; i <= len; i++)
        for(x.s[i] = 0, j = 0; j < 4; j++)
            x[i] = x[i] * 10 + buf[i*4-1-j] - '0';
    while(!x[x[0]] && x[0] > 1) x[0]--;
    return  is;
}

std::ostream& operator<<(std::ostream& os, const BigNum& x) {
    os << x[x[0]];
    for(int i = x[0] - 1; i; i--)
        for(int j = 1000; j; j /= 10)
            os << x[i] / j % 10;
    return  os;
}

int comp(const BigNum& a, const BigNum& b){
    int i;
    if(a[0] != b[0]) return a[0] - b[0];
    for(i = a[0]; i; i--)
        if(a[i] != b[i])
            return  a[i] - b[i];
    return 0;
}

bool operator==(const BigNum& a, const BigNum& b) { return comp(a, b)==0; }
bool operator!=(const BigNum& a, const BigNum& b) { return comp(a, b)!=0; }
bool operator< (const BigNum& a, const BigNum& b) { return comp(a, b)< 0; }
bool operator<=(const BigNum& a, const BigNum& b) { return comp(a, b)<=0; }
bool operator> (const BigNum& a, const BigNum& b) { return comp(a, b)> 0; }
bool operator>=(const BigNum& a, const BigNum& b) { return comp(a, b)>=0; }

//////////////////////////////////////////////////////////
//           ����ʵ������ ������� �Ƚ� ����            //
//////////////////////////////////////////////////////////

const BigNum operator+(const BigNum& a, const BigNum& b) {
    BigNum  c;  int i;
    for(i = 1; i <= b[0] || i <= a[0]; i++) {
        if((c[i] += a[i] + b[i]) >= 10000) {
            c[i] -= 10000;
            c[i+1] = 1;
        }
    }
    c[0] = i;
    if(c[0] > 1 && !c[c[0]]) c[0] -= 1;
    return  c;
}

// ��Ϊ���߰�ȫ�ȵĿ������˴�Ӧ������һ���쳣����� a<b�������׳��쳣 
const BigNum operator-(const BigNum& a, const BigNum& b) {
    BigNum  c;  int i;
    for(i = 1; i <= b[0] || i <= a[0]; i++) {
        if((c[i] += a[i] - b[i]) < 0) {
            c[i] +=10000;
            c[i+1] = -1;
        }
    }
    c[0] = i;
    while(c[0] > 1 && !c[c[0]]) c[0] -= 1;
    return  c;
}

const BigNum operator*(const BigNum& a, const BigNum& b) {
    BigNum  c;
    c[0] = a[0] + b[0];
    for(int i = 1; i <= a[0]; i++) {
        for(int j = 1; j <= b[0]; j++) {
            if((c[i+j-1] += a[i] * b[j]) >= 10000) {
                c[i+j] += c[i+j-1] / 10000;
                c[i+j-1] %= 10000;
            }
        }
    }
    while(!c[c[0]] && c[0] > 1) c[0]--;
    return  c;
}

//////////////////////////////////////////////////////////
//              ����ʵ������ �� �� �� ����              //
//////////////////////////////////////////////////////////

// �˴�Ӧ��ӳ����쳣
void div(BigNum& a, int b, int& c) {
    for(int i = a[0]; i; i--) {
        c = c * 10000 + a[i];
        a[i] = c / b;
        c %= b;
    }
    while(!a[a[0]] && a[0]>1) a[0]--;
}

const BigNum operator/(BigNum a, int b) { int c = 0; div(a, b, c); return  a; }
int operator%(BigNum a, int b) { int c = 0; div(a, b, c); return  c; }

//////////////////////////////////////////////////////////
//        ����Ϊ���� �� ģ ��ͨ�������ܣ���Ը�Ч       //
//////////////////////////////////////////////////////////

int comp(const BigNum& a, int c, int d, const BigNum& b){
    int i,  t = 0,  Z = -20000;
    if(b[0] - a[0] < d && c) return 1;
    for(i =b[0];i>d;i--){
        t = t * 10000 + a[i-d] * c - b[i];
        if(t > 0) return 1;
        if(t < Z) return 0;
    }
    for(i = d; i; i--){
        t = t * 10000 - b[i];
        if (t > 0) return 1;
        if (t < Z) return 0;
    }
    return  t > 0;
}

void sub(BigNum& a, const BigNum& b, int c, int d){
    int i,  Z = b[0]+d;
    for(i = 1 + d; i <= Z; i++) {
        if((a[i] -= b[i-d] * c)<0) {
            a[i+1] += (a[i]-9999) / 10000;
            a[i] -= (a[i]-9999) / 10000 * 10000;
        }
    }
    for(; a[i]<0; i++) {
        a[i+1] += (a[i]-9999) / 10000;
        a[i] -= (a[i]-9999)/10000*10000;
    }
    while(!a[a[0]] && a[0] > 1) a[0]--;
}

// �˴�Ӧ��ӳ����쳣
void div(BigNum& a, const BigNum& b, BigNum& c) {
    int h,  l,  m,  i; 
    c[0] = (b[0]<a[0]+1) ? (a[0]-b[0]+2) : 1;
    for(i = c[0]; i; sub(a, b, c[i]=m, i-1), i-- ) {
        for(h=9999, l=0, m=h+l+1>>1; h>l; m=h+l+1>>1 )
            if(comp(b, m, i-1, a))  h = m - 1;
            else    l = m;
    } 
    while(!c[c[0]] && c[0] > 1) c[0]--;
    c[0] = c[0] > 1 ? c[0] : 1;
}

const BigNum operator/(BigNum a, const BigNum& b) { BigNum c; div(a, b, c); return c; }
const BigNum operator%(BigNum a, const BigNum& b) { BigNum c; div(a, b, c); return a; }

//////////////////////////////////////////////////////////
//  ����Ϊ���� �� ģ �������ܣ��൱��Ч����������ʹ��   //
//////////////////////////////////////////////////////////

#endif  // BIG_NUM_XPER

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <algorithm>
using namespace std;

BigNum DP[15][1<<11][11];

bool B[11];

int M, N, MASK;

int main() {
    while(cin >> M >> N && M) {
        if(M < N) swap(M, N);
        if(M % 2 && N % 2) {puts("0"); continue;}
        memset(DP, 0, sizeof(DP));
        DP[0][0][0] = 1;
        MASK = (1<<N) - 1;
        for(int i = 0; i <= M; ++i) {
            for(int n = 0, b; n <= N; ++n) {
                memset(B, 0, sizeof(B));
                for(int j = 0; j < n; ++j)
                    B[j] = true;
                do {
                    b = 0;
                    for(int j = 0; j < N; ++j)
                        if(B[j])
                            b |= (1<<j);
                    for(int v = 0; v <= N; ++v) {
                        if(DP[i][b][v] == 0) continue;
                        DP[i+1][(~b)&MASK][0] = DP[i+1][(~b)&MASK][0] + DP[i][b][v];
                        for(int p = v; p+1 < N; ++p)
                            if(((3<<p)&b) == 0)
                                DP[i][(3<<p)|b][p+2] = DP[i][(3<<p)|b][p+2] + DP[i][b][v];
                    }
                } while(prev_permutation(B, B + N));
            }
        }
        cout << DP[M][0][0] << endl;
    }
}
