class Solution {
public:
      //for encoding converting llist of string into format like lenght of word then ,
      // after reading all word length then add # then all characters of words
      // 4,3,5,#anasabdalyan
    string encode(vector<string>& strs) {
     if (strs.empty()) return "";
     string result; 
     for(string& str:strs)
     { 
     result += to_string(str.length()); 
     result += ","; 
     } 
     result += "#"; 
     for(string& str :strs)
     {
       result += str;
      } 
     return result; 
     }
   //for decoding same like reading string from start and count ther=ir words size then make 
   //list of strings using substring of sizes
    vector<string> decode(string s) {
        if(s.empty()) return {};
       vector <int> sizes;
       vector<string> result;
       int i=0;
       while(s[i] != '#'){
        int j = i;
          while(s[j] != ','){
             j++;
          }
          sizes.push_back(stoi(s.substr(i,j-i)));
          i=j+1;
       }
       i++;
       for(int sz : sizes){
        result.push_back(s.substr(i,sz));
        i+=sz;
       }
       return result;
    }
};















