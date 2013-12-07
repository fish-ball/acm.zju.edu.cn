// 2211815 2010-06-12 19:52:04 Accepted  3336 C++ 10 184 呆滞的慢板 

// 现在前头补一个 0 免得溢出；
// 然后从末尾第一个非零的扣掉 1，剩余的累加到 sum 中，该位归 0；
// 然后从前一位往前，逢九吃掉(加到 sum 中)归 0。
// 直到第一个不为 9 的，加一；
// 最后把 sum 从个位开始填回去；
// 消掉前导零，输出。 
 

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
