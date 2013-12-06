// 2544462 2011-05-25 13:30:06 Accepted 3487 C++ 40 188 ´ôÖÍµÄÂı°å

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        string ord = "th";
        if(num % 10 == 2 && num % 100 != 12) {
            ord = "nd";
        }
        else if(num % 10 == 1 && num % 100 != 11) {
            ord = "st";
        }
        else if(num % 10 == 3 && num % 100 != 13) {
            ord = "rd";
        }
        
        cout << num << ord << endl;
    }
}