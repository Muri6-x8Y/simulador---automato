#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;


struct Transicao {
    int from;
    char read;
    int to;
};

class AutomatoFinito {
    int estadoInicial;
    unordered_set<int> estadosFinais;
    unordered_map<pair<int, char>, int, hash<string>> transicoes;

    
    struct PairHash {
        size_t operator()(const pair<int, char>& p) const {
            return hash<int>()(p.first) ^ hash<char>()(p.second);
        }
    };

    unordered_map<pair<int, char>, int, PairHash> delta;

public:
    void carregarJSON(const string& arquivo) {
        ifstream file(arquivo);
        json j;
        file >> j;

        estadoInicial = j["inicial"];
        for (int f : j["final"]) {
            estadosFinais.insert(f);
        }

        for (const auto& t : j["estados"]) {
            int from = t["from"];
            char read = t["read"].get<string>()[0];
            int to = t["to"];
            delta[{from, read}] = to;
        }
    }

    bool processar(const string& entrada, int estadoAtual, int& estadoFinal) {
        for (char c : entrada) {
            auto it = delta.find({estadoAtual, c});
            if (it == delta.end()) {
                estadoFinal = estadoAtual;
                return false;
            }
            estadoAtual = it->second;
        }
        estadoFinal = estadoAtual;
        return estadosFinais.count(estadoAtual) > 0;
    }

};

int main(){
    AutomatoFinito af;
    af.carregarJSON("automato.json");
    
    ifstream testes("testes.txt");
    ofstream resultado("resultado.txt");

    string linha;
    while (getline(testes, linha)) {
        stringstream ss(linha);
        string cadeia;
        int estadoInicial;
        if (getline(ss, cadeia, ';') && ss >> estadoInicial) {
            int estadoFinal;
            bool aceita = af.processar(cadeia, estadoInicial, estadoFinal);
            resultado << cadeia << ";" << estadoFinal << ": " << (aceita ? "ACEITA" : "REJEITA") << endl;
        }
    }
   
    cout << "Processamento concluído. Verifique resultado.txt." << endl;
    return 0;
}