#include<bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
    fstream file;
    string text;
    bool open=false, close=false, isQuoted = false;
    file.open("sample/string.c");
    int lineNo = 0;
    while(getline(file, text)){
        lineNo++;
        for(char c: text){
            if(c=='"'){
                isQuoted = true;
                if(!open && !close ) open = true;
                else if( open && !close) close = true;
                else if(open && close) close = false;
            }
        }
        if(!isQuoted) continue;
        if(open && close) {
            cout<<"perfect line\n";
        }
        else{
            cout<<"Error in line "<< lineNo <<"\n";
        }
        open=false, close=false, isQuoted = false;
    }



    file.close();

}