#include "structs.h"
#include"menu.h"
#include"puzzle.h"
//#include"background.h"
//#include"resource_enigme/enigme.h"
/* Prototypes des fonctions utilisées */

 extern  void init(char * , Gestion * jeu);
 extern void initializeEnnemy(Monstre *monstre) ; 
 extern void drawanimatedEnnemy(Monstre *monstre , hero he , Gestion * jeu);
 extern void cleanup(void);
extern Input2  getInput2(Input2  input2);

 extern Input  getInput(Input input);
 extern void  draw_object (Gestion * jeu,  object o[5] );

 extern SDL_Surface* drawImage(SDL_Surface *image,SDL_Surface *screen, int x, int y ) ;
 //menu  
 extern  void menu(int * menuout);
 extern void delay(unsigned int);
//extern void drawanimatedplayer1(hero* he , Gestion * jeu);
 extern void drawanimatedplayer(hero* he , Gestion * jeu);
 extern void drawanimatedplayer2(hero2* he2 , Gestion * jeu);


 extern void loadGame(Gestion * jeu);
extern void loadGame1(Gestion *jeu);
 extern void loadGame2(Gestion * jeu);

 extern void initializehero(hero *he);
 extern void initializehero2(hero2 *he2);

 extern void reset(hero *he,hero2 *he2 ,Monstre *monstre , vie v[4] , object o[5]) ;
 extern void initialiservie(vie v[]);
 extern SDL_Surface*  draw_vie (SDL_Surface* screen,  vie v[4] , int hvie );
 extern Mix_Music* loadSound_infini(char *name);
 extern void initialiserobject(object o[]);

// extern void drawgame( );
 extern void dohero( hero *he , Input input,Gestion * jeu,ArduinoMaster *ard_ms);
extern void dohero2( hero2 *he2 , Input2 input2,Gestion *jeu);


 extern void dovie(hero *he, object o[5],vie v[4],SDL_Rect camera,Monstre monstre);
//extern void dotime(hero *he);
//extern void doscore(hero *he,coin *cn);
 extern void playSound_infini(Mix_Music* sfx);

 extern void drawhero(hero * he , Gestion *jeu);
extern void drawhero2(hero2 * he2 , Gestion *jeu);

// extern void drawhero1(hero * he , Gestion *jeu);
 extern int solution_e (char image []);
 extern int resolution (int * go ,int * run );
//minimap 
 extern void Init_MiniMap(Minimap*m,Gestion *jeu);
 extern void Update_MiniMap(Minimap *m,Gestion *jeu);
 extern void Display_MiniMap(Minimap*m,SDL_Surface*screen);
 extern void InitArduino(ArduinoMaster *ard_ms);
//arduino 
 extern void read_from_arduino(ArduinoMaster *ard_ms);
 extern int ArduinoKeyCheck(ArduinoMaster *ard_ms, char *key_str);
 extern int serialport_init(const char* serialport, int baud);
 extern int serialport_close( int fd );
 extern int serialport_writebyte( int fd, uint8_t b);
 extern int serialport_read_until(int fd, char* buf, char until, int buf_max, int timeout);
 extern int serialport_flush(int fd);
 extern int serialport_write(int fd, const char* str);


//chrono 
extern void Init_score(score *s,SDL_Rect pos,int temps);
 extern void Display_score(score *s,SDL_Surface*screen);


 extern void Init_Chrono(Chrono *c,SDL_Rect pos,int temps);
 extern void Display_Chrono(Chrono *c,SDL_Surface*screen);
 extern bool Calcul_Chrono(Chrono *c);
 extern void Pause_Chrono(Chrono *c);
 extern bool Calcul_ChronoE(Chrono *c,SDL_Surface *screen); 


//tic tac toc game 
 extern void Init_Xo(Xo *xo);
 extern int Checkwin_Xo(Xo *xo);
 extern void Put_Xo(Xo* xo,int x,int y);
 extern void Random_Xo(Xo *xo);
 extern void Diplay_Xo(Xo* xo,SDL_Surface* ecran);
 extern void Free_Xo(Xo *xo);
 extern void Play_Xo(SDL_Surface *ecran);




  
