#ifndef DEF_PERSO
#define DEF_PERSO

typedef struct Perso Perso;

//Structure des objets Case
struct Perso{
    int x;        //position sur les x (coin supérieur gauche) (nombre de case)
    int y;        //position sur les y (coin supérieur gauche)(nombre de case)
    int numSprite; //nom de l'image de la case
    SDL_Rect position; //positions de la surface
    SDL_Surface *Perso_Sprites[24];//Tableau des sprites du personnage
};

//Entrer ici les prototypes
void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites);
void deplacerPerso(Perso perso, SDL_Surface *ecran, Case ** Map, FileDecors *file, FilePorte *filePorte);
int autoriserDeplacement(Case ** Map,Direction direction, Perso perso);
#endif // DEF_PERSO
