#include <iostream>
#include <queue>
#include "bank_account.hpp"

int main()
{
int choose, money;
std::string x(80,'*');
bank_account acc(10000);
std::cout<<x<<std::endl;
std::cout<<"Action\n 1. New transaction\n 2. Apply transaction\n 3. Pending transaction\n 4. Discard pending transaction\n 5. Balance\n 6. Exit"<<std::endl;
do{
std::cout<<"Your choose: ";
std::cin>>choose;

    switch(choose){
    case 1:
        std::cout<<"\n"<<"How much money do you want to add to transaction: ";
        std::cin>>money;
        acc.add_trans(money);
        break;
    case 2:
        acc.apply_trans();
        break;
    case 3:
        acc.read_trans();
        break;
    case 4:
        acc.remove_trans();
        break;
    case 5:
        acc.balance();
        break;
    case 6:
        std::cout<<"GOOD BYE!"<<std::endl;
        break;
    default:
        std::cout<<"\n Error! Please choose one of the following options \n \n";
    }
}
while(choose!=6);










return 0;

}

