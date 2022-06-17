#include <cstdio>
struct No{
    int dado;
    struct No *prox;
} *inicio = nullptr;

char menu(){
    char op; //op = opção
    printf("\nEscolha uma opcao: \n\n0 - Encerrar o programa \n1 - Inserir numero \n2 - Imprimir os numeros \n3 - Inserir o numero no final \n4 - Buscar numero \n5 - Trocar numero \n\nOpcao: ");
    scanf("%c%*C", &op);
    return op;
}

void insere(int numero){
    struct No *novo;
    novo = new struct No(); //"novo" irá receber o endereço da estrutura Nó
    novo->dado = numero;
    novo->prox = inicio;
    inicio = novo; //O "início" vai apontar para o endereço que "novo" aponta
}

void insereFinal(int numero) {
    if (inicio == nullptr){
        insere(numero);
    }
    else {
        struct No *novo;
        struct No *aux;
        novo = new struct No();
        novo->dado = numero;
        for (aux = inicio; aux -> prox != nullptr; aux = aux -> prox){} //O "aux" vai apontar para o endereço que "inicio" aponta
        novo->prox = aux -> prox;
        aux->prox = novo;//O "prox" vai apontar para o endereço que "novo" aponta
    }
}

void imprime(){
    struct No *aux;
    printf("\nLista...");
    if (inicio == nullptr)
        printf(" vazia!\n");
    else {
        printf("\n");
        for (aux = inicio; aux != nullptr; aux=aux->prox) {
            printf("%d | ", aux->dado);
        }
        printf("\n");
    }
}

struct No *buscar(int numero){
    struct No *aux;
    for (aux = inicio; aux != nullptr; aux=aux->prox){
        if (numero == aux->dado){
            printf("O numero %d foi encontrado no endereco %p", numero, aux);
            return aux;
        }
    }
    printf("Numero %d nao encontrado!\n", numero);
    return nullptr;
}

void trocar(){
    int numero;
    printf("Qual numero voce quer trocar?");
    scanf ("%d%*C", &numero);
    struct No *aux = buscar(numero);
    if (aux == nullptr) {
        return;
    }
    printf("Qual o numero voce quer substituir da lista?");
    scanf ("%d%*C", &aux->dado);
    printf("Pronto!");
}
int main(){
    char op;
    int num;
    do {
        op = menu();
        switch (op){
            case '1':
                printf("Digite um numero para inserir na lista: ");
                scanf ("%d%*C", &num);
                insere(num);
                break;
            case '2': 
				imprime(); 
				break;
            case '3':
                printf("Digite um numero para inserir no final da lista: ");
                scanf ("%d%*C", &num);
                insereFinal(num);
                break;
            case '4':
                printf("Digite um numero para buscar na lista: ");
                scanf ("%d%*C", &num);
                buscar(num);
                break;
            case '5':
                trocar();
                break;
            default :
                if (op != '0')
                    printf ("\nEscolha errada!!\n");
                else
                    printf ("\nO programa foi encerrado!");
        }
    } while (op != '0');
    return 0;
}