#include<bits/stdc++.h>
#include <string.h>
using namespace std;

int calPoints(vector<string>& ops) {
        int sum=0;
        stack<string> s;
		for(int i=0;i<ops.size();i++){
			if(ops[i] == "+"){
				string t1 = s.top();
                s.pop();
                string t2 = s.top();
                s.pop();
                int t =stoi(t1)+stoi(t2);
                s.push(t2);
				s.push(t1);
				s.push(to_string(t));
                sum+=t;
            } else if(ops[i] == "C"){
                string t1 = s.top();
                s.pop();
                sum -= stoi(t1);
            } else if(ops[i] == "D"){
                string t1 = s.top();
                s.push(to_string(2*stoi(t1)));
                sum+=2*stoi(t1);
            } else {
                sum+=stoi(ops[i]);
                s.push(ops[i]);
            }
        }
        return sum;
    }
int main(){
	vector<string> m;
	m.push_back("5");
	m.push_back("-2");
	m.push_back("4");
	m.push_back("C");
	m.push_back("D");
	m.push_back("9");
	m.push_back("+");
	m.push_back("+");
	cout<< "Final output is "<<calPoints(m)<<endl;
	return 0;
}
