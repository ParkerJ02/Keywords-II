/*
Parker Haynie
7/22/2022
Keywords II - Building the Code Breaker Training Simulation Program for CIA Recruits
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
// Display Title of the program to the user
    cout << "                <-[ Code Breaker Training Simulation Program ]->" << endl;
// Ask the recruit to log in using their name
    cout << "\nPlease enter your name below before proceeding with the simulation." << endl;
// Hold the recruit's name in a var, and address them by it throughout the simulation.
    string playerName;
    cin >> playerName;
// Display an overview of what Keywords II is to the recruit 
    cout << "\nHello " << playerName << " and welcome to the official Code Breaker Training Simulation Program." << endl;
    cout << "In this simulation you will try your best to decode 3 words that have been scrambled." << endl;
    cout << "If you are able to decode the 3 keywords then you have succeeded in becoming a code" << endl;
    cout << "breaker." << endl;
// Display directions to the recruit on how to use Keywords
    cout << "\nIn order to decode these keywords you have to guess one letter at a time for each" << endl;
    cout << "word but you will only be given 24 chances total. If you use up all 24 chances" << endl;
    cout << "without decoding the words you fail. You can restart the program again to give" << endl;
    cout << "another go at decoding the 3 keywords but you will most likely not get the same" << endl;
    cout << "three words to decode. Lets see if you have what it takes to be a code breaker." << endl;
// Create a collection of 10 words you had written down manually
    vector<string> words; //collection of possible words to guess
    words.push_back("OPERATIVE");
    words.push_back("AGENT");
    words.push_back("UNDERCOVER");
    words.push_back("CONFIDENTIAL");
    words.push_back("SECURITY");
    words.push_back("ESPIONAGE");
    words.push_back("INFILTRATE");
    words.push_back("STEALTHY");
    words.push_back("GUARDED");
    words.push_back("ENCRYPTED");
// Create an int var to count the number of simulations being run starting at 1
    int simulationsRan = 1;
// Display the simulation # is starting to the recruit. 
    cout << "\nNumber of simulations ran during this session: " << simulationsRan;
// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string WORD_ONE = words[0]; //word to guess
    const string WORD_TWO = words[1];
    const string WORD_THREE = words[2];
// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
    const int MAX_WRONG = 8;
    int wrong = 0;
    string soFar(WORD_ONE.size(), '-'); //word guessed so far
    string used = ""; //letters already guessed

    while ((wrong < MAX_WRONG) && (soFar != WORD_ONE))
    {
        //     Tell recruit how many incorrect guesses he or she has left
        cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
        //     Show recruit the letters he or she has guessed
        cout << "\nYou used the following letters:\n" << used << endl;
        //     Show player how much of the secret word he or she has guessed
        cout << "\nSo far, the word is:\n" << soFar << endl;
        //     Get recruit's next guess
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); //make uppercase since secret word in uppercase
        //     While recruit has entered a letter that he or she has already guessed
        while (used.find(guess) != string::npos)
        {
            //          Get recruit ’s guess
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            //     Add the new guess to the group of used letters
            guess = toupper(guess);
        }

        used += guess;

        //     If the guess is in the secret word
        if (WORD_ONE.find(guess) != string::npos)
        {
            //          Tell the recruit the guess is correct
            cout << "That's right! " << guess << " is in the word.\n";
            //          Update the word guessed so far with the new letter
            for (int i = 0; i < WORD_ONE.length(); ++i)
            {
                if (WORD_ONE[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
//     Otherwise
        else
        {
//          Tell the recruit the guess is incorrect
            cout << "Sorry, " << guess << " isn't in the word.\n";
//          Increment the number of incorrect guesses the recruit has made
            ++wrong;
        }
    }
// If the recruit has made too many incorrect guesses
    if (wrong == MAX_WRONG)
    {
//     Tell the recruit that he or she has failed the Keywords II course.
        cout << "\nYou failed to guess the word correctly!";
    }
// Otherwise
    else
    {
        //     Congratulate the recruit on guessing the secret words
        cout << "\nYou guessed it!";
        cout << "\nThe word was " << WORD_ONE << endl;
    }
    
    return 0;
}
// Ask the recruit if they would like to run the simulation again

// If the recruit wants to run the simulation again

//     Increment the number of simulations ran counter

//     Move program execution back up to // Display the simulation # is starting to the recruit. 

// Otherwise 

//     Display End of Simulations to the recruit

//     Pause the Simulation with press any key to continue
