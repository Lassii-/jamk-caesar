#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int argChecker(int countOfArgc, char *valueofArgv);
string cipherText(int key, string plainText);
void savetoFile(string plain, int key, string ciphered);

int main(int argc, char **argv) {
    // Estetään segfault jossei komentoriviargumenttia ole annettu
    if (argv[1] == nullptr)
    {
        cout << "Komentoriviargumentti puuttuu. Anna luku väliltä 1-26." << endl;
        return(1);
    }
    // caesar-tietue salaamattoman & salatun sanan sekä salausavaimen säilytykseen
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
/**
 * @brief Komentorivi-argumenttien tarkastusfunktio
 * @param countOfArgc Komentorivi-argumenttien määrä
 * @param valueofArgv Ensimmäisen komentorivi-argumentin arvo
 * @return Komentorivi-argumentti kokonaislukuna
 */
int argChecker(int countOfArgc, char *valueofArgv)
{
    // Muutetaan komentorivisyöte string-tyypistä kokonaisluvuksi
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
/**
 * @brief Salaa tekstin Caesar-salauksella
 * @param key Salausavain kokonaislukuna
 * @param plainText Selkokielinen sana/lause, joka halutaan salata
 * @return Palauttaa string-tyypin muuttujan, jossa salattu versio sanasta
 */
string cipherText(int key, string plainText)
{
    string ciphered;
    // Käydään salaamaton sana läpi
    for(auto c : plainText)
    {
        // Jos merkki on kirjain
        if(isalpha(c))
        {
            // Muutetaan merkki aakkos-indeksiin
            char cipher = tolower(c) - 'a';
            
            // Siirretään kirjainta aakkos-indeksillä salaus-avaimen luvun verran
            // Sekä otetaan jakojäännös luvulla 26, jotta Z-kirjaimen jälkeen pyörähdetään takaisin A-kirjaimeen
            cipher = cipher + key;
            cipher = cipher % 26;

            // Muutetaan merkki takaisin ASCII-indeksiin
            char cipherASCII = cipher + 'a';

            // Laitetaan kirjain ciphered-muuttujaan oikeankokoisena
            if(isupper(c))
            {
                ciphered.push_back(toupper(cipherASCII));
            }
            else if (islower(c))
            {
                ciphered.push_back(tolower(cipherASCII));
            }
        }
        // Jossei merkki ole aakkonen niin laitetaan se vain suoraan ciphered-muuttujaan
        else
        {
            ciphered.push_back(c);
        }
    }
    return ciphered;
}
/**
 * @brief Tallentaa salaamattoman ja salatun sanan sekä salausvaimen tekstitiedostoon formaatissa salaamaton + avain = salattu
 * @param plainText Salaamaton teksti
 * @param key Salausavain
 * @param ciphered Salattu teksti
 */
void savetoFile(string plainText, int key, string ciphered)
{
    // Luodaan outputstream-objekti outfile
	ofstream outfile;
    // Avataan sanaparit.txt-tiedosto append-tilassa, jolloin tallennettu tieto menee aina uudelle omalle rivilleen.
	outfile.open("sanaparit.txt", ios_base::app);
	
    // Kirjoitetaan tieto tiedostoon ja suljetaan tiedosto
	cout << "Kirjoitetaan sanapari tiedostoon..." << endl;
	outfile << plainText << " + " << key << " = " << ciphered << endl;
	cout << "Kirjoitus valmis." << endl;
	outfile.close();
}
