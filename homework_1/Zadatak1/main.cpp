#include <iostream>
#include "ArrayList.hpp"
#include<vector>

int main(void)
{
    ArrayList<int> x(12);
   x.push_back(1).push_back(2).push_back(3).push_back(4).push_back(5);

    ArrayList<int>::const_iterator ict=x.cbegin();
    ArrayList<int>::iterator it=x.begin();
    ArrayList<int>::iterator it2=x.begin()+2;
    x.insert(it,10);
    x.print();

    x.remove(it2);
    x.print();

    auto temp=x.find(5);
    x.remove(temp);
    x.print();

    x.invert();
    x.print();

    x.insert(ict,100);

    x.print();

    auto temp2=x.find_if([](int a){return a==102;});
    if(temp2==x.end()){
        std::cout<<"END()"<<std::endl;
    }
    else {
    std::cout<<*temp2<<std::endl;}

    x.remove_if([](int a){return a==100;});
    x.print();



  return 0;
}
