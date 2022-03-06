#include <iostream>
#include "sorted_list.hpp"

// zadatak1.cpp sluzi kao primjer koristenja klase koju trebate implementirati u
// okviru prvog zadatka. Ovaj file se mora moci kompajlirati bez ikakvih izmjena
// unutar njega. Fajl mozete mijenjati u svrhu testiranja (nije potrebno
// predavati ovaj file).
//
// Napomena:
// Funkcija main testira u potpunosti ispravnost vaseg koda. Funkcija main sluzi
// samo kao kratki primjer

int main(void) {
  sorted_list<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    auto x=s.begin();


  return 0;
}
