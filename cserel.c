#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cserel.h"
#include "torol.h"
#include "kereses.h"
#include "debugmalloc.h"
void szamvaltoztat(int *melyik,int ezt,lista *mozgo,int elso, int masodik, int keres){
    *melyik=*melyik+1;
    if(*melyik==ezt){
        switch(keres){
            case 1: mozgo->honap = elso;
                    mozgo->nap = masodik;
                    break;
            case 2: mozgo->ora = elso;
                    mozgo->perc = masodik;
                    break;
        }
    }
}

void sztringvaltoztat(int *melyik,int ezt,lista *mozgo, char *elso, int keres){
    *melyik=*melyik+1;
    if(*melyik==ezt){
        switch(keres){
            case 1: strcpy(mozgo->hely,elso); break;
            case 2: strcpy(mozgo->elnevezes,elso); break;
            case 3: strcpy(mozgo->megjegyzes,elso); break;
        }
    }
}

/*A szám változóban megkapja, hogy mi lett kiválasztva megváltoztatásra, majd a sorszamként megkapott keresési feltétel
alapján kikeresi, azt a kiválasztott sorszámú listaelemet, amit az ezt-ben kap meg a függvény. Utána pedig a szintén
paramáterként átvett adatokra(egyes és kettes, ha dátumot vagy időt változtat, egyébként pedig a keres) megváltoztatja a megfelelőt.*/
void menu2(int szam,int ezt,int sorszam,lista *eleje,int egyes,int kettes,char *keres){
    system("cls");
    switch(szam){
        case 1:{
                printf(" Gepelje a megfelelo formatumban: honap.nap.\n");
                int elso, masodik;
                scanf("%d.%d.",&elso,&masodik);
                int melyik=0;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    switch(sorszam){
                        case 1:
                            if(mozgo->honap == egyes && mozgo->nap == kettes){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,1);
                            }
                        case 2:
                            if(mozgo->ora == egyes && mozgo->perc == kettes){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,1);
                            }
                        case 3:
                            if(strcmp(keres,mozgo->hely)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,1);
                            }
                        case 4:
                            if(strcmp(keres,mozgo->elnevezes)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,1);
                            }
                        case 5:
                            if(strcmp(keres,mozgo->megjegyzes)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,1);
                            }
                    }
                }break;
        }
        case 2:{
                printf(" Gepelje a megfelelo formatumban: ora:perc\n");
                int elso, masodik;
                scanf("%d:%d;",&elso,&masodik);
                int melyik=0;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    switch(sorszam){
                        case 1:
                            if(mozgo->honap == egyes && mozgo->nap == kettes){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,2);
                            }
                        case 2:
                            if(mozgo->ora == egyes && mozgo->perc == kettes){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,2);
                            }
                        case 3:
                            if(strcmp(keres,mozgo->hely)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,2);
                            }
                        case 4:
                            if(strcmp(keres,mozgo->elnevezes)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,2);
                            }
                        case 5:
                            if(strcmp(keres,mozgo->megjegyzes)==0){
                                szamvaltoztat(&melyik,ezt,mozgo,elso,masodik,2);
                            }

                    }
                }break;
        }
        case 3:{
                printf(" Gepelje be az uj helyet megfelelo formatumban: hely;\n");
                char elso[51];
                scanf("\n%[^;];",elso);
                int melyik=0;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    switch(sorszam){
                        case 1:
                            if(mozgo->honap == egyes && mozgo->nap == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,1);
                            }
                        case 2:
                            if(mozgo->ora == egyes && mozgo->perc == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,1);
                            }
                        case 3:
                            if(strcmp(keres,mozgo->hely)==0){
                               sztringvaltoztat(&melyik,ezt,mozgo,elso,1);
                            }
                        case 4:
                            if(strcmp(keres,mozgo->elnevezes)==0){
                               sztringvaltoztat(&melyik,ezt,mozgo,elso,1);
                            }
                        case 5:
                            if(strcmp(keres,mozgo->megjegyzes)==0){
                               sztringvaltoztat(&melyik,ezt,mozgo,elso,1);
                            }
                    }

                }break;
        }
        case 4:{
                printf(" Gepelje be az elnevezest megfelelo formatumban: elnevezes;\n");
                char elso[51];
                scanf("\n%[^;];",elso);
                int melyik=0;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    switch(sorszam){
                        case 1:
                            if(mozgo->honap == egyes && mozgo->perc == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,2);
                            }
                        case 2:
                            if(mozgo->ora == egyes && mozgo->perc == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,2);
                            }
                        case 3:
                            if(strcmp(keres,mozgo->hely)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,2);
                            }
                        case 4:
                            if(strcmp(keres,mozgo->elnevezes)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,2);
                            }
                        case 5:
                            if(strcmp(keres,mozgo->megjegyzes)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,2);
                            }
                    }break;
                }
        }
        case 5:{
                printf(" Gepelje be az uj megjegyzest megfelelo formatumban: megjegyzes;\n");
                char elso[101];
                scanf("\n%[^;];",elso);
                int melyik=0;
                for(lista *mozgo=eleje; mozgo!=NULL; mozgo=mozgo->kov){
                    switch(sorszam){
                        case 1:
                            if(mozgo->honap == egyes && mozgo->nap == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,3);
                            }
                        case 2:
                            if(mozgo->ora == egyes && mozgo->perc == kettes){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,3);
                            }
                        case 3:
                            if(strcmp(keres,mozgo->hely)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,3);
                            }
                        case 4:
                            if(strcmp(keres,mozgo->elnevezes)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,3);
                            }
                        case 5:
                            if(strcmp(keres,mozgo->megjegyzes)==0){
                                sztringvaltoztat(&melyik,ezt,mozgo,elso,3);
                            }
                    }break;
                }
        }
    }
return;
}

