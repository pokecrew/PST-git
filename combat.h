#ifndef DEF_COMBAT
#define DEF_COMBAT

typedef struct Poke Poke;

struct Poke{
  char nom[25];
  int PV;
  int exp;
  int niv;
  int def;
  int att;
  int vit;
  int id;
};

void combat(SDL_Surface *ecran);
void poke_nom();
void sauvage();
void poke_alea(SDL_Surface *ecran);
void my_pokemons();
void changer_poke(SDL_Surface *ecran);
void deroulement( SDL_Surface *ecran, Poke *j1, Poke *j2);


#endif // DEF_COMBAT
