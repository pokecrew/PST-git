//Raccourcis terminal
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define ONLINE      "\033[A"       /*Imprime sur la ligne précédente*/

typedef enum Direction Direction;
enum Direction
{
    HAUT, GAUCHE, DROITE, BAS
};

typedef enum bool bool;
enum bool
{
    TRUE,FALSE
};

typedef enum Musique_Replay Musique_Replay;
enum Musique_Replay
{
    BOUCLE = -1, UNIQUE = 1
};

typedef enum adversaire_combat adversaire_combat;
enum adversaire_combat
{
    SAUVAGE,DRESSEUR
};

typedef enum Type Type;
enum Type
{
    COMBAT, EAU, ELEC, NORMAL, FEU, GLACE, INSECTE, PLANTE, POISON, PSY, ROCHE, GROUND, SPECTRE, VOL
};

//Sont déclarées dans ce fichier les constantes et les variables globales au programme

int TAILLE_SPRITE = 24; //variable taille affichage
int NBLIN=0; //Nombre de lignes de la carte (0 au démarrage)
int NBCOL=0; //Nombre de colonnes de la carte (0 au démarrage)

//taille fenêtre
int FENETRE_W=1280;
int FENETRE_H=720;
typedef struct Perso Perso;

//Structure des objets Perso
struct Perso{
    int x;        //position sur les x (coin supérieur gauche)(nombre de case)
    int y;        //position sur les y (coin supérieur gauche)(nombre de case)
    int numSprite; //numéro sprite
    SDL_Rect position; //positions de la surface
    SDL_Surface *Perso_Sprites[24];//Tableau des sprites du personnage
};

typedef struct Att Att;

struct Att{
  int id;
  char nom[40];
  Type type;
  int classe; //0 = Physique, 1 = Spéciale
  int puissance;
  int precision;
  int pp_max;
  int pp;
};


typedef struct Poke Poke;

struct Poke{
  char nom[25];
  int PV;
  int exp;
  int niv;
  int def;
  int att;
  int vit;
  int id;
  Att  attaque[4];
  int nivEvo;
};



//variables globales
SDL_Color couleurBleue = {7, 58, 101}; //couleurs utilisées dans le jeu
SDL_Color couleurRouge = {165, 38, 10};
SDL_Color couleurBlanche = {190, 190, 190};
SDL_Color couleurJaune = {182, 120, 35};
SDL_Color couleurTitre = {0, 0, 0};
Mix_Music *music; //Musique du jeu
SDL_Surface *Map_Sprites[10000];//Tableau des sprites de la Map
SDL_Rect perso_position_old; //dernière position du joueur sur une map unique (= autre que maison, centre pkmn, etc...) (relatif au coordonnées de Map[0][0])
int musicMapPrec = -1; //musique jouée lors sur la carte précédente (par défaut -1)

int musicMap = 3; //musique jouée sur la map actuelle
int numMapPrec = 3; //numéro de la map précédente (à charger depuis un fichier sauvegarde)
int numMap = 3; //numéro de la map actuelle (à charger depuis un fichier sauvegarde)
int volumeSon = 0; //0 = min, 128 = max;

char nomMap[40]="";
char mapPath[]="map/03.lvl"; //chemin vers le fichier source de la carte actuelle
int typeSprite = 0; //sprites de petites tailles (0) ou de grande taille (12)
int lancerCombat = 0; // variable qui stocke le nombre de pas dans les hautes herbes sans avoir lancé de combat
bool surf = FALSE; //stocke si le perso peut surfer ou non
int nbPokeJoueur = 6;
//poke Theo/Camille
Poke poke1, poke2;
// type d'adversaire
adversaire_combat type_adversaire = SAUVAGE;
