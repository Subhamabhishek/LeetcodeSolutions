class Solution {
public:

    static bool mycomp(string a,string b){
        string t1=a + b; //string addition not int so '3'+'30' is '330' not 33
        string t2=b + a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n:nums){
            snums.push_back(to_string(n)); //converted to string
        }

        sort(snums.begin(), snums.end(), mycomp);
        if(snums[0]=="0") return "0";
        string ans="";
        for(auto str:snums){
            ans+=str;
        }
        return ans;
    }
};