#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int argChecker(int countOfArgc, char *valueofArgv);
string caesarCipher(int key, string plainText);
void savetoFile(string plain, int key, string ciphered);

int main(int argc, char **argv) {
    if (argv[1] == nullptr)
    {
        cout << "Komentoriviargumentti puuttuu. Anna luku väliltä 1-26." << endl;
        return(1);
    }
    const int key = argChecker(argc, argv[1]);
    string plainText;
    cout << "Alkuperäinen teksti: ";
    getline (cin, plainText);
    cout << "Salattu teksti: ";
    string cipheredText = caesarCipher(key, plainText);
    cout << cipheredText;
    cout << endl;
	savetoFile(plainText, key, cipheredText);
    return(0);
}

int argChecker(int countOfArgc, char *valueofArgv)
{
    int argvToInt = atoi(valueofArgv);
    if(countOfArgc < 2)
    {
        cout << "Komentoriviargumentti puuttuu!" << endl;
        exit(1);
    }
    else if(countOfArgc > 2)
    {
        cout << "Komentoriviargumentteja on liikaa! " << "Anna ainoastaan numero väliltä 1-26." << endl;
        exit(1);
    }
    if(argvToInt <=0 || argvToInt > 26)
    {
        cout << "Anna ainoastaan numero väliltä 1-26!" << endl;
        exit(1);
    }
    return argvToInt;
}

string caesarCipher(int key, string plainText)
{
    string ciphered;
    for(auto c : plainText)
    {
        if(isalpha(c))
        {
            char cipher = tolower(c) - 'a';

            cipher = cipher + key;
            cipher = cipher % 26;

            char cipherASCII = cipher + 'a';

            if(isupper(c))
            {
                ciphered.push_back(toupper(cipherASCII));
            }
            else if (islower(c))
            {
                ciphered.push_back(tolower(cipherASCII));
            }
        }
        else
        {
            ciphered.push_back(c);
        }
    }
    return ciphered;
}

void savetoFile(string plain, int key, string ciphered)
{
	ofstream outfile;
	outfile.open("sanaparit.txt", std::ios_base::app);
	
	cout << "Kirjoitetaan sanapari tiedostoon..." << endl;
	outfile << plain << " + " << key << " = " << ciphered << endl;
	cout << "Kirjoitus valmis" << endl;
	outfile.close();
}
