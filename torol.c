#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cserel.h"
#include "torol.h"
#include "kereses.h"
#include "debugmalloc.h"

lista *eltavolit(lista *eleje,int *melyik, int ezt, lista *lemarado, lista *mozgo){
    *melyik=*melyik+1;
    if(*melyik==ezt){
        if (lemarado==NULL) {
            eleje=mozgo->kov;
            free(mozgo);
        }
        else{
            lemarado->kov = mozgo->kov;
            free(mozgo);
        }
    }
    return eleje;
}

/*A megfelelő keresés alapján, kikeresi az adatokat, majd törli a kiválasztottat.*/
lista *torol(int sorszam,lista *eleje,int egyes,int kettes,char *keres){
    printf("Valasszon meyilket torli,a megfelelo sorszamot gepelje be: ");
    int ezt;
    scanf("%d",&ezt);
    int melyik=0;
    lista *lemarado;
    lemarado=NULL;
    lista *mozgo;
    mozgo=eleje;
    while(mozgo!=NULL){
        switch(sorszam){
            case 1:
                if(mozgo->honap == egyes && mozgo->nap == kettes){
                    eleje=eltavolit(eleje,&melyik,ezt,lemarado,mozgo);
                }break;
            case 2:
                if(mozgo->ora == egyes && mozgo->perc == kettes){
                    eleje=eltavolit(eleje,&melyik,ezt,lemarado,mozgo);
                }break;
            case 3:
                if(strcmp(keres,mozgo->hely)==0){
                    eleje=eltavolit(eleje,&melyik,ezt,lemarado,mozgo);
                }break;
            case 4:
                if(strcmp(keres,mozgo->elnevezes)==0){
                    eleje=eltavolit(eleje,&melyik,ezt,lemarado,mozgo);
                }break;
            case 5:
                if(strcmp(keres,mozgo->megjegyzes)==0){
                    eleje=eltavolit(eleje,&melyik,ezt,lemarado,mozgo);
                }break;
        }
        if(melyik==ezt){
            return eleje;
        }
        lemarado=mozgo;
        mozgo=mozgo->kov;
    }
return eleje;
}
