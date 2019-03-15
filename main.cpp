#include <iostream>
#include "graphe.h"

int main()
{
    //std::string id;
    graphe g{"graphe_1.txt"};

    g.afficher();

    //std::cout << "Entrer le sommet pour parcourir le graphe : ";
    //std::cin >> id;

    g.afficherBFS("1");
    g.afficherDFS("1");

    std::cout << std::endl;
    /// CC
    int ncc = g.rechercher_afficherToutesCC();
    std::cout << std::endl << "Il y a " << ncc << " composantes connexes" << std::endl;

    std::cout<<"le graphe est-il eulerien ? a coder ..."<<std::endl<<std::endl;

    return 0;
}
