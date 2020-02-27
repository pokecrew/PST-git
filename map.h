#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

// Définition du type de décors, ici ARBRE=0, BATIMENT=1
typedef enum Decors_type Decors_type;
enum Decors_type
{
    SOL, MUR, INTERIEUR1, ARBRE, BATIMENT, PNJ, EVENEMENT, AUTRE
};


typedef struct Case Case;

//Structure des objets Case
struct Case{
    int x;        //ligne de la carte
    int y;        //colonne de la carte
    int type;   // type de case (franchissable, infranchissable, hautes herbes, saut)
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

typedef struct Porte Porte;
struct Porte{
    int pos_x;        //position coin supérieur gauche en largeur(case)
    int pos_y;        //position coin supérieur gauche en hauteur(case)
    int dim_x;        //position coin inférieur droit en largeur (case)
    int dim_y;        //position coin inférieur droit en hauteur (case)
    int map;         //nom de la map vers laquelle elle pointe
    SDL_Rect position; //positions de la surface (débogage)
    SDL_Rect pos_perso; //positions du personnage sur la nouvelle map
    Porte *suivant; //adresse de la porte suivante dans la file
};

typedef struct FilePorte FilePorte;
struct FilePorte
{
    Porte *premier; //adresse du premier décors de la file
};
//Map
Case **createMap(char mapPath[]);
int loadMap(char mapPath[], Case **Map);
void chargerSpritesMap();
void displayMap(Case **Map, SDL_Surface *ecran, Perso perso);
void effacerEcran(SDL_Surface *noir, SDL_Surface *ecran);
int chargerObjets(char mapPath[], FileDecors *fileDecors, FilePorte *filePorte);//fonction qui charge les  objets décors, portes, un à un dans leurs files
void deplacerObjets(FileDecors *fileDecors, FilePorte *filePorte, Direction direction);//déplace les objets en même temps que la carte
int chargerTypeEvenement(Decors element);
void viderMap(Case **Map);
//Décors
FileDecors *initialiserFileDecors();//fonction qui initialise la file de Décors
Decors chargerCaracteristiquesDecors(char *chaine);
void ajouterElementFileDecors(FileDecors *file, char *chaine);//Fonction qui rajoute un élément à la file de décors (à la fin)
int viderFileDecors(FileDecors *file);//Fonction qui vide la file
void afficherFileDecorsTerm(FileDecors *file); //Fonction qui affiche dans le terminal les éléments de la file des décors
void afficherDecors(FileDecors *file, SDL_Surface *ecran, Perso perso, int currentSprite); //fonction d'affichage des decors
void chargerCollisionsDecors(FileDecors *file, Case ** Map);//fonction qui charge les collisions des décors
void afficheCollisions(Case **Map, SDL_Surface *ecran); //Fonction de développement qui surligne en rouge les cases infranchissables
//Changement Map
int changeMap(int numMap, Case **Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position);//fonction qui permet de changer de carte
FilePorte *initialiserFilePorte();
void ajouterElementFilePorte(FilePorte *file, char *chaine);
int viderFilePorte(FilePorte *file);
Porte chargerCaracteristiquesPortes(char *chaine);
void afficherFilePorteTerm(FilePorte *file); //Fonction qui affiche dans le terminal les éléments de la file des porte
void afficherFilePorteSDL(FilePorte *file, SDL_Surface *ecran);//Fonction qui affiche en rouge les portes de la map
int verifChangementMap(Case ** Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position);
void centrerMap(Case **Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position);
void changerDimensionsMap(char mapPath[], Case **Map);
void ajouterPorteMapCommune(Case origine, FilePorte *filePorte);
//Lancement combat
void lancementCombat(SDL_Surface *ecran);
#endif // MAP_H_INCLUDED
