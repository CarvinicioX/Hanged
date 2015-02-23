#ifndef HANGED_H
#define HANGED_H
#include <string>
#include <vector>

using namespace std;

class Hanged{
private:
	vector<string> newlist;
	vector<string> oldlist;
	string player;
	int cats;
	int intentos;
	int levels;
	string getPalabra;
	string setPalabra;
public:
	Hanged(string, int, int);
	void Iniciar(int);
	string Otra();
	void Level(int);
	bool Termino()const;
	string getStringCurrentState();
	string Guess(char);
	bool Guess(string);
	bool Gano()const;
};

#endif	/* HANGED_H */
