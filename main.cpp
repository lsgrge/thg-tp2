#include <iostream>
#include "graphe.h"

int main()
{
    //std::string id;
    graphe g{"graphe_2.txt"};

    g.afficher();

    //std::cout << "Entrer le sommet pour parcourir le graphe : ";
    //std::cin >> id;

    g.afficherBFS("1");
    g.afficherDFS("1");

    std::cout << std::endl;
    /// CC
    int ncc = g.rechercher_afficherToutesCC();
    std::cout << std::endl << "Il y a " << ncc << " composantes connexes" << std::endl << std::endl;

    int elerien = g.IsEulerien();
    switch(elerien)
    {
      case 0:
        std::cout<<"Le graphe n'est pas Eulerien "<<std::endl<<std::endl;
        break;
      case 1:
        std::cout<<"Le graphe est une chaine Eulerienne"<<std::endl<<std::endl;
        break;
      case 2:
        std::cout<<"Le graphe est un cycle Eulerien"<<std::endl<<std::endl;
        break;

        //std::cout << ((esteulerien)?"oui":"non")
    }

    return 0;
}
