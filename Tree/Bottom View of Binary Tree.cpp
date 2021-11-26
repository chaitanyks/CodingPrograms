
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        // int dis = 0;
        mp[0] = root->data;
        while(!q.empty())
        {
            Node * temp = q.front().first;
            int dis = q.front().second;
            // cout<<temp->data<<" "<<dis<<endl;
            q.pop();
            if(temp->left!=NULL)
            {
                q.push({temp->left,dis-1});
                mp[dis-1] = temp->left->data;
            }
            
            if(temp->right!=NULL)
            {
                q.push({temp->right,dis+1});
                mp[dis+1] = temp->right->data;
            }
        }
        
        for(auto itr: mp)
        {
            // cout<<itr.first<<" "<<itr.second<<endl;
            ans.push_back(itr.second);
        }
        return ans;
    }
};
