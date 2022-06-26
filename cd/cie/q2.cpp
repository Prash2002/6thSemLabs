
// 2. Write a C / C++ program to accept a C program and do error detection & correction for the following. (CO1)
//    Check for un- terminated multi line comment statement in your C program.

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{

    fstream file;
    string text;
    bool commentStart = false;
    int start = 0;
    file.open("../sample/string.c");
    int lineNo = 0;
    while (getline(file, text))
    {
        lineNo++;
        if (text.find("/*") != string::npos && !commentStart)
        {
            start = lineNo;
            commentStart = true;
        }
        if (text.find("*/") != string::npos && commentStart)
        {
            cout << "Comment started at: " << start << " and ended at: " << lineNo << "\n";
            commentStart = false;
        }
    }
    if (commentStart)
    {
        cout << "Unterminated comment which starts at: " << start << "\n";
    }
    else
    {
        cout << "All comments terminated! Beautiful Code\n";
    }
}