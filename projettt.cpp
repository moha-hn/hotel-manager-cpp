#include <iostream>
#include "gestion_reservations.h"
#include <algorithm>

using namespace std;

int main() {
    initialiserChambres();
    int choix;

    do {
        cout << "             Bienvenue dans notre hotel:\n";
        cout << "--------------------------------------------------\n";
        cout << "1. Creer une reservation\n";
        cout << "--------------------------------------------------\n";
        cout << "2. Annuler la reservation\n";
        cout << "--------------------------------------------------\n";
        cout << "3. Modifier une reservation\n";
        cout << "--------------------------------------------------\n";
        cout << "4. Modifier la reservation de la chambre\n";
        cout << "--------------------------------------------------\n";
        cout << "5. Montrer la liste de reservations\n";
        cout << "--------------------------------------------------\n";
        cout << "6. Trouver une reservation\n";
        cout << "--------------------------------------------------\n";
        cout << "7. Echanger les reservations entre les chambres\n";
        cout << "--------------------------------------------------\n";
        cout << "8. Trier le tableau\n";
        cout << "--------------------------------------------------\n";
        cout << "9. Statistique de reservation\n";
        cout << "--------------------------------------------------\n";
        cout << "0. Quitter le menu\n";
        cout << "--------------------------------------------------\n";
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            creerReservation();
            break;
        case 2:
            annulerReservation();
            break;
        case 3:
            modifierReservation();
            break;
        case 4:
            modifierReservationChambre();
            break;
        case 5:
            afficherReservations();
            break;
        case 6:
            trouverReservation();
            break;
        case 7:
            echangerReservations();
            break;
        case 8:
            trierReservations();
            break;
        case 9:
            statistiquesReservations();
            break;
        case 0:
            cout << "Merci pour votre visite on espere vous revoir bientot!\n";
            break;
        default:
            cout << "Veuiller entrer un nombre entre 0-9.\n";
        }
    } while (choix != 0);

    return 0;
}
