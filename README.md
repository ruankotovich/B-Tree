# Documentação do Projeto

## 1. A estrutura de cada arquivo de dados e índices

## 2. Quais fontes formam cada programa

## 3. As funções que cada fonte contém

## 4. Quem desenvolveu cada fonte/função

## 5. Qual o papel de cada função



# Rascunho
- Decidimos classificar cada par de caracteres na leitura para fazer o parsing dos registros, salvando-os num buffer para tratar os caracteres excedentes.
- Decidimos usar hash perfeito, nos custou memória.
  - Optamos por utilizar máscaras de validação ao invés de bitmap de pertinência, uma vez que é custoso para muitos elementos (visto que é um hash perfeito)

- Árvore de Dependências
```
Projeto
│
├───▶ upload
│     |
│     └─▶ hashfilefactory
│         │
│         ├─▶ iohandler
│         │   │
│         │   └─▶ article
│         │
│         └─▶ block
│             │
│             └─▶ article
│
├───▶ findrec
│     |
│     └─▶ hashfilefactory
│         │
│         ├─▶ iohandler
│         │   │
│         │   └─▶ article
│         │
│         └─▶ block
│             │
│             └─▶ article
│
├───▶ seek1
│     
│     
│     
│     
│     
│     
└───▶ seek2
```
