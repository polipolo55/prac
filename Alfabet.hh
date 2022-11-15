#ifndef ALFABET_HH
#define ALFABET_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif


class Alfabet 
{
private:
  map<char, int> mapalf;
  bool especial;
  int nmsg = 0;
  string alf;

public:

Alfabet();

Alfabet(const string& input_alf);
void print_alfabet();
bool check_special(const string& s);
void add_msgs_alf(const int& n);
int n_msg_alf();
bool is_special() const;
int size();
int find_pos_on_map(const char& c) ;
int find_char_int_pos(const int& c) ;

};
#endif