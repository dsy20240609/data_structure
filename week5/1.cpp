#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<sstream>

using namespace std;
struct TreeNode {
  int value;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    public :
	    TreeNode* buildTree(const std::vector<int>& inorder, const std::vector<int> & postorder) {
	        if(inorder.size() != postorder.size()) {
		    return nullptr;
		}
                std::unordered_map<int,int> inorderMap;
		for(int i = 0; i < inorder.size(); i++) {
		    inorderMap[inorder[i]] = i;
		}
	        return buildTreeRec(inorder,0, inorder.size() -1, postorder, 0, postorder.size()-1, inorderMap);
	    }
    private:
	    TreeNode * buildTreeRec(const std::vector<int>& inorder, int inStart, int inEnd, const std::vector<int> & postorder, int postStart, int postEnd,
			    const std::unordered_map<int,int> &inorderMap) {
	    
	        if(inStart > inEnd || postStart > postEnd) return nullptr;
		int rootValue= postorder[postEnd];
		TreeNode * root = new TreeNode(rootValue);
		int inorderRootIndex = inorderMap.at(rootValue);
		int leftTreeSize = inorderRootIndex - inStart;
		
		root->left=buildTreeRec(inorder, inStart, inorderRootIndex -1, postorder, postStart, postStart+leftTreeSize-1,inorderMap);
		root->right= buildTreeRec(inorder,inorderRootIndex+1, inEnd, postorder, postStart+leftTreeSize, postEnd-1, inorderMap);
		return root;
	    
	    }
  };

void printPreOrder(TreeNode* node) {
    if(node == nullptr) return;
    std::cout << node->value<< " " ;
    printPreOrder(node->left);
    printPreOrder(node->right);
}


int main () { 
	string line1;
	getline(cin,line1);
        istringstream ss1(line1);
	string tmp1;
	vector<int> res1;
	while( ss1>> tmp1) {
	    res1.push_back(stoi(tmp1));
	}


        string line2;
	getline(cin,line2);
	istringstream ss2(line2);
	vector<int> res2;
	string tmp2;
	while( ss2 >> tmp2) {
	    res2.push_back(stoi(tmp2));
	}
        BinaryTree tree;
        TreeNode* root=tree.buildTree(res1,res2);	
        printPreOrder(root);
}
