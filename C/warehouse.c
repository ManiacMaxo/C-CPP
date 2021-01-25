#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    float quality;
    int quantity;
} product_t;

typedef struct {
    char name[15];
    product_t product;
} factory_t;

typedef struct {
    int num_comp;  // compartments
    int max;       // maximum products
    product_t *products;
} warehouse_t;

product_t *production(factory_t *factories) {
    int n = sizeof(factories) / sizeof(factory_t);
    product_t *products = malloc(sizeof(product_t) * n);
    for (int i = 0; i < n; i++) {
        products[i] = factories[i].product;
    }
    return products;
}

int product_available(warehouse_t wh, product_t product) {
    for (int i = 0; i < sizeof(wh.products) / sizeof(product_t); i++) {
        if (strcmp(product.name, wh.products[i].name) &&
            product.quality == wh.products[i].quality) {
            return i;  // where
        }
    }
    return -1;
}

int free_compartment(warehouse_t wh) {
    for (int i = 0; i < wh.num_comp; i++) {
        if (wh.products[i].name[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void add_products(product_t *products, warehouse_t wh) {
    int n = sizeof(products) / sizeof(product_t);  // number of products
    int comp, where;

    for (int i = 0; i < n; i++) {
        where = product_available(wh, products[i]);

        if (where != -1) {
            if (wh.products[where].quantity + products[i].quantity >= wh.max) {
                products[i].quantity -= wh.max - wh.products[where].quantity;
                wh.products[where].quantity = wh.max;
                where = -1;
                continue;
            } else {
                wh.products[where].quantity += products[i].quantity;
            }
        }

        if (where == -1) {
            comp = free_compartment(wh);
            if (comp != -1) {
                wh.products[comp] = products[i];
            } else {
                printf("no free place to load product\n");
            }
        }
    }
}

int main(int argc, char **argv) {
    int F = atoi(argv[1]);  // num factories
    int W = atoi(argv[2]);  // max size of wh
    int S = atoi(argv[3]);  // products in wh
    int I = atoi(argv[4]);  // num itterations

    product_t *products = malloc(2 * sizeof(product_t));
    factory_t *factories = malloc(F * sizeof(factory_t));
    warehouse_t wh = {
        .max = W,
        .num_comp = S,
        .products = malloc(sizeof(product_t) * W),
    };

    for (int i = 0; i < I; i++) {
        add_products(products, wh);
    }

    free(factories);
    free(products);
}
