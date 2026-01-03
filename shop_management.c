#include <stdio.h>

struct Product {
    int id;
    char name[50];
    int qty;
    float price;
    float total;
};

int main() {
    struct Product p[5], temp;
    FILE *fp;
    int i, searchId, found = 0;
    float grandTotal = 0;

    for (i = 0; i < 5; i++) {
        printf("\nEnter details of Product %d\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &p[i].id);

        printf("Product Name: ");
        scanf("%s", p[i].name);

        printf("Quantity: ");
        scanf("%d", &p[i].qty);

        printf("Price: ");
        scanf("%f", &p[i].price);

        p[i].total = p[i].qty * p[i].price;
    }

    
    fp = fopen("products.txt", "w");
    for (i = 0; i < 5; i++) {
        fprintf(fp, "%d %s %d %.2f %.2f\n",
                p[i].id, p[i].name, p[i].qty, p[i].price, p[i].total);
    }
    fclose(fp);

    
    fp = fopen("products.txt", "r");

    printf("\n-----------------------------------------------\n");
    printf("ID\tName\tQty\tPrice\tTotal\n");
    printf("-----------------------------------------------\n");

    while (fscanf(fp, "%d %s %d %f %f",
                  &temp.id, temp.name, &temp.qty, &temp.price, &temp.total) != EOF) {

        printf("%d\t%s\t%d\t%.2f\t%.2f\n",
               temp.id, temp.name, temp.qty, temp.price, temp.total);

        grandTotal += temp.total;
    }

    printf("-----------------------------------------------\n");
    printf("Total Bill Amount: %.2f\n", grandTotal);
    fclose(fp);

    
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    fp = fopen("products.txt", "r");
    while (fscanf(fp, "%d %s %d %f %f",
                  &temp.id, temp.name, &temp.qty, &temp.price, &temp.total) != EOF) {

        if (temp.id == searchId) {
            printf("\nProduct Found!");
            printf("\nID: %d", temp.id);
            printf("\nName: %s", temp.name);
            printf("\nQuantity: %d", temp.qty);
            printf("\nPrice: %.2f", temp.price);
            printf("\nTotal: %.2f\n", temp.total);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }

    fclose(fp);

    return 0;
}
