#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
    int densidade_demografica;
} Carta;

void exibirOpcoes(int atributoEscolhido) {
    printf("Escolha um atributo (diferente do primeiro, se já escolhido):\n");
    if (atributoEscolhido != 1) {
        printf("1 - Força\n");
    }
    if (atributoEscolhido != 2) {
        printf("2 - Velocidade\n");
    }
    if (atributoEscolhido != 3) {
        printf("3 - Inteligência\n");
    }
    if (atributoEscolhido != 4) {
        printf("4 - Densidade Demográfica\n");
    }
}

int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.forca;
        case 2: return c.velocidade;
        case 3: return c.inteligencia;
        case 4: return c.densidade_demografica;
        default: return 0;
    }
}

void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    int valor1_attr1 = obterValorAtributo(c1, atributo1);
    int valor2_attr1 = obterValorAtributo(c2, atributo1);
    int valor1_attr2 = obterValorAtributo(c1, atributo2);
    int valor2_attr2 = obterValorAtributo(c2, atributo2);

    int pontos_c1 = 0, pontos_c2 = 0;

    pontos_c1 += (atributo1 == 4) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1); 
    pontos_c2 += (atributo1 == 4) ? (valor1_attr1 > valor2_attr1) : (valor1_attr1 < valor2_attr1); 

    pontos_c1 += (atributo2 == 4) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    pontos_c2 += (atributo2 == 4) ? (valor1_attr2 > valor2_attr2) : (valor1_attr2 < valor2_attr2);

    int soma_c1 = valor1_attr1 + valor1_attr2;
    int soma_c2 = valor2_attr1 + valor2_attr2;

    printf("\nComparacao:\n");
    printf("%s - %d (Attr1) + %d (Attr2) = %d\n", c1.nome, valor1_attr1, valor1_attr2, soma_c1);
    printf("%s - %d (Attr1) + %d (Attr2) = %d\n", c2.nome, valor2_attr1, valor2_attr2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("%s vence a rodada!\n", c1.nome);
    } else if (soma_c1 < soma_c2) {
        printf("%s vence a rodada!\n", c2.nome);
    } else {
        printf("Empate!\n"); 
    }
}

int main() {
    
    Carta carta1 = {"Brasil", 8, 7, 6, 3};
    Carta carta2 = {"Japão", 6, 4, 8, 5};

    int atributo1, atributo2;

    printf("Super Trunfo - Comparacao de Cartas!\n\n");

    
    printf("Escolha o primeiro atributo para comparar:\n");
    exibirOpcoes(0);
    scanf("%d", &atributo1);

    
    do {
        printf("Escolha o segundo atributo para comparar:\n");
        exibirOpcoes(atributo1);
        scanf("%d", &atributo2);

        if (atributo1 == atributo2) {
            printf("Erro: Você escolheu o mesmo atributo duas vezes. Escolha outro atributo.\n");
        }
    } while (atributo1 == atributo2);


    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
