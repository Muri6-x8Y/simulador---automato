# Simulador de Autômatos Finitos

Este projeto consiste em um **simulador de autômatos finitos** desenvolvido em C++. A ferramenta permite a definição de autômatos determinísticos e não determinísticos, bem como a simulação da aceitação de cadeias de entrada.

## 📌 Funcionalidades

- Leitura de autômatos a partir de arquivos JSON
- Definição de estados, alfabeto, estado inicial e estados finais
- Simulação de processamento de cadeias
- Verificação de aceitação ou rejeição de uma cadeia
- Geração de relatório com os resultados das simulações

## 📁 Estrutura do Repositório

- `Automato.cpp` - Código-fonte principal
- `json.hpp` - Biblioteca usada para manipulação de JSON (inclusa no projeto)
- `entradas.txt` - Arquivo de entrada com cadeias a serem testadas
- `resultado.txt` - Arquivo de saída com os resultados das simulações
- `README.md` - Este arquivo

## 🛠️ Requisitos

- `g++` (compilador C++)
- Nenhuma biblioteca externa (usa apenas `json.hpp` incluído no projeto)

## ▶️ Como compilar

Abra o terminal (CMD) na pasta do projeto e execute:

```
g++ -std=c++11 -o simulador Automato.cpp
```

## 🚀 Como executar

No mesmo terminal:

```
./simulador
```

## 📄 Formato do JSON

```json
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
```

## ✉️ Exemplo de Entradas (`entradas.txt`)

```
cadeia;estadoInicial
aabab;0
abba;1
```

## 📤 Saída Gerada (`resultado.txt`)

```
aabab;0: ACEITA
abba;1: REJEITA
```

---

Desenvolvido como parte de um exercício(imcompleto) de aprendizado em teoria da computação e programação em C++.