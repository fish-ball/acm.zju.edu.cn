// 1773629 2009-03-01 15:19:25 Accepted  3167 C++ 100 184 呆滞的慢板

// 求最小的 n，使得 M^n 的第 K 位是 7，M, K 1000 以内结果保证在 100 以内，
// 直接大数乘法模拟，不过要加入一个操作，就是求大数第 K 位是什么。

//////////////////////////////////////////////////////////
//               大整数模板（只支持正数）v1.0           //
//////////////////////////////////////////////////////////

#ifndef BIG_NUM_XPER
#define BIG_NUM_XPER

#include <iostream>
#include <string>
#include <algorithm>
 
const std::size_t BSZ = 1000; 

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
    ////////////////////////////////////////
    int getDigit(int n) {
        int k = n / 4, i = n % 4;
        int pos = 1;
        while(i--) pos *= 10;
        return s[k + 1] / pos % 10;
    }
    ////////////////////////////////////////
    
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
//           以上实现所有 输入输出 比较 功能            //
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

// 作为更高安全度的开发，此处应该增加一个异常，如果 a<b，向外抛出异常 
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
//              以上实现所有 加 减 乘 功能              //
//////////////////////////////////////////////////////////

// 此处应添加除零异常
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
//        以上为大数 除 模 普通整数功能，相对高效       //
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

// 此处应添加除零异常
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
//  以上为大数 除 模 大数功能，相当低效，尽量避免使用   //
//////////////////////////////////////////////////////////

#endif  // BIG_NUM_XPER

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

int main() {
    int K, M;
    BigNum xx;
    while(cin >> K >> M) {
        int ans = 1;
        xx = M;
        while(xx.getDigit(K - 1) != 7) {
            ++ans;
            xx = xx * M;
        }
        cout << ans << endl;
    }
}
