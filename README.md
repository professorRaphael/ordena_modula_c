# 🧩 Projeto de Algoritmos de Ordenação em C

Este projeto foi desenvolvido com fins **didáticos**, para o **estudo e comparação de algoritmos de ordenação** clássicos, além de servir como exercício de **modularização em linguagem C**.

---

## 🎯 Objetivos de Aprendizado

* **Compreender o funcionamento interno** de algoritmos de ordenação importantes.
* **Medir e comparar** seus tempos de execução em diferentes tamanhos de entrada.
* **Praticar modularização** — separando o código em múltiplos arquivos `.c` e `.h` para melhor organização e reutilização.
* **Explorar boas práticas** de programação estruturada, uso de ponteiros, alocação dinâmica e passagem de funções como parâmetros.

---

## ⚙️ Estrutura do Projeto

```
Estrutura/
├── main.c              # Programa principal (gera dados, chama os algoritmos e mede o tempo)
├── insertion_sort.c    # Implementação do Insertion Sort
├── quick_sort.c        # Implementação do Quick Sort
├── merge_sort.c        # Implementação do Merge Sort
├── heap_sort.c         # Implementação do Heap Sort
├── insertion_sort.h
├── quick_sort.h
├── merge_sort.h
├── heap_sort.h
└── README.md
```

O `main.c` gera um vetor de números aleatórios, cria cópias para cada algoritmo e mede o tempo gasto para ordenar cada uma das cópias, imprimindo resultados comparativos.

---

## 🚀 Como Compilar e Executar

No terminal, dentro da pasta do projeto:

```bash
gcc main.c insertion_sort.c quick_sort.c merge_sort.c heap_sort.c -o main.exe
```

Depois execute:

```bash
.\main.exe
```

---

## 📊 Exemplo de Saída

```
n = 20000 elementos
Insertion (prefixo ordenado): 0 0 4 5 5 6 9 10 12 15 ...
Quick     (prefixo ordenado): 0 0 4 5 5 6 9 10 12 15 ...
Merge     (prefixo ordenado): 0 0 4 5 5 6 9 10 12 15 ...
Heap      (prefixo ordenado): 0 0 4 5 5 6 9 10 12 15 ...

Tempos aproximados:
Insertion sort :  206.000 ms  (complexidade teórica: O(n²))
Quick sort     :    2.000 ms  (complexidade teórica: O(n log n))
Merge sort     :    2.000 ms  (complexidade teórica: O(n log n))
Heap sort      :    4.000 ms  (complexidade teórica: O(n log n))
```

---

## 🧠 Conceitos Envolvidos

* **Ordenação por inserção (Insertion Sort)** — simples, mas ineficiente para grandes volumes.
* **Ordenação rápida (Quick Sort)** — divide e conquista; geralmente o mais eficiente em média.
* **Ordenação por mistura (Merge Sort)** — estável e com complexidade garantida O(n log n).
* **Ordenação por heap (Heap Sort)** — baseada em estrutura de heap binária.

Além disso, o código explora:

* Passagem de funções como parâmetros (ponteiros para função).
* Cálculo de tempo de execução com `clock()`.
* Alocação dinâmica de memória com `malloc()`.
* Modularização e separação de responsabilidades.

---

## 🧩 Autor e Propósito

Projeto criado para **estudo acadêmico** na disciplina de **Estrutura de Dados**, com o objetivo de reforçar a compreensão sobre **algoritmos de ordenação** e **boas práticas de modularização em C**.
