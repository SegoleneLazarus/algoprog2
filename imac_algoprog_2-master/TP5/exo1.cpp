#include <iostream>
#include <time.h>
#include <vector>
#include <string>

std::vector<std::string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

std::vector<std::string> hash_table;

int hash( std::string element)
{
    // element[0] prend la première lettre du mot
    // size pr les vecteurs, length pour les string
    int somme = 0;
    for(int i=0;i<element.length();i++){
        int val = (int) element[i] % hash_table.size();
        somme += val;
    }
    return somme% hash_table.size();
}
 
void insert(std::vector<std::string>& hash_table, std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    // on compare la valeur du hash à l'indice et on insert

    hash_table[hash(element)] = element;
}


void buildHashTable(std::vector<std::string>& hash_table, std::vector<std::string> names, int namesCount)
{
    for(int i=0;i<namesCount;i++){
        hash_table[i]=names[i];
    }
}

bool contains(std::vector<std::string>& hash_table, std::string element)
{    
    if(hash_table[hash(element)]==element){
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
    hash_table.resize(31);
    buildHashTable(hash_table,names,31);


    std::cout << "le hash de matthieu est le suivant!!!! :  " <<  hash("Matthieu") << "\n";

   for(int i=0;i<names.size();i++){
       std::cout << names[i] << " ; " << "\n";
   }

    insert(hash_table,"Matthieu");

     std::cout << "affiche hash tab mtn" << "\n";

    for(int i=0;i<hash_table.size();i++){
       std::cout << hash_table[i] << " ; " << "\n";
   }

     std::cout << "est-ce Matthieu????????? " << hash_table[27] << "\n";

    std::cout << "le tableau contient matthieu ? " << contains(hash_table,"Matthieu") << "\n";
}