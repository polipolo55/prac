#include "Missatges.hh"
#include <iostream>

using namespace std;

Missatges::Missatges() {}


void Missatges::read_missatges() {
  int n_msg;
  cin >> n_msg;
  for(int i; i < n_msg; ++i) {
    string idm, ida;
    cin >> idm >> ida;
    add_msg(idm, ida);
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
  missatges[idm] = msg_info{msg, ida};
}

