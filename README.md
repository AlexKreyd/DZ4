# ДЗ №4. Вариант №33. Найти частоту степеней вершин и отсортировать вершины по возрастанию степени вершины (сортировка подсчетом)

## Алгоритм:
- Определение степени каждой вершины и запись их в массив
``` c
int* degrees = (int*) malloc(max_node * sizeof(int)); 
    for(int i =0; i<=max_node; ++i) 
        degrees[i] = 0;

    int max_degree = -1; 
    for(int j = 1; j<=max_node; ++j){ 
        for(int i = 1; i<=max_node; ++i){
            if(i == j){
                degrees[j] += 2*matrix[i][j]; 
                continue;
            }
            degrees[j] += matrix[i][j];
        }
        if(degrees[j] > max_degree) 
            max_degree = degrees[j];
    }
    
```
- Определение частоты степеней вершин, запись их в массив и вывод
``` c
int* frequency = (int*) malloc(max_node * sizeof(int)); 
    for(int i = 0; i <= max_node; ++i){
        frequency[i] = 0;
    }

    for(int i = 1; i <= max_node; ++i){
        frequency[degrees[i]]++;
    }
    
    printf("Frequency of degrees:\n");
    for(int i = 0; i <= max_node; ++i){
        if(frequency[i] != 0)
            printf("Degree = %d, frequency = %d\n",i, frequency[i]);
    }
    
```
- Создание массива, в котором вершины сгруппированы по степеням
``` c
int nodes_grouped[100][100];
    for(int i =0; i<= max_degree; ++i){ 
        int j =0;
        for(int x =1; x <= max_node; ++x){
            if(degrees[x] == i){
                nodes_grouped[i][j] = x;
                j++;
            }
        }
    }
```

- Сортировка подсчетом и вывод отсортированных по степеням вершин
``` c
printf("\nNodes sorted by degree: ");
    for(int i = 0; i<= max_node; ++i){
        if(frequency[i] != 0){
            for(int j =0; j< frequency[i]; ++j){
                printf("%d ",nodes_grouped[i][j]);
            }
        }
    }
```
## Структурная схема алгоритма 
- Определение степени каждой вершины и запись их в массив

![Image alt](https://github.com/AlexKreyd/DZ4/blob/main/scheme1.png)

- Определение частоты степеней вершин, запись их в массив и вывод

![Image alt](https://github.com/AlexKreyd/DZ4/blob/main/scheme2.png)

- Создание массива, в котором вершины сгруппированы по степеням

![Image alt](https://github.com/AlexKreyd/DZ4/blob/main/scheme3.png)


- Сортировка подсчетом и вывод отсортированных по степеням вершин
![Image alt](https://github.com/AlexKreyd/DZ4/blob/main/scheme4.png)

