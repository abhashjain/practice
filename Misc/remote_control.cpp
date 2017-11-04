#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int getMinimumClicks(string , string);
int leftClicks(int current ,int destination,int min,int max);
int rightClicks(int current ,int destination,int min,int max);
int numberpunch (int destination);
int alternate (int destination,int previous);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string startAndEndChannel="";
    string listOfChannels="";
    cin >> startAndEndChannel;
    cin >> listOfChannels;
    int minimumClick = getMinimumClicks(startAndEndChannel,listOfChannels);
    cout << minimumClick;
    return 0;
}
int leftClicks(int current, int destination,int min,int max){
   int clicks = 0;
   if(current==max){
	clicks++;
	current=min;
   }
    for(int i=current;i%max!=destination;){
        if(i==destination)
            break;
        clicks++;
        if(i==max){
            i=min;
        }
	else	i=i+1;
    }
    return clicks;
}
int rightClicks(int current ,int destination,int min,int max){
    int clicks = 0;
    if(current==min){
	clicks++;
	current=max;
    }
    for(int i=current;i!=destination;){
        if(i==destination)
            break;
        clicks++;
        if(i==min)
           i=max;
    else i=i-1;
    }
    return clicks;
}

int numberpunch (int destination){
    int count=0;
    if(destination == 0)
        return 1;
    while(destination>0){
        destination = destination/10;
        count++;
    }
    return count;
}

int alternate(int destination,int previous){
    if(destination == previous)
        return 1;
    else
        return INT_MAX;
}
int getmin(int a ,int b,int c,int d){
    return min(a,min(b,min(c,d)));

}
int getMinimumClicks(string startAndEndChannel, string listOfChannels)
{
    int minimumCount=0,startChannel,endChannel;
    stringstream ss(startAndEndChannel);
    stringstream s_s(listOfChannels);
    int i,j;
    vector<int> vect;
    vector<int> channelList;
    //to read start and end channel
    while(ss >> i){
        vect.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }
    startChannel = vect[0];
    endChannel = vect[1];
    //to read the channel Number
    while(s_s >> i){
        channelList.push_back(i);
        if(s_s.peek() == ',')
            s_s.ignore();
    }
    for(int i=0;i<channelList.size();i++){
        if(i==0){
            int left = leftClicks(0,channelList[i],startChannel,endChannel);
            int right = rightClicks(0,channelList[i],startChannel,endChannel);
            int direct_number = numberpunch(channelList[i]);
            int alternate_punch = alternate(channelList[i],0);
            minimumCount+=getmin(left,right,direct_number,alternate_punch);
	    //cout<<channelList[i]<<" is "<< left <<" "<< right <<" "<<direct_number<<" "<<alternate_punch<<endl;
        } else {
            int left = leftClicks(channelList[i-1],channelList[i],startChannel,endChannel);
            int right = rightClicks(channelList[i-1],channelList[i],startChannel,endChannel);
            int direct_number = numberpunch(channelList[i]);
            int alternate_punch = alternate(channelList[i],channelList[i-2]);
            minimumCount+=getmin(left,right,direct_number,alternate_punch);
	    //cout<<channelList[i]<<" is "<< left <<" "<< right <<" "<<direct_number<<" "<<alternate_punch<<endl;
        }
    }
    return minimumCount;  
}
