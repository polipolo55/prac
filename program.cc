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
#include "Missatges.hh"
#include "Missatge.hh"
//#include "Encriptacions.hh"
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
  int n;
  cin >> n;
  //msg.read_missatges(n);
  for(int i = 0; i < n; ++i) {
    string idm, ida;
    cin >> idm >> ida;
    alf.add_msgs_alf(ida, 1);
    msg.add_msg(idm, ida);
  }

  //Encriptacions enc;

  Missatge missatge;

  string s;

  cin >> s;
  while (s != "fin") {
    if (s == "nuevo_mensaje" or s == "nm") {
      string idm;
      cin >> idm;
      string ida;
      cin >> ida;
      cout << "#" << s << " " <<idm << ' ' << ida << endl;

      if (alf.is_alf_there(ida)) {
        if (!msg.is_msg_there(idm)) {
          alf.add_msgs_alf(ida, 1);
          msg.add_msg(idm, ida);
          cout << msg.n_msg() << endl;
        } else {
          cout << "error: ya existe un mensaje con ese identificador"<< endl;
        }
      } else { 
        cout << "error: el alfabeto no existe" << endl;
      }

    } else if (s == "nuevo_alfabeto" or s == "na") {
      string ida;
      cin >> ida;
      cout << "#" << s << " " << ida << endl;;
      if (!alf.is_alf_there(ida)) {
        alf.add_alf(ida);
        cout << alf.n_alf() << endl;
      } else
        cout << "error: el alfabeto ya existe" << endl;

    } else if (s == "borra_mensaje" or s == "bm") {
      string idm;
      cin >> idm;
      cout << "#" << s << " " << idm << endl;
      if (msg.is_msg_there(idm)) {
        alf.add_msgs_alf(msg.get_alf(idm), -1);
        msg.del_msg(idm);
        cout << msg.n_msg() << endl;
      } else
        cout << "error: el mensaje no existe" << endl;

    } else if (s == "borra_alfabeto" or s == "ba") {
      string ida;
      cin >> ida;
      cout << "#" << s << " " << ida << endl;
      if (alf.is_alf_there(ida)) {
        if (1 > alf.n_of_msg(ida)) {
          alf.del_alf(ida);
          cout << alf.n_alf() << endl;
        } else cout << "error: hay mensajes guardados con el alfabeto" << endl;
      } else cout << "error: el alfabeto no existe" << endl;
    } else if (s == "listar_mensajes" or s == "lm") {
      cout << "#" << s << endl;
      msg.print_missatges();

    } else if (s == "listar_alfabetos" or s == "la") {
      cout << "#" << s << endl;
      alf.print_alfabets();

    } else if (s == "codificar_sustitucion_guardado" or s == "csg") {
      string idm;
      cin >> idm;
      string cl;
      cin.ignore();
      getline(cin, cl);
      cout << "#" << s << " " << idm << " \"" << cl << "\"" << endl;
      if (msg.is_msg_there(idm)) {
        string ida = msg.get_alf(idm);
        Alfabet alfabet1 = alf.get_alf(ida);
        missatge.encrip_sust(alfabet1, msg.get_msg(idm), cl);
      } else {
        cout << "error: el mensaje no existe" << endl; 
      }

    } else if (s == "codificar_sustitucion" or s == "cs") {
      string ida, cl, msg;
      cin >> ida;
      cin.ignore();
      getline(cin, cl);
      getline(cin, msg);
      cout << "#" << s << " "<< ida << " \"" << cl << "\"" << endl;
      if (alf.is_alf_there(ida)) {
        //cout << "param encrip: " << ida << " " << cl << " " << msg << endl; 
        Alfabet alfabet1 = alf.get_alf(ida);
        missatge.encrip_sust(alfabet1, msg, cl);
      } else cout << "error: el alfabeto no existe" << endl;
      
    } else if (s == "decodificar_sustitucion" or s == "ds") {
      string ida, cl;
      cin >> ida;
      cin.ignore();
      getline(cin, cl);
      cout << "#" << s << " "<< ida << " \"" << cl << "\"" << endl;
      string msg;
      getline(cin, msg);
      if (alf.is_alf_there(ida)) {

        Alfabet alfabet1 = alf.get_alf(ida);
        missatge.decrip_sust(alfabet1, msg, cl);
      }
      else cout << "error: el alfabeto no existe" << endl;
    
    } else if (s == "codificar_permutacion_guardado" or s == "cpg") {
      string idm;
      cin >> idm;
      int b;
      cin >> b;
      cout << "#" << s << " "<< idm << " " << b << endl;
      if (msg.is_msg_there(idm)) {

        missatge.encrip_perm(msg.get_msg(idm), b);
      } else
        cout << "error: el mensaje no existe" << endl;

    } else if (s == "codificar_permutacion" or s == "cp") {
      int b;
      cin >> b;
      string msg;
      cin.ignore();
      getline(cin, msg);
      cout << "#" << s << " " << b << endl;
      missatge.encrip_perm(msg, b);

    } else if (s == "decodificar_permutacion" or s == "dp") {
      int b;
      cin >> b;
      string msg;
      cin.ignore();
      getline(cin, msg);
      cout << "#" << s << " " << b << endl;
      missatge.encrip_perm(msg, b);
    } 
    cin >> s;
  } 
}

