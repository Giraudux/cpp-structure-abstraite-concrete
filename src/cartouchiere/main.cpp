/* 
 * File:   main.cpp
 * Author: didierrobbes
 *
 * Created on 7 novembre 2013, 16:04
 */

#include <cstdlib>
#include <iostream>

// pour definir le type T_ELT
#include "genericite.h"

// les declarations specifiques de la SDC choisie
// le fichier est en fait dans le dossier de la SDC
#include "cartouchiere.h"

// les declarations communes quelque soit la SDC
#include "SDAcartouchiere.h"

using namespace std;

/*
 * 
 */
int main() {
    T_ELT rep;
    cout << "donnez une valeur "<<endl;
    cin >> rep;
    
    cartouchiere cart;
    cart_init(cart,5);   
         
    int p= ajout(cart,rep);      
    cout<< p << ":" << valeurEn(cart,p) << endl; 
    
    return 0;
}

