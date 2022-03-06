#include <iostream>
#include "sorted_list.hpp"
#include "ToDoTask.hpp"
#include <string>

int main() {
int choose,priority,finish;
std::string title, desc;
sorted_list<ToDoTask> list;
sorted_list<ToDoTask>::iterator it;
do{
std::cout<<"WELCOME PLEASE CHOOSE ONE OF THE FOLLOWING OPTIONS \n 1. Create new task \n 2. Read all tasks \n 3. Mark task as complited \n 4. Delete three task with hightest priorities \n 5. Delete three task with lowest priorities \n Your choose: ";
std::cin>>choose;
//int id=generateId();
switch(choose){
case 1:
    std::cout<<"Please insert Title"<<std::endl;
    std::cin.ignore();
    getline(std::cin,title);
    std::cin.clear();
    std::cout<<"Please insert Descrioption"<<std::endl;
    getline(std::cin,desc);
    std::cin.clear();
    std::cout<<"Please insert Priority (number)"<<std::endl;
    std::cin>>priority;
    list.add_task(title,priority,desc);
    break;

case 2:
    list.read();
    break;
case 3:
    std::cout<<"Insert ID"<<std::endl;
    std::cin>>finish;
    it=list.find(finish);
    list.remove(it);
    break;
case 4:
     list.remove_high();
     break;
case 5:
     list.remove_low();
     break;
}

std::cout<<std::endl;

}
while(choose>=1 and choose<=5);




return 0;
}
