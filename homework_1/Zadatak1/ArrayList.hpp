#pragma once
#include <iostream>
#include <stdexcept>
#include<functional>

template <typename T>
class ArrayList {
  private:
  T* elements_;
  size_t size_;
  size_t capacity_;

  public:
  ArrayList(int size = 100);
  ArrayList(const ArrayList<T>& other);
  const ArrayList<T>& operator=(const ArrayList<T>&);
  bool empty() const;
  bool full() const;
  int size() const { return size_; }
  int capacity() const { return capacity_; }
  void print() const;
  T& at(int index);
  void reserve(int new_cap);
  ~ArrayList(void) { delete[] elements_; }


  ArrayList<T>& push_back(const T& value);
  ArrayList<T>& pop_back();

  ArrayList<T>& push_front(const T& value);
  ArrayList<T>& pop_front();

  ArrayList<T>& insert(int index, const T& value);

  ArrayList<T>& invert();

  //int find(const T& value);
  ArrayList<T>& replace(const T& oldValue, const T& newValue);

  class iterator;
  class const_iterator;
  iterator begin(){return iterator(elements_);} //O(1)
  iterator end(){return iterator(elements_+size_);} //O(1)
  const_iterator cbegin(){return const_iterator(elements_);} //O(1)
  const_iterator cend(){return const_iterator(elements_+size_);}//O(1)

   void insert(iterator it,const T& value); //O(n)
   iterator find(const T& value); //O(n)
   void remove(iterator it); //O(n)

   iterator find_if(std::function<bool(T&)>const &); //O(n)
   void remove_if(std::function<bool(T&)>const &); //O(n)
   void insert(const_iterator ,const T& ); // O(n)
};
template<typename T>
class ArrayList<T>::const_iterator
: public std::iterator<std::random_access_iterator_tag, T>{
private:
    T * pel;
public:
    const_iterator(){pel=nullptr;}
    const_iterator( T* x){ pel=x;}
    const T& operator *(){return *pel;}
    const_iterator& operator++(){
    ++pel;
    return pel;
    }
    const_iterator operator++(int){
    auto temp=pel;
    ++pel;
    return temp;
    }
    const_iterator& operator--(){
    --pel;
    return pel;
    }
    const_iterator operator--(int){
    auto temp=pel;
    --pel;
    return temp;
    }
    const_iterator operator+(const int& value){return const_iterator(pel+value);}
    const_iterator operator-(const int& value){return const_iterator(pel-value);}
    bool operator ==(const const_iterator& other){return pel==other.pel;}
    bool operator !=(const const_iterator& other){return pel!=other.pel;}
    bool operator <=(const const_iterator& other){return pel<=other.pel;}
    bool operator >=(const const_iterator& other){return pel>=other.pel;}
    bool operator <(const const_iterator& other){return pel<other.pel;}
    bool operator >(const const_iterator& other){return pel>other.pel;}
};

template<typename T>
class ArrayList<T>::iterator
: public std::iterator<std::random_access_iterator_tag, T>{
private:
    T * pel;
public:
    iterator(){pel=nullptr;}
    iterator(T* x){ pel=x;}
    T& operator *(){return *pel;}
    iterator& operator++(){
    ++pel;
    return *this;
    }
    iterator operator++(int){
    auto temp=pel;
    ++pel;
    return temp;
    }
    iterator& operator--(){
    --pel;
    return pel;
    }
    iterator operator--(int){

    auto temp=pel;
    --pel;
    return temp;
    }
    iterator operator+(const int& value){
    return iterator(pel+value);
    }
    iterator operator-(const int& value){
    return iterator(pel-value);
    }
    bool operator ==(const iterator& other){return pel==other.pel;}
    bool operator !=(const iterator& other){return pel!=other.pel;}
    bool operator <=(const iterator& other){return pel<=other.pel;}
    bool operator >=(const iterator& other){return pel>=other.pel;}
    bool operator <(const iterator& other){return pel<other.pel;}
    bool operator >(const iterator& other){return pel>other.pel;}
};




template <typename T>
ArrayList<T>& ArrayList<T>::insert(int index, const T& value) {
  if (full()) reserve(2*capacity_);
  for (int i = size_; i > index; i--) {
    std::swap(elements_[i], elements_[i-1]);
  }
  size_++;
  elements_[index] = value;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::push_front(const T& value) {
  return insert(0, value);
  // if (full()) {
  //   reserve(2*capacity_);
  // }
  // for (int i = size_; i > 0; i--) {
  //   std::swap(elements_[i], elements_[i-1]);
  // }
  // size_++;
  // elements_[0] = value;
  // return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::pop_front() {
  for (int i = 0; i < size_ - 1; i++) {
    std::swap(elements_[i], elements_[i+1]);
  }
  pop_back();
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::pop_back() {
  if (size_ > 0)
    size_--;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::push_back(const T& value) {
  if (full()) {
    reserve(2*capacity_);
  }
  // elements_[size_++] = value;
  elements_[size_]= value;
  size_++;
  return *this;
}


template <typename T>
ArrayList<T>& ArrayList<T>::replace(const T& oldValue, const T& newValue) {
  int result = find(oldValue);
  if (result != -1) {
    elements_[result] = newValue;
  }
  return *this;
}


template <typename T>
void ArrayList<T>::reserve(int new_cap) {
  if (new_cap > capacity_) {
    auto temp = new T[new_cap];
    for (int i = 0; i < size_; i++)
      temp[i] = std::move(elements_[i]);
    delete[] elements_;
    elements_ = temp;
    capacity_ = new_cap;
  }
}

template <typename T>
ArrayList<T>::ArrayList(int n) {
  n < 0 ? capacity_ = 100 : capacity_ = n;
  size_ = 0;
  elements_ = new T[capacity_];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
  capacity_ = other.capacity();
  size_ = other.size();
  elements_ = new T[capacity_];
  for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
}

template <typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
  if (this != &other) {
    delete[] elements_;
    capacity_ = other.capacity();
    size_ = other.size();
    elements_ = new T[capacity()];
    for (int i = 1; i < size_; i++) elements_[i] = other.elements_[i];
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::empty() const {
  return (size_ == 0);
}

template <typename T>
bool ArrayList<T>::full() const {
  return (size_ == capacity_);
}

template <typename T>
void ArrayList<T>::print() const {
  for (int i = 0; i < size_; i++) std::cout << elements_[i] << " ";
  std::cout << std::endl;
}

template <typename T>
T& ArrayList<T>::at(int index) {
  if (index < 0 || index >= size_)
    throw std::out_of_range("Index is out of range.");
  else
    return elements_[index];
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
typename ArrayList<T>::iterator ArrayList<T>::find(const T& value){
    auto it=begin();
for(it;it<end();it++){
    if(*it==value){
        return it;
    }
}
return end();
}

template<typename T>
void ArrayList<T>::remove(iterator it){
    if(empty()){
        throw std::logic_error("List is empty");
    }
    if(it<begin() || it>=end()){
        throw std::out_of_range("Out of range!");
    }
for(it;it<end();it++){
    std::swap(*it,*(it+1));
}
size_--;
}

template <typename T>
ArrayList<T>& ArrayList<T>::invert() {
  auto end_=end()-1;
  int i=0;
  for(i;i<size_;i++){
    for(auto begin_=begin();begin_<end_;begin_++){
        std::swap(*begin_,*(begin_+1));
    }
    end_--;
  }
  return *this;
}

template<typename T>
typename ArrayList<T>::iterator ArrayList<T>::find_if(std::function<bool(T&)>const& predikat){
    auto temp=end();
for(auto it =begin();it<end();it++){
if(predikat(*it)){
temp=it;
break;
}
}
return temp;
}

template<typename T>
void ArrayList<T>::remove_if(std::function<bool(T&)>const& predikat){
    if(empty()){
        throw std::logic_error("List is empty");
    }
for(auto it=begin();it<end()-1;it++){
    if(predikat(*it)){
        std::swap(*it,*(it+1));
    }
}
size_--;
}
template<typename T>
void ArrayList<T>::insert(const_iterator it,const T& value) {
    if(it<cbegin() || it>=cend()){
        throw std::out_of_range("Out of range!");
    }

  if(full()){
    reserve(2*capacity_);
}
auto ctemp=cend();
auto temp=end();
*temp=value;
for(;ctemp>it;ctemp--){
    std::swap(*temp,*(temp-1));
    temp--;
}
size_++;
}

template<typename T>
void ArrayList<T>::insert(iterator it,const T& value) {
    if(it<begin() || it>=end()){
        throw std::out_of_range("Out of range!");
    }

  if(full()){
    reserve(2*capacity_);
}

auto temp=end();
*temp=value;
for(temp;temp>it;temp--){
    std::swap(*temp,*(temp-1));
}
size_++;
}
