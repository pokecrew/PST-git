#include "include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

void chargerSpritesPerso(int numSpritePerso, SDL_Surface **Perso_Sprites){
  char path[]="images/sprites/Perso/000/01.png";
  path[21]= (numSpritePerso/100)+48; //on récupère le chiffre des centaines du numéro de sprite
  numSpritePerso = numSpritePerso%100;//on enleve le chiffre des centaines
  path[22]= (numSpritePerso/10)+48; //on récupère le chiffre des dizaines du numéro de sprite
  numSpritePerso = numSpritePerso%10;//on enleve le chiffre des dizaines
  path[23]= numSpritePerso+48; //on récupère le chiffre des unités du numéro de sprite
  for(int i=0; i<9; i++){
    path[26]= i+49; //on affecte i+1 au caractère des unités
    Perso_Sprites[i]=IMG_Load(path);
  }
  path[25]=49; // on affecte 1 au chiffre des dizaines
  for(int i=0; i<3; i++){
    path[26]= i+48; //on affecte i au caractère des unités
    Perso_Sprites[i+10]=IMG_Load(path);
  }
}
