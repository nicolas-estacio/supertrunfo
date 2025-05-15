#include <stdio.h>
#include <string.h>
#include <locale.h>



// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;               // Estado (A a Z)
    char codigo[4];            // Código (ex.: A01)
    char nomeCidade[50];       // Nome da cidade
    unsigned long int populacao; // População (unsigned long int)
    float area;                // Área (km²)
    float pib;                 // PIB (bilhões de reais)
    int pontosTuristicos;      // Número de pontos turísticos
    float densidade;           // Densidade populacional (calculada)
    float pibPerCapita;        // PIB per capita (calculado)
    float superPoder;          // Super Poder (calculado)
} Carta;

// Função para ler os dados de uma carta
void lerCarta(Carta *carta, int numeroCarta) {
    printf("\n=== Carta %d ===\n", numeroCarta);
    
    // Leitura do estado
    printf("Estado (A a Z): ");
    scanf(" %c", &carta->estado);
    while (carta->estado < 'A' || carta->estado > 'Z') {
        printf("Estado inválido! Digite novamente (A a Z): ");
        scanf(" %c", &carta->estado);
    }
    
    // Leitura do código
    printf("Código da carta (ex.: A01): ");
    scanf("%s", carta->codigo);
    while (strlen(carta->codigo) != 3 || carta->codigo[0] != carta->estado ||
           carta->codigo[1] < '0' || carta->codigo[1] > '4' || 
           carta->codigo[2] < '1' || carta->codigo[2] > '4') {
        printf("Código inválido! Digite novamente (ex.: A01): ");
        scanf("%s", carta->codigo);
    }
    
    // Leitura do nome da cidade
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // Lê string com espaços
    
    // Leitura da população
    printf("População: ");
    scanf("%lu", &carta->populacao);
    while (carta->populacao <= 0) {
        printf("População inválida! Digite novamente: ");
        scanf("%lu", &carta->populacao);
    }
    
    // Leitura da área
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    while (carta->area <= 0) {
        printf("Área inválida! Digite novamente: ");
        scanf("%f", &carta->area);
    }
    
	printf("PIB (bilhões de reais): ");
	while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
    	printf("PIB inválido! Digite novamente: ");
    	while (getchar() != '\n'); // limpa o buffer
	}
    
    // Leitura do número de pontos turísticos
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    while (carta->pontosTuristicos < 0) {
        printf("Número de pontos turísticos inválido! Digite novamente: ");
        scanf("%d", &carta->pontosTuristicos);
    }
}

// Função para calcular densidade populacional, PIB per capita e Super Poder
void calcularMetricas(Carta *carta) {
    // Densidade populacional = população / área
    carta->densidade = (float)carta->populacao / carta->area;
    
    // PIB per capita = PIB / população
    carta->pibPerCapita = carta->pib / carta->populacao;
    
    // Super Poder = soma de todos os atributos numéricos
    // Inverso da densidade = 1 / densidade
    float inversoDensidade = 1.0 / carta->densidade;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita + inversoDensidade;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\nCarta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar as cartas atributo por atributo
void compararCartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");
    
    // Comparação da população
    printf("População: Carta %d venceu (%d)\n", 
           carta1.populacao > carta2.populacao ? 1 : 2, 
           carta1.populacao > carta2.populacao ? 1 : 0);
    
    // Comparação da área
    printf("Área: Carta %d venceu (%d)\n", 
           carta1.area > carta2.area ? 1 : 2, 
           carta1.area > carta2.area ? 1 : 0);
    
    // Comparação do PIB
    printf("PIB: Carta %d venceu (%d)\n", 
           carta1.pib > carta2.pib ? 1 : 2, 
           carta1.pib > carta2.pib ? 1 : 0);
    
    // Comparação dos pontos turísticos
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2, 
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 0);
    
    // Comparação da densidade populacional (menor valor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           carta1.densidade < carta2.densidade ? 1 : 2, 
           carta1.densidade < carta2.densidade ? 1 : 0);
    
    // Comparação do PIB per capita
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 2, 
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 0);
    
    // Comparação do Super Poder
    printf("Super Poder: Carta %d venceu (%d)\n", 
           carta1.superPoder > carta2.superPoder ? 1 : 2, 
           carta1.superPoder > carta2.superPoder ? 1 : 0);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Carta carta1, carta2;
    
    // Leitura dos dados das cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    // Cálculo das métricas
    calcularMetricas(&carta1);
    calcularMetricas(&carta2);
    
    // Exibição dos dados das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Comparação das cartas
    compararCartas(carta1, carta2);
    
    return 0;
}
