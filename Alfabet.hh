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
  int n_msg = 0;
  string alf;

public:

Alfabet();

Alfabet(const string& alf);
void print_alfabet();
void add_msg_alf(const int& n);
int n_msg_alf();
int n_of_msg();

};
#endif