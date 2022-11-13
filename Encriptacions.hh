/**
 * @file Encriptacions.hh
 * 
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief  Especificacion de los metodos de encriptacion
 * @version 0.1
 * @date 07-11-22
 * 
 */

#ifndef ENCRIPTACIONS_HH
#define ENCRIPTACIONS_HH 

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/**
 * @class Encriptacions
 * @brief Contiene los metodos prehechos de encriptar un mensaje
 * 
 */
class Encriptacions
{
private:

public:

  /**
   * @brief Función creadora de Encriptacions por defecto. 
   * 
   * \pre <em>cierto<em>
   * \post Crea alfabets vacío
   */
  Encriptacions();

  /**
   * @brief encripta mediante el método de sustitución
   * 
   * \pre <me>cierto<me>
   * \post imprime msg codificado por sustitución con el alfabeto ida y la clave cl
   * @param ida 
   * @param msg 
   * @param cl 
   */
  void encrip_sust(const Alfabet& alf, const string& msg, const string& cl);

  /**
   * @brief encripta mediante el método de permutación
   * 
   * \pre <me>cierto<me>
   * \post imprime msg codificado por permutación con el alfabeto ida y b divisiones
   * @param ida 
   * @param msg 
   * @param b 
   */
  void encrip_perm(const string& ida,const string& msg, const int& b);
  
};

#endif