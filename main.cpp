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
             << ", Preco: " << preco << ", Validade: " << validade << endl;
    }
};

// Classe Prato (Item do Cardápio)
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

    void exibir(const vector<Prato>& cardapio) const {
        cout << "Pedido da Mesa " << mesa << ":\n";
        for (int codigo : listaCodigosPratos) {
            auto it = find_if(cardapio.begin(), cardapio.end(), [&codigo](const Prato& prato) {
                return prato.codigo == codigo;
            });
            if (it != cardapio.end()) {
                it->exibir();
            }
        }
        cout << "Total: R$ " << total << endl;
    }
};

// Classe Garçom
class Garcom {
public:
    string nome;
    string senha;

    Garcom(string nome, string senha) : nome(nome), senha(senha) {}

    bool autenticar(const string& senhaFornecida) const {
        return senha == senhaFornecida;
    }
};

// Classe Banco de Dados
class BancoDeDados {
public:
    vector<Insumo> insumos;
    vector<Prato> cardapio;

    void adicionarInsumo(const Insumo& insumo) {
        insumos.push_back(insumo);
    }

    void editarInsumo(int index, const Insumo& novoInsumo) {
        if (index >= 0 && index < insumos.size()) {
            insumos[index] = novoInsumo;
        }
    }

    void adicionarPrato(const Prato& prato) {
        cardapio.push_back(prato);
    }

    void editarPrato(int index, const Prato& novoPrato) {
        if (index >= 0 && index < cardapio.size()) {
            cardapio[index] = novoPrato;
        }
    }
};

void exibirMenu() {
    cout << "\n--- Sistema de Gerenciamento do Restaurante ---\n";
    cout << "1. Exibir Estoque\n";
    cout << "2. Editar Estoque\n";
    cout << "3. Exibir Cardápio\n";
    cout << "4. Editar Cardápio\n";
    cout << "5. Gerenciar Pedidos\n";
    cout << "6. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    BancoDeDados banco;
    banco.adicionarInsumo(Insumo("Farinha", 50, 2.5, "2024-12-31"));
    banco.adicionarInsumo(Insumo("Carne", 30, 15.0, "2024-01-15"));
    banco.adicionarPrato(Prato("Pizza", "Pizza de queijo", 25.0, 1));
    banco.adicionarPrato(Prato("Hamburguer", "Hamburguer artesanal", 15.0, 2));

    vector<Pedido> pedidos;

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

        case 2:
            cout << "\nEditar Estoque ainda não implementado.\n";
            break;

        case 3:
            cout << "\n--- Cardápio ---\n";
            for (const auto& prato : banco.cardapio) {
                prato.exibir();
            }
            break;

        case 4:
            cout << "\nEditar Cardápio ainda não implementado.\n";
            break;

        case 5: {
            cout << "\n--- Gerenciar Pedidos ---\n";
            cout << "Digite o número da mesa: ";
            int mesa;
            cin >> mesa;
            Pedido pedido(mesa);

            cout << "Selecione os pratos pelo código (0 para finalizar):\n";
            for (const auto& prato : banco.cardapio) {
                prato.exibir();
            }

            int codigo;
            do {
                cout << "Código do prato: ";
                cin >> codigo;
                auto it = find_if(banco.cardapio.begin(), banco.cardapio.end(), [&codigo](const Prato& prato) {
                    return prato.codigo == codigo;
                });
                if (it != banco.cardapio.end()) {
                    pedido.adicionarPrato(*it);
                } else if (codigo != 0) {
                    cout << "Código inválido!\n";
                }
            } while (codigo != 0);

            pedidos.push_back(pedido);
            cout << "Pedido adicionado com sucesso!\n";
            pedido.exibir(banco.cardapio);
            break;
        }

        case 6:
            cout << "Encerrando o sistema...\n";
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
