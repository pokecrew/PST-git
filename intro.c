#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

void intro_video(SDL_Surface *ecran){

  SDL_Surface *frames;//Tableau des sprites de la Map
  char SpritePath[]="Ressources/intro_video/0000.png";
  SDL_Rect position;
  SDL_Event event;
  int continuer = 1;
  int i=0;
  unsigned int tempsPrecedent = 0, tempsActuel = 0;
  position.x = position.y = 0;
  printf("\n");
//  printf("%u - %u = %u\n",17,18,17-18);
  music = Mix_LoadMUS("Ressources/Musiques/intro.mp3"); //Musique de la carte
  Mix_PlayMusic(music, 1); //Jouer la musique 1x
  while(continuer){
    if(i < 560){
      SpritePath[24]= i/100+'0';
      SpritePath[25]= (i%100)/10+'0';
      SpritePath[26]=  i%10+'0';
    //  printf("\033[A Chargement : %d%% \n",(i*100)/620);
      frames=IMG_Load(SpritePath);
    }
    SDL_PollEvent(&event);
      switch(event.type){
          case SDL_QUIT:
              SDL_FreeSurface(frames);
              Mix_CloseAudio(); //Fermeture de l'API audio
              SDL_Quit();
          break;
          case SDL_KEYDOWN:
                if(i >= 560){
                  SDL_FreeSurface(frames);
                  continuer = 0;
                  Mix_HaltMusic();
                }
          break;
      }
      if(i < 560){
        SDL_BlitSurface(frames, NULL, ecran, &position);
        SDL_Flip(ecran);
        tempsActuel = SDL_GetTicks();
        if(tempsActuel-tempsPrecedent < 33){ //33 = fps
          SDL_Delay(33-(tempsActuel-tempsPrecedent));
        }
        tempsPrecedent= SDL_GetTicks();
      /*}
      if(i < 619){*/
        SDL_FreeSurface(frames);
        frames=NULL;
        i++;
      }
  }
/*  for(int i=0; i<620; i++){
    SDL_FreeSurface(frames[i]);
  }*/
}
