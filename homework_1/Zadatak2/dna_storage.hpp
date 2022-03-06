#pragma once
#include<string>;
#include <iosfwd>
#include<fstream>
class DNAStorage {
  private:
      int cap;
      std::string *lanac_;
      int size_;
  public:
  DNAStorage();
  DNAStorage(const DNAStorage&);
  DNAStorage(DNAStorage&&);
  DNAStorage& operator=(const DNAStorage&);
  DNAStorage& operator=(DNAStorage&&);
  ~DNAStorage(){delete [] lanac_;};

  void print(std::ostream&) const;
  void print(std::ostream&, int pos, int len) const;
  void insert(int pos, std::string lanac);
  // remove vraca broj elemenata koji su obrisani
  int remove(int pos, int len);
  void store(std::string filename);
  // load baca iznimku tipa std::runtime_error ukoliko ne postoji
  // file sa imenom filename
  void load(std::string filename);

  //std::ostream& operator<<(std::ostream&)

};
DNAStorage::DNAStorage():cap(100),lanac_(new std::string[cap]),size_(0){
lanac_[0]="";
}
DNAStorage::DNAStorage(const DNAStorage& other){
size_=other.size_;
cap=other.cap;
delete [] lanac_;
lanac_= new std::string[cap];
std::copy(other.lanac_,other.lanac_+other.size_,lanac_);
};

  DNAStorage::DNAStorage(DNAStorage&& other){
    size_=other.size_;
    cap=other.cap;
    lanac_=other.lanac_;
    other.cap=0;
    other.lanac_=nullptr;
    other.size_=0;
  }

  DNAStorage& DNAStorage::operator=(const DNAStorage& other){
    return *this=DNAStorage{other};
  }
  DNAStorage& DNAStorage::operator=(DNAStorage&& other){
    size_=other.size_;
    std::swap(lanac_,other.lanac_);
    return *this;
  }

void DNAStorage::print(std::ostream& o) const{
    for(int i=0; i<cap;i++){
        if(lanac_[i]!=""){
                std::string temp=lanac_[i];
            o<<i<<"-"<<i+temp.length()-1<<": "<<lanac_[i]<<std::endl;
        }
    }
    std::cout<<std::endl;
}

void DNAStorage::print(std::ostream& o, int pos, int len) const{
std::string temp=lanac_[pos];
o<<pos;
if(len>temp.length()){
    o<<temp<<std::endl;
}else{
for(int i=0;i<len;i++){
    o<<temp[i];
}}
std::cout<<std::endl;
}

void DNAStorage::insert(int pos,std::string lanac){
if(lanac_[pos]==""){
    lanac_[pos]=lanac;
}else{
lanac_[pos]+=lanac;
}
std::cout<<std::endl;
size_++;
}
int DNAStorage::remove(int pos, int len){
std::string temp=lanac_[pos];
int size_=temp.length();
auto it=temp.begin()+(size_-len);
if(len>=size_){
    temp.erase(temp.begin(),temp.end());
    std::swap(temp,lanac_[pos]);
    size_--;
    return size_;
}
else{
    temp.erase(it,temp.end());
    std::swap(temp,lanac_[pos]);
    return len;
}
}

void DNAStorage::store(std::string filename){
    std::ofstream output(filename);
    if(output.is_open()){
        for (int i=0; i<cap;i++){
            if(lanac_[i]!="")
            output<<i<<" "<<lanac_[i]<<std::endl;
        }
    }

}
void DNAStorage::load(std::string filename){
     std::ifstream input{filename};
    if(input.is_open()){
        for (int i=0; i<cap;i++){
            input >> i;
            input >> lanac_[i];
        }
    }
}

