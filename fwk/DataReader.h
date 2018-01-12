//
// Created by 北條 育男 on 2017/06/02.
//

#ifndef SAMPLE_QT_DATAREADER_H
#define SAMPLE_QT_DATAREADER_H

#include <deque>

template <typename T = uint8_t>
class DataReader {
  std::deque<T> m_que;
public:
  typedef typename std::deque<T>::size_type size_type;

  inline void apply(T data) { m_que.push_front(data); }
  inline T pop() {
    T data = m_que.back();
    m_que.pop_back();
    return data;
  }
  inline size_type size() const { return m_que.size(); }
};

#endif //SAMPLE_QT_DATAREADER_H
