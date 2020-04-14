/*
 * main.c
 * 
 * Copyright 2016 André Luiz Pereira de Almeida
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int set;
int count;
char opt = 'n';

void startSet(){
	srand((unsigned)time(NULL));
	set = 1+ rand()%10;
	count = 0;
}

bool game(int num){

	if(num == set){
		return true;
	}
	return false;
}

int main(){
	
	printf(" O objetivo do jogo e acertar o numero gerado pelo CPU.     \n\nVamos comecar!\n");
	
	int num;
	
	startSet();
	while ( !game(num) && count < 3 ){
	
		while(!isdigit(num)){
			printf("Digite um numero entre 00 e 09: ");
			fflush(stdin);
			scanf("%d", &num);
		}
		count++;
		
		if(game(num)){
			printf("Parabens voce acertou!\n");
			break;
		}else{
			printf("Chance %d de 3 falhou!\t",count);
		
			if (num < set){
				printf("Era maior!\n\n");
			}else if ( num > set){
				printf("Era menor!\n\n");
			}
		}
	}
	
	do{
		fflush(stdin);
		printf("\n\nQuer tentar novamente?\n");
		opt = getchar();
		
		if (opt == 's')
		{
			system("CLS");
			main();
		}elseif (opt == 'n'){
			break;
		}
			
	}while(opt != 's' && opt != 'n');
	return 0;
}

