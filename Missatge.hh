#ifndef MISSATGE_HH
#define MISSATGE_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include "Alfabet.hh"
#include "BinTree.hh"
using namespace std;
#endif

class Missatge
{
  private:
    string ida;
    string msg;

    char cod_char(Alfabet alf, const char& px, const char& py);
    //char decod_char(Alfabet alf, const char& px, const char& py);
    BinTree<char> read_tree(const string& s);
    BinTree<char> swap(const char& c, const BinTree<char>& left, const BinTree<char>& right);
    string write_tree(const BinTree<char>& a);
  public:

  Missatge();

  Missatge(const string& in_ida, const string& in_msg);

  string get_ida();

  string get_msg();


  /**
   * @brief encripta mediante el método de sustitución
   * 
   * \pre <me>cierto<me>
   * \post imprime msg codificado por sustitución con el alfabeto ida y la clave cl
   * @param ida 
   * @param msg 
   * @param cl 
   */
  void encrip_sust(const Alfabet& alfabet, const string& msg, const string& cl);

 /**
   * @brief decripta mediante el método de sustitución
   * 
   * \pre <me>cierto<me>
   * \post imprime msg decodificado por sustitución con el alfabeto ida y la clave cl
   * @param ida 
   * @param msg 
   * @param cl 
   */
  void decrip_sust(const Alfabet& alfabet, const string& msg, const string& cl);

  /**
   * @brief encripta mediante el método de permutación
   * 
   * \pre <me>cierto<me>
   * \post imprime msg codificado por permutación con el alfabeto ida y b divisiones
   * @param ida 
   * @param msg 
   * @param b 
   */
  void encrip_perm(const string& msg, const int& b);
};
#endif