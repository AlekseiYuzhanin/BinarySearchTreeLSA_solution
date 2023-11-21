#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, int start, int end) {
    if (start > end) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[start]);

    int i;
    for (i = start; i <= end; i++) {
        if (preorder[i] > root->val) {
            break;
        }
    }

    root->left = buildTree(preorder, start + 1, i - 1);
    root->right = buildTree(preorder, i, end);

    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root->val > p && root->val > q) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p && root->val < q) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

string BinarySearchTreeLCA(string strArr[], int arrLength) {
    string strTree = strArr[0];
    int val1 = stoi(strArr[1]);
    int val2 = stoi(strArr[2]);

    string strNum;
    vector<int> preorder;
    for (int i = 0; i < strTree.length(); i++) {
        if (isdigit(strTree[i])) {
            strNum += strTree[i];
        }
        else if (strNum != "") {
            preorder.push_back(stoi(strNum));
            strNum = "";
        }
    }

    TreeNode* root = buildTree(preorder, 0, preorder.size() - 1);

    TreeNode* lca = lowestCommonAncestor(root, val1, val2);

    return to_string(lca->val);
}

vector<string> splitString(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << BinarySearchTreeLCA(A, arrLength);
  return 0;
    
}