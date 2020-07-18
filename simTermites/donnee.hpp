#ifndef donnee_hpp
#define donnee_hpp

#define RED     "\033[1;31m"
#define WHITE   "\033[1;0m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                       << " line " << __LINE__ << ": " #test << endl

using namespace std;

////////////////////////////////////////// 
// Constantes :

static const short X = 90, Y = 40;
static const short tempsVide = 6;

static const unsigned short proba_t = 5, proba_b = 10;  // Les densités des Brindilles et termites (sur 100)

const short taille = X * Y;
const unsigned short tailleTabIdT = taille*(proba_t+10)/100;  // La taille du tableau des termites. 
                                                              // (Cette valeur est supérieure au vrai nombre de termites).

// Deux variables globales qui seront utilisées dans la fonction 'main'.
static string message = "Bonjour !\nBienvenue à la simulation des termites !\nDans cette simulation, les termites qui portent des brindilles sont de couleurs rouge, ceux qui n'en portent pas sont verts.\n\nPour :\n\t- faire une passe, appuyez sur entrée\n\t- accélérer la simulation 2 fois, appuyez sur la touche '*' puis entrée\n\t- diminuer la vitesse de passe 2 fois, appuyez sur '/' puis entrée\n\t- l'arrêter, appuyez '.' et puis entrée.\n\nSi vous etes prêt, appuyez sur entrée.\nAmusez-vous bien !";

static string instruc = "Pour faire une passe, appuyez sur entrée. Pour accélerer la simulation 2 fois, appuyez sur la touche '*' puis entrée, et  sur '/' puis entrée pour diminuer 2 fois, '.' pour l'arreter.";


//////////////////////////////////////////
// liés à coord :

struct Coord {
    int x;
    int y;
};

enum Direction {
    nordOuest=0, nord = 1, nordEst = 2, est = 3, sudEst = 4, sud = 5, sudOuest = 6, ouest = 7,
    NO = 0,      N = 1,    NE = 2,      E = 3,   SE = 4,     S = 5,   SO = 6,       O = 7
};

//////////////////////////////////////////
// liés à grille :

struct Case{
    bool brindille;
    short idT;
};

struct Grille {
    Case tab[X][Y]; 
};

//////////////////////////////////////////
// liés à termite :

struct Termite {
    short idT;
    Coord c;
    short sablier;
    bool brin;
    Direction d;
    bool tourneSurPlace;
};

#endif