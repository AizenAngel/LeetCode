class Solution {
public:
    
    void count_good_paths(TreeNode* root, int max, int& num){
        
        if(root == NULL){
            return;
        }
        
        if(root->val >= max){
            num++;
            max = root->val;
        }
        
        count_good_paths(root->left, max, num); 
        count_good_paths(root->right, max, num);
    }
    
    int goodNodes(TreeNode* root) {
        int max = root->val;
        int num = 0;
        
        count_good_paths(root, max, num);
        
        return num;
    }
};