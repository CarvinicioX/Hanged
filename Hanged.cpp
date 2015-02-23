#include "Hanged.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
 
Hanged::Hanged(string player, int Categoria = 1, int levels = 1){
	Iniciar(Categoria);
	this -> levels = levels;
	this -> player = player;
}
 
void Hanged::Iniciar(int Categoria){
	if( Categoria == 1 ){
		char buffer[101];
		int i;
		ifstream file("./Palabras.txt");
		if(file.good()){
			for(i = 0; !file.eof(); i++){
				file.getline(buffer,100);
				newlist.push_back(buffer);
			}
			file.close();
		}
	}
}

void Hanged::Level(int level) {
	this -> levels = level;
}
 
string Hanged::Otra(){
	setPalabra = "";
	srand(time(0));
	int random;
	int cool;
	if(oldlist.empty()){
		random = rand() % newlist.size();
		oldlist.push_back(newlist[random]);
		if(this->levels == 1){
			this-> intentos = newlist[random].length()*2;
		}else if (this->levels == 2){
			this-> intentos = (newlist[random].length() / 2)+newlist[random].length();
		}else if(this->levels == 3){
			this-> intentos = newlist[random].length();
		}
		getPalabra = newlist[random];
		for( int i = 0; i < getPalabra.length(); i++){
		    setPalabra += '_';
		}  
		return newlist[random];
	}else {
		bool NoseRepite = false;
		do{		
			random = rand() % newlist.size();
			for( int i = 0; i < oldlist.size(); i++){
				if(oldlist[i] == newlist[random]){				
					NoseRepite = true;
				}else{ 
					NoseRepite = false;
					 if(levels == 1){
				         this-> intentos = newlist[random].length()*2;
					 }else if (levels == 2){
						 this-> intentos = (newlist[random].length() / 2)+newlist[random].length();
					 }else if(levels == 3){
						 this-> intentos = newlist[random].length();
			       }
				   	getPalabra = newlist[random];
					for( int i = 0; i < getPalabra.length(); i++){
				         setPalabra += '_';
				     }  
					return newlist[random];
				}
			}
		}while(NoseRepite);
	}
}
 
bool Hanged::Termino()const{
	if (intentos == 0 || Gano()){
		return true;
	}else 
		return false;
}
 
string Hanged::getStringCurrentState(){
	cout << endl;
	return this -> setPalabra;
}
 
string Hanged::Guess(char letra){
	bool es = false;
	 for (int i = 0; i < getPalabra.length(); i++){
		if (setPalabra[i] == '_') {
			if (letra == getPalabra[i]) {
				es = false;
				setPalabra[i] = letra;
				break;
			} else {
				es = true;
				setPalabra[i] = '_';
			}
		}
	}
	if (es) {
		intentos-=1;
	}
	return setPalabra;
}
 
bool Hanged::Guess(string Cadena){
	if (Cadena == getPalabra){
		return true;
	}else 
		return false;
}
 
bool Hanged::Gano()const {
	if (setPalabra == getPalabra) {
		return true;
	} else {
		return false;
	}
}
