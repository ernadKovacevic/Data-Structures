#pragma once
#include<iostream>
#include<stack>

class PostfixCalc{
private:
    std::stack<int> calc;
public:
    PostfixCalc()=default;


bool isOperator(const char& value){
if(value=='+' || value=='-' || value=='*' || value=='/')
    return true;
else
    return false;
}


void input(){
int first_number,second_number,temp;
std::string str, input;
std::cout<<"Welcome! Please insert your string \nYOUR STRING: "<<std::endl;
getline(std::cin, input);

for(int i=0; i<input.length();i++){
    if(input[i]!=' '){
        if(input[i]>='0' && input[i]<='9'){
            str.push_back(input[i]);
            if(input[i+1]==' '){
                calc.push(std::stoi(str));
                str="";
            }
        }
    else if( isOperator(input[i]) ) {
            if(calc.size()<2){
                throw std::runtime_error("Not enough operands in stack , two required");
            }
            second_number=calc.top();
            calc.pop();
            first_number=calc.top();
            calc.pop();

                switch(input[i]){
                    case '+':
                            calc.push(first_number+second_number);
                            break;
                    case '-':
                            calc.push(first_number-second_number);
                            break;
                    case '*':
                            calc.push(first_number*second_number);
                            break;
                    case '/':
                            if(second_number==0){
                                throw std::runtime_error("Cannot divide with 0(zero)");
                            }
                            calc.push(first_number/second_number);
                            break;
                }
    }
    }
}
}


void result(){
std::cout<<"YOUR RESULT IS : "<<calc.top()<<std::endl;
}
};

