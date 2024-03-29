/***********************************************************************
* A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
* #include <string.h>
* #include <math.h>
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
************************************************************************
**  ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat (5 pont)

Az alabbi fuggveny feladata helyet foglalni egy ketdimenzios int tombnek.
A tomb sor- es oszlopszama megegyezik.
A tomb N meretet a fuggveny parameterkent kapja.
A helyfoglalas ugy tortenjen, hogy a ketdimenzios tomb osszes elemet
egy egydimenzios N*N-es tombben helyezzuk el sorfolytonosan.
A helyfoglalas utan toltsuk fel a tomb elemeit ertekekkel a kovetkezo modon:
A tomb "atloi" --- azaz azon elemek, melyek sor- es oszlopindexe megegyezik, vagy
ezek osszege N-1 --- legyenek 1, belso elemei pedig -1 ertekuek.
A fuggveny terjen vissza a tombre mutato pointerrel. A memoria felszabaditasaval
nem kell foglalkoznod.
*/

int *foglal(int n) {
	int* tomb = (int*)malloc(sizeof(int)*n*n);
	int index = 0;
	for(int i = 0; i<n;i++){
		for(int j = 0; j<n;j++){
			if(j ==i || j+i== n-1){
				tomb[index] = 1;
				index++;
			}
			else {
				tomb[index] = -1;
				index++;
			}
		}
	}
	return tomb;
	}

/*
2. feladat (5 pont)

Irj egy fuggvenyt, amely kiszamolja, hogy egy utasitassorozat hatasara
hova jutunk a (0,0) koordinatabol kezdetben eszak fele nezve! Az
utasitassorozat egy sztring, ami a kovetkezo karakterekbol allhat:
'b', 'j', 'e', 'k', 'd', 'n', '1'..'9'. Minden egyeb, a sztringben
szereplo karaktert figyelmen kivul kell hagyni! A karakterek jelentesei:
'b' - forduljunk balra 90 fokkal; 'j' - forduljunk jobbra 90 fokkal;
'e', 'k', 'd', 'n' - forduljunk eszaknak, keletnek, delnek, nyugatnak;
'1'..'9' - lepjunk elore 1..9 egyseget. A fuggveny visszateresi erteke
a vegpont koordinatainak (elojeles) osszege. Az egyik koordinata kelet,
a masik eszak fele novekszik.
*/

int koord(char* utasitas) {
	char irany = 'e';
	int x= 0;
	int y = 0;
	for(int i = 0; utasitas[i] != '\0';i++){
		if(utasitas[i] == 'e'){
			irany = 'e';
		}
		else if (utasitas[i] == 'k'){
			irany = 'k';
		}
		else if (utasitas[i] == 'd'){
			irany = 'd';
		}
		else if (utasitas[i] == 'n'){
			irany = 'n';
		}
		else if (utasitas[i] == 'b'){
			if(irany == 'e'){
				irany = 'n';
			}
			else if(irany == 'n'){
				irany = 'd';

			}
			else if(irany == 'd'){
				irany = 'k';
			}
			else if(irany == 'k'){
				irany = 'e';
			}
		}
		else if (utasitas[i] == 'j'){
			if(irany == 'e'){
				irany = 'k';
			}
			else if(irany == 'n'){
				irany = 'e';

			}
			else if(irany == 'd'){
				irany = 'n';
			}
			else if(irany == 'k'){
				irany = 'd';
			}
		}
		else if(utasitas[i] >=1 && utasitas[i] <=9) {
			if(irany == 'e'){
				y += (utasitas[i] -'0');
			}
			else if (irany == 'd'){
				y -= (utasitas[i] - '0');
			}
			else if(irany == 'k'){
				x += (utasitas[i] -'0');
			}
			else if(irany == 'n'){
				x -= (utasitas[i] - '0');
			}


		}




	}

	return (x+y);

}
/***********************************************************************
************************************************************************
**
**  EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1()
{
	int chck;
	int n, ij;
	int *ptr = NULL;
	if(fscanf(stdin, "%d %d", &chck, &n)!=2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	ptr = foglal(n);
	switch (chck) {
		case 1:
			if (ptr != NULL) {
				free(ptr);
				fprintf(stdout,"%d\n", n);
			} else {
				fprintf(stdout,"NULL\n");
			}
			break;
		case 2:
			if (ptr != NULL) {
				ptr[n*n-1]=n;
				fprintf(stdout,"%d\n", n);
			} else {
				fprintf(stdout,"NULL\n");
			}
			break;
		case 3:
			for(ij=0; ij<n*n; ij++) {
				fprintf(stdout, "%d%c", ptr[ij], ((ij%n)==(n-1))?'\n':' ');
			}
			break;
		default:
			if(fscanf(stdin, "%d", &ij)!=1) {
				fprintf(stderr, "HIBA: Nem olvasható adat!\n");
				return;
			}
			fprintf(stdout,"%d\n", ptr[ij]);
			break;
	}
}
void test_1()
{
	const int n = 3;
	int i, j, k;
  int *ptr = NULL;
  struct {int ptr[9];} testlist[1] = {
  	{
  		{1,-1,1, -1,1,-1, 1,-1,1}
  	}
  };
  for (i = 0; i < 1; ++i) {
    ptr = foglal(n);
    if (ptr == NULL) {
    	fprintf(stderr, "HIBA: NULL pointer\n");
    	return;
    } else {
    	for (j = 0; j < n; ++j) {
    		for (k = 0; k < n; ++k) {
    			if (ptr[j*n+k] != testlist[i].ptr[j*n+k]) {
    				fprintf(stderr, "HIBA a(z) (%d,%d) pozíción\n"
    					              "\telvárt eredmény: %d\n"
    					              "\tkapott eredmény: %d\n",
    					              j, k, testlist[i].ptr[j*n+k], ptr[j*n+k]);
    				return;
    			}
    		}
    	}
    }
    free(ptr);
  }
}

void call_2()
{
	int i = 0;
	char kif[100];
	if(fscanf(stdin, "%s", kif)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	i = koord(kif);
	fprintf(stdout,"%d\n",i);
}
void test_2()
{
	int i, eredmeny;
	struct {char kif[100]; int eredmeny;} testlist[1] = {
		{"2b3jj1j1ezer1", 0}
	};
	for (i = 0; i < 1; ++i) {
		eredmeny = koord(testlist[i].kif);
		if (testlist[i].eredmeny != eredmeny) {
			fprintf(stderr, "HIBA: koord(\"%s\")\n"
							"\telvárt eredmény: %d\n"
							"\tkapott eredmény: %d\n",
					testlist[i].kif, testlist[i].eredmeny, eredmeny);
		}
	}
}

typedef void (*call_function)();

call_function call_table[] = {
	call_1,
	call_2,
	NULL
};


call_function test_table[] = {
	test_1,
	test_2,
	NULL
};

static int __arg_check_helper(const char * exp, const char * arg) {
    while (*exp && *arg && *exp == *arg) {
        ++exp;
        ++arg;
    }
    return *exp == *arg;
}

int main(int argc, char *argv[])
{
    int feladat, calltabsize;
    if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1]))) {
        if (argc > 2) {
            feladat = atoi(argv[2]);
            for (calltabsize=0; test_table[calltabsize]; calltabsize++);
            if (feladat <= 0 || calltabsize < feladat) {
                fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
                return 1;
            }
            (*test_table[feladat-1])();
        } else {
            for (feladat=0; test_table[feladat]; ++feladat) {
                (*test_table[feladat])();
            }
        }
        return 0;
    }
    if (!freopen("be.txt", "r", stdin)) {
        fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
        return 1;
    }
    if (!freopen("ki.txt", "w", stdout)) {
        fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
        return 1;
    }
    for (calltabsize=0; call_table[calltabsize]; calltabsize++);
    if (fscanf(stdin, "%d%*[^\n]", &feladat)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
        return 1;
    }
    fgetc(stdin);
    if (0<feladat && feladat<=calltabsize) {
        (*call_table[feladat-1])();
    } else {
        fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
        return 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
