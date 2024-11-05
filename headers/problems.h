#include <vector>
#include <string>

class Problems {

  public:
    static int candy(std::vector<int>& ratings);
    static int trap_rainwater(std::vector<int>& input);
    static int roman_to_int(const std::string& input);
    static std::string int_to_roman(int num);
    static int length_of_last_word(const std::string& input);
    static std::string longest_common_prefix(const std::vector<std::string>& input);
    static std::string reverse_words(const std::string& input);
    static std::string zigzag_conversion(const std::string& input, int numRows);
    static int needle_in_haystack(const std::string& haystack, const std::string& needle);


};