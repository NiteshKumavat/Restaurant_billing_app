#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>

struct info{
    char name[255];
    int age;
};

struct menuItems{
    int code;
    char itemName[255];
    double price;
};


struct data{
    int code;
    char itemName[255];
    double price;
    int quantity;
};

int order = 0;
struct data orders[20];


int addItem(int code, struct menuItems menu[], int quantity){
    for(int i=0; i<20; i++){
        if(code == menu[i].code){
            orders[order].code = menu[i].code;
            strcpy(orders[order].itemName ,menu[i].itemName);
            orders[order].price = menu[i].price;
            orders[order].quantity = quantity;
            order++;
            return 1;
        }
    }
    return -1;
}

void billing(char* name, int age){
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Name : %s\t\t\t age : %d\n", name, age);
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Code\t\t| Food Item\t\t\t| Price(in dollers)\t|Quantity\t|Total Price\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    double currentAmount = 0;
    for(int i=0; i<order; i++){
        double total_amount = orders[i].price * orders[i].quantity;
        printf("%d\t\t| %s\t\t| %0.1lf\t\t\t| %d\t\t|%0.2lf\n", orders[i].code, orders[i].itemName, orders[i].price, orders[i].quantity, total_amount);
        currentAmount += total_amount;
        
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Before GST Total Amount \t\t\t\t\t\t\t\t| %0.2lf\n", currentAmount);
    printf("CGST = 9%% \t\t\t\t\t\t\t\t\t\t| %0.2lf\n", currentAmount*(0.09));
    printf("CGST = 9%% \t\t\t\t\t\t\t\t\t\t| %0.2lf\n", currentAmount*(0.09));
    double totalAmount = currentAmount+currentAmount*(0.18);
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Total Amount \t\t\t\t\t\t\t\t\t\t| %0.2lf\n", totalAmount);
    printf("----------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
}


void setMenu(){
    struct menuItems menu[20] = {
        {101, "Margherita Pizza    ", 8.99},
        {102, "Veg Burger          ", 4.99},
        {103, "Cheese Sandwich     ", 3.99},
        {104, "Grilled Chicken     ", 10.99},
        {105, "French Fries        ", 2.99},
        {106, "Pasta Alfredo       ", 7.99},
        {107, "Paneer Tikka        ", 6.99},
        {108, "Chicken Biryani     ", 9.99},
        {109, "Veg Biryani         ", 8.49},
        {110, "Mutton Curry        ", 11.99},
        {111, "Caesar Salad        ", 5.49},
        {112, "Spring Rolls        ", 4.49},
        {113, "Noodles             ", 6.99},
        {114, "Samosa              ", 1.99},
        {115, "Butter Naan         ", 1.49},
        {116, "Cold Coffee         ", 2.99},
        {117, "Lemonade            ", 1.99},
        {118, "Chocolate Shake     ", 3.49},
        {119, "Gulab Jamun         ", 2.49},
        {120, "Ice Cream (2 scoops)", 3.99}
    };

    char answer[10];
    int quantity;
    int code;

    do
    {
        printf("------------------------------------------------------------------------------------------------\n");
        printf("\t\t\tMenu\n");
        printf("------------------------------------------------------------------------------------------------\n");
        printf("Code\t\t| Food Item\t\t\t| Price(in dollers)\n");
        printf("--------------------------------------------------------------------\n");
        for(int i=0; i<20; i++){
            printf("%d\t\t| %s\t\t| %0.2lf\n", menu[i].code, menu[i].itemName, menu[i].price);
            printf("--------------------------------------------------------------------\n");
        }
        printf("Do you want to order something yes or no : ");
        scanf(" %s", answer);
        if (strcmp(answer, "yes") == 0){
            printf("Enter the food code : ");
            scanf("%d", &code);
            printf("Enter the food quantity : ");
            scanf("%d", &quantity);
            if(addItem(code, menu, quantity) == -1){
                printf("Please Choose the correct code value :)\n");
            }else{
                printf("item added successfully\n");
            }
            sleep(5);
            
        }
        system("cls");
    }while (strcmp(answer,"yes") == 0);
    
}


void displayOrders(){
    if(order == 0){
        printf("You didn't order anything yet! ");
    }else{
        for(int i=0; i<order; i++){
            printf("Order no. %d\n", i+1);
            printf("Code : %d\n", orders[i].code);
            printf("Item Name : %s\n", orders[i].itemName);
            printf("Price : %0.2lf\n", orders[i].price);
            printf("Quantity : %d\n\n", orders[i].quantity);
        }
    }
    system("pause");
    system("cls");
}


void updateOrders(){
    int answer = 0;
    do{
        printf("Enter 1 for adding items and 2 for delete the item and 0 for exiting : ");
        scanf("%d", &answer);
        switch(answer){
            case 1 : setMenu();
                break;
            case 2 : 
                printf("Enter the Order no.  : ");
                int number;
                scanf("%d", &number);
                number--;
                if(number > 0 && number < order){
                    for(int i=number; i<order-1; i++){
                        orders[i] = orders[i+1];
                    }
                    order--;
                    printf("Item deleted successfully\n");
                }else{
                    printf("invalid Order number");
                }
                sleep(5);
                system("cls");
                break;
            case 0 : break;
            
            default :
                printf("Invalid Number\n");

        }
    }while(answer != 0);
    system("cls");

}

void displayInfo(char* name , int age){
    int answer = 0;
    do
    {
        printf("------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t Welcome to our Restaurant\n");
        printf("------------------------------------------------------------------------------------------------\n");
        printf("1. Menu\n");
        printf("2. See Your Orders\n");
        printf("3. Update Your Orders\n");
        printf("4. Bill\n");
        printf("5. Exit\n");
        
        printf("Enter Your Choice : ");
        scanf("%d", &answer);
        system("cls");
        switch (answer)
        {
        case 1:
            setMenu();
            break;

        case 2 :
            displayOrders();
            break;

        case 3 :
            updateOrders();
            break;
        
        case 4 :
            billing(name, age);
            break;

        case 5 :
            printf("Exiting....");
            sleep(5);
            break;
        
        default:
            printf("Invalid Input");
            break;
        }
    } while (answer != 5);
    
}


int main(){
    char name[255];
    printf("Enter Your Name : ");
    fgets(name, 255, stdin);
    name[strcspn(name, "\n")] = 0;
    int age;
    printf("Enter Your age : ");
    scanf("%d", &age);
    displayInfo(name, age);
    return 0;
}