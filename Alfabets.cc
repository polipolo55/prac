#include "Alfabets.hh"
#include <iostream>
using namespace std;

Alfabets::Alfabets() {}

void Alfabets::read_alfabets() {
  int n_alf;
  cin >> n_alf;
  for (int i = 0; i < n_alf; ++i) {
    string ida;
    cin >> ida;
    add_alf(ida);
  }
}

void Alfabets::print_alfabets() {
  int num = 1;
  for (auto it = alfabets.begin(); it != alfabets.end(); ++it){
    cout << num << ". " << it->first << endl;
    it->second.print_alfabet();
    ++num;
  }
}

bool Alfabets::is_alf_there(const string& ida) {
  return alfabets.find(ida) != alfabets.end();
}

void Alfabets::add_alf(const string& ida){
  string alf;
  cin.ignore(streamsize(), '\n');
  getline(cin, alf);
  alfabets[ida] = Alfabet(alf);
}

void Alfabets::del_alf(const string& ida) {
  auto it = alfabets.find(ida);
  if (it != alfabets.end()) {
    if(it->second.n_msg_alf() == 0){
      alfabets.erase(it);
    } else cout << "error algun mensaje usa este alfabeto" << endl;
  } cout << "el alfabeto: " << ida << " no existe" << endl;
}

int Alfabets::n_alf() {
  return nalf;
}

int Alfabets::n_of_msg(const string& ida) {
  return alfabets[ida].n_of_msg();
}