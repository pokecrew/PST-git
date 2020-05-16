#ifndef DEF_GAME
#define DEF_GAME

//Entrer ici les prototypes
int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran);
int charger_att(Att att[4], int id_att[4]);
int animation_evo(int id,  SDL_Surface *ecran);
void tirage_poke_sauvage(int poke1_niv);
void selection_att_adv(Poke *poke);
void maj_att_niv(Poke *poke);
#endif // DEF_GAME
