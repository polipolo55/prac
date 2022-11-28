#include "Alfabet.hh"

Alfabet::Alfabet() {}

Alfabet::Alfabet(const string& s) {
  alf = s;
  especial = check_special(s);
}

void Alfabet::print_alfabet() {
  if (especial) cout << "especial [" << alf[0] << ".." << alf [alf.size() - 1] << "] ";
  else cout << "normal \"" << alf << "\" ";
  cout << nmsg << " mensajes" << endl;
}

bool Alfabet::check_special(const string& s) {
  int i = 1;
  while (i < alf.size()) {
    if (s[i] != s[i-1] + 1) return false;
    ++i;
  }
  return true;
}

void Alfabet::add_msgs_alf(const int& n) {
  nmsg += n;
}

int Alfabet::n_msg_alf() {
  return nmsg;
}

bool Alfabet::is_special() const{
  return especial;
}

int Alfabet::size() {
  return alf.size();
}

string Alfabet::get_alf() const{
  return alf;
}
