/**
 * @file Alfabets.hh
 * 
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Especificacion de los Alfabetos
 * @version 0.1 
 * @date 07-11-22
 * 
 */

#ifndef ALFABETS_HH
#define ALFABETS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include "Alfabet.hh"
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
  
public:

  /**
   * @brief Función creadora de Alfabets por defecto. 
   * 
   * \pre <em>cierto<em>
   * \post Crea alfabets vacío
   */
  Alfabets();

  /**
   * @brief Funcion para leer los elementos de Alfabetos
   * \pre un numero A de alfabetos es una sola línea no vacía 
   * \post Alfabets con todos sus ids y datos
   */
  void read_alfabets(const int& a);

  /**
   * @brief Imprime Alfabetos por orden alfabético
   * \pre <em>cierto<em>
   * \post se imprimen los datos en pantalla
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
   */
  bool is_alf_there(const string& ida);

  /**
   * @brief Añade el alfabeto identificado por ida
   * 
   * \pre <em>cierto<em>
   * \post Se ha añadido ida a Alfabetos
   * @param ida 
   */
  void add_alf(const string& ida);

  /**
   * @brief Elimina el mensaje alfabeto identificado por ida
   * 
   * \pre <em>cierto<em>
   * \post Se ha eliminador ida a Alfabetos
   * @param ida 
   */
  void del_alf(const string& ida);

  /**
   * @brief Consulta el némero de Alfabetos
   * 
   * \pre <em>cierto<em>
   * \post Retorna el número de Alfabetos
   * @return int 
   */
  int n_alf();

  /**
   * @brief Consulta el némero de Mensajes en un Alfabeto ida
   * 
   * \pre Ida forma parte de Alfabetos
   * \post Retorna el número de mensajes oara un alfabeto
   * @return int 
   */
  int n_of_msg(const string& ida);
};

#endif
