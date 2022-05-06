# Final Project - Hunter Dutton
### Summary:
My project is a User Interface to work with a database
of faculty members. C++ acts as the interface, allowing users
to see, search for, add, and remove members in the database.
Members are split into three tables: Professors, Administrators,
and TAs. C++ will pass command line arguments to the Python file,
which determines and runs the correct SQL statements. Additionally, 
a website frontend displays the up-to-date database tables.
#### [Website Link](https://hdutton.w3.uvm.edu/cs120-final/facultyDisplay.php)

### Concepts from Class:
In my program, I used concepts from Module 2 and Module 3.
I used inheritance to create a Faculty superclass, and then
made subclasses for Professors, Administrators, and TAs. 
I also used the Command Line Interface to connect C++ to the 
Python file, and Python to the SQL Database.

### Operating System:
I created this system using Windows. I have tried to make the program
cross-compatible by using preprocessor directives to change the command line
arguments depending on your operating system, but I'm not 100% sure
it will work on macOS or Linux.

### Necessary Installations:
I installed the MySQL Connector module for Python.
On my computer, I installed it with the following command:
```
py -m pip install mysql-connector-python
```
(Note: the command necessary to install this module
may be different depending on your operating system.)

### Grading:
I believe I deserve the full 150 points for this
project. I used the different concepts I chose
in a way that made sense, my files are well documented
and run without, the program has definite utility
in the real world, and I believe it is complex
enough to qualify as a final project.

### [Video Demo](https://uvmoffice-my.sharepoint.com/:v:/g/personal/hdutton_uvm_edu/EaY9a2e8Z_9Pq6QLYwoS9aUBr68ZdUa047cDgGlrs1Kbag?e=NcsRQa)