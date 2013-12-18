// Alexis Giraudet

#ifndef SDACARTOUCHIERE_H
#define	SDACARTOUCHIERE_H

cartouchiere creerCartouchiere(int n);//throw exception
void initialiserCartouchiere(cartouchiere &c, int n);//throw exception
bool estVide(const cartouchiere &c, int p);//throw exception
int ajouter(cartouchiere &c,T_ELT t);//throw exception
void retirer(cartouchiere &c, int p);//throw exception
T_ELT acceder(const cartouchiere &c, int p);//throw exception
void afficher(const cartouchiere &c);
void detruire(cartouchiere &c);

#endif
