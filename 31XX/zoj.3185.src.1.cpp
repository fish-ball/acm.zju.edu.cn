// 1868812 2009-05-14 15:41:17 Accepted  3185 C++ 0 184 ���͵����� 

// ������б�������㣬�����Ļ�ֱ�Ӵ��ӣ�
// ��Ļ��������Ҳ����б�ŵ� map �У�Ȼ��ö��������б�
// ��������� map �У�ɾ���� map �е�һ��������
// ������ӵ��µ��б��У����ԭ�����б��滻���µ��б� 

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct List {
    
    vector<string> comp;
    
    bool get() {
        string s;
        cin >> s;
        if(s == ".") return false;
        s = s.substr(1, s.size() - 2);
        comp.clear();
        while(s != "") {
            int pos = s.find_first_of(',');
            if(pos == string::npos) {
                comp.push_back(s);
                s.erase();
            }
            else {
                comp.push_back(s.substr(0, pos));
                s.erase(0, pos + 1);
            }
        }
        return true;
    }
    
    void put() {
        cout << "[";
        int T = 0;
        for(int i = 0; i < comp.size(); ++i) {
            if(T++) cout << ',';
            cout << comp[i];
        }
        cout << "]" << endl;
    }
    
    List sub(const List& rhs) {
        map<string, int> MP;
        for(int i = 0; i < rhs.comp.size(); ++i) {
            MP[rhs.comp[i]]++;
        }
        vector<string> tmp(0);
        for(int i = 0; i < comp.size(); ++i) {
            if(MP[comp[i]]) --MP[comp[i]];
            else tmp.push_back(comp[i]);
        }
        comp = tmp;
        return *this;
    }
    
    List add(const List& rhs) {
        for(int i = 0; i < rhs.comp.size(); ++i) {
            comp.push_back(rhs.comp[i]);
        }
        return *this;
    }
};

int main() {
    List a, b;
    while(a.get()) {
        string ss;
        cin >> ss;
        b.get();
        if(ss == "++") a.add(b).put();
        else a.sub(b).put();
    }

}
