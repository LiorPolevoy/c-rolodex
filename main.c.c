#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Card;

int count = 0;

Card *cards = NULL;

void add(Card card) {
    
    for (int i = 0; i < count; i++) {
        if (cards[i].id == card.id) {
            printf ("ID Already Taken\n\n");
            return;
        }
    } 

    Card *temp = realloc(cards, (count + 1) * sizeof(Card));
    
    if (temp == NULL) {
        printf("Could Not Reallocate Memory!\n");
    }
    else { 
        cards = temp;

        cards[count] = card;    
    
        printf("%s Added Successfully\n", card.name);
    
        count ++;
    }
}



void delete_card(char name[50]) {

    for (int i = 0; i < count; i++) {
        if (strcmp(cards[i].name, name) == 0) {
            for(int j = i; j < count - 1; j++) {
                cards[j] = cards[j+1]; 
            }       
        
            printf("%s Deleted Successfully\n", name);     
            count --;
            return;
        }
        else {
            continue;
        } 
    } printf("Can't Find Contact.\n");
}   


void search(int id) {

    if(count == 0) {
        printf("No Contacts found.\n");
    }
    else {
        for(int i = 0; i < count; i++) {
            if(cards[i].id == id) {
                printf("Name: %s | Age: %d\n", cards[i].name, cards[i].age);
                return;
            }
            else {
                continue;
            }
        }
        printf("Can't Find Contact.\n");
    }
}



void print_all() {
    
    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d\n", cards[i].id, cards[i].name, cards[i].age);
    }

}


int main(){

    int choice = -1;

    while(choice != 5) { 
        
        choice = -1; 

        printf("1. Add Card\n2. Search Card\n3. Delete Card\n4. Print All Cards\n5. Exit\n");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  
            printf("Invalid input! Please enter a number.\n\n");
            continue;
        }        
        if (choice == 1) {
            Card card;
            
            printf("Enter ID number:\n");
            while (scanf("%d", &card.id) != 1) {
                while (getchar() != '\n');  
                printf("Invalid input! Please enter a number.\n\n");
            }
            while (getchar() != '\n');


            printf("Enter Full Name:\n");
            scanf(" %49[^\n]", card.name);

            
            printf("Enter Age:\n");
            while (scanf("%d", &card.age) != 1) {
                while (getchar() != '\n');  
                printf("Invalid input! Please enter a number.\n\n");    
            }
            while (getchar() != '\n');

            add(card);

        }
        
        else if (choice == 2) {
            int target_id;

            printf("Please Enter ID:\n");
            scanf("%d", &target_id);

            search(target_id);
        }
        
        else if (choice == 3) {
            char name[50];
        
            if (count == 0){
            printf("No Contacts Yet.\n");
            }

            else {    
                printf("Enter Full Name:\n");    
                scanf(" %[^\n]", name);
            
                delete_card(name);    
            }  
        }
        else if (choice == 4) {
            print_all();
        }
        
        else if (choice > 5) {
            printf("No Option\n");
        }
    }

    free(cards);
    printf("Goodbye!\n");
    return 0;
}