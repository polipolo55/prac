#include <iostream>
#include "Alfabets.hh"
#include "Alfabet.hh"
#include "Encriptacions.hh"
using namespace std;


Encriptacions::Encriptacions() {}

void Encriptacions::encrip_sust(const Alfabet& alf,const string& msg, const string& cl) {
  int n = msg.size();
  int n_cl = cl.size();
  char fl = alf.find_char_int_pos(0);
  for (int i = 0; i < n; ++i){
    if (alf.is_special()) {
      //alfabet es c d e f// e - c
      int px = msg[i] - fl;
      int py = msg[i%n_cl] - fl;
      cout << char(fl + px + py);

    } else {
      int px = mapalf[msg[i]];
      int py = mapalf[cl[i%n_cl]];
      char c = alf[px + py];

    }
  }
}

void Encriptacions::encrip_perm(const string& ida,const string& msg, const int& b) {

}



