/*
 * main.c
 * 
 * Copyright 2016 André Luiz Pereira de Almeida
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
	
		printf("Digite um numero entre 00 e 09: ");
		scanf("%d", &num);
		count++;
		fflush(stdin);
		
		if(game(num)){
			printf("Parabens voce acertou!\n");
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
		}
			
	}while(opt != 's' && opt != 'n');
	return 0;
}

