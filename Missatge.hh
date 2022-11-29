/**
 * @file Missatge.hh
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Especificació de la classe Missatges
 *  
 */

#ifndef MISSATGE_HH
#define MISSATGE_HH


#include "Alfabets.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
using namespace std;
#endif

/**
 * @class Missatge
 * @brief Representa una sola unidad de mensaje con sus datos y sus operacions de encriptaciones
 * 
 * Definimos mensaje vacio aunque siempre se usara la constructora con los datos
 * 
 */
class Missatge
{
  private:
    /** @brief indica al alfabeto del mensaje*/
    string ida;
    /** @brief indica la informacion del alfabeto*/
    string msg;

    /**
     * @brief 
     * 
     * @param s 
     * @return BinTree<char> 
     * \pre <em>cierto<em>
     * \post devuelve un arbol con string s en posicion inorder
     * \cost lineal por el tamaño de s
     */
    BinTree<char> read_tree(const string& s);

    /**
     * @brief intercambia los el arbol entre derecha y izquierda
     * 
     * @param c 
     * @param left 
     * @param right 
     * @return BinTree<char> 
     * \pre c es la raiz del arbol left la izquierda y right la derecha
     * \post left y right se han intercambiado de lado y se devuelve un arbol de chars
     * \cost logaritmico por el tamaño del arbol
     */
    BinTree<char> swap(const char& c, const BinTree<char>& left, const BinTree<char>& right);

    /**
     * @brief convierte un arbol a una string
     * @param a 
     * @return string 
     * \pre <em>cierto<em>
     * \post devuelve el arbol esrito en forma de string de forma inorden
     * \cost lineal por el tamaño de a
     */
    string write_tree(const BinTree<char>& a);

  public:

  /**
   * @brief Constructora de Missatge vacio
   * 
   * \pre <em>cierto<em>
   * \post se ha construido missatge
   * \cost const
   */
  Missatge();

  /**
   * @brief Constructora de Missatge
   * 
   * @param in_ida 
   * @param in_msg 
   * \pre in_ida es un identificador que pertenece a alfabetos y msg es el texto del mensaje
   * \post crea un mensaje con con sus respectivos datos
   * \cost const
   */
  Missatge(const string& in_ida, const string& in_msg);

  /**
   * @brief Saca el identificador del alfabeto al que forma parte el mensaje
   * @return string 
   * \pre <em>cierto<em>
   * \post devuelve la string del id identificador del alfabeto
   * \cost const
   */
  string get_ida();

  /**
   * @brief Saca el texto que compone el mensaje
   * @return string 
   * \pre <em>cierto<em>
   * \post devuelve el string con el texto del mensaje
   * \cost const
   */
  string get_msg();


  /**
   * @brief codifica mediante el método de sustitución 
   * @param ida 
   * @param msg 
   * @param cl 
   * \pre alfabet es el alfabeto en el que estan escritos el mensaje i la clave, estos pueden estar vacios pero siempre del alfabeto
   * \post imprime msg codificado por sustitución con el alfabeto ida y la clave cl
   * \cost lineal por el tamaño de msg
   */
  void encrip_sust(const Alfabet& alfabet, const string& msg, const string& cl);

 /**
   * @brief decodifica mediante el método de sustitución
   * 
   * @param ida 
   * @param msg 
   * @param cl 
   * \pre enc i cl estan estan escritos en el alfabeto, poden estar vacios pero tienen que coincidir con alfabeto
   * \post imprime msg decodificado por sustitución con el alfabeto ida y la clave cl
   * \cost lineal por el tamaño nec
   */
  void decrip_sust(const Alfabet& alfabet, const string& enc, const string& cl);

  /**
   * @brief encripta mediante el método de permutación
   * @param ida 
   * @param msg 
   * @param b 
   * \pre <em>cierto<em>
   * \post imprime msg codificado por permutación con b divisiones
   * \cost lineal por msg
   */
  void encrip_perm(const string& msg, const int& b);
};
#endif