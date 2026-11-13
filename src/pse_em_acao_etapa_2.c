#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACOES 100

typedef struct {
    int codigo;
    char escola[100];
    char tema[100];
    char data[20];
    char publicoAlvo[100];
    char responsavel[100];
    int participantesPlanejados;
    int participantesRealizados;
    char situacao[20];
} Acao;

void limparEnter(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

void lerTexto(char mensagem[], char destino[], int tamanho) {
    do {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        limparEnter(destino);

        if (strlen(destino) == 0) {
            printf("Campo obrigatorio. Tente novamente.\n");
        }
    } while (strlen(destino) == 0);
}

int lerInteiro(char mensagem[]) {
    char entrada[50];
    int valor;
    char extra;

    while (1) {
        printf("%s", mensagem);
        fgets(entrada, sizeof(entrada), stdin);

        if (sscanf(entrada, "%d %c", &valor, &extra) == 1) {
            return valor;
        }

        printf("Entrada invalida. Digite um numero inteiro.\n");
    }
}

int codigoExiste(Acao acoes[], int quantidade, int codigo) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (acoes[i].codigo == codigo) {
            return 1;
        }
    }

    return 0;
}

int localizarCodigo(Acao acoes[], int quantidade, int codigo) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void mostrarAcao(Acao a) {
    printf("\n---------------------------------------------\n");
    printf("Codigo: %d\n", a.codigo);
    printf("Escola: %s\n", a.escola);
    printf("Tema: %s\n", a.tema);
    printf("Data prevista: %s\n", a.data);
    printf("Publico-alvo: %s\n", a.publicoAlvo);
    printf("Responsavel: %s\n", a.responsavel);
    printf("Participantes previstos: %d\n", a.participantesPlanejados);
    printf("Participantes efetivos: %d\n", a.participantesRealizados);
    printf("Situacao: %s\n", a.situacao);
    printf("---------------------------------------------\n");
}

void cadastrarAcao(Acao acoes[], int *quantidade) {
    Acao nova;

    if (*quantidade >= MAX_ACOES) {
        printf("\nLimite de 100 acoes atingido.\n");
        return;
    }

    printf("\n===== CADASTRO DE ACAO =====\n");

    while (1) {
        nova.codigo = lerInteiro("Codigo: ");

        if (nova.codigo <= 0) {
            printf("O codigo deve ser maior que zero.\n");
        } else if (codigoExiste(acoes, *quantidade, nova.codigo)) {
            printf("Codigo ja cadastrado. Informe outro.\n");
        } else {
            break;
        }
    }

    lerTexto("Escola: ", nova.escola, sizeof(nova.escola));
    lerTexto("Tema: ", nova.tema, sizeof(nova.tema));
    lerTexto("Data prevista (dd/mm/aaaa): ", nova.data, sizeof(nova.data));
    lerTexto("Publico-alvo: ", nova.publicoAlvo, sizeof(nova.publicoAlvo));
    lerTexto("Responsavel: ", nova.responsavel, sizeof(nova.responsavel));

    do {
        nova.participantesPlanejados =
            lerInteiro("Quantidade prevista de participantes: ");

        if (nova.participantesPlanejados < 0) {
            printf("A quantidade nao pode ser negativa.\n");
        }
    } while (nova.participantesPlanejados < 0);

    nova.participantesRealizados = 0;
    strcpy(nova.situacao, "PLANEJADA");

    acoes[*quantidade] = nova;
    (*quantidade)++;

    printf("\nAcao cadastrada com sucesso!\n");
}

void listarAcoes(Acao acoes[], int quantidade) {
    int i;

    printf("\n===== LISTA DE ACOES =====\n");

    if (quantidade == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        mostrarAcao(acoes[i]);
    }
}

void pesquisarAcao(Acao acoes[], int quantidade) {
    int opcao, i, codigo, encontrou = 0;
    char termo[100];

    if (quantidade == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    printf("\n===== PESQUISAR ACAO =====\n");
    printf("1 - Por codigo\n");
    printf("2 - Por escola\n");
    printf("3 - Por tema\n");

    do {
        opcao = lerInteiro("Opcao: ");

        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida.\n");
        }
    } while (opcao < 1 || opcao > 3);

    if (opcao == 1) {
        codigo = lerInteiro("Digite o codigo: ");
        i = localizarCodigo(acoes, quantidade, codigo);

        if (i != -1) {
            mostrarAcao(acoes[i]);
        } else {
            printf("Nenhuma acao encontrada para esse codigo.\n");
        }

        return;
    }

    if (opcao == 2) {
        lerTexto("Digite a escola: ", termo, sizeof(termo));

        for (i = 0; i < quantidade; i++) {
            if (strcmp(acoes[i].escola, termo) == 0) {
                mostrarAcao(acoes[i]);
                encontrou = 1;
            }
        }
    } else {
        lerTexto("Digite o tema: ", termo, sizeof(termo));

        for (i = 0; i < quantidade; i++) {
            if (strcmp(acoes[i].tema, termo) == 0) {
                mostrarAcao(acoes[i]);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhuma acao encontrada.\n");
    }
}

void atualizarSituacao(Acao acoes[], int quantidade) {
    int codigo, posicao, opcao, participantes;

    if (quantidade == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    printf("\n===== ATUALIZAR SITUACAO =====\n");
    codigo = lerInteiro("Codigo da acao: ");

    posicao = localizarCodigo(acoes, quantidade, codigo);

    if (posicao == -1) {
        printf("Acao nao encontrada.\n");
        return;
    }

    printf("\nAcao localizada:\n");
    mostrarAcao(acoes[posicao]);

    printf("1 - PLANEJADA\n");
    printf("2 - REALIZADA\n");
    printf("3 - CANCELADA\n");

    do {
        opcao = lerInteiro("Nova situacao: ");

        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida.\n");
        }
    } while (opcao < 1 || opcao > 3);

    if (opcao == 1) {
        strcpy(acoes[posicao].situacao, "PLANEJADA");
        acoes[posicao].participantesRealizados = 0;
    } else if (opcao == 2) {
        do {
            participantes =
                lerInteiro("Quantidade efetiva de participantes: ");

            if (participantes < 0) {
                printf("A quantidade nao pode ser negativa.\n");
            }
        } while (participantes < 0);

        acoes[posicao].participantesRealizados = participantes;
        strcpy(acoes[posicao].situacao, "REALIZADA");
    } else {
        strcpy(acoes[posicao].situacao, "CANCELADA");
        acoes[posicao].participantesRealizados = 0;
    }

    printf("\nSituacao atualizada com sucesso!\n");
}

void gerarResumo(Acao acoes[], int quantidade) {
    int i;
    int planejadas = 0, realizadas = 0, canceladas = 0;
    int totalPrevisto = 0, totalRealizado = 0;
    float percentual = 0.0;

    printf("\n===== RESUMO GERAL =====\n");

    for (i = 0; i < quantidade; i++) {
        totalPrevisto += acoes[i].participantesPlanejados;

        if (strcmp(acoes[i].situacao, "PLANEJADA") == 0) {
            planejadas++;
        } else if (strcmp(acoes[i].situacao, "REALIZADA") == 0) {
            realizadas++;
            totalRealizado += acoes[i].participantesRealizados;
        } else if (strcmp(acoes[i].situacao, "CANCELADA") == 0) {
            canceladas++;
        }
    }

    if (totalPrevisto > 0) {
        percentual = ((float) totalRealizado / totalPrevisto) * 100;
    }

    printf("Total de acoes: %d\n", quantidade);
    printf("Acoes planejadas: %d\n", planejadas);
    printf("Acoes realizadas: %d\n", realizadas);
    printf("Acoes canceladas: %d\n", canceladas);
    printf("Total de participantes previstos: %d\n", totalPrevisto);
    printf("Total de participantes efetivos: %d\n", totalRealizado);
    printf("Percentual de participacao: %.2f%%\n", percentual);
}

int main() {
    Acao acoes[MAX_ACOES];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=============================================\n");
        printf("              PSE EM ACAO\n");
        printf("=============================================\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acao\n");
        printf("4 - Atualizar situacao\n");
        printf("5 - Gerar resumo\n");
        printf("0 - Sair\n");
        printf("=============================================\n");

        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                cadastrarAcao(acoes, &quantidade);
                break;

            case 2:
                listarAcoes(acoes, quantidade);
                break;

            case 3:
                pesquisarAcao(acoes, quantidade);
                break;

            case 4:
                atualizarSituacao(acoes, quantidade);
                break;

            case 5:
                gerarResumo(acoes, quantidade);
                break;

            case 0:
                printf("\nSistema encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
