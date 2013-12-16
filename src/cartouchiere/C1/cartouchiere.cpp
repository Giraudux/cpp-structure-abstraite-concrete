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
    ;
}

int ajouter(cartouchiere &c,T_ELT t)//throw exception
{
    ;
}

void retirer(cartouchiere &c, int p)//throw exception
{
    ;
}

T_ELT acceder(const cartouchiere &c, int p)//throw exception
{
    ;
}

void afficher(const cartouchiere &c)
{
    ;
}
