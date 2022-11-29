/**
 * @file Alfabets.hh
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Especificacion de la clase Alfabets que representa el conjunto de varios alfabetos y su id
 *  
 */

#ifndef ALFABETS_HH
#define ALFABETS_HH

#include "Alfabet.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/**
 * @class Alfabets
 * @brief Es el conjunto de alfabetos y contiene los alfabetos con su id y su información
 * 
 */
class Alfabets 
{
private:
  map<string, Alfabet> alfabets;
  int nalf = 0;

  
public:

  /**
   * @brief Función creadora de Alfabets por defecto. 
   * 
   * \pre <em>cierto<em>
   * \post Crea alfabets vacío
   * \cost const
   */
  Alfabets();

  /**
   * @brief Funcion para leer los elementos de Alfabetos
   * \pre un numero A de alfabetos es una sola línea no vacía 
   * \post Alfabets con todos sus ids y datos
   * \cost lineal respeto numero de alfabetos
   */
  void read_alfabets();

  /**
   * @brief Imprime Alfabetos por orden alfabetico
   * \pre <em>cierto<em>a
   * \post se imprimen los datos en pantalla
   * \cost lineal respeto numero de alfabetos
   */
  void print_alfabets();

  /**
   * @brief Comprueba que el alfabeto por el identificador ida está en Alfabetos
   * 
   * \pre <em>cierto<em>
   * \post retorna si ida está en Alfabetos o no
   * @param ida 
   * @return true 
   * @return false 
   * \cost const
   */
  bool is_alf_there(const string& ida);

  /**
   * @brief Añade el alfabeto identificado por ida
   * 
   * \pre <em>cierto<em>
   * \post Se ha añadido ida a Alfabetos
   * @param ida 
   * \cost lineal respeto numero de alfabetos en el mapa
   */
  void add_alf(const string& ida);

  /**
   * @brief Elimina el mensaje alfabeto identificado por ida
   * 
   * \pre <em>cierto<em>
   * \post Se ha eliminador ida a Alfabetos
   * @param ida 
   * \cost lineal respeto numero de alfabetos en el mapa
   */
  void del_alf(const string& ida);

  /**
   * @brief Consulta el némero de Alfabetos
   * 
   * \pre <em>cierto<em>
   * \post Retorna el número de Alfabetos
   * @return int 
   * \cost constante
   */
  int n_alf() const;

  /**
   * @brief Consulta el némero de Mensajes en un Alfabeto ida
   * 
   * \pre Ida forma parte de Alfabetos
   * \post Retorna el número de mensajes oara un alfabeto
   * @return int 
   * \cost const
   */
  int n_of_msg(const string& ida);

  /**
   * @brief 
   * 
   * @param ida 
   * @param n 
   * \pre ida pertany a alfabets i n es un enter
   * \post nmsg += n
   * \cost const
   */
  void add_msgs_alf(const string& ida, const int& n);

  /**
   * @brief Saca el alfabateo correspondiente a ida
   * 
   * @param ida 
   * @return * Alfabet 
   * \pre ida forma de parte de alfabetos 
   * \post devuelve alfabeto
   * \cost const
   */
  Alfabet get_alf(const string& ida);

  //void encrip_sust(const string& ida, const strsing& msg, const string& cl);

  //void decrip_sust(const string& ida, const string& enc, const string& cl);

  //void encrip_perm(const string& ida,const string& msg, const int& b);

};

#endif
