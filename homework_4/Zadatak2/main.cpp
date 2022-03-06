#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "student.hpp"
#include "funkcije.hpp"

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
int izbor, index;
std::string ime, prezime;
double ocjena;
std::map<int,Student> map_;

do{
std::cout<<"1. Unos \n2. Brisanje studenta \n3. Prikaz svih studenata \n4. Prikaz jednog studenta \n5. Izlaz \nVas izbor: ";
std::cin>>izbor;
std::cout<<std::endl;
if(izbor ==1){

    std::cout<<"Unesite ime studenta: ";
        std::cin>>ime;
    std::cout<<"Unesite prezime studenta: ";
        std::cin>>prezime;
    std::cout<<"Unesite broj indexa studenta: ";
        std::cin>>index;
    std::cout<<"Unesite srednju ocjenu studenta: ";
        std::cin>>ocjena;
    Student temp(ime,prezime,index,ocjena);
        if(nepostoji(temp,map_))
            map_[index]=temp;
    std::cout<<"\n";
}
    else if(izbor == 2){ brisanje(map_); }
    else if(izbor == 3){ prikaz(map_); }
    else if(izbor == 4){ pojedinacna_pretraga(map_);}
    else if(izbor == 5){
        std::cout<<"Pozdrav! Ugodan dan zelimo"<<std::endl;
    }
    else {
        std::cout<<"Pogresan unos, molimo odaberite neki od ponudjenih brojeva! \n"<<std::endl;
    }
}
while(izbor != 5 );


    return 0;
}
