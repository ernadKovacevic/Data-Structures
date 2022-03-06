#pragma once


template<typename T>
bool nepostoji(const Student& other,const T& map_){
    auto it=map_.begin();
for(it; it!=map_.end();it++){
    if(other.index == it->second.index){
        std::cout<<"\nGRESKA! Student sa datim indeksom vec postoji u bazi!"<<std::endl;
    return false;
}
}
return true;
}

template<typename T>
void prikaz(const T& map_){
    auto it=map_.begin();
for(it; it!=map_.end();it++){
    std::cout<<"Ime studenta : "<<it->second.ime<<std::endl;
    std::cout<<"Prezime studenta : "<<it->second.prezime<<std::endl;
    std::cout<<"Broj indeksa studenta : "<<it->second.index<<std::endl;
    std::cout<<"Prosjecna ocjena studenta : "<<it->second.prosjecna_ocjena<<std::endl<<std::endl;
}
}



template<typename T>
void pojedinacna_pretraga(T map_){
std::string name,surname;
int index, indicator=0, izbor;
    auto it=map_.begin();

std::cout<<"Izaberite po cemu zelite da pronadjete studenta :\n1. Ime i Prezime \n2. Broj indeksa \nVas izbor: ";
    std::cin>>izbor;
    if(izbor == 1){
        std::cout<<"\nUnesite ime studenta: ";
            std::cin>>name;
        std::cout<<"Unesite prezime studenta: ";
            std::cin>>surname;

        for(it; it!=map_.end();it++){
            if(it->second.ime == name && it->second.prezime==surname){
                std::cout<<"\nIme studenta : "<<it->second.ime<<std::endl;
                std::cout<<"Prezime studenta : "<<it->second.prezime<<std::endl;
                std::cout<<"Broj indeksa studenta : "<<it->second.index<<std::endl;
                std::cout<<"Prosjecna ocjena studenta : "<<it->second.prosjecna_ocjena<<std::endl<<std::endl;
                indicator++;
            }
        }
        if(indicator == 0){
            std::cout<<"\nGRESKA! Student "<<name<<" "<<surname<<" ne postoji u bazi!";
        }
    }
    else if(izbor == 2){
        std::cout<<"\nUnesite broj indeksa studenta : ";
            std::cin>>index;
        auto it=map_.find(index);
            if(it->first == index){
                std::cout<<"\nIme studenta : "<<map_[index].ime<<std::endl;
                std::cout<<"Prezime studenta : "<<map_[index].prezime<<std::endl;
                std::cout<<"Broj indeksa studenta : "<<map_[index].index<<std::endl;
                std::cout<<"Prosjecna ocjena studenta : "<<map_[index].prosjecna_ocjena<<std::endl<<std::endl;
            }
            else{
                std::cout<<"GRESKA! Student sa indeksom "<<index<<" ne postoji u bazi\n";
            }

    }else{
        std::cout<<"\nUpisali ste invalidan broj!\n"<<std::endl;
    }

std::cout<<"\n";
}

template<typename T>
void brisanje(T& map_){
int kljuc,izbor;
std::cout<<"Unesite broj indeksa koji zelite da izbrisete\nBroj indexa : ";
    std::cin>>kljuc;

auto it=map_.begin();
for(it; it!=map_.end();it++){
    if(it->first == kljuc){
        std::cout<<"\nPodaci o studentu koji se zeli izbrisati"<<std::endl;
        std::cout<<"\nIme studenta : "<<it->second.ime<<std::endl;
        std::cout<<"Prezime studenta : "<<it->second.prezime<<std::endl;
        std::cout<<"Broj indeksa studenta : "<<it->second.index<<std::endl;
        std::cout<<"Prosjecna ocjena studenta : "<<it->second.prosjecna_ocjena<<std::endl;
        std::cout<<"\nDa li ste sigurni da zelite obrisati studenta iz base: \n1.Da \n2.Ne \nVas izbor : ";
        std::cin>>izbor;
        if(izbor == 1){
            map_.erase(it);
            std::cout<<"STUDENT OBRISAN \n"<<std::endl;
            return;
        }
        else if(izbor == 2){ return ;}
        else {
            std::cout<<"GRESKA! Unijeli ste invalidan broj! \n";
            return ;
        }
}
std::cout<<"\nGRESKA! Student sa indeksom "<<kljuc<<" ne postoji u bazi\n"<<std::endl;

}
}


