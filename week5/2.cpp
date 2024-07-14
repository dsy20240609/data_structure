#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<functional>

class minHeap {
    public:
	    void insert(int value) {
	        minHeap.push(value);
	    }
	    int extractMin() {
	        if(minHeap.empty()) {
		    throw std::runtime_error("Heap is empty");
		}
	        int minValue = minHeap.top();
		minHeap.pop();
		return minValue;
	    }
	    void clear() {
	       while(!minHeap.empty()) {
	           minHeap.pop();
	       }
	    }
    private:
	    std::priority_queue<int,std::vector<int>, std::greater<int>> minHeap;
};

using namespace std;


int main() {
    int firstLine=0;
    int inputNumber=0;
    int caseNumber=0;
    string line;
    minHeap heap;
    while(getline(cin,line)) {
        if(firstLine==0) {
	   caseNumber= stoi(line);
	   firstLine++;
	   continue;
	} else {
	    if(inputNumber== 0) {
	        inputNumber= stoi(line);
		caseNumber--;
		heap.clear();
		continue;
	    } else {
	       istringstream ss(line);
	       vector<int> words;
	       string word;
	       while( ss>>word) {
	           words.push_back(std::stoi(word));
	       } 
	       if(words.size()==2 && words[0] == 1) {
	          heap.insert(words[1]); 
	       } else if (words.size() == 1 && words[0] == 2) {
	          int minValue= heap.extractMin();
                  std::cout << minValue << endl;
	       }
	    }
	
	}
    }
}
