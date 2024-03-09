#ifndef HOSPITAL.H
#define HOSPITAL.H

// Define constants for maximum number of rooms, users, and patients
#define MAX_ROOMS 100
#define MAX_USERS 50
#define MAX_PATIENTS 100

// Structure to store room information
struct Room {
    int room_number;
    int is_empty; // 1 if empty, 0 if occupied
    int patient_id; // -1 if room is empty
};

// Structure to store user information
struct User {
    char username[50];
    char password[50];
    int privilege; // 0 for regular user, 1 for admin
};

// Structure to store patient information
struct Patient {
    int patient_id;
    char name[50];
    char status[50];
};






#endif // HOSPITAL
