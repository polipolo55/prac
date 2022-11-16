#include "Alfabets.hh"
#include <iostream>
using namespace std;

Alfabets::Alfabets() {}




void Alfabets::read_alfabets() {
  int n;
  cin >> n ;
  for (int i = 0; i < n; ++i) {
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

void Alfabets::add_alf(const string& ida){
  string alf;
  cin.ignore(1024, '\n');
  getline(cin, alf);
  alfabets[ida] = Alfabet(alf);
  ++nalf;
}

bool Alfabets::is_alf_there(const string& ida) {
  return alfabets.find(ida) != alfabets.end();
}


void Alfabets::del_alf(const string& ida) {
  auto it = alfabets.find(ida);
  if (it != alfabets.end()) {
    if(it->second.n_msg_alf() == 0){
      alfabets.erase(it);
      --nalf;
    } else cout << "error: hay mensajes guardados con este alfabeto" << endl;
  } else cout << "error: el alfabeto no existe" << endl;
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


void Alfabets::encrip_sust(const string& ida, const string& msg, const string& cl) {
  int n = msg.size();
  int n_cl = cl.size();
  Alfabet alf = alfabets[ida];
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

void Alfabets::decrip_sust(const string& ida, const string& enc, const string& cl) {
	Alfabet alf = alfabets[ida];
	int n = enc.size();
	int n_c = cl.size();
  bool special = alf.is_special();
  char fl = alf.find_pos_on_map(0);
	string r = enc;

	if (special) {
	  for (int i = 0; i < n; ++i) {
      char c = enc[i];
      char b = cl[i%n_c];
		  char a = c- b;
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


//void Alfabets::encrip_perm(const string& ida,const string& msg, const int& b) {}