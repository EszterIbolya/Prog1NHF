#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cserel.h"
#include "torol.h"
#include "kereses.h"
#include "debugmalloc.h"
//Kiírja a választási lehetőségeket a főmenüben.
void fomenuoptions(){
printf("1. Uj rekord letrehozasa\n2. Rekord modositasa\n3. Rekord torlese\n4. Kereses a rekordok kozott ido szerint\n5. Kereses a rekordok kozott nev szerint\n6. Fajlba mentes\nHa kilepne irjon be -1-et\nIrja be a kivant muvelet megfelelo sorszamat: ");}

/*Beolvas egy szövegfájl nevet,amiben az adatok a megfelelő formátumban szerepelnek, az abban levő adatokat beolvassa
listába a, illetve, ha '0;'-t ír be nem. Majd visszalép a mainbe.*/
void listabeolvas(lista **eleje){
    FILE *fp;
    printf("Melyik szovegfajl adatait olvassa be? Irja be a megfelelo formatumban: nev.txt;\nHa nem olvasna be irjon 0;-t.\n");
    char fajlnev[21];
    scanf("\n%[^;];",fajlnev);
    if(strcmp(fajlnev,"0")==0){return;}
    fp=fopen(fajlnev,"r");
    if (fp == NULL) {
    return;}
    char sor[200];
    lista *mozgo;
    while(fgets(sor,200,fp)!=NULL){
        lista *uj=(lista*) malloc(sizeof(lista));
        sscanf(sor,"%d.%d.;%d:%d;%[^;];%[^;];%[^;];",&uj->honap,&uj->nap,&uj->ora,&uj->perc,uj->hely,uj->elnevezes,uj->megjegyzes);
        uj->kov = NULL;
        if (*eleje == NULL) {
            *eleje = uj;
            mozgo=*eleje;
        }
        else {
            mozgo->kov=uj;
            mozgo=mozgo->kov;
        }
    }
    fclose(fp);
    return;
}
//Egy szövegfájl nevének megadásával abba lementi az adatokat olyan formátumba, amiből később vissza is tudja azt olvasni
void ment(lista *eleje){
    FILE *fp;
    printf("Melyik szovegfajlba menti ki az adatokat? Irja be a megfelelo formatumban: nev.txt;\n");
    char fajlnev[21];
    scanf("\n%[^;];",fajlnev);
    fp=fopen(fajlnev,"w");
    if (fp == NULL) {
    return;}
    lista *mozgo;
    mozgo=eleje;
    while(mozgo!=NULL){
        fprintf(fp, "%d.%d.;%d:%d;%s;%s;%s;\n" ,mozgo->honap,mozgo->nap,mozgo->ora,mozgo->perc,mozgo->hely,mozgo->elnevezes,mozgo->megjegyzes);
        mozgo=mozgo->kov;
    }
    fclose(fp);
    return;
}
//Beolvas egy új listaelemet
lista *beolvas(){
    lista *uj=(lista*) malloc(sizeof(lista));
    printf("A rekordot adatait igy vigye be: honap.nap.;ora:perc;hely;elnevezes;megjegyzes;\nHa visszalepne, akkor barmelyik adat helyere irjon -1-et\n");
    scanf("%d.%d.;%d:%d;%[^;];%[^;];%[^;];",&uj->honap,&uj->nap,&uj->ora,&uj->perc,uj->hely,uj->elnevezes,uj->megjegyzes);
    if(uj->honap==-1 || uj->nap==-1 || uj->ora==-1 || uj->perc==-1 || strcmp(uj->hely,"-1")==0 || strcmp(uj->elnevezes,"-1")==0 || strcmp(uj->megjegyzes,"-1")==0){
        return NULL;}
    return uj;}
//Bolvas, majd a főmenüt, addig ismétli, amíg '-1'-et nem kap, akkor fölszabadítja a listaelemeket és kilép a porgramból.
int main(){
    lista *eleje=NULL;
    listabeolvas(&eleje);
    int szam;
    while(1){
        system("cls");
        fomenuoptions();
        scanf("%d", &szam);
        switch(szam){
        case 1: ;
            lista *uj;
            uj=beolvas();
            if(uj==NULL){break;}
            uj->kov = NULL;
            if (eleje == NULL) {
                eleje = uj;}
            else {
                lista *mozgo;
                for(mozgo=eleje; mozgo->kov!=NULL; mozgo=mozgo->kov){}
                mozgo->kov=uj;}
            break;
        case 2:
            eleje=keres(eleje,2);
            break;
        case 3:
            eleje=keres(eleje,3);
            break;
        case 4:
            idokeres(eleje);
            break;
        case 5:
            nevkeres(eleje);
            break;
        case 6:
            ment(eleje);
            break;
        case -1:;
            lista *mozgo;
            mozgo=eleje;
            while(mozgo!=NULL){
                lista *kov=mozgo->kov;
                free(mozgo);
                mozgo=kov;
            }
            return 0;
        default:
            break;

        }
    }
    return 0;
}
