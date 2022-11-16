#include "structure.h"
#include "time.h"
#include <stdio.h>
#include <conio.h>

Global lecture_fichier_texte(char *nomFichier) {
    Global informationPlateau;
    int i, j;
    FILE *input = fopen(nomFichier, "r");
    for (i = 0; i < NOMBRE_DE_LIGNE; i++) {
        for (j = 0; j < NOMBRE_DE_COLLONNE; j++) {
            fscanf(input, "%d", &informationPlateau.matriceDuplateau[i][j]);
        }
    }
    return informationPlateau;
}

Global lecture_fichier_texte2(char *nomFichier) {
    Global informationbatiment;
    int i, j;
    FILE *input = fopen(nomFichier, "r");
    for (i = 0; i < 2; i++) {
        fscanf(input,
               "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",
               &informationbatiment.route.type, &informationbatiment.route.ligne, &informationbatiment.route.colonne,
               &informationbatiment.route.habitants, &informationbatiment.route.prix,
               &informationbatiment.canalisation.type, &informationbatiment.canalisation.ligne,
               &informationbatiment.canalisation.colonne, &informationbatiment.canalisation.habitants,
               &informationbatiment.canalisation.prix,
               &informationbatiment.ligneelectrique.type, &informationbatiment.ligneelectrique.ligne,
               &informationbatiment.ligneelectrique.colonne, &informationbatiment.ligneelectrique.habitants,
               &informationbatiment.ligneelectrique.prix,
               &informationbatiment.cabane.type, &informationbatiment.cabane.ligne,
               &informationbatiment.cabane.colonne, &informationbatiment.cabane.habitants,
               &informationbatiment.cabane.prix,
               &informationbatiment.maison.type, &informationbatiment.maison.ligne,
               &informationbatiment.maison.colonne, &informationbatiment.maison.habitants,
               &informationbatiment.maison.prix,
               &informationbatiment.immeuble.type, &informationbatiment.immeuble.ligne,
               &informationbatiment.immeuble.colonne, &informationbatiment.immeuble.habitants,
               &informationbatiment.immeuble.prix,
               &informationbatiment.gratteciel.type, &informationbatiment.gratteciel.ligne,
               &informationbatiment.gratteciel.colonne, &informationbatiment.gratteciel.habitants,
               &informationbatiment.gratteciel.prix,
               &informationbatiment.chateaueau.type, &informationbatiment.chateaueau.ligne,
               &informationbatiment.chateaueau.colonne, &informationbatiment.chateaueau.habitants,
               &informationbatiment.chateaueau.prix,
               &informationbatiment.centraleelectrique.type, &informationbatiment.centraleelectrique.ligne,
               &informationbatiment.centraleelectrique.colonne, &informationbatiment.centraleelectrique.habitants,
               &informationbatiment.centraleelectrique.prix,
               &informationbatiment.terrainvague.type, &informationbatiment.terrainvague.ligne,
               &informationbatiment.terrainvague.colonne, &informationbatiment.terrainvague.habitants,
               &informationbatiment.terrainvague.prix);

    }

    return informationbatiment;

}

Global sauvegarde_information_joueur(Global joueur) {

    FILE *fichier = fopen("sauvegardeinformationJoueur.txt", "w");

    int argent, nombrehabitantsdeLavville;

    nombrehabitantsdeLavville = joueur.joueur.nombrehabitantsdelaville;
    argent = joueur.joueur.argent;
    fscanf(fichier, "%d %d", &argent, &nombrehabitantsdeLavville);
    fprintf(fichier, "%d\n", argent);
    fprintf(fichier, "%d\n", nombrehabitantsdeLavville);
    return joueur;
}

/*Global temps( Global joueur){

    time_t mtn = time(NULL);

    char *string_mtn = ctime(&mtn);

    while (joueur.joueur.argent !=0){
        printf("%s\n",string_mtn);
        if((long )(string_mtn)%15 ==0){
            joueur.joueur.argent = joueur.joueur.argent *joueur.joueur.nombrehabitantsdelaville;
            printf("Vous avez %d\n",joueur.joueur.argent);
        }
    }
    return joueur;


}*/
int verificateur_argent(Global joueur1,int type){

    Global information;
    if(type == 1){
        if((joueur1.joueur.argent -= information.route.prix)<=0){
            printf("Vous n'avez pas les fond necessaire veuillez saisir un autre type de batiment\n");
            scanf("%d\n",&type);
        }
    }
    if(type == 8){
        joueur1.joueur.argent = joueur1.joueur.argent-information.chateaueau.prix;
        int aeffacer;
        aeffacer = joueur1.joueur.argent;
        if((aeffacer)<=0){
            printf("Vous n'avez pas les fond necessaire veuillez saisir un autre type de batiment\n");
            scanf("%d\n",&type);
        }
    }
    if(type == 9){
        if((joueur1.joueur.argent -= information.centraleelectrique.prix)<0){
            printf("Vous n'avez pas les fond necessaire veuillez saisir un autre type de batiment\n");
            scanf("%d\n",&type);
        }
    }
    return type;



}
void jeu() {


    int k, l;
    Global informationBatiment;
    Global informationPlateau;
    Global joueur1;
    //temps(joueur1);
    joueur1.joueur.argent = 500000;
    joueur1.joueur.nombrehabitantsdelaville = 0;
    //temps(joueur1);

    informationPlateau = lecture_fichier_texte("plateauniveau0.txt");
    informationBatiment = lecture_fichier_texte2("informationglobal");
    printf("***************************** MatricePlateau *************************\n\n");


    for (k = 0; k < NOMBRE_DE_LIGNE; k++) {
        printf("\n");
        for (l = 0; l < NOMBRE_DE_COLLONNE; l++) {
            printf("%d ", informationPlateau.matriceDuplateau[k][l]);
        }


    }
    printf("\n\n*********************** Information de base ***********************\n");
    printf("\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d\n",
           informationBatiment.route.type, informationBatiment.route.ligne, informationBatiment.route.colonne,
           informationBatiment.route.habitants, informationBatiment.route.prix,
           informationBatiment.canalisation.type, informationBatiment.canalisation.ligne,
           informationBatiment.canalisation.colonne, informationBatiment.canalisation.habitants,
           informationBatiment.canalisation.prix,
           informationBatiment.ligneelectrique.type, informationBatiment.ligneelectrique.ligne,
           informationBatiment.ligneelectrique.colonne, informationBatiment.ligneelectrique.habitants,
           informationBatiment.ligneelectrique.prix,
           informationBatiment.cabane.type, informationBatiment.cabane.ligne,
           informationBatiment.cabane.colonne, informationBatiment.cabane.habitants, informationBatiment.cabane.prix,
           informationBatiment.maison.type, informationBatiment.maison.ligne,
           informationBatiment.maison.colonne, informationBatiment.maison.habitants, informationBatiment.maison.prix,
           informationBatiment.immeuble.type, informationBatiment.immeuble.ligne,
           informationBatiment.immeuble.colonne, informationBatiment.immeuble.habitants,
           informationBatiment.immeuble.prix,
           informationBatiment.gratteciel.type, informationBatiment.gratteciel.ligne,
           informationBatiment.gratteciel.colonne, informationBatiment.gratteciel.habitants,
           informationBatiment.gratteciel.prix,
           informationBatiment.chateaueau.type, informationBatiment.chateaueau.ligne,
           informationBatiment.chateaueau.colonne, informationBatiment.chateaueau.habitants,
           informationBatiment.chateaueau.prix,
           informationBatiment.centraleelectrique.type, informationBatiment.centraleelectrique.ligne,
           informationBatiment.centraleelectrique.colonne, informationBatiment.centraleelectrique.habitants,
           informationBatiment.centraleelectrique.prix,
           informationBatiment.terrainvague.type, informationBatiment.terrainvague.ligne,
           informationBatiment.terrainvague.colonne, informationBatiment.terrainvague.habitants,
           informationBatiment.terrainvague.prix);

    FILE *inpute = fopen("sauvegardetemporaire.txt", "w");
    int type;
    int position1horzontal, position2verticale;
    while (joueur1.joueur.argent > 0) {


        printf("Que voulez vous poser ?\n");

        if (time(NULL) / 15 == 0) {
            joueur1.joueur.argent = joueur1.joueur.argent + 10 * joueur1.joueur.nombrehabitantsdelaville;
            printf("Vous avez %d argent car vous avez finit un cucle\n", joueur1.joueur.argent);
        }
        scanf("%d", &type);
        //int nv;
        //nv = verificateur_argent(joueur1,type);
        if (type == 1) {
            printf("Vous allez poser une route.\n");
        }
        if (type == 2) {
            printf("Vous allez poser une canalisation.\n");
        }
        if (type == 3) {
            printf("Vous allez poser une ligne electrique.\n");
        }

        if (type == 4) {
            printf("vous allez poser une cabane.\n ");
        }
        if (type == 5) {
            printf("Vous allez poser une maison.\n");
        }
        if (type == 6) {
            printf("Vous allez poser un immeuble.\n");
        }
        if (type == 7) {
            printf("Vous allez poser un gratte ciel.\n");
        }
        if (type == 8) {
            printf("Vous allez poser un chateau d'eau.\n");
        }
        if (type == 9) {
            printf("Vous allez poser une centrale electrque.\n");
        }
        printf("Quelle position collonne ligne?\n");
        scanf("%d %d", &position1horzontal, &position2verticale);
        int variable;
        variable = type;
        FILE *input = fopen("sauvegardetemporaire.txt", "w");


        for (int i = 0; i < NOMBRE_DE_LIGNE; i++) {

            for (int j = 0; j < NOMBRE_DE_COLLONNE; j++) {
                if (position1horzontal == i && position2verticale == j) {
                    if (type == 1) {
                        int nbderouteverticale;
                        int nbroutehorizontal;
                        printf("Combien de route voulez vous posez sur la vertical ?\n");
                        scanf("%d",&nbderouteverticale);
                        printf("Combien de route voulez vous poser sur l'horizontal ?\n");
                        scanf("%d",&nbroutehorizontal);
                        while (informationPlateau.matriceDuplateau[position1horzontal][position2verticale] != 0){
                            printf("Il y deja une infrastructure choissisez une autre position\n ");
                            scanf("%d %d",&position1horzontal,&position2verticale);
                        }
                        joueur1.joueur.argent -= nbderouteverticale *informationBatiment.route.prix +nbroutehorizontal*informationBatiment.route.prix;
                        printf("Vous avez %d habitants dans votre ville\n", nbderouteverticale*joueur1.joueur.nombrehabitantsdelaville);
                        printf("Vous disposez de %d ECE_Flouz\n", joueur1.joueur.argent);

                        for (int m = position1horzontal;m < position1horzontal + nbderouteverticale*informationBatiment.route.ligne; m++) {
                            for (int n = position2verticale;n < position2verticale + nbroutehorizontal*informationBatiment.route.colonne; n++) {
                                variable = type;


                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 2) {
                            while (informationPlateau.matriceDuplateau[position1horzontal][position2verticale] != 0) {
                                printf("Il y deja une infrastructure choissisez une autre position\n ");
                                scanf("%d %d", &position1horzontal, &position2verticale);
                            }
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.canalisation.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.canalisation.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.canalisation.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 3) {
                        while (informationPlateau.matriceDuplateau[position1horzontal][position2verticale] != 0) {
                            printf("Il y deja une infrastructure choissisez une autre position\n ");
                            scanf("%d %d", &position1horzontal, &position2verticale);
                        }
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.ligneelectrique.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.ligneelectrique.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.ligneelectrique.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }


                    if (type == 4) {
                        //////while (informationPlateau.matriceDuplateau[i][j] != 0){


                           /* if(informationPlateau.matriceDuplateau[position1horzontal][position2verticale+3] !=0){
                                    printf("Veuillez saisir des nouvelles positions il y a deja une infrastructure\n");
                                    scanf("%d %d",&position1horzontal,&position2verticale);
                                }
                           // if(informationPlateau.matriceDuplateau[position1horzontal+1][position2verticale+3] !=0){
                                printf("Veuillez saisir des nouvelles positions il y a deja une infrastructure\n");
                                scanf("%d %d",&position1horzontal,&position2verticale);
                            }
                            if(informationPlateau.matriceDuplateau[position1horzontal+2][position2verticale+3] !=0){
                                printf("Veuillez saisir des nouvelles positions il y a deja une infrastructure\n");
                                scanf("%d %d",&position1horzontal,&position2verticale);
                            }*/



                       // }
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.cabane.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.cabane.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.cabane.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 5) {
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.maison.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.maison.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.maison.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 6) {
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.immeuble.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.immeuble.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.immeuble.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 7) {
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.gratteciel.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.gratteciel.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.gratteciel.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 8) {


                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.chateaueau.habitants;

                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        joueur1.joueur.argent -= informationBatiment.chateaueau.prix;
                        printf("Vous disposez de %d ECE_Flouz\n", joueur1.joueur.argent);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.chateaueau.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.chateaueau.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }
                    if (type == 9) {
                        joueur1.joueur.nombrehabitantsdelaville += informationBatiment.centraleelectrique.habitants;
                        printf("Vous avez %d habitants dans votre ville\n", joueur1.joueur.nombrehabitantsdelaville);
                        joueur1.joueur.argent -= informationBatiment.centraleelectrique.prix;
                        printf("Vous disposez de %d ECE_Flouz\n", joueur1.joueur.argent);
                        for (int m = position1horzontal;
                             m < position1horzontal + informationBatiment.centraleelectrique.ligne; m++) {
                            for (int n = position2verticale;
                                 n < position2verticale + informationBatiment.centraleelectrique.colonne; n++) {
                                variable = type;
                                informationPlateau.matriceDuplateau[m][n] = variable;
                            }
                        }
                    }

                    i = position1horzontal;
                    j = position2verticale;

                    variable = informationPlateau.matriceDuplateau[i][j];
                    fprintf(input, "%d", variable);
                } else {
                    variable = informationPlateau.matriceDuplateau[i][j];
                    fprintf(input, "%d", variable);
                }
            }
            fputc((int) '\n', input);
        }

    }
    sauvegarde_information_joueur(joueur1);

    fclose(inpute);
}

int main() {
    jeu();
}

