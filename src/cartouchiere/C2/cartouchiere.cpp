// Alexis Giraudet

// C2

#include "genericite.h"
#include "cartouchiere.h"
#include "SDAcartouchiere.h"

cartouchiere creerCartouchiere(int n)//throw std::exception
{
    if(n < 1)//taille incorrecte
    {
        throw std::exception();
    }
    else
    {
        cartouchiere c;
        initialiserCartouchiere(c, n);
        return c;
    }
}

void initialiserCartouchiere(cartouchiere &c, int n)//throw std::exception
{
    if(n < 1)//taille incorrecte
    {
        throw std::exception();
    }
    else
    {
        c.nb = n;
        c.tete = 0;
        c.queue = 0;
    }
}

int taille(const cartouchiere &c)
{
    return c.nb;
}

bool estVide(const cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb)//indice incorrect
    {
        throw std::exception();
    }
    else
    {
        maillon *m = c.tete;
        while(m != 0)//parcourt des maillons
        {
            if((*m).numero == p)//si le maillon numéro p existe alors la case n'est pas vide
            {
                return false;
            }
            m = (*m).suiv;
        }
        return true;
    }
}

int ajouter(cartouchiere &c,T_ELT t)//throw std::exception
{
    //ajout du maillon dans l'ordre croissant des numéro
    if((c.tete == 0) || (c.queue == 0))//cartouchiere vide
    {
        maillon *tmp = new maillon;
        (*tmp).numero = 0;
        (*tmp).elt = t;
        (*tmp).pre = 0;
        (*tmp).suiv = 0;
        c.tete = tmp;
        c.queue = tmp;
        return 0;
    }
    else if((*c.tete).numero-1 >= 0)//ajout en tête
    {
        int i=(*c.tete).numero-1;
        maillon *tmp = new maillon;
        (*tmp).numero = i;
        (*tmp).elt = t;
        (*tmp).pre = 0;
        (*tmp).suiv = c.tete;
        (*c.tete).pre = tmp;
        c.tete = tmp;
        return i;
    }
    else if((*c.queue).numero+1 < c.nb)//ajout en queue
    {
        int i=(*c.queue).numero+1;
        maillon *tmp = new maillon;
        (*tmp).numero = i;
        (*tmp).elt = t;
        (*tmp).pre = c.queue;
        (*tmp).suiv = 0;
        (*c.queue).suiv = tmp;
        c.queue = tmp;
        return i;
    }
    else//insertion entre deux maillons
    {
        maillon *m1 = c.tete;
        while((*m1).suiv != 0)//parcourt des maillons deux à deux
        {
            maillon *m2 = (*m1).suiv;
            if(((*m1).numero+1) != ((*m2).numero))//les numéros des maillons ne se suivent pas (il y a un écart minimum de 1)
            {
                int i=(*m1).numero+1;
                maillon *tmp = new maillon;
                (*tmp).numero = i;
                (*tmp).elt = t;
                (*tmp).pre = m1;
                (*tmp).suiv = m2;
                (*m1).suiv = tmp;
                (*m2).pre = tmp;
                return i;
            }
            m1 = m2;
        }
    }
    throw std::exception();
}

void retirer(cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb)//indice incorrect
    {
        throw std::exception();
    }
    else
    {
        maillon *m = c.tete;
        while(m != 0)//parcourt des maillons
        {
            if((*m).numero == p)//si on tombe sur le maillon numéro p alors on le désalloue
            {
                if(c.tete == m)
                {
                    c.tete = (*m).suiv;
                }
                else
                {
                    (*((*m).pre)).suiv = (*m).suiv;
                }
                if(c.queue == m)
                {
                    c.queue = (*m).pre;
                }
                else
                {
                    (*((*m).suiv)).pre = (*m).pre;
                }
                delete m;
                break;
            }
            m = (*m).suiv;
        }
    }
}

T_ELT acceder(const cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb || estVide(c,p))//indice incorrect ou le maillon p n'existe pas
    {
        throw std::exception();
    }
    else
    {
        maillon *m = c.tete;
        while(m != 0)//parcourt des maillons
        {
            if((*m).numero == p)//on retourne l'élément du maillon numéro p
            {
                return (*m).elt;
            }
            m = (*m).suiv;
        }
    }
}

void afficher(const cartouchiere &c)
{
    int i=0;
    maillon *m = c.tete;
    while(i < c.nb)//parcourt des numéros de la cartouchière
    {
        std::cout << i << ": ";
        if(m == 0)//plus/pas de maillon
        {
            std::cout << "vide";
        }
        else
        {
            if((*m).numero == i)//affichage de l'élément du ième maillon
            {
                std::cout << (*m).elt;
                m = (*m).suiv;
            }
            else//le maillon i n'existe pas (case vide)
            {
                std::cout << "vide";
            }
        }
        std::cout << std::endl;
        i++;
    }
}

void detruire(cartouchiere &c)
{
    maillon *m = c.tete;
    while(m != 0)//parcourt et destruction des maillons
    {
        maillon *tmp = m;
        m = (*m).suiv;
        delete tmp;
    }
}
