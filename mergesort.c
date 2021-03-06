#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

//exit(100) - ошибка ввода 


void merge(int* a, int, int);

clock_t start, end;


int main(void)
{
    int* mass;
    long int qw;
    int n;
    int k;
    

    printf("-------MergeSort Realization-------\n");
    printf("Выберите способ задания чисел\n1)Свои числа\n2)Рандомные числа\n->");
    scanf_s("%d", &k);

    if (k == 1)
    {
       
        printf("Введите количество чисел:");
        scanf_s("%d", &qw);


        mass = (int*)malloc(qw * sizeof(int));


        for (n = 0; n < qw; n++)
        {
            printf("Введите числа:");
            scanf_s("%d", &mass[n]);
        }

        merge(mass, 0, qw - 1);

        for (int i = 0; i < qw; i++)
        {
            printf("%d ", mass[i]);
        }

        free(mass);
    }


    if (k == 2)
    {

        printf("Введите количество чисел:");
        scanf_s("%d", &qw);

        srand(time(NULL));

        mass = (int*)malloc(qw * sizeof(int));

        for (int l = 0; l < qw; l++)
        {
            mass[l] = rand() % 1000000001;
        }
        clock_t begin = clock();
        merge(mass, 0, qw - 1);
        clock_t end = clock();

        for (int i = 0; i < qw; i++)
        {
            printf("%d ", mass[i]);
        }

        printf("\n\ntime : %.15f ms", (float)(end - begin)/ CLOCKS_PER_SEC);
        free(mass);

    }
    else{
        exit(100);
    }

    return 0;

}


void merge(int* a, int l, int r)
{


    if (l == r) return;
    int mid = (l + r) / 2;

    merge(a, l, mid);
    merge(a, mid + 1, r);

    int i = l;
    int j = mid + 1;
    int* tmp = (int*)malloc((r + 1) * sizeof(int));



    for (int step = 0; step < r - l + 1; step++)
    {

        if ((j > r) || ((i <= mid) && (a[i] < a[j])))
        {
            tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }

    }

    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = tmp[step]; 
}

