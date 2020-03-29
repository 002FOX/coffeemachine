//Name: Sami ELARIF      Date: 29/03/2020
// This is the coffee vending machine main file
#include <stdio.h>
#include "header.h"
  

int main() {

     int choice, x, y, total_entry= 0, water, sl_choice, feedback = 0;

     initialize();

    do { 
                 printf("******** New customer ******** \n");
        choice = get_order();
        x = check_order(choice);


        if(x){
      printf("Enter 1 if you wish to continue.\n");
      scanf("%d", &feedback);

              if(feedback==1){
                 do {
                 sl_choice = get_sugarlevel();
                 y = check_sugar(sl_choice);
                 }while(y==0);
                 printf("Enter 1 if you wish to continue.\n");
                 scanf("%d", &feedback);
                  if(feedback==1){
                     total_entry = get_money(choice);
                     water = deliver_order(choice);
                     deliver_change(choice, total_entry);
                    }
              }

                
      }         
         else
        printf("Sorry we ran out of ingredients.\n");
    
    
    
    }while(water>=1);

 return 0;

}
