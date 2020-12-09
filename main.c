#include<stdio.h>
#include<stdlib.h>


int main(void){
  int arr1[100];
  int arr2[100];
  printf("Enter the graph, write -1 - -1 to end\n");
  int a = 0;
  int max_node = -1;;
  do{
    int c,d;
    scanf("%d - %d",&c, &d);
    if(c == -1 && d == -1) break;
    if(c > max_node) max_node = c;
    if(d > max_node) max_node = d;
    arr1[a] = c;
    arr2[a] = d;
    a++;
  }while(1);

  int matrix[100][100]; // обнуление матрицы графа
  for(int i =0; i < 100; ++i){
    for(int j = 0; j < 100; ++j)
      matrix[i][j] = 0;
  }


  for(int i = 0; i < a; ++i){ // заполнение матрицы графа
    if(arr1[i] == arr2[i]){
      matrix[arr1[i]][arr2[i]] += 1;
      continue;
    }

    matrix[arr1[i]][arr2[i]] += 1;
    matrix[arr2[i]][arr1[i]] += 1;
  }



    int* degrees = (int*) malloc(max_node * sizeof(int)); // степени вершин графа
    for(int i =0; i<=max_node; ++i) // обнуляем массив степеней
        degrees[i] = 0;

    int max_degree = -1; //максимальная степень
    for(int j = 1; j<=max_node; ++j){ // заполняем массив степеней; индекс - номер вершины, значение - степень
        for(int i = 1; i<=max_node; ++i){
            if(i == j){
                degrees[j] += 2*matrix[i][j]; // ребро - петля учитывается дважда
                continue;
            }
            degrees[j] += matrix[i][j];
        }
        if(degrees[j] > max_degree) // поиск максимальной степени
            max_degree = degrees[j];
    }


    int* frequency = (int*) malloc(max_node * sizeof(int)); // массив частот степеней
    for(int i = 0; i <= max_node; ++i){ // обнуляем массив frequency
        frequency[i] = 0;
    }


    // записываем частоту степеней вершин
    for(int i = 1; i <= max_node; ++i){
        frequency[degrees[i]]++;
    }
    printf("\n");


    printf("Frequency of degrees:\n");
    for(int i = 0; i <= max_node; ++i){
        if(frequency[i] != 0)
            printf("Degree = %d, frequency = %d\n",i, frequency[i]);
    }


    // массив, в котором вершины сгруппированы по степеням
    int nodes_grouped[100][100];
    for(int i =0; i<= max_degree; ++i){ // i - значение степени, элементы каждой строки - вершины
        int j =0;
        for(int x =1; x <= max_node; ++x){
            if(degrees[x] == i){
                nodes_grouped[i][j] = x;
                j++;
            }
        }
    }


    printf("\nNodes sorted by degree: ");
    for(int i = 0; i<= max_node; ++i){
        if(frequency[i] != 0){
            for(int j =0; j< frequency[i]; ++j){
                printf("%d ",nodes_grouped[i][j]);
            }
        }
    }

    printf("\n");

  FILE *file;
  file = fopen("graph.dot", "w");
  fprintf(file,"graph gr{\n");
  for(int i = 0; i < a; ++i){
    if(arr1[i] == 0){
      fprintf(file,"\t%d;\n",arr2[i]);
      continue;
    }
    if(arr2[i] == 0) {
      fprintf(file,"\t%d;\n",arr1[i]);
    continue;
  }
    fprintf(file, "\t%d -- %d;\n", arr1[i], arr2[i]);

  }
  fprintf(file, "}");
  fclose(file);

  system("dot -v -Tpng -o graph_image.png graph.dot");
  system("graph_image.png");

  free(degrees);
  free(frequency);

  return 0;
}
