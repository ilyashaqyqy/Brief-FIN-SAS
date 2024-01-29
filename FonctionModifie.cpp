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

void modifierTache(Tache taches[], int nombreTaches) {
    if (nombreTaches == 0) {
    	printf("==============================\n");
        printf(" Aucune tache disponible.\n");
        printf("==============================\n");
        return;
    }

    printf("Liste des taches :\n");
    for (int i = 0; i < nombreTaches; i++) {
        printf("%d. %s\n", i + 1, taches[i].titre);
    }

    int choix;
    printf("Choisissez le numero de la tache a modifier : ");
    scanf("%d", &choix);

    if (choix >= 1 && choix <= nombreTaches) {
        int index = choix - 1;

        printf("1. Modifier le titre\n");
        printf("2. Modifier la description\n");
        printf("3. Modifier la date limite\n");
        printf("4. Modifier la priorite\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Nouveau titre : ");
                scanf(" %[^\n]", taches[index].titre);
                break;
            case 2:
                printf("Nouvelle description : ");
                scanf(" %[^\n]", taches[index].description);
                break;
            case 3:
                printf("Nouvelle date limite (jour mois annee) : ");
                scanf("%d %d %d", &taches[index].dateLimite.jour,
                                    &taches[index].dateLimite.mois,
                                    &taches[index].dateLimite.annee);
                break;
            case 4:
                printf("Nouvelle priorite (1-5) : ");
                scanf("%d", &taches[index].priorite);
                break;
            default:
            	printf("==============================\n");
                printf(" Choix invalide.\n");
                printf("==============================\n");
                return;
        }

        printf("==============================\n");
        printf(" > Tache modifiee avec succes.\n");
        printf("==============================\n");
        
    } else {
    	printf("==============================\n");
        printf(" Choix invalide.\n");
        printf("==============================\n");
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
            case 3:
                modifierTache(taches, nombreTaches); 
                break;
                default : 
                printf("entrer un choix entre (1-5) :\n");
        }

    } while (choix != 5);

    return 0;
}

