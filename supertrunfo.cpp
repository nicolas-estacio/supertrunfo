#include <stdio.h>
#include <string.h>
#include <locale.h>



// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;               // Estado (A a Z)
    char codigo[4];            // C�digo (ex.: A01)
    char nomeCidade[50];       // Nome da cidade
    unsigned long int populacao; // Popula��o (unsigned long int)
    float area;                // �rea (km�)
    float pib;                 // PIB (bilh�es de reais)
    int pontosTuristicos;      // N�mero de pontos tur�sticos
    float densidade;           // Densidade populacional (calculada)
    float pibPerCapita;        // PIB per capita (calculado)
    float superPoder;          // Super Poder (calculado)
} Carta;

// Fun��o para ler os dados de uma carta
void lerCarta(Carta *carta, int numeroCarta) {
    printf("\n=== Carta %d ===\n", numeroCarta);
    
    // Leitura do estado
    printf("Estado (A a Z): ");
    scanf(" %c", &carta->estado);
    while (carta->estado < 'A' || carta->estado > 'Z') {
        printf("Estado inv�lido! Digite novamente (A a Z): ");
        scanf(" %c", &carta->estado);
    }
    
    // Leitura do c�digo
    printf("C�digo da carta (ex.: A01): ");
    scanf("%s", carta->codigo);
    while (strlen(carta->codigo) != 3 || carta->codigo[0] != carta->estado ||
           carta->codigo[1] < '0' || carta->codigo[1] > '4' || 
           carta->codigo[2] < '1' || carta->codigo[2] > '4') {
        printf("C�digo inv�lido! Digite novamente (ex.: A01): ");
        scanf("%s", carta->codigo);
    }
    
    // Leitura do nome da cidade
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // L� string com espa�os
    
    // Leitura da popula��o
    printf("Popula��o: ");
    scanf("%lu", &carta->populacao);
    while (carta->populacao <= 0) {
        printf("Popula��o inv�lida! Digite novamente: ");
        scanf("%lu", &carta->populacao);
    }
    
    // Leitura da �rea
    printf("�rea (km�): ");
    scanf("%f", &carta->area);
    while (carta->area <= 0) {
        printf("�rea inv�lida! Digite novamente: ");
        scanf("%f", &carta->area);
    }
    
	printf("PIB (bilh�es de reais): ");
	while (scanf("%f", &carta->pib) != 1 || carta->pib <= 0) {
    	printf("PIB inv�lido! Digite novamente: ");
    	while (getchar() != '\n'); // limpa o buffer
	}
    
    // Leitura do n�mero de pontos tur�sticos
    printf("N�mero de pontos tur�sticos: ");
    scanf("%d", &carta->pontosTuristicos);
    while (carta->pontosTuristicos < 0) {
        printf("N�mero de pontos tur�sticos inv�lido! Digite novamente: ");
        scanf("%d", &carta->pontosTuristicos);
    }
}

// Fun��o para calcular densidade populacional, PIB per capita e Super Poder
void calcularMetricas(Carta *carta) {
    // Densidade populacional = popula��o / �rea
    carta->densidade = (float)carta->populacao / carta->area;
    
    // PIB per capita = PIB / popula��o
    carta->pibPerCapita = carta->pib / carta->populacao;
    
    // Super Poder = soma de todos os atributos num�ricos
    // Inverso da densidade = 1 / densidade
    float inversoDensidade = 1.0 / carta->densidade;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita + inversoDensidade;
}

// Fun��o para exibir os dados de uma carta
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\nCarta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("C�digo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Popula��o: %lu\n", carta.populacao);
    printf("�rea: %.2f km�\n", carta.area);
    printf("PIB: %.2f bilh�es de reais\n", carta.pib);
    printf("N�mero de Pontos Tur�sticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km�\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Fun��o para comparar as cartas atributo por atributo
void compararCartas(Carta carta1, Carta carta2) {
    printf("\nCompara��o de Cartas:\n");
    
    // Compara��o da popula��o
    printf("Popula��o: Carta %d venceu (%d)\n", 
           carta1.populacao > carta2.populacao ? 1 : 2, 
           carta1.populacao > carta2.populacao ? 1 : 0);
    
    // Compara��o da �rea
    printf("�rea: Carta %d venceu (%d)\n", 
           carta1.area > carta2.area ? 1 : 2, 
           carta1.area > carta2.area ? 1 : 0);
    
    // Compara��o do PIB
    printf("PIB: Carta %d venceu (%d)\n", 
           carta1.pib > carta2.pib ? 1 : 2, 
           carta1.pib > carta2.pib ? 1 : 0);
    
    // Compara��o dos pontos tur�sticos
    printf("Pontos Tur�sticos: Carta %d venceu (%d)\n", 
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2, 
           carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 0);
    
    // Compara��o da densidade populacional (menor valor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           carta1.densidade < carta2.densidade ? 1 : 2, 
           carta1.densidade < carta2.densidade ? 1 : 0);
    
    // Compara��o do PIB per capita
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 2, 
           carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 0);
    
    // Compara��o do Super Poder
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
    
    // C�lculo das m�tricas
    calcularMetricas(&carta1);
    calcularMetricas(&carta2);
    
    // Exibi��o dos dados das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Compara��o das cartas
    compararCartas(carta1, carta2);
    
    return 0;
}
