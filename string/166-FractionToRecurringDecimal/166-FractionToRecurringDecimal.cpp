// Last updated: 19/08/2026, 16:06:20
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         if (numerator == 0) return "0";

    string result;

    // handle sign
    if ((numerator < 0) ^ (denominator < 0)) 
        result.push_back('-');

    // absolute values
    long long num = llabs(numerator);
    long long den = llabs(denominator);

    // integer part
    result += to_string(num / den);
    long long remainder = num % den;

    if (remainder == 0) 
        return result;

    result.push_back('.');

    // map remainder -> position in result
    unordered_map<long long, int> remainderIndex;
    
    while (remainder != 0) {
        if (remainderIndex.count(remainder)) {
            // insert '(' at the index where this remainder first appeared
            result.insert(remainderIndex[remainder], "(");
            result.push_back(')');
            break;
        }

        remainderIndex[remainder] = result.size();
        remainder *= 10;
        result += to_string(remainder / den);
        remainder %= den;
    }

    return result;
    }
};