#ifndef CSEREL_H_INCLUDED
#define CSEREL_H_INCLUDED

typedef struct lista{
    int honap;
    int nap;
    int ora;
    int perc;
    char hely[51];
    char elnevezes[51];
    char megjegyzes[101];
    struct lista *kov;
}lista;

void szamvaltoztat(int *melyik,int ezt,lista *mozgo,int elso, int masodik, int keres);
void sztringvaltoztat(int *melyik,int ezt,lista *mozgo, char *elso, int keres);
void menu2(int szam,int ezt,int sorszam,lista *eleje,int egyes,int kettes,char *keres);




#endif
