#include <iostream>
#include "dna_storage.hpp"
using namespace std;

int main(){
DNAStorage x;
int select,position,len,ret;
std::string file,value;
std::cout<<"Welcome to DNA storage. Please enter one of the following option: \n\n";
do{
    std::cout<<"1. Print\n"<<"2. Print <pos> <len>\n"<<"3. Insert <pos> <lanac>\n"<<"4. Remove <pos> <len>\n"<<"5. Store <file>\n"<<"6. Load <file>\n"<<"7. Exit \n"<<"Your choice: "<<std::endl;
    std::cin>>select;
switch (select){
    case 1: x.print(std::cout);  break;
    case 2:
       len;
        std::cout<<"Position: ";
        std::cin>>position;
        std::cout<<"Lenght: ";
        std::cin>>len;
        std::cout<<"\n";
        x.print(std::cout,position,len);
        break;
    case 3:
        std::cout<<"Position: ";
        std::cin>>position;
        std::cout<<"Value: ";
        std::cin>>value;
        x.insert(position,value);
         break;
    case 4:
        std::cout<<"Position: ";
        std::cin>>position;
        std::cout<<"Lenght: ";
        std::cin>>len;
        ret=x.remove(position,len);
         break;
    case 5:
        std::cout<<"File: ";
        std::cin>>file;
        x.store(file);
        break;
    case 6:
        std::cout<<"File: ";
        std::cin>>file;
        x.load(file);
        break;
    case 7: break;
    default:
        std::cout<<"Error please enter one of the following numbers\n"<<std::endl;
}
}
while(select!=7);















return 0;
}
