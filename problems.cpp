#include "problems.h"
#include "utilities.h"
#include <iostream>
#include <sstream>

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
  while (input[i] == ' ')
    i--;
  int count = 0;
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
  int i = 0;
  int j = 0;
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
  std::istringstream inputStream(input);
  std::vector<std::string> words;
  for (std::string buffer; inputStream >> buffer; ) {
    words.push_back(buffer);
  }
  if (words.size() == 0)
    return "";
  std::string result;
  for (int i = words.size()-1; i >= 0; i--) {
    result.append(words[i] + " ");
  }
  result.pop_back();
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

// find first occurence given string "needle" in "haystack"
// returns -1 if none found
int Problems::needle_in_haystack(const std::string& haystack, const std::string& needle) {
  int i = 0;
  int j = 0;
  int index = -1;
  while (i < haystack.size()) {
    if (haystack[i] == needle[j]) {
      index = i;
      i++; j++;
      while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] != needle[j])
          break;
        i++; j++;
      }
      if (j == needle.size())
        break;
      else {
        index = -1;
        j = 0;
      }
    }
    else {
      i++;
    }
  }
  return index;
}










