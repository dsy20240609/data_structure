#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

int main () {
   int number;
   int count=0;
   string input;
   string s1;
   string s2;
   while(std::getline(cin,input)) {
       if(count ==0 ) {
           number=std::stoi(input);
	   count++;
	   continue;
       } else {
            if(count%2 ==1) {
	        s1 = translate(input);
	    } else {
	        s2 = translate(input);
	        if(s1 == s2) {
	            std::cout<< "YES"<<endl;
	        } else {
	            std::cout<< "NO" << endl;
	        }
	    }    
       }
   }
}
string translate(string input) {
    string res;
    stack<char> s;
    for(int i = 0 ; i < input.size(); i++) {
        if(input[i] == ")") {
            while(s.top() != "(") {
	        res.push_back(s.pop());
                std::reverse(res.begin(),res.end());
	    }
	} else if (input[i] == ' ' || input[i] == '\t') {
	    continue;	
	} else {
	    s.push(input[i]);
	}    
    }
}
