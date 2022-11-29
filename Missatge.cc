/**
 * @file Missatge.cc
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Codigo de la clase missatges
 * 
 */

#include "Missatge.hh"

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
  //cout << "comença la encrip" << endl;
  int n = msg.size();
  int n_cl = cl.size();
  Alfabet alf = alfabet;
  string alf_data = alf.get_alf();
  int alf_size = alf_data.size();
  char fl = alf_data[0];
  string s;
  
  if (alf.is_special()) {
    //cout << "es especial" << endl;
    int px = 0;
    int py = 0;
    while (px < n) {
      int pos = (msg[px] - fl) + (cl[py] - fl);
      if (pos >= alf_size) pos = pos - alf_size;
      s.push_back(alf_data[pos]);
      px++;
      py++;
      if (py >= n_cl) py = 0;
    }
  } else {
    //cout << "no es especial " << "alf: " << alf_data << endl;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      int px = 0;
      int py = 0;
      while (alf_data[px] != msg[i] or alf_data[py] != cl[pos]) {
        if (alf_data[px] != msg[i]) px++;
        if (alf_data[py] != cl[pos]) py++;
      }
      px = px + py;
      if (px >= alf_size) px = px - alf_size;
      s.push_back(alf_data[px]);
      ++pos;
      if (pos >= n_cl) pos = 0;
    }
    //cout << "fi bucle" << endl;
  }
  cout << "\""<< s << "\"" <<endl;
}


void Missatge::decrip_sust(const Alfabet& alfabet, const string& enc, const string& cl) {
	int n = enc.size();
  int n_cl = cl.size();
  Alfabet alf = alfabet;
  string alf_data = alf.get_alf();
  int alf_size = alf_data.size();
  string r;
  if (alf.is_special()) {
  	int i = 0;
		int j = 0;
		while (i < n) {
			int pos_c = (enc[i] - alf_data[0]) - (cl[j] - alf_data[0]); //usar modulo
			if (pos_c < 0) pos_c = pos_c + alf_size;
			r.push_back(alf_data[pos_c]);
			i++;
			j++;
			if (j >= n_cl) j = 0;
		}
	}
	else {
		int pos = 0;
		for (int i = 0; i < n; i++) {

			int px = 0;
			int py = 0;
			while (alf_data[px] != enc[i] or alf_data[py] != cl[pos]) {
				if (alf_data[px] != enc[i]) px++;
				if (alf_data[py] != cl[pos]) py++;

			}
			px = px - py;
			if (px < 0) px = px + alf_size;
			r.push_back(alf_data[px]);
			pos++;
			if (pos >= n_cl) pos = 0;
		}
	}
	cout << '"' << r << '"' << endl;
}

BinTree<char> Missatge::swap(const char& c, const BinTree<char>& left, const BinTree<char>& right) {
	BinTree<char> l_aux, r_aux;
	if (not left.empty()) l_aux = BinTree<char>(right.value(), left.left(), left.right());
	if (not right.empty() and not left.empty()) r_aux = BinTree<char>(left.value(), right.left(), right.right());
	else if (not right.empty()) r_aux = right;

	return BinTree<char>(c, l_aux, r_aux);
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

  return swap(s[m], left, right);

}

string Missatge::write_tree(const BinTree<char>& t) {
  string s, r_aux;
  if (not t.left().empty()) {
    s = write_tree(t.left());
  }
  s += t.value();
  if (not t.right().empty()) {
      r_aux = write_tree(t.right());
  }
  s += r_aux;
  return s;
}


void Missatge::encrip_perm(const string& msg, const int& b) {
  int msg_size = msg.size();
  int num_parts = msg_size/b + bool(msg_size%b);
  
  if (msg_size == 0) {
    cout << "\"\""<< endl;

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