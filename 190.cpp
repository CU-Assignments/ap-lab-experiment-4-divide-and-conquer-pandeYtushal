class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;       // Extract the least significant bit
            result = (result << 1) | bit; // Append the bit to the result
            n = n >> 1;           // Right-shift n to process the next bit
        }
        return result;
    }
};



Input: 00000010100101000001111010011100
  Output:    964176192 (00111001011110000010100101000000)
