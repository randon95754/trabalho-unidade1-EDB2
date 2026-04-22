#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <fstream>

#include "algoritmos.h"
#include "medicao.h"

using namespace std;
using namespace chrono;

vector<int> gerarVetor(int n)
{
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        v[i] = rand() % 100000;

    return v;
}

double medirAlgoritmo(int n, string tipo)
{
    double total = 0;
    const int repeticoes = 10;

    for (int teste = 0; teste < repeticoes; teste++)
    {
  
        vector<int> original = gerarVetor(n);
        vector<int> v = original; 

        auto inicio = high_resolution_clock::now();

        if (tipo == "insertion") {
            insertionSort(v);
        } else {
            mergeSort(v, 0, v.size() - 1);
        }

        auto fim = high_resolution_clock::now();
        
        total += duration<double, milli>(fim - inicio).count();
    }

    return total / (double)repeticoes;
}


void executarTestes()
{
    srand(time(NULL)); 

    ofstream arquivo("resultados.csv");
    arquivo << "n,insertion,merge\n";

    for (int n = 1000; n <= 20000; n += 1000)
    {
        
        double tempoInsertion = medirAlgoritmo(n, "insertion");
        double tempoMerge = medirAlgoritmo(n, "merge");

        cout << "N = " << n << " | Insertion: " << tempoInsertion << "ms | Merge: " << tempoMerge << "ms" << endl;

        arquivo << n << "," << tempoInsertion << "," << tempoMerge << "\n";
    }

    arquivo.close();
}
