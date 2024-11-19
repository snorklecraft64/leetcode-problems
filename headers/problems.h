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
     * or -1 if needle is not part of haystack.
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

    /**
     * Given a string, return true if it is a palindrome, false otherwise.
     * 
     * https://leetcode.com/problems/valid-palindrome/description/
     */
    static bool is_palindrome(const std::string& input);

    /**
     * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
     */
    static bool is_subsequence(const std::string& s, const std::string& t);

    /**
     * Given an array of numbers sorted in non-decreasing order,
     * find two numbers such that they add up to a specific target.
     * 
     * vv I am ignoring the "1-indexed" part vv
     * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
     */
    static std::pair<int,int> two_sum_2(const std::vector<int>& input, int target);

    /**
     * Given an array of line heights, find two lines that together form a container,
     * such that the container contains the most water.
     * 
     * Better thought of as which two lines make the largest area rectangle.
     * 
     * https://leetcode.com/problems/container-with-most-water/description/
     */
    static int max_water(const std::vector<int>& input);

    /**
     * Given an int array, return all triplets that add to 0
     * 
     * https://leetcode.com/problems/3sum/description/
     */
    static std::vector<std::vector<int>> three_sum(const std::vector<int>& input);

    /**
     * Given an int array, return the minimum possible size of a subarray
     * whose sum is greater than or equal to the given target. If no subarray
     * exists, return 0.
     * 
     * https://leetcode.com/problems/minimum-size-subarray-sum/description/
     */
    static int min_subarray_sum(const std::vector<int>& nums, int target);

    /**
     * Find the longest substring that has no repeating characters
     * 
     * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
     */
    static int longest_nonrepeating_substring(const std::string input);

    /**
     * Find first indices of all substrings that are a concatenation of all the given words in any order.
     * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab"
     * are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation
     * of any permutation of words.
     * 
     * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
     */
    static std::vector<int> concatenated_substrings(const std::string s, const std::vector<std::string> words);


};