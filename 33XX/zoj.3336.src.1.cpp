// 2211815 2010-06-12 19:52:04 Accepted  3336 C++ 10 184 ���͵����� 

// ����ǰͷ��һ�� 0 ��������
// Ȼ���ĩβ��һ������Ŀ۵� 1��ʣ����ۼӵ� sum �У���λ�� 0��
// Ȼ���ǰһλ��ǰ����ųԵ�(�ӵ� sum ��)�� 0��
// ֱ����һ����Ϊ 9 �ģ���һ��
// ���� sum �Ӹ�λ��ʼ���ȥ��
// ����ǰ���㣬����� 
 

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    for(cin >> N; N--;) {
        string x;
        cin >> x;
        x = "0" + x;
        int tail = x.find_last_not_of('0');
        int sum = x[tail] - '0' - 1;
        x[tail--] = '0';
        while(x[tail] == '9') {
            x[tail--] = '0';
            sum += 9;
        }
        x[tail] += 1;
        for(int k = x.size() - 1; k >= 0 && sum; --k) {
            if(sum <= 9) {
                x[k] += sum;
                sum = 0;
            }
            else {
                x[k] += 9;
                sum -= 9;
            }
            
        }
        if(x[0] == '0') {
            x.erase(0, 1);
        }
        cout << x << endl;
    }
}
