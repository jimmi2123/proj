#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"



int main() {
    struct Room rooms[MAX_ROOMS];
    struct User users[MAX_USERS];
    struct Patient patients[MAX_PATIENTS];
    int num_rooms = 0;
    int num_users = 0;
    int num_patients = 0;

    // Populate initial data (for demonstration purposes)
    // In a real system, this data would be loaded from a database or file
    // For simplicity, passwords are stored in plaintext in this example
    // In practice, passwords should be hashed for security
    rooms[num_rooms++] = (struct Room){101, 1, -1};
    rooms[num_rooms++] = (struct Room){102, 0, 1};
    rooms[num_rooms++] = (struct Room){103, 1, -1};

    users[num_users++] = (struct User){"user1", "password1", 0}; // Regular user
    users[num_users++] = (struct User){"admin", "adminpassword", 1}; // Admin user

    // Main menu
    int choice;
    do {
        printf("\nHospital Management System Operations:\n");
        printf("1. Login\n");
        printf("2. Remove Current Reservation\n");
        printf("3. Check Empty Rooms\n");
        printf("4. Update Patient's Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char username[50], password[50];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                int privilege = login(users, num_users, username, password);
                if (privilege == 0) {
                    printf("Login successful as regular user.\n");
                    // Provide access to regular user operations
                } else if (privilege == 1) {
                    printf("Login successful as admin.\n");
                    // Provide access to admin operations
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            }
            case 2:
                removeReservation(rooms, num_rooms);
                break;
            case 3:
                checkEmptyRooms(rooms, num_rooms);
                break;
            case 4:
                updatePatientData(patients, &num_patients);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
