#include <stdio.h>

typedef struct Date {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct Tache {
    char titre[20];
    char description[100];
    Date dateLimite;
    int priorite;
} Tache;

int ajouterTache(Tache taches[], int nombreTaches) {
    if (nombreTaches < 50) {
        printf("Entrez le titre de la tache : ");
        scanf(" %[^\n]", taches[nombreTaches].titre);
        printf("Entrez la description de la tache : ");
        scanf(" %[^\n]", taches[nombreTaches].description);
        printf("Entrez la date limite (jour mois annee) : ");
        scanf("%d %d %d", &taches[nombreTaches].dateLimite.jour,
                          &taches[nombreTaches].dateLimite.mois,
                          &taches[nombreTaches].dateLimite.annee);
        printf("Entrez la priorite (1-5) : ");
        scanf("%d", &taches[nombreTaches].priorite);

        printf("Tache ajoutee avec succes \n");
        return 1;
    } else {
        printf("Impossible d'ajouter plus de taches.\n");
        return 0;
    }
}

void afficherTaches(Tache taches[], int nombreTaches) {
    if (nombreTaches == 0) {
        printf("Aucune tache disponible.\n");
    } else {
        printf("Liste des taches :\n");
        for (int i = 0; i < nombreTaches; i++) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date limite : %02d/%02d/%d\n", taches[i].dateLimite.jour, taches[i].dateLimite.mois, taches[i].dateLimite.annee);
            printf("Priorite : %d\n", taches[i].priorite);
            printf("\n");
        }
    }
}

int main() {
    Tache taches[50];
    int nombreTaches = 0;

    int choix;
    do {
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la Liste des Taches\n");
        printf("3. Modifier une Tache\n");
        printf("4. Supprimer une Tache\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (ajouterTache(taches, nombreTaches)) {
                    nombreTaches++;
                }
                break;
            case 2:
                afficherTaches(taches, nombreTaches);
                break;
                default : 
                printf("entrer un choix entre (1-5) :\n");
        }

    } while (choix != 5);

    return 0;
}

