# Comparações de estruturas em árvore

<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>  
</a> 
</div>

<h2><a>Proposta</a></h2>

<p>Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) Qual o tempo necessário para montar a estrutura em memória. 

3) Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. </p>

<h2><a>Gerando os arquivos</a></h2>

<p>Os arquivos com 500, 5.000, 10.000, 50.000 e   500.000 foram criados no site https://codinglab.huostravelblog.com/programming/random-number-generator/index.php?numofdata=100000&datatype=1&lowerlimit=0&upperlimit=99&rounding=3&divider=newline.</p>

<p>O arquivo de 10.000 pontos flutuantes foi gerado da maneira a seguir: </p>

| Arquivo | Qtda |   %   |
|---------|------|-------|
| 500.000 | 5575 | 55,75 |
| 50.000  | 2575 | 25,75 |
| 5.000   | 1575 | 15,75 |
| 500     | 275  | 2,75  |

<p>Cada arquivo contribui com uma certa porcentagem do arquivo de pesquisa com 10.000 números flutuantes.</p>

<h2><a>Árvore Binária</a></h2>

<p>Tempo médio de 10 testes arredondando na quinta casa após a vírgula.</p>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00205  |   0,01755  |   0,01142  |
|      **5.000**     |   0,14022  |   0,01895  |   0,01649  |
|     **50.000**     |   0,14458  |   0,01871  |   0,02127  |
|     **500.000**    |   1,34354  |   0,03671  |   0,22825  |

<h2><a>Árvore AVL</a></h2>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00118  |   0,01278  |   0,01087  |
|      **5.000**     |   0,01430  |   0,01440  |   0,01448  |
|     **50.000**     |   0,11393  |   0,02933  |   0,01934  |
|     **500.000**    |   1,23304  |   1,23304  |   0,02136  |


<h2><a>Árvore RB</a></h2>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00165  |   0,02817  |  0,000323  |
|      **5.000**     |   0,05587  |   0,15050  |   0,00043  |
|     **50.000**     |   1,62479  |   0,52312  |   0,00031  |
|     **500.000**    |  40,87941  |   1,0052   |   0,00033  |

<h2><a>Map</a></h2>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00087  |   0,07082  |   0,00789  |
|      **5.000**     |   0,00747  |   0,01012  |   0,01395  |
|     **50.000**     |   0,07876  |   0,01300  |   0,02705  |
|     **500.000**    |   0,88285  |   0,01471  |   0,03244  |

<h2><a>Unordered_map</a></h2>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00044  |   0,00186  |   0,00230  |
|      **5.000**     |   0,00306  |   0,02554  |   0,00453  |
|     **50.000**     |   0,03085  |   0,00410  |   0,00805  |
|     **500.000**    |   0,38412  |   0,00473  |   0,00916  |

<h2><a>Vector</a></h2>

| **Entradas/Teste** | **Insert** | **Search** | **Remove** |
|:------------------:|:----------:|:----------:|:----------:|
|       **500**      |   0,00017  |   0,00716  |   0,00718  |
|      **5.000**     |   0,00132  |   0,01273  |   0,01176  |
|     **50.000**     |   0,01825  |   0,05790  |   0,00930  |
|     **500.000**    |   0,08365  |   0,56559  |   0,02977  |

<h2><a>Compilando</a></h2>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<h2><a>Dados</a></h2>

<p>Disciplina: Algoritmos e Estrutura De Dados II 2022-2

Aluno: Caio Fernando Dias

Professor: Michel Pires

Data: 20/10/2022</p>

<h2><a>Contato</a></h2>

<div> 
  <a href="https://www.instagram.com/caio_fer_dias/" target="_blank"><img src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
  <a href = "mailto:caiodias200109@gmail.com"><img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
  <a href="https://www.linkedin.com/in/caio-dias-8a4962246/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
  <a href="https://t.me/caio_fer_dias" target="_blank"><img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"></a>
  <a href="https://www.facebook.com/caiofernando.dias.77"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white"></a>
  <a href="https://github.com/Caio-Fernando-Dias"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
</div>

