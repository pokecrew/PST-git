//--------------------------------------------------------------------------------------------------------------\\
//                                   Groupe 3  classe 22 PST                                                    \\
//                                                                                                              \\
//  Si erreur make :                                                                                            \\
//  ligne de compilation: gcc -o PST main.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image      \\
//--------------------------------------------------------------------------------------------------------------\\

#include "include.h"
#include "menu.c"
#include "map.c"
#include "perso.c"
#include "game.c"
#include "combat.c"
#include "son.c"

int main(int argc, char** argv)
{
  //initialisation des variables
  TTF_Init(); //on initialise les polices
  SDL_Init(SDL_INIT_VIDEO); //initialisation de la sdl
  loadsoundEffect();//on charge les Musiques
  Mix_AllocateChannels(3); //alloue des canaux pour les effets sonores (!= des musiques)
  SDL_WM_SetIcon(IMG_Load("icon.png"), NULL); // Chargement de l'icône AVANT SDL_SetVideoMode
  SDL_Surface *ecran = NULL; //Surface sur laquelle on affichera les différents éléments
  ecran = SDL_SetVideoMode((1280), (720), 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); //on affiche un écran de la taille souhaitée
  SDL_WM_SetCaption("PST v0.1.1", NULL);   //titre de la fenêtre
  SDL_EnableKeyRepeat(15, 50); //répétition des touches (millisecondes)
  //initialisation des maps
  Case **Map=createMap(mapPath); //On crée un tableau  de cases aux dimensions correspondantes au nombre de cases de la map
  FileDecors *fileDecors = initialiserFileDecors();
  FilePorte *filePorte = initialiserFilePorte();
  int chargementMap = 0;
  chargerSpritesMap(); //chargement en mémoire des sprites de la Map
  //initialisation du personnage
  Perso perso;
  perso.numSprite = 0;
  chargerSpritesPerso(perso.numSprite,perso.Perso_Sprites);
  perso.position.x=FENETRE_W/2;
  perso.position.y=FENETRE_H/2;
  // initialisation pokemon et stats
  poke1.id = 136;
  poke1.niv = 16;
  //poke1.exp = (poke1.niv)*(poke1.niv)*(poke1.niv);
  calcul_stat(&poke1);
  poke1.exp = 4000;
  printf("%d\n",poke1.exp);
  int attaques[4]={5,12,3,6};
  charger_att((poke1.attaque), attaques);

  //la boucle suivante constitue le menu
  int continuer = 1;
  int Menu=0;
  char Mat_Dialogue[3][100];
  SDL_Event event; //on crée un evenement

  while (continuer)
  {
    Menu = menu(ecran);
    switch(Menu)
    {
      case -2:
        continuer = 0;
        break;

      case 0: //Quitter
        continuer = 0;
        break;

      case 1: //Alexis/Sarah
        //animation_evo(poke1.id,ecran);
        selection_att_adv(&poke1);
      break;

      case 2: //Camille/Théo(Combats)
        affichage_combat(ecran);
        break;

      case 3: //Thomas(Jeu)
        //chargement
        changeMap(numMap, Map, fileDecors, filePorte, &perso.position, Mat_Dialogue);
        //afficherFileDecorsTerm(fileDecors);
        jeu(perso,ecran , Map, fileDecors, filePorte, Mat_Dialogue);

        //Libération de la mémoire
        viderFileDecors(fileDecors);
        viderFilePorte(filePorte);
        //On libère la map
        break;

      case 4: //Options
            break;

    }
  }
  viderMap(Map);
  Mix_CloseAudio(); //Fermeture de l'API audio
  TTF_Quit();//on quitte sdl_ttf
  SDL_Quit();
  return EXIT_SUCCESS;
}
