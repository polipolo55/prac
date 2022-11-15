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

Alfabet Alfabets::get_alf(const string& ida) {
  return alfabets[ida];
}

void Alfabets::encrip_sust(const string& ida, const string& msg, const string& cl) {
  int n = msg.size();
  int n_cl = cl.size();
  Alfabet alf = alfabets[ida];
  int fl = alf.find_pos_on_map(0);
  
  for (int i = 0; i < n; ++i){
    if (alf.is_special()) {
      int px = msg[i] - fl;
      int py = cl[i%n_cl] - fl;
      cout << char(fl + px + py) << " / ";
      //cout << "debug encript -----------------" << endl;
      //cout << px << " " << py << " " << char(px) << " " << char(py) << " " << fl+px+py << " fl:"<< fl << endl;

      //cout << char((px + py - 2*fl)%alf.size() + fl);
      //s[i] = msg[i] + cl[i%n_cl] - 2*char(alf.find_pos_on_map(0))%alf.size() + alf.find_pos_on_map(0);
      


    } else {
      
      //int px = alf.find_pos_on_map(msg[i]);
      //int py = alf.find_pos_on_map(cl[i%n_cl]);
      //char c = char(alf.find_char_int_pos(px + py));
      //cout << px;
      
      //cout << char(alf.find_pos_on_map((alf.find_char_int_pos(msg[i]) + alf.find_char_int_pos(cl[i%n_cl]))%alf.size()));

    }
  }
  //cout << s << endl;
}

void Alfabets::encrip_perm(const string& ida,const string& msg, const int& b) {}