#include"header.h"
const int MAXLENGTH = 80;
const int MAX_TRIES = 5;
const int MAXROW = 7;

int letterFill(char, char[], char[]);
void initUnknown(char[], char[]);
int Hangman()
{

    char unknown[MAXLENGTH];
    char letter;
    int num_of_wrong_guesses = 0;
    char word[MAXLENGTH];
    char words[][MAXLENGTH] =
    { "Afghanistan",
    "Albania",
    "Algeria",
    "America",
    "Andorra",
    "Angola",
    "Antigua",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaijan",
    "Bahamas",
    "Bahrain",
    "Bangladesh",
    "Barbados",
    "Belarus",
    "Belgium",
    "Belize",
    "Benin",
    "Bhutan",
    "Bissau",
    "Bolivia",
    "Bosnia",
    "Botswana",
    "Brazil",
    "British",
    "Brunei",
    "Bulgaria",
    "Burkina",
    "Burma",
    "Burundi",
    "Cambodia",
    "Cameroon",
    "Canada",
    "CapeVerde",
    "CentralAfricanRepublic",
    "Chad",
    "Chile",
    "China",
    "Colombia",
    "Comoros",
    "Congo",
    "CostaRica",
    "Croatia",
    "Cuba",
    "Cyprus",
    "Czech",
    "Denmark",
    "Djibouti",
    "Dominica",
    "EastTimor",
    "Ecuador",
    "Egypt",
    "ElSalvador",
    "Emirates",
    "England",
    "Eritrea",
    "Estonia",
    "Ethiopia",
    "Fiji",
    "Finland",
    "France",
    "Gabon",
    "Gambia",
    "Georgia",
    "Germany",
    "Ghana",
    "GreatBritain",
    "Greece",
    "Grenada",
    "Grenadines",
    "Guatemala",
    "Guinea",
    "Guyana",
    "Haiti",
    "Herzegovina",
    "Honduras",
    "Hungary",
    "Iceland",
    "India",
    "Indonesia",
    "Iran",
    "Iraq",
    "Ireland",
    "Israel",
    "Italy",
    "IvoryCoast",
    "Jamaica",
    "Japan",
    "Jordan",
    "Kazakhstan",
    "Kenya",
    "Kiribati",
    "Korea",
    "Kosovo",
    "Kuwait",
    "Kyrgyzstan",
    "Laos",
    "Latvia",
    "Lebanon",
    "Lesotho",
    "Liberia",
    "Libya",
    "Liechtenstein",
    "Lithuania",
    "Luxembourg",
    "Macedonia",
    "Madagascar",
    "Malawi",
    "Malaysia",
    "Maldives",
    "Mali",
    "Malta",
    "Marshall",
    "Mauritania",
    "Mauritius",
    "Mexico",
    "Micronesia",
    "Moldova",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Morocco",
    "Mozambique",
    "Myanmar",
    "Namibia",
    "Nauru",
    "Nepal",
    "Netherlands",
    "NewZealand",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "Norway",
    "Oman",
    "Pakistan",
    "Palau",
    "Panama",
    "Papua",
    "Paraguay",
    "Peru",
    "Philippines",
    "Poland",
    "Portugal",
    "Qatar",
    "Romania",
    "Russia",
    "Rwanda",
    "Samoa",
    "SanMarino",
    "SaoTome",
    "SaudiArabia",
    "Scotland",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leone",
    "Singapore",
    "Slovakia",
    "Slovenia",
    "Solomon",
    "Somalia",
    "SouthAfrica",
    "SouthSudan",
    "Spain",
    "SriLanka",
    "StKitts",
    "StLucia",
    "Sudan",
    "Suriname",
    "Swaziland",
    "Sweden",
    "Switzerland",
    "Syria",
    "Taiwan",
    "Tajikistan",
    "Tanzania",
    "Thailand",
    "Tobago",
    "Togo",
    "Tonga",
    "Trinidad",
    "Tunisia",
    "Turkey",
    "Turkmenistan",
    "Tuvalu",
    "Uganda",
    "Ukraine",
    "UnitedKingdom",
    "UnitedStates",
    "Uruguay",
    "USA",
    "Uzbekistan",
    "Vanuatu",
    "Vatican",
    "Venezuela",
    "Vietnam",
    "wales",
    "Yemen",
    "Zambia",
    "Zimbabwe",
    };

    //choose and copy a word from array of words randomly
    srand(time(0));
    int xx = 203; // size of words
    int n = rand() % (xx + 1);
    strcpy(word, words[n]);
    for (int i = 0; i < strlen(word); i++) // to avoid the confusion of Capital lettered countries
        word[i] = tolower(word[i]);
    //transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Initialize the secret word with the * character.
    initUnknown(word, unknown);

    // welcome the user
    cout << "\n\nWELCOME TO HANGMAN...\nGuess a country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    // Loop until the guesses are used up
    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;
        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl << "Whoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << endl << "You found a letter! Isn't that exciting!" << endl;
        }
        // Tell user how many guesses he is left with.
        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;
        // Check if they guessed the word.
        if (strcmp(word, unknown) == 0)
        {
            cout << word << endl;
            cout << "\nOH Yeahh! You got it!...\nYOU ARE A WINNER";
            break;
        }
    }
    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        cout << "The word was : " << word << endl;
    }

    return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, char secretword[], char guessword[])
{
    int i;
    int matches = 0;
    for (i = 0; secretword[i] != '\0'; i++)
    {
        // if already match this letter in a previous guess
        if (guess == guessword[i])
                return 0;
        // if guess in the secret word
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}


// Initialize the unknown word char array

void initUnknown(char word[], char unknown[])
{
    int i;
    int length = strlen(word);
    for (i = 0; i < length; i++)
        unknown[i] = '*';
    unknown[i] = '\0';
}
