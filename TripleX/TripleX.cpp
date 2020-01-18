#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    //Printing the mission statment of the game 
    std::cout << "\n\nHello rookie, are you ready to defuse these bombs!\n";
    std::cout << "The last one did not make it very long.....\n";
    std::cout << "But all you have to do is put in the right code, easy as pie right?\n";
    std::cout << "Oh and dont forget to put a space between your numbers\n\n";
}

void BombLevel(int Difficulty){
    //Print the current bomb level
    std::cout << "\nThe bomb level is: " << Difficulty << std::endl;
}

bool PlayGame(int Difficulty)
{
   BombLevel(Difficulty);

    //Declaring our game numbers  
    const int CodeA = (rand() % Difficulty) + Difficulty;
    const int CodeB = (rand() % Difficulty) + Difficulty;
    const int CodeC = (rand() % Difficulty) + Difficulty;
    
    //Declaring our game hints 
    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    //Printing out our game hints to the command line 
    std::cout <<"+ There are 3 number in the code ";
    std::cout <<"\n+ The codes add up to: " << CodeSum;
    std::cout <<"\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    //Add and multply the players guess 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB *GuessC;
    
    //Check to see if the player guess is right 
    if (CodeSum == GuessSum && CodeProduct ==GuessProduct)
    {
        std::cout <<"\n** Wow you actually did it **";
        return true;
    }
    else
    {
        std::cout <<"\n** Welp we need to find a replacement for him now **";
        std::cout <<"\n** Guess he should have known the code was "<< CodeA <<" "<< CodeB <<" " << CodeC <<" **\n\n";
        return false;
    }
}

int main()
{ 
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int  MaxDifficulty = 10;
     PrintIntroduction();

    while (LevelDifficulty <= MaxDifficulty)//Loop game until all level completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
         std::cin.clear();//Clears any errors
         std::cin.ignore();//Discards the buffer

         if (bLevelComplete)
         {
             ++LevelDifficulty;
         }
         
    }
    
    std::cout <<"\n\n** Well I guess are no longer a rookie welcome to the team! **";
    return 0;
}