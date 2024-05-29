#include "gestion_reservations.h"
#include <iostream>
#include <algorithm>
using namespace std;

const int NB_CHAMBRES = 10;
vector<vector<string>> chambres(NB_CHAMBRES, vector<string>(4));

void initialiserChambres() {
    for (int i = 0; i < NB_CHAMBRES; ++i) {
        chambres[i][0] = to_string(101 + i); // Numéro de chambre
        chambres[i][1] = ""; // Nom
        chambres[i][2] = ""; // Prénom
        chambres[i][3] = "non"; // Réservation
    }
}

bool creerReservation() {
    string chambre, nom, prenom;
    cout << "Entrez le numero de chambre : ";
    cin >> chambre;

    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == chambre) {
            if (chambres[i][3] == "non") {
                cout << "Entrez le nom : ";
                cin >> nom;
                cout << "Entrez le prenom : ";
                cin >> prenom;
                chambres[i][1] = nom;
                chambres[i][2] = prenom;
                chambres[i][3] = "oui";
                cout << "Reservation creee avec succes.\n";
                return true;
            }
            else {
                cout << "La chambre " << chambre << " est deja reservee.\n";
                return false;
            }
        }
    }
    cout << "La chambre n'existe pas.\n";
    return false;
}

void annulerReservation() {
    string chambre;
    cout << "Entrez le numero de chambre : ";
    cin >> chambre;

    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == chambre) {
            chambres[i][1] = "";
            chambres[i][2] = "";
            chambres[i][3] = "non";
            cout << "Reservation annulee avec succes.\n";
            return;
        }
    }
    cout << "Aucune reservation trouvee pour cette chambre.\n";
}

void modifierReservation() {
    string chambre, nom, prenom;
    cout << "Entrez le numero de chambre : ";
    cin >> chambre;

    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == chambre) {
            cout << "Entrez le nouveau nom : ";
            cin >> nom;
            cout << "Entrez le nouveau prenom : ";
            cin >> prenom;
            chambres[i][1] = nom;
            chambres[i][2] = prenom;
            cout << "Reservation modifiee .\n";
            return;
        }
    }
    cout << "Aucune reservation trouvee pour cette chambre.\n";
}

void modifierReservationChambre() {
    string chambreSource, chambreDestination;
    cout << "Entrez le numero de chambre source : ";
    cin >> chambreSource;
    cout << "Entrez le numero de chambre destination : ";
    cin >> chambreDestination;

    vector<string> temp(4);
    bool trouveSource = false, trouveDestination = false;
    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == chambreSource) {
            temp = chambres[i];
            trouveSource = true;
        }
        if (chambres[i][0] == chambreDestination) {
            chambres[i] = temp;
            trouveDestination = true;
        }
    }

    if (trouveSource && trouveDestination) {
        cout << "Reservation de la chambre " << chambreSource << " deplacee vers la chambre " << chambreDestination << ".\n";
    }
    else {
        cout << "Chambres non trouvees.\n";
    }
}

void afficherReservations() {
    cout << "Liste des reservations :\n";
    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][3] == "oui") {
            cout << "Chambre " << chambres[i][0] << " : " << chambres[i][1] << " " << chambres[i][2] << endl;
        }
    }
}

void trouverReservation() {
    string recherche;
    cout << "Entrez le nom, le prenom ou le numero de chambre : ";
    cin >> recherche;

    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == recherche || chambres[i][1] == recherche || chambres[i][2] == recherche) {
            cout << "Reservation trouvee :\n";
            cout << "Chambre " << chambres[i][0] << " : " << chambres[i][1] << " " << chambres[i][2] << endl;
            return;
        }
    }
    cout << "Aucune reservation trouvee.\n";
}

void echangerReservations() {
    string chambre1, chambre2;
    cout << "Entrez le numero de la premiere chambre : ";
    cin >> chambre1;
    cout << "Entrez le numero de la deuxieme chambre : ";
    cin >> chambre2;

    vector<string> temp(4);
    bool trouve1 = false, trouve2 = false;
    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][0] == chambre1) {
            temp = chambres[i];
            trouve1 = true;
        }
        if (chambres[i][0] == chambre2) {
            chambres[i] = temp;
            trouve2 = true;
        }
    }

    if (trouve1 && trouve2) {
        cout << "Reservations echangees avec succes.\n";
    }
    else {
        cout << "Chambres non trouvees.\n";
    }
}

void trierReservations() {
    int critere;
    cout << "Trier par :\n"
        "1. Reservations\n"
        "2. Nom\n"
        "3. Prenom\n";
    cin >> critere;

    switch (critere) {
    case 1:
        sort(chambres.begin(), chambres.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[3] < b[3];
            });
        break;
    case 2:
        sort(chambres.begin(), chambres.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[1] < b[1];
            });
        break;
    case 3:
        sort(chambres.begin(), chambres.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[2] < b[2];
            });
        break;
    default:
        cout << "Choix invalide.\n";
        return;
    }
    cout << "Tableau trie avec succes.\n";
}

void statistiquesReservations() {
    int chambre = 0;
    for (int i = 0; i < NB_CHAMBRES; ++i) {
        if (chambres[i][3] == "oui") {
            chambre++;
        }
    }
    float po = (static_cast<float>(chambre) / NB_CHAMBRES) * 100.0;
    cout << "Pourcentage de chambres occupees : " << po << "%\n";
}
