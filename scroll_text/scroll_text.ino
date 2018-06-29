#include <LiquidCrystal.h>
//Map pins to lcd
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  printString("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
}

void loop() {
 
}

/*
 * First we print the string starting from the left side, so we
 * print the 16 first characters of the string and then we 
 * later print the next 16 characters whit an offset to
 * do the scroll animation
 */
void printString(String string) {
  if (string.length() <=16) {
    lcd.clear();
    lcd.print(string);
    return;
  }

   for(int i=0; i<string.length(); i++) {
      lcd.clear();  
      lcd.print(string.substring(i, i+16));
      delay(350);
   }

   lcd.clear();
   printStringStartingFromRight(string);
}

/**
 * Print the string starting from the right side and 
 * moving the letters to reach the left side of the lcd. 
 * When we reach the left side we apply the same method 
 * to scroll the text as seen in the previous function
 */
void printStringStartingFromRight(String string) {
  /**
   * We need to go to lenght() + 16 to have a 
   * string with zero characters when we reach 
   * the end of the loop
   */
  for(int i=0; i<string.length()+16; i++) {
    lcd.clear();
    if (i<=16) {
      /*In every iteration we set the cursor in 1 less
      to move to the left*/
      lcd.setCursor(16-i, 0);
      /*
       * As we are moving to the left side, in every 
       * loop we display 1 letter more than before, 
       * but after reaching the max letters of the 
       * display (16) we have to show the substring of [0,i+1], 
       * as the i starts with value 0 and we need it to start in 1
       */
      lcd.print(string.substring(0,i+1));
    } else {
      /**
       * Redundant instruction
       */
      lcd.setCursor(0,0);
      /*
       * The same method as we have seen in printScreen()
       */
      lcd.print(string.substring(i-16, i));
    }
    delay(350);
  }

  printStringStartingFromRight(string);
}

