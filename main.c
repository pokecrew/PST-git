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


int main ( int argc, char** argv ){
    //initialisation des variables
    TTF_Init(); //on initialise les polices
    SDL_Init(SDL_INIT_VIDEO); //initialisation de la sdl
    SDL_WM_SetIcon(IMG_Load("icon.png"), NULL); // Chargement de l'icône AVANT SDL_SetVideoMode
    SDL_Surface *ecran = NULL; //Surface sur laquelle on affichera les différents éléments
    ecran = SDL_SetVideoMode((1280), (720), 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); //on affiche un écran de la taille souhaitée
    SDL_WM_SetCaption("PST v0.0", NULL);   //titre de la fenêtre
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

    //la boucle suivante constitue le menu
    int continuer = 1;
    int Menu=0;
    SDL_Event event; //on crée un evenement

    while (continuer){
        Menu = menu(ecran);
        switch(Menu){
            case -2:
              continuer = 0;
            break;
            case 0: //Thomas
                //chargement
                    changeMap(numMap, Map, fileDecors, filePorte);
                  //  afficherFilePorteTerm(filePorte);

                //Affichage
                  //  displayMap(Map, ecran);
                  // afficherDecors(fileDecors, ecran);
                  //afficherFileTerm(fileDecors);
                  /*for(int k=0;k<NBLIN;k++){
                           for(int l=0;l<NBCOL;l++){
                                   printf("%d ", Map[k][l].type);
                           }
                           printf("\n");
                  }*/
                  deplacerPerso(perso,ecran , Map, fileDecors, filePorte);

                //Libération de la mémoire
                viderFileDecors(fileDecors);
                viderFilePorte(filePorte);
                //SDL_Delay(3500);
            break;
            case 1: //Alexis

            return 0;

            break;
            case 2: //Camille

              combat(ecran);

            break;
            case 3: //Sarah

            break;
            case 4: //Theo
                continuer = 0;
            break;
        }
    }

    Mix_CloseAudio(); //Fermeture de l'API audio
    TTF_Quit();//on quitte sdl_ttf
    SDL_Quit();
    return EXIT_SUCCESS;
}
