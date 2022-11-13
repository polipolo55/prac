#ifndef ALFABET_HH
#define ALFABET_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

class Alfabet 
{
private:
  map<char, char> mapalf;
  bool especial = true;
  int nmsg = 0;
  string alf;

public:

Alfabet();

Alfabet(const string& input_alf);
void print_alfabet();
void add_msgs_alf(const int& n);
int n_msg_alf();
bool is_special();
int size();
char find_pos_on_map(const char& c);
char find_pos_of_char(const char& c);

};
#endif