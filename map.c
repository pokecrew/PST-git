#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h
//fonction créant un tableau de cases des dimensions indiquées dans le fichier map
Case **createMap(char mapPath[]){
  Case **Map;
  FILE* mapFile = NULL;
  mapFile = fopen(mapPath, "r");
  if (mapFile != NULL){
      fscanf(mapFile,"%d %d", &NBLIN, &NBCOL);
      fclose(mapFile);
  }
  else{
      fclose(mapFile);
      printf("Erreur lors de l'ouverture de %s", mapPath);
  }
  Map = malloc(NBLIN*sizeof(Case *));
  for(int i=0; i<NBLIN; i++){
    Map[i]= malloc(NBCOL*sizeof(Case));
  }
  //printf("Création Map ok \n");
  //printf("mapPath = %s \n", mapPath);
  return Map;

}

//fonction servant à charger les caractéristiques des cases de la carte
int loadMap(char mapPath[], Case **Map){
    FILE* mapFile = NULL;
    mapPath[7]='l';
    mapPath[8]='v';
    mapPath[9]='l';
    mapFile = fopen(mapPath, "r");
    int millier = 0;
    int centaine = 0;
    int dizaine = 0;
    int unite = 0;
    char espace;
    if (mapFile != NULL){

        // Boucle de lecture des caractères un à un
        fseek(mapFile, 8, SEEK_SET);
        for(int i=0;i<NBLIN;i++){
                            for(int j=0;j<NBCOL;j++){

                                  //initialisation des positions de la case
                                    Map[i][j].x = i; //numéro de la ligne de la case
                                    Map[i][j].y = j; //numéro de la colonne de la case
                                    Map[i][j].position.x = j*TAILLE_SPRITE; //position en pixel du coin supérieur gauche de l'image
                                    Map[i][j].position.y = i*TAILLE_SPRITE; //position en pixel du coin supérieur gauche de l'image

                                  //chargement du numéro du sprite à afficher (numIMG)
                                    millier=(fgetc(mapFile)-48); //on récupère le chiffre des centaine
                                    centaine=(fgetc(mapFile)-48); //on récupère le chiffre des centaine
                                    dizaine=(fgetc(mapFile)-48); //on récupere le chiffre des dizaines
                                    unite=(fgetc(mapFile)-48); //on récupère le chiffre des unités
                                    espace= (fgetc(mapFile)); //on récupère les epaces pour éviter de tout décaler
                                    Map[i][j].numIMG = (1000*millier)+(100*centaine)+(10*dizaine)+(unite);

                                  //chargement du type de case (sol, mur, etc)
                                    if(Map[i][j].numIMG < 1000){ //si le numéro du sprite est compris entre 000 et 999 (franchissable)
                                      Map[i][j].type = 0; //type franchissable
                                    }
                                    else {
                                      Map[i][j].type = 1; //type infranchissable
                                    }


                            }
        }
        /*        for(int k=0;k<NBLIN;k++){
                      for(int l=0;l<NBCOL;l++){
                              printf("%d ", Map[k][l].type);
                      }
                      printf("\n");
                  }*/
    }
    else{
      return -1;
    }
    fclose(mapFile);
    return 0;

}

//fonction qui charge tous les sprites dans la mémoire
void chargerSpritesMap(){

  char SpritePath[]="map/Tiles32/Sol/0000.png";
  //Récupération de la taille des sprites à aller charger
  SpritePath[9]=TAILLE_SPRITE/10+48;
  SpritePath[10]=TAILLE_SPRITE%10+48;
  //récupération de tous les sols (de 0 à 1999)
    for(int i=0; i<2; i++){//chiffre des miliers
        SpritePath[16]= i+48;
        for(int j=0; j<10; j++){//chiffre des centaines
            SpritePath[17]=j+48;
            for(int k=0; k<10; k++){//chiffre des dizaines
                SpritePath[18]=k+48;
                for(int l=0; l<10; l++){//chiffre des unités
                    SpritePath[19]=l+48;
                    Map_Sprites[(i*1000)+(j*100)+(k*10)+l]=IMG_Load(SpritePath);
                }
            }
        }
    }
    //récupération de tous les décors intérieurs (partie 1) (2000 à 2999)
          SpritePath[12]='I';
          SpritePath[13]='n';
          SpritePath[14]='1';
          SpritePath[16]= '2';
          for(int j=0; j<10; j++){//chiffre des centaines
              SpritePath[17]=j+48;
              for(int k=0; k<10; k++){//chiffre des dizaines
                  SpritePath[18]=k+48;
                  for(int l=0; l<10; l++){//chiffre des unités
                      SpritePath[19]=l+48;
                      Map_Sprites[(2*1000)+(j*100)+(k*10)+l]=IMG_Load(SpritePath);
                  }
              }
          }
  //récupération de tous les arbres (5000 à 5999)
        SpritePath[12]='A';
        SpritePath[13]='r';
        SpritePath[14]='b';
        SpritePath[16]= '5';
        for(int j=0; j<10; j++){//chiffre des centaines
            SpritePath[17]=j+48;
            for(int k=0; k<10; k++){//chiffre des dizaines
                SpritePath[18]=k+48;
                for(int l=0; l<10; l++){//chiffre des unités
                    SpritePath[19]=l+48;
                    Map_Sprites[(5*1000)+(j*100)+(k*10)+l]=IMG_Load(SpritePath);
                }
            }
        }
    //récupération de tous les batiments (6000 à 6999)
        SpritePath[12]='B';
        SpritePath[13]='a';
        SpritePath[14]='t';
        SpritePath[16]= '6';
        for(int j=0; j<10; j++){//chiffre des centaines
            SpritePath[17]=j+48;
            for(int k=0; k<10; k++){//chiffre des dizaines
                SpritePath[18]=k+48;
                for(int l=0; l<10; l++){//chiffre des unités
                    SpritePath[19]=l+48;
                    Map_Sprites[(6*1000)+(j*100)+(k*10)+l]=IMG_Load(SpritePath);
                }
            }
        }
      //récupération de tous les évènements (8000 à 8999)
            SpritePath[12]='E';
            SpritePath[13]='v';
            SpritePath[14]='e';
            SpritePath[16]= '8';
            for(int j=0; j<10; j++){//chiffre des centaines
                SpritePath[17]=j+48;
                for(int k=0; k<10; k++){//chiffre des dizaines
                    SpritePath[18]=k+48;
                    for(int l=0; l<10; l++){//chiffre des unités
                        SpritePath[19]=l+48;
                        Map_Sprites[(8*1000)+(j*100)+(k*10)+l]=IMG_Load(SpritePath);
                    }
                }
            }
      //    printf("%s\n", SpritePath);
}

//fonction qui affiche les cases (le sol)
void displayMap(Case ** Map, SDL_Surface *ecran, Perso perso){
        effacerEcran(Map_Sprites[1533], ecran);
        for(int i=0;i<NBLIN;i++){
			     for(int j=0;j<NBCOL;j++){
             if(Map[i][j].position.x >= 0 && Map[i][j].position.x <= FENETRE_W && Map[i][j].position.y >=0 && Map[i][j].position.y <= FENETRE_H){
                SDL_BlitSurface(Map_Sprites[0], NULL, ecran, &Map[i][j].position);
                SDL_BlitSurface(Map_Sprites[(Map[i][j].numIMG)], NULL, ecran, &Map[i][j].position);
                }
              }
			     }

}
//met un fond noir sur la map
void effacerEcran(SDL_Surface *noir, SDL_Surface *ecran){
  SDL_Rect pos;
   for(int i=0; i<(FENETRE_W/TAILLE_SPRITE); i++ ){
     for(int j=0;j<(FENETRE_H/TAILLE_SPRITE); j++){
       pos.x = i*TAILLE_SPRITE;
       pos.y = j*TAILLE_SPRITE;
       SDL_BlitSurface(noir, NULL, ecran, &pos);
     }
   }
 }

//fonction qui initialise la file de Décors
FileDecors *initialiserFileDecors(){
    FileDecors *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}

//fonction qui charge les éléments un à un dans la file
int chargerObjets(char mapPath[], FileDecors *fileDecors, FilePorte *filePorte){

    FILE* mapFile = NULL; //pointeur vers le fichier
    int objet_type = 1;
    int cmp = -1;
    //on charge l'extension pour lire le fichier objet
    mapPath[7]='o';
    mapPath[8]='b';
    mapPath[9]='j';
  //  printf("%s\n", mapPath);
    mapFile = fopen(mapPath, "r"); //ouverture du fichier mapPath en lecture seule
    char chaine[30] =""; //chaine qui contiendra la ligne lue par fgets

    //Decors decors;

    if (mapFile != NULL){
        //printf("Coucou\n");
        while (fgets(chaine, 30, mapFile) != NULL){ //tant qu'on est pas arrivé à la dernière ligne
                cmp = strcmp(chaine,"##########\n");
                if(cmp != 0){

                  switch (objet_type) {
                    case 1 : //décors
                        ajouterElementFileDecors(fileDecors,chaine);
                    break;
                    case 2: //changement map
                        ajouterElementFilePorte(filePorte,chaine);
                    break;
                  }
                }
                else {
                  objet_type++;
                }
          }

    }
    else{
      printf("Erreur lors de l'ouverture de %s /n", mapPath);
      return -1;
    }
    fclose(mapFile);
    return 0;
}

void deplacerObjets(FileDecors *fileDecors, FilePorte *filePorte, Direction direction){//déplace les objets en même temps que la carte
  //Partie décors
  if (fileDecors->premier != NULL){ // La file n'est pas vide
      // On se positionne à la fin de la file
      Decors *elementActuel = fileDecors->premier;
      while (elementActuel != NULL){
        switch(direction){
          case HAUT:
            elementActuel->pos_y += 1;
            elementActuel->position.y += TAILLE_SPRITE/2;
          break;
          case BAS:
            elementActuel->pos_y -= 1;
            elementActuel->position.y -= TAILLE_SPRITE/2;
          break;
          case DROITE:
            elementActuel->pos_x -= 1;
            elementActuel->position.x -= TAILLE_SPRITE/2;
          break;
          case GAUCHE:
            elementActuel->pos_x += 1;
            elementActuel->position.x += TAILLE_SPRITE/2;
          break;
        }
        elementActuel = elementActuel->suivant;
      }
  }
  //partie porte
  if (filePorte->premier != NULL){ // La file n'est pas vide
      // On se positionne à la fin de la file
      Porte *element = filePorte->premier;
      while (element != NULL){
        switch(direction){
          case HAUT:
            element->pos_y += 1;
            element->position.y += TAILLE_SPRITE/2;
          break;
          case BAS:
            element->pos_y -= 1;
            element->position.y -= TAILLE_SPRITE/2;
          break;
          case DROITE:
            element->pos_x -= 1;
            element->position.x -= TAILLE_SPRITE/2;
          break;
          case GAUCHE:
            element->pos_x += 1;
            element->position.x += TAILLE_SPRITE/2;
          break;
        }
        element = element->suivant;
      }
  }
}
int chargerTypeEvenement(Decors element){
  //La fonction permet de calculer le type de la map en fonction de l'evenement que l'on applique dessus
  if(element.numIMG == 8000){//hautes herbes
    return 2;
  }
  else if(element.numIMG >= 8001 && element.numIMG <= 8003){//rampe vers le bas
    return 3;
  }
  else if(element.numIMG >= 8004 && element.numIMG <= 8006){//rampe vers la droite
    return 4;
  }
  else if(element.numIMG >= 8007 && element.numIMG <= 8009){//rampe vers la gauche
    return 5;
  }
  else if(element.numIMG == 8010){ //rampe vers la droite ou le bas
    return 6;
  }
  else if(element.numIMG == 8011){ //rampe vers la gauche ou le bas
    return 7;
  }
  else if(element.numIMG == 8012){//bord eau coin supérieur gauche
    return 8;
  }
  else if(element.numIMG == 8013){//bord eau avec eau à droite
    return 9;
  }
  else if(element.numIMG == 8014){ //bord eau coin inférieur gauche
    return 10;
  }
  else if(element.numIMG == 8015){//bord eau avec eau au dessus
    return 11;
  }
  else if(element.numIMG == 8016){//bord eau coin inférieur droit
    return 12;
  }
  else if(element.numIMG == 8017){ //bord eau avec eau à gauche
    return 13;
  }
  else if(element.numIMG == 8018){//bord eau coin supérieur droit
    return 14;
  }
  else if(element.numIMG == 8019){//bord eau avec eau au dessous
    return 15;
  }
  else{
    return 0;
  }

}
Decors chargerCaracteristiquesDecors(char *chaine){
    char objetType[4] =""; //chaine qui contiendra le type d'objet
    Decors decor;
    typeSprite = 0; //on passe à la grande taille de sprites
    //on récupère le type d'objet
    for(int i=0; i<3; i++){
      objetType[i] = chaine[i];
    }
    //printf("type d'objet = %s \n", objetType);
    //Traitement en fonction du type d'objet
    if(strcmp(objetType, "sol") == 0){ // Si il s'agit d'un sol
            decor.type = SOL;
            decor.numIMG = 0000;
              //printf("L'objet est un sol");
    }
    else if (strcmp(objetType, "mur") == 0){ // Si il s'agit d'un arbre
            decor.type = MUR; //on affecte le bon type à l'objet
            decor.numIMG = 1000; //on affecte le bon rang d'image à l'objet
              //printf("L'objet est un arbre");
    }
    else if (strcmp(objetType, "in1") == 0){ // Si il s'agit d'un arbre
            decor.type = INTERIEUR1; //on affecte le bon type à l'objet
            decor.numIMG = 2000; //on affecte le bon rang d'image à l'objet
            typeSprite = 12; //on passe à la grande taille de sprites
              //printf("L'objet est un arbre");
    }
    else if (strcmp(objetType, "arb") == 0){ // Si il s'agit d'un arbre
            decor.type = ARBRE; //on affecte le bon type à l'objet
            decor.numIMG = 5000; //on affecte le bon rang d'image à l'objet
              //printf("L'objet est un arbre");
    }
    else if(strcmp(objetType, "bat") == 0){ // Si il s'agit d'un batiment
            decor.type = BATIMENT;
            decor.numIMG = 6000;
              //printf("L'objet est un batiment");
    }
    else if(strcmp(objetType, "eve") == 0){ // Si il s'agit d'un évènement
            decor.type = EVENEMENT;
            decor.numIMG = 8000;
              //printf("L'objet est un évènement");
    }
    else{
            decor.type = AUTRE;
            decor.numIMG = 9000;
              //printf("Le type d'objet n'est pas défini");
    }

    //on recupère les chiffre qui suivent le type d'objet et on les stock dans numIMG
    decor.numIMG += ((chaine[3]-48)*100)+((chaine[4]-48)*10)+(chaine[5]-48);
      //printf(" et l'image correspondante est %d.png \n", decor.numIMG);

    //récupération de sa position (en cases)
    decor.pos_x = ((chaine[8]-48)*10)+(chaine[9]-48);
    decor.pos_y = ((chaine[11]-48)*10)+(chaine[12]-48);
      //printf(", ses coordonnées sont (%d;%d) \n", decor.pos_x, decor.pos_y);

    //Calcul de sa position en pixel
    decor.position.x = decor.pos_x*TAILLE_SPRITE;
    decor.position.y = decor.pos_y*TAILLE_SPRITE;
      //printf(", ses coordonnées en pixels sont (%d;%d) \n", decor.position.x, decor.position.y);

    //récupération de ses dimensions (en cases)
    decor.dim_x = ((chaine[15]-48)*10)+(chaine[16]-48);
    decor.dim_y = ((chaine[18]-48)*10)+(chaine[19]-48);
      //printf(", ses dimensions sont (%d;%d) \n", decor.dim_x, decor.dim_y);

    //récupération de ses dimensions (en cases)
    decor.repeat_x = ((chaine[22]-48)*10)+(chaine[23]-48);
    decor.repeat_y = ((chaine[25]-48)*10)+(chaine[26]-48);
  //      printf(", sa répétition se fera %d fois sur les x et %d fois sur les y \n", decor.repeat_x, decor.repeat_y);


    return decor;
}

//Fonction qui rajoute un élément à la file de décors (à la fin)
void ajouterElementFileDecors(FileDecors *file, char *chaine){
    Decors *nouveau = malloc(sizeof(*nouveau));
    //si il y a  une erreur on quitte
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    *nouveau = chargerCaracteristiquesDecors(chaine);
    nouveau->suivant = NULL;

    if (file->premier != NULL){ // La file n'est pas vide
        // On se positionne à la fin de la file
        Decors *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else // La file est vide, notre élément est le premier
    {
        file->premier = nouveau;
    }
}

//Fonction qui vide la file
int viderFileDecors(FileDecors *file){
    if (file == NULL)
    {
        printf("Erreur lors du nettoyage de la file de décors/n");
        exit(EXIT_FAILURE);//on retourne qu'il y a une erreur
    }


    // On vérifie s'il y a quelque chose à retirer */
    while (file->premier != NULL){
        Decors *elementDefile = file->premier;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return 0;
}

//Fonction qui affiche dans le terminal les éléments de la file des décors
void afficherFileDecorsTerm(FileDecors *file){
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Decors *actuel = file->premier;
    int i=0;

    while (actuel != NULL){

        printf("\nDécor n°%d\n",i);
        printf("Type: %d\n", actuel->type);
        printf("Sprite : %d.png\n", actuel->numIMG);
        printf("Dimensions: (%d;%d)\n", actuel->dim_x, actuel->dim_y);
        printf("Position: (%d;%d) / (%d,%d)\n", actuel->pos_x, actuel->pos_y, actuel->position.x, actuel->position.y);
        printf("Répétition : (%d;%d)\n", actuel->repeat_x, actuel->repeat_y);

      //  printf("%d", actuel->nombre);
        actuel = actuel->suivant;
        i++;
    }

    printf("\n");
}

//fonction qui affiche les décors
void afficherDecors(FileDecors *file, SDL_Surface *ecran, Perso perso, int currentSprite){

  if (file == NULL)
  {
      exit(EXIT_FAILURE);
  }
  Decors *actuel = file->premier;
  SDL_Rect position;
  int repeat_x = 0;
  int repeat_y = 0;
  int affichage_Perso = 0; //stocke si le perso est déja affiché ou non
/*  printf("\n");*/
  while (actuel != NULL){
    position = actuel->position; //positions de la surface
    if((actuel->repeat_x > 0) || (actuel->repeat_y > 0)){
        //position = actuel->position; //positions de la surface
        repeat_x = actuel->dim_x;
        repeat_y = actuel->dim_y;
        switch (actuel->type) {
          case ARBRE:
            repeat_x--;
            repeat_y-=2;
          break;
          case BATIMENT:
            repeat_x++;
          break;
          default:
          break;
        }
        for(int i=0; i<(actuel->repeat_x); i++){
          position.x = actuel->position.x+i*(repeat_x*TAILLE_SPRITE);
          for(int j=0; j<(actuel->repeat_y); j++){
              position.y = actuel->position.y+j*(repeat_y*TAILLE_SPRITE);
              /*if(affichage_Perso == 0 && position.y >= perso.position.y){// && (position.x >= perso.position.x)){
                SDL_BlitSurface(perso.Perso_Sprites[currentSprite], NULL, ecran, &perso.position); // Collage de la surface sur l'écran
                affichage_Perso = 1;
                printf(BLUE"R:perso : (%d;%d) \n"RESET, perso.position.x, perso.position.y);
              }*/
              if(position.x >= 0 && position.x <= FENETRE_W && position.y >= 0 && position.y <= FENETRE_H){
              /*  printf("R :décors %d : (%d;%d) \n", actuel->numIMG, actuel->position.x,actuel->position.y);*/
                SDL_BlitSurface(Map_Sprites[(actuel->numIMG)], NULL, ecran, &position);
              }
        }
      }
    }
    else{
      if(affichage_Perso == 0 && position.y >= perso.position.y){// && (position.x >= perso.position.x)){
        SDL_BlitSurface(perso.Perso_Sprites[currentSprite], NULL, ecran, &perso.position); // Collage de la surface sur l'écran
        /*printf(BLUE"S :perso : (%d;%d) \n"RESET, perso.position.x, perso.position.y);*/
        affichage_Perso = 1;
      }
      if(position.x >= 0 && position.x <= FENETRE_W && position.y >= 0 && position.y <= FENETRE_H){
      /*  printf("S: décors %d : (%d;%d) \n", actuel->numIMG, position.x,position.y);*/
        SDL_BlitSurface(Map_Sprites[(actuel->numIMG)], NULL, ecran, &actuel->position);
      }
    }
    actuel = actuel->suivant;
  }
  if(affichage_Perso == 0){
    SDL_BlitSurface(perso.Perso_Sprites[currentSprite], NULL, ecran, &perso.position); // Collage de la surface sur l'écran
  }
}

//fonction qui charge les collisions des décors
void chargerCollisionsDecors(FileDecors *file, Case ** Map){

  if (file == NULL)
  {
      exit(EXIT_FAILURE);
  }
  Decors *actuel = file->premier;
  int pos_x = 0;
  int pos_y = 0;
  int repeat_x = 0; //cases séparant chaque répitiion
  int repeat_y = 0;
  int dim_x = 0;//dimension du décor en case de collision
  int dim_y = 0;//dimension du décor en case de collision
  int init_x = 0;//dimension du décor en case de collision
  int init_y = 0;//dimension du décor en case de collision
  int typeCollisions = 1 ; //type de collision (0: franchissable, 1 : infranchissable)

  while (actuel != NULL){
    pos_x = actuel->pos_x; //coordonées de la case (axe des x)
    pos_y = actuel->pos_y; //coordonées de la case (axe des y)
    dim_x = actuel->dim_x; //largeur de l'objet décor (en cases)
    dim_y = actuel->dim_y; //hauteur de l'objet décor (en cases)
    init_x = 0; //case à laquelle commence les collisions (sur l'axe des x)
    init_y = 0; //case à laquelle commence les collisions (sur l'axe des y)
    switch (actuel->type) {
      case SOL :
        typeCollisions = 0;
      break;
      case ARBRE:
        dim_y--;
        //dim_x--;
        init_y++;
      break;
      case BATIMENT:
        dim_y--;
        init_y+=2;
      break;
      case EVENEMENT :
        typeCollisions = chargerTypeEvenement(*actuel);
      break;
      default:
      break;
    }
      if((actuel->repeat_x > 0) || (actuel->repeat_y > 0)){
          repeat_x = actuel->dim_x;
          repeat_y = actuel->dim_y;
          switch (actuel->type) {
            case ARBRE:
              repeat_x--;
              repeat_y-=2;
            break;
            case BATIMENT:
              repeat_x++;
            break;
            default:
            break;
          }
          for(int i=0; i<(actuel->repeat_x); i++){
            pos_x = actuel->pos_x+(i*repeat_x);
            for(int j=0; j<(actuel->repeat_y); j++){
              pos_y = actuel->pos_y+(j*repeat_y);
                for(int k=init_y; k < dim_y; k++){
                  for(int l=0; l < dim_x; l++){
                      Map[pos_y+k][pos_x+l].type = typeCollisions;
                  }
              }
              //  SDL_BlitSurface(Map_Sprites[(actuel->numIMG)], NULL, ecran, &position);
          }
        }
      }
      else{
          for(int k=init_y; k < dim_y; k++){
              for(int l=0; l < dim_x; l++){
                  Map[pos_y+k][pos_x+l].type = typeCollisions;
              }
          }
      }
    typeCollisions = 1;
    actuel = actuel->suivant;
  }
}

void afficheCollisions(Case ** Map, SDL_Surface *ecran){
  SDL_Surface *image = NULL;
  char SpritePath[]="map/Tiles32/collision.png";
  //Récupération de la taille des sprites à aller charger
  SpritePath[9]=TAILLE_SPRITE/10+48;
  SpritePath[10]=TAILLE_SPRITE%10+48;

  image = IMG_Load(SpritePath);
  for(int i=0;i<NBLIN;i++){
     for(int j=0;j<NBCOL;j++){
        if(Map[i][j].type == 1){
          if(Map[i][j].position.x > 0 && Map[i][j].position.x < FENETRE_W && Map[i][j].position.y >0 && Map[i][j].position.y < FENETRE_H){
            SDL_BlitSurface(image, NULL, ecran, &Map[i][j].position);
          }
        }
      }
  }
}
//fonction qui permet de changer de carte
int changeMap(int numeroMap, Case ** Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position){

  mapPath[4]= (numeroMap/10)+48;
  mapPath[5]= numeroMap%10+48;
  numMap=numeroMap;
  viderFileDecors(fileDecors);
  viderFilePorte(filePorte);
  //On libère la map
  viderMap(Map);
  Map = createMap(mapPath);
  chargerObjets(mapPath, fileDecors, filePorte);//on charge les décors
//  afficherFileDecorsTerm(fileDecors);
  int chargementMap=loadMap(mapPath, Map);
  chargerCollisionsDecors(fileDecors, Map);
  centrerMap(Map,fileDecors,filePorte, perso_position);
//  printf("Load ok \n");

}
//fonction qui initialise la file de Décors
FilePorte *initialiserFilePorte(){
    FilePorte *file = malloc(sizeof(*file));
    file->premier = NULL;
    return file;
}
//Fonction qui rajoute un élément à la file de portes (à la fin)
void ajouterElementFilePorte(FilePorte *file, char *chaine){
    Porte *nouveau = malloc(sizeof(*nouveau));
    //si il y a  une erreur on quitte
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    *nouveau = chargerCaracteristiquesPortes(chaine);
    nouveau->suivant = NULL;

    if (file->premier != NULL){ // La file n'est pas vide
        // On se positionne à la fin de la file
        Porte *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else // La file est vide, notre élément est le premier
    {
        file->premier = nouveau;
    }
}
//Fonction qui vide la file
int viderFilePorte(FilePorte *file){
    if (file == NULL)
    {
        printf("Erreur lors du nettoyage de la file de portes/n");
        exit(EXIT_FAILURE);//on retourne qu'il y a une erreur
    }


    // On vérifie s'il y a quelque chose à retirer */
    while (file->premier != NULL){
        Porte *elementDefile = file->premier;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return 0;
}
//Fonction qui charge les caractéristiques des portes
Porte chargerCaracteristiquesPortes(char *chaine){
    Porte porte;
      //on recupère les chiffres qui suivent le type d'objet et on les stock dans Porte.map
    porte.map = ((chaine[3]-48)*100)+((chaine[4]-48)*10)+(chaine[5]-48);
    //printf(" et l'image correspondante est %d.png \n", decor.numIMG);

    //récupération de sa position (en cases)
    porte.pos_x = ((chaine[8]-48)*10)+(chaine[9]-48);
    porte.pos_y = ((chaine[11]-48)*10)+(chaine[12]-48);
      //printf(", ses coordonnées sont (%d;%d) \n", decor.pos_x, decor.pos_y);

    //Calcul de sa position en pixel
    porte.position.x = porte.pos_x*TAILLE_SPRITE;
    porte.position.y = porte.pos_y*TAILLE_SPRITE;
      //printf(", ses coordonnées en pixels sont (%d;%d) \n", decor.position.x, decor.position.y);

    //récupération de ses dimensions (en cases)
    porte.dim_x = ((chaine[15]-48)*10)+(chaine[16]-48);
    porte.dim_y = ((chaine[18]-48)*10)+(chaine[19]-48);

    //récupération de la position du perso sur la map d'arrivée
    porte.pos_perso.x = (((chaine[22]-48)*10)+(chaine[23]-48))*TAILLE_SPRITE;
    porte.pos_perso.y = (((chaine[25]-48)*10)+(chaine[26]-48))*TAILLE_SPRITE;


    return porte;
}
void afficherFilePorteTerm(FilePorte *file){
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Porte *actuel = file->premier;
    int i=0;

    while (actuel != NULL){

        printf("\nPorte n°%d\n",i);
        printf("Lien: map n°%d\n", actuel->map);
        printf("Dimensions: (%d;%d)\n", actuel->dim_x, actuel->dim_y);
        printf("Position: (%d;%d) / (%d,%d)\n", actuel->pos_x, actuel->pos_y, actuel->position.x, actuel->position.y);
        printf("Position du perso sur la nouvelle map (en pixels): (%d;%d)", actuel->pos_perso.x, actuel->pos_perso.y);

        actuel = actuel->suivant;
        i++;
    }

    printf("\n");
}
void afficherFilePorteSDL(FilePorte *file, SDL_Surface *ecran){
    SDL_Surface *image = NULL;
    SDL_Rect position;
    char SpritePath[]="map/Tiles32/portes.png";
    //Récupération de la taille des sprites à aller charger
    SpritePath[9]=TAILLE_SPRITE/10+48;
    SpritePath[10]=TAILLE_SPRITE%10+48;
    image = IMG_Load(SpritePath);

    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Porte *actuel = file->premier;
    int i=0;

    while (actuel != NULL){

        for(int i=0; i< actuel->dim_x; i++){
          for(int j=0; j< actuel->dim_y; j++){
            position.x = actuel->position.x + i*TAILLE_SPRITE;
            position.y = actuel->position.y + j*TAILLE_SPRITE;
            SDL_BlitSurface(image, NULL, ecran, &position);
          }
        }


        actuel = actuel->suivant;

    }
}
int verifChangementMap(Case ** Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position){
    if (fileDecors == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Porte *actuel = filePorte->premier;

    while (actuel != NULL){
      if( ((perso_position->x+(TAILLE_SPRITE/2)) >= actuel->position.x) && ((perso_position->y+(TAILLE_SPRITE*3/2)) >= actuel->position.y) && ((perso_position->x+(TAILLE_SPRITE/2)) < (actuel->position.x+(TAILLE_SPRITE*(actuel->dim_x)))) && ((perso_position->y+(TAILLE_SPRITE*3/2)) < (actuel->position.y+(TAILLE_SPRITE*actuel->dim_y)))){
        //printf("\ndimensions porte : (%d,%d)", actuel->dim_x, actuel->dim_y);
        //printf("\nperso_position = (%d;%d)", perso_position->x, perso_position->y);
        *perso_position = actuel->pos_perso;
        changeMap(actuel->map, Map, fileDecors, filePorte, perso_position);
        //centrerMap(Map,fileDecors,filePorte, perso_position);
        return 1;
      }
      //printf("position porte : (%d,%d)\n", actuel->position.x, actuel->position.y);
      //printf("perso_position = (%d;%d)\n", perso_position->x+TAILLE_SPRITE, perso_position->y+(TAILLE_SPRITE*3/2));
      actuel = actuel->suivant;
    }
    return 0;
}
void lancementCombat(SDL_Surface *ecran){
  //srand(time(NULL));
  int alea = 0;
  alea = rand()%13;
  lancerCombat++;
  //printf("lancerCombat = %d, alea= %d \n", lancerCombat, alea);
  if(lancerCombat > 8 && (alea == 0 || lancerCombat > 60)){
  //if(alea == 0){
    combat(ecran);
    lancerCombat = 0;
  }
}
void centrerMap(Case ** Map, FileDecors *fileDecors, FilePorte *filePorte, SDL_Rect *perso_position){
  //Calcul du déplacement à effectuer
  int x;
  int y =  FENETRE_H/2 - perso_position->y;
  int largeurMap = Map[0][NBCOL-1].position.x + TAILLE_SPRITE - Map[0][0].position.x ;
  int hauteurMap = Map[NBLIN-1][0].position.y + TAILLE_SPRITE - Map[0][0].position.y ;
  //printf(ONLINE BLUE"%d;%d"RESET, x, y);

  //si la map est moins large que l'écran, on la centre horizontalement
  if(largeurMap < FENETRE_W){
      x = (FENETRE_W - largeurMap)/2;
      //centrage vertical
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.x += x;
                            Map[i][j].x += x/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_x += x/TAILLE_SPRITE;
                elementActuel->position.x += x;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_x += x/TAILLE_SPRITE;
            element->position.x += x;
            element = element->suivant;
          }
      }
      perso_position->x += x;

  }
  else{
      //on centre d'abord la carte sur le joueur
      x =  FENETRE_W/2 - perso_position->x;
      //centrage vertical
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.x += x;
                            Map[i][j].x += x/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_x += x/TAILLE_SPRITE;
                elementActuel->position.x += x;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_x += x/TAILLE_SPRITE;
            element->position.x += x;
            element = element->suivant;
          }
      }
      perso_position->x = FENETRE_W/2;

      //On colle les bords
      if(Map[0][0].position.x > 0){
        x = 0 - Map[0][0].position.x;
      }
      else if((Map[0][NBCOL-1].position.x + TAILLE_SPRITE) < FENETRE_W){
        x = FENETRE_W - Map[0][NBCOL-1].position.x + TAILLE_SPRITE;
      }
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.x += x;
                            Map[i][j].x += x/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_x += x/TAILLE_SPRITE;
                elementActuel->position.x += x;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_x += x/TAILLE_SPRITE;
            element->position.x += x;
            element = element->suivant;
          }
      }
      perso_position->x += x;
  }
  //Centrage vertical
  if(hauteurMap < FENETRE_H){
      y = (FENETRE_H - hauteurMap)/2;
      //centrage vertical
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.y += y;
                            Map[i][j].y += y/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_y += y/TAILLE_SPRITE;
                elementActuel->position.y += y;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_y += y/TAILLE_SPRITE;
            element->position.y += y;
            element = element->suivant;
          }
      }
      perso_position->y += y;

  }
  else{
  //  printf("Fenetre plus haute\n");
      //on centre d'abord la carte sur le joueur
      y =  FENETRE_H/2 - perso_position->y;
      //centrage vertical
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.y += y;
                            Map[i][j].y += y/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_y += y/TAILLE_SPRITE;
                elementActuel->position.y += y;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_y += y/TAILLE_SPRITE;
            element->position.y += y;
            element = element->suivant;
          }
      }
      perso_position->y = FENETRE_H/2 ;

      //On colle les bords
      if(Map[0][0].position.y > 0){
        y = 0 - Map[0][0].position.y;
      }
      else if((Map[NBLIN-1][0].position.y + TAILLE_SPRITE) < FENETRE_H){
        y = FENETRE_H - Map[NBLIN-1][0].position.y + TAILLE_SPRITE;
      }
      else{
        //printf("break");
        y=0;
        //break;
      }
      //Déplacement du fond
      for(int i=0;i<NBLIN;i++){
                          for(int j=0;j<NBCOL;j++){
                            Map[i][j].position.y += y;
                            Map[i][j].y += y/TAILLE_SPRITE;
                          }
      }
      //Partie décors
      if (fileDecors->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Decors *elementActuel = fileDecors->premier;
          while (elementActuel != NULL){
                elementActuel->pos_y += y/TAILLE_SPRITE;
                elementActuel->position.y += y;
            elementActuel = elementActuel->suivant;
          }
      }
      //partie porte
      if (filePorte->premier != NULL){ // La file n'est pas vide
          // On se positionne à la fin de la file
          Porte *element = filePorte->premier;
          while (element != NULL){
            element->pos_y += y/TAILLE_SPRITE;
            element->position.y += y;
            element = element->suivant;
          }
      }
      perso_position->y += y;
    }
}
void viderMap(Case **Map){
  for(int i=0; i<NBLIN; i++){
    free(Map[i]);
    Map[i] = NULL;
  }
  free(Map);
  Map = NULL;
}
