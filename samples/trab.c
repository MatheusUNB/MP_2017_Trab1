/*
*@Aluno: Alexander Matheus de Melo Lima
*@Matrícula: 12/0108534

*@Descrição da função: funcao que permite separar uma string em tokens delimitados pelo caracter definido no parametro delimiter
*@Params: -content => a string que será fatiada em tokens ; -point => o token encontrado; -delimiter => delimitador dos tokens
*@Return: retorna 1 enquanto exitir tokens disponiveis e 0 quando atingir o final  
*/

char tokenBuffer[1000];
int nextToken(char *content, char **point, char delimiter) {
static int lastIndex;
int tokenSize  = 0;
tokenBuffer[tokenSize++] = *(content + lastIndex); 
while(*(content + (++lastIndex)) != '\0') {
	if(*(content + (lastIndex)) == delimiter) {
		tokenBuffer[tokenSize] = '\0';
		*point = tokenBuffer;
		++lastIndex; // aponta para o proximo caracter depois do espaco em branco
		return 1;
	}

	tokenBuffer[tokenSize++] = *(content + lastIndex); 
}
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char const *argv[]) {
char *token;
char txt[50];
char txt2[50],txt3[50],del[40],cdel;
char txt4[50],txt5[50],del2[40],cdel2;
int num[6],i=0,j,n=0,first,soma=0,valido=0;
int contavirgula=0,contnum=1,qtd_caracteres;

printf("\nDigite: ");
scanf("%s",txt);

for(i=0;i<strlen(txt);i++){
	if (txt[i]=='[' && txt[i+1]==']')
		soma=-1;
}

//Se "//["
if (txt[0]=='/' && txt[1]=='/' && txt[2]=='[' && soma==0){
soma=0;	

	for(i=0;i<strlen(txt);i++){
		//Pega a posição do "]"		
		if(txt[i]==']'){
			if (n == 0){			
				j=i;
				first=j;
			}
			n++;
		}
	}		

	//Válido se após "]" for "\n"
	if (txt[j+1]=='\\' && txt[j+2]=='n'){
		
		//copiar texto depois do "\n"
		for(i=0;i<strlen(txt);i++){
			txt2[i]=txt[i+j+3];
			txt3[i]=txt[i+j+3];
		}
		
		//Primeiro delimitador
		for(i=0;i<(strlen(txt));i++){
			if (txt[i+3]!=']')		
				del[i]=txt[i+3];
			else
				del[i]='\0';
		}
		
		cdel=del[0];
		
		//converte tudo que for "n" ou "\" para ",", para entrar 
		//na lógica da função
		for(i=0;i<strlen(txt3);i++){
			if ((txt2[i] == 'n') || (txt2[i] == '\\'))
				txt2[i] = cdel;
		}
		
		//transforma delimitadores em espaço, menos um.
		for (i=0;i<strlen(txt2);i++){
        	if(txt2[i]==cdel && txt2[i]==txt2[i+1]){
        		txt2[i] = ' ';
        	}
		}
		//transforma espaços, em nada, até que todos os 
		//espaços sumam
		for(n=0;n<strlen(txt3);n++){
			for (int i = 0, posicao = 0; i < strlen(txt2); i++, posicao++){
				if (txt2[posicao] == ' '){
					posicao++;
				}
				txt2[i] = txt2[posicao];
			}
		}

		i=0;
		j=0;
		//separa a string em caracteres usando a função nextToken()
		while(nextToken(txt2, &token, cdel)){
			num[i]=atoi(token);//transforma char em int
			
			if (num[i] > 1000)
				num[i]=0;

			soma=soma+num[i];
			i++;
		}

		j=0;
		for(i=0; i<strlen(txt3); i++){
			if (txt3[i] == cdel){
				j++;
				//confere se existe algum delimitador errado
				if (j != strlen(del) && txt3[i+1] != cdel)
					soma=-1;
			}
			else{
				j=0;
				if (txt3[i] != '0' && txt3[i] != '1' && 
				txt3[i] != '2' && txt3[i] != '3' && 
				txt3[i] != '4' && txt3[i] != '5' &&
				txt3[i] != '6' && txt3[i] != '7' && 
				txt3[i] != '8' && txt3[i] != '9' &&
				txt3[i] != '\\' && txt3[i] != 'n')
				{
					soma=-1;
				}
			}
		}
	
		//conta o número de delimitadores e valida no meio do caminho
		for (i=0;i<strlen(txt3);i++){
			if (txt3[i] == cdel)
				contavirgula++;
			if (contavirgula==3){
				contavirgula=0;
				//Neste ponto quando há 3 números, se o delimitador não vier antes ou depois
				//de "\n", ou seja, vier algum número, será inválido
				if (((txt3[i]==cdel) && (txt3[i+1]!='\\' && txt3[i+2]!='n')) &&
				((txt3[i]==cdel) && (txt3[i-2]!='\\' && txt3[i-1]!='n'))){
					soma=-1;
					valido=1;
				}
			}
			else if (valido!=1){
				valido=0;
			}
		}

		if ((txt[strlen(txt)-2] != '\\') || (txt[strlen(txt)-1] != 'n')){
			soma=-1;
		}
	}

	//SEGUNDO DELIMITADOR///////////
	else if (txt[first+1]=='['){		

		for(i=first+1;i<strlen(txt);i++){
			//Pega a posição do SEGUNDO/último "]"		
			if(txt[i]==']'){
				j=i;
			}
		}		
		
		//Válido se após o SEGUNDO "]" for "\n"
		if (txt[j+1]=='\\' && txt[j+2]=='n'){

			//copiar texto depois do "\n"
			for(i=0;i<strlen(txt);i++){
				txt4[i]=txt[i+j+3];
				txt5[i]=txt[i+j+3];
			}
		
			//Primeiro delimitador
			for(i=0;i<(strlen(txt));i++){
				if (txt[i+3]!=']')		
					del[i]=txt[i+3];
				else
					del[i]='\0';
			}
		
			cdel=del[0];		

			//SEGUNDO delimitador
			for(i=0;i<(strlen(txt));i++){
				if (txt[i+first+2]!=']')		
					del2[i]=txt[i+first+2];
				else
					del2[i]='\0';
			}
			
			cdel2=del2[0];
			
			//converte tudo que for "n" ou "\" para ",", para entrar 
			//na lógica da função
			for(i=0;i<strlen(txt5);i++){
				if ((txt4[i] == 'n') || (txt4[i] == '\\'))
					txt4[i] = ',';
			}

			//transforma delimitadores em espaço, menos um.
			for (i=0;i<strlen(txt4);i++){
        		if((txt4[i]==cdel || txt4[i]==cdel2) && txt4[i]==txt4[i+1]){
        			txt4[i] = ' ';
        		}
			}
			//transforma espaços, em nada, até que todos os 
			//espaços sumam
			for(n=0;n<strlen(txt5);n++){
				for (int i = 0, posicao = 0; i < strlen(txt4); i++, posicao++){
					if (txt4[posicao] == ' '){
						posicao++;
					}
					txt4[i] = txt4[posicao];
				}
			}

			//transforma delimitadores em vírgula.
			for (i=0;i<strlen(txt4);i++){
        		if(txt4[i]==cdel || txt4[i]==cdel2){
        			txt4[i] = ',';
        		}
			}
		
			i=0;
			//separa a string em caracteres usando a função nextToken()
			while(nextToken(txt4, &token, ',')){
				num[i]=atoi(token);//transforma char em int
			
				if (num[i] > 1000)
					num[i]=0;

				soma=soma+num[i];
				i++;
			}
			
			j=0;
			for(i=0; i<strlen(txt5); i++){
				if (txt5[i] == cdel || txt5[i] == cdel2){
					j++;
					//confere se existe algum delimitador errado
					if ((j != strlen(del) && txt5[i+1] != cdel) && 
					(j != strlen(del2) && txt5[i+1] != cdel2) &&
					(txt5[i+1] != '\\' && txt5[i+1] != 'n'))
						soma=-1;
				}
				else{
					j=0;
					if (txt5[i] != '0' && txt5[i] != '1' && 
					txt5[i] != '2' && txt5[i] != '3' && 
					txt5[i] != '4' && txt5[i] != '5' &&
					txt5[i] != '6' && txt5[i] != '7' && 
					txt5[i] != '8' && txt5[i] != '9' &&
					txt5[i] != '\\' && txt5[i] != 'n'){
					soma=-1;}
				}
			}

			//conta o número de DELIMITADORES e valida no meio do caminho
			for (i=0;i<strlen(txt5);i++){
				if ((txt5[i] == cdel) || (txt5[i] == cdel2))
					contavirgula++;
				if (contavirgula==3){
					contavirgula=0;
					//Neste ponto quando há 3 números, se o delimitador não vier antes ou depois
					//de "\n", ou seja, vier algum número, será inválido
					if (((txt5[i] == cdel || txt5[i] == cdel2) && 
					(txt5[i+1]!='\\' && txt5[i+2]!='n')) &&
					((txt5[i] == cdel || txt5[i] == cdel2) && 
					(txt5[i-2]!='\\' && txt5[i-1]!='n'))){
						soma=-1;
						valido=1;
					}
				}
				else if (valido!=1){		
					valido=0;
				}
			}

			if ((txt[strlen(txt)-2] != '\\') || (txt[strlen(txt)-1] != 'n')){
				soma=-1;
			}
		}
		else{//Se estiver faltando o "\n"
			soma=-1;
		}	
	}	
	////////////////////////////////

	else{//Se estiver faltando o "\n"
		soma=-1;
	}
}

///////////part2.c////////////////////////////////////////////
else{

	qtd_caracteres=strlen(txt);

	//condições de validação

	//se tiverem duas vírgulas consecutivas é inválido
	for (i=0;i<qtd_caracteres;i++){
		if (txt[i] == ',' && txt[i+1] == ','){
			soma=-1;
			valido=1;
		}

	}

	

	//contar a quantidade de NÚMEROS da string, depois da "," ou "\n"
	for (i=0;i<qtd_caracteres;i++){
		
	if (((txt[i]==',') && (txt[i+1]=='0' || txt[i+1]=='1' || 
	txt[i+1]=='2' || txt[i+1]=='3' || txt[i+1]=='4' || 
		txt[i+1]=='5' || txt[i+1]=='6' || txt[i+1]=='7' || 
		txt[i+1]=='8' || txt[i+1]=='9')) ||
		((txt[i]=='n') && (txt[i+1]=='0' || txt[i+1]=='1' || 
		txt[i+1]=='2' || txt[i+1]=='3' || txt[i+1]=='4' || 
		txt[i+1]=='5' || txt[i+1]=='6' || txt[i+1]=='7' || 
		txt[i+1]=='8' || txt[i+1]=='9'))){
			contnum++;
		}
	
	}

	//conta o número de VÍRGULAS e valida no meio do caminho
	for (i=0;i<qtd_caracteres;i++){
		if (txt[i] == ',')
			contavirgula++;
		if (contavirgula==3){
			contavirgula=0;
			//Neste ponto quando há 3 números, se a vírgula não vier antes ou depois
			//de "\n", ou seja, vier algum número, será inválido
			if (((txt[i]==',') && (txt[i+1]!='\\' && txt[i+2]!='n')) &&
			((txt[i]==',') && (txt[i-2]!='\\' && txt[i-1]!='n'))){
				soma=-1;
				valido=1;
			}
		}
		else if (valido!=1){
			soma=0;		
			valido=0;
		}
	}

	contavirgula=0;
	//conta o número de VÍRGULAS
	for (i=0;i<qtd_caracteres;i++){
		if (txt[i] == ',')
			contavirgula++;}

	//se tiver a mesma quantidade de "," que números é invalido
	if (contnum <= contavirgula || contnum-contavirgula>=2) {
		valido=1;
		soma=-1;
	}
	else if (valido!=1){
		valido=0;
		soma=0;
	}

	//se "," for o primeiro caracter é invalido 
	for (i=0;i<qtd_caracteres;i++){
		if (txt[0] == ','){
			soma=-1;
			valido=1;
		}
	}
	
	//se o final for diferente de "\n" será inválido
	if ((txt[qtd_caracteres-2] != '\\') || (txt[qtd_caracteres-1] != 'n')){
		soma=-1;
		valido=1;
	}

	//evita que seja considerado o separador decimal
	for (i=0;i<qtd_caracteres;i++){
		if (txt[i] == '.'){
			soma=-1;
			valido=1;
		}
	}

	//a string só reconhece "0-9", "\n" e "," se for diferente é invalido 
	for (i=0;i<qtd_caracteres;i++){
	
		if (txt[i] != ',' && txt[i] != '\\' && txt[i] != 'n' &&
		txt[i] != '0' && txt[i] != '1' && txt[i] != '2' &&
		txt[i] != '3' && txt[i] != '4' && txt[i] != '5' &&
		txt[i] != '6' && txt[i] != '7' && txt[i] != '8' && txt[i] != '9'){
			soma=-1;
			valido=1;
		}
	}

	if (valido == 1)
		soma=-1;		

//////////////////////////////////////////////////////////////////	
		//se for válido entra nessa rotina a seguir
		else{
			contavirgula=0;
			//conta o número de VÍRGULAS
			for (i=0;i<qtd_caracteres;i++){
				if (txt[i] == ',')
					contavirgula++;}

		//converte tudo que for "n" ou "\" para ",", para entrar 
		//na lógica da função
		for(i=0;i<qtd_caracteres;i++){
			if ((txt[i] == 'n') || (txt[i] == '\\'))
				txt[i] = ',';
		}

		i=0;

		//separa a string em caracteres usando a função nextToken()
		while(nextToken(txt, &token, ',')){
			
			num[i]=atoi(token);//transforma char em int
			
			if (num[i] > 1000)
				num[i]=0;
			i++;
		}

		//faz a soma
			for(j=0;j<i;j++){
				soma = soma + num[j];
			}
		
	}
}

printf("\n%d\n\n", soma);
return soma;
}
