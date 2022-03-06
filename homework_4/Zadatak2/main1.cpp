#include <iostream>
#include "student.hpp"
#include "funkcije.hpp"
#include <map>
#include <vector>
using namespace std;
template<typename T>
bool nepostoji(const Student& other,const T& map_);

template<typename T>
void prikaz(const T& map_);

template<typename T>
void pojedinacna_pretraga(T map_);

template<typename T>
void brisanje(T& map_);

int main()
{
map<string,double> x;

x["1111"]= 8.0;
x["2222"]= 1.1;
x["3333"] =10.1;
x ["4444"] =12.2;
x["12"] = 12.114;
auto it=x.begin();

for(it; it != x.end(); it++){

 if(it->second > 8){
   std::cout<<it->first<<std::endl;
}

}



    return 0;
}
