#include "include.h"//inclusion des .h nécessaires regroupés dans le fichier include.h

int menu(SDL_Surface *ecran){ //menu d'accueil du jeu
    TTF_Font *police = NULL, *police2 =NULL; //polices propres au menu
    police = TTF_OpenFont("fonts/angel_bilsh/AngeLBilsh-Demo.ttf", 55); //on charge les polices
    police2 = TTF_OpenFont("fonts/angel_bilsh/AngeLBilsh-Demo.ttf", 37);
    SDL_Surface  *menu = NULL, *titre = NULL, *option1 = NULL, *option2 = NULL, *option3 =NULL, *quitter = NULL, *parametre = NULL; //surfaces servant pour l'ecran d'accueil
    SDL_Surface  *option1_j = NULL, *option2_j = NULL, *option3_j =NULL, *quitter_j = NULL, *parametre_j = NULL; //surfaces servant pour l'ecran d'accueil(couleur jaune)
    SDL_Rect positionMenu; //positions du menu
    SDL_Rect positionTitre; //position du titre
    SDL_Rect positionOption1; //positions de l'option 1
    SDL_Rect positionOption2; //positions de l'option 2
    SDL_Rect positionOption3; //positions de l'option 3
    SDL_Rect positionQuitter; //positions de quitter
    SDL_Rect positionParametre; //positions de quitter
    SDL_Event event; //on crée un evenement
    int continuer = 1;
    int widthOption = 220;
    int heightOption = 50;
    short int option1_status = 0, option2_status = 0, option3_status=0, quitter_status=0, parametre_status=0;
    menu = IMG_Load("images/homescreen7.png"); //image de fond de l'écran d'accueil
    titre = TTF_RenderText_Blended(police, "Pokemoon", couleurTitre);
    option1 = TTF_RenderText_Blended(police2, "Alexis", couleurTitre);
    option2 = TTF_RenderText_Blended(police2, "Camille", couleurTitre);
    option3 = TTF_RenderText_Blended(police2, "Sarah", couleurTitre);
    parametre = TTF_RenderText_Blended(police2, "Quitter", couleurTitre);
    quitter = TTF_RenderText_Blended(police2, "Thomas", couleurTitre);
    option1_j = TTF_RenderText_Blended(police2, "Alexis", couleurJaune);
    option2_j = TTF_RenderText_Blended(police2, "Camille", couleurJaune);
    option3_j = TTF_RenderText_Blended(police2, "Sarah", couleurJaune);
    parametre_j = TTF_RenderText_Blended(police2, "Quitter", couleurJaune);
    quitter_j = TTF_RenderText_Blended(police2, "Thomas", couleurJaune);
    positionMenu.x = 0; //on centre l'image
    positionMenu.y = 0;
    positionTitre.x = 830;
    positionTitre.y = 70;
    positionOption1.x = 830;//on centre l'image
    positionOption1.y = 170;
    positionOption2.x = 830; //on centre l'image
    positionOption2.y = 230;
    positionOption3.x = 830; //on centre l'image
    positionOption3.y = 290;
    positionParametre.x = 830;
    positionParametre.y = 350;
    positionQuitter.x = 830;
    positionQuitter.y = 410;
    int choix = 0;

    //la boucle suivante constitue le menu
    while (continuer){ //tant que continuer != 0 (= l'utilisateur ne veut pas quitter)
        SDL_WaitEvent(&event); //on attends un évènement
        switch(event.type){ //on teste son type
            case SDL_QUIT: //si c'est un clic sur la croix rouge alors on quitter
                continuer = 0;
                choix = -1;
            break;
            case SDL_KEYDOWN: //si c'est un appui sur une touche
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE: // arrêter le jeu
                        continuer = 0;
                        choix = -1;
                    break;
                    case SDLK_UP: //si c'est la flèche du haut
                        switch(choix){ //en fonction de l'onglet en surbrillance actuel
                            case 0 :
                                choix = 4;
                                option1_status = 0; //première option en blanc
                                quitter_status = 1; //quitter en jaune
                            break;
                            case 1 :
                                choix-- ;
                                option1_status = 1; //première option en jaune
                                option2_status = 0; //deuxième option en blanc
                            break;
                            case 2:
                                choix-- ;
                                option3_status = 0; //troisième option en blanc
                                option2_status = 1; //deuxième option en jaune
                            break;
                            case 3:
                                choix--;
                                parametre_status = 0; //parametre en blanc
                                option3_status = 1; //troisième option en jaune
                            break;
                            case 4:
                                choix-- ;
                                quitter_status = 0; //quitter option en blanc
                                parametre_status = 1; //parametre en jaune
                            break;

                        }
                    break;
                    case SDLK_DOWN: //si c'est flèche du bas
                        switch(choix){ //en fonction de l'élément en surbrillance actuelle
                            case 0 :
                                choix++ ;
                                option1_status = 0;
                                option2_status = 1; //deuxième option en jaune
                            break;
                            case 1 :
                                choix++ ;
                                option2_status = 0; //deuxième option en blanc
                                option3_status = 1; //troisième option en jaune
                            break;
                            case 2:
                                choix++ ;
                                option3_status = 0; //troisième option en blanc
                                parametre_status = 1; //parametre en jaune
                            break;
                            case 3:
                                choix++;
                                parametre_status = 0; //parametre en blanc
                                quitter_status = 1; //quitter en jaune
                            break;
                            case 4:
                                choix = 0;
                                quitter_status = 0; //quitter en blanc
                                option1_status = 1; //première option en jaune
                            break;

                        }
                    break;
                    case SDLK_RETURN: //si c'est un appui sur la touche Entrée, on mets à jour le choix et on sort de la boucle
                      if(choix < 4){
                        choix++ ;
                      }
                      else{choix = 0; }
                      continuer = 0;
                    break;
                }
                break;
            case SDL_MOUSEMOTION: // Mouvement de la souris
                    //on déclare tous les états des variables en blanc
                    option1_status = 0;
                    option2_status = 0;
                    option3_status = 0;
                    parametre_status = 0;
                    quitter_status = 0;
                    //puis on déclare en jaune celui qui est survolé par la souris
                    if((event.motion.x >= positionOption1.x) && (event.motion.x <= positionOption1.x+widthOption) && (event.motion.y >= positionOption1.y) && (event.motion.y <= positionOption1.y+heightOption)){
                        option1_status = 1;
                    }
                    else if((event.motion.x >= positionOption2.x) && (event.motion.x <= positionOption2.x+widthOption) && (event.motion.y >= positionOption2.y) && (event.motion.y <= positionOption2.y+heightOption)){
                        option2_status = 1;
                    }
                    else if((event.motion.x >= positionOption3.x) && (event.motion.x <= positionOption3.x+widthOption) && (event.motion.y >= positionOption3.y) && (event.motion.y <= positionOption3.y+heightOption)){
                        option3_status = 1;
                    }
                    else if((event.motion.x >= positionParametre.x) && (event.motion.x <= positionParametre.x+widthOption) && (event.motion.y >= positionParametre.y) && (event.motion.y <= positionParametre.y+heightOption)){
                        parametre_status = 1;
                    }
                    else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption)){
                        quitter_status = 1;
                    }

            break;
            case SDL_MOUSEBUTTONUP: // Clic de la souris, on affecte la valeur de choix en fonction de l'endroit du clic puis on sort de la boucle
                    if((event.motion.x >= positionOption1.x) && (event.motion.x <= positionOption1.x+widthOption) && (event.motion.y >= positionOption1.y) && (event.motion.y <= positionOption1.y+heightOption)){
                        choix = 1;
                        //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
                        continuer = 0;
                    }
                    else if((event.motion.x >= positionOption2.x) && (event.motion.x <= positionOption2.x+widthOption) && (event.motion.y >= positionOption2.y) && (event.motion.y <= positionOption2.y+heightOption)){
                        choix = 2;
                        //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
                        continuer = 0;
                    }
                    else if((event.motion.x >= positionOption3.x) && (event.motion.x <= positionOption3.x+widthOption) && (event.motion.y >= positionOption3.y) && (event.motion.y <= positionOption3.y+heightOption)){
                        choix = 3;
                        //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
                        continuer = 0;
                        break;
                    }
                    else if((event.motion.x >= positionParametre.x) && (event.motion.x <= positionParametre.x+widthOption) && (event.motion.y >= positionParametre.y) && (event.motion.y <= positionParametre.y+heightOption)){
                        choix = 4;
                        //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
                        continuer = 0;
                    }
                    else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption)){
                        choix = 0;
                      //  if (soundEffectStatus == 1) playSound(1);//son lorsque la souris clique sur l'option
                        continuer = 0;
                    }

            break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));       // Effacement de l'écran
        //on affiche les surfaces
        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
        SDL_BlitSurface(titre, NULL, ecran, &positionTitre); // Blit du texte
        (option1_status == 0) ? SDL_BlitSurface(option1, NULL, ecran, &positionOption1) : SDL_BlitSurface(option1_j, NULL, ecran, &positionOption1);
        (option2_status == 0) ? SDL_BlitSurface(option2, NULL, ecran, &positionOption2) : SDL_BlitSurface(option2_j, NULL, ecran, &positionOption2);
        (option3_status == 0) ? SDL_BlitSurface(option3, NULL, ecran, &positionOption3) : SDL_BlitSurface(option3_j, NULL, ecran, &positionOption3);
        (parametre_status == 0) ? SDL_BlitSurface(parametre, NULL, ecran, &positionParametre) : SDL_BlitSurface(parametre_j, NULL, ecran, &positionParametre);
        (quitter_status == 0) ? SDL_BlitSurface(quitter, NULL, ecran, &positionQuitter) : SDL_BlitSurface(quitter_j, NULL, ecran, &positionQuitter);
        SDL_Flip(ecran);
    }
    //on libère les surfaces et les polices avant de retourner le choix de l'utilisateur
    TTF_CloseFont(police); // Doit être avant TTF_Quit()
    TTF_CloseFont(police2); // Doit être avant TTF_Quit()
    SDL_FreeSurface(menu);
    SDL_FreeSurface(titre);
    SDL_FreeSurface(option1);
    SDL_FreeSurface(option2);
    SDL_FreeSurface(option3);
    SDL_FreeSurface(parametre);
    SDL_FreeSurface(quitter);
    SDL_FreeSurface(option1_j);
    SDL_FreeSurface(option2_j);
    SDL_FreeSurface(option3_j);
    SDL_FreeSurface(parametre_j);
    SDL_FreeSurface(quitter_j);
    return choix;
}
/*
void menuOption(SDL_Surface *ecran){ //cette fonction constitue le menu des options du jeu
  SDL_Surface  *menu = NULL, *titre = NULL, *wrap = NULL, *parametre[2] = {NULL,NULL}, *credit[2] = {NULL,NULL}, *quitter[2] = {NULL,NULL}; //surface servant pour le panneau de gauche
  SDL_Surface  *fullscreen = NULL, *iaLvl=NULL, *niveauIa[3]={NULL,NULL,NULL}, *soundEffect = NULL , *theme=NULL, *themeImg[2] = {NULL, NULL}, *leftArrow =NULL, *rightArrow = NULL, *switch_on = NULL, *switch_off = NULL;//surfaces du sous menu parametre
  SDL_Surface  *auteurs = NULL, *infos[3]= {NULL};//surfaces de l'onglet crédits
  TTF_Font *police = NULL, *police2 = NULL, *police3 = NULL, *police4 = NULL; //polices qui vont être utilisées
  police = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 10); //chargement de la police dans différentes tailles
  police2 = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 15);
  police3 = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 8);
  police4 = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 6);
  SDL_Rect positionMenu , positionTitre , positionwrap, positionparametre, positioncredit, positionQuitter; //positions des surfaces du panneau de gauche
  SDL_Rect positionFullscreen , positionfullscreen_Status, positionIaLvl, positionIaLvl_Status, positionSoundEffect, positionSoundEffect_Status, positionTheme, positionThemeImg, positionLeftArrow, positionRightArrow , positionLeftArrow_IA, positionRightArrow_IA; //positions des surfaces des parametres
  SDL_Rect positionAuteurs , positionInfos[3]; //position des surfaces de l'onglet crédit
  SDL_Event event; //on crée un evenement
  int continuer = 1; //variable qui permet de savoir si on doit quitter la fonction ou non
  int widthOption = 140;  //variable utile pour gérer les clics souris
  int heightOption = 50;  //variable utile pour gérer les clics souris
  short int parametre_status = 0, credit_status = 0, quitter_status = 0, iaLvl_Status = 0;
  menu = IMG_Load("images/fond.png"); //image de fond du menu option
  titre = TTF_RenderText_Blended(police2, "Options", couleurTitre); //on ecrit dans la surface
  wrap = SDL_CreateRGBSurface(SDL_HWSURFACE, 180, 480, 32, 0, 0, 0, 0);
  parametre[0] = TTF_RenderText_Blended(police, "Parametres", couleurTitre);//on ecrit dans la surface
  parametre[1] = TTF_RenderText_Blended(police, "Parametres", couleurJaune);//on ecrit dans la surface
  credit[0] = TTF_RenderText_Blended(police, "Credits", couleurBlanche);//on ecrit dans la surface
  credit[1] = TTF_RenderText_Blended(police, "Credits", couleurJaune);//on ecrit dans la surface
  quitter[0] = IMG_Load("images/sprites/exit.png"); //image pour retourner à l'écran d'accueil
  quitter[1] = IMG_Load("images/sprites/exit_hover.png");  //image pour retourner à l'écran d'accueil (survolé)
  fullscreen = TTF_RenderText_Blended(police3, "Plein ecran :", couleurBlanche);//on ecrit dans la surface
  soundEffect = TTF_RenderText_Blended(police3, "Effets Sonores :", couleurBlanche);//on ecrit dans la surface
  iaLvl= TTF_RenderText_Blended(police3, "Niveau Ordinateur :", couleurBlanche);//on ecrit dans la surface
  theme = TTF_RenderText_Blended(police3, "Theme :", couleurBlanche);//on ecrit dans la surface
  leftArrow = IMG_Load("images/sprites/prev.png"); //fleche gauche
  rightArrow = IMG_Load("images/sprites/next.png"); //fleche droite
  switch_on = IMG_Load("images/sprites/switch_on.png"); //option activée
  switch_off = IMG_Load("images/sprites/switch_off.png"); //option désactivée
  themeImg[0] = IMG_Load("images/sprites/Lettre/1.png"); //image de theme
  themeImg[1] = IMG_Load("images/sprites/Persos/1.png"); //image de theme
  niveauIa[0]=  TTF_RenderText_Blended(police3, "Facile", couleurBlanche);//on ecrit dans la surface
  niveauIa[1]=  TTF_RenderText_Blended(police3, "Normal", couleurBlanche);//on ecrit dans la surface
  niveauIa[2]=  TTF_RenderText_Blended(police3, "Difficile", couleurBlanche);//on ecrit dans la surface
  positionMenu.x = 0; //coordonées de l'arrière plan
  positionMenu.y = 0;
  positionTitre.x = 20; //coordonées du titre
  positionTitre.y = 15;
  positionwrap.x = 0; ////coordonées du panneau latéral
  positionwrap.y = 0;
  positionparametre.x = positioncredit.x = positionQuitter.x = 30; //on aligne verticalement les surfaces du panneau de gauche
  positionparametre.y = 140;
  positioncredit.y = 200;
  positionQuitter.y = 370;
  positionFullscreen.x = positionIaLvl.x = positionSoundEffect.x = positionTheme.x = 230; //on aligne verticalement les options du sous menu parametre
  positionFullscreen.y = positionfullscreen_Status.y = positionThemeImg.y = 140;
  positionSoundEffect.y = positionSoundEffect_Status.y = 180;
  positionTheme.y = 300;
  positionThemeImg.y = 260;
  positionfullscreen_Status.x = positionSoundEffect_Status.x =  500;
  positionThemeImg.x = 480;
  positionLeftArrow.x = positionLeftArrow_IA.x =positionThemeImg.x-35;
  positionRightArrow.x = positionRightArrow_IA.x = positionThemeImg.x+78;
  positionLeftArrow.y = positionRightArrow.y = positionThemeImg.y+35;
  positionIaLvl_Status.x = positionIaLvl.x+253;
  positionIaLvl_Status.y = positionIaLvl.y = 220;
  positionLeftArrow_IA.y = positionRightArrow_IA.y = positionIaLvl_Status.y-5;

  auteurs=  TTF_RenderText_Blended(police3, "Theo Boussiquet / Thomas Abriat, 1A ESIEA ", couleurBlanche);//on ecrit dans la surface
  infos[0]=  TTF_RenderText_Blended(police4, "Toutes les images du jeu sont libres de droit, ", couleurBlanche);//on ecrit dans la surface
  infos[1]=  TTF_RenderText_Blended(police4, "celles-ci sont accessibles sur le site Flaticons.", couleurBlanche);//on ecrit dans la surface
  positionAuteurs.x = 200 ;
  positionAuteurs.y = 100 ;
  positionInfos[0].x = 205;
  positionInfos[0].y = 150;
  positionInfos[1].x = 205;
  positionInfos[1].y = 165;
  int choix = 1; //variable qui stocke le sous-menu dans lequel on se trouve

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));       // Effacement de l'écran
  SDL_FillRect(wrap, NULL, SDL_MapRGB(wrap->format, 0, 0, 0));       // Effacement de l'écran
  SDL_SetAlpha(wrap, SDL_SRCALPHA, 50);     //crée un effet de fondu pour le bandeau gauche

  //la boucle suivante constitue le menu option
  while (continuer){
      SDL_WaitEvent(&event); // on attends un évènement
      switch(event.type){ //en fonction de son type
          case SDL_QUIT: //si on veut quitter
              continuer = 0; //continuer prends la valeur 0 pour sortir du while
              choix = 0; //on retourne un choix de 0
          break;
          case SDL_KEYDOWN: //si on appuie sur une touche
              switch(event.key.keysym.sym){
                  case SDLK_ESCAPE: // si c'est echap
                      continuer = 0; //continuer prends la valeur 0 pour sortir du while
                      choix = 0; //on retourne un choix de 0
                  break;
              }
              break;
          case SDL_MOUSEMOTION: // Mouvement de la souris, on met en couleur jaune les éléments survolés par la souris
                  parametre_status=0; // élément en blanc
                  credit_status=0; // élément en blanc
                  quitter_status = 0; // élément en blanc
                  //si on survole l'onglet parametre
                  if((event.motion.x >= positionparametre.x) && (event.motion.x <= positionparametre.x+widthOption) && (event.motion.y >= positionparametre.y) && (event.motion.y <= positionparametre.y+heightOption)){
                      parametre_status=1; //on l'affiche en jaune
                  }
                  //si on survole l'onglet credit
                  else if((event.motion.x >= positioncredit.x) && (event.motion.x <= positioncredit.x+widthOption) && (event.motion.y >= positioncredit.y) && (event.motion.y <= positioncredit.y+heightOption)){
                      credit_status=1; //on l'affiche en jaune
                  }
                  //si on survole l'icone quitter
                  else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption)){
                      quitter_status=1;
                  }
          break;
          case SDL_MOUSEBUTTONUP: // on traite les actions en fonction des coordonnées du clic de la souris
                //si on clique sur l'onglet parametre
                 if((event.motion.x >= positionparametre.x) && (event.motion.x <= positionparametre.x+widthOption) && (event.motion.y >= positionparametre.y) && (event.motion.y <= positionparametre.y+heightOption)){
                      choix = 1;
                      if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option

                  }
                  //si on clique sur l'onglet credit
                  else if((event.motion.x >= positioncredit.x) && (event.motion.x <= positioncredit.x+widthOption) && (event.motion.y >= positioncredit.y) && (event.motion.y <= positioncredit.y+heightOption)){
                      choix = 2;
                      if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option

                      break;
                  }
                  //si on clique sur l'icone quitter
                  else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption)){
                      if (soundEffectStatus == 1)  playSound(3);//son lorsque la souris clique sur l'option
                      continuer = 0;
                  }
                  //si on clique sur le bouton plein ecran
                  else if((event.motion.x >= positionfullscreen_Status.x) && (event.motion.x <= positionfullscreen_Status.x+42) && (event.motion.y >= positionfullscreen_Status.y) && (event.motion.y <= positionfullscreen_Status.y+20)){
                        fullscreenStatus = (fullscreenStatus +1)%2; //on met à jour la variable d'état
                        if(fullscreenStatus == 0){
                           ecran = SDL_SetVideoMode((600), (480), 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //on affiche un écran de la taille souhaitée
                        }
                        else{

                          ecran = SDL_SetVideoMode((600), (480), 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN); //on affiche en plein écran
                        }
                  }
                  //si on clique sur le bouton effets sonores
                  else if((event.motion.x >= positionSoundEffect_Status.x) && (event.motion.x <= positionSoundEffect_Status.x+42) && (event.motion.y >= positionSoundEffect_Status.y) && (event.motion.y <= positionSoundEffect_Status.y+20)){
                        soundEffectStatus = (soundEffectStatus +1)%2; //on met à jour la variable d'état

                  }
                  //si on clique sur la fleche gauche de la difficulté de l'IA, on décrémente la variable globale niveauIA
                  else if((event.motion.x >= positionLeftArrow_IA.x) && (event.motion.x <= positionLeftArrow_IA.x+42) && (event.motion.y >= positionLeftArrow_IA.y) && (event.motion.y <= positionLeftArrow_IA.y+20)){
                        if(niveauIA > 0){
                          niveauIA--;
                        }
                        else{
                          niveauIA=2;
                        }
                  }
                  //si on clique sur la fleche droite de la difficulté de l'IA, on incrémente la variable globale niveauIA
                  else if((event.motion.x >= positionRightArrow_IA.x) && (event.motion.x <= positionRightArrow_IA.x+42) && (event.motion.y >= positionRightArrow_IA.y) && (event.motion.y <= positionRightArrow_IA.y+20)){
                        if(niveauIA < 2){
                          niveauIA++;
                        }
                        else{
                          niveauIA=0;
                        }
                  }
                  //si on clique sur la fleche gauche de la sélection des themes, on décrémente la variable globale currentTheme
                  else if((event.motion.x >= positionLeftArrow.x) && (event.motion.x <= positionLeftArrow.x+42) && (event.motion.y >= positionLeftArrow.y) && (event.motion.y <= positionLeftArrow.y+20)){
                        if(currentTheme > 1){
                          currentTheme--;
                        }
                        else{
                          currentTheme=2;
                        }
                  }
                  //si on clique sur la fleche droite de la sélection des themes, on incrémente la variable globale currentTheme
                  else if((event.motion.x >= positionRightArrow.x) && (event.motion.x <= positionRightArrow.x+42) && (event.motion.y >= positionRightArrow.y) && (event.motion.y <= positionRightArrow.y+20)){
                        if(currentTheme < 2){
                          currentTheme++;
                        }
                        else{
                          currentTheme=1;
                        }
                  }


          break;
      }

      //on affiche toutes les surfaces nécessaires
      SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
      SDL_BlitSurface(wrap, NULL, ecran, &positionwrap);
      SDL_BlitSurface(titre, NULL, ecran, &positionTitre);
      switch (choix) { //en fonction de l'onglet choisi, on affiche les bonnes variables
        case 1: //si on est dans l'onglet parametre
        SDL_BlitSurface(fullscreen, NULL, ecran, &positionFullscreen);
        SDL_BlitSurface(soundEffect, NULL, ecran, &positionSoundEffect);
        SDL_BlitSurface(iaLvl, NULL, ecran, &positionIaLvl);
        switch(niveauIA){
          case 0:
            positionIaLvl_Status.x = positionIaLvl.x+258;
            SDL_BlitSurface(niveauIa[0], NULL, ecran, &positionIaLvl_Status);
         break;
          case 1:
            positionIaLvl_Status.x = positionIaLvl.x+253;
            SDL_BlitSurface(niveauIa[1], NULL, ecran, &positionIaLvl_Status);
          break;
          case 2:
            positionIaLvl_Status.x = positionIaLvl.x+248;
            SDL_BlitSurface(niveauIa[2], NULL, ecran, &positionIaLvl_Status);
          break;
        }
        SDL_BlitSurface(theme, NULL, ecran, &positionTheme);
        (fullscreenStatus == 0) ? SDL_BlitSurface(switch_off, NULL, ecran, &positionfullscreen_Status) : SDL_BlitSurface(switch_on, NULL, ecran, &positionfullscreen_Status);
        (soundEffectStatus == 0) ? SDL_BlitSurface(switch_off, NULL, ecran, &positionSoundEffect_Status) : SDL_BlitSurface(switch_on, NULL, ecran, &positionSoundEffect_Status);
        (currentTheme == 1) ? SDL_BlitSurface(themeImg[0], NULL, ecran, &positionThemeImg) : SDL_BlitSurface(themeImg[1], NULL, ecran, &positionThemeImg);
        SDL_BlitSurface(leftArrow, NULL, ecran, &positionLeftArrow);
        SDL_BlitSurface(rightArrow, NULL, ecran, &positionRightArrow);
        SDL_BlitSurface(leftArrow, NULL, ecran, &positionLeftArrow_IA);
        SDL_BlitSurface(rightArrow, NULL, ecran, &positionRightArrow_IA);
        break;
        case 2: // si on est dans l'onglet crédit
          SDL_BlitSurface(auteurs, NULL, ecran, &positionAuteurs);
          SDL_BlitSurface(infos[0], NULL, ecran, &positionInfos[0]);
          SDL_BlitSurface(infos[1], NULL, ecran, &positionInfos[1]);
        break;
      }
      //on affiche les bons boutons et icones en fonction de l'état des paramètre qui leur sont associés
      (parametre_status == 0) ? SDL_BlitSurface(parametre[0], NULL, ecran, &positionparametre) : SDL_BlitSurface(parametre[1], NULL, ecran, &positionparametre);
      (credit_status == 0) ? SDL_BlitSurface(credit[0], NULL, ecran, &positioncredit) : SDL_BlitSurface(credit[1], NULL, ecran, &positioncredit);
      (quitter_status == 0) ? SDL_BlitSurface(quitter[0], NULL, ecran, &positionQuitter) : SDL_BlitSurface(quitter[1], NULL, ecran, &positionQuitter);

      //on gère la transparence des arrières plans des images
      SDL_SetColorKey(switch_on, SDL_SRCCOLORKEY, SDL_MapRGB(switch_on->format, 255, 255, 255));
      SDL_SetColorKey(switch_off, SDL_SRCCOLORKEY, SDL_MapRGB(switch_off->format, 255, 255, 255));
      SDL_SetColorKey(themeImg[0], SDL_SRCCOLORKEY, SDL_MapRGB(themeImg[0]->format, 0, 0, 0));
      SDL_SetColorKey(themeImg[1], SDL_SRCCOLORKEY, SDL_MapRGB(themeImg[1]->format, 0, 0, 0));
      SDL_SetColorKey(leftArrow, SDL_SRCCOLORKEY, SDL_MapRGB(leftArrow->format, 0, 0, 0));
      SDL_SetColorKey(rightArrow, SDL_SRCCOLORKEY, SDL_MapRGB(rightArrow->format, 0, 0, 0));
      //et on met à jour l'écran
      SDL_Flip(ecran);
  }
  //on libère toutes les surfaces et les polices avant de quitter
 SDL_FreeSurface(fullscreen);
  SDL_FreeSurface(iaLvl);
  SDL_FreeSurface(niveauIa[0]);
  SDL_FreeSurface(niveauIa[1]);
  SDL_FreeSurface(niveauIa[2]);
  SDL_FreeSurface(soundEffect);
  SDL_FreeSurface(theme);
  SDL_FreeSurface(themeImg[0]);
  SDL_FreeSurface(themeImg[1]);
  SDL_FreeSurface(leftArrow);
  SDL_FreeSurface(rightArrow);
  SDL_FreeSurface(switch_on);
  SDL_FreeSurface(switch_off);
  SDL_FreeSurface(menu);
  SDL_FreeSurface(titre);
  SDL_FreeSurface(wrap);
  SDL_FreeSurface(parametre[0]);
  SDL_FreeSurface(parametre[1]);
  SDL_FreeSurface(credit[0]);
  SDL_FreeSurface(credit[1]);
  SDL_FreeSurface(quitter[0]);
  SDL_FreeSurface(quitter[1]);
  SDL_FreeSurface(auteurs);
  SDL_FreeSurface(infos[0]);
  SDL_FreeSurface(infos[1]);
  SDL_FreeSurface(infos[2]);
  TTF_CloseFont(police); // Doit être avant TTF_Quit()
  TTF_CloseFont(police2); // Doit être avant TTF_Quit()
  TTF_CloseFont(police3); // Doit être avant TTF_Quit()
  TTF_CloseFont(police4); // Doit être avant TTF_Quit()
}
/*
void menuVictoire(SDL_Surface *ecran, int mode, int winner){ //menu de victoire

  TTF_Font *police = NULL, *police2 =NULL, *police3 = NULL; //pointeurs des polices
  police = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 17); //chargement des polices
  police2 = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 9);
  police3 = TTF_OpenFont("fonts/clean_sports/Clean Sports.ttf", 12);
  SDL_Surface  *fond = NULL, *trophee = NULL, *Message = NULL, *Score[2] = {NULL}, *TexteContinuer = NULL, *TexteResultat[2]= {NULL}; //création des surfaces
  SDL_Rect positionfond; //position de l'image de fond
  SDL_Rect positiontrophee; //position de limage du trophée ou du petit robot
  SDL_Rect positionTexteContinuer; // position du texte "Appuyer sur ..."
  SDL_Rect positionTexteResultat[2]; //position de l'annonce des scores
  SDL_Event event; //on crée un évènement
  char resultat_solo[37] = "Vous avez fini la partie en 97 coups"; //chaine de caractère utile au mode solo
  char resultat_multi[38] = "Joueur1 gagne sur le score de 7 : 5"; //chaine de caractère utile au mode multijoueur
  fond = IMG_Load("images/fond.png"); //Chargement de l'image de fond
  TexteContinuer = TTF_RenderText_Blended(police2, "Appuyez sur une touche pour continuer", couleurBlanche); //chargement du texte
  positionfond.x = 0; //coordonnées de l'arrière plan
  positionfond.y = 0;
  positiontrophee.x = 280; //coordonnées du trophée
  positiontrophee.y = 100;
  positionTexteContinuer.x = 110; //coordonnées du texte pour continuer
  positionTexteContinuer.y = 350;
  positionTexteResultat[0].x = 180; //coordonnées du résultat (victoire)
  positionTexteResultat[0].y = 190;
  positionTexteResultat[1].x = 60;
  positionTexteResultat[1].y = 230; //coordonées des scores
  int continuer = 1;
  if(mode == 3 && winner == 2){ //si l'ordinateur à gagné en mode joueur contre IA
    trophee = IMG_Load("images/sprites/robot.png"); //on charge la tête du robot
    TexteResultat[0] = TTF_RenderText_Blended(police, "Dommage...", couleurBlanche); //on charge le texte "dommage"
  }
  else{ // dans le cas contraire
    trophee = IMG_Load("images/sprites/trophy.png"); //on charge une image de trophée
  }
  if(winner == 1 || (mode != 3 && winner == 2) ){ //si il y a un gagnant humain
    TexteResultat[0] = TTF_RenderText_Blended(police, "Felicitations !", couleurBlanche); //on charge "félicatitions"
  }
  else if(winner == 3){ //u si il y a eu match nul
    TexteResultat[0] = TTF_RenderText_Blended(police, "Match nul !", couleurBlanche); // on charge "Match Nul"
    positionTexteResultat[0].x = 200; //on centre la surface
  }
  switch(mode){ //en fonction du mode de jeu
    case 1: //Si c'est le mode 1 Joueur
      if((score[0].score/10) == 0){ //si son score est inférieur à 10
        resultat_solo[28]=' '; //on affiche un espace dans la colonne des dizaines de la chaine qui affichera le resultat
      }
      else{//si son score est >= 10
        resultat_solo[28] = score[0].score/10+48; //on affiche dans la chaine le chiffre des dizaines de son scores
      }
      resultat_solo[29]= score[0].score%10+48; //puis on affiche le chiffre des unités dans la case suivante de la chaine
      TexteResultat[1] = TTF_RenderText_Blended(police3, resultat_solo, couleurBlanche); //on charge ensuite la chaine dans la surface
    break;
    case 2: //mode joueur vs joueur
      if(winner == 2){ //si c'est le joueur 2 qui gagne
        resultat_multi[6]= '2'; //on affiche '2' à la suite du mot 'joueur'dans la chaine de résultat
      }
      resultat_multi[30]= score[0].score+48; //on écrit dans la chaine le score du Joueur1
      resultat_multi[34]= score[1].score+48; //on écrit dans la chaine le score du Joueur2
      TexteResultat[1] = TTF_RenderText_Blended(police3, resultat_multi, couleurBlanche); //on charge la chaine dans la surface
    break;
    case 3: //mode joueur contre ordinateur
      if(winner == 2){ //si l'ordinateur à gagné
        positionTexteResultat[0].x = 220; //on recentre la surface qui affiche le resultat
        positionTexteResultat[0].y = 175;
        resultat_multi[0]= ' '; //on remplace Joueur1 par ' Ubuntu' dans la chaîne de caractères
        resultat_multi[1]= 'U';
        resultat_multi[2]= 'b';
        resultat_multi[3]= 'u';
        resultat_multi[4]= 'n';
        resultat_multi[5]= 't';
        resultat_multi[6]= 'u';
      }
      resultat_multi[30]= score[0].score+48; //on écrit dans la chaine le score du Joueur1
      resultat_multi[34]= score[1].score+48; //on écrit dans la chaine le score du Joueur2
      TexteResultat[1] = TTF_RenderText_Blended(police3, resultat_multi, couleurBlanche); //on charge la chaine dans la surface
    break;
  }

  while (continuer){ // on crée une boucle dépendant de la variable continuer pour attendre que le joueur appuie sur une touche
      SDL_PollEvent(&event);
      switch(event.type){
          case SDL_QUIT:
              continuer = 0;
          break;
          case SDL_KEYDOWN:
              continuer = 0;
          break;
          case SDL_MOUSEBUTTONUP:
              continuer = 0;
          break;
        }
    //on affiche les surfaces
    SDL_BlitSurface(fond, NULL, ecran, &positionfond);
    SDL_BlitSurface(trophee, NULL, ecran, &positiontrophee);
    SDL_BlitSurface(TexteContinuer, NULL, ecran, &positionTexteContinuer);
    SDL_BlitSurface(TexteResultat[0], NULL, ecran, &positionTexteResultat[0]);
    if(winner != 3){
      SDL_BlitSurface(TexteResultat[1], NULL, ecran, &positionTexteResultat[1]);
    }
    SDL_Flip(ecran); //on mets à jour l'écran
  }
  // on libère les surfaces et les polices avantde quitter
  TTF_CloseFont(police); // Doit être avant TTF_Quit()
  TTF_CloseFont(police2); // Doit être avant TTF_Quit()
  TTF_CloseFont(police3); // Doit être avant TTF_Quit()
  SDL_FreeSurface(TexteResultat[0]);
  SDL_FreeSurface(TexteResultat[1]);
  SDL_FreeSurface(fond);
  SDL_FreeSurface(trophee);
  SDL_FreeSurface(Message);
  SDL_FreeSurface(Score[0]);
  SDL_FreeSurface(Score[1]);
  SDL_FreeSurface(TexteContinuer);
}
*/
