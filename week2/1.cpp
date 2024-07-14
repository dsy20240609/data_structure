#include<iostream>
#include<list>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

int main() {
  int n,m;
  string input;
  std::getline(cin,input);
  istringstream ss(input);
  vector<string> s1;
  string s;
  while( ss>>s) {
    s1.push_back(s);
  }
  n=std::stoi(s1[0]);
  m=std::stoi(s1[1]);
  list<int> l;
  for(int i=1; i <= n;++i) {
    l.push_back(i);   
  }
  int count =m;
  list<int>::iterator pos= l.begin();
  while(l.size()>1) {
      auto lastIt=std::prev(l.end());
      while(count >1) {
	  if(pos==lastIt) {
	      pos=l.begin();
	  } else {
              pos++;
	  }
	  count--;
      }
      if(count ==1) {
         list<int>::iterator tmp = pos;
	 if(pos==lastIt) {
             pos=l.begin();
         } else {
	     pos++;
	 }
         l.erase(tmp);
         count =m;	 
      }      
  }
  printf("%d",l.front());
  return l.front();  
}
// study the api of c++ list class. know list.end() points to the the theoretical last element which follows the last element. c++ list is implementes as doubly linked list. and front() returns the value of the first element, back() returns the value of the last element.
