class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
            return !std::isalnum(c); // Remove if not alphanumeric
        }), s.end());
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            char chLeft = s[left];
            char chRight = s[right];
            
            if (chLeft != chRight) return false;
            left++;
            right--;
        }
        return true;
    }
};