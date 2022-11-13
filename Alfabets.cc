#include "Alfabets.hh"
#include <iostream>
using namespace std;

Alfabets::Alfabets() {}

void Alfabets::read_alfabets() {
  int n_alf;
  cin >> n_alf;
  nalf = n_alf;
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
  ++nalf;
}

void Alfabets::del_alf(const string& ida) {
  auto it = alfabets.find(ida);
  if (it != alfabets.end()) {
    if(it->second.n_msg_alf() == 0){
      alfabets.erase(it);
    } else cout << "error: hay mensajes guardados con este alfabeto" << endl;
  } cout << "error: el alfabeto no existe" << endl;
}

int Alfabets::n_alf() {
  return nalf;
}

int Alfabets::n_of_msg(const string& ida) {
  return alfabets[ida].n_msg_alf();
}

void Alfabets::add_msgs_alf(const string& ida, const int& n) {
  alfabets[ida].add_msgs_alf(n);
}