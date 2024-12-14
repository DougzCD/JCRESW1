#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Classe Insumo
class Insumo {
public:
    string nome;
    int quantidade;
    double preco;
    string validade;

    Insumo(string nome, int quantidade, double preco, string validade)
        : nome(nome), quantidade(quantidade), preco(preco), validade(validade) {}

    void exibir() const {
        cout << "Nome: " << nome << ", Quantidade: " << quantidade
             << ", Preco: R$" << preco << ", Validade: " << validade << endl;
    }
};

// Classe Prato
class Prato {
public:
    string nome;
    string descricao;
    double preco;
    int codigo;

    Prato(string nome, string descricao, double preco, int codigo)
        : nome(nome), descricao(descricao), preco(preco), codigo(codigo) {}

    void exibir() const {
        cout << "[" << codigo << "] " << nome << " - " << descricao << " - R$ " << preco << endl;
    }
};

// Classe Pedido
class Pedido {
public:
    int mesa;
    vector<int> listaCodigosPratos;
    double total;

    Pedido(int mesa) : mesa(mesa), total(0) {}

    void adicionarPrato(const Prato& prato) {
        listaCodigosPratos.push_back(prato.codigo);
        total += prato.preco;
    }

    void exibir(const vector<Prato>& pratos) const {
        cout << "Pedido da Mesa " << mesa << ":\n";
        for (int codigo : listaCodigosPratos) {
            auto it = find_if(pratos.begin(), pratos.end(), [&codigo](const Prato& prato) {
                return prato.codigo == codigo;
            });
            if (it != pratos.end()) {
                it->exibir();
            }
        }
        cout << "Total: R$ " << total << endl;
    }
};

// Classe Banco de Dados
class BancoDeDados {
public:
    vector<Insumo> insumos;
    vector<Prato> pratos;
    vector<Pedido> pedidosPendentes;
    vector<Pedido> pedidosConcluidos;

    void adicionarInsumo(const Insumo& insumo) {
        insumos.push_back(insumo);
    }

    void editarInsumo(int index, const Insumo& novoInsumo) {
        if (index >= 0 && index < insumos.size()) {
            insumos[index] = novoInsumo;
        } else {
            cout << "Índice inválido!\n";
        }
    }

    void adicionarPrato(const Prato& prato) {
        pratos.push_back(prato);
    }

    void editarPrato(int index, const Prato& novoPrato) {
        if (index >= 0 && index < pratos.size()) {
            pratos[index] = novoPrato;
        } else {
            cout << "Índice inválido!\n";
        }
    }

    void adicionarPedido(const Pedido& pedido) {
        pedidosPendentes.push_back(pedido);
    }

    void concluirPedido(int indice) {
        if (indice >= 0 && indice < pedidosPendentes.size()) {
            pedidosConcluidos.push_back(pedidosPendentes[indice]);
            pedidosPendentes.erase(pedidosPendentes.begin() + indice);
        } else {
            cout << "Índice inválido!\n";
        }
    }

    void exibirPedidosPendentes() const {
        cout << "\n--- Pedidos Pendentes ---\n";
        for (size_t i = 0; i < pedidosPendentes.size(); ++i) {
            cout << "[" << i << "] ";
            pedidosPendentes[i].exibir(pratos);
        }
    }

    void exibirRelatorioPedidosConcluidos() const {
        cout << "\n--- Relatório de Pedidos Concluídos ---\n";
        for (const auto& pedido : pedidosConcluidos) {
            pedido.exibir(pratos);
        }
    }
};

void exibirMenu() {
    cout << "\n--- Sistema de Gerenciamento do Restaurante ---\n";
    cout << "1. Exibir Estoque de Insumos\n";
    cout << "2. Editar Estoque de Insumos\n";
    cout << "3. Exibir Pratos\n";
    cout << "4. Editar Pratos\n";
    cout << "5. Gerenciar Pedidos\n";
    cout << "6. Exibir Pedidos Pendentes\n";
    cout << "7. Concluir Pedido\n";
    cout << "8. Relatório de Pedidos Concluídos\n";
    cout << "9. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    BancoDeDados banco;
    banco.adicionarInsumo(Insumo("Farinha", 50, 2.5, "2024-12-31"));
    banco.adicionarInsumo(Insumo("Carne", 30, 15.0, "2024-01-15"));
    banco.adicionarPrato(Prato("Pizza", "Pizza de queijo", 25.0, 1));
    banco.adicionarPrato(Prato("Hamburguer", "Hamburguer artesanal", 15.0, 2));

    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "\n--- Estoque ---\n";
            for (const auto& insumo : banco.insumos) {
                insumo.exibir();
            }
            break;

        case 2: {
            cout << "\n--- Editar Estoque ---\n";
            cout << "1. Adicionar Insumo\n";
            cout << "2. Editar Insumo Existente\n";
            cout << "Escolha uma opção: ";
            int escolha;
            cin >> escolha;

            if (escolha == 1) {
                string nome, validade;
                int quantidade;
                double preco;
                cout << "Digite o nome do insumo: ";
                cin >> nome;
                cout << "Digite a quantidade: ";
                cin >> quantidade;
                cout << "Digite o preço: ";
                cin >> preco;
                cout << "Digite a validade: ";
                cin >> validade;
                banco.adicionarInsumo(Insumo(nome, quantidade, preco, validade));
                cout << "Insumo adicionado com sucesso!\n";
            } else if (escolha == 2) {
                cout << "Digite o índice do insumo a ser editado: ";
                int indice;
                cin >> indice;
                if (indice >= 0 && indice < banco.insumos.size()) {
                    string nome, validade;
                    int quantidade;
                    double preco;
                    cout << "Digite o novo nome do insumo: ";
                    cin >> nome;
                    cout << "Digite a nova quantidade: ";
                    cin >> quantidade;
                    cout << "Digite o novo preço: ";
                    cin >> preco;
                    cout << "Digite a nova validade: ";
                    cin >> validade;
                    banco.editarInsumo(indice, Insumo(nome, quantidade, preco, validade));
                    cout << "Insumo editado com sucesso!\n";
                } else {
                    cout << "Índice inválido!\n";
                }
            } else {
                cout << "Opção inválida!\n";
            }
            break;
        }

        case 3:
            cout << "\n--- Pratos ---\n";
            for (const auto& prato : banco.pratos) {
                prato.exibir();
            }
            break;

        case 4: {
            cout << "\n--- Editar Pratos ---\n";
            cout << "1. Adicionar Prato\n";
            cout << "2. Editar Prato Existente\n";
            cout << "Escolha uma opção: ";
            int escolha;
            cin >> escolha;

            if (escolha == 1) {
                string nome, descricao;
                double preco;
                int codigo;
                cout << "Digite o nome do prato: ";
                cin >> nome;
                cout << "Digite a descrição: ";
                cin >> descricao;
                cout << "Digite o preço: ";
                cin >> preco;
                cout << "Digite o código do prato: ";
                cin >> codigo;
                banco.adicionarPrato(Prato(nome, descricao, preco, codigo));
                cout << "Prato adicionado com sucesso!\n";
            } else if (escolha == 2) {
                cout << "Digite o índice do prato a ser editado: ";
                int indice;
                cin >> indice;
                if (indice >= 0 && indice < banco.pratos.size()) {
                    string nome, descricao;
                    double preco;
                    int codigo;
                    cout << "Digite o novo nome do prato: ";
                    cin >> nome;
                    cout << "Digite a nova descrição: ";
                    cin >> descricao;
                    cout << "Digite o novo preço: ";
                    cin >> preco;
                    cout << "Digite o novo código do prato: ";
                    cin >> codigo;
                    banco.editarPrato(indice, Prato(nome, descricao, preco, codigo));
                    cout << "Prato editado com sucesso!\n";
                } else {
                    cout << "Índice inválido!\n";
                }
            } else {
                cout << "Opção inválida!\n";
            }
            break;
        }

        case 5: {
            cout << "\n--- Gerenciar Pedidos ---\n";
            cout << "Digite o número da mesa: ";
            int mesa;
            cin >> mesa;
            Pedido pedido(mesa);

            cout << "Selecione os pratos pelo código (0 para finalizar):\n";
            for (const auto& prato : banco.pratos) {
                prato.exibir();
            }

            int codigo;
            do {
                cout << "Código do prato: ";
                cin >> codigo;
                auto it = find_if(banco.pratos.begin(), banco.pratos.end(), [&codigo](const Prato& prato) {
                    return prato.codigo == codigo;
                });
                if (it != banco.pratos.end()) {
                    pedido.adicionarPrato(*it);
                } else if (codigo != 0) {
                    cout << "Código inválido!\n";
                }
            } while (codigo != 0);

            banco.adicionarPedido(pedido);
            cout << "Pedido adicionado com sucesso!\n";
            pedido.exibir(banco.pratos);
            break;
        }

        case 6:
            banco.exibirPedidosPendentes();
            break;

        case 7: {
            banco.exibirPedidosPendentes();
            cout << "Digite o índice do pedido a ser concluído: ";
            int indice;
            cin >> indice;
            banco.concluirPedido(indice);
            break;
        }

        case 8:
            banco.exibirRelatorioPedidosConcluidos();
            break;

        case 9:
            cout << "Encerrando o sistema...\n";
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 9);

    return 0;
}
