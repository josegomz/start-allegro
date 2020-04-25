
//Objetos id
enum IDS{JUGADOR, BALA, ENEMIGO};


//jugador
struct NaveEspacial{
	int ID;
	int x;
	int y;
	int vidas;
	int velocidad;
	int score;
	int boundx;
	int boundy;
};

struct Bala{
	int ID;
	int x;
	int y;
	bool vivo;
	int velocidad;
};

struct Enemigo{
	int ID;
	int x;
	int y;
	bool vivo;
	int velocidad;
	int boundx;
	int boundy;
	int velocidady;
};