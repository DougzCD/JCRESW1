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

## Documentação

### Requisitos

| ID |  Requisito   |   Forma de medição e critério de satisfação   |   Requisitos Relacionados  |   Importancia   |
|----|--------------|-----------------------------------------------|----------------------------|-----------------|
| R1 |  GERENCIAR OS INSUMOS    |   Deve existir um banco de dados onde são catalogados os insumos. |   #   |   Alta    |
| R1.1 | CRUD DOS INSUMOS    |  Usuarios devem poder adicionar, ver, atualizar e remover insumos dos bancos de dados.   |   R1   |   Alta    |
| R2 |  CARDAPIO DIGITAL   |    Um cardapio  digital que mostra todas as opições de compra com preço e descrição.    |   #   |   Alta    |
| R3 |  COMANDA DIGITAL    |    Pode gerar e dividir comandas e alocar os pedidos para diferentes comandas.  |   #   |   Alta    |
| R4 |  CHAMAR GARÇOM    |  Botao que imediatamente notifica o garcom mais proximo. |   #   |   Alta    |


#### Legenda:
- **Importancia:**
  - Alta: Requisitos essenciais para o funcionamento básico do sistema ou que agregam alto valor ao usuário.
  - Média: Requisitos importantes, mas que podem ser implementados em fases posteriores ou têm menor impacto imediato.

### Diagramas

#### Diagrama de Caso de Uso
![image](./documentos/diagramas/Diagrama%20de%20caso%20de%20uso.drawio.png)

#### Diagrama de Classes
![image](./documentos/diagramas/Diagrama%20de%20classe%20Estagio.drawio.png)
