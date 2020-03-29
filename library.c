//Name: Sami ELARIF      Date: 29/03/2020
// This is the coffee vending machine library file with all the function implementations.


#include <stdio.h>
#define HOTCOCOA_PRICE 5
#define TEA_PRICE 3
#define ESPRESSO_PRICE 4
#define HOTCOCOAWATER 4
#define TEAWATER 4
#define ESPRESSOWATER 1
#define COCOMIXNEEDED 1
#define TEANEEDED 1
#define COFFEENEEDED 1

int water, coffee_beans, tea, coco_mix, choice, success, total_entry= 0, price, sugar, sugar_lvl, sl_choice, coins1, coins2, coins5,
coins10;


#include <stdio.h>







void initialize() {

    water = 100;
    coffee_beans = 100;
    tea = 100;
    coco_mix = 100;
    sugar = 100;
    coins1 = 100;
    coins2 = 100;
    coins5 = 100;
    coins10 = 100;
}




int get_order() {
    
    int success = 1;

    if(water >= HOTCOCOAWATER && coco_mix >= COCOMIXNEEDED)
    printf(" 1. Hot cocoa\n Price: %d Dh\n", HOTCOCOA_PRICE);
    if(water >= ESPRESSOWATER && coffee_beans >= COFFEENEEDED)
    printf(" 2. Espresso\n Price: %d Dh\n", ESPRESSO_PRICE);
    if(water >= TEAWATER && tea >= TEANEEDED)
    printf(" 3. Tea\n Price: %d Dh\n", TEA_PRICE);

    printf("Please enter the index of the product you'd like to buy:\n");
do {
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("You have chosen Hot cocoa.\n");
        success = 1;
        break;
      case 2:
        printf("You have chosen Espresso.\n");
        success = 1;
        break;
      case 3:
        printf("You have chosen Tea.\n");
        success = 1;
        break;
      default:
        printf("You have chosen the wrong product, please try again.\n");
        success = 0;
        break;
    }
 }while(success==0);

  return (choice);

} 



int get_sugarlevel() {
    
    int success = 1;

    
    printf(" 0. No sugar\n");
    if(sugar >=1)
    printf(" 1. Low sugar\n");
    if(sugar >=2)
    printf(" 2. Medium sugar\n");
    if(sugar >=3)
    printf(" 3. High sugar\n");

    printf("Please enter the level of sugar you'd like with your drink:\n");
do {
    scanf("%d", &sl_choice);

    switch(sl_choice){
      case 0:
        printf("You have chosen no sugar.\n");
        success = 1;
        break;
      case 1:
        printf("You have chosen low sugar level.\n");
        success = 1;
        break;
      case 2:
        printf("You have chosen medium sugar level.\n");
        success = 1;
        break;
      case 3:
        printf("You have chosen high sugar level.\n");
        success = 1;
        break;
      default:
        printf("You have chosen the wrong option, please try again.\n");
        success = 0;
        break;
    }
 }while(success==0);

 return (sl_choice);

 }






int check_order(int choice){

  switch (choice) {
    case 1:
     if(water >= HOTCOCOAWATER && coco_mix >= COCOMIXNEEDED){
       success = 1;
     }
     else
     success = 0;
    break;
    case 2:
     if(water >= ESPRESSOWATER && coffee_beans >= COFFEENEEDED){
       success = 1;
     }
     else
     success = 0;
    break;
    case 3:
     if(water >= TEAWATER && tea >= TEANEEDED){
       success = 1;
     }
     else
     success = 0;
    }

     return (success);
}



int check_sugar(int sl_choice){

  switch (sl_choice) {
    case 0:
    success = 1;
    case 1:
     if(sugar >= 1){
       success = 1;
     }
     else
     success = 0;
    break;
    case 2:
     if(sugar >= 2){
       success = 1;
     }
     else
     success = 0;
    break;
    case 3:
     if(sugar >= 3){
       success = 1;
     }
     else
     success = 0;
    }

     return (success);
}





int get_money(int choice) {

   int user_entry = 0;
   total_entry = 0;

    switch (choice) {
      case 1: 
        price = HOTCOCOA_PRICE;
      break;
      case 2:
        price = ESPRESSO_PRICE;
      break;
      case 3:
        price = TEA_PRICE;
      break;
    }
do {
    printf("Please enter %d DH in 1, 2, 5, or 10dhs coins.\n", price);
    scanf("%d", &user_entry);

    if(user_entry==1 || user_entry==2 || user_entry==5 || user_entry==10) {
    total_entry += user_entry;
    switch (user_entry) {
      case 1:
      coins1 ++;
      break;
      case 2:
      coins2 ++;
      break;
      case 5:
      coins5 ++;
      case 10:
      coins10 ++;
      break;
    }
    }
    else
     printf("Error. You have entered an unavailable coin. Please try again.\n");
}while(total_entry<price);

  
  return (total_entry);

}






int deliver_order(int choice) {

    switch (choice) { 
      case 1:
        printf("Here is your ordered Hot cocoa.\n");
        coco_mix -= COCOMIXNEEDED;
        water -= HOTCOCOAWATER;
      break;
      case 2:
        printf("Here is your ordered Espresso.\n");
        coffee_beans -= COFFEENEEDED;
        water -= ESPRESSOWATER;
      break;
      case 3:
        printf("Here is your ordered Tea.\n");
        tea -= TEANEEDED;
        water -= TEAWATER;
      break;

    } 

    switch (sl_choice) { 
      case 1:
        sugar -= 1;
      break;
      case 2:
        sugar -= 2;
      break;
      case 3:
        sugar -= 3;
      break;

    } 
  return (water);
}





void deliver_change(int choice, int total_entry) {

    int change = 0, x1 = 0, x2 = 0, x3 = 0;

    if(total_entry==price){
       change = 0;
       printf("Your change is 0 Dhs.\n");
    }
    else
    {
      change = total_entry - price;
      x1 = (change - (change % 10))/10;
      change = change % 10;
      x2 = (change - (change % 5))/5;
      change = change % 5;
      x3 = (change - (change % 2))/2;
      change = change % 2;

      coins10 -= x1;
      coins5 -= x2;
      coins2 -= x3;
      coins1 -= change;
      
     
      printf("Your change is %d 10 Dhs, %d 5 Dhs, %d 2 Dhs, and %d 1 Dhs.\n", x1, x2, x3, change);
     }
   
}
