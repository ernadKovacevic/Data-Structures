#pragma once
template<typename T>
class queue{
private:
    size_t size_;
    int cap;
    int first;
    int last;
    T* elements;
public:
    ~queue();
    queue();
    queue(const int&);
    queue(const queue&);
    queue(queue&&);
    queue& operator=(queue&&);
    inline bool full(){return cap==size_;};
    inline bool empty(){return size_==0;};
    template<typename U>
    void push(U&&);
    T pop();
    int size();
    int capacity();
    T& front();
    T& back();
    T& operator[](const int&);
};
//----------------------------------------- KONSTRUKTORI I DESTUKTOR-------------------------------------------------------------
template<typename T>
queue<T>::queue():size_(0),cap(5),first(0),last(0),elements(new T[cap]){};

template<typename T>
queue<T>::queue(const int& value):size_(0),cap(value),first(0),last(0),elements(new T[cap]){};

template<typename T>
queue<T>::queue(queue&& other){
elements=other.elements;
cap=other.cap;
first=other.first;
last=other.last;
size_=other.size_;
other.elements=nullptr;
other.cap=other.last=other.first=other.size_=0;
}

template<typename T>
queue<T>& queue<T>::operator=(queue&& other){
std::swap(elements,other.elements);
std::swap(cap,other.cap);
std::swap(first,other.first);
std::swap(last,other.last);
std::swap(size_,other.size_);
return *this;
}

template<typename T>
queue<T>::~queue(){
elements=nullptr;
first=last=cap=size_=0;
}

template<typename T>
queue<T>::queue(const queue& other){
cap=other.cap;
elements=new T[cap];
std::copy(other.elements,other.elements+other.size_,elements);
first=other.first;
last=other.last;
size_=other.size_;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
template<typename U>
void queue<T>::push(U&& value){

if (full()){
    throw std::out_of_range("Quequ is full!");
}
if(last==cap){
last=0;
}
elements[last]=std::forward<U>(value);
last++;
size_++;

}
template<typename T>
T queue<T>::pop(){
if(empty()){
    throw std::runtime_error("Queue is empty!");
}
int temp=first;
if(first==cap-1){
    first=0;
}else{
first++;
}
size_--;
return std::move(elements[temp]);
}

template<typename T>
int queue<T>::size(){return size_;};

template<typename T>
T& queue<T>::front(){return elements[first];};

template<typename T>
int queue<T>::capacity(){return cap;};

template<typename T>
T& queue<T>::back(){
    int temp=last;
    temp--;
return elements[temp];
};

