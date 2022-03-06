#include <iostream>
#include "queue.hpp"


int main(){
queue<int> x;
std::cout<<"Adding 5 number to our queue (1 2 3 4 5) (capacity = 5) "<<std::endl;
x.push(1);
x.push(2);
x.push(3);
x.push(4);
x.push(5);
std::cout<<"first element (expecting 1) is: "<<x.front()<<std::endl;
std::cout<<"last element (expecting 5) is: "<<x.back()<<std::endl;
std::cout<<"----------------------------------------------------------"<<std::endl;
std::cout<<"Using methods push and pop two times"<<std::endl;
x.pop();
x.pop();
x.push(6);
x.push(7);
std::cout<<"first element (expecting 3) is: "<<x.front()<<std::endl;
std::cout<<"last element (expecting 7) is: "<<x.back()<<std::endl;
std::cout<<"----------------------------------------------------------\n"<<std::endl;

queue<int> new_queue(x);
std::cout<<"Creating new object with coppy constructor"<<std::endl;
std::cout<<"first element of object 'x' (expecting 3) is: "<<x.front()<<std::endl;
std::cout<<"last element of object 'x' (expecting 7) is: "<<x.back()<<"\n"<<std::endl;
std::cout<<"first element of object 'new_queue' (expecting 3) is: "<<x.front()<<std::endl;
std::cout<<"last element of object 'new_queue' (expecting 7) is: "<<x.back()<<"\n"<<std::endl;
std::cout<<"----------------------------------------------------------"<<std::endl;

queue<int> move_queue(std::move(x));
std::cout<<"Creating new object with move constructor"<<std::endl;
std::cout<<"Size of object 'x' is: "<<x.size()<<std::endl;
std::cout<<"first element of object 'move_queue' (expecting 3) is: "<<move_queue.front()<<std::endl;
std::cout<<"last element of object 'move_queue' (expecting 7) is: "<<move_queue.back()<<"\n"<<std::endl;
std::cout<<"----------------------------------------------------------"<<std::endl;

queue<int> moveop_queue;
moveop_queue=std::move(new_queue);
std::cout<<"Creating new object with move operator ="<<std::endl;
std::cout<<"Capacity : "<<moveop_queue.capacity()<<std::endl;
std::cout<<"first element of object 'move_queue' (expecting 3) is: "<<move_queue.front()<<std::endl;
std::cout<<"last element of object 'move_queue' (expecting 7) is: "<<move_queue.back()<<"\n"<<std::endl;
std::cout<<"Using method pop three times"<<std::endl;
moveop_queue.pop();
moveop_queue.pop();
moveop_queue.pop();
std::cout<<"first element of object 'moveop_queue' (expecting 6) is: "<<moveop_queue.front()<<"\n"<<std::endl;
std::cout<<"----------------------------------------------------------"<<std::endl;

queue<int> cap_queue(10);
std::cout<<"Creating new object with capacity 10"<<std::endl;
std::cout<<"Capacity is: "<<cap_queue.capacity()<<std::endl;
std::cout<<"Size is: "<<cap_queue.size()<<"\n"<<std::endl;


return 0;
}
