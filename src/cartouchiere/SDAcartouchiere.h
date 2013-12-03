/* 
 * File:   SDAcartouchiere.h
 * Author: didierrobbes
 *
 * Created on 7 novembre 2013, 16:06
 */

#ifndef SDACARTOUCHIERE_H
#define	SDACARTOUCHIERE_H

// le type cartouchiere doit etre defini avant d'inclure cet entete
 
void cart_init(cartouchiere & c, int n );
bool estLibre(const cartouchiere & c, int p);
int ajout(cartouchiere & c,T_ELT t);
void vider(cartouchiere & c,int p);
T_ELT valeurEn(const cartouchiere & c,int p);
void aff(const cartouchiere & c);





#endif	/* SDACARTOUCHIERE_H */

