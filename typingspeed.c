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
	int n,wpm;
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
	stop=time(NULL);
	wpm=(PLAY_WORDS/(stop-start))*60;
	printf("your speed is %d wpm\n",wpm);
	
	
}
