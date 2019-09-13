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
                                    Map[i][j].position.x = j*16; //position en pixel du coin supérieur gauche de l'image
                                    Map[i][j].position.y = i*16; //position en pixel du coin supérieur gauche de l'image

                                  //chargement du numéro du sprite à afficher (numIMG)
                                    millier=(fgetc(mapFile)-48); //on récupère le chiffre des centaine
                                    centaine=(fgetc(mapFile)-48); //on récupère le chiffre des centaine
                                    dizaine=(fgetc(mapFile)-48); //on récupere le chiffre des dizaines
                                    unite=(fgetc(mapFile)-48); //on récupère le chiffre des unités
                                    espace= (fgetc(mapFile)); //on récupère les epaces pour éviter de tout décaler
                                    Map[i][j].numIMG = (1000*millier)+(100*centaine)+(10*dizaine)+(unite);

                                  //chargement du type de case (sol, mur, etc)
                                    if(Map[i][j].numIMG < 199){ //si le numéro du sprite est compris entre 000 et 199 (sol)
                                      Map[i][j].type = 0;
                                    }
                                    else if ((Map[i][j].numIMG > 199) && (Map[i][j].numIMG < 399)){ //si le numéro du sprite est compris entre 200 et 399 (mur)
                                      Map[i][j].type = 1;
                                    }


                            }
        }
      /*  for(int k=0;k<NBLIN;k++){
                            for(int l=0;l<NBCOL;l++){
                              printf("%d ", Map[k][l].numIMG);
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

  char SpritePath[]="map/Sprites/Sol/0000.png";
  //récupération de tous les sols (de 0 à 4999)
    for(int i=0; i<5; i++){//chiffre des miliers
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

}

//fonction qui affiche les cases (le sol)
void displayMap(Case ** Map, SDL_Surface *ecran){
        SDL_Surface *floor= NULL;

        floor =  IMG_Load("map/Sprites/Sol/0000.png");

        for(int i=0;i<NBLIN;i++){
			     for(int j=0;j<NBCOL;j++){

                SDL_BlitSurface(floor, NULL, ecran, &Map[i][j].position);
                SDL_BlitSurface(Map_Sprites[(Map[i][j].numIMG)], NULL, ecran, &Map[i][j].position);
              }
			     }

    SDL_Flip(ecran); // Mise  à jour de l'écran
    SDL_FreeSurface(floor); // Libération de la surface

}

//fonction qui initialise la file de Décors
FileDecors *initialiserFileDecors(){
    FileDecors *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}

//fonction qui charge les éléments un à un dans la file
int chargerDecors(char mapPath[], FileDecors *file){

    FILE* mapFile = NULL; //pointeur vers le fichier
    //on charge l'extension pour lire le fichier décors
    mapPath[7]='d';
    mapPath[8]='e';
    mapPath[9]='c';
  //  printf("%s\n", mapPath);
    mapFile = fopen(mapPath, "r"); //ouverture du fichier mapPath en lecture seule
    char chaine[30] =""; //chaine qui contiendra la ligne lue par fgets


    //Decors decors;

    if (mapFile != NULL){
        //printf("Coucou\n");
        while (fgets(chaine, 30, mapFile) != NULL){ //tant qu'on est pas arrivé à la dernière ligne
    //          printf("%s", chaine);
              ajouterElementFileDecors(file,chaine);

          }

    }
    else{
      printf("Erreur lors de l'ouverture de %s /n", mapPath);
      return -1;
    }
    fclose(mapFile);
    return 0;
}

Decors chargerCaracteristiquesDecors(char *chaine){
    char objetType[4] =""; //chaine qui contiendra le type d'objet
    Decors decor;

    //on récupère le type d'objet
    for(int i=0; i<3; i++){
      objetType[i] = chaine[i];
    }
    //printf("type d'objet = %s \n", objetType);
    //Traitement en fonction du type d'objet
    if (strcmp(objetType, "arb") == 0){ // Si il s'agit d'un arbre
            decor.type = ARBRE; //on affecte le bon type à l'objet
            decor.numIMG = 5000; //on affecte le bon rang d'image à l'objet
              //printf("L'objet est un arbre");
    }
    else if(strcmp(objetType, "bat") == 0){ // Si il s'agit d'un batiment
            decor.type = BATIMENT;
            decor.numIMG = 6000;
              //printf("L'objet est un batiment");
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

    if (file->premier != NULL) // La file n'est pas vide
    {
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
void afficherFileTerm(FileDecors *file){
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

        //printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
        i++;
    }

    printf("\n");
}

//fonction qui affiche les décors
void afficherDecors(FileDecors *file, SDL_Surface *ecran){

  if (file == NULL)
  {
      exit(EXIT_FAILURE);
  }
  Decors *actuel = file->premier;
  SDL_Rect position;
  int case_x = 0;
  int case_y = 0;

  while (actuel != NULL){
    if((actuel->repeat_x > 0) || (actuel->repeat_y > 0)){
        position = actuel->position; //positions de la surface
        case_x = actuel->dim_x;
        case_y = actuel->dim_y;
        switch (actuel->type) {
          case ARBRE:
            case_x--;
            case_y-=2;
          break;
          case BATIMENT:
            case_x++;
          break;
          default:
          break;
        }
        for(int i=0; i<(actuel->repeat_x); i++){
          position.x = actuel->position.x+i*(case_x*TAILLE_SPRITE);
          for(int j=0; j<(actuel->repeat_y); j++){
              position.y = actuel->position.y+j*(case_y*TAILLE_SPRITE);
              SDL_BlitSurface(Map_Sprites[(actuel->numIMG)], NULL, ecran, &position);
        }
      }
    }
    else{
      SDL_BlitSurface(Map_Sprites[(actuel->numIMG)], NULL, ecran, &actuel->position);
    }
    actuel = actuel->suivant;
  }
SDL_Flip(ecran);
}
