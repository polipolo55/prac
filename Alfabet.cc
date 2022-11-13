#include "Alfabet.hh"

Alfabet::Alfabet() {}

Alfabet::Alfabet(const string& s) {
  alf = s;
  int i = 1;
  int alf_size = alf.size();
  while (especial and i < alf_size) {
    if (s[i] != s[i-1] + 1) especial = false;
    ++i;
  }
  if (not especial) {
    for (int i = 0; i < alf_size; ++i) mapalf[alf[i]] = i;
  } else mapalf[0] = alf[0];
}

void Alfabet::print_alfabet() {
  if (especial) cout << "especial [" << alf[0] << ".." << alf [alf.size() - 1] << "] ";
  else cout << "normal \"" << alf << "\" ";
  cout << nmsg << " mensajes" << endl;
}

void Alfabet::add_msgs_alf(const int& n) {
  nmsg += n;
}

int Alfabet::n_msg_alf() {
  return nmsg;
}

bool Alfabet::is_special() {
  return especial;
}

int Alfabet::size() {
  return alf.size();
}

char Alfabet::find_pos_on_map(const char& c) {
  return mapalf[c];
}

char Alfabet::find_pos_of_char(const char& c) {
  return alf[c];
}
