// 2060419 2009-12-17 17:22:30 Accepted  3280 C++ 810 1748 ���͵����� 
/*
Choose The Best
��Ŀ���⣺����Nά�ռ��һЩ�㣬���Ȩ�����پ��������������ľ��롣
������ Ȩֵ���Գ˵���������ȥ������˵���԰�ÿ����ÿһά�����϶�Ӧ��w[t]��
����2ά����� |x1-x2|+|y1-y2| ���ֵֻ��4�������(x1+y1)-(x2+y2) , (-x1+y1)-(-x2+y2), (-x1-y1)-(-x2-y2), (x1-y1)-(x2-y2)�����ֵ��4��֮һ��������ȡ���Ϳ����ˡ���һ������4����ʽ��ÿ�������һ����͵ڶ����������������ŵķ�����һ���ġ��ƹ㵽Nά������ö�ټӷ��ŵķ�ʽ��һ����1<<M���֣�Ȼ���ÿ�ַ�ʽ��ÿ��������갴ö�ٵļ����ŵķ�ʽNά�������һ��ֵ����ȡ������Сֵ�Ĳ��Ϊ���ܽ�������ȡ���в�ֵ�����ļ��ɡ���ע��M��С��ֻ��8�����Ӷ�O(2M*n)
*/


#include <iostream>
#include <algorithm>
using namespace std;

int x[50000][8], w[8];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", x[i] + j);
            }
        }
        for(int j = 0; j < m; ++j) {
            scanf("%d", w + j);
        }
        int ans = 0;
        for(int b = 0; b < (1<<m); ++b) {
            int mx = INT_MIN, mn = INT_MAX;
            for(int i = 0; i < n; ++i) {
                int val = 0;
                for(int j = 0; j < m; ++j) {
                    if((1<<j)&b) {
                        val += w[j] * x[i][j];
                    }
                    else {
                        val -= w[j] * x[i][j];
                    }
                }
                mx = max(val, mx);
                mn = min(val, mn);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << endl;
    }
}
