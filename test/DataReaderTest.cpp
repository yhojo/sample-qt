//
// Created by 北條 育男 on 2017/06/02.
//

#include <gmock/gmock.h>

#include "DataReader.h"

using namespace ::testing;

class ADataReader : public Test {
public:
  DataReader<uint8_t> reader;
};

TEST_F(ADataReader, can_) {
  const uint8_t SAMPLE_DATA[] = {0x80, 0x81, 0x82};
  for (uint8_t data: SAMPLE_DATA) reader.apply(data);
  ASSERT_THAT(reader.size(), Eq(3));
  for (uint8_t data: SAMPLE_DATA) ASSERT_THAT(reader.pop(), Eq(data));
}
