#include<bits/stdc++.h>
#include <fstream>


using namespace std;

int main(){
    fstream file;
    string text;
    file.open("sample/string.c");
    int lineNo = 0;
    string firstStr;
    set<string> s = {"int", "char", "float", "long", "string", "unsigned", "double"};
    while(getline(file, text)){
        lineNo++;
        firstStr = "";
        for(char c: text){
            if(c==' ' && firstStr.empty() ) continue;
            if(c==' ' || c=='[') break;
            firstStr += c;
        }
        if(s.count(firstStr))
        {
            cout<<"Line "<<lineNo<<" is a declarative statement\n";
        }
        
    }



    file.close();

}