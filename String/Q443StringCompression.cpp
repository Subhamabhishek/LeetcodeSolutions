class Solution {
public:

//TWO POINTER APPROACH//

    int compress(vector<char>& s) {
        int index=0; // to store new char and count
        int count=1;//initially all char count is 1
        int prev = s[0];
        
        for(int i=1; i<s.size(); i++){
            if(s[i] == prev){
                count++;
            }
            else{
                s[index++]=prev;
                if(count > 1){
                    int start = index;
                    while(count){
                        s[index++] = (count % 10) +'0';
                        count /= 10;
                    }
                    reverse(s.begin()+start, s.begin()+index);
                }
                prev = s[i];
                count = 1;
            }
        }
        s[index++] = prev;
        if(count > 1){
            int start = index;
            while(count){
                s[index++] = (count % 10) +'0';
                count /= 10;
            }
            reverse(s.begin()+start, s.begin()+index);
        }
        return index;
    }
};