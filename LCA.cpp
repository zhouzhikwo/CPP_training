#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

class TreeNode
{
  public:
    int Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(int val = 1) : Val(val), Left(NULL), Right(NULL) {}
    ~TreeNode() {}

    void Add(TreeNode *child)
    {
        if (this->Left == NULL)
            this->Left = child;
        else
            this->Right = child;
        return;
    }
    int getVal() const { return this->Val; }
    void setVal(int val = 1)
    {
        this->Val = val;
        return;
    }
    friend TreeNode *getNode(TreeNode *root, TreeNode *v1, TreeNode *v2);
    friend int getNum(TreeNode *root);
};

TreeNode *getNode(TreeNode *root, TreeNode *v1, TreeNode *v2)
{
    if (root == NULL || root == v1 || root == v2)
        return root;
    TreeNode *Left = getNode(root->Left, v1, v2);
    TreeNode *Right = getNode(root->Right, v1, v2);
    if (Left != NULL && Right != NULL)
        return root;
    else if (Left != NULL)
        return Left;
    return Right;
}

int getNum(TreeNode *root)
{
    int n = 0;
    if (root == NULL)
        return n;
    int nl = getNum(root->Left);
    int nr = getNum(root->Right);
    n = nl + nr + 1;
    return n;
}

int main()
{
    ifstream fin("sample_input.txt");
    ofstream fout("sample_output_test.txt");
    int Num;
    fin >> Num;
    for (int n = 1; n <= Num; n++)
    {
        int nPt, nLine, v1, v2;
        fin >> nPt >> nLine >> v1 >> v2;
        vector<TreeNode> arr(nPt + 1);
        for (int i = 0; i <= nPt; i++)
            arr[i].setVal(i);
        int e1, e2;
        while (nLine--)
        {
            fin >> e1 >> e2;
            arr[e1].Add(&arr[e2]);
        }
        TreeNode *Rlt = getNode(&arr[1], &arr[v1], &arr[v2]);
        int nRlt = getNum(Rlt);
        fout << "#" << Num << ' ' << Rlt->getVal() << ' ' << nRlt << endl;
    }

    system("pause");
    return 0;
}
