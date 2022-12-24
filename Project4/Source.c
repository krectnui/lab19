#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

struct product {
    char productName[32];
    int createDay;
    int createMonth;
    int createYear;
    int bestBeforeDate;
    float price;
    int seriaNumber;
};

typedef struct product Product;

int main()
{
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt";
    char fname2[20] = "database.txt";
    FILE* out;
    // 2
    puts("\n\n\n");
    float step;
    int writeDown;
    puts("Введите шаг для функции y = x^2 + sin 5x; [0.1; 2.1]");
    scanf("%f", &step);
    puts("Дозаписать?");
    scanf("%f", &writeDown);
    float i = 0.1;
    if (writeDown) {
        if ((out = fopen(fname, "a")) == NULL) {
            printf("Ошибка открытия файла для записи");
            return 0;
        }
        printf("Дозапись...");
    }
    else {
        if ((out = fopen(fname, "wt")) == NULL) {
            printf("Ошибка открытия файла для записи");
            return 0;
        }
        printf("Запись...");
    }
    while (i < 2.1) {
        fprintf(out, "\n |  %4.4f  |  %4.4f  |", i, i * i + sin(5 * i));
        i += step;
    }
    fclose(out);

    Product anotherProduct;
    puts("Введите название продукта: ");
    scanf("%s", anotherProduct.productName);
    puts("Введите номер дня производства товара(в месяце):");
    scanf("%d", &anotherProduct.createDay);
    puts("Введите номер месяца производства товара:");
    scanf("%d", &anotherProduct.createMonth);
    puts("Введите год производства товара:");
    scanf("%d", &anotherProduct.createYear);
    puts("Введите срок годности товара(в днях):");
    scanf("%d", &anotherProduct.bestBeforeDate);
    puts("Введите цену товара:");
    scanf("%f", &anotherProduct.price);
    puts("Введите номер серии товара:");
    scanf("%d", &anotherProduct.seriaNumber);

    if ((out = fopen(fname2, "a")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    printf("Дозапись...");
    fprintf(out, "Название продукта: %32s; День производства: %d; Месяц производства: %d; Год производства: %d; Срок годности товара: %d; Цена товара: %.3f; Номер серии: %d\n", anotherProduct.productName, anotherProduct.createDay, anotherProduct.createMonth, anotherProduct.createYear, anotherProduct.bestBeforeDate, anotherProduct.price, anotherProduct.seriaNumber);
    return 1;
}
