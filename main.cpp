#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct Pilha {
    char itens[MAX];
    int topo;
};

void inicializarPilha(Pilha& pilha) {
    pilha.topo = -1;
}

bool estaCheia(Pilha& pilha) {
    return pilha.topo == MAX - 1;
}

bool estaVazia(Pilha& pilha) {
    return pilha.topo == -1;
}

void empilhar(Pilha& pilha, char valor) {
    if (!estaCheia(pilha)) {
        pilha.topo++;
        pilha.itens[pilha.topo] = valor;
    }
}

char desempilhar(Pilha& pilha) {
    if (!estaVazia(pilha)) {
        char valor = pilha.itens[pilha.topo];
        pilha.topo--;
        return valor;
    }
    return '\0';
}

bool corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']');
}

bool verificaExpressao(const string& expressao) {
    Pilha pilha;
    inicializarPilha(pilha);

    for (char c : expressao) {
        if (c == '(' || c == '[') {
            empilhar(pilha, c);
        }
        else if (c == ')' || c == ']') {
            if (estaVazia(pilha) || !corresponde(desempilhar(pilha), c)) {
                return false;
            }
        }
    }

    return estaVazia(pilha);
}

int main() {
    string expressao;

    cout << "Digite a expressao matematica: ";
    getline(cin, expressao);

    if (verificaExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "Errado" << endl;
    }

    return 0;
}
