A compilação do programa foi realizada com o comando:

g++ main.cpp algoritmos.cpp medicao.cpp -O2 -o trabalho

O parâmetro -O2 foi utilizado para ativar otimizações do compilador, melhorando a estabilidade das medições e o desempenho da execução.

Após a compilação, o programa foi executado com:

./trabalho

Durante a execução, o sistema calcula automaticamente os tempos médios de execução para diferentes tamanhos de entrada e gera o arquivo:

resultados.csv

Esse arquivo contém os pares (n, tempo) para os dois algoritmos analisados e foi posteriormente importado para o Google Planilhas, onde foram construídos os gráficos comparativos com as funções assintóticas teóricas O(n²) e O(n log n).
