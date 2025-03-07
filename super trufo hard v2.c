#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} CartaSuperTrunfo;

// Função para calcular a densidade demográfica
float calcularDensidade(CartaSuperTrunfo carta) {
    return carta.populacao / carta.area;
}

// Função para exibir uma carta
void exibirCarta(CartaSuperTrunfo carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

// Função para escolher um atributo para comparação
int escolherAtributo(int escolhido) {
    int opcao;
    do {
        printf("\nEscolha um atributo para comparar:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Demográfica\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        if (opcao == escolhido) {
            printf("\nVocê já escolheu esse atributo! Escolha outro.\n");
        }
    } while (opcao < 1 || opcao > 5 || opcao == escolhido);
    return opcao;
}

// Função para obter o valor do atributo escolhido
float obterValorAtributo(CartaSuperTrunfo carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return calcularDensidade(carta);
        default: return 0;
    }
}

// Função principal para comparar as cartas
void compararCartas(CartaSuperTrunfo carta1, CartaSuperTrunfo carta2) {
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);
    
    float valor1_carta1 = obterValorAtributo(carta1, atributo1);
    float valor1_carta2 = obterValorAtributo(carta2, atributo1);
    float valor2_carta1 = obterValorAtributo(carta1, atributo2);
    float valor2_carta2 = obterValorAtributo(carta2, atributo2);

    // Determinação dos vencedores individuais
    int vencedor1 = (atributo1 == 5) ? (valor1_carta1 < valor1_carta2) : (valor1_carta1 > valor1_carta2);
    int vencedor2 = (atributo2 == 5) ? (valor2_carta1 < valor2_carta2) : (valor2_carta1 > valor2_carta2);
    
    // Soma dos atributos
    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;
    
    // Determinação do vencedor final
    printf("\nResultados da Comparação:\n");
    printf("Atributo 1: %s -> Carta 1: %.2f | Carta 2: %.2f\n", 
           (atributo1 == 1) ? "População" : (atributo1 == 2) ? "Área" : (atributo1 == 3) ? "PIB" : (atributo1 == 4) ? "Pontos Turísticos" : "Densidade", 
           valor1_carta1, valor1_carta2);
    printf("Atributo 2: %s -> Carta 1: %.2f | Carta 2: %.2f\n", 
           (atributo2 == 1) ? "População" : (atributo2 == 2) ? "Área" : (atributo2 == 3) ? "PIB" : (atributo2 == 4) ? "Pontos Turísticos" : "Densidade", 
           valor2_carta1, valor2_carta2);
    printf("Soma Total -> Carta 1: %.2f | Carta 2: %.2f\n", soma1, soma2);
    
    if (soma1 > soma2) {
        printf("\nA Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (soma1 < soma2) {
        printf("\nA Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    // Exemplo de cartas pré-cadastradas
    CartaSuperTrunfo carta1 = {'A', "A01", "São Paulo", 12000000, 1521.11, 699, 50};
    CartaSuperTrunfo carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1182.30, 364, 45};
    
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    compararCartas(carta1, carta2);
    
    return 0;
}
