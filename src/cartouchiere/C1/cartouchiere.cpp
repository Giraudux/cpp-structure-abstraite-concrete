// Alexis Giraudet

#include "genericite.h"
#include "cartouchiere.h"
#include "SDAcartouchiere.h"

cartouchiere creerCartouchiere(int n)//throw exception
{
    if(n < 1)
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

void initialiserCartouchiere(cartouchiere &c, int n)//throw exception
{
    if(n < 1)
    {
        throw std::exception();
    }
    else
    {
        c.nb = n;
        c.tab = new box[n];
        for(int i=0; i<n; ++i)
        {
            c.tab[i].vide = true;
        }
    }
}

bool estVide(const cartouchiere &c, int p)//throw exception
{
    if(p < 0 || p >= c.nb)
    {
        throw std::exception();
    }
    else
    {
        return c.tab[p].vide;
    }
}

int ajouter(cartouchiere &c,T_ELT t)//throw exception
{
    for(int i=0; i<c.nb; ++i)
    {
        if(c.tab[i].vide)
        {
            c.tab[i].vide = false;
            c.tab[i].elt = t;
            return i;
        }
    }
    throw std::exception();
}

void retirer(cartouchiere &c, int p)//throw exception
{
    if(p < 0 || p >= c.nb)
    {
        throw std::exception();
    }
    else
    {
        c.tab[p].vide = true;
    }
}

T_ELT acceder(const cartouchiere &c, int p)//throw exception
{
    if(p < 0 || p >= c.nb || c.tab[p].vide)
    {
        throw std::exception();
    }
    else
    {
        return c.tab[p].elt;
    }
}

void afficher(const cartouchiere &c)
{
    for(int i=0; i<c.nb; ++i)
    {
        std::cout << i << ": ";
        if(c.tab[i].vide)
        {
            std::cout << "vide";
        }
        else
        {
            std::cout << c.tab[i].elt;
        }
        std::cout << std::endl;
    }
}

void detruire(cartouchiere &c)
{
    delete c.tab;
}
