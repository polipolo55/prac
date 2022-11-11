#include "Alfabets.hh"
#include <iostream>
using namespace std;

Alfabets::Alfabets() {}

void Alfabets::read_alfabets(const int& a) {
  for (int i = 0; i < a; ++i) {
    string ida;
    cin >> ida;
    add_alf(ida);
  }
}

void Alfabets::print_alfabets() {
  int num = 1;
  for (map<string, Alfabet>::iterator it = alfabets.begin(); it != alfabets.end(); ++it){
    cout << num << "-" << it->first << endl;
    it->second.print_alfabet();
    ++num;
  }
}

void Alfabets::add_alf(const string& ida){
  string alf;
  cin.ignore(streamsize(), '\n');
  getline(cin, alf);
  alfabets[ida] = Alfabet(alf);
}

bool Alfabets::is_alf_there(const string& ida){
  return alfabets.find(ida) != alfabets.end();
}

