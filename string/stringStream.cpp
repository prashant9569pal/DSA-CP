// Tokenizing a string using stringstream
#include <bits/stdc++.h>

using namespace std;



vector<string>findString(string str){
    // Vector of string to save tokens
    vector<string> tokens;

    // stringstream class check1
    stringstream check1(str);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}

int main()
{

    string line;
    getline(cin, line);

    vector<string>ans=findString(line);
    for(auto i:ans){
        cout<<i<<" ";
    }
    
    return 0;
  
}
