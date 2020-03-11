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
void poke_nom(Poke pokemon[20]);
void sauvage(SDL_Surface *poke[16]);
void poke_alea(SDL_Surface *ecran, SDL_Surface *poke[16], Poke pokemon[20]);
void my_pokemons();
void changer_poke(SDL_Surface *ecran);
int deroulement( SDL_Surface *ecran, Poke *j1, Poke *j2, int joueur);


#endif // DEF_COMBAT
