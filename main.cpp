#include <iostream>
#include <vector> 
#include <string> 
#include "ufo_functions.hpp"

int main() {
  greet(); 
  std::string codeword = "Rainbow", answer = "_______"; 

  int misses = 0; 

  std::vector<char> incorrect; 
  bool guess = false; 
  char letter; 
  do 
  {
    display_misses(misses); 
    display_status(incorrect, answer); 
    std::cout << "\n\nPlease enter your guess: "; 
    std::cin >> letter; 
    for(int i = 0; i < codeword.length(); ++i)
    {
      if(letter == codeword[i])
      {
         answer[i] = letter;
         guess = true; 
      }
    }
     if(guess)
      std::cout << "\nCorrect! your getting close!" << std::endl; 
      else 
      {
        std::cout << "\nIncorrect! The tractor beam pulls the person in further." << std::endl; 
        incorrect.push_back(letter); 
        misses++; 
      }
      guess = false; 
  }while(answer != codeword && misses < 7); 
  
  end_game(answer, codeword); 
}