# jamk-caesar
Caesar-salaustyökalu JAMK:n Ohjelmoinnin Perusteet-opintojaksolle.
## Kuvaus
Salaa tekstiä [Caesarin salakirjoituksella](https://fi.wikipedia.org/wiki/Caesarin_salakirjoitus) ja tallentaa sanaparit ja avaimen tekstitiedostoon.
## Käyttö
Ohjelma on suunniteltu käytettäväksi komentoriviltä. Komentorivisyötteenä tulee antaa numero väliltä 1-26, joka toimii salausavaimena. Ohjelman käynnistyttyä syötetään teksti, joka halutaan salataan.
~~~~
./caesarwin.exe 16
Alkuperäinen teksti: Laitumella seisoo hevonen.
Salattu teksti: Bqyjkcubbq iuyiee xuledud.
Kirjoitetaan sanapari tiedostoon...
Kirjoitus valmis.
~~~~
## TODO
* Mahdollisuus olla tallentamatta salauspareja tekstitiedostoon.
* Koodin kommentointi.
* Virheenkäsittely tiedostonkäsittelyyn (Jos ei oikeuksia kansioon jne.).
