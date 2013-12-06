#include <iostream>
#include <string>
using namespace std;

string Zodiac[] = {
    "Rat"
    , "Ox"
    , "Tiger"
    , "Rabbit"
    , "Dragon"
    , "Snake"
    , "Horse"
    , "Ram"
    , "Monkey"
    , "Rooster"
    , "Dog"
    , "Pig" };

int main() {
    int count;
    cin >> count;
    while(count--) {
        int age;
        cin >> age;
        cout << Zodiac[((4 - age) % 12 + 12) % 12] << endl;
    }

}