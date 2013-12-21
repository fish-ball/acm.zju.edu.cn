// 1687791 2008-11-03 18:49:44 Accepted  2612 C++ 50 380 ���͵����� 

// һ��ͼ������ѧ�ۺϵ���Ŀ���ȽϷ�����������ⱨ�档 

//////////////////////////////////////////////////////////
//               ������ģ�壨ֻ֧��������v1.0           //
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



//����ͼǿ��ͨ��֧,bfs�ڽ�����ʽ,O(n^2)
//���ط�֧��,id����1..��֧����ֵ
//����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩ0
#define MAXN 100

int find_components(int n,int mat[][MAXN],int* id){
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN],i,j,k,t;
	for (k=0;k<n;id[k++]=0);
	for (k=0;k<n;k++)
		if (!id[k]){
			for (i=0;i<n;i++)
				a[i]=b[i]=c[i]=d[i]=0;
			a[k]=b[k]=1;
			for (t=1;t;)
				for (t=i=0;i<n;i++){
					if (a[i]&&!c[i])
						for (c[i]=t=1,j=0;j<n;j++)
							if (mat[i][j]&&!a[j])
								a[j]=1;
					if (b[i]&&!d[i])
						for (d[i]=t=1,j=0;j<n;j++)
							if (mat[j][i]&&!b[j])
								b[j]=1;
				}
			for (ret++,i=0;i<n;i++)
				if (a[i]&b[i])
					id[i]=ret;
		}
	return ret;
}


#include <iostream>
#include <vector>
using namespace std;

// ����ʽ 
int P, p[101], Q, q[101], R; 

// ����ʽ��ֵ 
int eval(int Z, int *z, int x) {
    int ans = 0;
    for(int i = 0; i <= Z; ++i) {
        ans *= x;
        ans += z[i];
        ans %= R;
    }
    return ans;
}


// ԭͼ��������ű������������� DAG 
int pg[MAXN][MAXN], pid[MAXN], np, pdg[MAXN][MAXN];
int qg[MAXN][MAXN], qid[MAXN], nq, qdg[MAXN][MAXN];

// ����ͼ 
int GSZ;
bool G[200][200], B[200];

void dfs(int v) {
    B[v] = true;
    for(int i = 0; i < GSZ; ++i)
        if(!B[i] && G[v][i])
            dfs(i);
}


int main() {

    while(cin >> R && R) {

        // �������ʽ 
        cin >> P;
        for(int i = 0; i <= P; ++i)
            cin >> p[i];

        cin >> Q;
        for(int i = 0; i <= Q; ++i)
            cin >> q[i];

        // ���ǿ��ͨ������������� DAG 
        memset(pg, 0, sizeof(pg));
        for(int i = 0; i < R; ++i)
            pg[i][eval(P, p, i)] = 1;
        memset(pid, 0, sizeof(pid));
        np = find_components(R, pg, pid);
        for(int i = 0; i < R; ++i)
            pid[i] -= 1;

        memset(pdg, 0, sizeof(pdg));
        for(int i = 0; i < R; ++i)
            pdg[pid[i]][pid[eval(P, p, i)]] = 1;

        memset(qg, 0, sizeof(qg));
        for(int i = 0; i < R; ++i)
            qg[i][eval(Q, q, i)] = 1;
        memset(qid, 0, sizeof(qid));
        nq = find_components(R, qg, qid);
        for(int i = 0; i < R; ++i)
            qid[i] -= 1;

        memset(qdg, 0, sizeof(qdg));
        for(int i = 0; i < R; ++i)
            qdg[qid[i]][qid[eval(Q, q, i)]] = 1;

        // ���콻��ͼ 
        memset(G, 0, sizeof(G));
        GSZ = np + nq;
        for(int i = 0, x, y; i < R; ++i) {
            x = pid[i];
            y = qid[i] + np;
            G[x][y] = G[y][x] = true;
        }
                
        // �޳������ܵ�
        memset(B, 0, sizeof(B));
        
        for(int i = 0; i < np; ++i) {
            bool yes = false;
            for(int j = 0; j < np; ++j) {
                if(j != i && pdg[i][j]) {
                    yes = true;
                    break;
                }
            }
            if(yes && !B[i])
                dfs(i);
        }
        
        for(int i = 0; i < nq; ++i) {
            bool yes = false;
            for(int j = 0; j < nq; ++j) {
                if(j != i && qdg[i][j]) {
                    yes = true;
                    break;
                }
            }
            if(yes && !B[np+i])
                dfs(np+i);
        }

        // ����ʣ�������
        int C = 0;
        for(int i = 0; i < GSZ; ++i) {
            if(!B[i]) {
                ++C;
                dfs(i);
            }
        } 
        
        BigNum ans = 1;
        while(C--) ans = ans + ans;
        cout << ans << endl;

    }
}
