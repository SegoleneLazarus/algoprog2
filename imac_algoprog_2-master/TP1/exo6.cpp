#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    int capacite;
    int taille;
};


void initialise(Liste* liste)
{
//premier doit être nul
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* nv = new Noeud;
    nv->donnee = valeur;
    nv->suivant = liste->premier;
    liste->premier = nv;

    Noeud* dernier = liste->premier;

    if(dernier != nullptr){
        while (dernier->suivant != nullptr)
        {   dernier = dernier->suivant; }
        dernier->suivant = nv;
    }
    else{
        liste->premier = nv;
    }
}

void affiche(const Liste* liste)
{
    Noeud *nv = liste->premier;

    while(nv->suivant != nullptr){
        std::cout << nv->donnee <<endl;
        nv = nv->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud* iterateur = liste->premier;
    if(n == 0){
        return iterateur->donnee;
    }
    for(int i = 1; i<n+1; i++) {
        iterateur = iterateur->suivant;
    }
    return iterateur->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* current;
    current = liste->premier;
    int itterateur = 1;
    while (current->suivant != nullptr) {
        if (current->donnee == valeur) {
            return itterateur;
        }
        itterateur++;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    for(int i = 0; i<n; i++) {
        liste->premier = liste->premier->suivant;
    }
    liste->premier->donnee = valeur;
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille == tableau->capacite){
        tableau->capacite = tableau->capacite+5;
        
    }
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int[capacite];
    tableau->taille = 0;
    tableau->capacite = capacite;

}

bool est_vide(const DynaTableau* liste)
{
    if (liste->taille == 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

void affiche(const DynaTableau* tableau)
{
    for (int i = 0; i < tableau->taille; i++){
        cout << tableau->donnees[i] << endl;
    }

}

int recupere(const DynaTableau* tableau, int n)
{
    if(n >= tableau->taille){
        exit(1);
    }
    return tableau->donnees[n];

}

int cherche(const DynaTableau* tableau, int valeur)
{
    for (int i = 0; i < tableau->taille; i++)
    {
        if (tableau->donnees[i] == valeur)
        {
            return i;
        }
    }

    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n >= tableau->taille){
        exit(1);
    }

    tableau->donnees[n] = valeur;


}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud* nouveauNoeud = new Noeud;
    nouveauNoeud->donnee = valeur;
    nouveauNoeud->suivant = nullptr;

    if (liste->premier == nullptr){
        liste->premier = nouveauNoeud;
    }
    else{
        Noeud* dernier = liste->premier;
        while (dernier->suivant != nullptr){
            dernier = dernier->suivant;
        }
        dernier->suivant = nouveauNoeud;
    }

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int value = liste->premier->donnee;
    liste->premier = liste->premier->suivant;
    return value;

}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud* nouveauNoeud = new Noeud;
    nouveauNoeud->donnee = valeur;
    nouveauNoeud->suivant = nullptr;

    if (liste->premier == nullptr){
        liste->premier = nouveauNoeud;
    }
    else{
        Noeud* dernier = liste->premier;
        while (dernier->suivant != nullptr){
            dernier = dernier->suivant;
        }
        dernier->suivant = nouveauNoeud;
    }
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    int value = liste->premier->donnee;
    liste->premier = liste->premier->suivant;
    return 0;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
