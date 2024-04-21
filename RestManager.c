#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ORDERS 100
#define MAX_RESERVATIONS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Order;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_people;
} Reservation;

MenuItem menu[MAX_ITEMS];
Order orders[MAX_ORDERS];
Reservation reservations[MAX_RESERVATIONS];
int num_menu_items = 0;
int num_orders = 0;
int num_reservations = 0;

void addMenuItem();
void takeOrder();
void manageInventory();
void makeReservation();
void displayMenu();
void displayOrders();
void displayReservations();

int main() {
    int choice;

    do {
        printf("\nRestaurant Management System\n");
        printf("1. Add Menu Item\n");
        printf("2. Take Order\n");
        printf("3. Manage Inventory\n");
        printf("4. Make Reservation\n");
        printf("5. Display Menu\n");
        printf("6. Display Orders\n");
        printf("7. Display Reservations\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                takeOrder();
                break;
            case 3:
                manageInventory();
                break;
            case 4:
                makeReservation();
                break;
            case 5:
                displayMenu();
                break;
            case 6:
                displayOrders();
                break;
            case 7:
                displayReservations();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void addMenuItem() {
    if (num_menu_items >= MAX_ITEMS) {
        printf("Menu is full! Cannot add more items.\n");
        return;
    }
    printf("Enter name of the item: ");
    scanf("%s", menu[num_menu_items].name);
    printf("Enter price of the item: ");
    scanf("%f", &menu[num_menu_items].price);
    printf("Enter quantity of the item: ");
    scanf("%d", &menu[num_menu_items].quantity);

    num_menu_items++;
}

void takeOrder() {
    if (num_orders >= MAX_ORDERS) {
        printf("Too many orders! Cannot take more orders.\n");
        return;
    }

    printf("Enter name of the item: ");
    scanf("%s", orders[num_orders].name);
    printf("Enter quantity of the item: ");
    scanf("%d", &orders[num_orders].quantity);

    num_orders++;
}

void manageInventory() {
    int i;
    char item_name[MAX_NAME_LENGTH];
    int quantity;

    printf("Enter name of the item to update inventory: ");
    scanf("%s", item_name);
    printf("Enter quantity to add/subtract: ");
    scanf("%d", &quantity);

    for (i = 0; i < num_menu_items; i++) {
        if (strcmp(menu[i].name, item_name) == 0) {
            menu[i].quantity += quantity;
            printf("Inventory updated successfully.\n");
            return;
        }
    }

    printf("Item not found in menu!\n");
}

void makeReservation() {
    if (num_reservations >= MAX_RESERVATIONS) {
        printf("Too many reservations! Cannot make more reservations.\n");
        return;
    }

    printf("Enter name for the reservation: ");
    scanf("%s", reservations[num_reservations].name);
    printf("Enter number of people: ");
    scanf("%d", &reservations[num_reservations].num_people);

    num_reservations++;
}

void displayMenu() {
    int i;
    printf("\nMenu:\n");
    printf("------------------------------------------------\n");
    printf("Name\t\tPrice\t\tQuantity\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < num_menu_items; i++) {
        printf("%s\t\t%.2f\t\t%d\n", menu[i].name, menu[i].price, menu[i].quantity);
    }
    printf("------------------------------------------------\n");
}

void displayOrders() {
    int i;
    printf("\nOrders:\n");
    printf("--------------------------------------\n");
    printf("Item\t\tQuantity\n");
    printf("--------------------------------------\n");
    for (i = 0; i < num_orders; i++) {
        printf("%s\t\t%d\n", orders[i].name, orders[i].quantity);
    }
    printf("--------------------------------------\n");
}
void displayReservations() {
    int i;
    printf("\nReservations:\n");
    printf("--------------------------------------\n");
    printf("Name\t\tNumber of People\n");
    printf("--------------------------------------\n");
    for (i = 0; i < num_reservations; i++) {
        printf("%s\t\t%d\n", reservations[i].name, reservations[i].num_people);
    }
    printf("--------------------------------------\n");
}
