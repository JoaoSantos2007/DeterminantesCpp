/*
    Nome: Calculadora de Determinantes
    Autores: Yago G. I. Carniel and João Pedro Tomaz and H...
*/

#include <iostream>
using namespace std;

int main(){
    int n = 0;
    float valor, determinante = 0;

    //Input tamanho da matriz
    cout << "Digite o numero de linhas e colunas da matriz: ";
    cin >> n;

    //Matriz
    float matriz[n][n];

    //Leitura da Matriz
    for(int c = 0;c < n;c++){
        for(int l = 0;l < n;l++){
            cin >> valor;
            matriz[c][l] = valor;
        }
    }

    
    if(n == 1){//Matriz ordem 1
       determinante = matriz[0][0]; 
    }else if(n == 2){ // Matriz ordem 2
        float x = matriz[0][0] * matriz[1][1];
        float y = matriz[0][1] * matriz[1][0];
        
        determinante = x - y;
    }else if(n == 3){// Matriz ordem 3

        float matriz_apoio[n][n+2];//Matriz de apoio durante a execução da regra de Sarrus
        
        for(int c = 0;c < n;c++){//Preenche a matriz de apoio
            for(int l = 0;l < n+2;l++){
                if(l >= n){
                    matriz_apoio[c][l] = matriz[c][l-n];
                }else{
                   matriz_apoio[c][l] = matriz[c][l]; 
                }
                
            }
        }

        //Variáveis de controle
        float P1,P2 = 0;
        float P = 1;
        float C = 0;
        
        //Calcula a primeira parte
        for(int L = 0;L < n;L++){
            int l = L;
            for(int c = 0;c < n;c++){
                P *= matriz_apoio[c][l];
                l++;
            }
            P1 += P;
            P = 1;
        }

        //Calcula a segunda parte
        for(int L = 0;L < n;L++){
            int l = n + 1 - L;
            for(int c = 0;c < n;c++){
                P *= matriz_apoio[c][l];
                l--;
            }
            P2 += P;
            P = 1;
        }
        
        determinante = P1 - P2;

    }else{//Matriz com ordem maior que 3
        cout << "Ainda nao disponivel!" << endl;
    }

    cout << "Determinante: "<< determinante << endl;
}