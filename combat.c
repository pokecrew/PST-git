#include "include.h"



void fenetre (SDL_Surface *ecran)
{
  SDL_Surface *fond = NULL, *attaque = NULL, *pardessus = NULL;
  SDL_Rect position;
  SDL_Rect positionattaque;
  SDL_Rect positionpardessus;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Je suis en combat !!!",NULL);


  fond = IMG_Load("images/combatimage/fond.png");
  attaque = SDL_CreateRGBSurface(SDL_HWSURFACE,220,180,32,0,0,0,0);
  pardessus = SDL_CreateRGBSurface(SDL_HWSURFACE,220,180,32,0,0,0,0);

  position.x = 0;
  position.y = 0;
  positionattaque.x = 570;
  positionattaque.y = 400;
  positionpardessus.x = 100;
  positionpardessus.y = 400;

  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 17, 240, 200));
  SDL_FillRect(attaque,NULL,SDL_MapRGB(attaque->format, 255, 255, 255));

  SDL_BlitSurface(attaque,NULL,ecran,&positionattaque);
  SDL_BlitSurface(pardessus,NULL,ecran,&positionpardessus);
  SDL_BlitSurface(fond,NULL,ecran,&position);


  SDL_Flip(ecran);

  SDL_FreeSurface(attaque);
  SDL_FreeSurface(pardessus);



}
