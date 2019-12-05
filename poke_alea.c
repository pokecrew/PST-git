#include "include.h"

//SDL_Rect pos[4][4];
SDL_Surface *poke[4][4];

void poke_alea()
{
  pos_poke.x = 700;
  pos_poke.y = 55;

    srand(time(NULL));
  //  SDL_Surface *temp = NULL;
    int alea1 = 0, alea2 = 0;

    poke[0][0] = IMG_Load("sprites/poke/1.png");
    poke[0][1] = IMG_Load("sprites/poke/4.png");
    poke[0][2] = IMG_Load("sprites/poke/7.png");
    poke[0][3] = IMG_Load("sprites/poke/10.png");
    poke[1][0] = IMG_Load("sprites/poke/13.png");
    poke[1][1] = IMG_Load("sprites/poke/16.png");
    poke[1][2] = IMG_Load("sprites/poke/19.png");
    poke[1][3] = IMG_Load("sprites/poke/21.png");
    poke[2][0] = IMG_Load("sprites/poke/23.png");
    poke[2][1] = IMG_Load("sprites/poke/25.png");
    poke[2][2] = IMG_Load("sprites/poke/27.png");
    poke[2][3] = IMG_Load("sprites/poke/29.png");
    poke[3][0] = IMG_Load("sprites/poke/32.png");
    poke[3][1] = IMG_Load("sprites/poke/35.png");
    poke[3][2] = IMG_Load("sprites/poke/37.png");
    poke[3][3] = IMG_Load("sprites/poke/39.png");

    for(int i=0; i<100; i++)
    {
      for(int j=0; j<4; j++)
      {
        for(int k=0; k<4; k++)
        {
          alea1 = rand()%4;
          alea2 = rand()%4;

          	SDL_BlitSurface(poke[alea1][alea2], NULL, ecran, &pos_poke);
        //  temp = poke[j][k];
        //  poke[j][k] = poke[alea1][alea2];
        //  poke[alea1][alea2] = temp;

        }
      }
    }
}
