// 3493567 2013-12-21 18:16:02 Accepted 3551 C++ 90 168 ´ôÖÍµÄÂý°å

#include <cstdio>

int main() {

    int t, n, k;
    double p, ans;
    
    for(scanf("%d", &t); t--;) {
        scanf("%d%lf", &n, &p);
        for(ans = 0, k = 1; k < n; ++k)
            ans += 1.0/k/(n-k);
        printf("%.3lf\n", 0.5*n*(n-1)/p*ans);
    }

}
