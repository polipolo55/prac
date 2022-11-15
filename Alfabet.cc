#include "Alfabet.hh"

Alfabet::Alfabet() {}

Alfabet::Alfabet(const string& s) {
  alf = s;
  especial = check_special(s);
  int alf_size = alf.size();
  if (especial) mapalf[0] = s[0];
  else for (int i = 0; i < alf_size; ++i) mapalf[alf[i]] = i;
}

void Alfabet::print_alfabet() {
  if (especial) cout << "especial [" << alf[0] << ".." << alf [alf.size() - 1] << "] ";
  else cout << "normal \"" << alf << "\" ";
  cout << nmsg << " mensajes" << endl;
}

bool Alfabet::check_special(const string& s) {
  int i = 1;
  int alf_size = alf.size();
  while (i < alf_size) {
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

char Alfabet::find_pos_on_map(const char& c) {
  return mapalf[c];
}

char Alfabet::find_char_int_pos(const int& c) { 
  return alf[c];
}
