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

};

int main(){
    AutomatoFinito af;
    af.carregarJSON("automato.json");
    
    return 0;
}