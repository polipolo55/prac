#ifndef ALFABETS_HH
#define ALFABETS_HH

class Alfabets 
{
private:
  
public:

  Alfabets();

  void read_alfabets();

  void print_alfabets();

  bool is_alf_there(const string ida);

  void add_alf(const string ida);

  void del_alf(const string ida);

  int n_alf();

  int n_of_msg(const string ida);
};

#endif
