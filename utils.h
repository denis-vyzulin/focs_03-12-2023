#ifndef UTILS_H_
#define UTILS_H_
// ----------------------



// Новый тип данных для товара
typedef struct {
    char name[10];
    int price;
    int discount;
    float rate;
} product;


// Консольное меню
void console_menu(char *filename);

// Создание новой базы данных
void add_products(char *filename, int type);

// Просмотр списка элементов БД
void get_products(char *filename);

// Поиск элементов бд
void find_product(char *filename);



// ----------------------
#endif /* UTILS_H_ */