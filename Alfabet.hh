/**
 * @file Alfabet.hh
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief Especificacion del Alfabeto individual
 * 
 */

#ifndef ALFABET_HH
#define ALFABET_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/**
 * @class Alfabet
 * @brief Representa una unidad de alfabeto dentro del conjunto alfabetos
 * 
 */

class Alfabet 
{
private:
  /** @brief Inidica si este alfabeto es escpecial o no, siendo especial un rango de caracteres ascii*/
  bool especial = false;

  /** @brief indica el numero de mensajes en ese alfabeto*/
  int nmsg = 0;

  /** @brief es los del datos del alfabeto de por si con todas sus letras incluso si hay de repetidas*/
  string alf = "";

public:

/**
 * @brief Constructora de Alfabet
 * 
 * Se ejecuta al declarar Alfabeto, no se usa para crear nunca un alfabeto solo pero esta por si acaso
 * \pre <em>cierto<em>
 * \post resulta en la clase alfabeto vacia
 * \cost const
 */
Alfabet();

/**
 * @brief Constructora de Alfabet 
 * 
 * Esta vez crea un nuevo alfabeto vacio pero con un parametro de los datos del alfabeto
 * 
 * @param input_alf 
 * 
 * \pre la string de entrada es una string con un abecedario
 * \post resulta en un alfabeto con datos y si es especial o no
 * \cost lineal respecto tamanyo del alfabeto
 */
Alfabet(const string& input_alf);

/**
 * @brief imprime los todos lo alfabetos con por orden de input 
 * \pre <em>cierto<em>
 * \post se han imprimido los alfabetos
 * \coste constante
 */
void print_alfabet();

/**
 * @brief commprueba si un string es considera especial per tenir les lletres ordenades en lordre del ascii
 * @param s 
 * @return bool
 * \pre <em>cierto<em>
 * \post booleano de si es especial o no
 * \cost lineal a tamanya de alf
 */
bool check_special(const string& s);

/**
 * @brief añade el numero n de mensajes que corresponden al alfabeto
 * @param n
 * \pre  n es un entero puede ser negativo para restar
 * \post ha sumado n al numero de mesajes
 */
void add_msgs_alf(const int& n);

/**
 * @brief retorna el numero de mensajes (nmsg)
 * @return int 
 * @return int
 * \pre <em>cierto<em>
 * \post retorna un int numero de mensajes 
 * \cost const
 */
int n_msg_alf();

/**
 * @brief retorna el booleano special para saber si lo es o no
 * @return bool
 * \pre <em>cierto<em>
 * \post retorna booleano falso o cierto por si es especial en la variable special
 * \cost const
 */
bool is_special() const;

/**
 * @brief se usa para saber el tamaño
 * @return int
 * \pre <em>cierto<em>
 * \post retorna el entero con el tamaño
 * \cost const
 */
int size() const;

/**
 * @brief Saca el string con los datos del alfabeto y los devuelve
 * @return string 
 * \pre <em>cierto<em>
 * \post retorna un string con los datos del alfabeto en la variable alf
 * \cost const
 */
string get_alf() const;
};
#endif