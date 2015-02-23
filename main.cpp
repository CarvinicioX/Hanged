#include "Hanged.h"
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
int main(int argc, char* argv[]){
	string playername;
	char buffer[50];
	cout << "Nombre del Jugador: ";
	cin >> buffer;
	playername = buffer;
	Hanged Ahorcado(playername, 1, 1);
	while (true) {
		int category = 1;
		Ahorcado.Iniciar(category);
		int level = 1;
		Ahorcado.Level(level);
		string word = Ahorcado.Otra();
		cout << "Es una palabra de " << word.length() << " letras" << endl;
		for (int i = 0; i < word.length(); ++i) {
			cout << '_';
		}
		cout << endl;
		int NumerodeIntento = 0;
		string cadena;
		string printout;
		bool adivinoDeUnSolo = false;
		while (!Ahorcado.Termino()){
			printout = Ahorcado.getStringCurrentState();
			cout << "Digite su intento: ";
			cin >> cadena;
			NumerodeIntento += 1;
			if (cadena.length() == 1){
				printout = Ahorcado.Guess(cadena[0]);
				cout << printout << endl;
			} else {
				adivinoDeUnSolo = Ahorcado.Guess(cadena);
			}
			if (adivinoDeUnSolo) {
				cout << "Eres un Ganador en "
				<< NumerodeIntento + 1 << " intentos " << endl;
				break;
			}
		}
		if (Ahorcado.Gano() || adivinoDeUnSolo) {
			cout << "Eres un ganador!!" << endl;
		} else {
			cout << "Perdedor!!" << endl;
		}
		char Resp;
		cout << "Desea Continuar? [s/n]" << endl;
		cin >> Resp;
		if (Resp == 's' || Resp == 'S') {
			continue;
		} else {
			break;
		}
	}
	return 0;
}
