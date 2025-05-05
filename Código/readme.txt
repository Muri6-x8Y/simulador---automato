Requisitos:
g++ (compilador C++)
Nenhuma biblioteca externa (usa apenas json.hpp incluído no projeto)

Como compilar:
Abra o terminal (CMD) na pasta do projeto e execute
    g++ -std=c++11 -o simulador Automato.cpp

Como executar:
    ./simulador (no mesmo cmd)

Formato do json:
{
  "inicial": 0,
  "final": [2],
  "estados": [
    { "from": 0, "read": "a", "to": 1 },
    { "from": 0, "read": "b", "to": 0 },
    { "from": 1, "read": "a", "to": 1 },
    { "from": 1, "read": "b", "to": 2 },
    { "from": 2, "read": "a", "to": 1 },
    { "from": 2, "read": "b", "to": 0 }
  ]
}

Exemplo de entradas(entradas.txt):
cadeia;estadoInicial
ex:
aabab;0
abba;1

Saída (resultado.txt):
aabab;0: ACEITA // um para cada entrada digitada.
abba;1: REJEITA 