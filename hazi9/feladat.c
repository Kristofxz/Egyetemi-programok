#include <stdio.h>

int main(){
	FILE* be = fopen("be.txt","r");
	FILE* ki = fopen("ki.txt","w");

	int maxhegy;
	int maxviz;
	int minvih;
	int sor;
	int mag;
	int lakhato = 0;
	int vanhegy = 0;
	int vanviz = 0;
	int nincsvihar = 1;

	fscanf(be,"%d %d %d",&maxhegy,&maxviz,&minvih);
	fscanf(be,"%d %d",&sor,&mag);

	char map[mag][sor];

	for(int i = 0;i<mag;i++){
		for (int j = 0; j<sor;j++){
			fscanf(be,"%c",&map[i][j]);
		}
	}





	
	for(int i = 0;i<mag;i++){
		for (int j = 0; j<sor;j++){
			//lakható terület megtalálása
			if(map[i][j] == '~' || map[i][j] == '0'){
				
				vanhegy = 0;
				vanviz = 0;
				nincsvihar = 1;


				//hegy vizsgálat
				int tempmaxhegybal = maxhegy;
				int tempmaxhegyjobb = maxhegy;
				int tempmaxhegyfel = maxhegy;
				int tempmaxhegyle = maxhegy;

				while(i-tempmaxhegybal < 0){
					tempmaxhegybal--;
				}
				while(i+tempmaxhegyjobb > mag){
					tempmaxhegyjobb--;
				}
				while(j-tempmaxhegyfel < 0){
					tempmaxhegyfel--;
				}
				while(j+tempmaxhegyle > sor){
					tempmaxhegyle--;
				}




				for(int y = i - tempmaxhegybal; y<i+tempmaxhegyjobb;y++){
					for(int x = j- tempmaxhegyfel;x<j+ tempmaxhegyle;x++){
						if (map[x][y] == 'A'){
							vanhegy = 1;
						}
					}
				}


				//víz vizsgálat
				int tempmaxvizbal = maxviz;
				int tempmaxvizjobb = maxviz;
				int tempmaxvizfel = maxviz;
				int tempmaxvizle = maxviz;

				while(i-tempmaxvizbal < 0){
					tempmaxvizbal--;
				}
				while(i+tempmaxvizjobb > mag){
					tempmaxvizjobb--;
				}
				while(j-tempmaxvizfel < 0){
					tempmaxvizfel--;
				}
				while(j+tempmaxvizle > sor){
					tempmaxvizle--;
				}


				for(int y = i - tempmaxvizbal; y<i+tempmaxvizjobb;y++){
					for(int x = j- tempmaxvizfel;x<j+ tempmaxvizle;x++){
						if (map[x][y] == '~'){
							vanviz = 1;
						}
					}
				}

				//vihar vizsgálat
				int tempmaxvihbal = minvih;
				int tempmaxvihjobb = minvih;
				int tempmaxvihfel = minvih;
				int tempmaxvihle = minvih;

				while(i-tempmaxvihbal < 0){
					tempmaxvihbal--;
				}
				while(i+tempmaxvihjobb > mag){
					tempmaxvihjobb--;
				}
				while(j-tempmaxvihfel < 0){
					tempmaxvihfel--;
				}
				while(j+tempmaxvihle > sor){
					tempmaxvihle--;
				}


				for(int y = i - tempmaxvihbal; y<i+tempmaxvihjobb;y++){
					for(int x = j- tempmaxvihfel;x<j+ tempmaxvihle;x++){
						if (map[x][y] == 'X'){
							 nincsvihar= 0;
						}
					}
				}



				if(vanhegy == 1 && vanviz == 1 && nincsvihar == 1){
					lakhato++;
				}





			}
		}
	}
	fprintf(ki,"%d\n",lakhato);





	fclose(be);
	fclose(ki);
	return 0;
}