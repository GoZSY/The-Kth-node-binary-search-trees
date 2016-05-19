/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot)
        { 
            TreeNode *ret = KthNode(pRoot->left, k);
            if(ret) return ret;//为了可以逐层的返回
            if(++count == k) return pRoot;
            ret = KthNode(pRoot->right,k);
            if(ret) return ret;//为了可以逐层的返回
        }
        return NULL;
    }
};

/*********************************************************
更好理解的代码
**********************************************************/

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
  TreeNode *tr=NULL;
  unsigned int count =0;
  KthNode1(pRoot,&tr,count,k);
  return tr;
    }
 void KthNode1(TreeNode* pRoot, TreeNode** tr,unsigned int &count,unsigned int k)
 {
  if(pRoot==NULL)
   return ;
  KthNode1(pRoot->left,tr,count,k);
  count++;
  if(k==count)
  {
   *tr=pRoot;
   return;
  }
  KthNode1(pRoot->right,tr,count,k);
 }
};
