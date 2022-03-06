#pragma once
#include <queue>
#include <ctime>
class bank_account{
private:
    int balance_;
    std::queue<int> trans;
public:
bank_account(const int & value): balance_(value){};

void balance(){
std::cout<<"\n"<<"Your bank balance is :"<<balance_<<"\n"<<std::endl;
}

void add_trans(const int& value){
    trans.push(value);
    std::cout<<"\n";
}

void apply_trans(){
if(trans.empty()){
    std::cout<<"\n"<<"ERROR! No transaction added"<<"\n"<<std::endl;
    return;
    }
else if(trans.front() > balance_){
    std::cout<<"\n"<<"There is no enough money on your account"<<"\n"<<std::endl;
    return;
}
balance_-=trans.front();
std::cout<<"\n"<<"TRANSACTION DONE \nMONEY YOU HAVE SENT: "<<trans.front()<<std::endl;
timer();
trans.pop();
}

void timer(){
    time_t currenttime=time(0);
    tm * mytime=localtime(&currenttime);
    int day=mytime->tm_mday;
    int month=1+mytime->tm_mon;
    int year=1900+mytime->tm_year;

    int second=mytime->tm_sec;
    int minute=mytime->tm_min;
    int hour=mytime->tm_hour;

    std::cout<<"DATE: "<<day<<":"<<month<<":"<<year<<"\t dd:mm:yy"<<std::endl;
    std::cout<<"TIME: "<<hour<<":"<<minute<<":"<<second<<"\t h:min:sec \n"<<std::endl;
}

void read_trans(){
if(trans.empty()){
    std::cout<<"\n"<<"ERROR! No pending transactions"<<"\n"<<std::endl;
    return;
}
std::cout<<"\n"<<"PENDING TRANSACTION "<<std::endl;
std::cout<<"VALUE: "<< trans.front()<<"\n"<<std::endl;
}

void remove_trans(){
if(trans.empty()){
    std::cout<<"\n"<<"ERROR! Cant discard, no transaction added \n"<<std::endl;
    return;
}
std::cout<<"\n"<<"TRANSACTION DISCARDED \nValue: "<<trans.front()<<std::endl;
timer();
trans.pop();
}



};




