#include <iostream>
#include <vector>
#include <string>
#include <map>
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

// Classe Cardapio
class ItemCardapio {
public:
    string nome;
    string descricao;
    double preco;

    ItemCardapio(string nome, string descricao, double preco)
        : nome(nome), descricao(descricao), preco(preco) {}

    void exibir() const {
        cout << "Item: " << nome << ", Descricao: " << descricao
             << ", Preco: " << preco << endl;
    }
};

// Classe Mesa
class Mesa {
public:
    int numero;
    bool ocupada;

    Mesa(int numero, bool ocupada = false) : numero(numero), ocupada(ocupada) {}

    void alterarStatus() {
        ocupada = !ocupada;
    }

    void exibir() {
        cout << "Mesa " << numero << (ocupada ? " ocupada" : " livre") << endl;
    }
};

// Classe Comanda
class Comanda {
public:
    int mesa;
    vector<ItemCardapio> itens;
    double total;

    Comanda(int mesa) : mesa(mesa), total(0) {}

    void adicionarItem(const ItemCardapio& item) {
        itens.push_back(item);
        total += item.preco;
    }

    void exibir() const {
        cout << "Comanda da Mesa " << mesa << ":\n";
        for (const auto& item : itens) {
            item.exibir();
        }
        cout << "Total: R$ " << total << endl;
    }
};

// Classe Relatorio
class Relatorio {
public:
    static void gerarRelatorioVendas(const vector<Comanda>& comandas) {
        double totalVendas = 0;
        cout << "Relatorio de Vendas:\n";
        for (const auto& comanda : comandas) {
            totalVendas += comanda.total;
        }
        cout << "Total em Vendas: R$ " << totalVendas << endl;
    }

    static void gerarRelatorioEstoque(const vector<Insumo>& insumos) {
        cout << "Relatorio de Estoque:\n";
        for (const auto& insumo : insumos) {
            insumo.exibir();
        }
    }
};

void exibirMenu() {
    cout << "\n--- Sistema de Gerenciamento do Restaurante ---\n";
    cout << "1. Exibir Estoque\n";
    cout << "2. Exibir Cardapio\n";
    cout << "3. Gerenciar Mesas\n";
    cout << "4. Gerar Relatorio de Vendas\n";
    cout << "5. Gerar Relatorio de Estoque\n";
    cout << "6. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    // Dados iniciais
    vector<Insumo> estoque = {
        Insumo("Farinha", 50, 2.5, "2024-12-31"),
        Insumo("Carne", 30, 15.0, "2024-01-15")
    };

    vector<ItemCardapio> cardapio = {
        ItemCardapio("Pizza", "Pizza de queijo", 25.0),
        ItemCardapio("Hamburguer", "Hamburguer artesanal", 15.0)
    };

    vector<Mesa> mesas = {Mesa(1), Mesa(2)};
    vector<Comanda> comandas;

    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "\n--- Estoque ---\n";
            for (const auto& insumo : estoque) {
                insumo.exibir();
            }
            break;

        case 2:
            cout << "\n--- Cardapio ---\n";
            for (const auto& item : cardapio) {
                item.exibir();
            }
            break;

        case 3:
            cout << "\n--- Mesas ---\n";
            for (auto& mesa : mesas) {
                mesa.exibir();
            }
            cout << "Digite o numero da mesa para alterar o status: ";
            int numeroMesa;
            cin >> numeroMesa;
            for (auto& mesa : mesas) {
                if (mesa.numero == numeroMesa) {
                    mesa.alterarStatus();
                    cout << "Status da mesa " << numeroMesa << " alterado!\n";
                }
            }
            break;

        case 4:
            cout << "\n--- Relatorio de Vendas ---\n";
            Relatorio::gerarRelatorioVendas(comandas);
            break;

        case 5:
            cout << "\n--- Relatorio de Estoque ---\n";
            Relatorio::gerarRelatorioEstoque(estoque);
            break;

        case 6:
            cout << "Encerrando o sistema...\n";
            break;

        default:
            cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
