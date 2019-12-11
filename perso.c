#include "include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites){
  char path[]="images/sprites/Perso/000/32/01.png";
  path[21]= (numSpritePerso/100)+48; //on récupère le chiffre des centaines du numéro de sprite
  numSpritePerso = numSpritePerso%100;//on enleve le chiffre des centaines
  path[22]= (numSpritePerso/10)+48; //on récupère le chiffre des dizaines du numéro de sprite
  numSpritePerso = numSpritePerso%10;//on enleve le chiffre des dizaines
  path[23]= numSpritePerso+48; //on récupère le chiffre des unités du numéro de sprite
  //chargement des sprites 32 pixels
  for(int i=0; i<9; i++){
    path[29]= i+49; //on affecte i+1 au caractère des unités
    Perso_Sprites[i]=IMG_Load(path);
  }
  path[28]=49; // on affecte 1 au chiffre des dizaines
  for(int j=0; j<3; j++){
    path[29]= j+48; //on affecte i au caractère des unités
    Perso_Sprites[j+9]=IMG_Load(path);
  }
  //chargement des sprites 48 pixels
  //on passe du dossier '32' à '48' dans le chemin
  path [25]='4';
  path[26]='8';
  path[28]=48;// on remet le chiffre des dizaines à 0
  for(int i=0; i<9; i++){
    path[29]= i+49; //on affecte i+1 au caractère des unités
    Perso_Sprites[i+12]=IMG_Load(path);
  }
  path[28]=49; // on affecte 1 au chiffre des dizaines
  for(int i=0; i<3; i++){
    path[29]= i+48; //on affecte i au caractère des unités
    Perso_Sprites[i+21]=IMG_Load(path);
  }
}

void deplacerPerso(Perso perso, SDL_Surface *ecran, Case ** Map, FileDecors *fileDecors, FilePorte *filePorte){
  SDL_Event event;
  int continuer = 1;
  int iSpriteH = 1;
  int iSpriteD = 1;
  int iSpriteB = 1;
  int iSpriteG = 1;
  int canmove =1; //stocke si on peux se déplacer ou non
  int current = 4; //sprite courant
  int numSprite=0;//numéro du sprite à afficher (0 à 11 : petites tailles, 12 à 23 : grandes tailles)
  int refresh = 1;//variable qui stocke si on doit rafraichir l'affichage
  perso.position.x=560; //valeurs à récupérer depuis le fichier sauvegarde
  perso.position.y=400; //valeurs à récupérer depuis le fichier sauvegarde
  perso.x=(perso.position.x-(perso.position.x%16))/TAILLE_SPRITE;
  perso.y=(perso.position.y-(perso.position.y%16))/TAILLE_SPRITE;
//  printf("%d\t%d\n", perso.x, perso.y);

  while (continuer){

    //Séquence d'affichage
      if(refresh == 1){ //si on a besoin de raifraichir l'affichage
      //verification du changement de la map
        verifChangementMap(Map,fileDecors,filePorte, &perso.position);
        displayMap(Map, ecran); //on affiche les sols
        afficherDecors(fileDecors, ecran); //puis les decors
        //afficheCollisions(Map, ecran); //fonction de developpement qui applique un filtre rouge aux zones considérées comme des murs
        afficherFilePorteSDL(filePorte,ecran); //fonction de developpement qui applique un filtre bleu aux zones considérées comme des portes
        SDL_BlitSurface(perso.Perso_Sprites[numSprite+typeSprite], NULL, ecran, &perso.position); // Collage de la surface sur l'écran
        SDL_Flip(ecran); // Mise à jour de l'écran
      //  SDL_Delay(30); //attente de 30ms entre chaque chargement (sert à ne pas réafficher pour rien)
        refresh = 0;
      }
      SDL_WaitEvent(&event);
          switch(event.type){
              case SDL_QUIT:
                  SDL_Quit();
              break;
              case SDL_KEYDOWN:
                  refresh = 1; //on dit à l'ordinateur de rafraichir l'affichage
                  switch(event.key.keysym.sym){
                    case SDLK_ESCAPE: // arrêter le jeu
                        refresh = 0; //pas besoin de rafraichir
                        continuer = 0;
                    break;
                    case SDLK_UP: // Flèche haut
                        canmove = autoriserDeplacement(Map, HAUT, perso);
                        current=3;
                            if(canmove==1){
                            iSpriteH=(iSpriteH+1)%3;
                            perso.position.y = perso.position.y-8;
                    }
                    break;
                    case SDLK_DOWN: // Flèche bas
                        canmove = autoriserDeplacement(Map, BAS, perso);
                        current=0;
                        if(canmove==1){
                          iSpriteB=(iSpriteB+1)%3;
                          perso.position.y = perso.position.y+8;
                        }
                    break;
                    case SDLK_RIGHT: // Flèche droite
                        canmove = autoriserDeplacement(Map, DROITE, perso);
                        current=1;
                        if(canmove==1){
                         iSpriteD=(iSpriteD+1)%3;
                         perso.position.x = perso.position.x+8;
                        }
                    break;

                    case SDLK_LEFT: // Flèche gauche
                        canmove = autoriserDeplacement(Map, GAUCHE, perso);
                        current=2;
                        if(canmove==1){
                            iSpriteG=(iSpriteG+1)%3;
                            perso.position.x = perso.position.x-8;
                        }
                    break;
                    default:
                        refresh = 0;
                    break;
                }
            break;
            case SDL_KEYUP:
                iSpriteH=0;
                iSpriteB=0;
                iSpriteG=0;
                iSpriteD=0;
                    switch(event.key.keysym.sym){
                      case 'a': // changement de map manuel
                          numMap = (numMap+1)%3;
                          if(numMap == 0){
                            numMap = 3;
                          }
                          changeMap(numMap, Map, fileDecors, filePorte);
                          refresh = 1;
                      break;
                      case 'z': // changement de map manuel
                          if(typeSprite > 0){
                            typeSprite = 0;
                          }
                          else{
                            typeSprite = 12;
                          }
                          printf("typeSprite : %d\n", typeSprite);
                          refresh = 1;
                      break;
                        case SDLK_UP: // Flèche haut
                          current=3;
                        break;
                        case SDLK_DOWN: // Flèche haut
                          current=0;
                        break;
                        case SDLK_LEFT: // Flèche haut
                          current=2;
                        break;
                        case SDLK_RIGHT: // Flèche haut
                          current=1;
                        break;
                    }
            break;
          }
      //Affichage
      switch(current){
        case 0: //bas
          numSprite = (3*current)+(iSpriteB);
        break;
        case 1: //droite
          numSprite = (3*current)+(iSpriteD);
        break;
        case 2: //gauche
          numSprite = (3*current)+(iSpriteG);
        break;
        case 3: //haut
          numSprite = (3*current)+(iSpriteH);
        break;
      }

    }
}


int autoriserDeplacement(Case ** Map, Direction direction, Perso perso){ //fonction qui calcule si une déplacement est possible (retourne 1 si possible, 0 si impossible)

  perso.x=(perso.position.x-(perso.position.x%TAILLE_SPRITE))/TAILLE_SPRITE;
  perso.y=(perso.position.y-(perso.position.y%TAILLE_SPRITE))/TAILLE_SPRITE;
//  printf("%d\t%d\n", (perso.position.x%16), (perso.position.y%16));
//  printf("%d\t%d\n", (perso.x), (perso.y));

  switch(direction){
    case GAUCHE:
        if(perso.position.x%TAILLE_SPRITE == 0){
          return 1;
        }
        else{
          if(perso.position.y%TAILLE_SPRITE == 0){
            if((Map[perso.y+1][perso.x].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
          else{//perso.position.y%TAILLE_SPRITE != 0
            if((Map[perso.y+1][perso.x].type != 0) || (Map[perso.y+2][perso.x].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
        }
    break;
    case DROITE:
        if(perso.position.x%TAILLE_SPRITE == 0){
          return 1;
        }
        else{
          if(perso.position.y%TAILLE_SPRITE == 0){
            if((Map[perso.y+1][perso.x+2].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
          else{//perso.position.y%TAILLE_SPRITE != 0
            if((Map[perso.y+1][perso.x+2].type != 0) || (Map[perso.y+2][perso.x+2].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
        }
    break;
    case HAUT:
        if(perso.position.y%TAILLE_SPRITE != 0){
          return 1;
        }
        else{
          if(perso.position.x%TAILLE_SPRITE == 0){
            if((Map[perso.y][perso.x].type != 0) || (Map[perso.y][perso.x+1].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
          else{//perso.position.y%TAILLE_SPRITE != 0
            if(Map[perso.y][perso.x+1].type != 0){
              return 0;
            }
            else{
              return 1;
            }
          }
        }
    break;
    case BAS:
        if(perso.position.y%TAILLE_SPRITE != 0){
          return 1;
        }
        else{
          if(perso.position.x%TAILLE_SPRITE == 0){
            if((Map[perso.y+2][perso.x].type != 0) || (Map[perso.y+2][perso.x+1].type != 0)){
              return 0;
            }
            else{
              return 1;
            }
          }
          else{//perso.position.y%TAILLE_SPRITE != 0
            if(Map[perso.y+2][perso.x+1].type != 0){
              return 0;
            }
            else{
              return 1;
            }
          }
        }
    break;
  }

}
