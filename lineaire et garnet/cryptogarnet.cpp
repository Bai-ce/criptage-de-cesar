#include <iostream>
#include <cctype>
#include <string>
#include <istream>
using namespace std;
// Fonction pour le chiffrement de Wolseley
string chiffrementWolseley(const string& message, const string& cle) {
    string messageChiffre = "";
    int cleIndex = 0;

    for (char caractere : message) {
        if (isalpha(caractere)) {
            char base = (isupper(caractere)) ? 'A' : 'a';
            int decalage = cle[cleIndex] - 'A';
            char caractereChiffre = (caractere - base + decalage + 26) % 26 + base;
            messageChiffre += caractereChiffre;

            // Avancer à la prochaine lettre de la clé (cycler si nécessaire)
            cleIndex = (cleIndex + 1) % cle.length();
        } else {
            messageChiffre += caractere;
        }
    }

    return messageChiffre;
}

// Fonction pour le déchiffrement de Wolseley
string dechiffrementWolseley(const string& messageChiffre, const string& cle) {
    string messageDechiffre = "";
    int cleIndex = 0;

    for (char caractere : messageChiffre) {
        if (isalpha(caractere)) {
            char base = (isupper(caractere)) ? 'A' : 'a';
            int decalage = cle[cleIndex] - 'A';
            char caractereDechiffre = (caractere - base - decalage + 26) % 26 + base;
            messageDechiffre += caractereDechiffre;

            // Avancer à la prochaine lettre de la clé (cycler si nécessaire)
            cleIndex = (cleIndex + 1) % cle.length();
        } else {
            messageDechiffre += caractere;
        }
    }

    return messageDechiffre;
}

int main() {
    string cle;
    string message;
    // Demander à l'utilisateur le message à chiffrer
    cout << "Entrez le message à chiffrer : ";
    cin>> message;

    // Demander à l'utilisateur la clé
    cout << "Entrez la clé : ";
    cin >> cle;

    // Ignorer les caractères supplémentaires dans la ligne d'entrée
    std::cin.ignore(std::numeric_limits<std::size>::max(), '\n');
    // Chiffrer le message
    string messageChiffre = chiffrementWolseley(message, cle);
    cout << "Message chiffré : " << messageChiffre << endl;

    // Déchiffrer le message
    string messageDechiffre = dechiffrementWolseley(messageChiffre, cle);
    cout << "Message déchiffré : " << messageDechiffre << endl;

    return 0;
}
