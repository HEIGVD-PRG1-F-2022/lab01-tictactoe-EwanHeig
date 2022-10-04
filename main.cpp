/*
-----------------------------------------------------------------------------------
Nom du fichier  : TikTakToe.cpp
Auteur(s)       : Patrick Maillard, Ewan Bloechle, Guilherme Pinto
Date creation   : 27.09.2022

Description     : Jeux TicTacToe

Remarque(s)     : À exécuter sur la console Windows. (Problème avec le clear)

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>

using namespace std;

void assignation (int valeur,bool mode);
int verifVictoire(int victory);
void affichage (int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9);
char conversion(int c);
void jeuxHumain();
void jeuxRobot();
int nombreAleatoir();

int case1 = 0, case2 = 0, case3 = 0, case4 = 0, case5 = 0, case6 = 0, case7 = 0, case8 = 0, case9 = 0;
int compteur = 0;//compteur de coup en cas de match nul

int main() {
    int choix = 0;
    int jeux = 1;

    cout << "Bonjour,souhaitez vous jouer contre un humain (1) ou un robot (0) ? : " << endl;
    cin >> choix;


    while(jeux){ //boucle tant que le joueur n'as pas fait un choix correct
        jeux = 0; //permet de sortir de la boucle
        if(choix == 1){ //jouer contre un humain
            jeuxHumain();
        }
        else if(choix == 0){ //jouer contre un bot
            jeuxRobot();
        }
        else{ //choix incorrect
            cout << "Veuillez taper 1 pour jouer contre un humain ou 0 contre un robot svp : ";
            cin >> choix;
            jeux = 1; //reste dans la boucle pour refaire un choix
        }
    }

    system("pause");
    return EXIT_SUCCESS;
}

//fonction pour verifier si une case choisi est vide et l'assigner a un joueur
//prend en paramètre valeur nous disant qui a joué entre J1 et J2 ou J1 et bot, ainsi qu'un paramètre mode
//pour savoir si c'est le mode 2 joueurs ou 1 joueur
void assignation ( int valeur,bool mode){
    int numero_case;
    int erreur = 1;
    int nombreHasard;


    if (mode == 1){  //tour du joueur
        cin >> numero_case;

        //boucle tant qu'une case vide n'est pas choisie
        while(erreur){
            //verifie si la case est libre, si oui la remplie, si non demande d'en choisir une autre
            switch (numero_case) {
                case 1: if(case1 == 0){ case1 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 2: if(case2 == 0){ case2 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 3: if(case3 == 0){ case3 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 4: if(case4 == 0){ case4 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 5: if(case5 == 0){ case5 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 6: if(case6 == 0){ case6 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 7: if(case7 == 0){ case7 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 8: if(case8 == 0){ case8 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                case 9: if(case9 == 0){ case9 = valeur;erreur = 0;compteur++;} else{cout<<"case indisponible, rechoisissez : "<<endl; cin>> numero_case;} break;
                default : break;
            }

        }
    }


    else if (mode == 0){ //tour du bot

        //boucle tant qu'une case vide n'est pas choisie
        cout<<"le bot Choisis..."<<endl;
        while(erreur){

            //Choisi un nombre au hasard
            nombreHasard = nombreAleatoir();

            //verifie si la case est libre, si oui la remplie, si non en choisir une autre aleatoire
            switch (nombreHasard) {
                case 1: if(case1 == 0){ case1 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 2: if(case2 == 0){ case2 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 3: if(case3 == 0){ case3 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 4: if(case4 == 0){ case4 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 5: if(case5 == 0){ case5 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 6: if(case6 == 0){ case6 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 7: if(case7 == 0){ case7 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 8: if(case8 == 0){ case8 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                case 9: if(case9 == 0){ case9 = valeur;erreur = 0;compteur++;} else{nombreHasard = nombreAleatoir();} break;
                default : break;
            }

        }
    }

}

//fonction pour verifier si la partie est fini ou non
int verifVictoire(int victory){

    int lignes1 = case1 * case2 * case3; //cases composant la 1er ligne
    int lignes2 = case4 * case5 * case6 ; //cases composant la 2eme ligne
    int lignes3 = case7 * case8 * case9; //cases composant la 3eme ligne

    int colonnes1 = case1 * case4 * case7; //cases composant la 1er colonne
    int colonnes2 = case2 * case5 * case8 ; //cases composant la 2eme colonne
    int colonnes3 = case3 * case6 * case9; //cases composant la 3eme colonne

    int diagonale1 = case1 * case5 * case9 ; //cases composant la 1er diagonale
    int diagonale2 = case3 * case5 * case7 ; //cases composant la 2eme diagonale


    //si une des lignes, colonnes ou diagonal est rempli par le joueur 1 (1*1*1=1)
    if (lignes1 == 1||lignes2 == 1||lignes3 == 1||colonnes1 == 1||colonnes2 == 1||colonnes3 == 1||diagonale1 == 1||diagonale2 == 1){
        victory = 1;//victoire du joueur 1
    }
    //sinon si une des lignes, colonnes ou diagonal est rempli par le joueur 2 (2*2*2=8)
    else if (lignes1 == 8||lignes2 == 8||lignes3 == 8||colonnes1 == 8||colonnes2 == 8||colonnes3 == 8||diagonale1 == 8||diagonale2 == 8 ){
        victory = 2;//victoire du joueur 2
    }
    else if(compteur==9){//si 9 coups on été joué
        victory = 3;
    }

    //retourne le joueur victorieux
    return victory ;

}

//fonction d'affichage prenant en paramètre les 9 cases à afficher
void affichage (int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9){

   //Efface la grille précèdente
   system("CLS");
   cout << "Jeu actuel: " << endl;
   //converti les case en X ou O
    char ca1 = conversion(c1);
    char ca2 = conversion(c2);
    char ca3 = conversion(c3);
    char ca4 = conversion(c4);
    char ca5 = conversion(c5);
    char ca6 = conversion(c6);
    char ca7 = conversion(c7);
    char ca8 = conversion(c8);
    char ca9 = conversion(c9);

    //system("CLS");

    //affichage de la grille
    cout << ca1 << " | " << ca2 << " | " << ca3 << endl
         <<"---------"<<endl
         << ca4 << " | " << ca5 << " | " << ca6 << endl
         <<"---------"<<endl
         << ca7 << " | " << ca8 << " | " << ca9 << endl << endl << endl ;

}

//fonction pour converti le contenu des case en X ou O
//prenant en paramètre la case à convertire
char conversion(int c){
    if (c == 1) {return 'X';}//si la case est au J1 affiche un X
    else if (c == 2) {return 'O';}//si la case est au J2 affiche un O
    else {return ' ';}//si la case n'est à personne l'affiche vide
}

//fonction pour 2 joueurs
void jeuxHumain(){

    int victoire = 0;

    //tant que personne n'a gagné
    while (!verifVictoire(victoire)){

        cout<< "J1, Choisisez un chiffre entre 1 et 9 : "<<endl;
        assignation ( 1,1);//le joueur 1 choisis une case et la met dans le jeux si possible
        verifVictoire(victoire);//verifier si le joueur 1 à gagner

        //affiche le tableaux après le tour du J1
        affichage(case1,case2,case3,case4,case5,case6,case7,case8,case9);

        //si le J1 a gagné, sors de la boucle
        if(verifVictoire(victoire)){
            break;
        }

        cout<< "J2, Choisisez un chiffre entre 1 et 9 : "<<endl;
        assignation ( 2,1);//le joueur 2 choisis une case et la met dans le jeux si possible
        verifVictoire(victoire);//verifier si le joueur 2 à gagner

        //affiche le tableaux après le tour du J2
        affichage(case1,case2,case3,case4,case5,case6,case7,case8,case9);

    }
    //message de victoire en fonction du gagnant
    if (verifVictoire(victoire) == 1){
        cout<< "Bravo J1, vous avez gagne ! "<<endl;
    }else if(verifVictoire(victoire) == 2){
        cout<< "Bravo J2, vous avez gagne ! "<<endl;
    }else if(verifVictoire(victoire) == 3){
        cout<< "Match nul"<<endl;
    }

}

//fonction pour 1 joueur
void jeuxRobot(){

    int victoire = 0;

    //tant que personne n'a gagné
    while (!verifVictoire(victoire)){

        cout<< "Choisisez un chiffre entre 1 et 9 : "<<endl;
        assignation ( 1,1);//le joueur choisis une case et la met dans le jeux si possible
        verifVictoire(victoire);//verifier si le joueur à gagner

        //affiche le tableaux après le tour du J1
        affichage(case1,case2,case3,case4,case5,case6,case7,case8,case9);

        //si le joueur a gagné, sors de la boucle
        if(verifVictoire(victoire)){
            break;
        }



        assignation ( 2,0);//le bot choisis une case et la met dans le jeux si possible
        verifVictoire(victoire);//verifier si le bot à gagner

        //affiche le tableaux après le tour du bot
        affichage(case1,case2,case3,case4,case5,case6,case7,case8,case9);

    }

    //message de victoire en fonction du gagnant
    //message de victoire en fonction du gagnant
    if (verifVictoire(victoire) == 1){
        cout<< "Bravo J1, vous avez gagne ! "<<endl;
    }else if(verifVictoire(victoire) == 2){
        cout<< "Dommage, le bot gagne... "<<endl;
    }else if(verifVictoire(victoire) == 3){
        cout<< "Match nul"<<endl;
    }

}

//fonction de nombre aléatoire
int nombreAleatoir(){
    int nombre;
    const int MAX = 9;
    const int MIN = 0;

    //choisi un nombre entre 1 et 9
    srand(time(NULL));
    nombre = (rand() % (MAX - MIN + 1)) + MIN;

    return nombre;
}