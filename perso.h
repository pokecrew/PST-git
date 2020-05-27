#ifndef DEF_PERSO
#define DEF_PERSO

//Entrer ici les prototypes
void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites);
void jeu(Perso perso, SDL_Surface *ecran, Case ** Map, FileDecors *file, FilePorte *filePorte, char Mat_Dialogue[100][150], char nomMap[40]);
void deplacement(Case ** Map, Perso *perso, FileDecors *fileDecors, FilePorte *filePorte, Direction direction);
int autoriserDeplacement(Case ** Map,Direction direction, Perso perso, SDL_Surface *ecran);
void dialogue_affichage(SDL_Surface *ecran, char* texte, char* texte2, char* texte3);
#endif // DEF_PERSO
