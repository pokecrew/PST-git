#ifndef DEF_GAME
#define DEF_GAME

//Entrer ici les prototypes
int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran);
int charger_att(Att att[4], int id_att[4]);
#endif // DEF_GAME
