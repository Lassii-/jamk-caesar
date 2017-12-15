#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct caesar {
    unsigned int key;
    string text;
} salaus, plain, ciphered;

// Prototyypataan funktiot
int argChecker(int& countOfArgc, char *valueofArgv);
string cipherText(unsigned int& key, string& plainText);
void savetoFile(string& plain, unsigned int& key, string& ciphered, char& saveFlag);

int main(int argc, char **argv) {
    // Estetään segfault jossei komentoriviargumenttia ole annettu
    char saveFlag;
    if (argv[1] == nullptr)
    {
        cout << "Komentoriviargumentti puuttuu. Anna luku väliltä 1-26." << endl;
        return(1);
    }
    if (argv[2] == nullptr)
    {
        saveFlag = 'N';
    }
    else
    {
        saveFlag = *argv[2];
    }
    cout << saveFlag;
    // caesar-tietue salaamattoman & salatun sanan sekä salausavaimen säilytykseen
    salaus.key = argChecker(argc, argv[1]);
    cout << "Alkuperäinen teksti: ";
    getline (cin, plain.text);
    cout << "Salattu teksti: ";
    ciphered.text = cipherText(salaus.key, plain.text);
    cout << ciphered.text;
    cout << endl;
	savetoFile(plain.text, salaus.key, ciphered.text, saveFlag);
    return(0);
}
/**
 * @brief Komentorivi-argumenttien tarkastusfunktio
 * @param countOfArgc Komentorivi-argumenttien määrä
 * @param valueofArgv Ensimmäisen komentorivi-argumentin arvo
 * @return Komentorivi-argumentti kokonaislukuna
 */
int argChecker(int& countOfArgc, char *valueofArgv)
{
    // Muutetaan komentorivisyöte string-tyypistä kokonaisluvuksi
    unsigned int argvToInt = atoi(valueofArgv);
    if(countOfArgc < 2)
    {
        cout << "Komentoriviargumentti puuttuu!" << endl;
        exit(1);
    }
    else if(countOfArgc > 3)
    {
        cout << "Komentoriviargumentteja on liikaa! " << "Anna ainoastaan numero väliltä 1-26." << endl;
        exit(1);
    }
    if(argvToInt == 0 || argvToInt > 26)
    {
        cout << "Anna ainoastaan numero väliltä 1-26!" << endl;
        exit(1);
    }
    return argvToInt;
}
/**
 * @brief Salaa tekstin Caesar-salauksella
 * @param key Salausavain kokonaislukuna
 * @param plainText Selkokielinen sana/lause, joka halutaan salata
 * @return Palauttaa string-tyypin muuttujan, jossa salattu versio sanasta
 */
string cipherText(unsigned int& key, string& plainText)
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
void savetoFile(string& plainText, unsigned int& key, string& ciphered, char& saveFlag)
{
    if(saveFlag == 'Y')
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
}
