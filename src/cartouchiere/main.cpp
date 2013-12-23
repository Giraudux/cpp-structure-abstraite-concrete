// Alexis Giraudet

#include "main.h"

int main(int argc, char *argv[])
{
    //récupération d'une taille de cartouchière correcte
    int n=0;
    while(n < 1)
    {
        std::cout << "nombre de chambres de l'hôtel (>0) = ";
        std::cin >> n;
    }
    cartouchiere c = creerCartouchiere(n);
    
    //menu du programme
    int menu=-1;
    while(menu != 0)
    {
        std::cout << std::endl;
        std::cout << "0 - Quitter" << std::endl;
        std::cout << "1 - Accueillir un nouveau client" << std::endl;
        std::cout << "2 - Libérer une chambre" << std::endl;
        std::cout << "3 - Afficher les clients de l'hôtel" << std::endl;
        std::cout << "choix (0-3) = ";
        std::cin >> menu;
        std::cout << std::endl;
        
        //lecture du choix de l'utilisateur
        switch(menu)
        {
            case 1://ajouter d'un nouvel élément à la cartouchière
            {
                //lecture de la chaîne de caractères (nom du client)
                std::cout << "nom du nouveau client = ";
                char nom[32];
                std::cin.ignore();
                std::cin.getline(nom,32);
                try//tentative d'ajout de l'élément à la cartouchière
                {
                    std::string client(nom);
                    int chambre = ajouter(c,client);
                    //ajout réussi
                    std::cout << "chambre " << chambre << " attribuée au client " << client << std::endl;
                }
                catch(std::exception &e)//échec de l'ajout
                {
                    std::cout << "pas de chambre disponible" << std::endl;
                }
                break;
            }
            case 2://retirer un élément de la cartouchière
            {
                //lecture de l'indice de l'élément à retirer
                int chambre=0;
                std::cout << "numéro de la chambre à libérer = ";
                std::cin >> chambre;
                try//tentative de suppression de l'élément de la cartouchière
                {
                    retirer(c,chambre);
                    //suppression réussie
                    std::cout << "la chambre " << chambre << " est libre" << std::endl;
                }
                catch(std::exception &e)//échec de la suppression
                {
                    std::cout << "la chambre " << chambre << " n'existe pas" << std::endl;
                }
                break;
            }
            case 3:
            {
                afficher(c);//affichage des éléments de la cartouchière
                //calcul du taux d'occupation
                int acc=taille(c);
                for(int i=0; i<taille(c); ++i)
                {
                    if(estVide(c,i))
                    {
                        acc--;
                    }
                }
                std::cout << "occupation = " << 100*acc/taille(c) << "%" << std::endl;
                break;
            }
        }
    }
    
    //libération de la mémoire
    detruire(c);
    
    return 0;
}
