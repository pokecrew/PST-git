#ifndef DEF_PERSO
#define DEF_PERSO

//Entrer ici les prototypes
void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites);
void deplacerPerso(SDL_Surface **Perso_Sprites, SDL_Surface *ecran, Case ** Map, FileDecors *file);
#endif // DEF_PERSO
