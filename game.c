#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran)
{
  //printf("TEst EVENEMENT\n");
  //printf("%d\n", Map[i][j].type);
  SDL_Rect position;
  SDL_Event event;
  int continuer =1;
  switch(Map[i][j].type)
  {
    case 2: //Hautes herbes
      lancementCombat(ecran);
      return 1;
      break;

    case 3: //rampe vers le bas
      if(direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 4: //rampe vers la droite
      if(direction == DROITE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 5: //rampe vers la gauche
      if(direction == GAUCHE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 6: //rampe vers la droite ou le bas
      if(direction == DROITE || direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 7: //rampe vers la gauche ou le bas
      if(direction == GAUCHE || direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 8://bord eau coin supérieur gauche
      if((direction == DROITE || direction == BAS) && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 9: //bord eau avec eau à droite
      if(direction == DROITE  && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 10: //bord eau coin inférieur gauche
      if((direction == DROITE || direction == HAUT) && surf == TRUE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 11://bord eau avec eau au dessus
      if(direction == HAUT && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 12: //bord eau coin inférieur droit
      if((direction == GAUCHE || direction == HAUT) && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 13: //bord eau avec eau à gauche
      if(direction == GAUCHE && surf == TRUE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 14://bord eau coin supérieur droit
      if((direction == GAUCHE || direction == BAS) && surf == TRUE)
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 15://bord eau avec eau au dessous
      if(direction == BAS && surf == TRUE)
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 16://heal centre pokemon
      //printf(GREEN"[lancerEvenement]:"RESET"lancement évènement hill possible\n");
      while (continuer)
      {
        SDL_WaitEvent(&event);
          switch(event.type)
          {
            case SDL_QUIT:
              SDL_Quit();
              break;

            case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                case SDLK_ESCAPE: // arrêter le jeu
                  continuer =0;
                  break;

                case SDLK_SPACE: //
                  //printf(GREEN"[lancerEvenement]:"RESET"Debut phrase heal (boite de dialogue)\n");
                  position.x = Map[0][0].position.x+4*TAILLE_SPRITE;
                  position.y = Map[0][0].position.y+2*TAILLE_SPRITE;
                  Mix_PauseMusic(); //on arrête la musique
                  //remplissage du chariot en fonction du nombre de pokéball
                  for(int i=0; i<nbPokeJoueur; i++)
                  {
                    SDL_BlitSurface(Map_Sprites[(2057+i)], NULL, ecran, &position);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                  }
                  //clignotement
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  //2ème clignotement
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  //3ème clignotement
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(120);
                  SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                  SDL_Flip(ecran);
                  SDL_Delay(500);
                  Mix_ResumeMusic();//on remet de la musique
                  calcul_stat(&poke1);
                  //printf(GREEN"[lancerEvenement]:"RESET"Fin heal\n");
                  continuer = 0;
                  break;

                default:
                  continuer = 0;
                  break;
              }
          }
      }
      return 0;
      break;

    case 17:
      if(direction == HAUT)
      {
        printf(GREEN"[lancerEvenement]:"RESET"Panneau/Boite aux lettres\n");
      }
      return 0;
      break;

    case 18: //PNJ
      return 2;
      break;

    default:
      return 1;
      break;
  }
}


int charger_att(Att att[4], int id_att[4]){
  FILE *fic_att = NULL;
  fic_att = fopen("Ressources/Attaques","r");
  char TAB[120];
  char type_temp[10]= {' '};
  fgets(TAB, 119, fic_att);
  int attaques_chargees = 0;
  int attaques_a_charger = 4;
  int continuer =1;
  //Calcul du nombre d'attaques à charger
  for(int i=0; i<4; i++){
  //  printf(BLUE"[charger_att]:"RESET"%d \n",id_att[i]);
    if(id_att[i] == 0){
      attaques_a_charger--;
    }
  }
  printf(GREEN"[charger_att]:"RESET" attaques_a_charger = %d \n",attaques_a_charger);
  int id_f = 0;
  while(attaques_chargees != attaques_a_charger && continuer == 1){
    //recupère l'id en cours
    fgets(TAB, 119, fic_att);
    //printf("Attaque chargées : %d\n",attaques_chargees );
    id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
    //printf("%d\n", id_f);
    for(int i = 0; i<4; i++){
      if(id_att[i] == id_f){
          //chargement id Attaque
          att[i].id = id_f;
        //  printf(GREEN"[charger_att]:"RESET"att[%d].id : %d\n",i, id_f);

          //chargement nom Attaque
          for(int j=0; j<17; j++){ //pour chaque caractère
            if(TAB[4+j] == ' '){//Si il s'agit d'un espace, on affecte 17 à j, ce qui sort de la boucle;
              att[i].nom[j]='\0';
              j=17;
            }
            else if(TAB[4+j] == '_'){ //si c'est un underscore on affiche espace
              att[i].nom[j] = ' ';
            }
            else{
              att[i].nom[j] = TAB[4+j]; //sinon on charge le caractère correspondant
            }
          }
          printf(GREEN"[charger_att]:"RESET"att[%d].nom : %s\n",i, att[i].nom);

          //chargement type Attaque
          for(int k=0; k<8; k++){
            type_temp[k]=TAB[21+k];
          }
          if(strstr(type_temp, "combat") != NULL){
            att[i].type = COMBAT;
          }
          else if(strstr(type_temp, "eau") != NULL){
            att[i].type = EAU;
          }
          else if(strstr(type_temp, "electrik") != NULL){
            att[i].type = ELEC;
          }
          else if(strstr(type_temp, "feu") != NULL){
            att[i].type = FEU;
          }
          else if(strstr(type_temp, "glace") != NULL){
            att[i].type = GLACE;
          }
          else if(strstr(type_temp, "insecte") != NULL){
            att[i].type = INSECTE;
          }
          else if(strstr(type_temp, "plante") != NULL){
            att[i].type = PLANTE;
          }
          else if(strstr(type_temp, "poison") != NULL){
            att[i].type = POISON;
          }
          else if(strstr(type_temp, "psy") != NULL){
            att[i].type = PSY;
          }
          else if(strstr(type_temp, "roche") != NULL){
            att[i].type = ROCHE;
          }
          else if(strstr(type_temp, "sol") != NULL){
            att[i].type = GROUND;
          }
          else if(strstr(type_temp, "spectre") != NULL){
            att[i].type = SPECTRE;
          }
          else if(strstr(type_temp, "vol") != NULL){
            att[i].type = VOL;
          }
          else{
            att[i].type = NORMAL;
          }
        //  printf(GREEN"[charger_att]:"RESET"att[%d].type : %s\n",i, type_temp);

          //chargement classe Attaque
          att[i].classe = (TAB[30] == 'P')? 0 : 1;

          //chargement puissance attaque
          att[i].puissance =	(TAB[42]-'0')*100 + (TAB[43]-'0')*10 + TAB[44]-'0';
          //printf(GREEN"[charger_att]:"RESET"att[%d].puissance : %d\n",i, att[i].puissance);
          //chargement précision attaque
          att[i].precision =	(TAB[48]-'0')*100 + (TAB[49]-'0')*10 + TAB[50]-'0';
        //  printf(GREEN"[charger_att]:"RESET"att[%d].précision : %d\n",i, att[i].puissance);

          //chargement pp_max attaque
          att[i].pp_max =	(TAB[54]-'0')*10 + TAB[55]-'0';
        //  printf(GREEN"[charger_att]:"RESET"att[%d].pp : %d\n",i, att[i].pp);
          attaques_chargees++;//on augmente le compteur d'attaques chargées
      }
    }
    if(id_f == 71){
      continuer =0;
    }
  }
  fclose(fic_att);
}

int animation_evo(int id, SDL_Surface *ecran){
  TTF_Font *police = NULL, *police2 = NULL;
  police = TTF_OpenFont("bulle_dialogue_police.ttf", 30);
  police2 = TTF_OpenFont("bulle_dialogue_police.ttf", 25);
  SDL_Surface  *fond = NULL, *Poke = NULL, *Evo = NULL, *boite_dialogue = NULL, *texte[4]={NULL}; //création des surfaces
  SDL_Rect positionFond, positionPoke, positionDialogue, positionTexte;
  SDL_Event event, event2; //on crée un évènement
    poke2.id = poke1.id +1;
  calcul_stat(&poke2);
  char text[2][100];
  sprintf(text[0],"Quoi ? %s evolue !", poke1.nom);
  sprintf(text[1],"Felicitations ! %s a evolue en %s !", poke1.nom, poke2.nom);
  texte[0] = TTF_RenderText_Blended(police, text[0], couleurTitre);
  texte[1] = TTF_RenderText_Blended(police2, text[1], couleurTitre);
  texte[2] = TTF_RenderText_Blended(police, "(Mieux vaut ne pas le perturber) ", couleurTitre);
  texte[3] = TTF_RenderText_Blended(police, "Le pokemon n'a pas evolue ", couleurTitre);
  char path[80], path2[80];

    sprintf(path,"sprites/poke/%d.png",id);
    sprintf(path2,"sprites/poke/%d.png",(id+1));

  printf("Chemin vers images : \n %s \n %s \n",path, path2);
//  printf("Nom pokemon : %s \n", poke1.nom);
  //images
  fond = IMG_Load("Ressources/animations/evolution/fond.png"); //Chargement de l'image de fond
  Poke = IMG_Load(path); //Image pokemon actuel
  Evo = IMG_Load(path2); //Image évolution
  boite_dialogue = IMG_Load("Ressources/animations/evolution/dialogue.png");
  positionFond.x = 0; //coordonnées de l'arrière plan
  positionFond.y = 0;
  positionPoke.x = 450; //coordonnées de l'arrière plan
  positionPoke.y = 130;
  positionDialogue.x = 140;
  positionDialogue.y = 450;
  positionTexte.x = 190;
  positionTexte.y = 480;

  int continuer = 1;
  int i=0;
  int interval = 600;
  int tempsDebut = 0;
  int tempsPrecedent = 0, tempsActuel = 0;
  int success = 1;
  //// a supprimer dans le jeu
  //Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
  ///
  Mix_PauseMusic(); //on arrete la musique de fond
  Mix_Chunk *son;
  son = Mix_LoadWAV("Ressources/Musiques/evo.ogg");
  Mix_VolumeChunk(son,volumeSon);
  Mix_PlayChannel(-1, son, 0);


  SDL_BlitSurface(fond, NULL, ecran, &positionFond);
  SDL_BlitSurface(Poke, NULL, ecran, &positionPoke);
  SDL_BlitSurface(boite_dialogue, NULL, ecran, &positionDialogue);
  SDL_BlitSurface(texte[0], NULL, ecran, &positionTexte);
  SDL_Flip(ecran); //on mets à jour l'écran
  SDL_Delay(2000);
  tempsDebut = SDL_GetTicks();
  while ((tempsActuel - tempsDebut) <= 16000 && (continuer == 1)){ // on crée une boucle dépendant de la variable continuer pour attendre que le joueur appuie sur une touche
      while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
            break;
            case SDL_KEYDOWN:
                continuer = 0;
                success = 0;
            break;
        }
      }
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > interval) { // Si interval ms se sont écoulées
          tempsPrecedent = tempsActuel; // Le temps "actuel" devient le temps "precedent" pour nos futurs calculs
          if(interval > 50){
            interval -= interval/100 * 6;
          }
          SDL_BlitSurface(fond, NULL, ecran, &positionFond);
          i++;
          if(i%2 == 1){
            SDL_BlitSurface(Poke, NULL, ecran, &positionPoke);
          }
          else{
            SDL_BlitSurface(Evo, NULL, ecran, &positionPoke);
          }
          SDL_BlitSurface(boite_dialogue, NULL, ecran, &positionDialogue);
          SDL_BlitSurface(texte[2], NULL, ecran, &positionTexte);
          SDL_Flip(ecran);
        //  SDL_Delay(60); //temps d'attente entre chaque boucle pour réduire la charge processeur
        }
    }
    if(success == 1){//si l'évolution a marché
      SDL_BlitSurface(fond, NULL, ecran, &positionFond);
      SDL_BlitSurface(Evo, NULL, ecran, &positionPoke);
      SDL_BlitSurface(boite_dialogue, NULL, ecran, &positionDialogue);
      SDL_BlitSurface(texte[1], NULL, ecran, &positionTexte);
      SDL_Flip(ecran);
      while(continuer){
      SDL_WaitEvent(&event);
        switch(event.type)
        {
          case SDL_QUIT:
            SDL_Quit();
            break;

          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
              case SDLK_ESCAPE: // arrêter le jeu
                continuer =0;
              break;
              case SDLK_RETURN: // arrêter le jeu
                continuer =0;

              break;
            }
          }
        }
    }
    else{//si le joueur a empéché une évolution
      Mix_Pause(-1); //Arrête l'effet sonore
      SDL_BlitSurface(fond, NULL, ecran, &positionFond);
      SDL_BlitSurface(Poke, NULL, ecran, &positionPoke);
      SDL_BlitSurface(boite_dialogue, NULL, ecran, &positionDialogue);
      SDL_BlitSurface(texte[3], NULL, ecran, &positionTexte);
      SDL_Flip(ecran);
      SDL_Delay(2000);//remplacer par un  SDL_WaitEvent
      while(continuer){
      SDL_WaitEvent(&event2);
        switch(event2.type)
        {
          case SDL_QUIT:
            SDL_Quit();
            break;

          case SDL_KEYDOWN:
            switch(event2.key.keysym.sym)
            {
              case SDLK_ESCAPE: // arrêter le jeu
                continuer =0;
              break;
              case SDLK_RETURN: // arrêter le jeu
                continuer =0;
              break;
            }
          }
        }
    }
    Mix_FreeChunk(son);
  // on libère les surfaces et les polices avantde quitter
  SDL_FreeSurface(fond);
  SDL_FreeSurface(Poke);
  SDL_FreeSurface(Evo);
  SDL_FreeSurface(boite_dialogue);
  SDL_FreeSurface(texte[0]);
  SDL_FreeSurface(texte[1]);
  SDL_FreeSurface(texte[2]);
  SDL_FreeSurface(texte[3]);
  TTF_CloseFont(police);
  TTF_CloseFont(police2);
  //on rétablit la musique de base
  Mix_ResumeMusic();

return success;
}

void tirage_poke_sauvage(int poke1_niv){
  srand(time(NULL));
  Poke preEvo;
  int continuer = 1;
  do{
    continuer = 0;
		poke2.id = rand()%151;
    preEvo.id = (poke2.id)-1;
    calcul_stat(&preEvo);
		calcul_stat(&poke2);
    if(poke2.nivEvo == 111 || poke2.id == 0 || (preEvo.id != 0 && preEvo.nivEvo != 111 && preEvo.nivEvo >= poke1_niv)){
      continuer = 1;
    }
	}while(continuer);
}

void selection_att_adv(Poke *poke){
  //printf(GREEN"[apprendre_att]:"RESET"Id :%d\n",poke->id);
	FILE *fic = NULL;
	fic = fopen("Ressources/Stat_poke","r");
	char TAB[170];
	fgets(TAB, 169, fic);
	int id_f = 0;
  int i = 94, k = 0;
  int niv_depasse = 0;
  int att[2][4]; //att[0][] = id, att[1] = niv
  for(int l = 0; l < 2; l++){
    for(int m = 0; m < 4 ; m++){
      att[l][m]=0;
    }
  }
	while(id_f != poke->id)
	{
		fgets(TAB, 169, fic);
		id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
	}
	while(TAB[i] == '[' && niv_depasse == 0){
  //  printf(" k =%d\n", k);
    att[0][k]= (TAB[i+1] -'0')*10 + (TAB[i+2]-'0')%10;
    att[1][k]= (TAB[i+4] -'0')*10 + (TAB[i+5]-'0')%10;
    //printf(BLUE"[apprendre_att]:"RESET"Attaque n°%d détectée disponible au niveau %d\n", att[0][k], att[1][k]);
    i+=7;
    if((att[1][k] > poke->niv)){
      niv_depasse = 1;
      att[0][k]=0;
      att[1][k]=0;
    }
    k = (k+1)%4;
  }
  for(int j=0; j<4; j++){
    //printf(RED"[apprendre_att]:"RESET"Attaque n°%d retenue disponible au niveau %d\n", att[0][j], att[1][j]);
  }
  //chargement des attaques
  charger_att((poke->attaque), att[0]);
	fclose(fic);
}

void maj_att_niv(Poke *poke){
  //printf(GREEN"[apprendre_att]:"RESET"Id :%d\n",poke->id);
	FILE *fic = NULL;
	fic = fopen("Ressources/Stat_poke","r");
	char TAB[170];
	fgets(TAB, 169, fic);
	int id_f = 0;
  int i = 94;
  int niv_depasse = 0;
  int att[2][4]; //att[0][] = id, att[1] = niv
  for(int l = 0; l < 2; l++){
    for(int m = 0; m < 4 ; m++){
      att[l][m]=0;
    }
  }
	while(id_f != poke->id)
	{
		fgets(TAB, 169, fic);
		id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
	}
	while(TAB[i] == '[' && niv_depasse == 0){
  //  printf(" k =%d\n", k);
    att[0][0]= (TAB[i+1] -'0')*10 + (TAB[i+2]-'0')%10;
    att[1][0]= (TAB[i+4] -'0')*10 + (TAB[i+5]-'0')%10;
    printf(BLUE"[apprendre_att]:"RESET"Attaque n°%d détectée disponible au niveau %d\n", att[0][0], att[1][0]);
    i+=7;
    if((att[1][0] > poke->niv)){
      niv_depasse = 1;
    }
    else if(att[1][0] == poke->niv){
      niv_depasse = 1;
      att[0][1] = poke->attaque[0].id;
      att[0][2] = poke->attaque[1].id;
      att[0][3] = poke->attaque[2].id;
      charger_att((poke->attaque), att[0]);
    }
  }
	fclose(fic);
}
