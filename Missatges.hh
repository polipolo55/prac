#ifndef MISSATGES_HH
#define MISSATGES_HH

class Missatges 
{
private: 

public:

  Missatges();

  void read_missatges();

  void print_missatges();

  bool is_msg_there(const string idm);
  
  void add_msg(const string idm);

  void del_msg(const string idm);

	string get_msg(const string idm);

	string get_alf(const string idm);

  int n_msg();
};

#endif
