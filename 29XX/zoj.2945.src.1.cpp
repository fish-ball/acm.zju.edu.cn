// 1693280 2008-11-08 15:47:18 Accepted  2945 C++ 0 184 ���͵����� 

// ���ܣ�����ת��Ϊһ����ģ���Է�����Ľ⡣ 

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif
//��չEuclid���gcd(a,b)=ax+by
int ext_gcd(int a,int b,int& x,int& y){
	int t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}

//����m^a, O(loga), ����ûʲô��, ע�������λ����ķ��� :-P
int exponent(int m,int a){
	int ret=1;
	for (;a;a>>=1,m*=m)
		if (a&1)
			ret*=m;
	return ret;
}

//������ȡģa^b mod n, O(logb)
int modular_exponent(int a,int b,int n){ //a^b mod n
	int ret=1;
	for (;b;b>>=1,a=(int)((i64)a)*a%n)
		if (b&1)
			ret=(int)((i64)ret)*a%n;
	return ret;
}

//���ģ���Է���ax=b (mod n)
//���ؽ�ĸ���,�Ᵽ����sol[]��
//Ҫ��n>0,��ķ�Χ0..n-1
int modular_linear(int a,int b,int n,int* sol){
	int d,e,x,y,i;
	d=ext_gcd(a,n,x,y);
	if (b%d)
		return 0;
	e=(x*(b/d)%n+n)%n;
	for (i=0;i<d;i++)
		sol[i]=(e+i*(n/d))%n;
	return d;
}

//���ģ���Է�����(�й���������)
//  x = b[0] (mod w[0])
//  x = b[1] (mod w[1])
//  ...
//  x = b[k-1] (mod w[k-1])
//Ҫ��w[i]>0,w[i]��w[j]����,��ķ�Χ1..n,n=w[0]*w[1]*...*w[k-1]
int modular_linear_system(int b[],int w[],int k){
	int d,x,y,a=0,m,n=1,i;
	for (i=0;i<k;i++)
		n*=w[i];
	for (i=0;i<k;i++){
		m=n/w[i];
		d=ext_gcd(w[i],m,x,y);
		a=(a+y*m*b[i])%n;
	}
	return (a+n)%n;
}

int main() {
    int T, N, x, y;
    int w[4], b[4];
    string text;
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 0; i < 4; ++i)
            cin >> w[i];
        text.resize(N*3);
        for(int i = 0; i < N; ++i) {
            cin >> x;
            for(int j = 0; j < 4; ++j) {
                b[3-j] = x % 100;
                x /= 100;
            }
            y = modular_linear_system(b, w, 4);
            for(int j = 0; j < 3; ++j) {
                text[i * 3 + 2 - j] = y % 100;
                y /= 100;
            }
        }
        for(int i = 0; i < text.size(); ++i) {
            if(text[i] == 27) text[i] = ' ';
            else text[i] = 'A' + text[i] - 1;
        }
        text.erase(text.find_last_not_of(' ') + 1);
        cout << text << endl;
    }
}
