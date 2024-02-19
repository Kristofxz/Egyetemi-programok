#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* be = fopen("be.txt","r");
	FILE* ki = fopen("ki.txt","w");

	int latotav;
	fscanf(be,"%d",&latotav);
	int dbvaros;
	fscanf(be,"%d",&dbvaros);

	int tavok[dbvaros-1];
	for(int i = 0; i<dbvaros-1;i++){
		fscanf(be,"%d",&tavok[i]);
	}

	int tav;
	int varoslat;
	int maxvaroslat = 0;
	int maxindex;

	
	for(int i = 0; i<dbvaros;i++){
		tav = 0;
		varoslat = 0;
		//bal
		if(i>0){
		for(int j = i; j>0;j--){
			if(tav <= latotav){
				tav += tavok[j-1];
				varoslat++;
			}

		}
		tav = 0;
		//jobb
		for(int j = i; j<dbvaros-2;j++){
			if(tav <= latotav){
				tav += tavok[j+1];
				varoslat++;
			}


		}


		if(varoslat > maxvaroslat){
			maxvaroslat = varoslat;
			maxindex = i;
		}

	}



	}


	fprintf(ki,"%d\n",maxindex);



	fclose(be);
	fclose(ki);

	return 0;
}