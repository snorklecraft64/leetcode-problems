#include "problems.h"
#include "utilities.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

/*
CHECK HEADER FILE FOR PROBLEM DESCRIPTIONS

Not much argument validation is done in these methods
because part of leetcodes problem descriptions usually
says that the input is guarenteed to be a certain way

#--Erik Warling--#
*/

/**
 * Go through left to right, then right to left.
 * If current child has higher rating than last,
 * make sure they have one more candy than them
 */
int Problems::candy(std::vector<int>& ratings) {
  std::vector<int> candies(ratings.size(), 1);
  for (int i = 1; i < ratings.size(); i++) {
    if (ratings[i] > ratings[i-1]) {
      candies[i] = candies[i-1] + 1;
    }
  }
  for (int i = ratings.size()-2; i >= 0; i--) {
    if (ratings[i] > ratings[i+1]
        && candies[i] <= candies[i+1]) {
      candies[i] = candies[i+1] + 1;
    }
  }
  return Utilities::sumVector(candies);
}

int Problems::trap_rainwater(std::vector<int>& input) {
  std::vector<int> maxLeft;
  std::vector<int> maxRight(input.size());

  // Build maxLeft and maxRight, which stores the max size of walls on either side of a given index
  int max = 0;
  for (auto& num : input) {
    maxLeft.push_back(max);
    if (num > max)
      max = num;
  }
  max = 0;
  for (int i = input.size()-1; i >= 0; i--) {
    maxRight[i] = max;
    if (input[i] > max)
      max = input[i];
  }

  // At a given index, the amount of rainwater it holds
  // is determined by the shortest of left or right walls
  // minus the height at that index
  int count = 0;
  for (int i = 0; i < input.size(); i++) {
    int height = std::min(maxLeft[i], maxRight[i]);
    if (height > input[i])
      count += height - input[i];
  }
  return count;


  // brute force method
  //int totalRain = 0;
  //int i = 0;
  //while (i < input.size()) {
  //  int j = i+1;
  //  int toAdd = 0;
  //  while (j < input.size() && input[i] > input[j]) {
  //    toAdd += (input[i] - input[j]);
  //    j++;
  //  }
  //  if (j < input.size()) {
  //    totalRain += toAdd;
  //    i = j;
  //  }
  //  else
  //    i++;
  //}
  //return totalRain;
}

int Problems::roman_to_int(const std::string& input) {
  int total = 0;
  int i = input.size()-1;
  // go through right to left
  // if encounter a double, i subtracted twice
  while (i > 0) {
    char currChar = input[i];
    char nextChar = input[i-1];
    if (currChar == 'I')
      total++;
    else if (currChar == 'V') {
      if (nextChar == 'I'){
        total += 4;
        i--;
      }
      else
        total += 5;
    }
    else if (currChar == 'X') {
      if (nextChar == 'I'){
        total += 9;
        i--;
      }
      else
        total += 10;
    }
    else if (currChar == 'L') {
      if (nextChar == 'X'){
        total += 40;
        i--;
      }
      else
        total += 50;
    }
    else if (currChar == 'C') {
      if (nextChar == 'X'){
        total += 90;
        i--;
      }
      else
        total += 100;
    }
    else if (currChar == 'D') {
      if (nextChar == 'C'){
        total += 400;
        i--;
      }
      else
        total += 500;
    }
    else if (currChar == 'M') {
      if (nextChar == 'C'){
        total += 900;
        i--;
      }
      else
        total += 1000;
    }
    i--;
  }

  // i == 0 when left-most character is not part of a double
  if (i == 0) {
    switch(input[0]) {
      case 'M':
        total += 1000;
        break;
      case 'D':
        total += 500;
        break;
      case 'C':
        total += 100;
        break;
      case 'L':
        total += 50;
        break;
      case 'X':
        total += 10;
        break;
      case 'V':
        total += 5;
        break;
      case 'I':
        total++;
    }
  }

  return total;
}

std::string Problems::int_to_roman(int num) {
  std::string result = "";
  while (num >= 1000) {
    result += "M";
    num -= 1000;
  }
  if (num >= 100) {
    if (num % 900 < num) {
      result += "CM";
      num -= 900;
    }
    else if (num % 500 < num) {
      result += "D";
      num -= 500;
    }
    else if (num % 400 < num) {
      result += "CD";
      num -= 400;
    }
    while (num >= 100) {
      result += "C";
      num -= 100;
    }
  }
  if (num >= 10) {
    if (num % 90 < num) {
      result += "XC";
      num -= 90;
    }
    else if (num % 50 < num) {
      result += "L";
      num -= 50;
    }
    else if (num % 40 < num) {
      result += "XL";
      num -= 40;
    }
    while (num >= 10) {
      result += "X";
      num -= 10;
    }
  }
  if (num > 0) {
    if (num % 9 < num) {
      result += "IX";
      num -= 9;
    }
    else if (num % 5 < num) {
      result += "V";
      num -= 5;
    }
    else if (num % 4 < num) {
      result += "IV";
      num -= 4;
    }
    while (num > 0) {
      result += "I";
      num -= 1;
    }
  }
  return result;
}

int Problems::length_of_last_word(const std::string& input) {
  int i = input.size()-1;
  // go right to left until first non-space character
  while (input[i] == ' ')
    i--;
  int count = 0;
  // count right to left until next space character, or beginning of string
  while (i >= 0 && input[i] != ' ') {
    count++;
    i--;
  }
  return count;
}

std::string Problems::longest_common_prefix(const std::vector<std::string>& input) {
  if (!input.size())
    return "";
  if (!input[0].size())
    return "";
  
  char currChar = input[0][0];
  std::string result;
  int i = 1; // index into vector
  int j = 0; // index into strings
  // checks if jth index of all strings is the same
  // if it is, then add it to result and start from beginning of vector again
  while (j < input[i].size() && input[i][j] == currChar) {
    i++;
    if (i == input.size()) {
      j++;
      i = 0;
      result += currChar;
      if (j >= input[i].size()) {
        break;
      }
      currChar = input[i][j];
    }
  }
  return result;
}

std::string Problems::reverse_words(const std::string& input) {
  if (input.empty())
    return "";
  
  // seperate out words from input
  std::istringstream inputStream(input);
  std::vector<std::string> words;
  for (std::string buffer; inputStream >> buffer; ) {
    words.push_back(buffer);
  }

  if (words.size() == 0)
    return "";
  
  // append all words in reverse order
  // by starting from back of vector and working towards the front
  std::string result;
  for (int i = words.size()-1; i >= 0; i--) {
    result.append(words[i] + " ");
  }
  result.pop_back(); // get rid of extraneous space
  return result;
}

std::string Problems::zigzag_conversion(const std::string& input, int numRows) {
  char arr[numRows][(input.size()/2)+1] = {0};
  // really stupid loop as a workaround for wierd issue where above statement does not actually set first row to 0
  for (int m = 0; m < (input.size()/2)+1; m++) {
    arr[0][m] = 0;
  }

  int i = 0;
  int j = 0;
  int index = 0;
  bool zig = true;
  while (index < input.size()) {
    arr[i][j] = input[index];
    index += 1;
    if (zig) {
      if (i < numRows - 1) {
        i++;
      }
      else {
        i--;
        j++;
        zig = false;
      }
    }
    else {
      if (i > 0) {
        i--;
        j++;
      }
      else {
        i++;
        zig = true;
      }
    }
  }

  std::string result;
  for (int n = 0; n < numRows; n++) {
    for (int m = 0; m < (input.size()/2)+1; m++) {
      if (arr[n][m] != '\0')
        result += arr[n][m];
    }
  }
  return result;
}

int Problems::needle_in_haystack(const std::string& haystack, const std::string& needle) {
  int i = 0;
  int index = -1;
  while (i < haystack.size()) {
    if (haystack[i] == needle[0]) {
      // if we find the first index of needle in haystack,
      // keep going with subsequent indexes
      index = i;
      i++;
      int j = 1;
      while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] != needle[j])
          break;
        i++; j++;
      }
      // if we cound the whole needle, the index is correct and can return
      if (j == needle.size())
        break;
      // otherwise, index is not correct, return to original loop
      else {
        index = -1;
      }
    }
    else {
      i++;
    }
  }
  return index;
}

/**
 * helper function that adds spaces needed to justify and returns the full line
 */
std::string justify_line(std::vector<std::string>& currWords, int currCount, int maxWidth) {
  int spacesNeeded = maxWidth - currCount;
  if (currWords.size() > 1) {
    // regardless of spaces needed, we need a space between each word in the first place
    for (int i = 0; i < currWords.size()-1; i++) {
      currWords[i] += " ";
    }
    int j = 0; // index in currWords to add to
    // add spaces to end of words (except last) until we have all the spaces we need
    for (int i = 0; i < spacesNeeded; i++) {
      if (j == currWords.size()-1) {
        j = 0;
      }
      currWords[j] += " ";
      j++;
    }
    // combine words together and add to justified result
    std::string line;
    for (int i = 0; i < currWords.size(); i++) {
      line += currWords[i];
    }
    return line;
  }
  else {
    // if only one word, just add spaces needed to end
    for (int i = 0; i < spacesNeeded; i++) {
      currWords[0] += " ";
    }
    return currWords[0];
  }
}

std::vector<std::string> Problems::full_justify(const std::vector<std::string>& words, int maxWidth) {
  int currCount = 0;
  std::vector<std::string> justified;


  std::vector<std::string> currWords; // words in current line
  std::string word = words[0];
  currWords.push_back(word);
  currCount += word.size(); // how many chars in current line
  for (int i = 1; i < words.size(); i++) {
    word = words[i];
    // if word won't fit in current line, justify it and add to result
    if (currCount + word.size() + 1 > maxWidth) { // +1 is for the space 
      
      justified.push_back(justify_line(currWords, currCount, maxWidth));

      currWords.clear();
      currWords.push_back(word);
      currCount = word.size();
    }
    else {
      currWords.push_back(word);
      currCount += word.size() + 1;
    }
  }

  // add remaining words to result (left justified)
  std::string line = currWords[0];
  for (int i = 1; i < currWords.size(); i++) {
    line += " " + currWords[i];
  }

  // add spaces at end
  while (line.size() < maxWidth)
    line += " ";

  justified.push_back(line);

  return justified;
}

bool Problems::is_palindrome(const std::string& input) {
  // first convert to only alphanumeric characters in lowercase
  std::string cleaned;
  for (auto ch : input) {
    if (std::isalpha(ch)) {
      if (std::isupper(ch))
        cleaned += std::tolower(ch);
      else
        cleaned += ch;
    }
  }

  // go through cleaned forward and backward at same time to check if match
  int i = 0;
  int j = cleaned.size() - 1;
  bool palindrome = true;
  while (i < cleaned.size()) {
    if (cleaned[i] != cleaned[j]) {
      palindrome = false;
      break;
    }

    i++;
    j--;
  }

  return palindrome;
}

bool Problems::is_subsequence(const std::string& s, const std::string& t) {
  int i = 0; // index into t
  int j = 0; // index into s
  // go through all of t until all of s is found (in order)
  while (i < t.size()) {
    if (s[j] == t[i]) {
      j++;
      if (j >= s.size())
        break;
    }
    else {
      i++;
    }
  }

  // if j is greater or equal to s.size(), it means all chars of s were found
  return j >= s.size();
}

/**
 * start by adding first and last elements together
 * if too small, increase left index; if too big, decrease right index
 * since part of problem description guarantees there is an answer, eventually it will be found
 */
std::pair<int,int> Problems::two_sum_2(const std::vector<int>& input, int target) {
  int leftIndex = 0;
  int rightIndex = input.size()-1;

  int sum = input[leftIndex] + input[rightIndex];
  while (sum != target) {
    if (sum > target)
      rightIndex--;
    else
      leftIndex++;
    sum = input[leftIndex] + input[rightIndex];
  }

  return std::pair<int,int>(leftIndex,rightIndex);
}

int Problems::max_water(const std::vector<int>& input)  {
  int leftIndex = 0;
  int rightIndex = input.size()-1;

  // smaller height of the two times difference gives area
  int max = std::min(input[leftIndex],input[rightIndex]) * (rightIndex-leftIndex);
  int currArea, left, right, diff;
  while (leftIndex != rightIndex) {
    left = input[leftIndex];
    right = input[rightIndex];
    diff = (rightIndex-leftIndex);

    // advance smaller height because this is the largest rectangle it can make
    if (left < right) {
      currArea = left * diff;
      leftIndex++;
    }
    else {
      currArea = right * diff;
      rightIndex--;
    }

    if (currArea > max)
      max = currArea;
  }

  return max;
}

std::vector<std::vector<int>> Problems::three_sum(const std::vector<int>& input) {
  std::vector<int> nums = input;
  std::vector<std::vector<int>> triplets;

  // sort array in non-decreasing order
  std::sort(nums.begin(), nums.end());

  int sum, leftIndex, rightIndex, target, twosum;
  // go through every num except last 2
  for (int i = 0; i < nums.size()-2; i++) {
    // do two sum starting at i+1 with target -nums[i]
    // code more-or-less copied from two_sum_2 method above
    // calling it would mean making a whole new vector, so this is faster
    // also there is not guarenteed to be an answer this time
    leftIndex = i+1;
    rightIndex = nums.size()-1;
    target = -nums[i];

    twosum = nums[leftIndex] + nums[rightIndex];
    // added "leftIndex != rightIndex" because there is not guarenteed to be an answer
    // so we need to stop when we've tried all combinations
    while (twosum != target && leftIndex != rightIndex) {
      if (twosum > target)
        rightIndex--;
      else
        leftIndex++;
      twosum = nums[leftIndex] + nums[rightIndex];
    }

    // if triplet was found, add to solutions
    // if leftIndex and rightIndex aren't equal, it means two sum found a solution
    if (leftIndex != rightIndex)
      triplets.push_back(std::vector<int>({nums[i], nums[leftIndex], nums[rightIndex]}));
  }

  return triplets;
}

int Problems::min_subarray_sum(const std::vector<int>& nums, int target) {
  // if nums is only one number, that number needs to be greater than or equal
  // to target or else there is no subarray
  if (nums.size() == 1) {
    if (nums[0] >= target)
      return 1;
    else
      return 0;
  }

  // perform a 'sliding window' approach starting with first two nums
  int leftIndex = 0;
  int rightIndex = 1;
  int currSum = nums[0] + nums[1];
  int min = nums.size() + 1;

  while (true) {
    // if currSum is greater or equal, then we need to make window smaller
    if (currSum >= target) {
      if (rightIndex - leftIndex + 1 < min)
        min = rightIndex - leftIndex + 1;
      
      currSum = currSum - nums[leftIndex];
      leftIndex++;

      // if we can't make window smaller, then we've already found minimum
      if (leftIndex > rightIndex)
        break;
    }
    // if currSum is lesser, then we need to make window bigger
    else {
      rightIndex++;

      // if we're at end we can't make window bigger
      if (rightIndex >= nums.size())
        break;
      
      currSum += nums[rightIndex];
    }
  }

  // if min never changed, we never found an answer
  if (min == nums.size() + 1)
    return 0;

  return min;
}

int Problems::longest_nonrepeating_substring(const std::string input) {
  // if string is empty, no substrings exist so answer is 0
  if (input.size() == 0)
    return 0;
  // if string is only one character, answer is trivially 1
  else if (input.size() == 1)
    return 1;

  // perform sliding window approach starting with first two characters
  int leftIndex = 0; // index of left side of window
  int rightIndex = 1; // index of right side of window + 1
  int max = 1;
  std::unordered_set<char> chars; // set of chars in current substring
  chars.insert(input[0]);
  while (true) {
    // if char to add is already in substring, don't increase max
    // and reduce sliding window on left side
    if (chars.find(input[rightIndex]) != chars.end()) {
      chars.erase(input[leftIndex]);
      leftIndex++;
      if (leftIndex >= input.size())
        break;
    }
    // if char not in substring already, update max accordingly
    // and increase window on right side
    else {
      chars.insert(input[rightIndex]);
      if (chars.size() > max)
        max = chars.size();
      rightIndex++;
      if (rightIndex >= input.size())
        break;
    }
  }

  return max;
}

// improved version that is maybe easier to understand
// Using a "sliding window" approach, we examine all possible substrings and determine
// whether or not they have the right number of words from the input list.
// Done by keeping a count of how many times each word from the list appears
// and updating it as we slide the window along
std::vector<int> concatenated_substrings_improved(const std::string s, const std::vector<std::string> words) {
  // make a map of the word to how many times we can use paired with how many times we have
  // first is how many times we can use it, second is how many times we have
  std::unordered_map<std::string, std::pair<int,int>> word_map;
  for (auto word : words) {
    // if already in word_map, increase its max count
    if (word_map.find(word) != word_map.end())
      word_map[word].first++;
    else
      word_map.insert({word, std::pair<int,int>(1,0)});
  }

  std::vector<int> result;
  // since every word is same length (given in problem statement),
  // we just scan every word length in the string and compare it to word list
  int n = words[0].size();
  int leftIndex = 0; // left side of sliding window
  int rightIndex = 0; // right side of sliding window
  std::string currWord;
  while (rightIndex < s.size()) {
    currWord = s.substr(rightIndex, n);

    // if word not in list of words, no substring with this word is an answer
    // so we move the window past it by moving beginning to the end
    if (word_map.find(currWord) == word_map.end()) {
      rightIndex += n;
      leftIndex = rightIndex;
      for (auto ele : word_map) {
        word_map[ele.first].second = 0;
      }
    }
    // if word is in words
    else {
      word_map[currWord].second++;

      // if word is already in substring enough times
      if (word_map[currWord].second > word_map[currWord].first) {
        // shorten beginning of window until we remove an earlier word
        do {
          word_map[s.substr(leftIndex, n)].second--;
          leftIndex += n;
        } while (word_map[currWord].second > word_map[currWord].first);
      }
      // if substring is large enough, add to answer set
      else if (rightIndex + n - leftIndex == n * words.size()) {
        result.push_back(leftIndex);
        word_map[s.substr(leftIndex,n)].second--;
        leftIndex += n;
      }

      rightIndex += n;
    }
  }

  return result;
}

std::vector<int> Problems::concatenated_substrings(const std::string s, const std::vector<std::string> words) {
  return concatenated_substrings_improved(s, words);

  // everything below is deprecated
  // still works but is a little esoteric

  // make a map of the word to how many times we can use paired with how many times we have
  // first is how many times we can use it, second is how many times we have
  std::unordered_map<std::string, std::pair<int,int>> word_map;
  for (auto word : words) {
    // if already in word_map, increase its max count
    if (word_map.find(word) != word_map.end())
      word_map[word].first++;
    else
      word_map.insert({word, std::pair<int,int>(1,0)});
  }

  std::vector<int> result;
  // since every word is same length (given in problem statement),
  // we just scan every word length in the string and compare it to word list
  int n = words[0].size();
  std::string currWord;
  int currIndex = 0;
  int answerIndex = 0;
  int totalWords = 0;
  // count words seen in s consecutively, answer is found when enough consecutive words are found
  while (currIndex < s.size()) {
    currWord = s.substr(currIndex, n);

    // if word not in words, reset counters
    if (word_map.find(currWord) == word_map.end()) {
      totalWords = 0;
      for (auto ele : word_map) {
        word_map[ele.first].second = 0;
      }
      answerIndex = currIndex + n;
    }
    // if word in words, add to counter
    else {
      word_map[currWord].second++;
      totalWords++;

      // if counter now too high, keep removing words at beginning of substring until count is good again
      if (word_map[currWord].second > word_map[currWord].first) {
        do {
          word_map[s.substr(answerIndex, n)].second--;
          answerIndex += n;
          totalWords--;
        } while (word_map[currWord].second > word_map[currWord].first);
      }
      // if count is good and we have enough words, add it to result and go on to next word
      else if (totalWords == words.size()){
        result.push_back(answerIndex);
        word_map[s.substr(answerIndex, n)].second--;
        answerIndex += n;
        totalWords--;
      }
    }

    currIndex += n;
  }

  return result;
}

std::string Problems::min_window_substring(const std::string s, const std::string t) {
  // make a map of the chars in t to how many times we can use paired with how many times we have
  // first is how many times we can use it, second is how many times we have
  std::unordered_map<char, std::pair<int,int>> char_map;
  for (auto ch : t) {
    // if already in word_map, increase its max count
    if (char_map.find(ch) != char_map.end())
      char_map[ch].first++;
    else
      char_map.insert({ch, std::pair<int,int>(1,0)});
  }

  // do a sliding window approach to find all substrings that have all chars
  int leftIndex = 0;
  int rightIndex = 0;
  int answerLeft = 0;  // left index of final answer
  int answerRight = s.size(); // right index of final answer
  int totalCount = 0;
  char currChar;
  while (rightIndex < s.size()) {
    currChar = s[rightIndex];

    // if char in t
    if (char_map.find(currChar) != char_map.end()) {
      // increase count
      char_map[currChar].second++;
      // if we have more of this char than needed, don't increase total count
      if (char_map[currChar].second <= char_map[currChar].first)
        totalCount++;
    }

    // when we find a substring that has all chars,
    // keep shrinking window on left side until we no longer have all the chars we need
    while (totalCount >= t.size()) {
      // if length is smaller than current answer, replace answer
      if (rightIndex - leftIndex < answerRight - answerLeft) {
        answerRight = rightIndex;
        answerLeft = leftIndex;
      }

      // reduce window on left side until the next char that appears in t
      char_map[s[leftIndex]].second--;
      // if we now have less of this char than needed, decrease total count
      if (char_map[s[leftIndex]].second < char_map[s[leftIndex]].first)
        totalCount--;
      leftIndex++;
      while (char_map.find(s[leftIndex]) == char_map.end()) {
        leftIndex++;
      }
    }

    rightIndex++;
  }

  // if answerRight is still s.size(), no substring was found
  if (answerRight == s.size())
    return "";

  return s.substr(answerLeft, answerRight-answerLeft+1);
}







