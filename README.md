# Student Record System Project

This `Student Record System` is a simple console-based application developed in C. It utilizes linked lists to manage student data, including names, grades, IDs, ages, genders, and passwords. The system supports two modes of operation: Admin mode and User mode, catering to different user privileges and needs.

## Features

### Common Features
- **Two Modes of Operation**: Select between Admin and User mode at startup.
- **Secure Access**: Requires passwords to access sensitive features.

### Admin Mode
1. **Add Student Record**: Enter student's name, total grade, unique ID, age, gender, and password.
2. **Remove Student Record**: Remove a student's record by their unique ID.
3. **View Student Record**: Display a student's details using their ID.
4. **View All Records**: Display all students' records.
5. **Edit Admin Password**: Secure admin operations by allowing password changes.
6. **Edit Student Grade**: Modify a student's grade using their ID.

### User Mode
1. **View Your Record**: Display the logged-in student's record.
2. **Edit Your Password**: Allows students to change their own passwords.
3. **Edit Your Name**: Enables students to update their name.

## Implementation Details

### Data Handling
- **Linked Lists**: Utilizes linked lists for efficient data manipulation and storage.
- **Dynamic Memory Allocation**: Ensures flexible memory usage by dynamically allocating space for student names and passwords.
- **Unique ID Checks**: Guarantees that each student ID is unique and prevents duplicate records.

### Security Features
- **Password-Protected Admin Access**: Protects sensitive operations behind a password verification process with a default password `1234` and a limit of three attempts.
- **Individual Logins for Users**: Each student can access and edit their own records using their ID and password.


## Usage

1. **Starting the Program**: Run the program and choose between Admin or User mode.
2. **Admin Mode**: Authenticate with the admin password. Upon successful login, perform administrative tasks like adding, removing, or editing student records.
3. **User Mode**: Log in using a student ID and password to view or edit personal details.

## Additional Notes

- Ensure proper validation of user inputs to prevent errors during operations like adding new students or editing existing ones.
- Regularly update and test security features to safeguard user data.

This README aims to provide a clear overview of the `Student Record System` project. It serves as a guide for developers and users to understand the functionalities, implementation techniques, and best practices associated with the system.