#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h
void loadsoundEffect(){ //charge les sons dans un tableau
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }
  else{ //si l'API eest correctement chargé
      //on charge les différents effets sonores
      music = Mix_LoadMUS("Ressources/Musiques/000.mp3"); //Musique de la carte
    /*  music[1] = Mix_LoadMUS("");
      music[2] = Mix_LoadMUS("");
      music[3] = Mix_LoadMUS("");*/
    }
}

void changerSonCarte(){
  //printf(GREEN"[changerSonCarte]:"RESET"old = %d, new = %d\n",musicMapPrec,musicMap);
  if(musicMapPrec != musicMap){
    music = realloc_son();
    char path[]="Ressources/Musiques/000.mp3";
    path[20]= musicMap/100+'0';
    path[21]= (musicMap%100)/10+'0';
    path[22]= (musicMap%10)+'0';
    //printf("%s \n",path);
    music = Mix_LoadMUS(path);
    //playSound(musicMap, BOUCLE);
    Mix_PlayMusic(music, BOUCLE); //Jouer la musique en boucle
  }
}
Mix_Music* realloc_son(){
  free(music);
  Mix_Music *music_r;
  return music_r;
}
