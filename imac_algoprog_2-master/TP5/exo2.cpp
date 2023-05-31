#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>


using std::size_t;
using std::string;


std::vector<string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key){
    int cpt = 0;
    unsigned long int value_hash = 0;

    while(key[cpt] != '\0'){
        value_hash += key[cpt]* std::pow(128,cpt);
    }

    return value_hash;
    // longueur de la chaine
    // - de la [position du truc]-1
    // = exposant de ta base
}

struct MapNode
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    void insertNode(MapNode* node)
    {
        // todo
        if (this->key_hash > node->key_hash && this->left == nullptr) {
            this->left = node;
        }
        else if (this->key_hash > node->key_hash) {
            this->left->insertNode(node);
        }
        else if (this->key_hash < node->key_hash && this->right == nullptr) {
            this->right = node;
        }
        else if (this->key_hash < node->key_hash) {
            this->right->insertNode(node);
        }

    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    void insert(string key, int value)
    {
        if (this->root == nullptr) {
            this->root = new MapNode(key,value);
        }
        else {
            this->root->insertNode(key,value);
        }
    }

    int get(string key)
    {
        MapNode* noeud = this->root;
        while (noeud != nullptr){
            if (noeud->key == key){
                return noeud->value;
            }
            else if (noeud->key_hash < hash(key)){
                noeud = noeud->right;
            }
            else {
                noeud = noeud->left;
            }
        }
        return -1;
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));
}
