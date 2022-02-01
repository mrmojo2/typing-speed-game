#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

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
        FILE * fd=fopen("./words","r");

        fseek(fd,0L,SEEK_END);													
        int filesize=ftell(fd);                                                 
        fseek(fd,0L,SEEK_SET);													

        int size=fread(buffer,1,filesize,fd);
        //printf("buffer :%s\n",buffer);
}

int main(){
	int n;
	char words[MAX_WORD_LENGTH][MAX_WORDS],buffer[2048];
	
	readfile(buffer);
	n=seperator(buffer,words);

	//for(int i=0;i<n;i++) printf("%s ",words[i]);
	printf("%d",n);
}
