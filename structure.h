//
// Created by Brandolini Noe on 08/11/2022.
//

#ifndef BAC_A_SABLE_1_I_STRUCTURE_H
#define BAC_A_SABLE_1_I_STRUCTURE_H

#include <stdio.h>

#define NOMBRE_DE_COLLONNE 45
#define NOMBRE_DE_LIGNE 35

#include "structure.h"

typedef struct {
    int valeurDansLeFichierTexte;
} Case;
typedef struct {
    int argent;
    int nombrehabitantsdelaville;
} Joueur;
typedef struct {
    int type;
    int ligne, colonne;
    int habitants;
    int prix;
} Batiment;
typedef struct {
    Batiment route;
    Case valeurcasefichiertexte;
    Joueur joueur;

    Batiment canalisation;
    Batiment ligneelectrique;
    Batiment cabane;
    Batiment maison;
    Batiment immeuble;
    Batiment gratteciel;
    Batiment chateaueau;
    Batiment centraleelectrique;
    Batiment terrainvague;
    int matriceDuplateau[35][45];


} Global;

Global lecture_fichier_texte(char *nomFichier);

Global lecture_fichier_texte2(char *nomFichier);
Global sauvegarde_information_joueur(Global Joueur);
#endif //BAC_A_SABLE_1_I_STRUCTURE_H
/*for (int i=0; i<NOMBRE_DE_LIGNE; i++) {
        fputc((int) '\n', input);
        for (int j = 0; j <NOMBRE_DE_COLLONNE ;j++) {
            //if(i == position1 && j==position2){
                //variable = type;
                informationPlateau.matriceDuplateau[position1][position2] = type;
                fprintf(input, (const char *) variable);

            //}
            //else{
                 //informationPlateau.matriceDuplateau[i][j]=variable ;
                //fprintf(input, (const char *) variable);
            }


        }*/