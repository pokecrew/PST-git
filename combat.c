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
=======
SDL_Surface *temp = NULL;
SDL_Surface *my_poke[6];

typedef struct Poke Poke;

struct Poke{
  char nom[25];
  int PV;
};

void combat(SDL_Surface *ecran)
{
	SDL_Surface *fond_combat = NULL, *attaque1 = NULL, *attaque2 = NULL, *rect = NULL, *texte_attaques = NULL, *texte_fuite = NULL, *texte_changer = NULL, *fond_noir = NULL;
	SDL_Event event;
	SDL_Rect pos_fond, pos_fond_noir, pos_attaque, pos_attaque2, pos_rect, pos_texte_attaques, pos_texte_fuite, pos_texte_changer, pos_pokemon, pos_mypoke;
	TTF_Font *police = NULL;
	SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {255, 27, 27};
	int continuer = 1, bouton = 1;
	int longueur = 125, hauteur = 20, longueur2 = 70, longueur3 = 105;
	int i;

	pos_mypoke.x = 280;
	pos_mypoke.y = 300;
	pos_fond.x = 244;
	pos_fond.y = 87;
	pos_fond_noir.x = 0;
	pos_fond_noir.y = 0;
	pos_attaque.x = 472;
	pos_attaque.y = 169;
	pos_rect.x = 709;
	pos_rect.y = 487;
	pos_texte_attaques.x = 734;
	pos_texte_attaques.y = 505;
	pos_texte_fuite.x = 734;
	pos_texte_fuite.y = 535;
	pos_texte_changer.x = 734;
	pos_texte_changer.y = 565;
	pos_pokemon.x = 4;
	pos_pokemon.y = 5;

	police = TTF_OpenFont("combat/king.ttf", 25);
	fond_combat = IMG_Load("combat/plateau_combat.png");
	fond_noir = SDL_CreateRGBSurface(SDL_HWSURFACE, 1280, 720, 32, 0, 0, 0, 0);
	rect = IMG_Load("combat/rect_attaque.png");
	texte_attaques = TTF_RenderText_Blended(police, "Attaques", couleurNoire);
	texte_fuite = TTF_RenderText_Blended(police, "Fuite", couleurNoire);
	texte_changer = TTF_RenderText_Blended(police, "Changer", couleurNoire);

	SDL_FillRect(fond_noir,NULL,SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(fond_noir,NULL,ecran,&pos_fond_noir);

	SDL_BlitSurface(fond_combat, NULL, ecran, &pos_fond);
	SDL_Flip(ecran);
	SDL_Delay(500);

	poke_alea(ecran);
	SDL_Flip(ecran);
	SDL_Delay(500);

	my_pokemons(ecran);
	SDL_BlitSurface(my_poke[0], NULL, ecran, &pos_mypoke);
	SDL_Flip(ecran);
	SDL_Delay(500);

	SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
	SDL_BlitSurface(texte_attaques, NULL, ecran, &pos_texte_attaques);
	SDL_BlitSurface(texte_fuite, NULL, ecran, &pos_texte_fuite);
	SDL_BlitSurface(texte_changer, NULL, ecran, &pos_texte_changer);
	SDL_Flip(ecran);

	while(continuer) //Boucle infini qui s'arrête lorsque continuer = 0
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT: //quitte le programme lorsque l'on appui sur la croix rouge
				continuer = 0;
			break;

			case SDL_KEYDOWN: //appuyer sur une touche du clavier
				switch (event.key.keysym.sym) //évènement concernant les touches du clavier
				{
					case SDLK_ESCAPE: // Appuyer sur échap pour retourner au menu
						menu(ecran);
						continuer = 0;
					break;
				}
			break;

			case SDL_MOUSEMOTION: //déplacement de la souris
				if(bouton)
				{
					if ((pos_texte_attaques.x <= event.button.x) && ((pos_texte_attaques.x + longueur) >= event.button.x) && (pos_texte_attaques.y <= event.button.y) && (pos_texte_attaques.y + hauteur >= event.button.y))
					{
						texte_attaques = TTF_RenderText_Blended(police, "Attaques", couleurRouge);
					}
					else
					{
						texte_attaques = TTF_RenderText_Blended(police, "Attaques", couleurNoire);
					}
					if ((pos_texte_fuite.x <= event.button.x) && ((pos_texte_fuite.x + longueur2) >= event.button.x) && (pos_texte_fuite.y <= event.button.y) && (pos_texte_fuite.y + hauteur >= event.button.y))
					{
						texte_fuite = TTF_RenderText_Blended(police, "Fuite", couleurRouge);
					}
					else
					{
						texte_fuite = TTF_RenderText_Blended(police, "Fuite", couleurNoire);
					}
					if ((pos_texte_changer.x <= event.button.x) && ((pos_texte_changer.x + longueur3) >= event.button.x) && (pos_texte_changer.y <= event.button.y) && (pos_texte_changer.y + hauteur >= event.button.y))
					{
						texte_changer = TTF_RenderText_Blended(police, "Changer", couleurRouge);
					}
					else
					{
						texte_changer = TTF_RenderText_Blended(police, "Changer", couleurNoire);
					}
					SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
					SDL_BlitSurface(texte_attaques, NULL, ecran, &pos_texte_attaques);
					SDL_BlitSurface(texte_fuite, NULL, ecran, &pos_texte_fuite);
					SDL_BlitSurface(texte_changer, NULL, ecran, &pos_texte_changer);
				}
			break;

			case SDL_MOUSEBUTTONDOWN: //clic gauche de la souris
				if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
				{
					if ((pos_texte_attaques.x <= event.button.x) && ((pos_texte_attaques.x + longueur) >= event.button.x) && (pos_texte_attaques.y <= event.button.y) && (pos_texte_attaques.y + hauteur >= event.button.y))
					{
						bouton = 0;
						SDL_BlitSurface(fond_combat, NULL, ecran, &pos_fond);
					}

					if ((pos_texte_fuite.x <= event.button.x) && ((pos_texte_fuite.x + longueur2) >= event.button.x) && (pos_texte_fuite.y <= event.button.y) && (pos_texte_fuite.y + hauteur >= event.button.y))
					{
						continuer = 0;
					}

					if ((pos_texte_changer.x <= event.button.x) && ((pos_texte_changer.x + longueur3) >= event.button.x) && (pos_texte_changer.y <= event.button.y) && (pos_texte_changer.y + hauteur >= event.button.y))
					{
						changer_poke(ecran);
						bouton = 0;
					}
				}
			break;
		}
			SDL_Flip(ecran);
	}

	SDL_FreeSurface(fond_combat);
	SDL_FreeSurface(fond_noir);
	SDL_FreeSurface(attaque1);
	SDL_FreeSurface(rect);
	SDL_FreeSurface(texte_attaques);
	SDL_FreeSurface(texte_fuite);
	SDL_FreeSurface(texte_changer);
	TTF_CloseFont(police);
}

SDL_Surface *poke[16];

void poke_alea(SDL_Surface *ecran)
{
	Poke pokemon[20];
	SDL_Surface *nom = NULL;
	SDL_Rect pos_poke, pos_nom;

	strcat(pokemon[0].nom,"BULBIZARRE");
	strcat(pokemon[1].nom,"SALAMECHE");
	strcat(pokemon[2].nom,"CARAPUCE");
	strcat(pokemon[3].nom,"CHENIPAN");
	strcat(pokemon[4].nom,"ASPICOT");
	strcat(pokemon[5].nom,"ROUCOOL");
	strcat(pokemon[6].nom,"RATATA");
	strcat(pokemon[7].nom,"PIAFABEC");
	strcat(pokemon[8].nom,"ABO");
	strcat(pokemon[9].nom,"PIKACHU");
	strcat(pokemon[10].nom,"SABELETE");
	strcat(pokemon[11].nom,"NIDORAN F");
	strcat(pokemon[12].nom,"NIDORAN M");
	strcat(pokemon[13].nom,"MELOFEE");
	strcat(pokemon[14].nom,"GOUPIX");
	strcat(pokemon[15].nom,"RONDOUDOU");
	//pokemon[0].nom = "BULBIZARRE";

	pos_nom.x =
	pos_nom.y =
	pos_poke.x = 700;
	pos_poke.y = 55;

    srand(time(NULL));
    int alea = 0;

    poke[0] = IMG_Load("sprites/poke/1.png");
    poke[1] = IMG_Load("sprites/poke/4.png");
    poke[2] = IMG_Load("sprites/poke/7.png");
    poke[3] = IMG_Load("sprites/poke/10.png");
    poke[4] = IMG_Load("sprites/poke/13.png");
    poke[5] = IMG_Load("sprites/poke/16.png");
    poke[6] = IMG_Load("sprites/poke/19.png");
    poke[7] = IMG_Load("sprites/poke/21.png");
    poke[8] = IMG_Load("sprites/poke/23.png");
    poke[9] = IMG_Load("sprites/poke/25.png");
    poke[10] = IMG_Load("sprites/poke/27.png");
    poke[11] = IMG_Load("sprites/poke/29.png");
    poke[12] = IMG_Load("sprites/poke/32.png");
    poke[13] = IMG_Load("sprites/poke/35.png");
    poke[14] = IMG_Load("sprites/poke/37.png");
    poke[15] = IMG_Load("sprites/poke/39.png");


          alea = rand()%16;
					temp = poke[alea];

					SDL_BlitSurface(poke[alea], NULL, ecran, &pos_poke);
}


void my_pokemons(SDL_Surface *ecran)
{
	my_poke[0] = IMG_Load("sprites/poke/dos/1.png");
	my_poke[1] = IMG_Load("sprites/poke/dos/4.png");
	my_poke[2] = IMG_Load("sprites/poke/dos/7.png");
	my_poke[3] = IMG_Load("sprites/poke/dos/10.png");
	my_poke[4] = IMG_Load("sprites/poke/dos/13.png");
	my_poke[5] = IMG_Load("sprites/poke/dos/16.png");
}

void changer_poke(SDL_Surface *ecran)
{
		SDL_Surface *changer = NULL;
		SDL_Rect pos_fond;

		pos_fond.x = 244;
		pos_fond.y = 87;
		changer = IMG_Load("combat/fond_combat.png");
		//SDL_FillRect(changer,NULL,SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(changer, NULL, ecran, &pos_fond);
		SDL_Flip(ecran);

}

