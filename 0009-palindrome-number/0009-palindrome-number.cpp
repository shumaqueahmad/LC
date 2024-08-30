class Solution {
public:
    int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10; // Get the last digit
        x /= 10; // Remove the last digit

        // Check for overflow
        if (reversed > (std::numeric_limits<int>::max() - digit) / 10) {
            return 0; // Return 0 on overflow
        }

        reversed = reversed * 10 + digit; // Build the reversed number
    }

    return reversed;
}
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int y=reverse(x);
        if(x==y) return true;
        else return false;

        
    }
};
