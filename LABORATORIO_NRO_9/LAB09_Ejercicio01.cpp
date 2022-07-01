// Alineamiento Global
#include <iostream>
#include <algorithm> 
#include <random> 
#include <string> 
#include <chrono> 
#include <vector> 

using namespace std;

void imprimir_chars(char *&s, int size){	
	for (int i = 0; i != size; i++){
		cout << s[i];
	}
}


bool validar_secuencia(char *&c, int size){
	string s;
	for (int i = 0; i != size; i++){
		s.push_back(c[i]);
	}
	
	std::size_t found = s.find_first_not_of("ATGC");

	return std::string::npos == found;
}


void leer_sequencias(char *&a, char *&b, int &n, int &m ){	
	cout << "leer_sequencias -> " << endl;
	
	cout << "Primera secuencia?: "; cin >> n ;
	a = new char[n];
	for(int i = 0; i != n; i++){
		cin >> a[i];
	}
    
	cout << "Segunda secuencia?: "; cin >> m;
	b = new char[m];
	for(int i = 0; i != m; i++){
		cin >> b[i];
	}
}



string obtener_char(char *&c, int posicion){	
	

	string s;	
	s.push_back( c[posicion] );	

	return s;
}

bool comparar_char(char *&v, char *&w, int i, int j){
	bool equals = false;

	string left = obtener_char( v, i );
	string right = obtener_char( w, j);

	if( left.compare( right ) == 0 ){ 
		equals = true;
	}
	return equals;

}

void obtener_p(int **& p, int filas, int columnas, char *&v, char *&w){	
	for(int i = 1; i < filas; i++){
		for(int j = 1; j < columnas; j++){
			if( comparar_char(v, w, i - 1, j - 1) ){ 
				p[i][j] = 1;
			}else{
				p[i][j] = -1;
			}			
	    }
    }
}

int maximo(int a, int b){
	if( a > b ){
		return a;
	}else{
		return b;
	}
}

void calcular_similaridad(char *&v, char *&w, int n, int m, int g, int **& p, int **& S){
	
	cout << "calcular_similaridad -> " << endl;
	int filas, columnas;
	filas = n + 1;
	columnas = m + 1; 

	init_matrix(S, filas, columnas );
	init_matrix(p, filas, columnas );


	obtener_p(p, filas, columnas, v, w);
	
	for(int i = 0; i < columnas; i++){
       	S[0][i] = i*g;
    }

	for(int j = 1; j < filas; j++){
       	S[j][0] = j*g;
    }
	for(int i = 1; i < filas; i++){
		for(int j = 1; j < columnas; j++){
			
			int a = S[i-1][j] + g;
			int b = S[i-1][j-1] + p[i][j];
			int c = S[i][j-1] + g;			

			S[i][j] = maximo( a, maximo(b, c) );
	    }
    }
}



int main(int argc, const char* argv[]) {	
	cout<<"lABNRO9"<<endl;
}
