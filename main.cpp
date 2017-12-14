#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int argChecker(int countOfArgc, char *valueofArgv);
string cipherText(int key, string plainText);
void savetoFile(string plain, int key, string ciphered);

int main(int argc, char **argv) {
    if (argv[1] == nullptr)
    {
        cout << "Komentoriviargumentti puuttuu. Anna luku väliltä 1-26." << endl;
        return(1);
    }
    struct caesar {
        int key;
        string text;
    } cliInput, plain, ciphered;
    
    cliInput.key = argChecker(argc, argv[1]);
    cout << "Alkuperäinen teksti: ";
    getline (cin, plain.text);
    cout << "Salattu teksti: ";
    ciphered.text = cipherText(cliInput.key, plain.text);
    cout << ciphered.text;
    cout << endl;
	savetoFile(plain.text, cliInput.key, ciphered.text);
    return(0);
}

int argChecker(int countOfArgc, char *valueofArgv)
{
    int argvToInt = atoi(valueofArgv);
    if(countOfArgc < 2)
    {
        cout << "Komentoriviargumentti puuttuu!" << endl;
        return(1);
    }
    else if(countOfArgc > 2)
    {
        cout << "Komentoriviargumentteja on liikaa! " << "Anna ainoastaan numero väliltä 1-26." << endl;
        return(1);
    }
    if(argvToInt <=0 || argvToInt > 26)
    {
        cout << "Anna ainoastaan numero väliltä 1-26!" << endl;
        return(1);
    }
    return argvToInt;
}

string cipherText(int key, string plainText)
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
	outfile.open("sanaparit.txt", ios_base::app);
	
	cout << "Kirjoitetaan sanapari tiedostoon..." << endl;
	outfile << plain << " + " << key << " = " << ciphered << endl;
	cout << "Kirjoitus valmis." << endl;
	outfile.close();
}
