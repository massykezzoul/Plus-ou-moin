#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Info Info;
struct Info {
  char nom[50];
  char prenom[50];
};

void LecturePlayers(Info players[] ,int nombrePlayers);

int main(int argc, char const *argv[]) { // peut s'ecrire "int main ()"
        srand(time(NULL)); //à faire q'une seule fois dans un programme !
        int reponse = 0,reponse2 = 0, choixMode,choix, compteur=0,compteur2=0,compteur3=0,compteur4=0,MAX, MIN = 1,joueur = 0;
        printf("Jeu du nombre Mystére !\n");
        printf("-----------------------\n");
        do {
          MIN = 1;joueur= 0;
                do {
                        printf("Choisisez le mode de jeux :\n");
                        printf("1-Un seule joueur\n2-Deux joueurs\n");
                        printf("3-Trois joueurs\n4-Quatre joueurs\n");
                        scanf("%d",&choixMode);
                } while(choixMode < 1 || choixMode > 4);
                do {
                        printf("Choisisez le niveau de jeu :\n");
                        printf("1-facile (entre 1 et 100)\n2-Moyen (entre 1 et 1000)\n");
                        printf("3-Difficile (entre 1 et 10000)\n");
                        printf("4-Mode Extreme (impossible)\n");
                        scanf("%d", &choix);
                        if (choix == 1) {
                                MAX = 100;
                                printf("\nVous avez choisie le mode Facile !\n");
                        } else if (choix == 2) {
                                MAX = 1000;
                                printf("\nVous avez choisie le mode Moyen !\n");
                        } else if (choix == 3) {
                                MAX = 10000;
                                printf("\nVous avez choise le mode Difficile !\nBonne chance ! ;)\n");
                        } else if (choix == 4) {
                                MAX = 100000000;
                                printf("\nVous avez choisie le mode Extreme nta mqawed\n");
                        }  else {
                                printf("Choix incorecte '%d' ne figure pas dans la liste\n", choix);
                        }
                } while (choix < 1 || (choix > 4 && choix != 78));
                choix = 0;
                compteur = 0;
                int nombreMystere =(rand() % (MAX - MIN + 1)) + MIN;// Generateur de nombre aléatoire
                if (choixMode == 1) {
                  printf("Le nombre est entre %d et %d\n", MIN, MAX);
                  printf("Quelle est le nombre mystére ?\n");
                        do {
                                compteur++;
                                scanf("%d", &reponse);
                                if (reponse > nombreMystere) {
                                        printf("C'est moins !\n");
                                }
                                if (reponse < nombreMystere) {
                                        printf("C'est plus !\n");
                                }
                                if (reponse == nombreMystere) {
                                        printf("Koulchi Mebrouke ! le nombre mystére étais = %d\n",nombreMystere);
                                        printf("Vous avez fait %d tantative(s)\n", compteur);
                                }
                        } while (reponse != nombreMystere);
                }else{
                  Info players[choixMode-1];
                  LecturePlayers(players,choixMode);

                  compteur2=0;
                  compteur3=0;
                  compteur4=0;
                  printf("Mode %d joueur(s) :\n",choixMode);   // mode multijoueurs
                        do {
                          joueur++;
                          printf("À %s %s de jouer :\n",players[joueur-1].prenom,players[joueur-1].nom );
                          printf("Le nombre est entre %d et %d\n", MIN, MAX);
                          printf("Quelle est le nombre mystére ?\n");
                          scanf("%d", &reponse);
                          if (reponse > nombreMystere) {
                                  printf("C'est moins !\n");
                                  if (MAX > reponse){
                                  MAX = reponse;
                                  getchar();
                                }
                          }
                          if (reponse < nombreMystere) {
                                  printf("C'est plus !\n");
                                  if (MIN < reponse){
                                  MIN = reponse;
                                  getchar();
                                }
                          }
                          if (reponse == nombreMystere) {
                                  printf("Bravo ! le nombre mystére étais = %d\n",nombreMystere);
                                  if (joueur==1) {
                                    printf("C'est %s %s qui a gagné\n",players[joueur-1].nom,players[joueur-1].prenom );
                                    printf("Vous avez fait %d tantative(s)\n", compteur+1);
                                  }else if (joueur==2) {
                                    printf("C'est %s %s qui a gagné\n",players[joueur-1].nom,players[joueur-1].prenom );
                                    printf("Vous avez fait %d tantative(s)\n", compteur2+1);
                                  }else if (joueur==3){
                                    printf("C'est %s %s qui a gagné\n",players[joueur-1].nom,players[joueur-1].prenom );
                                    printf("Vous avez fait %d tantative(s)\n", compteur3+1);
                                  }else if (joueur==4){
                                    printf("C'est %s %s qui a gagné\n",players[joueur-1].nom,players[joueur-1].prenom );
                                    printf("Vous avez fait %d tantative(s)\n", compteur4+1);
                                  }
                          }
                          switch (joueur) {
                            case 1:compteur++;
                              break;
                            case 2:{
                              compteur2++; if (choixMode==2){joueur=0;}
                            }
                              break;
                            case 3:{
                              compteur3++;if (choixMode==3){joueur=0;}
                            }
                              break;
                            case 4:{compteur4++;joueur=0;}
                          }
                        } while(reponse != nombreMystere);
                }
                while (choix != 1 && choix != 2) {
                        printf("Voulez-vous rejouer ?\n1-Oui\n2-Non\n");
                        scanf("%d", &choix);
                }
        } while (choix == 1);
        printf("Merci d'avoir joué !\n");
        return 0;
}

void LecturePlayers(Info players[] ,int nombrePlayers){
  for (int i = 0; i < nombrePlayers; i++) {
    printf("joueur N°%d Donnez votre nom puis prenom :\n",i+1 );
    scanf("%s%s",players[i].nom ,players[i].prenom);
}
}
