#include <iostream>
#include "Alfabet.hh"
#include "Encriptacions.hh"
using namespace std;

Encriptacions::Encriptacions() {}

void Encriptacions::encrip_sust(const Alfabet& alfabet,const string& msg, const string& cl) {
  int n = msg.size();
  int n_cl = cl.size();
  Alfabet alf = alfabet;
  char fl = alf.find_pos_on_map(0);
  bool special = alf.is_special();
  string s = msg;
  
  if (special) {
    for (int i = 0; i < n; ++i) {
      char px = msg[i] - fl;
      char py = cl[i%n_cl] - fl;
      s[i] = (px + py)%alf.size() + fl;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      char px = alf.find_pos_on_map(msg[i]);
      char py = alf.find_pos_on_map(cl[i%n_cl]);
      s[i] = alf.find_char_int_pos((px + py)%alf.size());
    }
  }
  cout << "\""<< s << "\"" <<endl;
}

void Encriptacions::decrip_sust(const Alfabet& alfabet, const string& enc, const string& cl) {
	Alfabet alf = alfabet;
	int n = enc.size();
	int n_c = cl.size();
  bool special = alf.is_special();
  char fl = alf.find_pos_on_map(0);
	string r = enc;

	if (special) {
	  for (int i = 0; i < n; ++i) {
      char c = enc[i];
      char b = cl[i%n_c];
		  char a = c - b;
		  if (a < 0) a += alf.size();
		  r[i] = a + fl;
	  }
	} else {
    for (int i = 0; i < n; ++i) {
      char c = alf.find_pos_on_map(enc[i]);
      char b = alf.find_pos_on_map(cl[i%n_c]);
		  char a = c - b;
		  if (a < 0) a += alf.size();
		  r[i] = alf.find_char_int_pos(a);
	  }
	}
	cout << "\""<< r << "\""<< endl;
}

void Encriptacions::encrip_perm(const string& msg, const int& b) {

}



