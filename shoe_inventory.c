#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct Shoe {
    int stockNumber;
    int styleNumber; //0 - 50
    int sizes[12]; //NUMBER OF PAIRS FOR SIZE 3 - 14
    float price;
};

void Create(struct Shoe *shoeRecord);
void Read(struct Shoe *shoeRecord);
void Update(struct Shoe *shoeRecord);
void Delete(struct Shoe *shoeRecord);
bool CheckIfExisting(int Number, int choice);

int main() {
    int userChoice;

    while (1) {
        struct Shoe shoeRecord;

        printf("\nSHOE INVENTORY MENU:\n");
        printf("\t1: CREATE SHOE INVENTORY\n");
        printf("\t2: DISPLAY SHOE INVENTORY\n");
        printf("\t3: UPDATE SHOE INVENTORY\n");
        printf("\t4: DELETE SHOE INVENTORY\n");
        printf("\t5: EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                Create(&shoeRecord);
                break;
            case 2:
                Read(&shoeRecord);
                break;
            case 3:
                Update(&shoeRecord);
                break;
            case 4:
                Delete(&shoeRecord);
                break;
            case 5:
                printf("\nDo you want to continue the exit?\n");
                printf("\tEnter Y for YES and N for NO: ");
                scanf(" %c", &userChoice);

                if (userChoice == 'Y') {
                    printf("\nThank you for using our program!\n");
                    return 1;
                }

                break;
        }
    }
}

void Create(struct Shoe *shoeRecord) {
    FILE *inventory = fopen("inventory.txt", "a");

    int i;
    char userChoice;

    while (1) {
        printf("Enter the stock number: ");
        scanf("%d", &shoeRecord->stockNumber);

        if (CheckIfExisting(shoeRecord->stockNumber, 1)) 
            printf("INPUT ANOTHER NUMBER\n");
        else
            break;
    }

    while (1) {
        printf("Enter the style number: ");
        scanf("%d", &shoeRecord->styleNumber);

        if (CheckIfExisting(shoeRecord->styleNumber, 2) || shoeRecord->styleNumber > 50) 
            printf("INPUT ANOTHER NUMBER\n");
        else
            break;
    }

    printf("Enter the price: ");
    scanf("%f", &shoeRecord->price);

    printf("\nEnter the number on hand for size 3 - 14\n");
    for (i = 0; i < 12; i++) {
        printf("Size %d: ", i + 3);
        scanf("%d", &shoeRecord->sizes[i]);
    }

    printf("\nEnter [Y] to continue the insertion and [N] for cancellation: ");
    scanf(" %c", &userChoice);

    if (userChoice == 'Y') {
        fprintf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: ", shoeRecord->stockNumber, shoeRecord->styleNumber);

        for (i = 0; i < 12; i++)
            fprintf(inventory, "%d ", shoeRecord->sizes[i]);
        
        fprintf(inventory, "| PRICE: %.2f\n", shoeRecord->price);

        printf("\nSuccessfully inserted.\n");
    }
    else
        printf("\nCancellation confirmed.\n");
    
    fclose(inventory);
}

void Read(struct Shoe *shoeRecord) {
    FILE *inventory = fopen("inventory.txt", "r");

    int i, userChoice, count = 1;
    bool ifFound = false;
    int stockStyleNumber;
    int stockNumber;
    int styleNumber;
    int size;

    printf("\nDISPLAY ONLY OF SPECIFIC INVENTORY\n");
    printf("\t1. DISPLAY ALL SHOES RECORD\n");
    printf("\t2. DISPLAY SPECIFIC SHOE\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
		case 1:
            while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price) == 15) {
					
		        printf("\nSHOE #%d\n", count);
		        printf("\tSTOCK NUMBER: %d\n", shoeRecord->stockNumber);
		        printf("\tSTYLE NUMBER: %d\n", shoeRecord->styleNumber);
		        printf("\tSHOE PRICE: %.2f\n\n", shoeRecord->price);
		
		        for (i = 0; i < 12; i++)
		            printf("\tSIZE %d: %d\n", i + 3, shoeRecord->sizes[i]);
		        
		        count++;
		    }
		    break;

		case 2:
		    printf("\nEnter the stock number: ");
		    scanf("%d", &stockNumber);
		
		    printf("Enter the style number: ");
		    scanf("%d", &styleNumber);
		
		    printf("\nDISPLAY SPECIFIC SHOE\n");
		    printf("\t1. Stock Number Only\n");
		    printf("\t2. Stock Style Only\n");
		    printf("\t3. Size Only\n");
		    printf("\t4. Price Only\n");
		    printf("\t5. Stock Number Only & Stock Style Only & Size Only\n");
		    printf("ENTER YOUR CHOICE: ");
		    scanf("%d", &userChoice);
		
		    while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price) == 15) {
		
		        if (shoeRecord->stockNumber == stockNumber || shoeRecord->styleNumber == styleNumber) {
		            switch (userChoice) {
		                case 1:
		                    printf("\nSHOE #%d\n", count);
		                    printf("STOCK NUMBER: %d\n", shoeRecord->stockNumber);
		                    break;
		                case 2:
		                    printf("\nSHOE #%d\n", count);
		                    printf("STYLE NUMBER: %d\n", shoeRecord->styleNumber);
		                    break;
		                case 3:
		                    printf("\nSHOE #%d\n", count);
		                    printf("SIZE DETAILS:\n");
		                    for (i = 0; i < 12; i++) {
		                        printf("SIZE %d: %d\n", i + 3, shoeRecord->sizes[i]);
		                    }
		                    break;
		                case 4: // Case for displaying price only
		                    printf("\nSHOE #%d\n", count);
		                    printf("PRICE: %.2f\n", shoeRecord->price);
		                    break;
		                case 5:
		                    printf("\nSHOE #%d\n", count);
		                    printf("STOCK NUMBER: %d\n", shoeRecord->stockNumber);
		                    printf("STYLE NUMBER: %d\n", shoeRecord->styleNumber);
                            printf("PRICE: %.2f\n", shoeRecord->price);
		                    printf("NUMBER ON HAND FOR SIZE 3 - 14\n");
		                    for (i = 0; i < 12; i++) {
		                        printf("SIZE %d: %d\n", i + 3, shoeRecord->sizes[i]);
		                    }
		                    break;
		                default:
		                    printf("\nINVALID CHOICE.\n");
		                    break;
		            }
		            ifFound = true;
		            break;
		        }
		
		        count++;
		    }
		    if (!ifFound) {
		        printf("\nRECORD NOT FOUND.\n");
		    }
		    break;
		}

        fclose(inventory);
}

void Update(struct Shoe *shoeRecord) {
    FILE *inventory = fopen("inventory.txt", "r");
    FILE *tempFile = fopen("tempFile.txt", "w");

    int i, userChoice, stockNumber, styleNumber;
    bool ifFound = false;
    char confirmation;

    printf("\nMENU FOR UPDATING THE RECORD\n");
    printf("\t1: CHANGE PRICE\n");
    printf("\t2: CHANGE STOCK ON HAND\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &userChoice);

	printf("\nEnter the stock number: ");
	scanf("%d", &stockNumber);
		
	printf("Enter the style number: ");
	scanf("%d", &styleNumber);

    while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price) == 15) {

        if (shoeRecord->stockNumber == stockNumber && shoeRecord->styleNumber == styleNumber) {
            ifFound = true;

            switch (userChoice) {
                case 1:
                    printf("\nCURRENT PRICE OF STOCK NUMBER %d: %.2f\n", shoeRecord->stockNumber, shoeRecord->price);
                    printf("Enter the new price: ");
                    scanf("%f", &shoeRecord->price);

                    printf("\nEnter [Y] to confirm the change price and [N] for cancellation: ");
                    scanf(" %c", &confirmation);
                    confirmation = toupper(confirmation);

                    if (confirmation == 'Y') {
                        printf("\nSuccessfully changed the price of stock number %d to %.2f.\n", shoeRecord->stockNumber, shoeRecord->price);
                    }
                    else {
                        printf("\nCancellation confirmed.\n");
                    }
                    break;
                case 2:
                    printf("\n1: Update stock for a specific size\n");
                    printf("2: Update stock for all sizes\n");
                    printf("ENTER YOUR CHOICE: ");
                    int sizeUpdateChoice;
                    scanf("%d", &sizeUpdateChoice);

					if (sizeUpdateChoice == 1) {
					    int specificSize;
					    printf("\nEnter the size (3 to 14) to update stock: ");
					    scanf("%d", &specificSize);
					
					    if (specificSize < 3 || specificSize > 14) {
					        printf("\nInvalid size. Please enter a size between 3 and 14.\n");
					    } else {
					        int newStock;
					        printf("Enter the new stock on hand for size %d: ", specificSize);
					        scanf("%d", &newStock);

					        int sizeIndex = specificSize - 3;

					        shoeRecord->sizes[sizeIndex] = newStock;
					
					        printf("\nSuccessfully updated stock for size %d to %d for stock number %d.\n", specificSize, newStock, shoeRecord->stockNumber);
					    }
					}
                    else if (sizeUpdateChoice == 2) {
                        int tempNumber, tempHolder;

                        printf("\nEnter the new stock on hand for all sizes (for sizes 3 to 14):\n");

                        for (int i = 0; i < 12; i++) {
                            printf("Size %d: ", i + 3);
                            scanf("%d", &tempNumber);
                            shoeRecord->sizes[i] = tempNumber;
                        }

                        printf("\nEnter [Y] to confirm the change stock on hand and [N] for cancellation: ");
                        scanf(" %c", &confirmation);

                        if (confirmation == 'Y') {
                            printf("\nSuccessfully changed the stock on hand for all sizes for stock number %d.\n", shoeRecord->stockNumber);
                        }
                        else {
                            printf("\nCancellation confirmed.\n");
                        }
                    }
                    else {
                        printf("\nINVALID CHOICE.\n");
                    }
                    break;
                default:
                    printf("\nINVALID CHOICE.\n");
                    break;
            }
        }

        fprintf(tempFile, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %.2f\n", shoeRecord->stockNumber, shoeRecord->styleNumber, shoeRecord->sizes[0], shoeRecord->sizes[1], shoeRecord->sizes[2], shoeRecord->sizes[3], shoeRecord->sizes[4], shoeRecord->sizes[5], shoeRecord->sizes[6], shoeRecord->sizes[7], shoeRecord->sizes[8], shoeRecord->sizes[9], shoeRecord->sizes[10], shoeRecord->sizes[11], shoeRecord->price);
    }

    if (!ifFound)
        printf("\nRECORD NOT FOUND\n");

    fclose(inventory);
    fclose(tempFile);

    remove("inventory.txt");
    rename("tempFile.txt", "inventory.txt");
}


void Delete(struct Shoe *shoeRecord) {
    FILE *inventory = fopen("inventory.txt", "r");
    FILE *tempFile = fopen("tempFile.txt", "w");

    int i, userChoice, stockStyleNumber;
    bool ifFound = false;
    char confirmation;

    printf("\nMENU FOR DELETING THE RECORD\n");
    printf("\t1: DELETE SPECIFIC SHOE RECORD\n");
    printf("\t2: DELETE WHOLE SHOE RECORD\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &userChoice);

    if (userChoice == 1) {
        printf("Enter the stock/style number: ");
        scanf("%d", &stockStyleNumber);

        while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price) == 15) {

            if (stockStyleNumber == shoeRecord->stockNumber || stockStyleNumber == shoeRecord->styleNumber) {
                ifFound = true;
                printf("\nSuccessfully delete the record of stock number %d.\n", shoeRecord->stockNumber);
            } else {
                fprintf(tempFile, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: ", shoeRecord->stockNumber, shoeRecord->styleNumber);
                for (i = 0; i < 12; i++)
                    fprintf(tempFile, "%d ", shoeRecord->sizes[i]);
                fprintf(tempFile, "| PRICE: %.2f\n", shoeRecord->price);
            }
        }

        if (!ifFound)
            printf("\nRECORD NOT FOUND.\n");
    } else if (userChoice == 2) {
        while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price) == 15) {

            fprintf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d | PRICE: %f\n", &shoeRecord->stockNumber, &shoeRecord->styleNumber, &shoeRecord->sizes[0], &shoeRecord->sizes[1], &shoeRecord->sizes[2], &shoeRecord->sizes[3], &shoeRecord->sizes[4], &shoeRecord->sizes[5], &shoeRecord->sizes[6], &shoeRecord->sizes[7], &shoeRecord->sizes[8], &shoeRecord->sizes[9], &shoeRecord->sizes[10], &shoeRecord->sizes[11], &shoeRecord->price);
        }

        printf("\nSuccessfully delete all records.\n");
    }

    fclose(inventory);
    fclose(tempFile);

    remove("inventory.txt");
    rename("tempFile.txt", "inventory.txt");
}

bool CheckIfExisting(int number, int choice) {
    FILE *inventory = fopen("inventory.txt", "r");

    int stockNumber, styleNumber;

    while (fscanf(inventory, "STOCK NUMBER: %d | STOCK STYLE: %d ", &stockNumber, &styleNumber) == 2) {
        if (choice == 1 && stockNumber == number) {
            fclose(inventory);
            return true;
        }
        else if (choice == 2 && styleNumber == number) {
            fclose(inventory);
            return true;
        }
        
        char c;
        while ((c = fgetc(inventory)) != '\n'){
            if (c == EOF)
                break;
        }
    }

    fclose(inventory);
    return false;
}

