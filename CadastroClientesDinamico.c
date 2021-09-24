#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    int ano;
    float montante;
} Cliente;

void pausar()
{
    printf("Pressione ENTER para continuar! ");
    fflush(stdin);
    getchar();
    fflush(stdin);
}

int menu();
void inserir(Cliente *ptr, int qte);
int excluir(Cliente *ptr, int qte);
void atualizar(Cliente *ptr, int qte);
void zerar(Cliente *ptr, int qte);
void print(Cliente *ptr, int qte);
void melhor(Cliente *ptr, int qte);
int buscar(Cliente *ptr, int qte);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int op, qte=0;
    Cliente *ptr = malloc(10*sizeof(Cliente)); //Reserva 10 espa�os na mem�ria.
    if(ptr==NULL){
        printf("[ERRO] Mem�ria Indispon�vel! Volte mais tarde!!!\n");
        exit(1);
    }
    do{
        op = menu();
        switch(op)
        {
        case 1:
            inserir(ptr+qte, qte);
            qte++;
            if(qte%10==0){
                ptr = realloc(ptr, (qte+10)*(sizeof(Cliente))); //Reajusta mais 10 espa�os na mem�ria.
                if(ptr==NULL){
                    printf("[ERRO] Mem�ria Indispon�vel!");
                    exit(1);
                }
            }
            break;
        case 2:
            if(qte>0){
                qte = excluir(ptr, qte);
                if((qte+1)%10==0)
                {
                    ptr = realloc(ptr, (qte+1)*(sizeof(Cliente))); // Reajusta menos dez espa�os na mem�ria.
                    if(ptr==NULL){
                        printf("[ERRO] Mem�ria Indispon�vel!");
                        exit(1);
                    }
                }
            } else
                printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
            pausar();
            break;
        case 3:
            if(qte>0)
                atualizar(ptr, qte);
            else {
                printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
                pausar();
            }
            break;
        case 4:
            if(qte>0)
                zerar(ptr, qte);
            else {
                printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
                pausar();
            }
            break;
        case 5:
            print(ptr, qte);
            break;
        case 6:
            if(qte>0)
                melhor(ptr, qte);
            else {
                printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
            }
            pausar();
            break;
        case 7:
            if(qte>0){
                system("cls");
                printf(" === PERFIL CLIENTE ===\n\n");
                op = buscar(ptr, qte);
                if(op==-1)
                    printf("\nCliente inexistente!\n\n");
            } else
                printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
            pausar();
            break;
        case 8:
            printf("\nO programa ser� encerrado. Confirmar? [1]SIM / [0]N�O ");
            scanf("%d", &op);
            if(op){
                printf("\nPROGRAMA FINALIZADO!!!\n");
                return 0;
            }
            printf("\nRetornando ao programa!\n\n");
            pausar();
            break;
        default:
            printf("\n[ERRO] Op��o Inexistente! Tente uma op��o v�lida.\n\n");
            pausar();
        }
        op = 0;
    } while(!op);
}

int menu()
{
    int op;
    system("cls");
    printf(" === MENU - LOJA ===\n\n1 - Cadastrar Cliente\n2 - Excluir Cliente\n"
           "3 - Atualizar Compras Cliente\n4 - Zerar Todas as Compras / Virada M�s\n5 - Listar Clientes\n"
           "6 - Melhor Cliente\n7 - Exibir Compras Cliente\n8 - Sair\n\nDigite a op��o desejada: ");
    scanf("%d", &op);
    return op;
}

void inserir(Cliente *ptr, int qte)
{
    system("cls");
    printf(" === CADASTRAR CLIENTE %d ===\n\nDigite o nome: ", qte+1);
    fflush(stdin);
    fgets(ptr->nome,30,stdin);
    strcpy(ptr->nome,strupr(ptr->nome));
    printf("Digite o ano de nascimento[AAAA]: ");
    scanf("%d", &ptr->ano);
    ptr->montante = 0;
    printf("\nCLIENTE CADASTRADO!\n\nPara registrar compras, escolha a op��o 3 do Menu.\n\n");
    pausar();
}

int excluir(Cliente *ptr, int qte)
{
    int pos, i, op;
    system("cls");
    printf(" === EXCLUIR CLIENTE ===\n\n");
    pos = buscar(ptr, qte);
    if(pos==-1){
        printf("\nCliente inexistente.\n\n");
        return qte;
    }
    printf("Deseja realmente excluir o cliente? [1]SIM / [0]N�O ");
    scanf("%d", &op);
    if(!pos && op && qte==1){
        ptr = NULL;
        free(ptr);
        qte--;
        printf("\nCliente exclu�do com sucesso!!!\n\nLista Vazia!\n\n");
        return qte;
    } if(op){
        for(i=pos;i<qte-1;i++)
            memcpy(ptr+i, ptr+i+1, sizeof(Cliente));
            printf("\nCliente exclu�do com sucesso!!!\n\n");
        return --qte;
    }
    printf("\nProcesso de exclus�o cancelado!\n\n");
    return qte;
}

void atualizar(Cliente *ptr, int qte)
{
    int pos;
    float valor;
    system("cls");
    printf(" === ATUALIZAR VALORES CLIENTE ===\n\n");
    pos = buscar(ptr, qte);
    if(pos==-1)
        printf("\nCliente inexistente.\n\n");
    else {
        printf("Digite o valor: ");
        scanf("%f", &valor);
        (ptr+pos)->montante += valor;
        system("cls");
        printf(" === ATUALIZAR VALORES CLIENTE ===\n\n\n");
        printf("\n === CLIENTE %d ===\n\n", pos+1);
        printf("Nome: %sNasc: %d\nTotal: R$%.2f\n\n", (ptr+pos)->nome, (ptr+pos)->ano, (ptr+pos)->montante);
    }
    pausar();
}

void zerar(Cliente *ptr, int qte)
{
    int i, op;
    system("cls");
    printf("\n[ATEN��O] TODOS os clientes ter�o o montante ZERADO!\n\nConfirmar? [1]SIM / [0]VOLTAR ");
    scanf("%d", &op);
    if(op){
        for(i=0;i<qte;i++){
            ptr->montante = 0;
            ptr++;
        }
        printf("\nTODOS OS MONTANTES FORAM ZERADOS!!!\n\n");
    } else
        printf("\nOpera��o Cancelada!\n\n");
    pausar();
}

void print(Cliente *ptr, int qte)
{
    int i;
    if(qte>0){
        system("cls");
        for(i=0;i<qte;i++){
            printf(" === CLIENTE %d ===\n\n", i+1);
            printf("Nome: %sNasc: %d\nTotal: R$%.2f\n\n", (ptr+i)->nome, (ptr+i)->ano, (ptr+i)->montante);
        }
    } else
        printf("\n[ERRO] N�o existem clientes cadastrados.\n\n");
    pausar();
}

void melhor(Cliente *ptr, int qte)
{
    int i, pos=0;
    Cliente *melhor = ptr;
    for(i=0;i<qte;i++){
        if((ptr+i)->montante>melhor->montante){
            melhor = ptr+i;
            pos = i;
        }
    }
    system("cls");
    printf(" === MELHOR CLIENTE ===\n\n === CLIENTE %d ===\n\n", pos+1);
    printf("Nome: %sNasc: %d\nTotal: R$%.2f\n\n", melhor->nome, melhor->ano, melhor->montante);
}

int buscar(Cliente *ptr, int qte)
{
    int i=0;
    char name[30];
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(name,30,stdin);
    while(i<qte){
        if(!strcmp((ptr+i)->nome,strupr(name))){
            printf("\n === CLIENTE %d ===\n\n", i+1);
            printf("Nome: %sNasc: %d\nTotal: R$%.2f\n\n", (ptr+i)->nome, (ptr+i)->ano, (ptr+i)->montante);
            return i;
        }
        i++;
        if(i==qte)
            return -1;
    }
}
