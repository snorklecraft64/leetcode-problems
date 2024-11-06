#include <vector>
#include <string>

class Problems {

  public:
    /**
     * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
     * 
     * You are giving candies to these children subjected to the following requirements:
     *
     * Each child must have at least one candy.
     * Children with a higher rating get more candies than their neighbors.
     *
     * Return the minimum number of candies you need to have to distribute the candies to the children.
     * 
     * https://leetcode.com/problems/candy/description/
     */
    static int candy(std::vector<int>& ratings);

    /**
     * Given n non-negative integers representing an elevation map where the width of each bar is 1,
     * compute how much water it can trap after raining.
     * 
     * https://leetcode.com/problems/trapping-rain-water/description/
     */
    static int trap_rainwater(std::vector<int>& input);

    /**
     * Given a roman numeral, convert it to an integer.
     * 
     * https://leetcode.com/problems/roman-to-integer/description/
     */
    static int roman_to_int(const std::string& input);

    /**
     * Given an integer, convert it to a Roman numeral.
     * 
     * https://leetcode.com/problems/integer-to-roman/description/
     */
    static std::string int_to_roman(int num);

    /**
     * Given a string consisting of words and spaces, return the length of the last word in the string.
     * 
     * https://leetcode.com/problems/length-of-last-word/description/
     */
    static int length_of_last_word(const std::string& input);

    /**
     * Find the longest common prefix string amongst an array of strings.
     * 
     * https://leetcode.com/problems/longest-common-prefix/description/
     */
    static std::string longest_common_prefix(const std::vector<std::string>& input);

    /**
     * Given an input string, reverse the order of the words.
     * 
     * Return a string of the words in reverse order concatenated by a single space.
     * 
     * Note that the string may contain leading or trailing spaces or multiple spaces between two words.
     * The returned string should only have a single space separating the words.
     * 
     * https://leetcode.com/problems/reverse-words-in-a-string/description/
     */
    static std::string reverse_words(const std::string& input);

    /**
     * Convert the string into a zig-zag pattern given the number of rows.
     * 
     * Example: input = "PAYPALISHIRING", numRows = 3
     * P   A   H   N
     * A P L S I I G
     * Y   I   R
     * So the final output would be "PAHNAPLSIIGYIR"
     * 
     * https://leetcode.com/problems/zigzag-conversion/description/
     */
    static std::string zigzag_conversion(const std::string& input, int numRows);

    /**
     * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
     * or -1 if needle is not part of haystack
     * 
     * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
     */
    static int needle_in_haystack(const std::string& haystack, const std::string& needle);


    /**
     * Given an array of strings words and a width maxWidth,
     * format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
     * 
     * https://leetcode.com/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150
     */
    static std::vector<std::string> full_justify(const std::vector<std::string>& words, int maxWidth);

};