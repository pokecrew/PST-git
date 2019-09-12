#define TAILLE_SPRITE 16

int NBLIN=0; //Nombre de lignes de la carte (0 au démarrage)
int NBCOL=0; //Nombre de colonnes de la carte (0 au démarrage)

SDL_Color couleurBleue = {7, 58, 101}; //couleurs utilisées dans le jeu
SDL_Color couleurRouge = {165, 38, 10};
SDL_Color couleurBlanche = {190, 190, 190};
SDL_Color couleurJaune = {182, 120, 35};
SDL_Color couleurTitre = {0, 0, 0};
Mix_Music *soundEffect[4]; //Tableau contenant les Musiques
int fullscreenStatus = 0; //stocke si le jeu est en plein écran ou non
int soundEffectStatus = 1; //stocke si le son est actif ou non
int currentTheme = 2; //stocke le theme choisi (1 = lettres, 2= Persos )

SDL_Surface *Map_Sprites[10000];//Tableau des sprites de la Map
