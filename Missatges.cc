#include "Missatges.hh"
#include <iostream>

using namespace std;

Missatges::Missatges() {}

//void Missatges::read_missatges(const int& n){}
void Missatges::print_missatges() { 
  int num = 1;
	for (auto it = missatges.begin(); it != missatges.end(); ++it) {
		cout << num << ". " << it->first << endl << it->second.get_ida() << endl << '"'<< it->second.get_msg() << '"'<< endl;
		num++;
  }
}

void Missatges::add_msg(const string& idm, const string& ida) {
  string msg;
  cin.ignore(1024,'\n');
  getline(cin, msg);
  missatges[idm] = Missatge(ida, msg);
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
  return missatges[idm].get_msg();
}

string Missatges::get_alf(const string& idm) {
  return missatges[idm].get_ida();
}
int Missatges::n_msg() {
  return nmsg;
}

