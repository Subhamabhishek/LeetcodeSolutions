class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        for (int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++;//size mein lane ke liye -'a' kiye 
        }
        //find most frequent char
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
            if (hash[i]>max_freq){
                max_freq=hash[i];
                max_freq_char = i+'a'; // toh char milega as ham -'a' kiye the 
            }
        }
        int index=0;//changing string
        while(max_freq>0 && index<s.size()){ //jitna max freq thaa agar usse i+2 index pe place kar pa raha hun thn fine
        s[index] = max_freq_char; //-->i+'a'
        max_freq--;
        index=index+2; // so that char should not be at adjacent place 
        }

        if(max_freq != 0){
            return "";
        }   //gar bool nikal na thaa thn yahi tak code hota kyun ki agar ham max freq wale ko place kar denge thn baki ho jayega 

        hash[max_freq_char - 'a'] = 0;

        //lets place the rest of the char
        for(int i=0; i<26; i++){
            while(hash[i]>0){ //kab tak place karenge ?
                index= index>=s.size() ? 1:index;//jab tak index is greater than equals to s.size() then usse index 1 kar denge nehi to wahi se place karo  
                s[index] = i+'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};