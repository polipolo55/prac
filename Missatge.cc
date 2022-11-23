#include "Missatge.hh"
using namespace std;

Missatge::Missatge() {}

Missatge::Missatge(const string& in_ida, const string& in_msg) {
  ida = in_ida;
  msg = in_msg;
}

string Missatge::get_ida() {
  return ida;
}

string Missatge::get_msg() {
  return msg;
}

void Missatge::encrip_sust(const Alfabet& alfabet,const string& msg, const string& cl) {
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

void Missatge::decrip_sust(const Alfabet& alfabet, const string& enc, const string& cl) {
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

BinTree<char> Missatge::swap() {
  BinTree<char> a;
  return a;
}
BinTree<char> Missatge::read_tree(const string& s) {
  if (s.size() == 0) return BinTree<char>();
	int n = s.size();
	int m;
	if (n%2 == 1) m = n/2;
	else m = n/2 - 1;
	BinTree<char> left, right;
	string sleft, sright;
	for (int i = 0; i < m; ++i) sleft += s[i];
	for (int i = m + 1; i < n; ++i) sright += s[i];

	left = read_tree(sleft);
	right = read_tree(sright);

	BinTree<char> aux_l, aux_r;
	if (not left.empty()) aux_l = BinTree<char>(right.value(), left.left(), left.right());
	if (not right.empty() && not left.empty()) aux_r = BinTree<char>(left.value(), right.left(), right.right());
	else if (not right.empty()) aux_r = right;

	return BinTree<char>(s[m], aux_l, aux_r);
}

string Missatge::write_tree(const BinTree<char>& t) {
  string s, aux_r;
  if (not t.left().empty()) {
    s = write_tree(t.left());
  }
  s += t.value();
  if (not t.right().empty()) {
      aux_r = write_tree(t.right());
  }
  s += aux_r;
  return s;
}


void Missatge::encrip_perm(const string& msg, const int& b) {
  int msg_size = msg.size();
  int num_parts = msg_size/b + bool(msg_size%b);
  
  if (msg_size == 0) {
    cout << endl;

  } else if (num_parts <= 1) {
    BinTree<char> arb1 = read_tree(msg);
    cout << "\""<< write_tree(arb1) << "\""<< endl;

    
  } else {
    int i = 0;
    int q = b;
    string cod;
    while (i < msg_size) {
      string temp_cod;
      while (i < q and i < msg_size) {
        temp_cod.push_back(msg[i]);
        i++;
      }
      q += b;
      BinTree<char> a = read_tree(temp_cod);
      temp_cod = write_tree(a);
      cod += temp_cod;
    }
  cout << "\""<< cod << "\""<< endl;  }
}