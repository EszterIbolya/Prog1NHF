#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cserel.h"
#include "torol.h"
#include "kereses.h"
#include "debugmalloc.h"

void kiirtalalat(int *szamoz, lista *mozgo){
    printf("%d. %d.%d.;%d:%d;%s;%s;%s;\n",*szamoz,mozgo->honap,mozgo->nap,mozgo->ora,mozgo->perc,mozgo->hely,mozgo->elnevezes,mozgo->megjegyzes);
    *szamoz=*szamoz+1;
}

void valasztas(int *mit, int *ezt){
    printf("\nValsszon a sorszam beirasaval melyiket valtoztatja: ");
    scanf("%d",ezt);
    printf("Melyik adatot valtoztatja?\n1.Datum\n2.Pontos ido\n3.Hely\n4.Elnevezes\n5.Megjegyzes\n Gepelje be a sorszamat: ");
    scanf("%d",mit);
    printf("Mire valtoztataja?\n");
}

/* Kiválasztva a keresési feltételt, a szerint keres, a találatokat pedig sorszámozva (szamoz számol fel) kiírja.
Hét alapján való keresés esetén, megszorozza a keresett hetet 7-tel, majd addig adja hozzá a hónapok napjait, amíg
az több nem lesz, mint a szorzat. Utána az utolsót levonja, mivel az már több lenne. Hogy hányszor adta hozzá a
hónapok napjait, mutatja melyik hónapban van a hét. A szorzatból kivonva a napok összegét, pedig megkapja az utolsó
napot a keresett hétből.*/
void idokeres(lista *eleje){
    system("cls");
    if(eleje==NULL){
        printf("A lista ures!\n");
    }
    else{
        printf("Mi szerint keres?\n1.Honap\n2.Nap\n3.Het\nA megfelelo sorszamat gepelje be: ");
        int sorszam;
        scanf("%d",&sorszam);
        switch(sorszam){
            case 1:{
                printf("\nIrja be melyik honap esemenyeit listazza ki: ");
                int honap;
                scanf("%d",&honap);
                int szamoz=1;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    if(mozgo->honap==honap){
                        kiirtalalat(&szamoz,mozgo);
                    }
                }break;
            }
            case 2:{
                printf("\nIrja be meyik nap esemenyeit listazza ki: ");
                int nap;
                scanf("%d",&nap);
                int szamoz=1;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    if(mozgo->nap==nap){
                        kiirtalalat(&szamoz,mozgo);
                    }
                }break;
            }
            case 3:{
                printf("Irja be melyik het esemenyeit listazza ki: ");
                int het;
                int honapnapszam[]={31,28,31,30,31,30,31,31,30,31,30,31};
                scanf("%d",&het);
                int napok=7*het;
                int osszeg=0;
                int i;
                for(i=0; osszeg<napok; i++){
                    osszeg=osszeg+honapnapszam[i];
                }
                osszeg=osszeg-honapnapszam[i];
                int konkretnap= napok-osszeg;
                int szamoz=1;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    if((mozgo->honap==i) && (konkretnap >= mozgo->nap) && (mozgo->nap > (konkretnap-7))){
                        kiirtalalat(&szamoz,mozgo);
                    }
                }
                break;
            }
        }
    }
    printf("A fomenube valo visszalepeshet irjon be -1-et: ");
    int visszalep;
    scanf("%d",&visszalep);
    if(visszalep==-1){
        return;
    }
}

void nevkeres(lista *eleje){
    system("cls");
    if(eleje==NULL){
        printf("A lista ures!\n");
    }
    else{
        printf("Irja be az elnevezest ami alapján keres, a megfelelo formatumban: elnevezes;\n");
        char kereses[51];
        scanf("\n%[^;];",kereses);
        int szamoz=1;
        for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
            if(strcmp(kereses,mozgo->elnevezes)==0){
                kiirtalalat(&szamoz,mozgo);
            }
        }
    }
    printf("A fomenube valo visszalepeshet irjon be -1-et: ");
    int visszalep;
    scanf("%d",&visszalep);
    if(visszalep==-1){
        return;
    }
}

/*Keres a megadott alapján, majd a szerint melyik menüpontből lett hívva, továbblép a következő függvénybe. */
lista *keres(lista *eleje,int menupont){
            system("cls");
    if(eleje==NULL){
        printf("A lista ures!\n"); return eleje;
    }
    else{
            printf("1.Datum\n2.Pontos ido\n3.Hely\n4.Elnevezes\n5.Megjegyzes\nHa visszalepne irjon be -1-et\nA keresesi lehetosegek kozol a sorszam beirasaval valasszon: ");
            int sorszam;
            scanf("%d",&sorszam);
            switch(sorszam){
                case -1: return eleje;
                case 1:{
                    printf("Irja be a datumot a megfelelo formatumban: honap.nap.\n");
                    int ho,n;
                    scanf("%d.%d.",&ho,&n);
                    int szamol=1;
                    system("cls");
                    for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                        if(mozgo->honap == ho && mozgo->nap == n){
                            kiirtalalat(&szamol,mozgo);
                        }
                    }
                    if (szamol==1){ return eleje;}
                    switch(menupont){
                        case 2:{
                            int ezt;
                            int mit;
                            valasztas(&mit,&ezt);
                               menu2(mit,ezt,sorszam,eleje,ho,n," ");
                        }break;
                        case 3:
                            eleje=torol(sorszam,eleje,ho,n," "); break;
                    }
                }break;
                case 2:{
                    printf("Irja be az idot a megfelelo formatumban: ora:perc;\n");
                    int o,p;
                    scanf("%d:%d;",&o,&p);
                    int szamol=1;
                    system("cls");
                    for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                        if(mozgo->ora == o && mozgo->perc == p){
                            kiirtalalat(&szamol,mozgo);
                        }
                    }
                    if (szamol==1){ return eleje;}
                    switch(menupont){
                        case 2:{
                            int ezt;
                            int mit;
                            valasztas(&mit,&ezt);
                                menu2(mit,ezt,sorszam,eleje,o,p," ");
                        }break;
                        case 3:
                            eleje=torol(sorszam,eleje,o,p," "); break;
                    }
                }break;
                case 3:{
                    printf("Irja be a helyet a megfelelo formatunmban: hely;\n");
                    char keres[51];
                    scanf("\n%[^;];",keres);
                    int szamol=1;
                    system("cls");
                    for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                        if(strcmp(keres,mozgo->hely)==0){
                            kiirtalalat(&szamol,mozgo);
                        }
                    }
                    if (szamol==1){ return eleje;}
                    switch(menupont){
                        case 2:{
                            int ezt;
                            int mit;
                            valasztas(&mit,&ezt);
                                menu2(mit,ezt,sorszam,eleje,1,1,keres);
                        }break;
                        case 3:
                            eleje=torol(sorszam,eleje,1,1,keres); break;
                    }
                }break;
                case 4:{
                    printf("Irja be az elnevezest a megfelelo formatumban: elnevezes;\n");
                    char keres[51];
                    scanf("\n%[^;];",keres);
                    int szamol=1;
                    system("cls");
                    for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                        if(strcmp(keres,mozgo->elnevezes)==0){
                            kiirtalalat(&szamol,mozgo);
                        }
                    }
                    if (szamol==1){return eleje;}
                    switch(menupont){
                        case 2:{
                            int ezt;
                            int mit;
                            valasztas(&mit,&ezt);
                                menu2(mit,ezt,sorszam,eleje,1,1,keres);
                        }break;
                        case 3:
                            eleje=torol(sorszam,eleje,1,1,keres); break;
                    }
                }break;
                case 5:{
                    printf("Irja be a megjegyzest a megfelelo formatumban: megjegyzes;\n");
                    char keres[101];
                    scanf("\n%[^;];",keres);
                    int szamol=1;
                    system("cls");
                    for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                        if(strcmp(keres,mozgo->megjegyzes)==0){
                            kiirtalalat(&szamol,mozgo);
                        }
                    }
                    if (szamol==1){ return eleje;}
                    switch(menupont){
                        case 2:{
                            int ezt;
                            int mit;
                            valasztas(&mit,&ezt);
                                menu2(mit,ezt,sorszam,eleje,1,1,keres);
                        }break;
                        case 3:
                            eleje=torol(sorszam,eleje,1,1,keres); break;
                    }
                }break;
        }
    }
return eleje;
}
