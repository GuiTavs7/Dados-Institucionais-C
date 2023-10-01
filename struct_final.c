#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
    
//DEFININDO AS VARIAVEIS DE CONTROLE DOS LOOPS "FOR"

int alunos, qtd_disciplinas;

//DEFININDO AS STRUCTS

struct reg_cursos{
    char nome_curso[40];
};

struct reg_disciplinas{
    char nome_disciplina[40];
    int disciplinas_matriculadas, carga_horaria;
    float nota1, nota2, nota3, frequencia, media_final;
};

struct registro{
    char instituicao[40];
};
   
struct reg_alunos {
    struct reg_disciplinas disciplinas[100];
};

//USANDO AS STRUCTS COMO VETORES

struct registro registro_vetor[2];
struct reg_cursos cursos[2];

//COMANDO "fflush(stdin) - LIMPA O BUFFER DA MEMORIA"
//COMANDO "fgets(nome_string, tamanho_string, stdin) - COMANDO PARA INSERIR DADOS COM ESPACAMENTO EM STRINGS"
//COMANDO "scanf(%inicial_do_tipo_da_variavel_numerica, &nome_variavel) - COMANDO PARA INSERIR DADOS DE VARIAVEIS NUMERICAS

//PEDINDO PARA QUE O USUARIO INSIRA OS VALORES
   
printf("\n DADOS INSTITUCIONAIS \n ");
 
printf("\nInsira o nome da instituicao: ");
fflush(stdin);
fgets(registro_vetor[1].instituicao, 40, stdin);
        
printf("\nInsira o nome do curso: ");
fflush(stdin);
fgets(cursos[1].nome_curso, 40, stdin);
        
printf("Digite o numero de alunos: ");
scanf("%d", &alunos);

struct reg_alunos reg1_alunos[100];

//UTILIZANDO LOOP FOR PARA UM NUMERO DETERMINADO DE REPETICOES

for(int i = 0; i < alunos; i++) {
    
    printf("\nDADOS DO ALUNO %d \n", i + 1);
    
    printf("Digite o numero de disciplinas matriculadas do aluno %d: ", i + 1);
    scanf("%d", &qtd_disciplinas);
    
    //VAMOS USAR O LOOP DAS DISCIPLINAS DENTRO DO LOOP DOS ALUNOS
    
    for(int j = 0; j < qtd_disciplinas; j++){
        
        printf("\nDADOS DA DISCIPLINA %d", j + 1);
        
        printf("\nInsira o nome da disciplina: ");
        getchar();
        fgets(reg1_alunos[i].disciplinas[j].nome_disciplina, 40, stdin);
                        
        printf("Digite a carga horaria da disciplina: ");
        scanf("%d", &reg1_alunos[i].disciplinas[j].carga_horaria);
                        
        printf("Insira a nota 1: ");
        scanf("%f", &reg1_alunos[i].disciplinas[j].nota1);
                        
        printf("Insira a nota 2: ");
        scanf("%f", &reg1_alunos[i].disciplinas[j].nota2);
                        
        printf("Insira a nota 3: ");
        scanf("%f", &reg1_alunos[i].disciplinas[j].nota3);
                        
        reg1_alunos[i].disciplinas[j].media_final = (reg1_alunos[i].disciplinas[j].nota1 + reg1_alunos[i].disciplinas[j].nota2 + reg1_alunos[i].disciplinas[j].nota3) / 3;
                        
        printf("\nInsira a sua frequencia: ");
        scanf("%f", &reg1_alunos[i].disciplinas[j].frequencia);  
                             
    } 
}

//PRINTANDO OS DADOS INSERIDOS DE CADA ALUNO COM SUAS RESPECTIVAS MATERIAS NA TELA 

printf("\nDADOS INSERIDOS RESPECTIVAMENTE");

printf("\nNome da instituicao: %s", registro_vetor[1].instituicao);
printf("Nome do curso: %s\n", cursos[1].nome_curso);

//UTILIZANDO LOOP FOR PARA UM NUMERO DETERMINADO DE REPETICOES

for(int i=0; i<alunos; i++){
                
    printf("Dados do aluno %d \n", i+1);
    
        //VAMOS USAR O LOOP DAS DISCIPLINAS DENTRO DO LOOP DOS ALUNOS!!!
                
        for(int j=0; j<qtd_disciplinas; j++){
                
            printf("\nNome da disciplina: %d %s", j+1, reg1_alunos[i].disciplinas[j].nome_disciplina);
                        
            printf("\nCarga horaria: %d", reg1_alunos[i].disciplinas[j].carga_horaria);
                        
            printf("\nNota 1: %.2f", reg1_alunos[i].disciplinas[j].nota1);
                        
            printf("\nNota 2: %.2f", reg1_alunos[i].disciplinas[j].nota2);
                       
            printf("\nNota 3: %.2f", reg1_alunos[i].disciplinas[j].nota3);
                        
            printf("\nMedia: %.2f", reg1_alunos[i].disciplinas[j].media_final);
                        
            printf("\nFrequencia: %.2f", reg1_alunos[i].disciplinas[j].frequencia);
                        
            if(reg1_alunos[i].disciplinas[j].media_final >= 6 && reg1_alunos[i].disciplinas[j].frequencia >=75){
                
                printf("\nAprovado!!!\n");                                                          
            }
            else{
                printf("\nReprovado!!!\n");
            }
        }    
}
        
//FINALIZANDO O PROGRAMA  

  getch();
  return 0;
}
