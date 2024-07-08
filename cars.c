#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* brand;
    char* model;
    int year;
    char* color;
    float km;
    int seriNo;
    int price;
} Car;

void addingCar(Car **carList, int *count);
void deleteCar(Car **carList, int *count);
void askCar(Car **carList, int *count);
void changeInfo(Car **carList, int *count);

int main() {
    int option;
    int carCount = 0;
    Car *carList = NULL;

    do {
        printf("\n\n******************MENU******************\n");
        printf("Please choose what you want to do:\n");
        printf("1- Adding a new car to list\n");
        printf("2- Deleting a car from the list\n");
        printf("3- Ask a car from the list\n");
        printf("4- Change the information from list\n");
        printf("0- EXIT\n");
        printf("****************************************\n\n");

        scanf("%d", &option);
        printf("Your choice: %d\n", option);

        switch (option) {
            case 1:
                addingCar(&carList, &carCount);
                break;

            case 2:
                deleteCar(&carList, &carCount);
                break;

            case 3:
                askCar(&carList, &carCount);
                break;

            case 4:
                changeInfo(&carList, &carCount);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Please enter a number between 0 and 4.\n");
                break;
        }
    } while (option != 0);

    
    for (int i = 0; i < carCount; i++) {
        free(carList[i].brand);
        free(carList[i].model);
        free(carList[i].color);
    }
    free(carList);

    return 0;
}

void addingCar(Car **carList, int *count) {
    int i = *count;

        i++;


        *carList = (Car *)realloc(*carList, i * sizeof(Car));

        (*carList)[i - 1].brand = (char *)malloc(100 * sizeof(char)); 
        printf("Brand:");
        scanf("%s", (*carList)[i - 1].brand);

        (*carList)[i - 1].model = (char *)malloc(100 * sizeof(char));
        printf("Model:");
        scanf("%s", (*carList)[i - 1].model);

        printf("Year:");
        scanf("%d", &(*carList)[i - 1].year);

        (*carList)[i - 1].color = (char *)malloc(100 * sizeof(char));
        printf("Color:");
        scanf("%s", (*carList)[i - 1].color);

        printf("Km:");                                                                   
        scanf("%f", &(*carList)[i - 1].km);

        printf("Seri No:");
        scanf("%d", &(*carList)[i - 1].seriNo);

        printf("Price:");
        scanf("%d", &(*carList)[i - 1].price);

        printf("New car is added. Car ID is: %d\n\n", i);


    *count = i;
}

void deleteCar(Car **carList, int *count) {
    if (*count == 0) {
        printf("No cars to delete.\n");
        return;
    }

    int deleteIndex;
    printf("Enter the ID of the car to delete: ");
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex > *count) {
        printf("Invalid index. No car deleted.\n");
        return;
    }

    free((*carList)[deleteIndex-1].brand);
    free((*carList)[deleteIndex-1].model);
    free((*carList)[deleteIndex-1].color);

    
    for (int i = deleteIndex-1; i < *count - 1; i++) {
        (*carList)[i] = (*carList)[i + 1];
    }

    
    (*count)--;

    *carList = (Car *)realloc(*carList, *count * sizeof(Car));
    printf("Car deleted successfully.\n");
}

void askCar(Car **carList, int *count) {
    if (*count == 0) {
        printf("No cars found.\n");
        return;
    }

    char changePart[20];
    printf("Enter the part of the info to ask (brand, model, year, color, km, seriNo, price): ");
    scanf("%s", changePart);

    if (strcmp(changePart, "brand") == 0) {
        char askIndex[50];
        printf("Enter the brand that you want to research: ");
        scanf("%s", askIndex); 

        for (int i = 0; i < *count; i++) {
            if (strcmp(askIndex, (*carList)[i].brand) == 0) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "model") == 0) {
        char askIndex[50];
        printf("Enter the model that you want to research: ");
        scanf("%s", askIndex); 

        for (int i = 0; i < *count; i++) {
            if (strcmp(askIndex, (*carList)[i].model) == 0) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "year") == 0) {
        int compareYear;
        printf("Enter the year that you want to research: ");
        scanf("%d", &compareYear); 

        for (int i = 0; i < *count; i++) {
            if ((*carList)[i].year == compareYear) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "color") == 0) {
        char askIndex[20];
        printf("Enter the color that you want to research: ");
        scanf("%s", askIndex); 

        for (int i = 0; i < *count; i++) {
            if (strcmp(askIndex, (*carList)[i].color) == 0) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "km") == 0) {
        float askIndex1, askIndex2;
        printf("Enter the km interval that you want to research: ");
        scanf("%d %d", &askIndex1, &askIndex2);

        for (int i = 0; i < *count; i++) {
            if (askIndex1 < (*carList)[i].km && (*carList)[i].km < askIndex2) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "seriNo") == 0) {
        int askIndex1;
        printf("Enter the seriNo that you want to research: ");
        scanf("%d", &askIndex1);

        for (int i = 0; i < *count; i++) {
            if (askIndex1 ==  (*carList)[i].seriNo) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else if (strcmp(changePart, "price") == 0) {
        double askIndex1, askIndex2;
        printf("Enter the price interval that you want to research: ");
        scanf("%lf %lf", &askIndex1, &askIndex2);

        for (int i = 0; i < *count; i++) {
            if (askIndex1 < (*carList)[i].price && (*carList)[i].price < askIndex2) {
                printf("Brand: %s\n", (*carList)[i].brand);
                printf("Model: %s\n", (*carList)[i].model);
                printf("Year: %d\n", (*carList)[i].year);
                printf("Color: %s\n", (*carList)[i].color);
                printf("Km: %f\n", (*carList)[i].km);
                printf("SeriNo: %d\n", (*carList)[i].seriNo);
                printf("Price: %d\n\n", (*carList)[i].price);
            }
        }
    } else {
        printf("Invalid part name. No car found.\n");
    }
}

void changeInfo (Car **carList, int *count) {
    if (*count == 0) {
        printf("No cars to change info.\n");
        return;
    }

    int changeIndex;
    printf("Enter the ID of the car to change: ");
    scanf("%d", &changeIndex);

    if (changeIndex < 1 || changeIndex > *count) {
        printf("Invalid index. No car changed.\n");
        return;
    }

    char changePart[100];
    printf("Enter the part of the info to change (brand, model, year, color, km, seriNo, price): ");
    scanf("%s", changePart);

    if (strcmp(changePart, "brand") == 0) {
        char newBrand[100];
        printf("Enter new brand: ");
        scanf("%s", newBrand);

        free((*carList)[changeIndex - 1].brand);
        (*carList)[changeIndex - 1].brand = strdup(newBrand);
        
    } 
    
    else if (strcmp(changePart, "model") == 0) {
        char newModel[100];
        printf("Enter new model: ");
        scanf("%s", newModel);

        free((*carList)[changeIndex - 1].model);
        (*carList)[changeIndex - 1].model = strdup(newModel);
    } 
    else if (strcmp(changePart, "year") == 0) {
        int newYear;
        printf("Enter new year: ");
        scanf("%d", &newYear);

        (*carList)[changeIndex - 1].year = newYear;
    }
    else if (strcmp(changePart, "color") == 0) {
        char newColor[100];
        printf("Enter new color: ");
        scanf("%s", newColor);

        free((*carList)[changeIndex - 1].color);
        (*carList)[changeIndex - 1].color = strdup(newColor);
    } 
    else if (strcmp(changePart, "km") == 0) {
        float newKm;
        printf("Enter new km: ");
        scanf("%f", &newKm);

        (*carList)[changeIndex - 1].km = newKm;
    } 
    else if (strcmp(changePart, "seriNo") == 0) {
        int newSeriNo;
        printf("Enter new seriNo: ");
        scanf("%d", &newSeriNo);

        (*carList)[changeIndex - 1].seriNo = newSeriNo;
    } 
    else if (strcmp(changePart, "price") == 0) {
        int newPrice;
        printf("Enter new price: ");
        scanf("%d", &newPrice);

        (*carList)[changeIndex - 1].price = newPrice;
    } 
    else {
        printf("Invalid part name. No car changed.\n");
    }
}
