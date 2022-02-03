#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100
#define PLAY_WORDS 35

int seperator(char *input,char output[MAX_WORD_LENGTH][MAX_WORDS]){
	int i=0,c=0;
	for(int row=0;row<MAX_WORDS;row++){
		for(int col=0;col<MAX_WORD_LENGTH;col++){
			if(input[i]==' '){
				output[row][col]='\0';
				i++;c++;
				break;
			}else{
				output[row][col]=input[i++];
			}

		}
	}
	return c;
}


void readfile(char* buffer){                                                    
        FILE * fd=fopen("words.txt","r");

        fseek(fd,0L,SEEK_END);													
        int filesize=ftell(fd);                                                 
        fseek(fd,0L,SEEK_SET);													

        int size=fread(buffer,1,filesize,fd);
}

int main(){
	int n,timetaken,correct=0;
	float wpm,accuracy;
	char allwords[MAX_WORD_LENGTH][MAX_WORDS],buffer[2048],randwords[MAX_WORD_LENGTH][PLAY_WORDS],input[2048],inparr[MAX_WORD_LENGTH][MAX_WORDS];
	time_t start,stop;
	
	start=time(NULL);
	readfile(buffer);
	n=seperator(buffer,allwords);
	
	srand(time(NULL));
	for(int i=0;i<PLAY_WORDS;i++){
		int r=rand()%n;
		printf("%s ",allwords[r]);
		strcpy(randwords[i],allwords[r]);
	}
	
	printf("\n");
	fgets(input,sizeof(input),stdin);
	seperator(input,inparr);
	
	for(int i=0;i<PLAY_WORDS;i++){
		if(strcmp(randwords[i],inparr[i])==0){
			correct++;
		}
	}
	
	stop=time(NULL);
	timetaken=stop-start;
	accuracy=(((double)correct)/PLAY_WORDS)*100;
		
	if(accuracy>65){
		printf("\ntime taken: %d\nAccuracy: %.2f\%\n",timetaken,accuracy);
		wpm=(PLAY_WORDS/((double)timetaken))*60;
		printf("Raw WPM: %.2f wpm\n",wpm);
	}else{
		printf("\nMinimm accuray of 65\% required\n");
	}
		
}
