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

    int ncc = g.rechercher_afficherToutesCC();
    std::cout<<"le graphe est-il eulerien ? a coder ..."<<std::endl<<std::endl;

    return 0;
}
