#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include "sommet.h"

Sommet::Sommet(std::string id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}
void Sommet::ajouterVoisin(const Sommet* voisin){
    m_voisins.push_back(voisin);
}
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }
void Sommet::afficherVoisins() const{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}

std::unordered_map<std::string,std::string> Sommet::parcoursBFS() const
{
    std::unordered_map<std::string,std::string> l_pred;
    //std::cout<<"BFS a completer"<<std::endl;
    std::queue<const Sommet*> file;
    const Sommet* s;
    file.push(this);

    while(!file.empty())
    {
      s = file.front(); //on récupère le premier élément de la file
      file.pop(); //on vide la file du premier élément

      for(size_t i = 0; i < s->m_voisins.size(); i++)
      {

        if((l_pred.find(s->m_voisins[i]->m_id)) == (l_pred.end()) && (s->m_voisins[i] != this))
        {
          file.push(s->m_voisins[i]);
          l_pred.insert({s->m_voisins[i]->m_id, s->m_id});
        }

      }
    }

    return l_pred;
}


std::unordered_map<std::string,std::string> Sommet::parcoursDFS() const{
    std::unordered_map<std::string,std::string> l_pred;

    std::stack<const Sommet*> pile;
    const Sommet* s;
    pile.push(this);

    while(!pile.empty())
    {
      s = pile.top(); //on récupère le premier élément de la file
      pile.pop(); //on vide la file du premier élément

      for(size_t i = 0; i < s->m_voisins.size(); i++)
      {

        if((l_pred.find(s->m_voisins[i]->m_id)) == (l_pred.end()) && (s->m_voisins[i] != this))
        {
          pile.push(s->m_voisins[i]);
          l_pred.insert( {s->m_voisins[i]->m_id, s->m_id});
        }

      }
    }
    return l_pred;
}


std::unordered_set<std::string> Sommet::rechercherCC() const{
    std::unordered_set<std::string> cc;
    //std::cout<<"rechercherCC a coder"<<std::endl;
    std::unordered_map<std::string, std::string> l_pred;

    l_pred = parcoursBFS();
    cc.insert(m_id);

    for(auto s: l_pred)
      cc.insert(s.first);

    return cc;
}

/*---------------------------------------------------------*/

Sommet::~Sommet()
{
    //dtor
}
