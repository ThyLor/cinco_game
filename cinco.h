
//Nome : Lorenzo Gasparollo                                                     Classe : 4^ B informatica
//                                 P R O G E T T O      C I N C O 


                         //definizione delle librerie
#ifndef CINCO_H
#define CINCO_H
#include"graphics.h"
#include <dos.h>
#include <winable.h>
#include<iostream>
using namespace std;
                          //definizione delle costanti
#define grigliatop 100
#define grigliabottom 660
#define dim 1000
#define larg 1000
#define lung 800
#define lato 518

class cinco
{
    //______________ATTRIBUTI
	private :
            int x;                                    //Coordinata x
            int y;                                    //Coordinata y
            int matr[20][20];                         //matrice che gestisce la sfida
            int matrIntel[20][20];                    //matrice dell'intelligenza artificiale
            int turno;                                //Variabile che descrive l'andamento dei turni
            int r,c;                                  //Variabili che descrivono la riga e la colonna della matrice
            bool norm,primo;                                //Variabile che descrive se deve giocare un giocatore contro l'altro
                                                      // oppure se deve giocare contro il pc
                                                      
         
    //___________METODI
    public:
           
		// class constructor
		cinco();
		// class destructor
		~cinco();
		
		void Gioca();
		void Trova();
		void DisegnaPedine(int i);
		void DisegnaScritteTurni(int i);
		int AssegnaValMatr(int i);
		bool CellaLibera(int x,int y);
		bool CursoreCompresoTavola(int x,int y);
		bool Vittoria(int r,int c);
		void Inizializza();
		int Menu();
		void ReIniz();
		void Opzioni(int posx,int posy1,int posy2,int posy3);
		void PosizioneMouse(int & x , int & y);
		void SpostaScritte(int & i);
		void VisualizzaMatr();
		void SetTurno(int x);
		void SetPrimo(bool x);
		void SetNorm(bool x);
		
        
        //Metodi per la gestione della intelligenza artificiale IA
		void IntelligenzaArtificiale(int chi,int avv);
		int AssegnaValori(int val);
		void CercaRighe(int chi,int avv);
		void CercaColonne(int chi,int avv);
		void CercaDiagonale1(int chi,int avv);
		void CercaDiagonale2(int chi,int avv);
		bool TerzinaApertaRighe(int i,int j,int chi);
		bool TerzinaApertaColonne(int i,int j,int chi);
		bool TerzinaApertaDiagonale1(int i,int j,int chi);
		bool TerzinaApertaDiagonale2(int i,int j,int chi);
		bool DuinaApertaRighe(int i,int j,int chi);
		bool DuinaApertaColonne(int i,int j,int chi);
		bool DuinaApertaDiagonale1(int i,int j,int chi);
		bool DuinaApertaDiagonale2(int i,int j,int chi);
		void CopiaMatrIntel();
		void VisualizzaMatrIntel();
		void InizPC(int i);
		void RicercaMassimo();
		
};

#endif // CINCO_H
