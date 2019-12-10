#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

#define TAM 7 // dimensionamento

// Prot. Function
void showMenu(int n, int x); // menu inicial
void composition(); // composição final
void tab(int n); // bordas horizontais >> 1
void tab2(int n); // bordas horizontais >> 2
int showTab(int n, int x, int y, char *z); // tabuleiro jogável
int showTabM(int n, int x, int y, char *z); // tabuleiro visual >> como jogar
void help(); // como jogar

/* 
	09 de dezembro de 2019	
    Departamento de T.I., UniProjeção (Taguatinga, Campus I)
    
    Sistemas de Informação (2º semestre)
    Autor: Yan Almeida Garcia
    
    00) Jogo da velha em C.
		
	Referência bibliográfica:
		[01]. "El codigo ASCII", disponível em: https://elcodigoascii.com.ar/
		[02]. "SLEEP EM C - LINUX [RESOLVIDO]", disponível em: "https://www.vivaolinux.com.br/topico/C-C++/Sleep-em-C-Linux"
		
*/

// global vars.
int i, j, menu;
char posS[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char S = 731; // bordas

int main(){
	showMenu(menu, 18);	
	
	return 0;
}

// Funtions
	// menu
void showMenu(int n, int x){
	system("cls"); // limpa a tela sempre que a função é chamada
	
	puts("\n\n");
	tab(x);
	
	printf("\n\t%c\t\t %c\n"
		"\t%c 2 - COMO JOGAR %c\n"
		"\t%c\t\t %c\n"
		"\t%c 1 -      JOGAR %c\n"	
		"\t%c 0 -       SAIR %c\n"
		"\t%c\t\t %c\n", S, S, S, S, S, S, S, S, S, S, S, S);
		
	tab(x);
	
	printf("\n\t  ");
	scanf(" %i", &n);
	system("cls");
	
	switch(n){
		case 0:
			exit(1);
			break;
	
		case 1:
			composition();
			break;
		
		case 2:
			puts("\n\n");
			showTabM(TAM, 5, TAM, posS);
			getch();
			break;
		default:
			showMenu(menu, 18);	
			break;
	}
}

void composition(){
	char res;
	int contJog, played, vezde = 0;
	do{
		contJog = 1;
		for(i = 0; i < 9; i++) posS[i] = ' '; // zerar o valor contido nas posS
	
		do{	
			puts("\n\n");
			showTab(TAM, 5, TAM, posS);		
			
			printf("\n\n\tCasas [1-9]: ");
			scanf(" %i", &played);
			if(played == 0) showMenu(menu, 18);
			
			if(played < 1 || played > 9) played = 0;
			else  if(posS[played - 1] != ' ') played = 0;
			else{
				if(vezde % 2 == 0) posS[played - 1] = 'X';
				else posS[played - 1] = 'O';
				
				contJog++;
				vezde++;
			}
			
			if (posS[0] == 'X' && posS [1] == 'X' && posS[2] == 'X') contJog = 11;
			if (posS[3] == 'X' && posS [4] == 'X' && posS[5] == 'X') contJog = 11;
			if (posS[6] == 'X' && posS [7] == 'X' && posS[8] == 'X') contJog = 11;
			if (posS[0] == 'X' && posS [3] == 'X' && posS[6] == 'X') contJog = 11;
			if (posS[1] == 'X' && posS [4] == 'X' && posS[7] == 'X') contJog = 11;
			if (posS[2] == 'X' && posS [5] == 'X' && posS[8] == 'X') contJog = 11;
			if (posS[0] == 'X' && posS [4] == 'X' && posS[8] == 'X') contJog = 11;
			if (posS[2] == 'X' && posS [4] == 'X' && posS[6] == 'X') contJog = 11;
			  
			if (posS[0] == 'O' && posS [1] == 'O' && posS[2] == 'O') contJog = 12;
			if (posS[3] == 'O' && posS [4] == 'O' && posS[5] == 'O') contJog = 12;
			if (posS[6] == 'O' && posS [7] == 'O' && posS[8] == 'O') contJog = 12;
			if (posS[0] == 'O' && posS [3] == 'O' && posS[6] == 'O') contJog = 12;
			if (posS[1] == 'O' && posS [4] == 'O' && posS[7] == 'O') contJog = 12;
			if (posS[2] == 'O' && posS [5] == 'O' && posS[8] == 'O') contJog = 12;
			if (posS[0] == 'O' && posS [4] == 'O' && posS[8] == 'O') contJog = 12;
			if (posS[2] == 'O' && posS [4] == 'O' && posS[6] == 'O') contJog = 12;
			
		}while(contJog <= 9);
		
		showTab(TAM, 5, TAM, posS);
		if(contJog == 10) printf("\n\n\tJogo Empatado.");
		if(contJog == 11) printf("\n\n\tVencedor X!");
		if(contJog == 12) printf("\n\n\tVencedor O!");	

		printf("\n\n\tDeseja jogar novamente? [S/N]\n\t\t\t\t  ");
		scanf(" %s", &res);
	
		res = toupper(res);
		if(res == 'N') showMenu(menu, 18);
	}while(res == 'S');
	
	getch();
}

	// bordas horizontais >> 1
void tab(int n){
	printf("\t");
	for(i = 0; i < n; i++) printf("%c", S);
}

	// bordas horizontais >> 2
void tab2(int n){
	for(i = 0; i < n; i++) printf("%c", S);
}

	// tabuleiro jogável
int showTab(int n, int x, int y, char *z){
	system("cls"); // limpa a tela sempre que a função é chamada
	puts("\n\n\t[ 0 ]. Voltar\n");
	tab(13);
	
	for(i = 0; i < x; i++){
		printf("\n\t");
		for(j = 0; j < y; j++){	
			if(j == 0 || j == y - 1) printf("%c", S); // bordas laterais	
		
			else if(i % 2 == 1 && j % 2 == 1) printf("---"); // divisões horizontais	
			else if(i % 2 == 0 && j == 2 || i % 2 == 0 && j == 4) printf("|");	// divisões verticais
			
			// jogabilidade: numpad do teclado
			else if(i == 4 && j == 1) printf(" %c ", z[0]);
			else if(i == 4 && j == 3) printf(" %c ", z[1]);
			else if(i == 4 && j == 5) printf(" %c ", z[2]);
			
			else if(i == 2 && j == 1) printf(" %c ", z[3]);
			else if(i == 2 && j == 3) printf(" %c ", z[4]);
			else if(i == 2 && j == 5) printf(" %c ", z[5]);
			
			else if(i == 0 && j == 1) printf(" %c ", z[6]);
			else if(i == 0 && j == 3) printf(" %c ", z[7]);
			else if(i == 0 && j == 5) printf(" %c ", z[8]);

			else printf(" "); // espaço entre "---"
		}
	}
	
	puts("");
	tab(13);	
}

	// tabuleiro visual >> como jogar
int showTabM(int n, int x, int y, char *z){
	tab(13);
	
	for(i = 0; i < x; i++){
		printf("\n\t");
		for(j = 0; j < y; j++){	
			if(j == 0 || j == y - 1) printf("%c", S); // bordas laterais	
		
			else if(i % 2 == 1 && j % 2 == 1) printf("---"); // divisões horizontais	
			else if(i % 2 == 0 && j == 2 || i % 2 == 0 && j == 4) printf("|");	// divisões verticais
			
			// como jogar: [1-9] >> numpad
			else if(i == 4 && j == 1) printf(" %c ", z[0]);
			else if(i == 4 && j == 3) printf(" %c ", z[1]);
			else if(i == 4 && j == 5) printf(" %c ", z[2]);
			
			else if(i == 2 && j == 1) printf(" %c ", z[3]);
			else if(i == 2 && j == 3) printf(" %c ", z[4]);
			else if(i == 2 && j == 5) printf(" %c ", z[5]);
			
			else if(i == 0 && j == 1) printf(" %c ", z[6]);
			else if(i == 0 && j == 3) printf(" %c ", z[7]);
			else if(i == 0 && j == 5) printf(" %c ", z[8]);
			
			else printf(" ");
		}
	}
	
	puts("");
	tab(13);	
	
	help();
}

	// como jogar
void help(){
	printf("\n\n ");
	tab2(29); // bordas horizontais
		
	printf("\n %c"
		" Utilize os n%cmeros do te-"
		" %c"
		"\n %c"
		" clado para jogar.        "
		" %c\n ", S, 163, S, S, S);
	
	tab2(29); // bordas horizontais
		
	sleep(8); // pausa de 8 secs >> limpa a tela e retorna ao menu
	
	showMenu(menu, 18); 
}
