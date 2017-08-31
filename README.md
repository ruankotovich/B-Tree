# Documentação do Projeto

## 1. A estrutura de cada arquivo de dados e índices

## 2. Quais fontes formam cada programa

## 3. As funções que cada fonte contém

## 4. Quem desenvolveu cada fonte/função

## 5. Qual o papel de cada função



# Rascunho
- Decidimos classificar cada par de caracteres na leitura para fazer o parsing dos registros, salvando-os num buffer para tratar os caracteres excedentes.
- Decidimos usar hash perfeito, nos custou memória.
  - Supomos que a inserção seria ordenada pelo ID para otimizar a inserção no hash de forma que torne mais rápida a invalidação de blocos vazios.

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


<!-- ```
Projeto
│   README.md
│   file001.txt    
│
├───folder1
│   │   file011.txt
│   │   file012.txt
│   │
│   └───subfolder1
│       │   file111.txt
│       │   file112.txt
│       │   ...
│   
└───folder2
    │   file021.txt
    │   file022.txt
``` -->
