// 3493552 2013-12-21 17:18:23 Accepted 3529 C++ 2680 564 ´ôÖÍµÄÂı°å
// ¾­µä Nim 

#include <cstdio>
#include <cstring>

const int MXP = 2236;

bool b[MXP] = {};
int p[331], a[100000], np = 0, i, j, n, t = 0;

int f(int x) {
    int ans = 0;
    for(int k = 0; k < np; ++k) {
        while(x % p[k] == 0) {
            x /= p[k];
            ans += 1;
        }
        if(x == 1) return ans;
    }
    return x == 1 ? ans : ans + 1;
}

int main() {
    
    for(i = 2; i < MXP; ++i) {
        if(!b[i]) {
            p[np++] = i;
            for(j = i*i; j < MXP; j+=i) b[j] = true; 
        }
    }
    
    while(scanf("%d", &n) != EOF) {
        
        int ans = 0;
        for(i = 0; i < n; ++i) {
            scanf("%d", a+i);
            ans ^= (a[i] = f(a[i]));
        }
        
        if(ans) {
            for(i = 0; i < n; ++i) {
                if((ans^a[i]) <= a[i]) {
                    printf("Test #%d: Alice %d\n", ++t, i+1);
                    break;
                }
            }
        }
        else printf("Test #%d: Bob\n", ++t);
        
    }
}
