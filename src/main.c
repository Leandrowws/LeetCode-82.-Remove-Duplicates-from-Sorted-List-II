#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
    struct ListNode *next;
};

typedef struct {
    int tam;
    struct ListNode *inicio;
} Lista;

void CriarLista(Lista *lista) {
    lista->tam = 0;
    lista->inicio = NULL;
}

void Inserir(Lista *lista, int num) {
    struct ListNode *aux, *novo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novo->val = num;

    if(novo != NULL) {

        if(lista->inicio == NULL) {
            lista->inicio = novo;
           
        } else {
            aux = lista->inicio;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = novo;   
        }
        novo->next = NULL;

    } else {
        printf("Erro ao alocar memoria!");
    }
}

void Imprimir(Lista lista) {
    struct ListNode *no = lista.inicio;

    while(no) {
        printf("%d ", no->val);
        no = no->next;
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *aux = &dummy;

    while(aux->next != NULL && aux->next->next != NULL) {

        if(aux->next->val == aux->next->next->val) {

            int repetido = aux->next->val;

            while(aux->next != NULL && aux->next->val == repetido) {

                struct ListNode *temp = aux->next;
                aux->next = aux->next->next;
                free(temp);
            }

        } else {

            aux = aux->next;
        }
    }

    return dummy.next;
}

int main() {
    
    Lista lista;
    CriarLista(&lista);

    Inserir(&lista, 2);
    Inserir(&lista, 3);
    Inserir(&lista, 3);
    Inserir(&lista, 5);
    Inserir(&lista, 5);
    Inserir(&lista, 5);
    Inserir(&lista, 7);
    Inserir(&lista, 7);
    Inserir(&lista, 11);
    Inserir(&lista, 11);
    Inserir(&lista, 11);
    Inserir(&lista, 13);

    deleteDuplicates(lista.inicio);

    Imprimir(lista);

    return 0;
}
