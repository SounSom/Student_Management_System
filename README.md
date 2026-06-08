# Student Management System
A modular, file-bound database application designed in C to manage student academic records through a command-line interface.

This project demonstrates core computer science and software engineering principles, including structured data management, persistent file I/O operations, and modular programmatic architecture.

Features
- Data Persistence: Automatically loads existing student records upon system initialization and serializes runtime updates back to a local storage file (.dat/.txt) upon termination.
  
- Record Allocation (Create): Facilitates the addition of new student profiles with distinct attributes, including unique identifiers, names, academic majors, and cumulative GPAs.

- Algorithmic Querying (Read): Implements search logic to locate and display individual student profiles from memory based on unique key constraints.

- Record Mutation (Update): Allows dynamic modification of existing administrative and academic records within active memory.

- Memory Management & Shifting (Delete): Facilitates the systematic removal of student entries from the data array while maintaining continuous indexing.

Architecture

- The system utilizes a modular multi-file structure to isolate execution logic and promote team-based parallel development:

- student.h: Header file acting as the central data contract, containing the core Student structure definition and global function prototypes.

- main.c: The master execution hub containing the system loop, user interface menu, and primary routing control logic.

- add.c / search.c / update.c / delete.c: Independent implementation files isolating specific business logic components.

- file_handler.c: Dedicated module managing disk I/O operations, specifically file parsing and data serialization.
