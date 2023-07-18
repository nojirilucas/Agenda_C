#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define M 100
#define N 365
#define O 12

int id_unico = 1;

typedef enum STATUS_COMPROMISSO {
	A_SER_CUMPRIDO,
	ADIVAVEL,
	CANCELADO

} STATUS_COMPROMISSO;

typedef struct TDATA {
	int dia, mes, ano;
	int hora, minuto;
} TDATA;

typedef struct TCOMPROMISSO {
	char nome_do_compromisso[M];
	int identificador;
	int tipo_compromisso;
	bool adiavel;
	TDATA data;
	int duracao;
	STATUS_COMPROMISSO status;
	struct TCOMPROMISSO* prox_TCOMPROMISSO;
} TCOMPROMISSO;

typedef struct TAGENDA {
	char nome_professor[M];
	int ano;
	int id_agenda;
	TCOMPROMISSO* eventos;
	struct TAGENDA* prox_TAGENDA;
} TAGENDA;

int inicializa_compromisso(TCOMPROMISSO* comp, int tipo_compromisso, TDATA data, int duracao, char *nome, int identificador) {
	strcpy(comp->nome_do_compromisso, nome);
	comp->tipo_compromisso = tipo_compromisso;
	comp->data = data;
	comp->duracao = duracao;
	comp->status = A_SER_CUMPRIDO;
	comp->adiavel = false;
	comp->identificador += 1;
	TCOMPROMISSO* prox_TCOMPROMISSO = NULL;
	printf("Sucesso ao salvar compromisso:%d\n",comp->identificador);
	return 1;
}

void altera_prioridade(TCOMPROMISSO* comp) {
	while (1) {
		int novaPri;
		printf("DIGITE UMA OPCAO:\n");
		scanf("%d", &novaPri);
		if (novaPri <= 0 || novaPri >= 5) {
			printf(" Prioridade inexistente ;) \n");
		} else {
			comp->tipo_compromisso = novaPri;
			return;
		}
	}
}

int retorna_prioridade(TCOMPROMISSO* comp) {  
	return comp->tipo_compromisso;
}

bool Eadiavel(TCOMPROMISSO c, bool adiavel) { //PRIORIDADE NAO EH SUFICIENTE PARA AVALIAR SE EH ADIAVEL
	if (c.tipo_compromisso == 2 || c.tipo_compromisso == 4) {  // ser for aula ou evento não podera ser adiado, outros compromisso podem ser adiados.
		printf("NAO E ADIVAVEL\n");
		adiavel = false;
		return adiavel;
	} else {
		printf("ADIVAVEL\n");  //status tem que mudar para true;
		adiavel = true;
		return adiavel;
	}
}

int temConflito(TCOMPROMISSO prim, TCOMPROMISSO novo) {
}

void atribuiStatus(TCOMPROMISSO* comp, int novoStatus) {	//NAO EH SUFICIENTE
	if (comp->tipo_compromisso == 2 || comp->tipo_compromisso == 4) {
		printf(" Aulas e eventos nao podem ser adiados\n");
		return;
	} else {
		comp->status = novoStatus;
	}
}

int retornaStatus(TCOMPROMISSO* comp) {	 
	return comp->status;
}

/*ordem identificador, tipo, data, hora, duracao, nome de disciplina/aluno/reuniao/evento (ou razao), adiavel, status.*/
void imprimeCompromisso(TCOMPROMISSO* comp) {
	TDATA* dat;
	*dat = comp->data;

	printf(" Identificador do compromisso : %d \n", comp->identificador);
	printf(" Compromisso : %s \n", tipo_de_compromisso_string(comp->tipo_compromisso));
	printf(" Data : %d / %d / %d \n", dat->dia, dat->mes, dat->ano);
	printf(" Hora :  %d:%d\n", dat->hora, dat->minuto);
	printf(" Nome : %s \n", comp->nome_do_compromisso);

	int* Duracao = malloc(sizeof(int) * 3);
	converte_duracao(comp->duracao, Duracao);
	printf(" Duracao de dias : %d , horas : %d , minutos %d :  \n", Duracao[0], Duracao[1], Duracao[2]);

	bool a= Eadiavel(comp->adiavel);

	printf(" Pode ser adiado? %s:\n", comp->adiavel ? "sim" : "não");
}


int main(){
	TCOMPROMISSO novo;
    char nome[10] = "jamal" ;
    int tipo= 2;
    TDATA data;
    data.dia=12;
    data.mes=6;
    data.minuto=30 ;
    data.hora=8; 


		inicializa_compromisso(&novo,tipo,data,30,nome,0);

    	printf("Digite o tipo de compromisso:\n");
        fflush(stdin);
        scanf("%d", &tipo);

        printf("Digite a data dia/mes:\n");
        fflush(stdin);
        scanf("%d%d", &data.dia, &data.mes);

        printf("Digite a hora marcada:\n");
        fflush(stdin);
        scanf("%d%d", &data.hora, &data.minuto);

        printf("Digite o nome do compromisso:\n");
        getchar();
        fgets(nome,10,stdin);
        
        inicializa_compromisso(&novo,tipo,data,30,nome,0);  
        printf("%d\n",novo.identificador); 

    // inicializa_compromisso(&novo,tipo,data,30,nome,0);
    // printf("%d\n",novo.identificador);

    // inicializa_compromisso(&novo,tipo,data,30,nome,0);
    // printf("%d\n",novo.identificador);

    // inicializa_compromisso(&novo,tipo,data,30,nome,0);
    // printf("%d\n",novo.identificador);
}

