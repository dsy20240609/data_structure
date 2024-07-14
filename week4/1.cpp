#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
bool isUnit(string s);
int transToUnit(string s);
bool isDigit(string s);
int transToDigit(string s);

int main() {
    std::string line;
    while(std::getline(std::cin,line)) {
        if(line.empty()) {
	    break;
	}
	else {
          istringstream ss(line);
          vector<string> words;
          string word;
	  while(ss>>word) {
	      words.push_back(word);
	  }
	   
	  bool isNeg= false;
	  int sum=0;
	  for(int i = 0 ; i < words.size(); i++) {
	    if(i == 0 && words[i] == "negative") {
	        isNeg= true;
		continue;
	    }
            if(isDigit(words[i])) {
	       sum=sum+transToDigit(words[i]);
	    } else if (isUnit(words[i])) {
	        sum= sum*(transToUnit(words[i]));
	    }
	  }
	if(isNeg == true) {
	    std::cout<< (-1)*sum << endl;
	} else {
	    std::cout << sum << endl;
	}
    }
  }
}

bool isUnit (string s) {
     if(s == "hundred") {
		return true;
     } else if( s == "thousand") {
		return true;
     } else if ( s == "million" ) {
		return true;
     } else {
		return false;
     }
}

int transToUnit(string s) {
     if(s == "hundred") {
		return 100;
     } else if( s== "thousand") {
		return 1000;
     } else if ( s == "million" ) {
		return 1000000;
     } else {
		return 0;
     }
}

bool isDigit(string s) {
    if(s == "zero") {
       return true;
    } else if (s == "one") {
       return true;
    } else if (s == "two") {
       return true;
    } else if (s == "three") {
       return true;
    } else if (s == "four") {
	           return true;
    } else if ( s == "five") {
	           return true;
    } else if ( s == "six") {
	           return true;
    } else if ( s == "seven") {
	           return true;
    } else if ( s == "eight") {
	           return true;
    } else if ( s == "nine") {
	           return true;
    } else if ( s == "ten") {
	           return true;
    } else if ( s == "eleven") {
	           return true;
    } else if ( s == "twelve") {
	           return true;
    } else if ( s == "thirteen") {
	           return true;
    } else if (s == "fourteen") {
	           return true;
    } else if (s == "fifteen") {
	           return true;
    } else if (s == "sixteen") {
	           return true;
    } else if (s =="seventeen") {
	           return true;
    } else if (s == "eighteen") {
	           return true;
    } else if ( s == "nineteen") {
	           return true;
    } else if ( s == "twenty") {
		   return true;
    } else if ( s == "thirty") {
		   return true;
    } else if ( s == "forty") {
		   return true;
    } else if ( s == "fifty") {
		    return true;
    } else if ( s == "sixty") {
		     return true;
    } else if ( s == "seventy") {
		     return true;
    } else if ( s =="eighty") {
		    return true;
    } else if ( s == "ninety") {
		    return true;
    } else {
		    return false;
    }
}

int transToDigit(string s) {
    if(s == "zero") {
           return 0;
    } else if (s == "one") {
       return 1;
    } else if (s == "two") {
       return 2;
    } else if (s == "three") {
       return 3;
    } else if (s == "four") {
               return 4;
    } else if ( s == "five") {
               return 5;
    } else if ( s == "six") {
               return 6;
    } else if ( s == "seven") {
               return 7;
    } else if ( s == "eight") {
               return 8;
    } else if ( s == "nine") {
               return 9;
    } else if ( s == "ten") {
               return 10;
    } else if ( s == "eleven") {
               return 11;
    } else if ( s == "twelve") {
               return 12;
    } else if ( s == "thirteen") {
               return 13;
    } else if (s == "fourteen") {
               return 14;
    } else if (s == "fifteen") {
               return 15;
    } else if (s == "sixteen") {
               return 16;
    } else if (s =="seventeen") {
               return 17;
    } else if (s == "eighteen") {
               return 18;
    } else if ( s == "nineteen") {
               return 19;
    } else if ( s == "twenty") {
    	   return 20;
    } else if ( s == "thirty") {
    	   return 30;
    } else if ( s == "fourty") {
    	   return 40;
    } else if ( s == "fifty") {
    	    return 50;
    } else if ( s == "sixty") {
    	     return 60;
    } else if ( s == "seventy") {
    	     return 70;
    } else if ( s =="eighty") {
    	    return 80;
    } else if ( s == "ninety") {
    	    return 90;
    } else {
    	    return 0;
    }
}
// shows wrong answer in the POJ system
