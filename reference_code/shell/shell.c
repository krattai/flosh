/**
*Author :Tharindra Galahena
*Project:Simple Shell in c
*Date   :24/11/2011
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int check_arg(char *s){
	int i;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == ' '){	
			return i;
		}          
	}
	return 0;
}
int check_pipe(char *s){
	int i;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == '|') return i;           
	}
	return 0;
}

int arg_count(char *s){
	int i = 0;
	int j = 0;
 	
	while(i < strlen(s)){		
		j++;
		while(s[i] != ' ' && i < strlen(s)) i++;
		while(s[i] == ' ' && i < strlen(s)) i++;
	}
	return j;
}

void run(char *s, int i){
	int x = i + 1;
	while(s[x] == ' ' && x < strlen(s)) x++;
	char *c = NULL;
	
	if(x < strlen(s)){
		c = &s[x];
		s[i] = '\0';
		int l = 1;
		int j = arg_count(c);  
		char *args[j + 2];
		memset(args, 0, sizeof(char *) * (j + 2));
		args[0] = s;
		x = 0;
		while(x < strlen(c)){
			args[l] = &c[x];	
			while(x < strlen(c) && c[x] != ' ') x++;
			if(x < strlen(c)){
				char *g = &c[x + 1];
				c[x] = '\0';
				c = g;
				x = 0;
			}
			while(x < strlen(c) && c[x] == ' ') x++;
			l++;
		}
		execvp(args[0], args);
	}else{
		s[i] = '\0';
		execlp(s, s, NULL);	
	}
}

void pip(char *inbuf, int a, int b){
	int j = check_pipe(inbuf);
	if(j){
		char *c = &inbuf[j+1];
		inbuf[j] = '\0';
		int pid[2]; 
		if(pipe(pid) == -1){
			perror("pipe call error");
			exit(1);           
		}
		if(fork()){
			close(pid[0]);
			//dup2(pid[1], b);
			pip(inbuf, a,pid[1]);
		}else{
			close(pid[1]);
			//dup2(pid[0], a ); 
			pip (c, pid[0], b);                                       
		}
	}else{
		dup2(a, 0);
		dup2(b, 1);
		int x = 0;
		while(inbuf[x] == ' ' && x < strlen(inbuf)) x++;
		inbuf = &inbuf[x];
		int i = check_arg(inbuf);
		if(!i){
			execlp(inbuf, inbuf, NULL);   
		}else{
			run(inbuf, i);       
		}                               
	}
}
int main(){
	int pid[2];
	char inbuf[10];
	printf("\n\nSimple Shell using C\n");
	printf("Create By Tharindra Galahena\n");
	printf("http://inf0warri0r.blogspot.com \n");
	printf("------------------------------------------------\n");
	while(1){
		printf("[my shell] :");
		gets(inbuf);
		if(fork()){
			wait();
		}else{
			pip(inbuf, 0, 1);
		}
	}
	return 0;
}
