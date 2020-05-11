#ifndef DEF_COMBAT
#define DEF_COMBAT

void affichage_combat(SDL_Surface *ecran);
void combat(SDL_Surface *ecran);
void poke_nom(Poke pokemon[20]);
void sauvage(SDL_Surface *poke[16]);
void poke_alea(SDL_Surface *ecran, SDL_Surface *poke[16], Poke pokemon[20]);
void my_pokemons();
void changer_poke(SDL_Surface *ecran);
int deroulement( SDL_Surface *ecran, int joueur,int puissance);
int calcul_stat(Poke *poke);
int calcul_exp_gagne(Poke poke);
void ajout_exp(int exp_gagne, SDL_Surface *ecran);
int calcul_pv_perdu(Poke attaquant, Poke defenseur,int puissance);
void evolution(SDL_Surface *ecran);
#endif // DEF_COMBAT
