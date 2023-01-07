#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAXSIZE = 9;
const int GUESSLIMIT= 100;


void generateValidNumber(int number[], int size);
int generateRandomNumber(int number[], int size, int limit);
bool checkNumberExists(int number[], int size, int target);
int countDigitInArray(int number[], int size, int target); 
int convertStringToInt(const char *str);
int findStringlenght(const char *str);
void getNumber(const char *str, int number[]);
void getUserGuessNumber(int number[], int size);
int countExact(int number1[], int number2[], int size);
int countMisplaced(int number1[], int number2[], int size);
bool isDigit(char c);
int findIndex(int number[], int size, int target);
bool checkNumberValid(int number[], int size);

int main(int argc, const char *argv[])
{
    srand(static_cast<int>(time(NULL)));

    int number[MAXSIZE];
    int userGuess[MAXSIZE];
    int arraySize;
    char selection;
    int counterExact;
    int counterMisplaced;
    int counter;
    bool found;

    if (argc != 3){
        std::cout << "E0\n";
        exit(EXIT_FAILURE);
    }

    selection = argv[1][1];
    if (selection == 'r'){
        arraySize = convertStringToInt(argv[2]);
        generateValidNumber(number, arraySize);
    } else if (selection == 'u'){
        arraySize = findStringlenght(argv[2]);
        getNumber(argv[2], number);
        if (!checkNumberValid(number, arraySize)){
            std::cout << "E0\n";
            exit(EXIT_FAILURE);
        }
    } else {
        std::cout << "E0\n";
        exit(EXIT_FAILURE);
    }

    counter = 0;
    found = false;
    while (counter < GUESSLIMIT && !found){

        //Get user guess
        getUserGuessNumber(userGuess, arraySize);

        counterExact = countExact(number, userGuess, arraySize);
        if (counterExact == arraySize){
            found = true;
        } else {
            
            counterMisplaced = countMisplaced(number, userGuess, arraySize);

            std::cout << counterExact << " "
                      << counterMisplaced << std::endl;
        }

        counter++;
    }

    if (found)
        std::cout << "FOUND" << " " << counter << std::endl;
    else
        std::cout << "FAILED" << std::endl;

    return 0;
}

//Generates a valid number.
//Stores number in parameter int array number.
//Precondition: number size has to be consistent value.
void generateValidNumber(int number[], int size)
{
    int i;
    int tmp;

    //left most digit has a special case which it can not be zero.
    do {
        tmp = generateRandomNumber(number, 0, 10);
        if (tmp != 0)
            number[0] = tmp;
    }while (tmp == 0);

    for (i = 1; i < size; i++){
        tmp = generateRandomNumber(number, i, 10);
        number[i] = tmp;
    }
}


//Generates a random number between 0 and limit (limit is excluded).
//Generated number will be a number hasn't appeared in array number
//Precondition: size of array has to be consistent. And limit has to be
//a positive integer number.
int generateRandomNumber(int number[], int size, int limit)
{
    bool numberIsValid;
    int tmp;

    do {
        tmp = rand() % limit;
        if (!checkNumberExists(number, size, tmp))
            numberIsValid = true;
        else
            numberIsValid = false;
    }while (!numberIsValid);

    return tmp;
}


//Checks that whether parameter target value exists in array number
//or not. If target exists in array number returns true. Else false.
//Precondition: size of array has to be consistent.
bool checkNumberExists(int number[], int size, int target)
{
    int i;
    bool ans = false;
    for (i = 0; i < size; i++)
        if (number[i] == target){
            ans = true;
            break;
        }

    return ans;
}


//Counts parameter target digit in paramter int array number. And returns
//the count of it. If target doesn't appear in array returns 0.
int countDigitInArray(int number[], int size, int target)
{
    int i;
    int counter = 0;

    for (i = 0; i < size; i++)
        if (number[i] == target)
            counter++;

    return counter;
}


//Converts c string to integer number and returns that number.
int convertStringToInt(const char *str)
{
    int n = 0;
    int i;

    if (str[0] == '0' || str[0] == '-'){
        //0 or Negative value entered. Print error code E0 and exit the program.
        std::cout << "E0\n";
        exit(EXIT_FAILURE);
    }

    for (i = 0; str[i] != 0; i++){
        n += str[i] - '0';
        if(str[i+1] != 0)
            n *= 10;
    }
    return n;
}


//Findst lenght of given c string and returns it.
int findStringlenght(const char *str)
{
    int i;

    for (i = 0; str[i] != 0; i++)
        ;
    return i;
}


//Fills number by using user input c string str.
void getNumber(const char *str, int number[])
{
    int i;

    if (str[0] == '0' || str[0] == '-'){
        //Entered number starts with 0 or a negative number. print
        //error code E0 and exit the program.
        std::cout << "E0\n";
        exit(EXIT_FAILURE);
    }
   

    for (i = 0; str[i] != 0; i++)
        number[i] = str[i] - '0';
}


//Gets a guess from user and store that guessed number into parameter
//int array number.
void getUserGuessNumber(int number[], int size)
{
    char c;
    int i = 0;

    std::cin.get(c);
    while (c != '\n'){
        if (!isDigit(c)){
            //nondigit number is entered. print error code E2 and exit the program.
            std::cout << "E2\n";
            exit(EXIT_FAILURE);
        } else if (i < size) {
            number[i] = c - '0';
            i++;
        } else {
            //Number exceeds the array size. return error code E1 and exit the program.
            std::cout << "E1\n";
            exit(EXIT_FAILURE);
        }
        std::cin.get(c);
    }

    if (i != size){
        //Size of entered number is less than array size. print error code E1
        //and exit the program.
        std::cout << "E1\n";
        exit(EXIT_FAILURE);
    }
}

//Counts Exact matches digits and returns that count.
int countExact(int number1[], int number2[], int size)
{
    int i;
    int counter = 0;
    for (i = 0; i < size; i++)
        if (number1[i] == number2[i])
            counter++;

    return counter;
}


//Counts Misplaced digits and returns that count.
int countMisplaced(int number1[], int number2[], int size)
{
    int i;
    int counter = 0;

    for (i = 0; i < size; i++)
        if (number1[i] != number2[i] &&
            findIndex(number2, size, number1[i]) != -1){
            //If current digits are not equal but current digit of
            //first number exists in number2 then current digit is
            //misplaced.
            counter++;
        }

    return counter;
}


//Checks whether char c is a digit or not. If c is a digit returns true.
//Else false.
bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}


//Finds and returns index of target number in array number.
//If target doesn't exist in array returns -1
int findIndex(int number[], int size, int target)
{
    int i;

    for (i = 0; i < size; i++)
        if (number[i] == target)
            return i;

    return -1;
}


//Check whether number is a valid number or not.
//If number is a valid number returns true. Else false.
bool checkNumberValid(int number[], int size)
{
    int i;
    bool ans = true;
    for (i = 0; i < size; i++){
        if (countDigitInArray(number, size, number[i]) != 1){
            ans = false;
            break;
        }
    }

    return ans;
}
