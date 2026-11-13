PSE em Ação

Sobre o projeto

O PSE em Ação é um sistema desenvolvido em linguagem C para auxiliar no planejamento, registro e acompanhamento de ações coletivas relacionadas ao Programa Saúde na Escola (PSE).

O sistema foi desenvolvido como projeto acadêmico da Universidade Cesumar – UNICESUMAR, na disciplina de Engenharia de Software, com foco na aplicação dos conhecimentos estudados durante o segundo semestre.

Objetivo

Organizar informações sobre ações planejadas e realizadas do PSE, permitindo cadastrar, listar, pesquisar e atualizar ações, além de gerar um resumo dos registros e participantes.

Integrantes

- KAEL STEM SACAHARA — RA: 26007382-2
- MARCIO DONIZETI PINTO — RA: 26005675-2
- GUSTAVO FERREIRA BAPTISTA — RA: 26006252-2

Tecnologias utilizadas

- Linguagem C
- Structs
- Vetores
- Funções
- Estruturas condicionais
- Estruturas de repetição
- Terminal/console
- GitHub

Funcionalidades

O sistema possui as seguintes funcionalidades:

- Cadastrar ações do PSE, informando código, escola, tema, data, público-alvo, responsável, quantidade prevista de participantes e situação.
- Listar todas as ações cadastradas.
- Pesquisar ações por código, escola ou tema.
- Atualizar a situação da ação para planejada, realizada ou cancelada.
- Registrar a quantidade efetiva de participantes quando a ação for realizada.
- Gerar um resumo geral das ações cadastradas, incluindo quantidade de ações por situação e participação.
- Validar dados de entrada, evitando códigos repetidos, quantidades negativas e opções inválidas.
  
Como compilar e executar

Compilação

O programa foi desenvolvido em linguagem C e pode ser compilado utilizando um compilador compatível, como o GCC.

No terminal, dentro da pasta "src", execute:

gcc pse_em_acao.c -o pse_em_acao

Execução

Após a compilação, execute o programa com:

./pse_em_acao

No Windows, caso o compilador gere um arquivo ".exe", execute:

pse_em_acao.exe

O sistema será iniciado pelo terminal e apresentará o menu principal para o usuário.
Situações das ações
Casos de uso

UC01 — Cadastrar ação

Ator: Usuário

Objetivo: Cadastrar uma nova ação do PSE no sistema.

Fluxo principal:

1. O usuário acessa a opção de cadastro.
2. Informa os dados da ação.
3. O sistema verifica se o código já existe.
4. O sistema valida os dados informados.
5. A ação é armazenada no sistema.
6. O sistema informa que o cadastro foi realizado.

UC02 — Listar ações

Ator: Usuário

Objetivo: Visualizar todas as ações cadastradas.

Fluxo principal:

1. O usuário seleciona a opção de listar.
2. O sistema verifica os registros existentes.
3. O sistema apresenta as ações cadastradas.

UC03 — Pesquisar ação

Ator: Usuário

Objetivo: Localizar uma ação por código, escola ou tema.

Fluxo principal:

1. O usuário escolhe o tipo de pesquisa.
2. Informa o dado para busca.
3. O sistema procura os registros correspondentes.
4. O sistema apresenta os resultados encontrados.

UC04 — Atualizar situação

Ator: Usuário

Objetivo: Alterar a situação de uma ação para planejada, realizada ou cancelada.

Fluxo principal:

1. O usuário informa o código da ação.
2. O sistema localiza o registro.
3. O usuário informa a nova situação.
4. Caso a ação seja realizada, informa a quantidade efetiva de participantes.
5. O sistema salva a atualização.

UC05 — Gerar resumo

Ator: Usuário

Objetivo: Apresentar um resumo geral das ações cadastradas.

Fluxo principal:

1. O usuário seleciona a opção de resumo.
2. O sistema contabiliza as ações por situação.
3. O sistema calcula os participantes.
4. O sistema apresenta o resumo na tela.
As ações podem possuir três situações:

- PLANEJADA
- REALIZADA
- CANCELADA

Quando uma ação é marcada como realizada, o sistema permite registrar a quantidade efetiva de participantes.

Estrutura do projeto

AEP/
├── README.md
├── integrantes.txt
│
├── src/
│   ├── pse_em_acao.c
│   └── pse_em_acao_etapa_2.c
│
└── documentacao/
    ├── Entrega1.AEP.pdf
    └── AEP_PSE_em_Acao_Etapa_2.pdf

Como executar

1. Baixe ou clone o repositório.
2. Abra o arquivo "pse_em_acao_etapa_2.c" em um compilador C, como o Dev-C++.
3. Compile o programa.
4. Execute o programa.
5. Utilize o menu para acessar as funcionalidades disponíveis.

Dados utilizados

O sistema utiliza somente dados fictícios ou coletivos para demonstração acadêmica.

Não devem ser cadastrados nomes de estudantes, diagnósticos, prontuários ou outras informações clínicas individuais.

Documentação

A documentação da primeira e da segunda etapa está disponível na pasta "documentacao".

Apresentação em vídeo

Link do vídeo da apresentação:

[INSERIR LINK DO VÍDEO AQUI]

Repositório

Este projeto foi desenvolvido para a AEP — PSE em Ação da UNICESUMAR.

Testes realizados

Foram planejados testes para verificar o funcionamento das principais funcionalidades do sistema.

Teste| Resultado esperado
Cadastrar uma ação com dados válidos| Cadastro realizado com sucesso
Cadastrar código repetido| Sistema informa que o código já existe
Listar ações| Exibir todas as ações cadastradas
Pesquisar código inexistente| Informar que nenhuma ação foi encontrada
Atualizar situação| Alterar a situação corretamente
Informar quantidade negativa| Sistema rejeita o valor
Gerar resumo geral| Exibir os totais e o percentual de participação

Os testes devem ser executados no programa para confirmar os resultados.

Cuidados e privacidade

O sistema utiliza exclusivamente dados fictícios ou informações coletivas para demonstração acadêmica.

Não devem ser cadastrados nomes de estudantes, diagnósticos, prontuários ou informações clínicas individuais.

O PSE em Ação tem finalidade administrativa e educacional, não realizando diagnósticos ou recomendações de tratamento.

Considerações finais

O desenvolvimento do PSE em Ação permitiu aplicar conhecimentos de programação em linguagem C, utilizando estruturas, vetores, funções, condicionais e repetições.

A aplicação busca facilitar a organização e o acompanhamento das ações coletivas do Programa Saúde na Escola.
