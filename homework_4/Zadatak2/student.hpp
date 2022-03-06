#pragma once
#include <iostream>

struct Student{

    std::string ime;
    std::string prezime;
    int index;
    double prosjecna_ocjena;

    Student():ime(""),prezime(""),index(0),prosjecna_ocjena(0.00){}

    Student(const std::string& ime_ ,const std::string& prezime_, const int& index_, const double& prosjecna_ocjena_ ){
    ime = ime_;
    prezime = prezime_;
    index = index_;
    prosjecna_ocjena = prosjecna_ocjena_;
    }

};
