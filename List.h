//
// Created by Macbook Pro on 06/02/2020.
//

#ifndef UNTITLED5_LIST_H
#define UNTITLED5_LIST_H

#include <iostream>

template<class T>
class List {
public:

  List() : tail_(nullptr), head_(nullptr) {
  }

  int operator+=(T value) {
    int counter = 0;
    if (head_ == nullptr) {
      head_ = new Elem(value, nullptr);
      tail_ = head_;
      return 1;
    }
    Elem *curr = head_;
    if (head_->getValue() > value) {
      head_ = new Elem(value, curr);
      return 1;
    } else if (tail_->getValue() < value) {
      tail_->setNext(new Elem(value, nullptr));
      tail_ = tail_->getNext();
      return 1;
    } else {
      while (curr != nullptr) {
        counter++;
        if (curr->getValue() >= value) {
          T tmpValue = curr->getValue();
          Elem *tmpPointer = curr->getNext();
          curr->setValue(value);
          curr->setNext(new Elem(tmpValue, tmpPointer));
          if (curr == tail_) {
            tail_ = curr->getNext();
          }
          return counter;
        }
        curr = curr->getNext();
      }
    }
  }


  ~List() {
    while (head_ != nullptr) {
      Elem *curr = head_;
      head_ = head_->getNext();
      delete (curr);
    }
  }


  bool isEmpty() const {
    return head_ == nullptr;
  }

  struct Elem {
  public:
    Elem(T value, Elem *next) : value_(value), next_(next) {
    }

    Elem *getNext() const {
      return next_;
    }

    void setValue(T value) {
      value_ = value;
    }

    void setNext(Elem *next) {
      next_ = next;
    }

    T getValue() const {
      return value_;
    }

  private:
    Elem *next_;
    T value_;
  };

  Elem *head_;
  Elem *tail_;
};

#endif //UNTITLED5_LIST_H
