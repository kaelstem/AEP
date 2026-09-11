#include <stdio.h>
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
    int situacao; // 1 = Planejada, 2 = Realizada, 3 = Cancelada
} Acao;

Acao acoes[MAX_ACOES];
int quantidadeAcoes = 0;

/* Verifica se o código já está cadastrado */
int codigoExiste(int codigo) {
    int i;

    for (i = 0; i < quantidadeAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            return 1;
        }
    }

    return 0;
}

/* Cadastra uma nova ação */
void cadastrarAcao() {
    Acao nova;

    if (quantidadeAcoes >= MAX_ACOES) {
        printf("\nLimite de acoes atingido.\n");
        return;
    }

    printf("\n=== CADASTRO DE ACAO ===\n");

    printf("Codigo: ");
    scanf("%d", &nova.codigo);
    getchar();

    if (codigoExiste(nova.codigo)) {
        printf("Codigo ja utilizado.\n");
        return;
    }

    printf("Escola: ");
    fgets(nova.escola, sizeof(nova.escola), stdin);
    nova.escola[strcspn(nova.escola, "\n")] = '\0';

    printf("Tema: ");
    fgets(nova.tema, sizeof(nova.tema), stdin);
    nova.tema[strcspn(nova.tema, "\n")] = '\0';

    printf("Data: ");
    fgets(nova.data, sizeof(nova.data), stdin);
    nova.data[strcspn(nova.data, "\n")] = '\0';

    printf("Publico-alvo: ");
    fgets(nova.publicoAlvo, sizeof(nova.publicoAlvo), stdin);
    nova.publicoAlvo[strcspn(nova.publicoAlvo, "\n")] = '\0';

    printf("Responsavel: ");
    fgets(nova.responsavel, sizeof(nova.responsavel), stdin);
    nova.responsavel[strcspn(nova.responsavel, "\n")] = '\0';

    do {
        printf("Participantes planejados: ");
        scanf("%d", &nova.participantesPlanejados);

        if (nova.participantesPlanejados < 0) {
            printf("Quantidade invalida. Digite um valor maior ou igual a zero.\n");
        }

    } while (nova.participantesPlanejados < 0);

    nova.participantesRealizados = 0;
    nova.situacao = 1;

    acoes[quantidadeAcoes] = nova;
    quantidadeAcoes++;

    printf("\nAcao cadastrada com sucesso!\n");
}

/* Exibe uma ação */
void exibirAcao(Acao acao) {
    printf("\nCodigo: %d\n", acao.codigo);
    printf("Escola: %s\n", acao.escola);
    printf("Tema: %s\n", acao.tema);
    printf("Data: %s\n", acao.data);
    printf("Publico-alvo: %s\n", acao.publicoAlvo);
    printf("Responsavel: %s\n", acao.responsavel);
    printf("Participantes planejados: %d\n",
           acao.participantesPlanejados);
    printf("Participantes realizados: %d\n",
           acao.participantesRealizados);

    printf("Situacao: ");

    if (acao.situacao == 1) {
        printf("PLANEJADA\n");
    } else if (acao.situacao == 2) {
        printf("REALIZADA\n");
    } else {
        printf("CANCELADA\n");
    }
}

/* Lista todas as ações */
void listarAcoes() {
    int i;

    printf("\n=== LISTA DE ACOES ===\n");

    if (quantidadeAcoes == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidadeAcoes; i++) {
        printf("\n--- ACAO %d ---\n", i + 1);
        exibirAcao(acoes[i]);
    }
}

/* Pesquisa uma ação */
void pesquisarAcao() {
    int opcao;
    int codigo;
    int encontrou = 0;
    char termo[100];
    int i;

    printf("\n=== PESQUISAR ACAO ===\n");
    printf("1 - Pesquisar por codigo\n");
    printf("2 - Pesquisar por escola\n");
    printf("3 - Pesquisar por tema\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1) {

        printf("Digite o codigo: ");
        scanf("%d", &codigo);

        for (i = 0; i < quantidadeAcoes; i++) {
            if (acoes[i].codigo == codigo) {
                exibirAcao(acoes[i]);
                encontrou = 1;
            }
        }

    } else if (opcao == 2 || opcao == 3) {

        printf("Digite o termo de pesquisa: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';

        for (i = 0; i < quantidadeAcoes; i++) {

            if (opcao == 2 &&
                strstr(acoes[i].escola, termo) != NULL) {

                exibirAcao(acoes[i]);
                encontrou = 1;
            }

            if (opcao == 3 &&
                strstr(acoes[i].tema, termo) != NULL) {

                exibirAcao(acoes[i]);
                encontrou = 1;
            }
        }

    } else {
        printf("Opcao invalida.\n");
        return;
    }

    if (!encontrou) {
        printf("\nNenhuma acao encontrada.\n");
    }
}

/* Atualiza a situação da ação */
void atualizarSituacao() {
    int codigo;
    int opcao;
    int i;
    int encontrada = 0;

    printf("\n=== ATUALIZAR SITUACAO ===\n");

    printf("Digite o codigo da acao: ");
    scanf("%d", &codigo);

    for (i = 0; i < quantidadeAcoes; i++) {

        if (acoes[i].codigo == codigo) {

            encontrada = 1;

            printf("\n1 - Planejada\n");
            printf("2 - Realizada\n");
            printf("3 - Cancelada\n");
            printf("Opcao: ");
            scanf("%d", &opcao);

            if (opcao == 1) {

                acoes[i].situacao = 1;
                acoes[i].participantesRealizados = 0;

            } else if (opcao == 2) {

                acoes[i].situacao = 2;

                do {
                    printf("Participantes realizados: ");
                    scanf("%d",
                          &acoes[i].participantesRealizados);

                    if (acoes[i].participantesRealizados < 0) {
                        printf("Quantidade invalida.\n");
                    }

                } while (acoes[i].participantesRealizados < 0);

            } else if (opcao == 3) {

                acoes[i].situacao = 3;
                acoes[i].participantesRealizados = 0;

            } else {

                printf("Opcao invalida.\n");
                return;
            }

            printf("\nSituacao atualizada com sucesso!\n");
        }
    }

    if (!encontrada) {
        printf("\nAcao nao encontrada.\n");
    }
}

/* Gera o resumo */
void gerarResumo() {
    int planejadas = 0;
    int realizadas = 0;
    int canceladas = 0;
    int planejadosParticipantes = 0;
    int realizadosParticipantes = 0;
    float percentual = 0;
    int i;

    printf("\n=== RESUMO ===\n");

    for (i = 0; i < quantidadeAcoes; i++) {

        planejadosParticipantes +=
            acoes[i].participantesPlanejados;

        if (acoes[i].situacao == 1) {

            planejadas++;

        } else if (acoes[i].situacao == 2) {

            realizadas++;

            realizadosParticipantes +=
                acoes[i].participantesRealizados;

        } else if (acoes[i].situacao == 3) {

            canceladas++;
        }
    }

    if (planejadosParticipantes > 0) {
        percentual =
            ((float)realizadosParticipantes /
             planejadosParticipantes) * 100;
    }

    printf("Total de acoes: %d\n", quantidadeAcoes);
    printf("Acoes planejadas: %d\n", planejadas);
    printf("Acoes realizadas: %d\n", realizadas);
    printf("Acoes canceladas: %d\n", canceladas);
    printf("Participantes planejados: %d\n",
           planejadosParticipantes);
    printf("Participantes realizados: %d\n",
           realizadosParticipantes);
    printf("Percentual de participacao: %.2f%%\n",
           percentual);
}

/* Programa principal */
int main() {
    int opcao;

    do {

        printf("\n====================================\n");
        printf("       PSE EM ACAO\n");
        printf("====================================\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acao\n");
        printf("4 - Atualizar situacao\n");
        printf("5 - Gerar resumo\n");
        printf("0 - Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrarAcao();
                break;

            case 2:
                listarAcoes();
                break;

            case 3:
                pesquisarAcao();
                break;

            case 4:
                atualizarSituacao();
                break;

            case 5:
                gerarResumo();
                break;

            case 0:
                printf("\nSistema encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
