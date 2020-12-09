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
- Определение частоты степеней вершин и запись их в массив
``` c
int* frequency = (int*) malloc(max_node * sizeof(int)); 
    for(int i = 0; i <= max_node; ++i){
        frequency[i] = 0;
    }

    for(int i = 1; i <= max_node; ++i){
        frequency[degrees[i]]++;
    }
    printf("\n");


    printf("Frequency of degrees:\n");
    for(int i = 0; i <= max_node; ++i){
        if(frequency[i] != 0)
            printf("Degree = %d, frequency = %d\n",i, frequency[i]);
    }
    
```
