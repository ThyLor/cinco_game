
//Nome : Lorenzo Gasparollo                                                     Classe : 4^ B informatica
//                                 P R O G E T T O      C I N C O 

                             //definizione delle librerie & costanti
#define _WIN32_WINNT 0x0500 
#include <cstdlib>
#include <iostream>
#include"cinco.h"
#include <mmsystem.h>
#include <dos.h>
#include <wincon.h>
#include<windows.h>

using namespace std;
//Programma principale
int main()
{

    HWND hWnd = GetConsoleWindow(); //Nasconde finestra del DOS
    ShowWindow(hWnd, SW_HIDE );
    
    cinco x;
    int fine;
    do
    {
     x.Inizializza();
     x.ReIniz();
    fine = x.Menu();
    if(fine!=3)
    x.Gioca();
    }while(fine!= 3); //Fintantoche l'utente non decide di smettere
    exit(0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
