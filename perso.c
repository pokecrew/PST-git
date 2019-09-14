#include "include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites){
  char path[]="images/sprites/Perso/000/01.png";
  path[21]= (numSpritePerso/100)+48; //on récupère le chiffre des centaines du numéro de sprite
  numSpritePerso = numSpritePerso%100;//on enleve le chiffre des centaines
  path[22]= (numSpritePerso/10)+48; //on récupère le chiffre des dizaines du numéro de sprite
  numSpritePerso = numSpritePerso%10;//on enleve le chiffre des dizaines
  path[23]= numSpritePerso+48; //on récupère le chiffre des unités du numéro de sprite
  for(int i=0; i<9; i++){
    path[26]= i+49; //on affecte i+1 au caractère des unités
    Perso_Sprites[i]=IMG_Load(path);
  }
  path[25]=49; // on affecte 1 au chiffre des dizaines
  for(int i=0; i<3; i++){
    path[26]= i+48; //on affecte i au caractère des unités
    Perso_Sprites[i+10]=IMG_Load(path);
  }
}

void deplacerPerso(Perso perso, SDL_Surface *ecran, Case ** Map, FileDecors *file){
  SDL_Event event;
  int continuer = 1;
  int iSpriteH = 1;
  int iSpriteD = 1;
  int iSpriteB = 1;
  int iSpriteG = 1;
  int canmove =1;
  int current = 4;
  int numSprite=0;
  perso.position.x=560; //valeurs à récupérer depuis le fichier sauvegarde
  perso.position.y=400; //valeurs à récupérer depuis le fichier sauvegarde
  perso.x=(perso.position.x-(perso.position.x%16))/TAILLE_SPRITE;
  perso.y=(perso.position.y-(perso.position.y%16))/TAILLE_SPRITE;
  printf("%d\t%d\n", perso.x, perso.y);

  while (continuer){
      SDL_PollEvent(&event);
          switch(event.type){
              case SDL_QUIT:
                  SDL_Quit();
              break;
              case SDL_KEYDOWN:
                  switch(event.key.keysym.sym){
                    case SDLK_ESCAPE: // arrêter le jeu
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
                }
            break;
            case SDL_KEYUP:
                iSpriteH=1;
                iSpriteB=1;
                iSpriteG=1;
                iSpriteD=1;
                    switch(event.key.keysym.sym){
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
      displayMap(Map, ecran);
      afficherDecors(file, ecran);
      SDL_BlitSurface(perso.Perso_Sprites[numSprite], NULL, ecran, &perso.position); // Collage de la surface sur l'écran
      SDL_Flip(ecran); // Mise à jour de l'écran
      SDL_Delay(30); //attente de 30ms entre chaque chargement (sert à ne pas réafficher pour rien)
      }
}

int autoriserDeplacement(Case ** Map, Direction direction, Perso perso){

  perso.x=(perso.position.x-(perso.position.x%16))/TAILLE_SPRITE;
  perso.y=(perso.position.y+(perso.position.y%16))/TAILLE_SPRITE;
  printf("%d\t%d\n", (perso.position.x%16), (perso.position.y%16));
  switch(direction){
    case GAUCHE:
        if((perso.position.y%16)==0){
          if(Map[perso.y+1][perso.x].type == 0){
            return 1;
          }
        }
        else{
          if(Map[perso.y+2][perso.x].type == 0){
            return 1;
          }
        }
        return 0;
    break;
    case DROITE:
        if(Map[perso.y+1][perso.x+2].type == 0){
            return 1;
          }
        return 0;
    break;
    case HAUT:
        return 1;
    break;
    case BAS:
        return 1;
    break;
  }

}
