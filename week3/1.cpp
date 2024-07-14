#include<string>
#include<vector>
#include<iostream>
using namespace std;

string translate(string input);
int main() {
    int number;
    int count =0;
    string input;
    while(std::getline(cin,input)) {
        if(count == 0) {
	    number=std::stoi(input);
	    count++;
	    continue;
	} else {
            string res= translate(input);
            std::cout<< res << endl;	    
	}
    }    
}

string translate(string input) {
    if(input.size() == 0) {
        return "";
    }
    vector<char> tmp;
    for(int i = 0 ; i < input.size(); i++) {
        if(input[i] == 'z') {
	    tmp.push_back('a');
	    continue;
	}
	if(input[i] == 'Z') {
	    tmp.push_back('A');
	    continue;
	}
	if('a' <= input[i] && input[i] <= 'y' ||
	   'A' <= input[i] && input[i] <= 'Y') {
            tmp.push_back(static_cast<char>(static_cast<int>(input[i])+1));
        } else {
	    tmp.push_back(input[i]);
	}	 
    }
    string res(tmp.begin(),tmp.end());
    return res;
}
