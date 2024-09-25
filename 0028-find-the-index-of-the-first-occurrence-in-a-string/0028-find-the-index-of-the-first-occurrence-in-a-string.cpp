class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // If needle is empty, return 0  
    if (needle.empty()) {  
        return 0;  
    }  

    // Get lengths of haystack and needle  
    int haystackLength = haystack.length();  
    int needleLength = needle.length();  

    // If the needle is longer than the haystack, it can't be found  
    if (needleLength > haystackLength) return -1;  

    // Loop through the haystack  
    for (int i = 0; i <= haystackLength - needleLength; ++i) {  
        // Check if the substring matches needle  
        if (haystack.substr(i, needleLength) == needle) {  
            return i;  // Return the starting index  
        }  
    }  
    
    return -1;
    }
};