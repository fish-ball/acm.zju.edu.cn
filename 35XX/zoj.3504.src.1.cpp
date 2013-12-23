// 3495262 2013-12-23 23:18:43 Accepted 3504 C++ 0 168 呆滞的慢板

#include <cstdio>
#include <cmath>
#include <cstring>

int main() {
    
    int i, j, n;
    double r1[16], r2[16], i1[16], i2[16], p, ans;
    char s1[257], s2[257], *ss1, *ss2;
    
    while(!feof(stdin)) {
        
        gets(ss1 = s1);
        gets(ss2 = s2);
        
        scanf("%lf ", &p);
        
        for(n = 0; *ss1; ++n) {
            sscanf(ss1, " (%lf,%lf)", r1+n, i1+n);
            sscanf(ss2, " (%lf,%lf)", r2+n, i2+n);
            ss1 = strchr(ss1, ')')+1;
            ss2 = strchr(ss2, ')')+1;
        }
        
        ans = 0;
        for(i = 0; i < n; ++i) {
            ans += pow((r1[i]-r2[i])*(r1[i]-r2[i])+(i1[i]-i2[i])*(i1[i]-i2[i]), 0.5*p);
        }
        printf("%.10lf\n", pow(ans, 1.0/p));
        
    }
    
}
