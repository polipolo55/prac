#include "Missatges.hh"
#include "Alfabets.hh"
#include <iostream>

using namespace std;

Missatges::Missatges() {}
Alfabets alf;

void Missatges::read_missatges(){
  int n_msg;
  cin >> n_msg;
  for(int i; i < n_msg; ++i) {
    string idm, ida;
    cin >> idm >> ida;
    add_msg(idm, ida);
    alf.add_msgs_alf(ida, 1);
  }
}
void Missatges::print_missatges() { 
  int num = 1;
	for (auto it = missatges.begin(); it != missatges.end(); ++it) {
		cout << num << ". " << it->first << endl << it->second.ida << endl << '"'<< it->second.msg << '"'<< endl;
		num++;
  }
}

void Missatges::add_msg(const string& idm, const string& ida) {
  string msg;
  cin.ignore(streamsize(),'\n');
  getline(cin, msg);
  missatges[idm].ida = ida;
  missatges[idm].msg = msg;
  ++nmsg;
}

bool Missatges::is_msg_there(const string& idm) {
  return missatges.find(idm) != missatges.end();
}

void Missatges::del_msg(const string& idm) {
  if(auto it = missatges.find(idm) != missatges.end()) {
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

