#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int main(){
  SDL_Surface *ecran = NULL, *personnage = NULL, *pnj = NULL, *dialogue = NULL, *nom = NULL, *bulle = NULL;
  SDL_Rect position_personnage, position_pnj, position_bulle, position_dialogue, position_nom;
  SDL_Event event;
  TTF_Font *police_dialogue = NULL, *police_nom = NULL;
  SDL_Color blanc = {255,255,255}, noir = {0, 0, 0};
  int boucle = 1;

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  ecran = SDL_SetVideoMode(1900, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
  SDL_WM_SetCaption("Tentative event pnj dialogue", NULL);

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 30, 30, 30));

  police_dialogue = TTF_OpenFont("bulle_dialogue_police.ttf", 30);
  police_nom = TTF_OpenFont("bulle_dialogue_police_nom.TTF", 20);
  dialogue = TTF_RenderText_Blended(police_dialogue, "Ceci est le dialogue", blanc);
  nom = TTF_RenderText_Blended(police_nom, "Billy", blanc);

  personnage = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(personnage, NULL, SDL_MapRGB(ecran->format, 200, 200, 200));

  pnj = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(pnj, NULL, SDL_MapRGB(ecran->format, 255, 255, 0));

  bulle = IMG_Load("bulle_dialogue.png");
  //SDL_SetColorKey(dialogue, SDL_SRCCOLORKEY, SDL_MapRGB(dialogue->format, 0, 255, 0));

  position_personnage.x = ecran->w / 4;
  position_personnage.y = ecran->h / 2;

  position_pnj.x = (ecran->w / 4)*3;
  position_pnj.y = ecran->h / 2;

  position_bulle.x = position_pnj.x - 20;
  position_bulle.y = position_pnj.y - 300;

  position_dialogue.x = position_bulle.x + 45;
  position_dialogue.y = position_bulle.y + 80;

  position_nom.x = position_bulle.x + 65;
  position_nom.y = position_bulle.y + 20;

  SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj);
  SDL_Flip(ecran);

  SDL_EnableKeyRepeat(50,100);

  printf("tout est bon\n");

  while(boucle == 1)
  {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
        boucle = 0;
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            boucle = 0;
            break;
          case SDLK_RIGHT:
            if((position_personnage.x + 50 == position_pnj.x) && (position_personnage.y == position_pnj.y)){
              break;
            }else{
              position_personnage.x += 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_LEFT:
            if((position_personnage.x - 50 == position_pnj.x) && (position_personnage.y == position_pnj.y)){
              break;
            }else{
              position_personnage.x -= 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_UP:
            if((position_personnage.y - 50 == position_pnj.y) && (position_personnage.x == position_pnj.x)){
              break;
            }else{
              position_personnage.y -= 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_DOWN:
            if((position_personnage.y + 50 == position_pnj.y) && (position_personnage.x == position_pnj.x)){
              break;
            }else{
              position_personnage.y += 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_RETURN:
            if((position_personnage.x != position_pnj.x) && (position_personnage.y != position_pnj.y))
            {
              break;
            }
            else if((position_personnage.x == position_pnj.x + 50) || (position_personnage.x == position_pnj.x - 50) || (position_personnage.y == position_pnj.y + 50) || (position_personnage.y == position_pnj.y - 50))
            {
              SDL_BlitSurface(bulle, NULL, ecran, &position_bulle);
              SDL_BlitSurface(dialogue, NULL, ecran, &position_dialogue);
              SDL_BlitSurface(nom, NULL, ecran, &position_nom);
              SDL_Flip(ecran);
              printf("YO c'est la boite de dialogue\n");
            }
        }
        break;
    }
  }

  SDL_FreeSurface(personnage);
  SDL_FreeSurface(pnj);
  SDL_FreeSurface(ecran);
  SDL_FreeSurface(dialogue);
  SDL_FreeSurface(bulle);
  SDL_FreeSurface(nom);
  SDL_Quit();

  return EXIT_SUCCESS;
}
