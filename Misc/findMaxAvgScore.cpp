//g++  5.4.0

#include <iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;


int findMax(vector<vector <string>> str){
    map<string,vector<int>> temp;
    //map<string,double> final;
    int max=0;
    for(int i=0;i<str.size();i++){
        //cout<<"Coming String "<<str[i][0]<<" "<<str[i][1]<<endl;
        auto it = temp.find(str[i][0]);
        if(it == temp.end()){
            //cout<<"First Time\t" << str[i][0]<<"\t";
            int marks = stoi(str[i][1]);
            //cout<<marks<<endl;
            vector<int> t(2,0);
            t[0] = marks;
            t[1] = 1;
            temp[str[i][0]]=t;
        } else {
            vector<int> t1 = it->second; 
            t1[0]= t1[0]+stoi(str[i][1]);
            //cout<<"Kya" <<t1[0]<<endl;
            t1[1] = t1[1]+1;
            temp[str[i][0]] = t1;
            auto it2= temp.find(str[i][0]);
            //cout<<"Second time "<<it2->first <<" "<< it2->second[0]<<endl;
        }
    }
    
    for (auto it1 = temp.begin();it1!=temp.end();it1++){
            vector<int> v1 = it1->second;
            int avg = v1[0]/v1[1];
            if(avg >max){
                max = avg;
            }
            //cout<< it1->first <<" ";
            //cout<<avg<<endl;
     }
    return max;
}
int main()
{
    vector<vector<string>> str = {{"Ab","70"},{"Ab","80"},{"Ab","90"},{"bc","7"}};
    //cout<<str.size()<<endl;
    cout<<findMax(str);
    return 0;
}
