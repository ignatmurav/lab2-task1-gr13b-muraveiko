/*
 * Author: Муравейко Игнат, 13 гр
 * Description: Программа для сравнения двух классов.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLASS_SIZE 18

/* Заполнение массива случайными числами от min до max */
void fill_random(double arr[], int n, double min, double max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + (rand() / (RAND_MAX + 1.0)) * (max - min);
    }
}

/* Вывод массива на экран */
void print_array(const double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5.2f ", arr[i]);
    }
    printf("\n");
}

/* Функция сравнения для сортировки по убыванию (используется в qsort) */
int cmp_desc(const void *a, const void *b) {
    double diff = *(double*)b - *(double*)a;
    return (diff > 0) - (diff < 0);
}

/* Находит k-й по величине элемент в массиве (k от 1) */
double kth_largest(double arr[], int n, int k) {
    if (k < 1 || k > n) return -1.0;
    double *sorted = malloc(n * sizeof(double));
    if (!sorted) return -1.0;
    for (int i = 0; i < n; i++) sorted[i] = arr[i];
    qsort(sorted, n, sizeof(double), cmp_desc);
    double result = sorted[k-1];
    free(sorted);
    return result;
}

int main() {
    double class1[CLASS_SIZE];
    double class2[CLASS_SIZE];

    srand(time(NULL));

    fill_random(class1, CLASS_SIZE, 2.0, 5.0);
    fill_random(class2, CLASS_SIZE, 2.0, 5.0);

    printf("Класс 1 (случайные оценки):\n");
    print_array(class1, CLASS_SIZE);
    printf("Класс 2 (случайные оценки):\n");
    print_array(class2, CLASS_SIZE);

    double third1 = kth_largest(class1, CLASS_SIZE, 3);
    double third2 = kth_largest(class2, CLASS_SIZE, 3);
    printf("Третья по величине оценка в классе 1: %.2f\n", third1);
    printf("Третья по величине оценка в классе 2: %.2f\n", third2);

    return 0;
}