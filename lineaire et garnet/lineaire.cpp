
#include <iostream>
#include <string>
using namespace std;
// Fonction pour le cryptage linéaire
string cryptageLineaire(const string& message, int a, int b) {
string messageCrypte = "";

    for (char caractere : message) {
        if (isalpha(caractere)) {
            // Appliquer l'équation linéaire pour chaque lettre
            char base = (isupper(caractere)) ? 'A' : 'a';
            char caractereCrypte = (a * (caractere - base) + b) % 26 + base;
            messageCrypte += caractereCrypte;
        } else {
            // Si ce n'est pas une lettre, ajouter le caractère tel quel
            messageCrypte += caractere;
        }
    }

    return messageCrypte;
}
// Fonction pour le déchiffrement linéaire
string dechiffrementLineaire(const string& messageChiffre, int a, int b) {
    // Trouver l'inverse modulaire de 'a' (modulo 26)
    int aInverse = 1;
    while ((a * aInverse) % 26 != 1) {
        aInverse++;
    }

    string messageDechiffre = "";

    for (char caractere : messageChiffre) {
        if (isalpha(caractere)) {
            char base = (isupper(caractere)) ? 'A' : 'a';
            char caractereDechiffre = (aInverse * (caractere - base - b + 26)) % 26 + base;
            messageDechiffre += caractereDechiffre;
        } else {
            messageDechiffre += caractere;
        }
    }

    return messageDechiffre;
}

int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Définir les paramètres de l'équation linéaire
    int a,b,resultatPGCD; // Terme constant
    // Demander à l'utilisateur d'entrer le message
    string message;
    cout << "Entrez le message à crypter : ";
    getline(cin, message);

    do {
    cout << "Entrez le nombre a premier avec 26 "<<endl;
    cin >>a;
    cout << "Entrez le nombre b de la cle"<<endl;
    cin>>b;
    resultatPGCD = pgcd(a, 26);
    }while(resultatPGCD != 1);

    // Crypter le message
    string messageCrypte = cryptageLineaire(message, a, b);

    // Afficher le message crypté
    cout << "Message crypté : " << messageCrypte << endl;
    // Déchiffrer le message
    string messageDechiffre = dechiffrementLineaire(messageCrypte, a, b);
    cout << "Message déchiffré : " << messageDechiffre<< endl;

    return 0;
}
