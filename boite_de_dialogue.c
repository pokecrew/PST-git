#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int main(){
  SDL_Surface *ecran = NULL, *personnage = NULL, *pnj = NULL, *dialogue = NULL, *erased = NULL;
  SDL_Surface *dialogue2 = NULL, *dialogue3 = NULL, *nom = NULL, *bulle = NULL, *nom2 = NULL, *erased_bulle = NULL;
  SDL_Rect position_personnage, position_pnj, position_bulle, position_dialogue;
  SDL_Rect position_nom, position_pnj2;
  SDL_Rect position_nom2;
  SDL_Event event;
  TTF_Font *police_dialogue = NULL, *police_nom = NULL;
  SDL_Color blanc = {255,255,255}, noir = {0, 0, 0};
  int boucle = 1;

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  ecran = SDL_SetVideoMode(1900, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
  SDL_WM_SetCaption("Tentative event pnj dialogue", NULL);

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 30, 30, 30));

  police_dialogue = TTF_OpenFont("bulle_dialogue_police.ttf", 25);
  police_nom = TTF_OpenFont("bulle_dialogue_police_nom.TTF", 20);
  dialogue = TTF_RenderText_Blended(police_dialogue, "Ceci est le dialogue unique", noir);
  dialogue2 = TTF_RenderText_Blended(police_dialogue, "Ceci est le dialogue phase 1", noir);
  dialogue3 = TTF_RenderText_Blended(police_dialogue, "Ceci est le dialogue phase 2", noir);
  nom = TTF_RenderText_Blended(police_nom, "BILLY", noir);
  nom2 = TTF_RenderText_Blended(police_nom, "BOBBY", noir);

  personnage = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(personnage, NULL, SDL_MapRGB(ecran->format, 200, 200, 200));

  erased = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(erased, NULL, SDL_MapRGB(ecran->format, 30, 30, 30));

  pnj = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(pnj, NULL, SDL_MapRGB(ecran->format, 255, 255, 0));

  bulle = IMG_Load("dialogue.png");

  erased_bulle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1200, 300, 32, 0, 0, 0, 0);
  SDL_FillRect(erased_bulle, NULL, SDL_MapRGB(ecran->format, 30, 30, 30));

  int tour = 0;
  int pause_mvt = 0;

  position_personnage.x = ecran->w / 4;
  position_personnage.y = ecran->h / 2;

  position_pnj.x = (ecran->w / 4)*3;
  position_pnj.y = 100;

  position_pnj2.x = ecran->w / 4;
  position_pnj2.y = (ecran->h / 4)*3;

  position_bulle.x = (ecran -> w)/2 - (bulle -> w)/2;
  position_bulle.y = ecran->h - bulle -> h;

  position_dialogue.x = position_bulle.x + 95;
  position_dialogue.y = position_bulle.y + 110;

  position_nom.x = position_bulle.x + 115;
  position_nom.y = position_bulle.y + 50;

  SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj);
  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj2);
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
            if(pause_mvt == 1)
            {
              break;
            }
            if((position_personnage.x + 50 == position_pnj.x) && (position_personnage.y == position_pnj.y))
            {
              break;
            }
            if((position_personnage.x + 50 == position_pnj2.x) && (position_personnage.y == position_pnj2.y))
            {
              break;
            }
            else
            {
              SDL_BlitSurface(erased, NULL, ecran, &position_personnage);
              position_personnage.x += 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_LEFT:
            if(pause_mvt == 1)
            {
              break;
            }
            if((position_personnage.x - 50 == position_pnj.x) && (position_personnage.y == position_pnj.y))
            {
              break;
            }
            if((position_personnage.x - 50 == position_pnj2.x) && (position_personnage.y == position_pnj2.y))
            {
              break;
            }
            else
            {
              SDL_BlitSurface(erased, NULL, ecran, &position_personnage);
              position_personnage.x -= 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_UP:
            if(pause_mvt == 1)
            {
              break;
            }
            if((position_personnage.y - 50 == position_pnj.y) && (position_personnage.x == position_pnj.x))
            {
              break;
            }
            if((position_personnage.y - 50 == position_pnj2.y) && (position_personnage.x == position_pnj2.x))
            {
              break;
            }
            else
            {
              SDL_BlitSurface(erased, NULL, ecran, &position_personnage);
              position_personnage.y -= 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_DOWN:
            if(pause_mvt == 1)
            {
              break;
            }
            if((position_personnage.y + 50 == position_pnj.y) && (position_personnage.x == position_pnj.x))
            {
              break;
            }
            if((position_personnage.y + 50 == position_pnj2.y) && (position_personnage.x == position_pnj2.x))
            {
              break;
            }
            else
            {
              SDL_BlitSurface(erased, NULL, ecran, &position_personnage);
              position_personnage.y += 50;
              SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
              SDL_Flip(ecran);
            }
            break;
          case SDLK_RETURN:
            if(((position_personnage.x == position_pnj.x + 50) || (position_personnage.x == position_pnj.x - 50) || (position_personnage.y == position_pnj.y + 50) || (position_personnage.y == position_pnj.y - 50)) && ((position_personnage.x == position_pnj.x) || (position_personnage.y == position_pnj.y)))
            {
              if(pause_mvt == 1)
              {
                pause_mvt = 0;
                SDL_BlitSurface(erased_bulle, NULL, ecran, &position_bulle);
                SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
                SDL_BlitSurface(pnj, NULL, ecran, &position_pnj);
                SDL_BlitSurface(pnj, NULL, ecran, &position_pnj2);
                SDL_Flip(ecran);
                position_bulle.y = ecran->h - bulle -> h;
                position_dialogue.y = position_bulle.y + 110;
                position_nom.y = position_bulle.y + 50;
                break;
              }
              else
              {
                pause_mvt = 1;
                if(position_bulle.y + 50 <= position_personnage.y)
                {
                  position_bulle.y -= 700;
                }
                position_dialogue.y = position_bulle.y + 110;
                position_nom.y = position_bulle.y + 50;
                SDL_BlitSurface(bulle, NULL, ecran, &position_bulle);
                SDL_BlitSurface(dialogue, NULL, ecran, &position_dialogue);
                SDL_BlitSurface(nom, NULL, ecran, &position_nom);
                SDL_Flip(ecran);
                break;
              }
            }
            else if(((position_personnage.x == position_pnj2.x + 50) || (position_personnage.x == position_pnj2.x - 50) || (position_personnage.y == position_pnj2.y + 50) || (position_personnage.y == position_pnj2.y - 50)) && ((position_personnage.x == position_pnj2.x) || (position_personnage.y == position_pnj2.y)))
            {
              if(tour == 0)
              {
                if(pause_mvt == 1)
                {
                  pause_mvt = 0;
                  SDL_BlitSurface(erased_bulle, NULL, ecran, &position_bulle);
                  SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
                  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj);
                  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj2);
                  SDL_Flip(ecran);
                  position_bulle.y = ecran->h - bulle -> h;
                  position_dialogue.y = position_bulle.y + 110;
                  position_nom.y = position_bulle.y + 50;
                  tour += 1;
                  break;
                }
                else
                {
                  pause_mvt = 1;
                  if(position_bulle.y + 50 <= position_personnage.y)
                  {
                    position_bulle.y -= 700;
                  }
                  position_dialogue.y = position_bulle.y + 110;
                  position_nom.y = position_bulle.y + 50;
                  SDL_BlitSurface(bulle, NULL, ecran, &position_bulle);
                  SDL_BlitSurface(dialogue2, NULL, ecran, &position_dialogue);
                  SDL_BlitSurface(nom2, NULL, ecran, &position_nom);
                  SDL_Flip(ecran);
                  break;
                }
              }
              else
              {
                if(pause_mvt == 1)
                {
                  pause_mvt = 0;
                  SDL_BlitSurface(erased_bulle, NULL, ecran, &position_bulle);
                  SDL_BlitSurface(personnage, NULL, ecran, &position_personnage);
                  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj);
                  SDL_BlitSurface(pnj, NULL, ecran, &position_pnj2);
                  SDL_Flip(ecran);
                  position_bulle.y = ecran->h - bulle -> h;
                  position_dialogue.y = position_bulle.y + 110;
                  position_nom.y = position_bulle.y + 50;
                  tour = 0;
                  break;
                }
                else
                {
                  pause_mvt = 1;
                  if(position_bulle.y + 50 <= position_personnage.y)
                  {
                    position_bulle.y -= 700;
                  }
                  position_dialogue.y = position_bulle.y + 110;
                  position_nom.y = position_bulle.y + 50;
                  SDL_BlitSurface(bulle, NULL, ecran, &position_bulle);
                  SDL_BlitSurface(dialogue3, NULL, ecran, &position_dialogue);
                  SDL_BlitSurface(nom2, NULL, ecran, &position_nom);
                  SDL_Flip(ecran);
                  break;
                }
              }
            }
            break;
        }
    }
  }
  SDL_FreeSurface(personnage);
  SDL_FreeSurface(pnj);
  SDL_FreeSurface(ecran);
  SDL_FreeSurface(dialogue);
  SDL_FreeSurface(dialogue2);
  SDL_FreeSurface(dialogue3);
  SDL_FreeSurface(bulle);
  SDL_FreeSurface(nom);
  SDL_FreeSurface(nom2);
  SDL_Quit();

  return EXIT_SUCCESS;
}
