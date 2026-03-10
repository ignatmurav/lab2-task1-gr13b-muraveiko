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

    return 0;
}