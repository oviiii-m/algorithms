#include <iostream>
using namespace std;
#include<queue>
#include<climits>
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};
template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
BinaryTreeNode<int>* takeinput()
{
    int rootdata;
    cout << "Enter root data: ";
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftchild;
        cout << "Enter left child of " << front->data << ": ";
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int>* lchild = new BinaryTreeNode<int>(leftchild);
            front->left = lchild;
            q.push(lchild);
        }
        int rightchild;
        cout << "Enter right child of " << front->data << ": ";
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int>* rchild = new BinaryTreeNode<int>(rightchild);
            front->right = rchild;
            q.push(rchild);
        }
    }
    return root;
}

//isBst   approach 1    time Complexity=O(n*h) h=height of tree which is bad
int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root){
    if(root==NULL)
        return true;
    int leftmax=maximum(root->left);
    int rightmin=minimum(root->right);
    bool output=root->data>leftmax&&root->data<rightmin&&isBST(root->left)&&isBST(root->right);
    return output;
}
// isBST approach2 time Complexity=O(n)  we will use pair class
class IsBSTReturn {
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
        leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}

//isBST approach 3   we apply i.e constraints to our root i.e root Range=(-infin,+infin),root->left Range=(-infin,root->data-1),root->right Range=(root->data,+infin)
bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data<min || root->data>max)
        return false;
    bool isLeft = isBST3(root->left,min,root->data-1);
    bool isRight = isBST3(root->right,root->data,max);
    return isLeft && isRight;
}

//Construct BST from sorted Array;
BinaryTreeNode<int>* ConstructBST(int* input, int si, int ei)
{
    if (si > ei)
        return NULL;
    int mid = (si + ei) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root->left = ConstructBST(input, si, mid - 1);
    root->right = ConstructBST(input, mid + 1, ei);
    return root;

}

//BST to Sorted LL
Node<int>* ConstructLL(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        Node<int>* output = new Node<int>(root->data);
        return output;
    }
    Node<int>* r = new Node<int>(root->data);
    Node<int>* lhead = ConstructLL(root->left);
    Node<int>* temp = lhead;
    if (lhead != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = r;
    }
    r->next = ConstructLL(root->right);
    if (lhead == NULL)
        return r;
    else return lhead;
}

//Find Path in BST
vector<int>* findPath(BinaryTreeNode<int>* root, int data) {
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    if (root->data > data)
    {
        vector<int>* leftoutput = findPath(root->left, data);
        if (leftoutput != NULL)
            leftoutput->push_back(root->data);
        return leftoutput;
    }
    else if (root->data < data)
    {
        vector<int>* rightoutput = findPath(root->right, data);
        if (rightoutput != NULL)
            rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
    {
        return NULL;
    }

}
// 9 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = takeinput();
    cout << endl;
    cout <<isBST3(root);
}

