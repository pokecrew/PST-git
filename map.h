#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

// Définition du type de décors, ici ARBRE=0, BATIMENT=1
typedef enum Decors_type Decors_type;
enum Decors_type
{
    ARBRE, BATIMENT, AUTRE
};


typedef struct Case Case;

//Structure des objets Case
struct Case{
    int x;        //ligne de la carte
    int y;        //colonne de la carte
    int type;   // type de case (franchissable, infranchissable)
    int numIMG; //nom de l'image de la case
    SDL_Rect position; //positions de la surface
};

typedef struct Decors Decors;

//Structure des objets Décors
struct Decors{
    int dim_x;        //dimension en largeur (nombre de case)
    int dim_y;        //dimension en longueur (nombre de case)
    int pos_x;        //position sur l'axe des x (nombre de case)
    int pos_y;        //position sur l'axe des y (nombre de case)
    int repeat_x;     //nombre de répétitions de l'objet sur les x
    int repeat_y;     //nombre de répétitions de l'objet sur les y
    Decors_type type;   //type de décors (arbre, batiment, etc)
    int numIMG; //nom de l'image de la case
    SDL_Rect position; //positions de la surface
    Decors *suivant; //adresse du décors suivant dans la file
};

//file des décors de la map
typedef struct FileDecors FileDecors;
struct FileDecors
{
    Decors *premier; //adresse du premier décors de la file
};


Case **createMap(char mapPath[]);
int loadMap(char mapPath[], Case **Map);
void chargerSpritesMap();
void displayMap(Case **Map, SDL_Surface *ecran);
FileDecors *initialiserFileDecors();//fonction qui initialise la file de Décors
int chargerDecors(char mapPath[], FileDecors *file);//fonction qui charge les éléments un à un dans la file
Decors chargerCaracteristiquesDecors(char *chaine);
void ajouterElementFileDecors(FileDecors *file, char *chaine);//Fonction qui rajoute un élément à la file de décors (à la fin)
int viderFileDecors(FileDecors *file);//Fonction qui vide la file
void afficherFileTerm(FileDecors *file); //Fonction qui affiche dans le terminal les éléments de la file des décors
#endif // MAP_H_INCLUDED
