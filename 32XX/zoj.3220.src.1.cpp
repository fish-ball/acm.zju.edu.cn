// 1914809 2009-07-11 12:05:08 Accepted  3220 C++ 0 184 ���͵����� 

// DotA �ƺ���ʾ����Ģ���⣬�ö����������Щ�Ļ�����һ�㡣 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Player {
    
    static const char*Streak[];
    
    // �Ƿ���˵�һ��Ѫ 
    static bool firstblood;
    
    // ������� 
    string name;
    
    // �ƺ��ۼ��� 
    int streak;
    
    // ��ɱ�����ۼ� 
    int continuum;
    
    // �ϴ�ɱ���¼�
    int lasttime; 
    
    static map<string, Player> players;
    
public:
    
    Player(string name) :
        name(name),
        streak(0),
        continuum(0),
        lasttime(-1) {} 
   
    // ����Լ�ɱ��һ���� 
    void Kill(int time) {
        // �����б��Ƿ� FB�� 
        if(!firstblood) {
            cout << name << " just drew First Blood!" << endl;
            firstblood = true;
        }
        // ���³ƺ��ۼ���
        streak = min(streak + 1, 10);
        // ���ƺ� 
        if(streak >= 3)
            cout << name << Streak[streak] << endl;
        // ������ɱ�� 
        if(time - lasttime <= 14) continuum += 1;
        else continuum = 1;
        // ����ʱ�� 
        lasttime = time;
        // ����ɱ
        if(continuum == 2)
            cout << name << " just got a Double Kill!" << endl;
        else if(continuum >= 3)
            cout << name << " just got a Triple Kill!" << endl;
    }
    
    // ����Լ���ɱ��
    void Killed(int time) {
        // �ƺ���������
        streak = 0;
    } 
    
    // ��ʼ����Ϸ����� FB ������б� 
    static void NewGame() {
        firstblood = false;
        players.clear();
    }
    
    // ɱ���¼�
    static void KillEvent(string a, string b, int t) {
        if(players.find(a) == players.end()) players.insert(make_pair(a, Player(a)));
        if(players.find(b) == players.end()) players.insert(make_pair(b, Player(b)));
        players.find(a)->second.Kill(t);
        players.find(b)->second.Killed(t);
    }
    
};

const char* Player::Streak[] = {
    "",
    "",
    "",
    " has a Killing Spree!",
    " is Dominating!",
    " has a Mega Kill!",
    " is Unstoppable!",
    " is Wicked Sick!",
    " has a Monster Kill!!!",
    " is Godlike!",
    " is Beyond Godlike! Somebody kill him!!" 
};

bool Player::firstblood = false;

map<string, Player> Player::players;

struct Rec {
    string A, B;
    Rec() {}
    Rec(string A, string B) : A(A), B(B) {}
};

bool operator<(Rec a, Rec b) { return a.A < b.A; }

int main() {
    int T;
    for(cin >> T; T--;) {
        int N = 0;
        pair<int, Rec> R[100];
        string buf;
        while(cin >> buf && buf != "#") {
            int p = buf.find(':');
            int t = atoi(buf.substr(0, p).c_str()) * 60 +
                    atoi(buf.substr(p + 1).c_str());
            string a, b;
            cin >> a >> buf >> b;
            R[N++] = make_pair(t, Rec(a, b));
        }
        Player::NewGame();
        sort(R, R+N);
        for(int i = 0; i < N; ++i)
            Player::KillEvent(R[i].second.A, R[i].second.B, R[i].first);
        puts("");
    }
}
