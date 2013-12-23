// Alexis Giraudet

#ifndef SDACARTOUCHIERE_H
#define	SDACARTOUCHIERE_H

//initialise une nouvelle cartouchière de taille n et la retourne, lève une exception si la taille est incorrecte
cartouchiere creerCartouchiere(int n);//throw std::exception

//initialise la cartouchière de taille n passée en paramètre, lève une exception si la taille est incorrecte
void initialiserCartouchiere(cartouchiere &c, int n);//throw std::exception

//retourne la taille de la cartouchière
int taille(const cartouchiere &c);

//retourne vrai si la case p est vide sinon faux, lève une exception si l'indice est incorrect
bool estVide(const cartouchiere &c, int p);//throw std::exception

//ajoute un élément à la cartouchière et retourne son emplacement dans la cartouchière, lève une exception si la cartouchière est pleine
int ajouter(cartouchiere &c,T_ELT t);//throw std::exception

//vide la case p de la cartouchière, lève une exception si l'indice est incorrect
void retirer(cartouchiere &c, int p);//throw std::exception

//retourne l'élément à l'indice p de la cartouchière, lève une exception si l'indice est incorrect ou si la case est vide
T_ELT acceder(const cartouchiere &c, int p);//throw std::exception

//affiche les éléments de la cartouchière
void afficher(const cartouchiere &c);

//libère la mémoire
void detruire(cartouchiere &c);

#endif
