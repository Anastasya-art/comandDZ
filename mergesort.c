#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define __STDC_WANT_LIB_EXT1__ 1

//exit(100) - ошибка ввода 


void merge(int* a, int, int);

clock_t start, end;


int main(void)
{
    int* mass;
    int* arr;
    int qw, n, q;
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
        scanf_s("%d", &q);

        srand(time(NULL));

        arr = (int*)malloc(q * sizeof(int));

        for (int l = 0; l < q; l++)
        {
            arr[l] = rand() % 1000000001;
        }
        clock_t begin = clock();
        merge(arr, 0, q - 1);
        clock_t end = clock();

        for (int i = 0; i < q; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n\ntime : %.15f ms", (float)(end - begin)/ CLOCKS_PER_SEC);
        free(arr);

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

