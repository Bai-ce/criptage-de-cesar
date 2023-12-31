#include <iostream>
#include <cctype> // Pour utiliser les fonctions isalpha et isupper
using namespace std;
string chiffrementCesar(const string& message, int decalage) {
    string resultat = "";

    for (char caractere : message) {
        if (isalpha(caractere)) {
            // Vérifier si le caractère est une lettre
            char base = (isupper(caractere)) ? 'A' : 'a';
            // Appliquer le décalage en prenant en compte la casse
            char lettre_chiffree = (caractere - base + decalage) % 26 + base;
            resultat += lettre_chiffree;
        } else {
            // Si ce n'est pas une lettre, ajouter le caractère tel quel
            resultat +="";
        }
    }

    return resultat;
}
string dechiffrementCesar(const string& messageChiffre, int decalage) {
    return chiffrementCesar(messageChiffre, -decalage);
}
int main() {
    string message, message_chiffre,message_dechiffre;
    int decalage;

    // Demander à l'utilisateur d'entrer le message
    cout << "Entrez le message à chiffrer : ";
    cin>>message;
    // Demander à l'utilisateur d'entrer le décalage
    cout << "Entrez le décalage (entier) : ";
    cin >> decalage;
    cout<<" choisir 1 pour chiffrer, 2 pour dechiffrer"<<endl;
    // Chiffrer le message
     message_chiffre = chiffrementCesar(message, decalage);

    // Afficher le message chiffré
    cout << "Message chiffré : " << message_chiffre <<endl;

    message_dechiffre = dechiffrementCesar(message_chiffre,decalage);
        cout << "Message dechiffré : " << message_dechiffre <<endl;
    return 0;

}
