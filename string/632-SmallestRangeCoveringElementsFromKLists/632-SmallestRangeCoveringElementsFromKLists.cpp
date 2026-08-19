// Last updated: 19/08/2026, 15:59:01
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<node* ,vector<node*>,compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int k = nums.size();
        for(int i=0; i<k; ++i){
            int el = nums[i][0];
            mini = min(mini,el);
            maxi = max(maxi,el);
            pq.push(new node(el,i,0));
        }
        int start = mini, end = maxi;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }else if(maxi - mini == end - start && mini < start){
                start = mini;
                end = maxi;
            }
            if(temp->col + 1 < nums[temp->row].size()){
                maxi = max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};