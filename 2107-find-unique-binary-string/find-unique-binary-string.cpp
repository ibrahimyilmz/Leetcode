class Solution {
private:

public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        vector<int> decimal(1 << n, - 1);
        for (string num : nums) {
            int decimalValue = std::stoi(num, nullptr, 2);
            decimal[decimalValue] = decimalValue;
        }

        for (int i = 0; i < (1 << n); i++) {
            if (decimal[i] == -1) {
                // Convert i to an n-bit binary string
                // 1) Create a large bitset (64 bits for example)
                bitset<64> bits(i);
                // 2) Convert entire 64-bit to string
                string full = bits.to_string();  
                // 3) Extract the last 'n' bits
                return full.substr(64 - n);
            }
        }
        return "-1";
    }
};