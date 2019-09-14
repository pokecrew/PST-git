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


int main ( int argc, char** argv ){
    //initialisation des variables
    TTF_Init(); //on initialise les polices
    char mapPath[]="map/02.lvl"; //chemin vers le fichier source
    SDL_Init(SDL_INIT_VIDEO); //initialisation de la sdl
    SDL_WM_SetIcon(IMG_Load("images/icon.png"), NULL); // Chargement de l'icône AVANT SDL_SetVideoMode
    SDL_Surface *ecran = NULL; //Surface sur laquelle on affichera les différents éléments
    ecran = SDL_SetVideoMode((1280), (720), 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //on affiche un écran de la taille souhaitée
    SDL_WM_SetCaption("PST v0.0", NULL);   //titre de la fenêtre
     SDL_EnableKeyRepeat(10, 15); //répétition des touches
    //initialisation des maps
    Case **Map=createMap(mapPath); //On crée un tableau  de cases aux dimensions correspondantes au nombre de cases de la map
    FileDecors *fileDecors = initialiserFileDecors();
    int chargementMap = 0;
    chargerSpritesMap(); //chargement en mémoire des sprites de la Map
    //initialisation du personnage
    Perso perso;
    perso.numSprite = 0;
    //la boucle suivante constitue le menu
    int continuer = 1;
    int Menu=0;
    SDL_Event event; //on crée un evenement
    while (continuer){

        Menu = menu(ecran);
        switch(Menu){
            case -1:
              continuer = 0;
            break;
            case 0: //Thomas
                //chargement
                    chargerDecors(mapPath, fileDecors);//on charge les décors
                    chargementMap=loadMap(mapPath, Map);
                    chargerSpritesPerso(perso.numSprite,perso.Perso_Sprites);



                //Affichage

                  //  displayMap(Map, ecran);
                  // afficherDecors(fileDecors, ecran);
                  //  afficherFileTerm(fileDecors);
                  deplacerPerso(perso,ecran , Map, fileDecors);

                //Libération de la mémoire
                    viderFileDecors(fileDecors);

                //SDL_Delay(3500);
            break;
            case 1: //Alexis


            break;
            case 2: //Camille


            break;
            case 3: //Sarah

            break;
            case 4: //Theo

            break;
        }
    }

    Mix_CloseAudio(); //Fermeture de l'API audio
    TTF_Quit();//on quitte sdl_ttf
    SDL_Quit();
    return EXIT_SUCCESS;
}
