#include "include.h"//inclusion des .h nécessaires regroupés dans le fichier include.h

//menu d'accueil du jeu
int menu(SDL_Surface *ecran)
{
  TTF_Font *police = NULL, *police2 =NULL; //polices propres au menu
  police = TTF_OpenFont("fonts/LemonJuice.otf", 55); //on charge les polices
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
  menu = IMG_Load("Ressources/menu11.jpg"); //image de fond de l'écran d'accueil
  titre = TTF_RenderText_Blended(police, "", couleurTitre);
  option1 = TTF_RenderText_Blended(police, "Alexis - Sarah", couleurTitre);
  option2 = TTF_RenderText_Blended(police, "Camille - Theo", couleurTitre);
  option3 = TTF_RenderText_Blended(police, "Thomas", couleurTitre);
  parametre = TTF_RenderText_Blended(police, "Options", couleurTitre);
  quitter = TTF_RenderText_Blended(police, "Quitter", couleurTitre);
  option1_j = TTF_RenderText_Blended(police, "Alexis - Sarah", couleurJaune);
  option2_j = TTF_RenderText_Blended(police, "Camille - Theo", couleurJaune);
  option3_j = TTF_RenderText_Blended(police, "Thomas", couleurJaune);
  parametre_j = TTF_RenderText_Blended(police, "Options", couleurJaune);
  quitter_j = TTF_RenderText_Blended(police, "Quitter", couleurJaune);
  positionMenu.x = 0; //on centre l'image
  positionMenu.y = 0;
  positionTitre.x = 830;
  positionTitre.y = 70;
  positionOption1.x = 100;//on centre l'image
  positionOption1.y = 580;
  positionOption2.x = 350; //on centre l'image
  positionOption2.y = 580;
  positionOption3.x = 600; //on centre l'image
  positionOption3.y = 580;
  positionParametre.x = 800;
  positionParametre.y = 580;
  positionQuitter.x = 1000;
  positionQuitter.y = 580;
  int choix = 0;
  //la boucle suivante constitue le menu
  while (continuer)
  { //tant que continuer != 0 (= l'utilisateur ne veut pas quitter)
    SDL_WaitEvent(&event); //on attends un évènement
    switch(event.type)
    { //on teste son type
      case SDL_QUIT: //si c'est un clic sur la croix rouge alors on quitter
        continuer = 0;
        choix = -1;
        break;

      case SDL_KEYDOWN: //si c'est un appui sur une touche
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE: // arrêter le jeu
            continuer = 0;
            choix = -1;
            break;

          case SDLK_LEFT: //si c'est la flèche du haut
            switch(choix)
            { //en fonction de l'onglet en surbrillance actuel
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

          case SDLK_RIGHT: //si c'est flèche du bas
            switch(choix)
            { //en fonction de l'élément en surbrillance actuelle
              case 0 :
                choix++;
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
            if(choix < 4)
            {
              choix++ ;
            }
            else
            {
              choix = 0;
            }
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
        if((event.motion.x >= positionOption1.x) && (event.motion.x <= positionOption1.x+widthOption) && (event.motion.y >= positionOption1.y) && (event.motion.y <= positionOption1.y+heightOption))
        {
          option1_status = 1;
        }
        else if((event.motion.x >= positionOption2.x) && (event.motion.x <= positionOption2.x+widthOption) && (event.motion.y >= positionOption2.y) && (event.motion.y <= positionOption2.y+heightOption))
        {
          option2_status = 1;
        }
        else if((event.motion.x >= positionOption3.x) && (event.motion.x <= positionOption3.x+widthOption) && (event.motion.y >= positionOption3.y) && (event.motion.y <= positionOption3.y+heightOption))
        {
          option3_status = 1;
        }
        else if((event.motion.x >= positionParametre.x) && (event.motion.x <= positionParametre.x+widthOption) && (event.motion.y >= positionParametre.y) && (event.motion.y <= positionParametre.y+heightOption))
        {
          parametre_status = 1;
        }
        else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption))
        {
          quitter_status = 1;
        }
        break;

      case SDL_MOUSEBUTTONUP: // Clic de la souris, on affecte la valeur de choix en fonction de l'endroit du clic puis on sort de la boucle
        if((event.motion.x >= positionOption1.x) && (event.motion.x <= positionOption1.x+widthOption) && (event.motion.y >= positionOption1.y) && (event.motion.y <= positionOption1.y+heightOption))
        {
          choix = 1;
          //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
          continuer = 0;
        }
        else if((event.motion.x >= positionOption2.x) && (event.motion.x <= positionOption2.x+widthOption) && (event.motion.y >= positionOption2.y) && (event.motion.y <= positionOption2.y+heightOption))
        {
          choix = 2;
          //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
          continuer = 0;
        }
        else if((event.motion.x >= positionOption3.x) && (event.motion.x <= positionOption3.x+widthOption) && (event.motion.y >= positionOption3.y) && (event.motion.y <= positionOption3.y+heightOption))
        {
          choix = 3;
          //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
          continuer = 0;
        }
        else if((event.motion.x >= positionParametre.x) && (event.motion.x <= positionParametre.x+widthOption) && (event.motion.y >= positionParametre.y) && (event.motion.y <= positionParametre.y+heightOption))
        {
          choix = 4;
          //if (soundEffectStatus == 1) playSound(3);//son lorsque la souris clique sur l'option
          continuer = 0;
        }
        else if((event.motion.x >= positionQuitter.x) && (event.motion.x <= positionQuitter.x+widthOption) && (event.motion.y >= positionQuitter.y) && (event.motion.y <= positionQuitter.y+heightOption))
        {
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

int menuPause(SDL_Surface *ecran){ //menu pause

  TTF_Font *police = NULL, *police2 =NULL, *police3 = NULL; //pointeurs des polices

  police = TTF_OpenFont("fonts/Nanum.ttf", 14); //on charge les polices
  SDL_Surface  *fond = NULL, *icons = NULL, *texteMap[2] = {NULL,NULL},  *texteVolume[2] = {NULL,NULL},  *texteSave[2] = {NULL,NULL}, *texteQuit[2] = {NULL,NULL}; //création des surfaces
  SDL_Surface *icoVolume[5] ={NULL};
  SDL_Rect positionFond, positionIcons, posIcoMap, posIcoVolume, posIcoSave, posIcoQuit, posTextMap, posTextVolume, posTextSave, posTextQuit;
  SDL_Event event; //on crée un évènement
  //images
  fond = IMG_Load("Ressources/fond_menu_pause.png"); //Chargement de l'image de fond
  icons = IMG_Load("Ressources/text_menu_pause4.png"); //Ensemble des icones
  icoVolume[0]=IMG_Load("Ressources/menu_pause_volume_0.png");
  icoVolume[1]=IMG_Load("Ressources/menu_pause_volume_2.png");
  icoVolume[2]=IMG_Load("Ressources/menu_pause_volume_4.png");
  icoVolume[3]=IMG_Load("Ressources/menu_pause_volume_6.png");
  icoVolume[4]=IMG_Load("Ressources/menu_pause_volume_8.png");
  //printf("Test\n");
  texteMap[0] = TTF_RenderText_Blended(police, "Carte", couleurTitre);
  texteMap[1] = TTF_RenderText_Blended(police, "Carte", couleurJaune);
  texteVolume[0] = TTF_RenderText_Blended(police, "Volume", couleurTitre);
  texteVolume[1] = TTF_RenderText_Blended(police, "Volume", couleurJaune);
  texteSave[0] = TTF_RenderText_Blended(police, "Sauvegarder", couleurTitre);
  texteSave[1] = TTF_RenderText_Blended(police, "Sauvegarder", couleurJaune);
  texteQuit[0] = TTF_RenderText_Blended(police, "Quitter le jeu", couleurTitre);
  texteQuit[1] = TTF_RenderText_Blended(police, "Quitter le jeu", couleurJaune);
  positionFond.x = 0; //coordonnées de l'arrière plan
  positionFond.y = 0;
  positionIcons.x = 350; //coordonnées de l'arrière plan
  positionIcons.y = 100;
  posIcoMap.y = posIcoVolume.y = posIcoSave.y = posIcoQuit.y = 328;
  posIcoMap.x = 380;
  posIcoVolume.x = 525;
  posIcoSave.x= 670;
  posIcoQuit.x=820;
  posTextMap.x = 400;
  posTextVolume.x = 535;
  posTextSave.x = 670;
  posTextQuit.x = 815;
  posTextMap.y = posTextVolume.y = posTextSave.y = posTextQuit.y = posIcoMap.y + 82;
  SDL_SetAlpha(fond, SDL_SRCALPHA, 0);
  int choix = 0;
  int continuer = 1;
  int hoover[4]= {0};

  SDL_BlitSurface(texteMap[0], NULL, ecran, &posTextMap);
  SDL_BlitSurface(texteVolume[0], NULL, ecran, &posTextVolume);
  SDL_BlitSurface(texteSave[0], NULL, ecran, &posTextSave);
  SDL_BlitSurface(texteQuit[0], NULL, ecran, &posTextQuit);
  SDL_BlitSurface(fond, NULL, ecran, &positionFond);
  SDL_BlitSurface(icons, NULL, ecran, &positionIcons);

//  SDL_Flip(ecran); //on mets à jour l'écran

  SDL_BlitSurface(texteMap[0], NULL, ecran, &posTextMap);
  SDL_BlitSurface(texteVolume[0], NULL, ecran, &posTextVolume);
  SDL_BlitSurface(texteSave[0], NULL, ecran, &posTextSave);
  SDL_BlitSurface(texteQuit[0], NULL, ecran, &posTextQuit);

  SDL_Flip(ecran); //on mets à jour l'écran

  while (continuer){ // on crée une boucle dépendant de la variable continuer pour attendre que le joueur appuie sur une touche
      SDL_WaitEvent(&event);
      switch(event.type){
          case SDL_QUIT:
              continuer = 0;
              choix = 0;
          break;
          case SDL_MOUSEMOTION: // Mouvement de la souris
            if((event.motion.x >= posIcoMap.x) && (event.motion.x <= posIcoMap.x+72) && (event.motion.y >= posIcoMap.y) && (event.motion.y <= posIcoMap.y+72)){
              hoover[0]=1;
              hoover[1] = hoover[2] = hoover[3] = 0;
            }
            else if((event.motion.x >= posIcoVolume.x) && (event.motion.x <= posIcoVolume.x+72) && (event.motion.y >= posIcoVolume.y) && (event.motion.y <= posIcoVolume.y+72)){
              hoover[1]=1;
              hoover[0] = hoover[2] = hoover[3] = 0;
            }
            else if((event.motion.x >= posIcoSave.x) && (event.motion.x <= posIcoSave.x+72) && (event.motion.y >= posIcoSave.y) && (event.motion.y <= posIcoSave.y+72)){
              hoover[2]=1;
              hoover[0] = hoover[1] = hoover[3] = 0;
            }
            else if((event.motion.x >= posIcoQuit.x) && (event.motion.x <= posIcoQuit.x+72) && (event.motion.y >= posIcoQuit.y) && (event.motion.y <= posIcoQuit.y+72)){
              hoover[3]=1;
              hoover[0] = hoover[1] = hoover[2] = 0;
            }
            else{
              hoover[0] = hoover[1] = hoover[2] = hoover[3] = 0;
            }
          break;
          /*case SDL_KEYDOWN:
              continuer = 0;
          break;*/
          case SDL_MOUSEBUTTONUP:
          continuer =0;
            if((event.motion.x >= posIcoMap.x) && (event.motion.x <= posIcoMap.x+72) && (event.motion.y >= posIcoMap.y) && (event.motion.y <= posIcoMap.y+72)){
              //miniMap();
              choix = 1;
            }
            else if((event.motion.x >= posIcoVolume.x) && (event.motion.x <= posIcoVolume.x+72) && (event.motion.y >= posIcoVolume.y) && (event.motion.y <= posIcoVolume.y+72)){
              //monterVolume
              continuer = 1;
              if(volumeSon/32 < 4){
                volumeSon += 32;
              }
              else{
                volumeSon=0;
              }
              Mix_VolumeMusic(volumeSon);
            }
            else if((event.motion.x >= posIcoSave.x) && (event.motion.x <= posIcoSave.x+72) && (event.motion.y >= posIcoSave.y) && (event.motion.y <= posIcoSave.y+72)){
              choix = 1;
            }
            else if((event.motion.x >= posIcoQuit.x) && (event.motion.x <= posIcoQuit.x+72) && (event.motion.y >= posIcoQuit.y) && (event.motion.y <= posIcoQuit.y+72)){
              choix = 0;
            }
            else{
              choix = 1;
            }
          break;
        }
        //Affichage
        if(hoover[0] ==  1){
          SDL_BlitSurface(texteMap[1], NULL, ecran, &posTextMap);
        }
        else{
          SDL_BlitSurface(texteMap[0], NULL, ecran, &posTextMap);
        }
        if(hoover[1] ==  1){
          SDL_BlitSurface(texteVolume[1], NULL, ecran, &posTextVolume);
        }
        else{
          SDL_BlitSurface(texteVolume[0], NULL, ecran, &posTextVolume);
        }
        if(hoover[2] ==  1){
          SDL_BlitSurface(texteSave[1], NULL, ecran, &posTextSave);
        }
        else{
          SDL_BlitSurface(texteSave[0], NULL, ecran, &posTextSave);
        }
        if(hoover[3] ==  1){
          SDL_BlitSurface(texteQuit[1], NULL, ecran, &posTextQuit);
        }
        else{
          SDL_BlitSurface(texteQuit[0], NULL, ecran, &posTextQuit);
        }
        switch(volumeSon/32){ //on affiche la pokeball remplit en fonction du volume en cours
          case 0:
            SDL_BlitSurface(icoVolume[0], NULL, ecran, &posIcoVolume);
          break;
          case 1:
            SDL_BlitSurface(icoVolume[1], NULL, ecran, &posIcoVolume);
          break;
          case 2:
            SDL_BlitSurface(icoVolume[2], NULL, ecran, &posIcoVolume);
          break;
          case 3:
            SDL_BlitSurface(icoVolume[3], NULL, ecran, &posIcoVolume);
          break;
          case 4:
            SDL_BlitSurface(icoVolume[4], NULL, ecran, &posIcoVolume);
          break;
        }
        SDL_Flip(ecran);
        //SDL_Delay(100); //temps d'attente entre chaque boucle pour réduire la charge processeur
    }
  // on libère les surfaces et les polices avantde quitter
  TTF_CloseFont(police); // Doit être avant TTF_Quit()
//  TTF_CloseFont(police2); // Doit être avant TTF_Quit()
//  TTF_CloseFont(police3); // Doit être avant TTF_Quit()
  SDL_FreeSurface(fond);
  SDL_FreeSurface(icons);
  for(int i=0; i<2 ; i++){
    SDL_FreeSurface(texteMap[i]);
    SDL_FreeSurface(texteVolume[i]);
    SDL_FreeSurface(texteSave[i]);
    SDL_FreeSurface(texteQuit[i]);
    SDL_FreeSurface(icoVolume[i]);
    SDL_FreeSurface(icoVolume[i+2]);
  }
  SDL_FreeSurface(icoVolume[4]);
  return choix;
}
