#include <stdio.h>

#define NUM_PAISES 5

// Definição da estrutura de uma carta de país
typedef struct {
    char nome[50];
    float pib;              // Produto Interno Bruto (em trilhões)
    float populacao;        // População (em milhões)
    float area;             // Área (em km²)
    float densidade_demografica; // Densidade demográfica (habitantes por km²)
} Pais;

// Função para exibir os dados de uma carta
void exibirCarta(Pais carta) {
    printf("Nome: %s\n", carta.nome);
    printf("PIB: %.2f trilhões\n", carta.pib);
    printf("População: %.2f milhões\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("Densidade Demográfica: %.2f habitantes por km²\n", carta.densidade_demografica);
}

// Função para exibir o menu de escolha de atributos
void exibirMenuAtributos() {
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. PIB\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. Densidade Demográfica\n");
}

void exibirMenuSegundoAtributo() {
    printf("\nEscolha o segundo atributo para comparar (não pode ser o mesmo do primeiro):\n");
    printf("1. PIB\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. Densidade Demográfica\n");
}

// Função para comparar os atributos selecionados
float compararAtributos(Pais pais1, Pais pais2, int atributo) {
    switch(atributo) {
        case 1: // PIB
            return pais1.pib - pais2.pib;
        case 2: // População
            return pais1.populacao - pais2.populacao;
        case 3: // Área
            return pais1.area - pais2.area;
        case 4: // Densidade Demográfica
            return pais2.densidade_demografica - pais1.densidade_demografica; // Menor vence
        default:
            return 0.0;
    }
}

// Função para comparar as cartas com base nos dois atributos
void compararCartas(Pais pais1, Pais pais2, int atributo1, int atributo2) {
    float resultado1 = 0, resultado2 = 0;

    // Comparação do primeiro atributo
    resultado1 = compararAtributos(pais1, pais2, atributo1);
    resultado2 = compararAtributos(pais2, pais1, atributo1);
    
    // Comparação do segundo atributo
    resultado1 += compararAtributos(pais1, pais2, atributo2);
    resultado2 += compararAtributos(pais2, pais1, atributo2);
    
    // Exibição do resultado final
    printf("\n--- Resultado da Comparação ---\n");
    printf("País 1: %s, País 2: %s\n", pais1.nome, pais2.nome);
    printf("Soma dos Atributos (País 1): %.2f\n", resultado1);
    printf("Soma dos Atributos (País 2): %.2f\n", resultado2);

    if (resultado1 > resultado2) {
        printf("\nVencedor: %s\n", pais1.nome);
    } else if (resultado1 < resultado2) {
        printf("\nVencedor: %s\n", pais2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    Pais paises[NUM_PAISES] = {
        {"Brasil", 2.055, 211.05, 8.515, 24.8},
        {"EUA", 21.43, 329.5, 9.83, 35.1},
        {"China", 14.34, 1393.8, 9.6, 147.3},
        {"Alemanha", 3.846, 83.02, 0.357, 232.0},
        {"Índia", 2.87, 1380, 3.287, 420.0}
    };

    int atributo1, atributo2;

    // Exibir o menu de atributos e selecionar o primeiro atributo
    exibirMenuAtributos();
    scanf("%d", &atributo1);

    // Exibir o menu para selecionar o segundo atributo
    exibirMenuSegundoAtributo();
    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("Erro: Você não pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // Exibir as opções de países para o jogador escolher
    printf("\nEscolha os dois países para comparar:\n");
    for (int i = 0; i < NUM_PAISES; i++) {
        printf("%d. %s\n", i + 1, paises[i].nome);
    }

    int paisEscolhido1, paisEscolhido2;
    printf("\nEscolha o primeiro país: ");
    scanf("%d", &paisEscolhido1);

    printf("Escolha o segundo país: ");
    scanf("%d", &paisEscolhido2);

    // Ajustar os índices para as cartas
    Pais pais1 = paises[paisEscolhido1 - 1];
    Pais pais2 = paises[paisEscolhido2 - 1];

    // Comparar as cartas com os atributos escolhidos
    compararCartas(pais1, pais2, atributo1, atributo2);

    return 0;
}
