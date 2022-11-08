/**
 * @mainpage Encriptación de mensajes.
 * Programa modular para la encriptación de mensajes mediante metodos de
 * substitución o permutación usando las clases <em>Alfabets<em>,
 * <em>Encriptacions<em>, y <em>Missatges<em>
 */

/**
 * @file program.cc
 * @author Pol Casanovas Puig (pol.casanovas.puig@estudiantat.upc.edu)
 * @brief La parte principal de programa con la gestión de la input de los
 * comandos
 * @version 0.1
 * @date 07-11-22
 *
 */

#include "Alfabets.hh"
#include "Encriptacions.hh" //redundant es fa servir dins de les classes
#include "Missatges.hh"
#include <iostream>
using namespace std;

/**
 * @brief Parte principal de programa
 *
 * @return main, no tiene return
 */
int main() {

  Alfabets alf;
  alf.read_alfabets();

  Missatges msg;
  msg.read_missatges();

  Encriptacions enc;

  string s;

  cin >> s;
  while (s != "fin") {
    if (s == "nuevo_mensaje" or s == "nm") {
      string ida;
      cin >> ida;
      if (alf.is_alf_there(ida)) {
        string idm;
        cin >> idm;
        if (!msg.is_msg_there(idm)) {
          msg.add_msg(idm);
          cout << msg.n_msg() << endl;
        } else
          cout << "ja existeix el missatge" << idm << endl;
      } else
        cout << "no existeix l'alfabet: " << ida << endl;

    } else if (s == "nuevo_alfabeto" or s == "na") {
      string ida;
      cin >> ida;
      if (!alf.is_alf_there(ida)) {
        alf.add_alf(ida);
        cout << alf.n_alf() << endl;
      } else
        cout << "ja existeix l'alfabet: " << ida << endl;

    } else if (s == "borra_mensaje" or s == "bm") {
      string idm;
      cin >> idm;
      if (msg.is_msg_there(idm)) {
        msg.del_msg(idm);
        cout << msg.n_msg() << endl;
      } else
        cout << "el missatge " << idm << " no existeix" << endl;

    } else if (s == "borra_alfabeto" or s == "ba") {
      string ida;
      cin >> ida;
      if (alf.is_alf_there(ida)) {
        if (1 > alf.n_of_msg(ida)) {
          alf.del_alf(ida);
        } else
          cout << "l'alfabet " << ida << " conté missatges" << endl;
      } else
        cout << "no existeix l'alfabet " << ida << endl;

    } else if (s == "listar_mensajes" or s == "lm") {
      msg.print_missatges();

    } else if (s == "listar_alfabetos" or s == "la") {
      alf.print_alfabets();

    } else if (s == "codificar_sustitucion_guardado" or s == "csg") {
      string idm;
      cin >> idm;
      if (msg.is_msg_there(idm)) {
        string cl;
        cin >> cl;
        enc.encrip_sust(msg.get_alf(idm), msg.get_msg(idm), cl);
      } else
        cout << "el missatge " << idm << " no existeix" << endl;

    } else if (s == "codificar_sustitucion" or s == "cs") {
      string ida, cl, msg;
      cin >> ida;
      if (alf.is_alf_there(ida)) {
        cin >> cl >> msg;
        enc.encrip_sust(ida, msg, cl);
      } else
        cout << "l'alfabet " << ida << " no existeix" << endl;

    } else if (s == "decodificar_sustitución" or s == "ds") {
      // mirar com fer es pot fer al reves depenent del algoritme
    } else if (s == "codificar_permutacion_guardado" or s == "cpg") {
      string idm;
      cin >> idm;
      if (msg.is_msg_there(idm)) {
        int b;
        cin >> b;
        enc.encrip_perm(msg.get_alf(idm), msg.get_msg(idm), b);
      } else
        cout << "el missatge " << idm << " no existeix" << endl;

    } else if (s == "codificar_permutacion" or s == "cp") {
      string ida, msg;
      int b;
      cin >> ida;
      if (alf.is_alf_there(ida)) {
        cin >> b >> msg;
        enc.encrip_perm(ida, msg, b);
      } else
        cout << "l'alfabet " << ida << " no existeix" << endl;

    } else if (s == "decodificar_permutacion" or s == "dp") {
      // mirar com fer-ho un cop pensat l'algoritme
    }
    cin >> s;
  }
}
