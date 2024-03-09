#include "hospital.h"


// Function to simulate user login
int login(struct User *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].privilege; // Return user privilege (0 for regular user, 1 for admin)
        }
    }
    return -1; // Return -1 if login failed
}

// Function to remove current reservation (empty a room)
void removeReservation(struct Room *rooms, int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        if (!rooms[i].is_empty) {
            rooms[i].is_empty = 1; // Mark the room as empty
            rooms[i].patient_id = -1; // Reset patient ID
            printf("Room %d reservation removed.\n", rooms[i].room_number);
            return; // Exit after removing one reservation
        }
    }
    printf("No reservations to remove. All rooms are empty.\n");
}

// Function to check empty rooms
void checkEmptyRooms(struct Room *rooms, int num_rooms) {
    printf("Empty rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].is_empty) {
            printf("Room %d\n", rooms[i].room_number);
        }
    }
}

// Function to update patient's data
void updatePatientData(struct Patient *patients, int *num_patients) {
    int patient_id;
    int found = 0; // Flag to track if patient is found

    do {
        printf("Enter patient ID (0 to cancel): ");
        if (scanf("%d", &patient_id) != 1) {
            // Clear input buffer if invalid input
            printf("Invalid input. Please enter a valid patient ID.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Restart loop
        }

        // Check if user wants to cancel
        if (patient_id == 0)
            return;

        // Check if the patient ID is valid
        found = 0; // Reset found flag
        for (int i = 0; i < *num_patients; i++) {
            if (patients[i].patient_id == patient_id) {
                found = 1;
                printf("Enter new status for patient %s: ", patients[i].name);
                scanf("%s", patients[i].status);
                printf("Patient data updated.\n");
                break;
            }
        }
        if (!found) {
            // Prompt user to create new patient entry
            char new_patient_name[50];
            printf("Patient not found. Enter name for new patient: ");
            scanf("%s", new_patient_name);

            // Create new patient entry
            printf("Creating new patient entry for %s...\n", new_patient_name);
            strcpy(patients[*num_patients].name, new_patient_name);
            strcpy(patients[*num_patients].status, "New");
            patients[*num_patients].patient_id = (*num_patients + 1); // Assign new patient ID
            (*num_patients)++;
            printf("New patient entry created with ID %d.\n", patients[*num_patients - 1].patient_id);
            break; // Exit loop after creating new patient entry
        }
    } while (!found);
}
