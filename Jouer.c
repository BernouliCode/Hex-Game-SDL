#include "Prototypes.h"

#include <SDL/SDL.h>

void BlitImage(SDL_Surface *Surface ,SDL_Surface *Ecran ,int X ,int Y){
SDL_Rect pos;
pos.x=X;
pos.y=Y;
SDL_BlitSurface(Surface,NULL,Ecran,&pos);
SDL_Flip(Ecran);
}
void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int Joueur_Humain(int Joueur  , Etat etat , SDL_Surface *Screen , SDL_Surface *Table ){
    int flag = 1 ,i ,j,x,y;
    SDL_Surface *Black = NULL;
    SDL_Surface *White = NULL;
    SDL_Surface *Pion  = NULL;
    SDL_Surface *Menu_Table = NULL;
    SDL_Surface *Quitter = NULL;
    SDL_Surface *Player_1_Actif=NULL , *Player_1_Passif=NULL;
    SDL_Surface *Player_2_Actif=NULL , *Player_2_Passif=NULL;
    SDL_Surface *Player_Actif=NULL ;
    SDL_Surface *Ordinateur_Passif=NULL;

    Black = IMG_Load("./Design/pion_noir.png");
    White = IMG_Load("./Design/pion_blanc_1.png");
    Player_Actif = IMG_Load("./Design/Joueur_Actif.png");
    Ordinateur_Passif = IMG_Load("./Design/Ordinateur_Passif.png");
    Player_1_Actif = IMG_Load("./Design/joueur1_actif.png");
    Player_2_Actif = IMG_Load("./Design/joueur2_actif.png");
    Player_1_Passif = IMG_Load("./Design/joueur1_passif.png");
    Player_2_Passif = IMG_Load("./Design/joueur2_passif.png");
    Menu_Table = IMG_Load("./Design/Menu_Table.png");
    Quitter = IMG_Load("./Design/Quitter_Partie.png");


     if(etat == Noir){
            Pion = Black;
         if(Joueur == 0){
         BlitImage(Ordinateur_Passif,Screen,0,0);
         BlitImage(Player_1_Actif,Screen,0,0);}
         if(Joueur == 1){
         BlitImage(Player_2_Passif,Screen,0,0);
         BlitImage(Player_1_Actif,Screen,0,0);}
         else if ( Joueur == 2){
         BlitImage(Player_1_Passif,Screen,0,0);
         BlitImage(Player_2_Actif,Screen,0,0);
         }
        }
     if(etat == Blanc){
         Pion = White;
         if(Joueur == 0){
         BlitImage(Ordinateur_Passif,Screen,0,0);
         BlitImage(Player_1_Actif,Screen,0,0);}
         if(Joueur == 1){
         BlitImage(Player_2_Passif,Screen,0,0);
         BlitImage(Player_1_Actif,Screen,0,0);}
         else if ( Joueur == 2){
         BlitImage(Player_1_Passif,Screen,0,0);
         BlitImage(Player_2_Actif,Screen,0,0);
         }
     }
 while(flag){

       SDL_WaitEvent(&mEvent);
       switch(mEvent.type){
       case SDL_QUIT:
           flag=0;
           exit(0);
            break;
      case SDL_MOUSEMOTION:
            x = mEvent.motion.x;
            y = mEvent.motion.y;
            if(x>123&&x<264&&y>675&&y<732)
                BlitImage(Fleche_Inverse,Screen,260,700);
           else BlitImage(Menu_Table,Screen,0,0);
           break;
       case SDL_MOUSEBUTTONUP:
            x = mEvent.button.x;
            y = mEvent.button.y;
            if(x>123&&x<264&&y>675&&y<732){
                BlitImage(Quitter,Screen,0,0);
                int flag=1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                                case SDL_MOUSEBUTTONUP:
                                     x = mEvent.button.x;
                                     y = mEvent.button.y;
                                    if(x>452&&x<514&&y>419&&y<459)
                                        return 1;
                                    if(x>738&&x<816&&y>420&&y<460){
                                            BlitImage(Table,Screen,0,0);
                                             if(etat == Noir){
            //Pion = Black;
                                                      if(Joueur == 0){
                                                          BlitImage(Ordinateur_Passif,Screen,0,0);
                                                          BlitImage(Player_Actif,Screen,0,0);}
                                                      if(Joueur == 1){
                                                          BlitImage(Player_2_Passif,Screen,0,0);
                                                          BlitImage(Player_1_Actif,Screen,0,0);}
                                                      else if ( Joueur == 2){
                                                          BlitImage(Player_1_Passif,Screen,0,0);
                                                          BlitImage(Player_2_Actif,Screen,0,0);
                                                                 }
                                                            }
                                            if(etat == Blanc){
        // Pion = White;
                                                       if(Joueur == 0){
                                                           BlitImage(Ordinateur_Passif,Screen,0,0);
                                                           BlitImage(Player_Actif,Screen,0,0);}
                                                        if(Joueur == 1){
                                                            BlitImage(Player_2_Passif,Screen,0,0);
                                                            BlitImage(Player_1_Actif,Screen,0,0);}
                                                        else if ( Joueur == 2){
                                                            BlitImage(Player_1_Passif,Screen,0,0);
                                                            BlitImage(Player_2_Actif,Screen,0,0);
                                                                     }
                                                              }
                                            for(i=0;i<9;i++)
                                                for(j=0;j<9;j++)
                                                {
                                                    if(Hex[i][j].etat==Noir)
                                                        BlitImage(Black,Screen,Pos_Pion[i][j].x,Pos_Pion[i][j].y);
                                                    if(Hex[i][j].etat==Blanc)
                                                    BlitImage(White,Screen,Pos_Pion[i][j].x,Pos_Pion[i][j].y);

                                                }
                                             flag=0;
                                            }

                                            break;
                        }
                    }
    }
            for(i=0;i<9;i++) for(j=0;j<9;j++)
                 if((x<=Pos_Pion[i][j].x+49&&x>=Pos_Pion[i][j].x+5)&&(y<=Pos_Pion[i][j].y+42&&y>=Pos_Pion[i][j].y+11)&&(Hex[i][j].etat==Vide)){
                    BlitImage(Pion,Screen,Pos_Pion[i][j].x,Pos_Pion[i][j].y);
                    Hex[i][j].etat=etat;
                    flag=0;
                    }
            break;
       }

  }
   /*SDL_FreeSurface(Black);
   SDL_FreeSurface(White);*/
   SDL_FreeSurface(Pion);
   SDL_FreeSurface(Menu_Table);
   SDL_FreeSurface(Player_1_Actif);
   SDL_FreeSurface(Player_1_Passif);
   SDL_FreeSurface(Player_2_Actif);
   SDL_FreeSurface(Player_2_Passif);
return 0;
}

int TestJoueur1(int i,int j,Cellule Hex_test[9][9]){
    Hex[i][j].teste = 1 ;
    if(i == 8) return 1;

    if(i == 0 && j == 0){
    if(Hex_test[i][j+1].etat == Noir && Hex_test[i][j+1].teste != 1){
            if(TestJoueur1(i,j+1,Hex_test)) return 1;}
    if(Hex_test[i+1][j].etat == Noir && Hex_test[i+1][j].teste != 1){
            if(TestJoueur1(i+1,j,Hex_test)) return 1;
            }
        }
    else if(i == 0 && j == 8){
    if(Hex_test[i+1][j-1].etat == Noir && Hex_test[i+1][j-1].teste != 1)
            if(TestJoueur1(i+1,j-1,Hex_test)) return 1;
    if(Hex_test[i][j-1].etat == Noir && Hex_test[i][j-1].teste != 1)
            if(TestJoueur1(i,j-1,Hex_test)) return 1;
    if(Hex_test[i+1][j].etat == Noir && Hex_test[i+1][j].teste != 1)
            if(TestJoueur1(i+1,j,Hex_test)) return 1;
    }
    else if(j == 0 && i !=0){
          if(Hex_test[i][j+1].etat == Noir && Hex_test[i][j+1].teste != 1){
          if(TestJoueur1(i,j+1,Hex_test)) return 1;}
          if(Hex_test[i+1][j].etat == Noir && Hex_test[i+1][j].teste != 1){
          if(TestJoueur1(i+1,j,Hex_test)) return 1;}
          if(Hex_test[i-1][j+1].etat == Noir && Hex_test[i-1][j+1].teste != 1){
          if(TestJoueur1(i-1,j+1,Hex_test)) return 1;}

    }
    else if(j == 8 && i != 0){
            if(Hex_test[i+1][j].etat == Noir && Hex_test[i+1][j].teste != 1){
          if(TestJoueur1(i+1,j,Hex_test)) return 1;}
          if(Hex_test[i+1][j-1].etat == Noir && Hex_test[i+1][j-1].teste != 1){
          if(TestJoueur1(i+1,j-1,Hex_test)) return 1;}
        if(Hex_test[i][j-1].etat == Noir && Hex_test[i][j-1].teste != 1){
          if(TestJoueur1(i,j-1,Hex_test)) return 1;}
        if(Hex_test[i-1][j].etat == Noir && Hex_test[i-1][j].teste != 1){
            if(TestJoueur1(i-1,j,Hex_test)) return 1;}
    }
    else{
    if(Hex_test[i][j+1].etat == Noir && Hex_test[i][j+1].teste != 1){
          if(TestJoueur1(i,j+1,Hex_test)) return 1;}
    if(Hex_test[i+1][j].etat == Noir && Hex_test[i+1][j].teste != 1){
          if(TestJoueur1(i+1,j,Hex_test)) return 1;}
    if(Hex_test[i+1][j-1].etat == Noir && Hex_test[i+1][j-1].teste != 1){

          if(TestJoueur1(i+1,j-1,Hex_test)) return 1;}
    if(Hex_test[i][j-1].etat == Noir && Hex_test[i][j-1].teste != 1){
          if(TestJoueur1(i,j-1,Hex_test)) return 1;}
    }
            Hex_test[i][j].teste=0;
return 0 ;
}

int TestJoueur2(int i , int j,Cellule Hex_test[9][9]){
      Hex[i][j].teste = 1;
    if(j==8)  return 1 ;

   if(i==0&&j==0){
     if(Hex_test[i][j+1].etat == Blanc && Hex_test[i][j+1].teste != 1){
          if(TestJoueur2(i,j+1,Hex_test)) return 1;}
           if(Hex_test[i+1][j].etat == Blanc && Hex_test[i+1][j].teste != 1){
          if(TestJoueur2(i+1,j,Hex_test)) return 1;}
          }
   else if(i==8&&j==0){
     if(Hex_test[i][j+1].etat == Blanc&& Hex_test[i][j+1].teste != 1){
          if(TestJoueur2(i,j+1,Hex_test)) return 1;}
     if(Hex_test[i-1][j+1].etat == Blanc && Hex_test[i-1][j+1].teste != 1){
          if(TestJoueur2(i-1,j+1,Hex_test)) return 1;}
      if(Hex_test[i-1][j].etat == Blanc && Hex_test[i-1][j].teste != 1){
          if(TestJoueur2(i-1,j,Hex_test)) return 1;}
   }
   else if(i==0&&j!=0){
       if(Hex_test[i][j+1].etat == Blanc && Hex_test[i][j+1].teste != 1){
          if(TestJoueur2(i,j+1,Hex_test)) return 1;}
         if(Hex_test[i][j-1].etat == Blanc && Hex_test[i][j-1].teste != 1){
          if(TestJoueur2(i,j-1,Hex_test)) return 1;}
     if(Hex_test[i+1][j].etat == Blanc && Hex_test[i+1][j].teste != 1){
          if(TestJoueur2(i+1,j,Hex_test)) return 1;}
      if(Hex_test[i+1][j-1].etat == Blanc && Hex_test[i+1][j-1].teste != 1){
          if(TestJoueur2(i+1,j-1,Hex_test)) return 1;}
   }
   else if(i==8&&j!=0){
     if(Hex_test[i][j+1].etat == Blanc && Hex_test[i][j+1].teste != 1){
          if(TestJoueur2(i,j+1,Hex_test)) return 1;}
     if(Hex_test[i][j-1].etat == Blanc && Hex_test[i][j-1].teste != 1){
          if(TestJoueur2(i,j-1,Hex_test)) return 1;}
     if(Hex_test[i-1][j].etat == Blanc && Hex_test[i-1][j].teste != 1){
          if(TestJoueur2(i-1,j,Hex_test)) return 1;}
      if(Hex_test[i-1][j+1].etat == Blanc && Hex_test[i-1][j+1].teste != 1){
          if(TestJoueur2(i-1,j+1,Hex_test)) return 1;}
   }
   else{
    if(Hex_test[i][j+1].etat == Blanc && Hex_test[i][j+1].teste != 1){
          if(TestJoueur2(i,j+1,Hex_test)) return 1;}
    if(Hex_test[i+1][j].etat == Blanc && Hex_test[i+1][j].teste != 1){
          if(TestJoueur2(i+1,j,Hex_test)) return 1;}
    if(Hex_test[i+1][j-1].etat == Blanc && Hex_test[i+1][j-1].teste != 1){
          if(TestJoueur2(i+1,j-1,Hex_test)) return 1;}
    if(Hex_test[i][j-1].etat == Blanc && Hex_test[i][j-1].teste != 1){
          if(TestJoueur2(i,j-1,Hex_test)) return 1;}
    if(j!=0){
        if(Hex_test[i-1][j+1].etat == Blanc && Hex_test[i-1][j+1].teste != 1){
            if(TestJoueur2(i-1,j+1,Hex_test)) return 1;}
    if(Hex_test[i-1][j].etat == Blanc && Hex_test[i-1][j].teste != 1){
            if(TestJoueur2(i-1,j,Hex_test)) return 1;}
        }
   }
   Hex_test[i][j].teste = 0;
return 0;
}


int TestNoir(Cellule Hex_test[9][9]){
    int i = 0 , j = 0;
      for(j=0;j<9;j++)
        if(Hex_test[0][j].etat == Noir)
          if(TestJoueur1(0,j,Hex_test)) return 1 ;

return 0 ;
}

int TestBlanc(Cellule Hex_test[9][9]){
    int i = 0 , j = 0 ;
      for(i=0;i<9;i++)
         if(Hex[i][0].etat == Blanc)
            if(TestJoueur2(i,0,Hex_test)) return 1 ;
return 0 ;
}

int Joueur_Ordinateur1( Etat etat , SDL_Surface *Screen , SDL_Surface *Table){
    srand(time(NULL));
    int flag = 1 ,i ,j,x,y;
    SDL_Surface *Black = NULL;
    SDL_Surface *White = NULL;
    SDL_Surface *Pion  = NULL;
    SDL_Surface *Player_Passif=NULL;
    SDL_Surface *Ordinateur_Actif=NULL;
    Black = IMG_Load("./Design/pion_noir.png");
    White = IMG_Load("./Design/pion_blanc_1.png");
    SDL_Surface *Menu_Table = NULL;
    Menu_Table = IMG_Load("./Design/Menu_Table.png");
    Player_Passif = IMG_Load("./Design/Joueur_Passif.png");
    Ordinateur_Actif = IMG_Load("./Design/Ordinateur_Actif.png");
    BlitImage(Player_Passif,Screen,0,0);
    BlitImage(Ordinateur_Actif,Screen,0,0);
     if(etat == Noir)
            Pion = Black;
     if(etat == Blanc)
         Pion = White;
    while(flag){
            SDL_PollEvent(&mEvent);
       switch(mEvent.type){
       case SDL_QUIT:
           flag=0;
           exit(0);
            break;
      case SDL_MOUSEMOTION:
            x = mEvent.motion.x;
            y = mEvent.motion.y;
            if(x>123&&x<264&&y>675&&y<732)
                BlitImage(Fleche_Inverse,Screen,260,700);
           else BlitImage(Menu_Table,Screen,0,0);
           break;}
    SDL_Delay(1000);
    i=rand()%9;
    j=rand()%9;
    if(Hex[i][j].etat==Vide){
            BlitImage(Pion,Screen,Pos_Pion[i][j].x,Pos_Pion[i][j].y);
            Hex[i][j].etat=etat;
            flag=0;
    }
      }
//    Curseur(Black,Screen);
SDL_FreeSurface(Menu_Table);
return 0;
    }


int Simulation(Etat ordi_etat,Etat Joueur_etat,SDL_Surface *Screen,SDL_Surface *Black){
int Nmax=1000,Nnew=0,Nold=100,i,j,iboucle=0,iChemin,jchemin,flag,vide=0,Test;
Cellule Hex_machine[9][9];
debut:
while(iboucle<Nmax){
    for(i=0;i<9;i++) {
            for(j=0;j<9;j++) {
                Hex_machine[i][j].etat = Hex[i][j].etat;
                Hex_machine[i][j].teste = 0; }}
        Nnew = 0;
        flag = 1;
while(flag){
        srand(time(NULL));
        vide = 0;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
    {
        if(Hex_machine[i][j].etat == Vide){
            vide++;
        }
    }
     if(vide == 0) break;
    do{
    i = rand()%9;
    j = rand()%9;
    }while(Hex_machine[i][j].etat!=Vide);
    Hex_machine[i][j].etat = ordi_etat ;
    Nnew++;
    if(ordi_etat == Noir) Test = TestNoir(Hex_machine);
    if(ordi_etat == Blanc) Test = TestBlanc(Hex_machine);
    if(Test == 1) {
        if(Nold>Nnew){
            iChemin = i ;
            jchemin = j ;
        }
        flag = 0;
    }
    vide = 0;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
    {
        if(Hex_machine[i][j].etat == Vide){
            vide++;
        }
    }
    if(vide == 0) break;
    do{
    i = rand()%9;
    j = rand()%9;
    }while(Hex_machine[i][j].etat!=Vide);
    Hex_machine[i][j].etat = Joueur_etat;
    if(Joueur_etat == Noir) Test = TestNoir(Hex_machine);
    if(Joueur_etat == Blanc) Test = TestBlanc(Hex_machine);
    if(Test == 1) flag = 0;

}
Nold = Nnew ;
iboucle++;
}
if(iChemin>8||jchemin>8){
        do{
    iChemin = rand()%9;
    jchemin = rand()%9;
        }while(Hex[iChemin][jchemin].etat!=Vide);
}
 BlitImage(Black,Screen,Pos_Pion[iChemin][jchemin].x,Pos_Pion[iChemin][jchemin].y);
  Hex[iChemin][jchemin].etat = Noir;
return 0;
}

int Joueur_Ordinateur2( Etat Ordi ,Etat Joueur, SDL_Surface *Screen , SDL_Surface *Table){
    srand(time(NULL));
    int flag = 1 ,i ,j,x,y;
    SDL_Rect Pos_pion_sim;
    SDL_Surface *Black = NULL;
    SDL_Surface *White = NULL;
    SDL_Surface *Pion  = NULL;
    SDL_Surface *Player_Passif=NULL;
    SDL_Surface *Ordinateur_Actif=NULL;
    Black = IMG_Load("./Design/pion_noir.png");
    White = IMG_Load("./Design/pion_blanc_1.png");
    SDL_Surface *Menu_Table = NULL;
    Menu_Table = IMG_Load("./Design/Menu_Table.png");
    Player_Passif = IMG_Load("./Design/Joueur_Passif.png");
    Ordinateur_Actif = IMG_Load("./Design/Ordinateur_Actif.png");
    BlitImage(Player_Passif,Screen,0,0);
    BlitImage(Ordinateur_Actif,Screen,0,0);
     if(Ordi == Noir)
            Pion = Black;
     if(Ordi == Blanc)
         Pion = White;
    while(flag){
            SDL_PollEvent(&mEvent);
       switch(mEvent.type){
       case SDL_QUIT:
           flag=0;
           exit(0);
            break;
      case SDL_MOUSEMOTION:
            x = mEvent.motion.x;
            y = mEvent.motion.y;
            if(x>123&&x<264&&y>675&&y<732)
                BlitImage(Fleche_Inverse,Screen,260,700);
           else BlitImage(Menu_Table,Screen,0,0);
           break;}
    }
    Simulation(Ordi,Joueur,Screen,Black);

return 0;
    }

void Initialisation(SDL_Rect Pos_Pion[9][9]){
    Pos_Pion[0][0].x = 66 ;
    Pos_Pion[0][0].y = 55 ;
    Pos_Pion[0][1].x = Pos_Pion[0][0].x + 86 ;
    Pos_Pion[0][1].y = Pos_Pion[0][0].y ;
    Pos_Pion[0][2].x = Pos_Pion[0][1].x + 86 ;
    Pos_Pion[0][2].y = Pos_Pion[0][1].y ;
    Pos_Pion[0][3].x = Pos_Pion[0][2].x + 86 ;
    Pos_Pion[0][3].y = Pos_Pion[0][2].y ;
    Pos_Pion[0][4].x = Pos_Pion[0][3].x + 86 ;
    Pos_Pion[0][4].y = Pos_Pion[0][3].y ;
    Pos_Pion[0][5].x = Pos_Pion[0][4].x + 86 ;
    Pos_Pion[0][5].y = Pos_Pion[0][4].y ;
    Pos_Pion[0][6].x = Pos_Pion[0][5].x + 86 ;
    Pos_Pion[0][6].y = Pos_Pion[0][5].y ;
    Pos_Pion[0][7].x = Pos_Pion[0][6].x + 86 ;
    Pos_Pion[0][7].y = Pos_Pion[0][6].y ;
    Pos_Pion[0][8].x = Pos_Pion[0][7].x + 86 ;
    Pos_Pion[0][8].y = Pos_Pion[0][7].y ;

    Pos_Pion[1][0].x = 110 ;
    Pos_Pion[1][0].y = 132 ;
    Pos_Pion[1][1].x = Pos_Pion[1][0].x + 86 ;
    Pos_Pion[1][1].y = Pos_Pion[1][0].y ;
    Pos_Pion[1][2].x = Pos_Pion[1][1].x + 86 ;
    Pos_Pion[1][2].y = Pos_Pion[1][1].y ;
    Pos_Pion[1][3].x = Pos_Pion[1][2].x + 86 ;
    Pos_Pion[1][3].y = Pos_Pion[1][2].y ;
    Pos_Pion[1][4].x = Pos_Pion[1][3].x + 86 ;
    Pos_Pion[1][4].y = Pos_Pion[1][3].y ;
    Pos_Pion[1][5].x = Pos_Pion[1][4].x + 86 ;
    Pos_Pion[1][5].y = Pos_Pion[1][4].y ;
    Pos_Pion[1][6].x = Pos_Pion[1][5].x + 86 ;
    Pos_Pion[1][6].y = Pos_Pion[1][5].y ;
    Pos_Pion[1][7].x = Pos_Pion[1][6].x + 86;
    Pos_Pion[1][7].y = Pos_Pion[1][6].y ;
    Pos_Pion[1][8].x = Pos_Pion[1][7].x + 86 ;
    Pos_Pion[1][8].y = Pos_Pion[1][7].y ;

    Pos_Pion[2][0].x = 152 ;
    Pos_Pion[2][0].y = 209 ;
    Pos_Pion[2][1].x = Pos_Pion[2][0].x + 86 ;
    Pos_Pion[2][1].y = Pos_Pion[2][0].y ;
    Pos_Pion[2][2].x = Pos_Pion[2][1].x + 86 ;
    Pos_Pion[2][2].y = Pos_Pion[2][1].y ;
    Pos_Pion[2][3].x = Pos_Pion[2][2].x + 86 ;
    Pos_Pion[2][3].y = Pos_Pion[2][2].y ;
    Pos_Pion[2][4].x = Pos_Pion[2][3].x + 86 ;
    Pos_Pion[2][4].y = Pos_Pion[2][3].y ;
    Pos_Pion[2][5].x = Pos_Pion[2][4].x + 86 ;
    Pos_Pion[2][5].y = Pos_Pion[2][4].y ;
    Pos_Pion[2][6].x = Pos_Pion[2][5].x + 86 ;
    Pos_Pion[2][6].y = Pos_Pion[2][5].y ;
    Pos_Pion[2][7].x = Pos_Pion[2][6].x + 86;
    Pos_Pion[2][7].y = Pos_Pion[2][6].y ;
    Pos_Pion[2][8].x = Pos_Pion[2][7].x + 86 ;
    Pos_Pion[2][8].y = Pos_Pion[2][7].y ;

    Pos_Pion[3][0].x = 195 ;
    Pos_Pion[3][0].y = 286 ;
    Pos_Pion[3][1].x = Pos_Pion[3][0].x + 86 ;
    Pos_Pion[3][1].y = Pos_Pion[3][0].y ;
    Pos_Pion[3][2].x = Pos_Pion[3][1].x + 86 ;
    Pos_Pion[3][2].y = Pos_Pion[3][1].y ;
    Pos_Pion[3][3].x = Pos_Pion[3][2].x + 86 ;
    Pos_Pion[3][3].y = Pos_Pion[3][2].y ;
    Pos_Pion[3][4].x = Pos_Pion[3][3].x + 86 ;
    Pos_Pion[3][4].y = Pos_Pion[3][3].y ;
    Pos_Pion[3][5].x = Pos_Pion[3][4].x + 86 ;
    Pos_Pion[3][5].y = Pos_Pion[3][4].y ;
    Pos_Pion[3][6].x = Pos_Pion[3][5].x + 86 ;
    Pos_Pion[3][6].y = Pos_Pion[3][5].y ;
    Pos_Pion[3][7].x = Pos_Pion[3][6].x + 86 ;
    Pos_Pion[3][7].y = Pos_Pion[3][6].y ;
    Pos_Pion[3][8].x = Pos_Pion[3][7].x + 86 ;
    Pos_Pion[3][8].y = Pos_Pion[3][7].y ;

    Pos_Pion[4][0].x = 239 ;
    Pos_Pion[4][0].y = 363 ;
    Pos_Pion[4][1].x = Pos_Pion[4][0].x + 86 ;
    Pos_Pion[4][1].y = Pos_Pion[4][0].y ;
    Pos_Pion[4][2].x = Pos_Pion[4][1].x + 86 ;
    Pos_Pion[4][2].y = Pos_Pion[4][1].y ;
    Pos_Pion[4][3].x = Pos_Pion[4][2].x + 86 ;
    Pos_Pion[4][3].y = Pos_Pion[4][2].y ;
    Pos_Pion[4][4].x = Pos_Pion[4][3].x + 86 ;
    Pos_Pion[4][4].y = Pos_Pion[4][3].y ;
    Pos_Pion[4][5].x = Pos_Pion[4][4].x + 86 ;
    Pos_Pion[4][5].y = Pos_Pion[4][4].y ;
    Pos_Pion[4][6].x = Pos_Pion[4][5].x + 86 ;
    Pos_Pion[4][6].y = Pos_Pion[4][5].y ;
    Pos_Pion[4][7].x = Pos_Pion[4][6].x + 86 ;
    Pos_Pion[4][7].y = Pos_Pion[4][6].y ;
    Pos_Pion[4][8].x = Pos_Pion[4][7].x + 86 ;
    Pos_Pion[4][8].y = Pos_Pion[4][7].y ;

    Pos_Pion[5][0].x = 281 ;
    Pos_Pion[5][0].y = 440 ;
    Pos_Pion[5][1].x = Pos_Pion[5][0].x + 86 ;
    Pos_Pion[5][1].y = Pos_Pion[5][0].y ;
    Pos_Pion[5][2].x = Pos_Pion[5][1].x + 87 ;
    Pos_Pion[5][2].y = Pos_Pion[5][1].y ;
    Pos_Pion[5][3].x = Pos_Pion[5][2].x + 86 ;
    Pos_Pion[5][3].y = Pos_Pion[5][2].y ;
    Pos_Pion[5][4].x = Pos_Pion[5][3].x + 86 ;
    Pos_Pion[5][4].y = Pos_Pion[5][3].y ;
    Pos_Pion[5][5].x = Pos_Pion[5][4].x + 86 ;
    Pos_Pion[5][5].y = Pos_Pion[5][4].y ;
    Pos_Pion[5][6].x = Pos_Pion[5][5].x + 86 ;
    Pos_Pion[5][6].y = Pos_Pion[5][5].y ;
    Pos_Pion[5][7].x = Pos_Pion[5][6].x + 86 ;
    Pos_Pion[5][7].y = Pos_Pion[5][6].y ;
    Pos_Pion[5][8].x = Pos_Pion[5][7].x + 86 ;
    Pos_Pion[5][8].y = Pos_Pion[5][7].y ;

    Pos_Pion[6][0].x = 324 ;
    Pos_Pion[6][0].y = 517 ;
    Pos_Pion[6][1].x = Pos_Pion[6][0].x + 86 ;
    Pos_Pion[6][1].y = Pos_Pion[6][0].y ;
    Pos_Pion[6][2].x = Pos_Pion[6][1].x + 87 ;
    Pos_Pion[6][2].y = Pos_Pion[6][1].y ;
    Pos_Pion[6][3].x = Pos_Pion[6][2].x + 86 ;
    Pos_Pion[6][3].y = Pos_Pion[6][2].y ;
    Pos_Pion[6][4].x = Pos_Pion[6][3].x + 86 ;
    Pos_Pion[6][4].y = Pos_Pion[6][3].y ;
    Pos_Pion[6][5].x = Pos_Pion[6][4].x + 86 ;
    Pos_Pion[6][5].y = Pos_Pion[6][4].y ;
    Pos_Pion[6][6].x = Pos_Pion[6][5].x + 86 ;
    Pos_Pion[6][6].y = Pos_Pion[6][5].y ;
    Pos_Pion[6][7].x = Pos_Pion[6][6].x + 86 ;
    Pos_Pion[6][7].y = Pos_Pion[6][6].y ;
    Pos_Pion[6][8].x = Pos_Pion[6][7].x + 86 ;
    Pos_Pion[6][8].y = Pos_Pion[6][7].y ;

    Pos_Pion[7][0].x = 367 ;
    Pos_Pion[7][0].y = 594 ;
    Pos_Pion[7][1].x = Pos_Pion[7][0].x + 86 ;
    Pos_Pion[7][1].y = Pos_Pion[7][0].y ;
    Pos_Pion[7][2].x = Pos_Pion[7][1].x + 87 ;
    Pos_Pion[7][2].y = Pos_Pion[7][1].y ;
    Pos_Pion[7][3].x = Pos_Pion[7][2].x + 86 ;
    Pos_Pion[7][3].y = Pos_Pion[7][2].y ;
    Pos_Pion[7][4].x = Pos_Pion[7][3].x + 86 ;
    Pos_Pion[7][4].y = Pos_Pion[7][3].y ;
    Pos_Pion[7][5].x = Pos_Pion[7][4].x + 86 ;
    Pos_Pion[7][5].y = Pos_Pion[7][4].y ;
    Pos_Pion[7][6].x = Pos_Pion[7][5].x + 86 ;
    Pos_Pion[7][6].y = Pos_Pion[7][5].y ;
    Pos_Pion[7][7].x = Pos_Pion[7][6].x + 86;
    Pos_Pion[7][7].y = Pos_Pion[7][6].y ;
    Pos_Pion[7][8].x = Pos_Pion[7][7].x + 86 ;
    Pos_Pion[7][8].y = Pos_Pion[7][7].y ;

    Pos_Pion[8][0].x = 410 ;
    Pos_Pion[8][0].y = 671 ;
    Pos_Pion[8][1].x = Pos_Pion[8][0].x + 86 ;
    Pos_Pion[8][1].y = Pos_Pion[8][0].y ;
    Pos_Pion[8][2].x = Pos_Pion[8][1].x + 87 ;
    Pos_Pion[8][2].y = Pos_Pion[8][1].y ;
    Pos_Pion[8][3].x = Pos_Pion[8][2].x + 86 ;
    Pos_Pion[8][3].y = Pos_Pion[8][2].y ;
    Pos_Pion[8][4].x = Pos_Pion[8][3].x + 86 ;
    Pos_Pion[8][4].y = Pos_Pion[8][3].y ;
    Pos_Pion[8][5].x = Pos_Pion[8][4].x + 86 ;
    Pos_Pion[8][5].y = Pos_Pion[8][4].y ;
    Pos_Pion[8][6].x = Pos_Pion[8][5].x + 86 ;
    Pos_Pion[8][6].y = Pos_Pion[8][5].y ;
    Pos_Pion[8][7].x = Pos_Pion[8][6].x + 86 ;
    Pos_Pion[8][7].y = Pos_Pion[8][6].y ;
    Pos_Pion[8][8].x = Pos_Pion[8][7].x + 86 ;
    Pos_Pion[8][8].y = Pos_Pion[8][6].y ;
}
