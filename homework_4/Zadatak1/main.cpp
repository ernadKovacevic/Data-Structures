#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>


int main()
{
std::fstream myFile;
std::string name_of_file, word;
std::map<std::string,std::vector<int>> map_;

myFile.open("story.txt");

while(myFile >> word ){

   static int counter=1;
   map_[word].push_back(counter);
   counter++;

}

std::map<std::string,std::vector<int>>::iterator begin_=map_.begin();
std::map<std::string,std::vector<int>>::iterator end_=map_.end();

for(begin_; begin_!=end_; begin_++){
    std::cout<<"Rijec je \""<<begin_->first<<"\" i nalazi se na sljedecim pozicijama:"<<std::endl;
        for(int i=0; i<begin_->second.size();i++){
        std::cout<<map_[begin_->first][i]<<"\t";
        }
    std::cout<<std::endl<<std::endl;
}

    return 0;
}
