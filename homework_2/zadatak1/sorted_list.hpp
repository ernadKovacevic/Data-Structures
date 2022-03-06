#pragma once
#include "node.hpp"
template<typename T>
class sorted_list{
public:
    node<T>* head;
    node<T>* tail;
    int size_;
public:
sorted_list();
~sorted_list();
sorted_list(const sorted_list&);
sorted_list(sorted_list&&);
sorted_list& operator=(const sorted_list&);
sorted_list& operator=(sorted_list&&);
void add(const T&);
void push_back(const T&);
void push_front(const T&);
inline bool empty(){return size_==0;};
void read();
void pop_back();
void pop_front();
void clear();
inline int size(){return size_;};

class iterator;
iterator begin(){return iterator(head,nullptr);};
iterator end(){return iterator(nullptr,tail);};
iterator find(const T&);
void insert_ispred(const T&, iterator);
void insert_iza(const T&,iterator);
template<typename U>
iterator find_if(U);
void remove(iterator);
};
template<typename T>
class sorted_list<T>::iterator{
private:
    node<T>* currentNode;
    node<T>* previousNode;
public:
    friend class sorted_list;
    iterator()=default;
    iterator(node<T>* currNode, node<T>* prevNode):currentNode(currNode),previousNode(prevNode){};
    T& operator*(){return currentNode->value;}

    iterator& operator++(){
    previousNode=currentNode;
    currentNode=currentNode->next;
    return *this;
    }
    iterator operator++(int){
    auto temp=*this;
    ++(*this);
    return temp;
    }
    iterator& operator--(){
    currentNode=previousNode;
    previousNode=previousNode->prev;
    return *this;
    }
    iterator operator--(int){
    auto temp=*this;
    --(*this);
    return temp;
    }
    bool operator==(const iterator& other){return currentNode==other.currentNode;};
    bool operator!=(const iterator& other){return currentNode!=other.currentNode;};
    bool operator>=(const iterator& other){return currentNode>=other.currentNode;};
    bool operator<=(const iterator& other){return currentNode<=other.currentNode;};
    bool operator<(const iterator& other){return currentNode<other.currentNode;};
    bool operator>(const iterator& other){return currentNode>other.currentNode;};


};




//-------------------------------------------KONSTRUKTORI I DESTRUKTOR---------------------------------------------------
template<typename T>
sorted_list<T>::~sorted_list(){clear();};

template<typename T>
sorted_list<T>::sorted_list():head(nullptr),tail(nullptr),size_(0){};

template<typename T>
sorted_list<T>::sorted_list(const sorted_list& other){
clear();
auto temp=other.head;
while(temp!=nullptr){
    add(temp->value);
    temp=temp->next;
}

}

template<typename T>
sorted_list<T>::sorted_list(sorted_list&& other){
clear();
head=other.head;
tail=other.tail;
size_=other.size_;
other.head=other.tail=nullptr;
other.size_=0;

}

template<typename T>
sorted_list<T>& sorted_list<T>::operator=(sorted_list&& other){
clear();
head=other.head;
tail=other.tail;
size_=other.size_;
other.head=other.tail=nullptr;
other.size_=0;

return *this;
}

template<typename T>
sorted_list<T>& sorted_list<T>::operator=(const sorted_list& other){
    auto temp=other.head;
while(temp!=nullptr){
    add(temp->value);
    temp=temp->next;
}
return *this;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename T>
typename sorted_list<T>::iterator sorted_list<T>::find(const T& value){
for(auto it=begin();it!=end();it++){
    if(*it==value){
        return it;
    }
}
return end();
}

template<typename T>
template<typename U>
typename sorted_list<T>::iterator sorted_list<T>::find_if(U predicate){
for(auto it=begin();it!=end();it++){
    if(predicate(*it)){
        return it;
    }
}
return end();
}


template<typename T>
void sorted_list<T>::remove(iterator position){
  auto temp=position.currentNode;
 if(size_==1){
    head=tail=nullptr;
    delete temp;
    size_=0;
    return;
 }
if(position==begin()){
    auto temp=position.currentNode;
    auto NewHead=++position;
    NewHead.previousNode=nullptr;
    head= NewHead.currentNode;
    delete temp;
}
if(position==(--end())){
    iterator temp=position;
    tail=temp.previousNode;
    tail->next=nullptr;
    delete temp.currentNode;
}
else{
    position.previousNode->next=position.currentNode->next;
    delete position.currentNode;
}
size_--;
}

template<typename T>
void sorted_list<T>::clear(){
while(head!=nullptr){
    auto temp=head;
     head=head->next;
     delete temp;
}
size_=0;
head=nullptr;
tail=nullptr;
}
template<typename T>
void sorted_list<T>::push_back(const T& value){
auto temp= new node<T>(value);
if (empty()){
    head=temp;
    tail=head;
}else{
temp->prev=tail;
tail->next=temp;
tail=temp;
}

size_++;
}



template<typename T>
void sorted_list<T>::add(const T& value){
    auto temp=new node<T>(value);
if(empty()){
    head=temp;
    tail=head;
}else{

    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
size_++;
}

template<typename T>
void sorted_list<T>::push_front(const T& value){
auto temp= new node<T>(value);
if(empty()){
    head=temp;
    tail=head;
}
else{
    temp->next=head;
    head->prev=temp;
    head=temp;
}
size_++;
}




template<typename T>
void sorted_list<T>::read(){
auto temp=head;
while(temp!=nullptr){
    std::cout<<temp->value<<" ";
    temp=temp->next;
}
std::cout<<std::endl;
}

template<typename T>
void sorted_list<T>::pop_front(){
if(empty()){
    return;
}else if(size_>1){
auto temp=head;
head=head->next;
delete temp;
}
else if(size_==1){
    delete head;
    head=nullptr;
    tail=nullptr;
}
size_--;

}

template<typename T>
void sorted_list<T>::pop_back(){
  auto temp=tail;
if(empty()){
    return;
}
else if(size_>1){
tail=tail->prev;
tail->next=nullptr;
delete temp;
}
else if(size_==1){
        tail = head=nullptr;
        delete temp;
}
size_--;
}

template<typename T>
void sorted_list<T>::insert_ispred(const T& value, iterator  it){
auto temp= new node<T>(value);

if(empty()){
    head=temp;
    tail=head;
}
else if(it==begin()){
    temp->next=it.currentNode;
    temp->prev=nullptr;
    head=temp;

}
else{
for(auto i=begin(); i!=end() ;i++){
    if(i==it){
        it.previousNode->next=temp;
        temp->next=it.currentNode;
        it.current->prev = temp;
        temp->prev=it.previousNode;
    }
}
}
size_++;
}

template<typename T>
void sorted_list<T>::insert_iza(const T& value, iterator  it){
auto temp= new node<T>(value);

if(empty()){

    head=temp;
    tail=head;
}
else if(it==begin()){
    temp->next=it.currentNode->next;
    it.currentNode->next=temp;
    temp->prev=it.currentNode;


}
else{
for(auto i=begin(); i!=end() ;i++){
    if(i==it){
        temp->next=it.currentNode->next;
        it.currentNode->next=temp;
        temp->prev=it.currentNode;
    }
}
}
size_++;
}






