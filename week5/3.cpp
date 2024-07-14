#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<map>

using namespace std;
class TreeNode {
    public :
	    char nodeValue;
            TreeNode* left;
	    TreeNode* right;
	    TreeNode(char nodeValue ) : nodeValue(nodeValue), left(nullptr), right(nullptr) {}
};

class BinaryTree {
	public:
		TreeNode* buildTree(vector<char> & nameVec, vector<int> & levelVec) {
		    if(nameVec.size() == 0) {
		        return nullptr;
		    } else {
		        multimap <int,int> order;
			for(int i = 0 ; i < levelVec.size(); i++) {
			    order.insert(make_pair(levelVec[i],i));
			}
		        return buildTreeRec(nameVec, levelVec, 0,levelVec.size() -1, order);
		    }
		}

		TreeNode* buildTreeRec( vector<char> & nameVec, vector<int> & levelVec, int start, int end, const multimap<int,int>& order) {
                    if( start <0 || end >= nameVec.size()) { return nullptr;}
		    if( nameVec[start] == '*') {return nullptr;}
	            TreeNode* root = new TreeNode(nameVec[start]);
		    int leftStart= start +1;
		    int level=levelVec[leftStart];
		    std::pair<std::multimap<int,int>::const_iterator, std::multimap<int,int>::const_iterator> ret;
		    ret = order.equal_range(level);
		    int rightStart= ret.second->second;
		    TreeNode* left = buildTreeRec(nameVec, levelVec,leftStart,rightStart-1,order);
	            TreeNode* right=buildTreeRec(nameVec,levelVec,rightStart,end,order);
	             root->left=left;
	             root->right=right;
	             return root;	   
		    }
	private:
		TreeNode * root;
};

void printPreOrder(TreeNode * node) {
    if(node == nullptr) {
        return;
    }
    std::cout<< node->nodeValue << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(TreeNode * node) {
    if(node == nullptr) {
        return;
    }
    printInOrder(node->left);
    std::cout<< node->nodeValue<< " ";
    printInOrder(node->right);
}

void printPostOrder(TreeNode * node) {
    if(node == nullptr) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout<< node->nodeValue<<" ";
}


int main() {
    int firstLine=0;
    string line;
    int caseNumber=0;
    vector<char> nameVec;
    vector<int>  levelVec;
    while(getline(cin,line)) {
        if(firstLine== 0) {
	    caseNumber=stoi(line);
	    firstLine++;
	    continue;
	} else {
            if(line == "0") {
                BinaryTree tree;
		TreeNode* root = tree.buildTree(nameVec,levelVec);
		std::cout<< "preOrdeer ";
		printPreOrder(root);
		std::cout << endl;
		std::cout << "Inorder ";
		printInOrder(root);
		std::cout<< endl;
		std::cout << "PostOrder ";
		printPostOrder(root);
		std::cout<< endl;

	        //nameVec.swap(vector<char>());
		//levelVec.swap(vector<int>());
		nameVec.clear();
		levelVec.clear();
                continue;
	    }	else {
	       int level=0;
	        for(int i=0; i < line.size()-1;i++) {
		    if(line[i] == '-') {
		        level++;
		    }
		} 
		nameVec.push_back(line[line.size()-1]);
		levelVec.push_back(level);
	    }
	}
    }    
}
