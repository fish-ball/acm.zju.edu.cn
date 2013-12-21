// 2982060 2008-07-16 10:52:36 Accepted 2699 C++ 00:01.12 4948K ���͵����� 

// ����������
// ��һ��ͼ��N �������� M �����������
//   ����Ҫ��ͼ�ϵ� K ����������ǣ�ʹ�ã�
//   1. ͼ�����еĶ��㣬������·������ͨ��һ����ǵĶ��㣻
//   2. ͼ�����еĶ��㣬�����Դ�ĳ����ǵĶ���ﵽ��
// �������ı�Ƿ������ж����֣� 

// ���
//   1. ���ǣ�����������ͼ���Ѿ���ĳЩ������б�ǣ���ô
//      ����ĳ�����㣬�����������������ģ��Ƹö��㱻���ǣ�
//   2. ǿ������һ������ͼ�е�ĳЩ�����Ӽ��������������ǵıߣ���
//      ��� 1) ���ڴ���ͼ���������㣬�����໥�����·����
//           2) ��ͼ�м�������һ������֮�����ͼ������ 1) ���ʣ�
//      ��ô�ƴ���ͼΪǿ������
//   3. ���� DAG��һ������ͼ���Էֽ�����ɸ�ǿ��������ô������
//      �ɴ��Ե�ʱ�򣬿��Խ���Щǿ������Ч��һ�����㣬ǿ����֮��
//      ������·�������Ч��һ������ߣ���ô��Ч������ͼ��һ�� DAG�� 
//      ��Ϊ��ͼ�ĺ��� DAG�� 

// ����һ������ͼ�Ŀɴ����Լ������ѧ�����⣺
// �������������ʵ��
//   1. ����ͼ���� N* ��ǿ��������ô��ÿ��ǿ�����б��һ�����㣬
//      �����Ը������е�ǿ�����еĶ��㡣
//   2. ��������һ�� DAG�������ж��㱻���ǵĳ�Ҫ�����ǣ�
//      ��������Դ��ͻ�㶼����ǡ�
//   3. ���ۣ���������һ������ͼ��Ҫ�������еĶ��㣬��Ҫ�����ǣ�
//      �����ں��� DAG �д���Դ��ͻ���ǿ�����У�������һ��
//      ���㱻��ǡ�

// Ѱ��һ������ͼ��ǿ�����ͺ��� DAG ����������ʱ���ڴﵽ����ô
// ����ת�������������ѧ�����⣺
//   1. �Ѿ��ҳ��� W ��Դ�����ǿ���� Ti(1=1..W)��
//   2. ÿ��������ǿ���������� U[i] �����㣬������һ���� U �����㣻
//   3. ������Щ��������Ļ��� V �����㣻 
//   3. ����������һ�� U[i] ����ȡ C ��������ϣ�ÿ�� U[i] 
//      ����ȡһ����for(W<=C<=K)������ X(C)��ϣ�
//   4. ʣ�µĿɱ�Ƕ�����Ϊ U = K - C�������ඥ����ȡ���
//      Y(C) = comb(V,K-C)��
//   5. ���Ľ��Ӧ���ǣ�sigma(X(C)*Y(C)) (for(W<=C<=K)) 

// ��ôȥ������������⣬����Ӧ�� DP��
// ���� vector U, U[i]  ( 0 <= i < U.size() )
// ���Ҫ������� C �������������ٷ�һ��
// ���� DP ��DP[U.size()][K]
//   1. ��ֵ DP[0][j] = comb(U[0], j)
//   2. ���� DP[i][j] = sigma_t( DP[i-1][t] * comb(U[i], j-t)
//   3. Լ�� DP[i][j] = 0���� (j<=i) 
// ò����Щ���������쭵��ܴ����Ҫʹ�ô���ģ�� 

#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>
using namespace std;

#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

int read(bignum_t a,istream& is=cin){
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>buf))	return 0;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}

int comp(const bignum_t a,const bignum_t b){
	int i;
	if (a[0]!=b[0])
		return a[0]-b[0];
	for (i=a[0];i;i--)
		if (a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}

int comp(const bignum_t a,const int b){
	int c[12]={1};
	for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}

int comp(const bignum_t a,const int c,const int d,const bignum_t b){
	int i,t=0,O=-DEPTH*2;
	if (b[0]-a[0]<d&&c)
		return 1;
	for (i=b[0];i>d;i--){
		t=t*DEPTH+a[i-d]*c-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	for (i=d;i;i--){
		t=t*DEPTH-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	return t>0;
}

void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

void add(bignum_t a,const int b){
	int i=1;
	for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]-=b[i])<0)
			a[i+1]--,a[i]+=DEPTH;
	for (;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const int b){
	int i=1;
	for (a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const bignum_t b,const int c,const int d){
	int i,O=b[0]+d;
	for (i=1+d;i<=O;i++)
		if ((a[i]-=b[i-d]*c)<0)
			a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
	for (;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t c,const bignum_t a,const bignum_t b){
	int i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for (c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
			if ((c[i+j-1]+=a[i]*b[j])>=DEPTH)
				c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for (c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}

void mul(bignum_t a,const int b){
	int i;
	for (a[1]*=b,i=2;i<=a[0];i++){
		a[i]*=b;
		if (a[i-1]>=DEPTH)
			a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t b,const bignum_t a,const int c,const int d){
	int i;
	memset((void*)b,0,sizeof(bignum_t));
	for (b[0]=a[0]+d,i=d+1;i<=b[0];i++)
		if ((b[i]+=a[i-d]*c)>=DEPTH)
			b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH;
	for (;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for (;!b[b[0]]&&b[0]>1;b[0]--);
}

void div(bignum_t c,bignum_t a,const bignum_t b){
	int h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
	for (i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
		for (h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}

void div(bignum_t a,const int b,int& c){
	int i;
	for (c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sqrt(bignum_t b,bignum_t a){
	int h,l,m,i;
	memset((void*)b,0,sizeof(bignum_t));
	for (i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
		for (h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!b[b[0]]&&b[0]>1;b[0]--);
	for (i=1;i<=b[0];b[i++]>>=1);
}

int length(const bignum_t a){
	int t,ret;
	for (ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
	return ret>0?ret:1;
}

int digit(const bignum_t a,const int b){
	int i,ret;
	for (ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
	return ret%10;
}

int zeronum(const bignum_t a){
	int ret,t;
	for (ret=0;!a[ret+1];ret++);
	for (t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
	return ret;
}

void comp(int* a,const int l,const int h,const int d){
	int i,j,t;
	for (i=l;i<=h;i++)
		for (t=i,j=2;t>1;j++)
			while (!(t%j))
				a[j]+=d,t/=j;
}

void convert(int* a,const int h,bignum_t b){
	int i,j,t=1;
	memset(b,0,sizeof(bignum_t));
	for (b[0]=b[1]=1,i=2;i<=h;i++)
		if (a[i])
			for (j=a[i];j;t*=i,j--)
				if (t*i>DEPTH)
					mul(b,t),t=1;
	mul(b,t);
}

void combination(bignum_t a,int m,int n){
	int* t=new int[m+1];
	memset((void*)t,0,sizeof(int)*(m+1));
	comp(t,n+1,m,1);
	comp(t,2,m-n,-1);
	convert(t,m,a);
	delete []t;
}

void permutation(bignum_t a,int m,int n){
	int i,t=1;
	memset(a,0,sizeof(bignum_t));
	a[0]=a[1]=1;
	for (i=m-n+1;i<=m;t*=i++)
		if (t*i>DEPTH)
			mul(a,t),t=1;
	mul(a,t);
}

#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))

int read(bignum_t a,int &sgn,istream& is=cin){
	char str[MAX*DIGIT+2],ch,*buf;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>str)) return 0;
	buf=str,sgn=1;
	if (*buf=='-') sgn=-1,buf++;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	if (a[0]==1&&!a[1]) sgn=0;
	return 1;
}

struct bignum{
	bignum_t num;
	int sgn;
public:
inline bignum(int xx = 0){memset(num,0,sizeof(bignum_t));num[0]=1;num[1]=xx;sgn=0;}
inline int operator!(){return num[0]==1&&!num[1];}
inline bignum& operator=(const bignum& a){memcpy(num,a.num,sizeof(bignum_t));sgn=a.sgn;return *this;}
inline bignum& operator=(const int a){memset(num,0,sizeof(bignum_t));num[0]=1;sgn=SGN(a);add(num,sgn*a);return *this;};
inline bignum& operator+=(const bignum& a){if(sgn==a.sgn)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=a.sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn;return *this;}
inline bignum& operator+=(const int a){if(sgn*a>0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sgn=-sgn;sub(num,t);}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=SGN(a),add(num,ABS(a));return *this;}
inline bignum operator+(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum operator+(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum& operator-=(const bignum& a){if(sgn*a.sgn<0)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)add(num,a.num),sgn=-a.sgn;return *this;}
inline bignum& operator-=(const int a){if(sgn*a<0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=-SGN(a),add(num,ABS(a));return *this;}
inline bignum operator-(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum operator-(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum& operator*=(const bignum& a){bignum_t t;mul(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn*=a.sgn;return *this;}
inline bignum& operator*=(const int a){mul(num,ABS(a));sgn*=SGN(a);return *this;}
inline bignum operator*(const bignum& a){bignum ret;mul(ret.num,num,a.num);ret.sgn=sgn*a.sgn;return ret;}
inline bignum operator*(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));mul(ret.num,ABS(a));ret.sgn=sgn*SGN(a);return ret;}
inline bignum& operator/=(const bignum& a){bignum_t t;div(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn;return *this;}
inline bignum& operator/=(const int a){int t;div(num,ABS(a),t);sgn=(num[0]==1&&!num[1])?0:sgn*SGN(a);return *this;}
inline bignum operator/(const bignum& a){bignum ret;bignum_t t;memcpy(t,num,sizeof(bignum_t));div(ret.num,t,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn;return ret;}
inline bignum operator/(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);return ret;}
inline bignum& operator%=(const bignum& a){bignum_t t;div(t,num,a.num);if (num[0]==1&&!num[1])sgn=0;return *this;}
inline int operator%=(const int a){int t;div(num,ABS(a),t);memset(num,0,sizeof(bignum_t));num[0]=1;add(num,t);return t;}
inline bignum operator%(const bignum& a){bignum ret;bignum_t t;memcpy(ret.num,num,sizeof(bignum_t));div(t,ret.num,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn;return ret;}
inline int operator%(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);memset(ret.num,0,sizeof(bignum_t));ret.num[0]=1;add(ret.num,t);return t;}
inline bignum& operator++(){*this+=1;return *this;}
inline bignum& operator--(){*this-=1;return *this;};
inline int operator>(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);}
inline int operator>(const int a){return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);}
inline int operator>=(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);}
inline int operator>=(const int a){return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);}
inline int operator<(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);}
inline int operator<(const int a){return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);}
inline int operator<=(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);}
inline int operator<=(const int a){return sgn<0?(a<0?comp(num,-a)>=0:1):(sgn>0?(a>0?comp(num,a)<=0:0):a>=0);}
inline int operator==(const bignum& a){return (sgn==a.sgn)?!comp(num,a.num):0;}
inline int operator==(const int a){return (sgn*a>=0)?!comp(num,ABS(a)):0;}
inline int operator!=(const bignum& a){return (sgn==a.sgn)?comp(num,a.num):1;}
inline int operator!=(const int a){return (sgn*a>=0)?comp(num,ABS(a)):1;}
inline int operator[](const int a){return digit(num,a);}
friend inline istream& operator>>(istream& is,bignum& a){read(a.num,a.sgn,is);return is;}
friend inline ostream& operator<<(ostream& os,const bignum& a){if(a.sgn<0)os<<'-';write(a.num,os);return os;}
friend inline bignum sqrt(const bignum& a){bignum ret;bignum_t t;memcpy(t,a.num,sizeof(bignum_t));sqrt(ret.num,t);ret.sgn=ret.num[0]!=1||ret.num[1];return ret;}
friend inline bignum sqrt(const bignum& a,bignum& b){bignum ret;memcpy(b.num,a.num,sizeof(bignum_t));sqrt(ret.num,b.num);ret.sgn=ret.num[0]!=1||ret.num[1];b.sgn=b.num[0]!=1||ret.num[1];return ret;}
inline int length(){return ::length(num);}
inline int zeronum(){return ::zeronum(num);}
inline bignum C(const int m,const int n){combination(num,m,n);sgn=1;return *this;}
inline bignum P(const int m,const int n){permutation(num,m,n);sgn=1;return *this;}
};

typedef bignum BigNum;


int     N,  M,  K,  x,  y;

// ԭ����ͼ 
bool    G[101][101];

// ĳ������������ǿ�������Լ�ǿ�����ܸ��� 
int     id[101],    scnt;

// ���� DFS ������ͼ����������ͼ���� 
bool    rev;

// postI ��һ��ջ����¼�����ѵ����� 
vector<int> postI;

// ���� DAG ͼ 
bool    DAG[101][101]; 

// ����ǿ���������Ķ������
vector<int> allComponent;

// ���� DAG �ĳ���ȱ� 
int     dag_in[101],    dag_out[101]; 

// ��Ϊ���� DAG ��Դ�����ķ������Ծ��еĶ�����
vector<int> U,  U_acc;

// ����ϵĶ�̬�滮��
BigNum  DP[101][101]; 

// ������� 
BigNum comb( int n, int m ) {
    BigNum ret( 1 );
    m = m < ( n - m ) ? m : ( n - m );
    for( int i = n - m + 1; i <= n; ret *= (i++) );
    for( int i = 1; i <= m; ret /= (i++) );
    return  m < 0 ? 0 : ret;
}



// ������ͼ�����ѵ����� ( rev == true )
// ������ͼ��ǿ����     ( rev == false )
void DFS( int w ) {
    id[w] = scnt;
    if( rev ) {
        for( int i = 1; i <= N; ++i )
        if( G[i][w] && id[i] == -1 )
            DFS( i );
    }
    else {
        for( int i = 1; i <= N; ++i )
        if( G[w][i] && id[i] == -1 )
            DFS( i );
    }
    postI.push_back( w );
}




int main() {
    
    while( cin >> N >> M >> K ) {
    
        memset( G, 0, sizeof( G ) );
        
        for( int i = 0; i < M; ++i ) {
            cin >> x >> y;
            G[x][y] = true;
        }
        
        // Kosaraju �㷨 
        memset( id, -1, sizeof( id ) );
        postI.clear();
        scnt = 0;   rev = true; 
        for( int i = 1; i <= N; ++i )
            if( id[i] == -1 )
                DFS( i );
        memset( id, -1, sizeof( id ) );
        scnt = 0;   rev = false; 
        for( int pos = N - 1; pos >= 0; --pos ) {
            if( id[postI[pos]] == -1 ) {
                DFS( postI[pos] );
                ++scnt;
            }
        }
        
        // �������ǿ�������еĶ����� 
        allComponent.assign( scnt, 0 );
        for( int i = 1; i <= N; ++i )
             ++allComponent[id[i]]; 
        
        // ǿ����������ϣ�������� DAG
        memset( DAG, 0, sizeof( DAG ) );
        for( int i = 1; i <= N; ++i )
            for( int j = 1; j <= N; ++j )
                if( G[i][j] ) 
                    if( id[i] != id[j] )
                        DAG[id[i]][id[j]] = true;
        
        // �������ȱ���ȷ���÷����Ƿ�ΪԴ����� 
        memset( dag_in, 0, sizeof( dag_in ) );
        memset( dag_out, 0, sizeof( dag_out ) );
        for( int i = 0; i < scnt; ++i ) {
            for( int j = 0; j < scnt; ++j ) {
                if( DAG[i][j] ) {
                    ++dag_out[i];
                    ++dag_in[j]; 
                }
            }
        }
        
        // ����� U
        U.clear(); 
        for( int i = 0; i < scnt; ++i )
            if( dag_in[i] == 0 || dag_out[i] == 0 )
                U.push_back( allComponent[i] );
        
        // ���� U ������ȫ�����
        sort( U.begin(), U.end() );
        U_acc = U;
        for( int i = 1; i < U.size(); ++i )
            U_acc[i] += U_acc[i-1];
        
        // ��̬�滮 
        for( int i = 0; i < 101; ++i )
            for( int j = 0; j < 101; ++j )
                DP[i][j] = 0;
        
        for( int j = 1; j <= U[0]; ++j )
            DP[0][j] = comb( U[0], j );
        for( int i = 1; i < U.size(); ++i ) {
            for( int j = i + 1; j <= U_acc[i]; ++j ) {
                for( int k = 1; j - k; ++k ) {
                    DP[i][j] += DP[i-1][j-k] * comb( U[i], k );
                }
            }
        }
        
        BigNum  ans = 0;
        for( int k = U.size(); k <= U_acc.back() && k <= K; ++k )
            ans += DP[U.size() - 1][k] * comb( N - U_acc.back(), K - k );
        
        
        cout << ans << endl << endl;
        
    }
    
}
