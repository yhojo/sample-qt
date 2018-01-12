//
// Created by 北條 育男 on 2017/06/02.
//

#include "Soundex.h"

#include <gmock/gmock.h>

using ::testing::Eq;
using ::testing::StartsWith;
using ::testing::Test;

class SoundexEncoding : public Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, retains_sole_letter_of_one_letter_word) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, pads_width_zeros_to_ensure_three_digits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, replaces_consonant_with_appropriate_digits) {
  ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
  ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
  ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
  ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, ignores_non_alphabetics) {
  ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, replaces_multiple_consonants_with_digits) {
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, limits_length_to_four_characters) {
  ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, ignores_vowel_like_letters) {
  ASSERT_THAT(soundex.encode("Baeiouhycdl"), Eq("B234"));
  ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, combines_duplicate_encodings) {
  ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, uppercases_first_letter) {
  ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, ignores_case_when_encoding_consonants) {
  ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, combines_duplicate_codes_when_2nd_letter_duplicates_1st) {
  ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, does_not_combine_duplicate_encoding_separated_by_vowels) {
  ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}

class Http {
public:
  virtual ~Http() {}
  virtual void initialize() = 0;
  virtual std::string get(const std::string &url) const = 0;
};

class HttpMock : public Http {
public:
  MOCK_METHOD0(initialize, void());
#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"
  MOCK_CONST_METHOD1(get, std::string(const std::string&));
#pragma clang diagnostic pop
};

class PlaceDescriptionService {
  Http *m_http;
public:
  PlaceDescriptionService(Http *http) : m_http(http) {}
  std::string run_query() {
    m_http->initialize();
    return m_http->get("http://test.com/run_tests");
  }
};

TEST(PlaceDescriptionService, can_call_with_mock) {
  ::testing::NiceMock<HttpMock> mockHttp;
  PlaceDescriptionService service(&mockHttp);
  service.run_query();
}
