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
    puts("������� ��� ��� ������� y = x^2 + sin 5x; [0.1; 2.1]");
    scanf("%f", &step);
    puts("����������?");
    scanf("%f", &writeDown);
    float i = 0.1;
    if (writeDown) {
        if ((out = fopen(fname, "a")) == NULL) {
            printf("������ �������� ����� ��� ������");
            return 0;
        }
        printf("��������...");
    }
    else {
        if ((out = fopen(fname, "wt")) == NULL) {
            printf("������ �������� ����� ��� ������");
            return 0;
        }
        printf("������...");
    }
    while (i < 2.1) {
        fprintf(out, "\n |  %4.4f  |  %4.4f  |", i, i * i + sin(5 * i));
        i += step;
    }
    fclose(out);

    Product anotherProduct;
    puts("������� �������� ��������: ");
    scanf("%s", anotherProduct.productName);
    puts("������� ����� ��� ������������ ������(� ������):");
    scanf("%d", &anotherProduct.createDay);
    puts("������� ����� ������ ������������ ������:");
    scanf("%d", &anotherProduct.createMonth);
    puts("������� ��� ������������ ������:");
    scanf("%d", &anotherProduct.createYear);
    puts("������� ���� �������� ������(� ����):");
    scanf("%d", &anotherProduct.bestBeforeDate);
    puts("������� ���� ������:");
    scanf("%f", &anotherProduct.price);
    puts("������� ����� ����� ������:");
    scanf("%d", &anotherProduct.seriaNumber);

    if ((out = fopen(fname2, "a")) == NULL) {
        printf("������ �������� ����� ��� ������");
        return 0;
    }
    printf("��������...");
    fprintf(out, "�������� ��������: %32s; ���� ������������: %d; ����� ������������: %d; ��� ������������: %d; ���� �������� ������: %d; ���� ������: %.3f; ����� �����: %d\n", anotherProduct.productName, anotherProduct.createDay, anotherProduct.createMonth, anotherProduct.createYear, anotherProduct.bestBeforeDate, anotherProduct.price, anotherProduct.seriaNumber);
    return 1;
}
