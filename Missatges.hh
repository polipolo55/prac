/**
 * @file Missatges.hh
 * 
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Especificacion del conjunto de Mensajes
 * @version 0.1
 * @date 07-11-22
 * 
 */

#ifndef MISSATGES_HH
#define MISSATGES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/**
 * @class Missatges
 * @brief Es el conjunto de mensajes y contiene los alfabetos con su id y su información
 * 
 */
class Missatges 
{
private: 
  struct msg_info {
    string ida;
    string msg;
  }; 
  map<string, msg_info> missatges;
  int nmsg = 0;
public:

  /**
   * @brief Función creadora de Missatges por defecto. 
   * 
   * \pre <me>cierto<me>
   * \post Crea missatges vacío
   */
  Missatges();



  //void read_missatges(const int& n);

  /**
   * @brief Imprime Missatges por orden alfabético de la id
   * \pre <em>cierto<em>
   * \post Se imprimen los datos en pantalla
   */
  void print_missatges();

     /**
   * @brief Añade el alfabeto identificado por idm
   * 
   * \pre <em>cierto<em>
   * \post Se ha añadido idm a Missatges
   * @param idm 
   */
  void add_msg(const string& idm, const string& ida);

   /**
  * @brief Comprueba que el alfabeto por el identificador ida está en Missatges
  * 
  * \pre <em>cert<em>
  * \post Retorna si ida está en Missatges o no
  * @param idm
  * @return true 
 * @return false 
  */
  bool is_msg_there(const string& idm);

  /**
   * @brief Borra el alfabeto identificado por idm
   * 
   * \pre <em>cierto<em>
   * \post Se ha borrado idm de Missatges
   * @param idm 
   */
  void del_msg(const string& idm);

  /**
   * @brief Obtiene el objeto mensaje con idm
   * 
   * \pre Idm está en Missatges
   * \post Retorna ese mensaje por idm
   * @param idm 
   * @return string 
   */
	string get_msg(const string& idm);

  /**
   * @brief Obtiene el objeto alfabeto asociado con el mensaje idm
   * 
   * \pre Idm está en Missatges
   * \post El alfabeto por ida por mensaje idm
   * @param idm 
   * @return string 
   */
	string get_alf(const string& idm);

  /**
   * @brief Retorna el número de mensajes
   * 
   * \pre <em>Cierto<em>
   * \post Número de mensajes en Missatges
   * @return int 
   */
  int n_msg();
};

#endif
