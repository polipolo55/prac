#include "Missatges.hh"
#include "Alfabets.hh"
#include <iostream>

using namespace std;

Missatges::Missatges() {}
Alfabets alf;

//void Missatges::read_missatges(const int& n){}
void Missatges::print_missatges() { 
  int num = 1;
	for (auto it = missatges.begin(); it != missatges.end(); ++it) {
		cout << num << ". " << it->first << endl << it->second.ida << endl << '"'<< it->second.msg << '"'<< endl;
		num++;
  }
}

void Missatges::add_msg(const string& idm, const string& ida) {
  string msg;
  cin.ignore(1024,'\n');
  getline(cin, msg);
  msg_info aux;
  aux.ida = ida;
  aux.msg = msg;
  missatges[idm] = aux;
  ++nmsg;
}

bool Missatges::is_msg_there(const string& idm) {
  return missatges.find(idm) != missatges.end();
}

void Missatges::del_msg(const string& idm) {
  auto it = missatges.find(idm);
  if(it != missatges.end()) {
    missatges.erase(idm);
    --nmsg;
  }
  else cout << "error! El mensaje no existe" << endl;
}

string Missatges::get_msg(const string& idm) {
  return missatges[idm].msg;
}

string Missatges::get_alf(const string& idm) {
  return missatges[idm].ida;
}
int Missatges::n_msg() {
  return nmsg;
}

