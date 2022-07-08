class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
     int x=0;
        for(auto ele : operations)
        {
            if(ele[0] == '+') ++x;
            else if(ele[0] == '-') --x;
            else if(ele[0] == 'X' && ele[1] == '+') x++;
            else x--;
        }
        
        return x;
    }
};