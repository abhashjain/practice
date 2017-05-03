//g++  5.4.0

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str = "Ab,c,de!$";
    int start =0;
    int last = str.length()-1;
    char temp;
    while(start < last){
        while (tolower(str[start])< 97 || tolower(str[start]) > 122){
             start++;
        }
        while (tolower(str[last])<97 || tolower(str[last]) > 122){
             last--;
        }
         temp=str[last];
         str[last]=str[start];
         str[start]=temp;
         start++;
         last--;
    }
    cout<<str<<endl;
    return 0;
}
