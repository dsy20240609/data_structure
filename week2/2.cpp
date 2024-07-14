#include<iostream>
#include<sstream>
#include<map>
#include<vector>

using namespace std;
vector<int> split(string s);
int main() {
    int number;
    int count =0;
    string line1;
    string line2;
    vector<int> line1split;
    vector<int> line2split;
    string input;
    while(std::getline(cin,input)) {
           if(count ==0 ) {
	       number=std::stoi(input);
	       count++;
	       continue;
	   } else {
	    if(count%2 == 1) {
		//line1=input.substr(0,input.size()-3); 
		line1 = input;
	        printf("%s\n",line1.c_str());
	        line1split=split(line1);
	        printf("line 22 %d\n", line1split.size());
		count++;
	        continue;
	    } else {
		//line2=input.substr(0,input.size()-3);
		line2=input;
	        line2split=split(line2);
	        printf("line 25 %d\n", line2split.size());
	        map<int,int> m1;
	        map<int,int> m2;
	        for(int i = 0 ; i <= line1split.size() -1; i=i+2) {
	            if(m1.find(line1split[i+1])!=m1.end()) {
	                m1[line1split[i+1]] = m1[line1split[i+1]] + line1split[i];
	            } else {
	                m1.emplace(make_pair(line1split[i+1],line1split[i]));
	            }
	        }
                for(int i = 0 ; i <= line2split.size() -1; i=i+2) {
	            if(m2.find(line1split[i+1]) !=m2.end()) {
	                m2[line2split[i+1]] = m2[line2split[i+1]] + line2split[i];
	            } else {
	                m2.emplace(make_pair(line2split[i+1],line2split[i]));
	            }
	        }

	        map<int,int> res = m1;
	        for(auto it=m2.begin(); it!=m2.end();it++) {
	            if(res.find(it->first) != m2.end()) {
	              res[it->first] = res[it->first] + m2[it->first];
	            } else {
	              res.emplace(make_pair(it->first,it->second));
	            }
	        }
	        for(auto it1=res.begin(); it1 != res.end(); it1++) {
	            std::cout << "[" << it1->first << " " <<  it1->second << "]" << endl;
	        }
		count++;
	        number--;
           }
        }
    }
}

vector<int> split(string s) {
    istringstream ss(s);
    string word;
    vector<int> res;
    while(ss>>word) {
       res.push_back(std::stoi(word));
    }
    return res;
}


