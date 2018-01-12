//
// Created by 北條 育男 on 2017/06/02.
//

#ifndef SAMPLE_QT_SOUNDEX_H
#define SAMPLE_QT_SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex {
public:
  const size_t MAX_CODE_LENGTH{4};
  const std::string NOT_A_DIGIT{"*"};

  std::string encode(const std::string &word) const {
    return zero_pad(upper_front(head(word)) + tail(encoded_digits(word)));
  }

private:
  std::string upper_front(const std::string &word) const {
    return std::string(1, std::toupper(word.front()));
  }
  std::string head(const std::string &word) const {
    return word.substr(0, 1);
  }
  std::string tail(const std::string &word) const {
    return word.substr(1);
  }
  std::string encoded_digits(const std::string &word) const {
    std::string encoding;
    encode_head(encoding, word);
    encode_tail(encoding, word);
    return encoding;
  }
  void encode_head(std::string &encoding, const std::string &word) const {
    encoding += encoded_digit(word.front());
  }
  void encode_tail(std::string &encoding, const std::string &word) const {
    for (auto i = 1u; i < word.length(); i++) {
      if (!is_complete(encoding)) encode_letter(encoding, word[i], word[i - 1]);
    }
  }
  void encode_letter(std::string &encoding, char letter, char last_letter) const {
    auto digit = encoded_digit(letter);
    if (digit != NOT_A_DIGIT
        && (digit != last_digit(encoding) || is_vowel(last_letter))) {
      encoding += digit;
    }
  }
  bool is_complete(const std::string &encoding) const {
    return encoding.length() == MAX_CODE_LENGTH;
  }
  std::string last_digit(const std::string &encoding) const {
    if (encoding.empty()) return NOT_A_DIGIT;
    return std::string(1, encoding.back());
  }
  bool is_vowel(char letter) const {
    return std::string("aeiouy").find(lower(letter)) != std::string::npos;
  }
  std::string encoded_digit(char letter) const {
    const std::unordered_map<char, std::string> encodings {
      {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
      {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
      {'d', "3"}, {'t', "3"},
      {'l', "4"},
      {'m', "5"}, {'n', "5"},
      {'r', "6"}
    };
    auto it = encodings.find(lower(letter));
    return it == encodings.end() ? NOT_A_DIGIT : it->second;
  }
  char lower(char c) const {
    return std::tolower(c);
  }
  std::string zero_pad(const std::string &word) const {
    auto zeros_needed = MAX_CODE_LENGTH - word.length();
    return word + std::string(zeros_needed, '0');
  }
};

#endif //SAMPLE_QT_SOUNDEX_H
