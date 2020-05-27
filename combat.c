#include "include.h"

SDL_Surface *my_poke[6];
SDL_Surface *nom1 = NULL;
int lire_sauvegarde(Poke *poke){
	FILE *fic1 = NULL;
	fic1 = fopen("Ressources/Sauvegarde","r");
	char TAB[170];
	fgets(TAB, 169, fic1);
	fgets(TAB, 169, fic1);
	printf(" ca marche ? \n");
	poke ->id = (TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
	printf("%d\n",poke->id);
	poke->PV =	(TAB[8]-'0')*100 + (TAB[9]-'0')*10 + TAB[10]-'0';
	poke->niv = (TAB[16]-'0')*100 + (TAB[17]-'0')*10 + TAB[18]-'0';
	printf("%d\n",poke->niv);
	poke->exp = (TAB[24]-'0')*1000000 + (TAB[25]-'0')*100000 + (TAB[26]-'0')*10000 + (TAB[27]-'0')*1000 + (TAB[28]-'0')*100 + (TAB[29]-'0')*10 + (TAB[30]-'0');
	printf("%d\n",poke->exp);
	fclose(fic1);
}
int calcul_stat(Poke *poke)
{
	printf(GREEN"[calcul_stat]:"RESET"Id :%d\n",poke->id);
	FILE *fic = NULL;
	fic = fopen("Ressources/Stat_poke","r");
	char TAB[170];
	fgets(TAB, 169, fic);
	int id_f = 0;
	while(id_f != poke->id)
	{
		fgets(TAB, 119, fic);
		id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
	}
	for(int i=0; i<15;i++){
		if(TAB[i+16] == ' '){
			printf("Espace \n");
			poke->nom[i]='\0';
			i = 15 ;
		}
		else{
			poke->nom[i]=TAB[i+16];
		}
	}
	printf(GREEN"[calcul_stat]:"RESET"Nom :%s\n",poke->nom);
	// charger les stats de base
	poke->PV =	(TAB[32]-'0')*100 + (TAB[33]-'0')*10 + TAB[34]-'0';
//	printf("%d\n",poke->PV);
	poke ->PV = ((2*poke->PV+31)*poke->niv)/100+poke->niv+10;
	  printf(GREEN"[calcul_stat]:"RESET"Pv :%d\n",poke->PV);
	poke->att =	(TAB[40]-'0')*100 + (TAB[41]-'0')*10 + TAB[42]-'0';
//	printf("%d\n",poke->att);
	poke ->att = ((2*poke->att+31)*poke->niv)/100+5;
		printf(GREEN"[calcul_stat]:"RESET"att :%d\n",poke->att);
	poke->def =	(TAB[48]-'0')*100 + (TAB[49]-'0')*10 + TAB[50]-'0';
	//printf("%d\n",poke -> def);
	poke->def = ((2*poke->def+31)*poke->niv)/100+5;
		printf(GREEN"[calcul_stat]:"RESET"def :%d\n",poke->def);
	poke->vit =	(TAB[72]-'0')*100 + (TAB[73]-'0')*10 + TAB[74]-'0';
	//	printf("%d\n",poke ->vit);
	poke ->vit = ((2*poke->vit+31)*poke->niv)/100+5;
		printf(GREEN"[calcul_stat]:"RESET"vit :%d\n",poke->vit);
	poke->nivEvo = (TAB[87]-'0')*100 + (TAB[88]-'0')*10 + TAB[89]-'0';
		printf("Niveau évolution du poke %d : %d\n",poke->id ,poke->nivEvo);

	fclose(fic);
}

void affichage_combat(SDL_Surface *ecran)
{
	SDL_Surface *fond_combat = NULL, *fond_noir = NULL;
	SDL_Surface *poke = NULL;
	SDL_Surface *nom2 = NULL;
	SDL_Rect pos_fond, pos_fond_noir, pos_mypoke, pos_nom;
	Poke pokemon[20] = {"", 0};
	TTF_Font *police = NULL;
	SDL_Color couleurNoire = {0, 0, 0};

	police = TTF_OpenFont("combat/king.ttf", 25);

	pos_fond.x = 244;
	pos_fond.y = 87;

	pos_fond_noir.x = 0;
	pos_fond_noir.y = 0;

	pos_mypoke.x = 280;
	pos_mypoke.y = 300;

	pos_nom.x = 725;
  pos_nom.y = 400;


	char path[30];
	sprintf(path, "sprites/poke/dos/%d.png", poke1.id);
	my_poke[0] = IMG_Load(path);

	fond_combat = IMG_Load("combat/plateau_combat.png");
	fond_noir = SDL_CreateRGBSurface(SDL_HWSURFACE, 1280, 720, 32, 0, 0, 0, 0);
	SDL_FillRect(fond_noir,NULL,SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(fond_noir,NULL,ecran,&pos_fond_noir);
	SDL_BlitSurface(fond_combat, NULL, ecran, &pos_fond);
	SDL_BlitSurface(my_poke[0], NULL, ecran, &pos_mypoke);//affiche notre pokemon
	nom2 = TTF_RenderText_Blended(police, poke1.nom, couleurNoire);
  SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
	SDL_Flip(ecran);

	poke_alea(ecran, poke, pokemon);
	//combat(ecran);

	SDL_FreeSurface(fond_combat);
	SDL_FreeSurface(fond_noir);
}

void combat(SDL_Surface *ecran)
{
	SDL_Surface *rect = NULL, *texte_attaques = NULL, *texte_fuite = NULL, *texte_changer = NULL, *texte_attaque1 = NULL, *pv = NULL, *rect_pv = NULL, *pv_2= NULL, *texte_attaque2 = NULL, *texte_attaque3 = NULL, *texte_attaque4 = NULL, *texte_niveau_poke1 = NULL, *texte_niveau_poke2 = NULL, *texte_capture = NULL;
  SDL_Surface *poke[16];
  Poke pokemon[20] = {"", 0};
	SDL_Event event;
	SDL_Rect pos_rect, pos_texte_attaques, pos_texte_fuite, pos_texte_changer, pos_pokemon, pos_nom, pos_pv,pos_rect_pv, pos_pv_2,pos_rect_pv_2,pos_texte_attaque1,pos_texte_attaque2,pos_texte_attaque3,pos_texte_attaque4,pos_texte_niveau_poke1,pos_texte_niveau_poke2, pos_texte_capture;
	TTF_Font *police = NULL;
	TTF_Font *police2 = NULL;
	SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {255, 27, 27};
	int continuer = 1, bouton = 1, attaque = 0;
	int longueur = 125, hauteur = 20, longueur2 = 70, longueur3 = 105, longueur4 = 85;
	int i;
  int joueur = 0;
	int derouler_combat = 0;

	//initialisation COMBAT
	//Tirage niveau pokemon adversaire
	int signe = rand()%2;
	if (signe%2==0){
		poke2.niv= poke1.niv - rand()%4;
	}
	else poke2.niv = poke1.niv + rand()%4;

	//Tirage au sort pokemon adversaire
	tirage_poke_sauvage(poke1.niv);

	//affichage_Fond
	affichage_combat(ecran);


	char capture_texte[150];
	sprintf(capture_texte,"La violence animale est interdite sauf sur ptitard");

	char texte_remplacer[150];



	char niveau_poke1[10];
	char niveau_poke2[10];
	//on remplit les tableaux
	sprintf(niveau_poke1,"niv : %d ",poke1.niv);
	sprintf(niveau_poke2,"niv : %d ",poke2.niv);
	int attaques2[4];
	selection_att_adv(&poke2);
	printf("il a chargé : %s, %s, %s, %s \n", poke2.attaque[0].nom, poke2.attaque[1].nom, poke2.attaque[2].nom, poke2.attaque[3].nom);
	printf("il a chargé : %d, %d, %d, %d \n", poke2.attaque[0].id, poke2.attaque[1].id, poke2.attaque[2].id, poke2.attaque[3].id);
	char TAB[100];
  char TAB1[100];
	//printf("pv du pokemon 1 : %d\n",poke1.PV);
	//printf("pv du pokemon 2 : %d\n",poke2.PV);
  sprintf(TAB,"pv : %d ",poke1.PV);
  sprintf(TAB1,"pv : %d",poke2.PV);


	pos_rect.x = 709;
	pos_rect.y = 487;
	pos_texte_attaques.x = 734;
	pos_texte_attaques.y = 505;
	pos_texte_fuite.x = 864;
	pos_texte_fuite.y = 505;
	pos_texte_changer.x = 734;
	pos_texte_changer.y = 565;
	pos_texte_capture.x = 864;
	pos_texte_capture.y = 565;
	pos_pokemon.x = 4;
	pos_pokemon.y = 5;

  pos_pv.x = 730;
  pos_pv.y = 437;

  pos_rect_pv.x = 715;
  pos_rect_pv.y = 427;

  pos_pv_2.x = 340;
  pos_pv_2.y = 185;

  pos_rect_pv_2.x = 321;
  pos_rect_pv_2.y = 177;

	pos_texte_attaque1.x = pos_texte_attaque3.x = 720;
	pos_texte_attaque1.y = pos_texte_attaque2.y = 510;
	pos_texte_attaque2.x = pos_texte_attaque4.x = 870;
	pos_texte_attaque3.y = pos_texte_attaque4.y = 560;

	pos_texte_niveau_poke1.x = 900;
	pos_texte_niveau_poke1.y = 408;

	pos_texte_niveau_poke2.x = 503;
	pos_texte_niveau_poke2.y = 155;

	police = TTF_OpenFont("combat/king.ttf", 25);
	police2 = TTF_OpenFont("combat/king.ttf",17);
	rect = IMG_Load("combat/rect_attaque.png");
  rect_pv = IMG_Load("combat/carre_blanc.png");
	texte_attaques = TTF_RenderText_Blended(police, "Attaques", couleurNoire);
	texte_fuite = TTF_RenderText_Blended(police, "Fuite", couleurNoire);
	texte_changer = TTF_RenderText_Blended(police, "Changer", couleurNoire);
	texte_capture = TTF_RenderText_Blended(police, "Capture", couleurNoire);
  texte_attaque1= TTF_RenderText_Blended(police2, poke1.attaque[0].nom, couleurNoire);
	texte_attaque2= TTF_RenderText_Blended(police2, poke1.attaque[1].nom, couleurNoire);
	texte_attaque3= TTF_RenderText_Blended(police2, poke1.attaque[2].nom, couleurNoire);
	texte_attaque4= TTF_RenderText_Blended(police2, poke1.attaque[3].nom, couleurNoire);
	texte_niveau_poke1 = TTF_RenderText_Blended(police2,niveau_poke1, couleurNoire);
	texte_niveau_poke2 = TTF_RenderText_Blended(police2, niveau_poke2 , couleurNoire);
  pv = TTF_RenderText_Blended(police,TAB, couleurNoire);
  pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);

  SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
  SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv_2);
	SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
	SDL_BlitSurface(texte_attaques, NULL, ecran, &pos_texte_attaques);
	SDL_BlitSurface(texte_fuite, NULL, ecran, &pos_texte_fuite);
	SDL_BlitSurface(texte_changer, NULL, ecran, &pos_texte_changer);
	SDL_BlitSurface(texte_capture, NULL, ecran, &pos_texte_capture);
  SDL_BlitSurface(pv, NULL, ecran, &pos_pv);
  SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
	SDL_BlitSurface(texte_niveau_poke1, NULL, ecran, &pos_texte_niveau_poke1);
  SDL_BlitSurface(texte_niveau_poke2, NULL, ecran , &pos_texte_niveau_poke2);
	SDL_Flip(ecran);
	while(continuer) //Boucle infini qui s'arrête lorsque continuer = 0
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT: //quitte le programme lorsque l'on appui sur la croix rouge
        menu(ecran);
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
					if ((pos_texte_capture.x <= event.button.x) && ((pos_texte_capture.x + longueur3) >= event.button.x) && (pos_texte_capture.y <= event.button.y) && (pos_texte_capture.y + hauteur >= event.button.y))
					{
						texte_capture = TTF_RenderText_Blended(police, "Capture", couleurRouge);
					}
					else
					{
						texte_capture = TTF_RenderText_Blended(police, "Capture", couleurNoire);
					}
					SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
					SDL_BlitSurface(texte_attaques, NULL, ecran, &pos_texte_attaques);
					SDL_BlitSurface(texte_fuite, NULL, ecran, &pos_texte_fuite);
					SDL_BlitSurface(texte_changer, NULL, ecran, &pos_texte_changer);
					SDL_BlitSurface(texte_capture, NULL, ecran, &pos_texte_capture);
				}
				break;

			case SDL_MOUSEBUTTONDOWN: //clic gauche de la souris
				if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
				{
          if(bouton)
          {
            if ((pos_texte_attaques.x <= event.button.x) && ((pos_texte_attaques.x + longueur) >= event.button.x) && (pos_texte_attaques.y <= event.button.y) && (pos_texte_attaques.y + hauteur >= event.button.y))
					  {

              SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
              SDL_BlitSurface(texte_attaque1, NULL, ecran, &pos_texte_attaque1);
							SDL_BlitSurface(texte_attaque2, NULL, ecran, &pos_texte_attaque2);
							SDL_BlitSurface(texte_attaque3, NULL, ecran, &pos_texte_attaque3);
							SDL_BlitSurface(texte_attaque4, NULL, ecran, &pos_texte_attaque4);
              bouton = 0;
              attaque = 1;

					  }

					  if ((pos_texte_fuite.x <= event.button.x) && ((pos_texte_fuite.x + longueur2) >= event.button.x) && (pos_texte_fuite.y <= event.button.y) && (pos_texte_fuite.y + hauteur >= event.button.y))
					  {
					    continuer = 0;
					  }

					  if ((pos_texte_changer.x <= event.button.x) && ((pos_texte_changer.x + longueur3) >= event.button.x) && (pos_texte_changer.y <= event.button.y) && (pos_texte_changer.y + hauteur >= event.button.y))
					  {
						  bouton = 0;
              changer_poke(ecran);
					  }
						if ((pos_texte_capture.x <= event.button.x) && ((pos_texte_capture.x + longueur3) >= event.button.x) && (pos_texte_capture.y <= event.button.y) && (pos_texte_capture.y + hauteur >= event.button.y))
					  {
						  bouton = 1;
							dialogue_affichage(ecran,capture_texte,capture_texte,capture_texte);
							affichage_combat(ecran);
							sprintf(TAB,"pv : %d ",poke1.PV);
							sprintf(TAB1,"pv : %d ",poke2.PV);
							SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
						  SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv_2);
							SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
							SDL_BlitSurface(texte_attaques, NULL, ecran, &pos_texte_attaques);
							SDL_BlitSurface(texte_fuite, NULL, ecran, &pos_texte_fuite);
							SDL_BlitSurface(texte_changer, NULL, ecran, &pos_texte_changer);
							SDL_BlitSurface(texte_capture, NULL, ecran, &pos_texte_capture);
						  SDL_BlitSurface(pv, NULL, ecran, &pos_pv);
						  SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
							SDL_BlitSurface(texte_niveau_poke1, NULL, ecran, &pos_texte_niveau_poke1);
						  SDL_BlitSurface(texte_niveau_poke2, NULL, ecran , &pos_texte_niveau_poke2);

					  }
          }
          else if(attaque)
          {
            printf("Lancement Attaques \n");
            if ((pos_texte_attaque1.x <= event.button.x) && ((pos_texte_attaque1.x + longueur4) >= event.button.x) && (pos_texte_attaque1.y <= event.button.y) && (pos_texte_attaque1.y + hauteur >= event.button.y))
            {
              printf(" lancement attaque1 \n");
							sprintf(texte_remplacer,"%s utilise %s",poke1.nom,poke1.attaque[0].nom);
							dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
              joueur = deroulement(ecran, joueur,poke1.attaque[0].puissance);
							sprintf(TAB1,"pv : %d ",poke2.PV);
							pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);
							SDL_BlitSurface(rect_pv, NULL, ecran,&pos_rect_pv_2);
							SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
							SDL_Delay(1000);
							derouler_combat = 1;
						}
						else if ((pos_texte_attaque2.x <= event.button.x) && ((pos_texte_attaque2.x + longueur4) >= event.button.x) && (pos_texte_attaque2.y <= event.button.y) && (pos_texte_attaque2.y + hauteur >= event.button.y))
						{
							printf(" lancement attaque2 \n");
							sprintf(texte_remplacer,"%s utilise %s",poke1.nom,poke1.attaque[1].nom);
							dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
							joueur = deroulement(ecran, joueur,poke1.attaque[1].puissance);
							sprintf(TAB1,"pv : %d ",poke2.PV);
							pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);
							SDL_BlitSurface(rect_pv, NULL, ecran,&pos_rect_pv_2);
							SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
							SDL_Delay(1000);
							derouler_combat = 1;
						}
						 else if ((pos_texte_attaque3.x <= event.button.x) && ((pos_texte_attaque3.x + longueur4) >= event.button.x) && (pos_texte_attaque3.y <= event.button.y) && (pos_texte_attaque3.y + hauteur >= event.button.y))
						{
							printf(" lancement attaque3 \n");
							sprintf(texte_remplacer,"%s utilise %s",poke1.nom,poke1.attaque[2].nom);
							dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
							joueur = deroulement(ecran, joueur,poke1.attaque[2].puissance);
							sprintf(TAB1,"pv : %d ",poke2.PV);
							pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);
							SDL_BlitSurface(rect_pv, NULL, ecran,&pos_rect_pv_2);
							SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
							SDL_Delay(1000);
							derouler_combat = 1;
						}
						else if ((pos_texte_attaque4.x <= event.button.x) && ((pos_texte_attaque4.x + longueur4) >= event.button.x) && (pos_texte_attaque4.y <= event.button.y) && (pos_texte_attaque4.y + hauteur >= event.button.y))
						{
							printf(" lancement attaque4 \n");
							sprintf(texte_remplacer,"%s utilise %s",poke1.nom,poke1.attaque[3].nom);
							dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
							joueur = deroulement(ecran, joueur,poke1.attaque[3].puissance);
							sprintf(TAB1,"pv : %d ",poke2.PV);
							pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);
							SDL_BlitSurface(rect_pv, NULL, ecran,&pos_rect_pv_2);
							SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
							SDL_Delay(1000);
							derouler_combat = 1;
						}

						if(derouler_combat  == 1){
							if(poke2.PV <= 0)
							{
								sprintf(texte_remplacer,"%s est K.O, %s a gagne %d exp",poke2.nom,poke1.nom,calcul_exp_gagne(poke2));
								dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
								SDL_Delay(1000);
								ajout_exp(calcul_exp_gagne(poke2), ecran);
								continuer = 0;
							}
							else{ //poke2.Pv > 0
								SDL_Flip(ecran);
								SDL_Delay(1000);
								// tour atomatique pour le pokemon sauvage
								joueur = deroulement(ecran, joueur,poke1.attaque[1].puissance);
								affichage_combat(ecran);
								sprintf(TAB,"pv : %d ",poke1.PV);
              	sprintf(TAB1,"pv : %d ",poke2.PV);
								pv = TTF_RenderText_Blended(police,TAB, couleurNoire);
              	pv_2 = TTF_RenderText_Blended(police,TAB1, couleurNoire);
              	SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
              	SDL_BlitSurface(rect_pv, NULL, ecran,&pos_rect_pv_2);
              	SDL_BlitSurface(pv, NULL, ecran,&pos_pv);
              	SDL_BlitSurface(pv_2, NULL, ecran , &pos_pv_2);
								if(poke1.PV <= 0)
								{
									sprintf(texte_remplacer,"%s est K.O par votre faute allez le soigner",poke1.nom);
									dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
									SDL_Delay(1000);
									continuer = 0;
								}
							}
							derouler_combat = 0;
						}
            attaque = 0;
            bouton=1;
          }
			  }
				break;
		}
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(texte_niveau_poke1);
	SDL_FreeSurface(texte_niveau_poke2);
  SDL_FreeSurface(rect);
  SDL_FreeSurface(texte_attaques);
  SDL_FreeSurface(texte_fuite);
	SDL_FreeSurface(texte_changer);
	SDL_FreeSurface(texte_capture);
  SDL_FreeSurface(texte_attaque1);
	SDL_FreeSurface(texte_attaque2);
	SDL_FreeSurface(texte_attaque3);
	SDL_FreeSurface(texte_attaque4);
	SDL_FreeSurface(pv);
	SDL_FreeSurface(pv_2);
	SDL_FreeSurface(rect_pv);
	TTF_CloseFont(police);
	TTF_CloseFont(police2);
}

void my_pokemons()
{
	//Ancienne fonction CamCam (dsl m'en veux pas)
	/*
	my_poke[0] = IMG_Load("sprites/poke/dos/01.png");
	my_poke[1] = IMG_Load("sprites/poke/dos/04.png");
	my_poke[2] = IMG_Load("sprites/poke/dos/07.png");
	my_poke[3] = IMG_Load("sprites/poke/dos/10.png");
	my_poke[4] = IMG_Load("sprites/poke/dos/13.png");
	my_poke[5] = IMG_Load("sprites/poke/dos/16.png");
	*/

}

void poke_nom(Poke pokemon[20])
{
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
  strcat(pokemon[10].nom,"SABELETTE");
  strcat(pokemon[11].nom,"NIDORAN F");
  strcat(pokemon[12].nom,"NIDORAN M");
  strcat(pokemon[13].nom,"MELOFEE");
  strcat(pokemon[14].nom,"GOUPIX");
  strcat(pokemon[15].nom,"RONDOUDOU");
}

void poke_alea(SDL_Surface *ecran, SDL_Surface *poke, Poke pokemon[20])
{
	SDL_Rect pos_poke, pos_nom;
	SDL_Color couleurNoire = {0, 0, 0};
	TTF_Font *police = NULL;

	police = TTF_OpenFont("combat/king.ttf", 25);
	pos_nom.x = 330;
	pos_nom.y = 150;
	pos_poke.x = 700;
	pos_poke.y = 55;

	srand(time(NULL));
	int alea = 0;
	alea = rand()%16;

	//sauvage(poke);
	char path[30];
	sprintf(path,"sprites/poke/%d.png",poke2.id);
	poke = IMG_Load(path);
	nom1 = TTF_RenderText_Blended(police, poke2.nom, couleurNoire);

	SDL_BlitSurface(nom1, NULL, ecran, &pos_nom);
	SDL_BlitSurface(poke, NULL, ecran, &pos_poke);

	SDL_FreeSurface(nom1);
	TTF_CloseFont(police);
}

void sauvage(SDL_Surface *poke[50])
{
  poke[0] = IMG_Load("sprites/poke/01.png");
  poke[1] = IMG_Load("sprites/poke/02.png");
  poke[2] = IMG_Load("sprites/poke/03.png");
  poke[3] = IMG_Load("sprites/poke/04.png");
  poke[4] = IMG_Load("sprites/poke/05.png");
  poke[5] = IMG_Load("sprites/poke/06.png");
  poke[6] = IMG_Load("sprites/poke/07.png");
  poke[7] = IMG_Load("sprites/poke/08.png");
  poke[8] = IMG_Load("sprites/poke/09.png");
  poke[9] = IMG_Load("sprites/poke/10.png");
  poke[10] = IMG_Load("sprites/poke/11.png");
  poke[11] = IMG_Load("sprites/poke/12.png");
  poke[12] = IMG_Load("sprites/poke/13.png");
  poke[13] = IMG_Load("sprites/poke/14.png");
  poke[14] = IMG_Load("sprites/poke/15.png");
  poke[15] = IMG_Load("sprites/poke/16.png");
	poke[16] = IMG_Load("sprites/poke/17.png");
  poke[17] = IMG_Load("sprites/poke/18.png");
  poke[18] = IMG_Load("sprites/poke/19.png");
  poke[19] = IMG_Load("sprites/poke/20.png");
  poke[20] = IMG_Load("sprites/poke/21.png");
  poke[21] = IMG_Load("sprites/poke/22.png");
  poke[22] = IMG_Load("sprites/poke/23.png");
  poke[23] = IMG_Load("sprites/poke/24.png");
  poke[24] = IMG_Load("sprites/poke/25.png");
  poke[25] = IMG_Load("sprites/poke/26.png");
  poke[26] = IMG_Load("sprites/poke/27.png");
  poke[27] = IMG_Load("sprites/poke/28.png");
  poke[28] = IMG_Load("sprites/poke/29.png");
  poke[29] = IMG_Load("sprites/poke/30.png");
  poke[30] = IMG_Load("sprites/poke/31.png");
  poke[31] = IMG_Load("sprites/poke/32.png");
	poke[32] = IMG_Load("sprites/poke/33.png");
  poke[33] = IMG_Load("sprites/poke/34.png");
  poke[34] = IMG_Load("sprites/poke/35.png");
  poke[35] = IMG_Load("sprites/poke/36.png");
  poke[36] = IMG_Load("sprites/poke/37.png");
  poke[37] = IMG_Load("sprites/poke/38.png");
  poke[38] = IMG_Load("sprites/poke/39.png");
  poke[39] = IMG_Load("sprites/poke/40.png");
  poke[40] = IMG_Load("sprites/poke/41.png");
  poke[41] = IMG_Load("sprites/poke/42.png");
  poke[42] = IMG_Load("sprites/poke/43.png");
  poke[43] = IMG_Load("sprites/poke/44.png");
  poke[44] = IMG_Load("sprites/poke/45.png");
  poke[45] = IMG_Load("sprites/poke/46.png");
  poke[46] = IMG_Load("sprites/poke/47.png");
  poke[47] = IMG_Load("sprites/poke/48.png");
}

void changer_poke(SDL_Surface *ecran)
{
	SDL_Event event;
	SDL_Surface *mini_poke[6], *rect = NULL, *plateau = NULL, *rect_pv = NULL;
	SDL_Surface *nom2 = NULL;
	SDL_Rect pos_mini1, pos_mini2, pos_mini3, pos_mini4, pos_mini5, pos_mini6, pos_rect, pos_mypoke, pos_nom, pos_plateau, pos_rect_pv;
	int longueur = 40, hauteur = 40, changer = 1, choix = 0;
	SDL_Color couleurNoire = {0, 0, 0};
	TTF_Font *police = NULL;
	Poke mini[20];

	poke_nom(mini);

	police = TTF_OpenFont("combat/king.ttf", 25);
	rect = IMG_Load("combat/rect_attaque.png");
	plateau = IMG_Load("combat/plateau_changer.png");
	rect_pv = IMG_Load("combat/carre_blanc.png");

	pos_mini1.x = 750;
	pos_mini1.y = 500;
	pos_mini2.x = 830;
	pos_mini2.y = 500;
	pos_mini3.x = 910;
	pos_mini3.y = 500;
	pos_mini4.x = 750;
	pos_mini4.y = 550;
	pos_mini5.x = 830;
	pos_mini5.y = 550;
	pos_mini6.x = 910;
	pos_mini6.y = 550;
	pos_rect.x = 709;
	pos_rect.y = 487;
	pos_rect_pv.x = 715;
  pos_rect_pv.y = 400;

	pos_mypoke.x = 280;
	pos_mypoke.y = 300;

	pos_nom.x = 725;
  pos_nom.y = 400;

	pos_plateau.x = 248;
	pos_plateau.y = 376;

	mini_poke[0] = IMG_Load("sprites/minipoke_5G/01.png");
	mini_poke[1] = IMG_Load("sprites/minipoke_5G/04.png");
	mini_poke[2] = IMG_Load("sprites/minipoke_5G/07.png");
	mini_poke[3] = IMG_Load("sprites/minipoke_5G/10.png");
	mini_poke[4] = IMG_Load("sprites/minipoke_5G/13.png");
	mini_poke[5] = IMG_Load("sprites/minipoke_5G/16.png");

	SDL_BlitSurface(rect, NULL, ecran, &pos_rect);

	SDL_BlitSurface(mini_poke[0], NULL, ecran, &pos_mini1);
	SDL_BlitSurface(mini_poke[1], NULL, ecran, &pos_mini2);
	SDL_BlitSurface(mini_poke[2], NULL, ecran, &pos_mini3);
	SDL_BlitSurface(mini_poke[3], NULL, ecran, &pos_mini4);
	SDL_BlitSurface(mini_poke[4], NULL, ecran, &pos_mini5);
	SDL_BlitSurface(mini_poke[5], NULL, ecran, &pos_mini6);

	while(changer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN: //appuyer sur une touche du clavier
			switch (event.key.keysym.sym) //évènement concernant les touches du clavier
			{
				case SDLK_ESCAPE: // Appuyer sur échap pour retourner au menu
				menu(ecran);
				changer = 0;
				break;
			}
			break;

			case SDL_MOUSEBUTTONDOWN: //clic gauche de la souris
			if (event.button.button == SDL_BUTTON_LEFT) //clic gauche
			{
				my_pokemons();
				if ((pos_mini1.x <= event.button.x) && ((pos_mini1.x + longueur) >= event.button.x) && (pos_mini1.y <= event.button.y) && (pos_mini1.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[0], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[0].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
				if ((pos_mini2.x <= event.button.x) && ((pos_mini2.x + longueur) >= event.button.x) && (pos_mini2.y <= event.button.y) && (pos_mini2.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[1], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[1].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
				if ((pos_mini3.x <= event.button.x) && ((pos_mini3.x + longueur) >= event.button.x) && (pos_mini3.y <= event.button.y) && (pos_mini3.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[2], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[2].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
				if ((pos_mini4.x <= event.button.x) && ((pos_mini4.x + longueur) >= event.button.x) && (pos_mini4.y <= event.button.y) && (pos_mini4.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[3], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[3].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
				if ((pos_mini5.x <= event.button.x) && ((pos_mini5.x + longueur) >= event.button.x) && (pos_mini5.y <= event.button.y) && (pos_mini5.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[4], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[4].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
				if ((pos_mini6.x <= event.button.x) && ((pos_mini6.x + longueur) >= event.button.x) && (pos_mini6.y <= event.button.y) && (pos_mini6.y + hauteur >= event.button.y))
				{
					SDL_BlitSurface(plateau, NULL, ecran, &pos_plateau);
					SDL_BlitSurface(my_poke[5], NULL, ecran, &pos_mypoke);
					SDL_BlitSurface(rect_pv, NULL, ecran, &pos_rect_pv);
					nom2 = TTF_RenderText_Blended(police, mini[5].nom, couleurNoire);
					SDL_BlitSurface(nom2, NULL, ecran, &pos_nom);
					combat(ecran);
					changer = 0;
				}
			}
			break;
		}
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(rect);
	TTF_CloseFont(police);
}

int deroulement(SDL_Surface *ecran, int joueur,int puissance)
{
	char texte_remplacer[150];
	if (joueur == 0)
	{
	//	printf(" pv perdu : %d\n",calcul_pv_perdu(poke1,poke2,puissance));
		poke2.PV-=calcul_pv_perdu(poke1, poke2,puissance);
		if(poke2.PV < 0){
			poke2.PV = 0;
		}
	}
	else
	{
		int nb_aleatoire;
		//La boucle suivante relance le tirage jusqu'à ce que le tirage donc une attaque non nulle
		do{
			nb_aleatoire = rand()%4;
		}while(poke2.attaque[nb_aleatoire].id == 0);
		//printf("poke1 va perdre %d hp \n",calcul_pv_perdu(poke2,poke1,poke2.attaque[nb_aleatoire].puissance));
		sprintf(texte_remplacer,"%s utilise %s",poke2.nom,poke2.attaque[nb_aleatoire].nom);
		dialogue_affichage(ecran,texte_remplacer,texte_remplacer,texte_remplacer);
		SDL_Delay(1000);
		poke1.PV-=calcul_pv_perdu(poke2, poke1,poke2.attaque[nb_aleatoire].puissance);

		if(poke1.PV < 0){
			poke1.PV = 0;
		}
	}
	return (joueur +1)%2;
}

int calcul_pv_perdu(Poke attaquant, Poke defenseur,int puissance)
{
	return ((attaquant.niv*0.4+2)*attaquant.att*puissance)/(defenseur.def*50)+2;
}

int calcul_exp_gagne(Poke poke)
{
	float a = 1;
	if (type_adversaire==DRESSEUR)
	{
		a = 1.5;
	}
	FILE *fic = NULL;
	fic = fopen("Ressources/Stat_poke","r");
	char TAB[120];
	fgets(TAB, 119, fic);
	int id_f = 0;
	while(id_f != poke.id)
	{
		fgets(TAB, 119, fic);
		id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
	}
	// charger les stats de base
	int b =	(TAB[80]-'0')*100 + (TAB[81]-'0')*10 + TAB[82]-'0';
	//calcul exp obtenue
	return (a*b*poke.niv)/7;
}

void ajout_exp(int exp_gagne, SDL_Surface *ecran)
{
	poke1.exp += exp_gagne;
	//printf("%d\n",poke1.exp);
	printf("%d\n",poke1.niv);
	while(poke1.exp >= ((poke1.niv+1)*(poke1.niv+1)*(poke1.niv+1)))
	{
		poke1.niv++;
		maj_att_niv(&poke1);
		if(poke1.niv >= poke1.nivEvo){//si le pokemon a le niveau suffisant pour évoluer
				evolution(ecran);
		}
		printf("Nouveau niveau :%d\n",poke1.niv);
	}
	printf("Experience total : %d\n",poke1.exp);
}

int attaque(SDL_Surface *ecran)
{
  SDL_Surface *rect = NULL;
  SDL_Rect pos_rect;
  pos_rect.x = 709;
  pos_rect.y = 487;
  rect = IMG_Load("combat/rect_attaque.png");
  SDL_BlitSurface(rect, NULL, ecran, &pos_rect);
}
void evolution(SDL_Surface *ecran){
	printf("EVOLUTIOOOOOOOOONN !!!!\n");
	if (animation_evo(poke1.id,ecran) == 1){
		poke1.id++;
		calcul_stat(&poke1);
	}
}
