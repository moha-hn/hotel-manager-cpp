#ifndef GESTION_RESERVATIONS_H
#define GESTION_RESERVATIONS_H

#include <string>
#include <vector>

using namespace std;

extern const int NB_CHAMBRES;
extern vector<vector<string>> chambres;

void initialiserChambres();
bool creerReservation();
void annulerReservation();
void modifierReservation();
void modifierReservationChambre();
void afficherReservations();
void trouverReservation();
void echangerReservations();
void trierReservations();
void statistiquesReservations();

#endif // GESTION_RESERVATIONS_H
