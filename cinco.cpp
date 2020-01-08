
//Nome : Lorenzo Gasparollo                                                     Classe : 4^ B informatica
//                                 P R O G E T T O      C I N C O 
#include "cinco.h" // class's header file

// class constructor
cinco::cinco()
{
	// Inizializzazione degli attributi
	turno = 1;
	norm = false;
	primo = false;
}
void cinco::ReIniz()
{
    SetTurno(1);
	norm = false;
	primo = false;
}
void cinco::SetTurno(int x)
{turno = x;}
void cinco::SetPrimo(bool x)
{primo=x;}
void cinco::SetNorm(bool x)
{norm=x;}
// class destructor
cinco::~cinco()
{
	// insert your code here
}
//procedura che copia la matrice normale nella matrice dell'intelligenza artificiale
void cinco::CopiaMatrIntel()
{
     for(int i=0;i<20;i++)
     for(int j=0;j<20;j++)
     matrIntel[i][j] = 0;
    
}

//procedura che visualizza la matrice
void cinco::VisualizzaMatrIntel()
{
     for(int i=0;i<20;i++)
     {
            for(int j=0;j<20;j++)
             cout<<matrIntel[i][j]<<" .";
             cout<<endl;
     }
             
}
//procedura che assegna i valori alle varie combinazioni
int cinco::AssegnaValori(int val)
{
    switch(val)
    {
      case 0: return 0;break;
      case 1: return 1;break; 
      case 2: return 10;break;   //__________________Duina
      case 3: return 60;break;   //__________________Terzina
      case 4: return 6000;break; //__________________Quartina
    }
}
//Ricerca il valore massimo all'interno della matrice
void cinco::RicercaMassimo()
{
     int max = 0;
     for(int i=0;i<20;i++)
     for(int j=0;j<20;j++)
     {
             if(matrIntel[i][j]>max) //classica implementazione della ricerca del massimo
             {
                 max = matrIntel[i][j];
                 r = i;
                 c = j;
             }
     }
}       
void cinco::CercaRighe(int chi,int avv)
{
    int contaChi = 0;
    
    for(int i = 0;i < 20;i++)
    for(int j = 0;j <= 15; j++) //15 poichè vado di 5 in 5
    {
                          for(int k = 0; k < 5;k++)    //controllo  5 elementi
                          {
                               if(matr[i][j+k] == avv) //se è presente la mia pedina non serve che vada avanti
                               {
                                    contaChi=0;
                                    break;
                               }
                               else
                               if(matr[i][j+k] == chi) //se l'elemento è presente
                               contaChi++;            //aggiorno il contatore
                               
                          }
                          
                          int aiuto = 0;
                          if(contaChi == 3)
                          if(TerzinaApertaRighe(i,j,chi))
                          aiuto = 100;
                          if(contaChi == 2)
                          if(DuinaApertaRighe(i,j,chi))
                          aiuto = 20;
                          //assegno i valori alla matriceIntel
                          for(int p = 0; p < 5;p++)    
                          {
                              aiuto+= AssegnaValori(contaChi); //chiamo funzione che assegna i valori alla matrice in base 
                                                                    // al contatore 
                              
                               if(matr[i][j+p]==0)
                               matrIntel[i][j+p]+=aiuto; //assegno il valore alla cella
                               aiuto = 0;
                          }
            contaChi = 0; //riazzero il contatore
    }
}
//_________________________________________________HO UTILIZZATO LO STESSO METODO DELLA CERCA RIGA
//:::::::::::::::::::::::::::::::::::::::::::::::::NATURALMENTE NON ANDRò PIù A CONTROLLARE LA RIGA BENSì QUELLO CHE MI INTERESSA
//::::::::::::::::::::::::::::::::::::::::::::::::: COLONNA, DIAGOLE1 O DIAGONALE2
void cinco::CercaDiagonale1(int chi,int avv)
{
     int contaChi = 0;
     for(int i = 0;i <= 15;i++)
     for(int j = 0;j <= 15;j++)
     {
             for(int k = 0; k < 5;k++)    
             {
                     if(matr[i+k][j+k] == avv)
                     {
                            contaChi=0;
                            cout<<"aaaaaaaaaaaaaaa";
                            break;
                     }
                     else
                     if(matr[i+k][j+k] == chi)
                     contaChi++; 
             }
                          
                          int aiuto = 0;
                          if(contaChi == 3)
                          if(TerzinaApertaDiagonale1(i,j,chi))
                          aiuto = 100;
                          if(contaChi == 2)
                          if(DuinaApertaDiagonale1(i,j,chi))
                          aiuto = 20;
                          //assegno i valori alla matriceIntel
                          for(int p = 0; p < 5;p++)    
                          {
                             aiuto += AssegnaValori(contaChi); 
                              if(matr[i+p][j+p]==0)
                              matrIntel[i+p][j+p]+=aiuto; //assegno il valore alla cella
                              aiuto = 0;
                          }
             
            contaChi = 0;
     }
}
void cinco::CercaDiagonale2(int chi,int avv)
{
     int contaChi = 0;
     for(int i = 4;i <= 20;i++)
     for(int j = 0;j <= 15;j++)
     {
             for(int k = 0; k < 5;k++)    
             {
                     if(matr[i-k][j+k] == avv)
                     {
                            contaChi=0;
                            break;
                     }
                     else
                     if(matr[i-k][j+k] == chi)
                      contaChi++; 
             }
                           int aiuto = 0;
                          if(contaChi == 3)
                          if(TerzinaApertaDiagonale2(i,j,chi))
                          aiuto = 100;
                          if(contaChi == 2)
                          if(DuinaApertaDiagonale2(i,j,chi))
                          aiuto = 20;
                          //assegno i valori alla matriceIntel
                          for(int p = 0; p < 5;p++)    
                          {
                             aiuto += AssegnaValori(contaChi); 
                              if(matr[i-p][j+p]==0)
                              matrIntel[i-p][j+p]+=aiuto; //assegno il valore alla cella
                              aiuto = 0;
                          }
             
            contaChi = 0;
     }
}

void cinco::CercaColonne(int chi,int avv)     
{
    int contaChi = 0;
    for(int i = 0;i <= 15;i++)
    for(int j = 0;j < 20; j++)
    {
                          for(int k = 0; k < 5;k++)    
                          {
                               if(matr[i+k][j] == avv)
                               {
                                    contaChi=0;
                                    break;
                               }
                               else
                               if(matr[i+k][j] == chi)
                               contaChi++;
                               
                               
                          }
                          int aiuto = 0;
                          if(contaChi == 3)
                          if(TerzinaApertaColonne(i,j,chi))
                          aiuto = 100;
                          if(contaChi == 2)
                          if(DuinaApertaColonne(i,j,chi))
                          aiuto = 20;
                          //assegno i valori alla matriceIntel
                          for(int p = 0; p < 5;p++)    
                          {
                            aiuto += AssegnaValori(contaChi); 
                              if(matr[i+p][j]==0)
                               matrIntel[i+p][j]+=aiuto; //assegno il valore alla cella
                              aiuto = 0;
                          }
             
            contaChi = 0;
    }
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::TERZINE

bool cinco::TerzinaApertaRighe(int i,int j,int chi)
{
  return (((matr[i][j]==0) && (matr[i][j+1]==chi) && (matr[i][j+2]==chi) && (matr[i][j+3]==chi) && (matr[i][j+4]==0))); //se la terzina è aperta  
}   
bool cinco::TerzinaApertaColonne(int i,int j,int chi)
{   
   return (((matr[i][j]==0) && (matr[i+1][j]==chi) && (matr[i+2][j]==chi) && (matr[i+3][j]==chi) && (matr[i+4][j]==0)));
}     
bool cinco::TerzinaApertaDiagonale1(int i,int j,int chi)
{   
   return ((matr[i][j]==0) && (matr[i+1][j+1]==chi) && (matr[i+2][j+2]==chi) && (matr[i+3][j+3]==chi) && (matr[i+4][j+4]==0));
}
bool cinco::TerzinaApertaDiagonale2(int i,int j,int chi)
{   
   return (((matr[i][j]==0) && (matr[i-1][j+1]==chi) && (matr[i-2][j+2]==chi) && (matr[i-3][j+3]==chi) && (matr[i-4][j+4]==0)));
} 

//::::::::::::::::::::::::::::::::::::::::::::::::::::::DUINE

bool cinco::DuinaApertaRighe(int i,int j,int chi)
{
  return (!(((matr[i][j]==chi) && (matr[i][j+1]==chi) && (matr[i][j+2]==0) && (matr[i][j+3]==0) && (matr[i][j+4]==0)) || ((matr[i][j]==0) && (matr[i][j+1]==0) && (matr[i][j+2]==0) && (matr[i][j+3]==chi) && (matr[i][j+4]==chi)))); //se la terzina è aperta  
}   
bool cinco::DuinaApertaColonne(int i,int j,int chi)
{   
   return (!(((matr[i][j]==chi) && (matr[i+1][j]==chi) && (matr[i+2][j]==0) && (matr[i+3][j]==0) && (matr[i+4][j]==0)) || ((matr[i][j]==0) && (matr[i+1][j]==0) && (matr[i+2][j]==0) && (matr[i+3][j]==chi) && (matr[i+4][j]==chi))));
}     
bool cinco::DuinaApertaDiagonale1(int i,int j,int chi)
{   
   return (!(((matr[i][j]==chi) && (matr[i+1][j+1]==chi) && (matr[i+2][j+2]==0) && (matr[i+3][j+3]==0) && (matr[i+4][j+4]==0)) || ((matr[i][j]==0) && (matr[i+1][j+1]==0) && (matr[i+2][j+2]==0) && (matr[i+3][j+3]==chi) && (matr[i+4][j+4]==chi))));
}
bool cinco::DuinaApertaDiagonale2(int i,int j,int chi)
{   
    return (!(((matr[i][j]==chi) && (matr[i-1][j+1]==chi) && (matr[i-2][j+2]==0) && (matr[i-3][j+3]==0) && (matr[i-4][j+4]==0)) || ((matr[i][j]==0) && (matr[i-1][j+1]==0) && (matr[i-2][j+2]==0) && (matr[i-3][j+3]==chi) && (matr[i-4][j+4]==chi)))); //se la terzina è aperta  
}   

//Procedura che gestisce l'intelligenza artificiale del computer          
void cinco::IntelligenzaArtificiale(int chi,int avv)
{
     CopiaMatrIntel();   //Inizialializza la matrice che gestisce l0intelligenza artificiale
     /*if(primo==false)
     matrIntel[10][10] = 1;*/
     //___________________Fa le varie ricerche DI RIGA , COLONNA , DIAGONALE 1 , DIAGONALE 2
     CercaRighe(chi,avv); 
     CercaRighe(avv,chi);
     CercaColonne(chi,avv);
     CercaColonne(avv,chi);
     CercaDiagonale1(avv,chi);
     CercaDiagonale1(chi,avv);
     CercaDiagonale2(avv,chi);
     CercaDiagonale2(chi,avv);
     VisualizzaMatrIntel();
     //Ricerco il valore massimo in cui mi conviene di più posizionare la pedina
     RicercaMassimo();
     
}
//procedura che inizializza la matrice che gestisce l'intera gara
void cinco::Inizializza()
{
     for(int i=0;i<20;i++)
     for(int j=0;j<20;j++)
     matr[i][j]=0;
}
//Procedura che disegna la pedina
void cinco::DisegnaPedine(int i)
{
     if(i%2==1)  //Dato l'indice stabilisce che pedina disegnare
     {
               for(int i=0;i<(lato/40)+1;i++) //Animazione pedina 1
               {
               readimagefile("img&songs\\pedina1.gif",42+(x*((lato/20)+1))+(lato/40)-i,162+(y*((lato/20)+1))+(lato/40)-i,42+(x*((lato/20)+1))+(lato/40)+i,162+(y*((lato/20)+1))+(lato/40)+i);
               delay(10);
               }
     }
     else
     for(int i=0;i<(lato/40)+1;i++) //Animazione pedina 2
     {
     readimagefile("img&songs\\pedina2.gif",42+(x*((lato/20)+1))+(lato/40)-i,162+(y*((lato/20)+1))+(lato/40)-i,42+(x*((lato/20)+1))+(lato/40)+i,162+(y*((lato/20)+1))+(lato/40)+i);
     delay(10);
     }
}
//Procedura che disegna la scritta che descrive a chi giocatore
void cinco::DisegnaScritteTurni(int i)
{
     if(i%2==1)//Dato l'indice stabilisce che scritta disegnare
     {
               for(int i=0;i<250;i=i+10)//Animazione scritta 1
               readimagefile("img&songs\\Giocatore2.jpg",292-i,70,322+i,140);
     }
     else
     {
          for(int i=0;i<250;i=i+10)//Animazione scritta 2
          readimagefile("img&songs\\Giocatore1.jpg",292-i,70,322+i,140);
     }
}
//Procedura che controlla se la pedina è compresa nella tavola
bool cinco::CursoreCompresoTavola(int x,int y)
{
     return ( ( x >= 42 && x <= 42+lato) && ( y >= 162 && y <= 162+lato) ); //restituisce un booleano
}
//procedura che assegna i valori alle matrici
int cinco::AssegnaValMatr(int i)
{
     if(i%2==1)
     return 6;
     else
     return 1;
}
//Procedura che dice se una cella è libera o meno
bool cinco::CellaLibera(int x,int y)
{
     return (matr[x][y]==0);
}/*
bool cinco::ControlloVittoria(int indx, int indy)
{
     int val = matr[indx][indy];
     int scorri = indy - 4;
     int conta = 0;
     for(int k = 0;k < 5;++)
     {
             if(matr[index][scorri+k]==val)
             conta++;
     }*/
             
//Procedura per il calcolo della vittoria
bool cinco::Vittoria(int indx, int indy)
{
     int nQuad = 20;
     //Controllo Verticale
      int conta=1, i=indy+1;
      while(i<(indy+5)&&i<nQuad&&matr[indx][i]!=turno&&matr[indx][i]!=0)
      {
         i++;
         conta++;
      }
      i=indy-1;
      while(i>(indy-5)&&i>=0&&matr[indx][i]!=turno&&matr[indx][i]!=0)
      {
         i--;
         conta++;
      }
      
      if(conta>4)
      {cout<<"colonna";
      return true;}
      
      
      //Controllo Orizzontale
      conta=1;
      
      conta=1, i=indx+1;
      while(i<(indx+5)&&i<nQuad&&matr[i][indy]!=turno&&matr[i][indy]!=0)
      {
         i++;
         conta++;
      }
      i=indx-1;
      while(i>(indx-5)&&i>=0&&matr[i][indy]!=turno&&matr[i][indy]!=0)
      {
         i--;
         conta++;
      }
      
      if(conta>4)
      {cout<<"Riga";
      return true;}
      
      //Controllo Obliquo 1
      int k=indy+1;
      conta=1, i=indx+1;
      while(i<(indx+5)&&k<nQuad&&i<nQuad&&matr[i][k]!=turno&&matr[i][k]!=0)
      {
         i++;
         k++;
         conta++;
      }
      i=indx-1;
      k=indy-1;
      while(i>(indx-5)&&k>=0&&i>=0&&matr[i][k]!=turno&&matr[i][k]!=0)
      {
         i--;
         k--;
         conta++;
      }
      
      if(conta>4)
      {
                 cout<<"Diagonale1";
      return true;}
      
      //Controllo Obliquo 2
      k=indy-1;
      conta=1, i=indx+1;
      while(i<(indx+5)&&      k>=0      &&i<nQuad&&matr[i][k]!=turno&&matr[i][k]!=0)
      {
         i++;
         k--;
         conta++;
      }
     
      i=indx-1;
      k=indy+1;
      while(i>(indx-5)&&k<nQuad&&i>=0&&matr[i][k]!=turno&&matr[i][k]!=0)
      {
         i--;
         k++;
         conta++;
      }
      if(conta>4)
      { cout<<"Diagonale2";
      return true;}
      
      return false;
}
//Procedura che gestisce le opzioni del gioco
void cinco::Opzioni(int posx,int posy1,int posy2,int posy3)
{
     settextstyle (8, 0, 2); 
     setcolor(BLUE);
     outtextxy(posx,posy1,"1. Gioca Modalità Player1 vs Player2");
     outtextxy(posx,posy2,"2. Gioca Modalità intelligenza artif.");
     outtextxy(posx,posy3,"3. Esci ");
}
//Procedura che sposta le scritte nel Menu'
void cinco::SpostaScritte(int & i)
{
     if(i*2%larg==0)
       i=0;
       settextstyle (8, 0, 4);
       setcolor(15);
       outtextxy(i*2,20," The  Gasparollo Lorenzo's");
       settextstyle (8, 0, 4);
       outtextxy((larg-240)-i*2,60," Experience ");
       i++;
       settextstyle (8, 0, 2); 
     setcolor(7);
}
void cinco::Trova()
{
      int i=0;
      int aiutox,aiutoy;
      do
      {
       DisegnaScritteTurni(i);
       //Fai inserire la pedina all'utente SE
       //_____________________________________Nell'intelligenza artificiale tocca all'utente 
       //_____________OPPURE
       //SE
       //_____________________________________Se la modalità è giocatore 1 vs giocatore 2 
       
        if((turno==1) || norm==true)
        {
        
        do
        {
        while(!ismouseclick(WM_LBUTTONDOWN)) //Fintantoche non premo
        delay(10);
        getmouseclick(WM_LBUTTONDOWN,aiutox,aiutoy);
     
        //calcolo le coordinate
          x=(aiutox-42)/((lato/20)+1);
          y=(aiutoy-162)/((lato/20)+1);
          c=x;
          r=y;
          //Fintantoche non la cella non è libera e il cursone non è compreso nella tavola
        }while( (!CellaLibera(r,c)) || (!CursoreCompresoTavola(aiutox,aiutoy)));           
        } 
        
        else
        { //____________ALTRIMENTI fai lavorare l'INTELLIGENZA
           
           IntelligenzaArtificiale(1,6);
           /*if(i==0)
           primo=true;*/
            x = c;
            y = r;
        }
        Vittoria(r,c);
        //Gestione dei turni
        if(turno == 1)
        turno = 6;
        else
        turno = 1;
       //Assegno il valore alla matrice
       matr[r][c]=AssegnaValMatr(i);
       //Controllo la Vittoria
       Vittoria(r,c);
       //Disegno le pedine
       DisegnaPedine(i);
       VisualizzaMatr();
       //incremento il numero di turni
       i++;
  
     }while(i<400 && !Vittoria(r,c) ); //Fintantochè qualcuno non vince o non c'è la patta
      //____________________________________GESTIONE DELLA FINE DELLA PARTITA
      initwindow(800,600," GAME OVER ");
      settextstyle (8, 0, 4); 
      readimagefile("img&songs\\gameOver.jpg",0,0,800,400);
     outtextxy(20,500,"Doppio click per continuare !");
     if( i == 400)
     outtextxy(150,400,"Pareggio!");
     else
     if( turno == 1)
     {
         outtextxy(150,400,"Ha vinto il giocatore 2!");
     }
     else
     outtextxy(150,400,"Ha vinto il giocatore 1!");
     do{_sleep(100);
       }while(!ismouseclick(WM_LBUTTONDBLCLK));
    system("cls");
    //CHIUDO LE FINESTRE
    if(ismouseclick(WM_LBUTTONDBLCLK))
    {
          closegraph();
          closegraph();
    }
     
}//Procedura che preleva la posizione del mouse
void cinco::PosizioneMouse(int & x , int & y)
{
     delay(20);
     x=mousex();
     delay(20);
     y=mousey();
}
void cinco::VisualizzaMatr()
{
     for(int i=0;i<20;i++)
     {for(int j=0;j<20;j++)
     cout<<matr[i][j]<<" ";
     cout<<endl;}
}
//Menu' del programma
int cinco::Menu()
{
    initwindow(larg,lung,"Cinco - The Gasparollo's Experience");
     int x,y;
     int gx,gy;
     int posx=(larg/2)-180;
     int posy1=(lung/3)+60;
     int posy2=(lung/3)+120;
     int posy3=(lung/3)+180;
     //Apro una nuova finestra
     //Cambio colore
     setbkcolor(0);
     cleardevice();
     setbkcolor(0);
     
     //readimagefile("binary_code.jpg",0,270,900,600);
     readimagefile("img&songs\\binary_code.jpg",0,0,larg,lung+400);
     settextstyle (7, 0, 3); 
     setcolor(14);
     settextstyle (8, 0, 10); 
     setcolor(14);
     //outtextxy(50,85," CINCO ");
     readimagefile("img&songs\\CINCO.gif",50,85,600,185);
     Opzioni(posx,posy1,posy2,posy3);
     
    int i=0;  
     do
     {
                                            gx=0,gy=0;
                                            Opzioni(posx,posy1,posy2,posy3);
                                            setfillstyle(0,0);
                                            //bar(550,100,702,252);
                                          
     do
     { 
       x=0,y=0;
       PosizioneMouse(x,y);
       settextstyle (8, 0, 3);
       SpostaScritte(i);
      //La prima condizione testa la scritta 1. Simulazione lancio dadi (normali) (fintantoche le ascisse e le ordinate non sono comprese [quindi fintantoche non vado sopra la scritta 1. Simulazione lancio dadi (normali)) e stessa cosa per la seconda scritta 2. Simulazione lancio dadi (truccati] ed Esci
     }while(( ( x > posx+430 || x < posx ) || ( y > posy1+15 || y < posy1) ) && ( ( x > posx+430 || x < posx ) || (( y > posy2+15) || y < posy2)) && ( ( x > posx+85 || x < posx ) || (( y > posy3+15) || y < posy3)) ) ;
     //Fintantoche sono sopra a una delle due scritte e non clicco il tasto sinistro
     
     do{  
        setcolor(14);
        x=0,y=0;
        PosizioneMouse(x,y);
       //Se le coordinate del mouse sono comprese nella scritta 1. Simulazione lancio dadi (normali)
        if( ( !( x > posx+430 || x < posx ) && !( y > posy1+15 || y < posy1) ))
        {outtextxy(posx,posy1,"1. Gioca Modalità Player1 vs Player2");//La colori
        //readimagefile("cincoR.jpg",550,100,700,250);
        }
        
      
      else
      
       //Se le coordinate del mouse sono comprese nella scritta 2. Simulazione lancio dadi (truccati)
       if((!( x > posx+430 || x < posx ) && !( y > posy2+15 || y < posy2) ))
       outtextxy(posx,posy2,"2. Gioca Modalità intelligenza artif.");//La colori 
      else
      //Se le coordinate del mouse sono comprese nella scritta Esci
       if((!( x > posx+85 || x < posx ) && !( y > posy3+15 || y < posy3) ))
       outtextxy(posx,posy3,"3. Esci ");//La colori e la sposti
     SpostaScritte(i);
     }
     while( ( ( ( !( x > posx+430 || x < posx ) && !( y > posy1+15 || y < posy1) ) ) || ( (!( x > posx+430 || x < posx ) && !( y > posy2+15 || y < posy2))) || (!( x > posx+85 || x < posx ) && !( y > posy3+15 || y < posy3) )) && !ismouseclick(WM_LBUTTONDOWN) );
     //Se ho premuto il tasto sinistro
     if(ismouseclick(WM_LBUTTONDOWN))
     getmouseclick(WM_LBUTTONDOWN,gx,gy);//Mi ottieni le coordinate
     clearmouseclick(100);
     //Fintanto che non clicco o sulle scritte 
     SpostaScritte(i);
     }while(( ( gx > posx+430 || gx < posx ) || (( gy > posy1+15 || gy < posy1) ) && ( ( gx > posx+430 || gx < posx ) || (( gy > posy2+15 || gy < posy2) )) && ( ( gx > posx+85 || gx < posx ) || (( gy > posy3+15) || gy < posy3))) );
    //closegraph();
     // Controllo se ho cliccato la prima scritta
    if( ( ( gx <= posx+430 && gx >= posx ) && ( gy <= posy1+15 && gy >= posy1) ))
    {norm = true;
    return 1;}
    else
    // Controllo se ho cliccato la seconda scritta
    if((( gx <= posx+430 && gx >= posx ) && ( gy <= posy2+15 && gy >= posy2) ))
    {norm = false;
    return 2;}
    else
    // Controllo se ho cliccato la terza scritta
    if((( gx <= posx+85 && gx >= posx ) && ( gy <= posy3+15 && gy >= posy3) ))
    return 3;

}



void cinco::Gioca()
{
     initwindow(800,601);
     /*mciSendString("open img&songs\DiscoPogo.mp3 type mp3audio alias myFile", NULL, 0, 0);
     mciSendString("play img&songs\DiscoPogo.mp3",NULL,0,NULL);*/
    
     readimagefile("sfondo.jpg",0,0,800,601);
     int scost=3;
      
     
      closegraph();
      initwindow(1000,775,"Gioca - Che vinca il migliore !");
      readimagefile("img&songs\\sfondo.jpg",0,0,1000,775);
      readimagefile("img&songs\\forsegiusto.gif",700,100,804,700);
      setcolor(0);
      setlinestyle(6,4,2);
      line(42,162,42+lato,162);
      line(42,162,42,162+lato);
      
     for(int i=0;i<21;i++)
     {
            line(42+((lato/20)+1)*i,162,42+((lato/20)+1)*i,162+lato);
            line(42,162+((lato/20)+1)*i,42+lato,162+((lato/20)+1)*i);
     }
     Inizializza();
     Trova();
     //_________________________________________________________INIZIA IL GIOCATORE
     
 }   // readimagefile("monalisa.gif",grigliatop+75,grigliatop+78,grigliabottom+50,grigliabottom+50);
