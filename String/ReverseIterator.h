#pragma once
#include <iterator>

template <class IterType>
class ReverseIterator {
  typedef std::iterator_traits<IterType> Traits;
  template <class T>
  friend bool operator==(const ReverseIterator<T>& left, const ReverseIterator<T>& right);
  
  IterType forward_iter_;
public:
  ReverseIterator(): forward_iter_(nullptr) { }
  ReverseIterator(const IterType& iter): forward_iter_(iter) { }
  ReverseIterator(const ReverseIterator& rev_iter): forward_iter_(rev_iter.forward_iter_) { }
  ~ReverseIterator() { }

  ReverseIterator& operator=(const ReverseIterator& iter) { forward_iter_ =  iter.forward_iter_; }

  ReverseIterator operator++(int a) { return ReverseIterator(forward_iter_--); }
  ReverseIterator& operator++() { --forward_iter_; return *this; }
  ReverseIterator operator--(int a) { return ReverseIterator(forward_iter_++); }
  ReverseIterator& operator--() { ++forward_iter_; return *this; }

  typename Traits::reference operator*() { return *forward_iter_; }
  typename Traits::reference operator->() { return _current; }

  typename Traits::reference operator[](const size_t i) { return *(forward_iter_ + i); }

  ReverseIterator& operator+=(ReverseIterator right) { forward_iter_ -= right.forward_iter_; return *this; }
  ReverseIterator& operator-=(ReverseIterator right) { forward_iter_ += right.forward_iter_; return *this; }
  ReverseIterator operator+(ReverseIterator right) { ReverseIterator sum(*this); return sum += right; }
  ReverseIterator operator-(ReverseIterator right) { ReverseIterator sum(*this); return sum -= right; }
  
  bool operator==(const ReverseIterator& right) { return forward_iter_ == right.forward_iter_; }
  bool operator!=(const ReverseIterator& right) { return !(*this == right); }
  bool operator<(const ReverseIterator& right) { return forward_iter_ > right.forward_iter_; }
  bool operator>(const ReverseIterator& right) { return forward_iter_ < right.forward_iter_; }
  bool operator<=(const ReverseIterator& right) { return !(forward_iter_ < right.forward_iter_); }
  bool operator>=(const ReverseIterator& right) { return !(forward_iter_ > right.forward_iter_); }
};

