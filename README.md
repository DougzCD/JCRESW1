# Sistema Gerenciamento de um Boteco

## Índice
- [Informações Gerais](#informações-gerais)
- [Reuniões](#reuniões)
- [Documentação](#documentação)

## Informações Gerais

### Grupo
- Douglas Candido Domiciano

### Cliente
- Amigo estudandte de gastronomia

### Tema
Um sistema de manejamento do estoque, cardapio, pedidos e atendimento de um Boteco.

## Reuniões
1º - 21/09/2024

2º - 05/10/2024

3º - 19/10/2024

4º -

## Documentação

### Requisitos

| ID |  Requisito   |   Forma de medição e critério de satisfação   |   Requisitos Relacionados  |   Importancia   |
|----|--------------|-----------------------------------------------|----------------------------|-----------------|
| R1 |  GERENCIAR OS INSUMOS    |   Deve existir um banco de dados onde são catalogados os insumos. |   #   |   Alta    |
| R1.1 | CRUD DOS INSUMOS    |  Usuarios devem poder adicionar, ver, atualizar e remover insumos dos bancos de dados.   |   R1   |   Alta    |
| R2 |  CARDAPIO DIGITAL   |    Um cardapio  digital que mostra todas as opições de compra com preço e descrição.    |   #   |   Media    |
| R3 |  COMANDA DIGITAL    |    Pode gerar e dividir comandas e alocar os pedidos para diferentes comandas.  |   #   |   Alta    |
| R4 |  CHAMAR GARÇOM    |  Botao que imediatamente notifica o garcom mais proximo. |   #   |   Alta    |


#### Legenda:
- **Importancia:**
  - Alta: Requisitos essenciais para o funcionamento básico do sistema ou que agregam alto valor ao usuário.
  - Média: Requisitos importantes, mas que podem ser implementados em fases posteriores ou têm menor impacto imediato.

### Casos de Uso

#### Diagrama de Caso de Uso
![image](./documentos/diagramas/Diagrama%20de%20caso%20de%20uso.drawio.png)

#### Descrição Textual dos Casos de uso

| **ID**  | **Caso de Uso**              | **Ator Principal** | **Resumo**                                                                                                                | **Fluxo Principal**                                                                                                                                                                                                                          |
|--------|-----------------------------|--------------------|--------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| C1     | Gerenciar Insumos            | Su-Chefe              | Gerencia os insumos no banco de dados, permitindo adicionar, visualizar, atualizar e remover insumos.                     | 1. Chefe acessa o gerenciamento de insumos.<br>2. Escolhe adicionar, ver, atualizar ou remover insumos.<br>3. Sistema atualiza o banco de dados.<br>4. Sistema confirma a operação.                                                         |
| C1.1   | CRUD dos Insumos             | Su-Chefe              | Realiza operações de CRUD nos insumos cadastrados no sistema.                                                             | 1. Chefe acessa o menu CRUD de insumos.<br>2. Seleciona criar, ler, atualizar ou excluir.<br>3. Insere ou edita as informações dos insumos.<br>4. Sistema atualiza o banco de dados.                                                        |
| C2     | Cardápio Digital             | Su-Chefe, Garçom      | Chefe gerencia itens do cardápio; garçom acessa o cardápio digital para registrar os pedidos dos clientes.                | 1. Chefe acessa o cardápio e edita itens.<br>2. Garçom acessa o cardápio digital durante o atendimento.<br>3. Garçom registra o pedido com base nas opções do cardápio.                                                                       |
| C3     | Chamar Garçom                | Cliente (indireto), Garçom | Clientes chamam o garçom via um botão, e o sistema notifica o garçom mais próximo.                                       | 1. Cliente aperta o botão "Chamar Garçom".<br>2. Sistema notifica o garçom mais próximo.<br>3. Garçom recebe a notificação e atende à mesa correspondente.|
| C4     | Comanda Digital              | Garçom             | Cria, divide e aloca pedidos nas comandas de cada mesa. Chefe acompanha o status das comandas em tempo real.              | 1. Garçom seleciona a mesa e cria uma comanda digital.<br>2. Registra os pedidos na comanda.<br>3. Garçom divide a comanda, se necessário.<br>4. Sistema associa pedidos às comandas.<br>5. Chefe visualiza status das comandas.             |
| C5     | Realizar Pagamento             | Garçom             | Após fechar a comanda, o gaçom pode iniciar o processo de pagamento.              | 1. Garçom seleciona a comanda a ser fechada.<br>2. O garçom pergunta pro cliente qual forma de pagamento.<br>3. Garçom seleciona a forma de pagamento desejada.<br>4. Sistema aguarda a confirmaçam do pagamento.<br>5. Pagamento é concluido             |
| C6     | Emissão de Vendas e Estoque | Chefe          | Gera relatórios sobre vendas e níveis de estoque dos insumos.                                                            | 1. Chefe acessa interface de relatórios.<br>2. Seleciona o tipo de relatório (vendas, estoque).<br>3. Sistema gera o relatório com base nos dados e apresenta ao chefe.                                                                      |

---

Esta tabela organiza os casos de uso de forma mais visual e estruturada, facilitando a compreensão das interações entre os atores e o sistema.


#### Diagrama de Sequencia

##### C1.1 - CRUD dos Insumos
![image](./documentos/diagramas/Diagrama_Sequencia_1.drawio.png)

##### C2 - Cardapio Digital
![image](./documentos/diagramas/Diagrama_Sequencia_2.drawio.png)

##### C3 - Chamar garçom
![image](./documentos/diagramas/Diagrama_Sequencia_3.drawio.png)

##### C4 - Comanda Digital
![image](./documentos/diagramas/Diagrama_Sequencia_4.drawio.png)

##### C5 - Realizar Pagamento
![image](./documentos/diagramas/Diagrama_Sequencia_5.drawio.png)

##### C6 - Emissão de Vendas e Estoque
![image](./documentos/diagramas/Diagrama_Sequencia_6.drawio.png)

#### Mapa de Navegação
![image](./documentos/diagramas/Map.drawio.png)

#### Modelo Conceitual

