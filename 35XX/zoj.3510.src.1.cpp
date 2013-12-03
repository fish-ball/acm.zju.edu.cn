// http://acm.zju.edu.cn/onlinejudge/showSubmission.do?submissionId=3768689
// 3485088	2013-12-02 23:49:33	 Accepted	3510	C++	160	2956	´ôÖÍµÄÂý°å

#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long i64;


// contains all the expressions.
vector<string> vexp;

// contains all the variable of each expressions.
vector<string> vvar;

// mapping variables to their values.
map<string, i64> vals;

// mapping variables to their expressions.
map<string, string> expr;


// contains the expressions requirement strings.
vector<set<string> > vreq;

// mapping variables to vexp indexs which requires the variables.
map<string, vector<int> > vidx;

// priority queue to index.
multimap<i64, int> q;

// result index order.
bool broken;
i64 ans;
vector<int> result;


// evaluates an expression.
i64 eval(string s) {
    
    vector<i64> vv(0);
    vector<char> op(0);
    
    istringstream iss(s);
    string buf;
    
    while(iss >> buf) {
        
        if(buf == "(") continue;
        else if(buf == "+") op.push_back('+');
        else if(buf == "*") op.push_back('*');
        else if(isdigit(buf[0])) vv.push_back(atoi(buf.c_str()));
        else if(isalpha(buf[0])) vv.push_back(vals[buf]);
        else if(buf == ")") {
            
            i64 x = vv.back();
            vv.pop_back();
            i64 y = vv.back();
            
            // + case
            if(op.back() == '+') {
                vv.back() += x;
                // BROKEN: If add overflow, result will less than both.
                if(vv.back() < x || vv.back() < y) return 0;
            }
            // * case
            else if(op.back() == '*') {
                vv.back() *= x;
                // BROKEN: If mutiply overflow, division cannot recover.
                if(vv.back() / x != y) return 0;
            }
            
            op.pop_back();
            
        }
        else {
            // Unexpected case, throw OLE.
            while(1) cout << "OLE!";
        }
    }
    
    return vv.back();
    
}




int main() {
    
    int n;
    
    while(cin >> n >> ws) {
        
        // reset.
        vexp.clear();
        vvar.clear();
        
        vals.clear();
        expr.clear();
        
        vreq.assign(n, set<string>());
        vidx.clear();
        
        q.clear();
        
        broken = false;
        ans = 0;
        result.clear();
        

        // input and calculation.
        for(int i = 0; i < n; ++i) {
            
            //cout << "i = " << i << endl;
            
            string s;
            getline(cin, s);
            int p = s.find(' ');
            
            vvar.push_back(s.substr(0, p));
            vexp.push_back(s.substr(p + 3));
            
            //cout << "vvar = |" << vvar[i] << "|" << endl;
            //cout << "vexp = |" << vexp[i] << "|" << endl;
            
            
            // scratch all the reference variables.
            // add sentienl to split.
            istringstream iss(vexp.back());
            string v;
            
            while(iss >> v) {
                
                // if variable gotcha.
                if(isalpha(v[0])) {
                    
                    // initialize variable list
                    vals[v] = 0;
                    expr[v] = "";
                    
                    // add requirement link
                    vreq[i].insert(v);
                    
                    // add index link, AVOID repeatly link.
                    if(vidx[v].size() == 0 || vidx[v].back() != i) { 
                        vidx[v].push_back(i);
                    }
                }
                
            }

            // if the value is clear.
            if(vreq[i].size() == 0) {
                
                i64 val = eval(vexp.back());
                
                q.insert(make_pair(val, i));
                
            }
            
        }
        
        // proccess
        while(!q.empty()) {
            
            // pop from priority queue.
            i64 val = q.begin()->first;
            int i = q.begin()->second;
            q.erase(q.begin());
            
            // get var.
            string v = vvar[i];
            
            if(vals[v] == 0) {
            
                result.push_back(i);
                
                vals[v] = val;
                expr[v] = vexp[i];
                
                for(int j = 0; j < vidx[v].size(); ++j) {
                    
                    int k = vidx[v][j];
                    
                    // kick the link.
                    vreq[k].erase(v);
                    
                    // if all requirement was calculated.
                    if(vreq[k].empty()) {
                
                        i64 val = eval(vexp[k]);
                        
                        if(val != 0) q.insert(make_pair(val, k));
                        
                    }
                }
                
            }
            
        }
        
        
        // reduce..
        if(result.size() < vals.size()) broken = true;
        
        for(map<string, i64>::iterator it = vals.begin(); it != vals.end(); ++it) {
            
            // if overflow
            if(ans + it->second < ans) {
                broken = true;
                break;
            }
            
            ans += it->second;
            
        }
        
        if(broken) {
            cout << "stupid expressions!" << endl;
        }
        else {
            cout << ans << endl;
            for(int i = 0; i < result.size(); ++i) {
                int j = result[i];
                cout << vvar[j] << " = " << vexp[j] << endl;
            }
        }
        
    }
    
    return 0;
    
}
