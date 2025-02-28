#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} CartaSuperTrunfo;

// Função para inserir os dados da carta
void inserirCarta(CartaSuperTrunfo *carta, int numero) {
    printf("\nInsira os dados da Carta %d:\n", numero);
    
    // Leitura do estado (A-H)
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado); // O espaço antes de %c evita problemas com buffer
    
    // Leitura do código da carta
    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigo); // Limita a leitura a 3 caracteres + '\0'

    // Limpa o buffer do teclado antes de ler a string
    getchar();

    // Leitura do nome da cidade
    printf("Nome da Cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; // Remove a quebra de linha se houver

    // Leitura dos demais dados
    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados da carta
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

int main() {
    CartaSuperTrunfo carta1, carta2;
    
    inserirCarta(&carta1, 1);
    inserirCarta(&carta2, 2);
    
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    return 0;
}

