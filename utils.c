#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "utils.h"
// ----------------------



//==> Создание новой базы данных
void add_products(char *filename, int type) {
    int length;
    printf("How many new products: ");
    scanf("%i", &length);
    
    // Массив строк
    product *products = (product*)calloc(length, sizeof(product));
    
    // Добавляем строки
    for (int i = 0; i < length; i++) {
        printf("--- product %i\n", i+1);
        printf("Product name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%i", &products[i].price);
        printf("Discount (in %%): ");
        scanf("%i", &products[i].discount);
        printf("Rating (use dot): ");
        scanf("%f", &products[i].rate);
    }
    
    // Сохраняем строки в файл
    if (type == 0) {
        FILE *db = fopen(filename, "w");
        fwrite(products, sizeof(product), length, db);
        fclose(db);
    } else {
        FILE *db = fopen(filename, "a");
        fwrite(products, sizeof(product), length, db);
        fclose(db);
    }
    
    // Освобождаем память
    free(products);

    printf("Press any key for continue...");
    getch();
    return;
}


//==> Просмотр списка элементов БД
void get_products(char *filename) {
    // Гототвим файл к работе
    FILE *db = fopen(filename, "r");
    fseek(db, 0, SEEK_END);
    
    // Получаем список элементов
    int length = ftell(db) / sizeof(product);
    rewind(db);
    product *products = (product*)calloc(length, sizeof(product));
    fread(products, sizeof(product), length, db);
    fclose(db);
    
    // Выводим элементы в консоль
    printf("List of products\n");
    for (int i = 0; i < length; i++) {
        printf("%i. %s (%.1f)\n", i+1, products[i].name, products[i].rate);
        printf("   Price: %i, Sale: %i%%\n", products[i].price, products[i].discount);
    }
    
    // Освобождаем память
    free(products);

    printf("Press any key for continue...");
    getch();
    return;
}



//==> Поиск элемента
void find_product(char *filename) {
	char *product_name = "none";
	printf("Are you looking for: ");
	scanf("%s", product_name);
	
    // Гототвим файл к работе
    FILE *db = fopen(filename, "r");
    fseek(db, 0, SEEK_END);
	
    // Получаем список элементов
    int length = ftell(db) / sizeof(product);
    rewind(db);
    product *products = (product*)calloc(length, sizeof(product));
    fread(products, sizeof(product), length, db);
    fclose(db);

    // Ищем товары
	int flag = false;
	for (int i = 0; i < length; i++) {
        if (strstr(products[i].name, product_name) != NULL){
            printf("Your product was found!");
            flag = true;
		}
	}
	if (!flag) {
	    printf("Your product wasn't found!");
	}

	// Освобождаем память
    free(products);

    printf("Press any key for continue...");
    getch();
    return;
}


//==> Консольное меню
void console_menu(char *filename) {
    char *options[4];
    options[0] = "1. Create new database";
    options[1] = "2. Add new products";
    options[2] = "3. View all products";
    options[3] = "4. Find products";
    options[4] = "5. Finish program";

    // Очищаем консоль
    system("cls");

    // Получаем вариант
    int variant = 0;
    printf("%s\n%s\n%s\n%s\n%s\n>> ", options[0], options[1], options[2], options[3], options[4]);
    scanf("%i", &variant);

    switch (variant) {
        case 1:
            system("cls");
            add_products(filename, 0);
            console_menu(filename);
        case 2:
            system("cls");
            add_products(filename, 1);
            console_menu(filename);
        case 3:
            system("cls");
            get_products(filename);
            console_menu(filename);
        case 4:
            system("cls");
            find_product(filename);
            console_menu(filename);
        case 5:
            exit(EXIT_SUCCESS);

        default:
            console_menu(filename);
    }
}


//==> Отображение опций
// void show_options(int selected, int index, char *options) {
//     // Выводим опции в консоль
//     if (selected == index) {
//         printf("> %s\n", options);
//     } else {
//         printf("  %s\n", options);
//     }
//     return;
// }


//==> Консольное меню (неудачное)
// void console_menu_tmp() {
//     // Объявляем опции
//     const int OPTIONS_LENGTH = 3;
//     char *options[2];
//     options[0] = "Create new database";
//     options[1] = "View products";
//     options[2] = "Change product";

//     int selected = 0, key = 0;
//     do {
//         if (key != 0) key = getch();

//         if (key == 119 && selected > 0) {
//             selected = selected - 1;
//         } else if (key == 115 && selected < OPTIONS_LENGTH) {
//             selected = selected + 1;
//         } else {
//             selected = selected;
//         }

//         for (int i = 0; i < OPTIONS_LENGTH; i++) {
//             show_options(selected, i, options[i]);
//         }
//     } while (key != 27);
// }



// ----------------------