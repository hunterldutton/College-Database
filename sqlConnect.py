# Facilitate commands to SQL as dictated by user input
# In main.cpp

# Install mysql.connector before running
# Run "py -m pip install mysql-connector-python" in CLI
import mysql.connector
import sys

# Connect to WebDB database
facultyDb = mysql.connector.connect(
    host = "webdb.uvm.edu",
    user = "hdutton_writer",
    password = "am9YHGaOxrjq7OiH",
    database = "HDUTTON_cs120"
)

cursor = facultyDb.cursor()

# Print the names of all Professors
def print_all_professors():
    hasNames = False
    cursor.execute("SELECT firstName, lastName FROM tblProfessorList;")
    for nameTuple in cursor:
        for names in nameTuple:
            print(names, end = ' ')
        print("\n")
        hasNames = True
    if hasNames == False:
        print("No entries in Professor list.")

# Print the names of all Administrators
def print_all_admin():
    hasNames = False
    cursor.execute("SELECT firstName, lastName FROM tblAdminList;")
    for nameTuple in cursor:
        for names in nameTuple:
            print(names, end = ' ')
        print("\n")
        hasNames = True
    if hasNames == False:
        print("No entries in Administrator list.")

# Print the names of all TAs
def print_all_TAs():
    hasNames = False
    cursor.execute("SELECT firstName, lastName FROM tblTAList;")
    for nameTuple in cursor:
        for names in nameTuple:
            print(names, end = ' ')
        print("\n")
        hasNames = True
    if hasNames == False:
        print("No entries in TAs list.")

# Use all three print functions
if sys.argv[1] == "printMembers":
    print("Professors: \n")
    print_all_professors()
    print("Administrators: \n")
    print_all_admin()
    print("TAs: \n")
    print_all_TAs()

# Print professors call
elif sys.argv[1] == "printProfessors":
    print("Professors: \n")
    print_all_professors()

# Print administrators call
elif sys.argv[1] == "printAdmin":
    print("Administrators: \n")
    print_all_admin()

# Print TAs call
elif sys.argv[1] == "printTA":
    print("TAs: \n")
    print_all_TAs()
    
# Search for faculty members by department
elif sys.argv[1] == "searchDep":
    department = sys.argv[2]
    if sys.argv[3] == "all":
        sql_statement = "SELECT firstName, lastName FROM tblProfessorList, tblAdminList, tblTAList " 
        + "WHERE department = %s;"
    departmentList = (department,)
    cursor.execute(sql_statement, departmentList)
    hasNames = False
    for nameTuple in cursor:
        for names in nameTuple:
            print(names, end = ' ')
        print("\n")
        hasNames = True
    if hasNames == False:
        print("No faculty members found in this department.")

# Search for faculty members by first and last name
elif sys.argv[1] == "searchName":
    firstNameSearch = sys.argv[2]
    lastNameSearch = sys.argv[3]
    countStatement = "SELECT COUNT(*) FROM tblProfessorList WHERE firstName = %s AND lastName = %s;"
    names = (firstNameRemove, lastNameRemove)
    cursor.execute(countStatement, names)
    numberDeletions = cursor.fetchone()
    if numberDeletions > 0:
        sql_statement = "SELECT * FROM tblProfessorList WHERE firstName = %s AND lastName = %s;"
        searchNames = (firstNameSearch, lastNameSearch)
        cursor.execute(sql_statement, searchNames)
        statusSearch = "Professor"
        hasNames = False
        for nameTuple in cursor:
            fn = nameTuple[0]
            ln = nameTuple[1]
            dep = nameTuple[2]
            email = nameTuple[3]
            offBuild = nameTuple[4]
            offNum = nameTuple[5]
            print(fn, ln + ",", dep+ ",", email, "-", offBuild, offNum, "-", statusSearch)
            hasNames = True
        if hasNames == False:
            print("No faculty members found with this name.")
    countStatement = "SELECT COUNT(*) FROM tblAdminList WHERE firstName = %s AND lastName = %s;"
    names = (firstNameRemove, lastNameRemove)
    cursor.execute(countStatement, names)
    numberDeletions = cursor.fetchone()
    if numberDeletions > 0:
        sql_statement = "SELECT * FROM tblAdminList WHERE firstName = %s AND lastName = %s;"
        searchNames = (firstNameSearch, lastNameSearch)
        cursor.execute(sql_statement, searchNames)
        statusSearch = "Administrator"
        hasNames = False
        for nameTuple in cursor:
            fn = nameTuple[0]
            ln = nameTuple[1]
            dep = nameTuple[2]
            email = nameTuple[3]
            offBuild = nameTuple[4]
            offNum = nameTuple[5]
            print(fn, ln + ",", dep+ ",", email, "-", offBuild, offNum, "-", statusSearch)
            hasNames = True
        if hasNames == False:
            print("No faculty members found with this name.")
    countStatement = "SELECT COUNT(*) FROM tblTAList WHERE firstName = %s AND lastName = %s;"
    names = (firstNameRemove, lastNameRemove)
    cursor.execute(countStatement, names)
    numberDeletions = cursor.fetchone()
    if numberDeletions > 0:
        sql_statement = "SELECT * FROM tblTAList WHERE firstName = %s AND lastName = %s;"
        searchNames = (firstNameSearch, lastNameSearch)
        cursor.execute(sql_statement, searchNames)
        statusSearch = "TA"
        hasNames = False
        for nameTuple in cursor:
            fn = nameTuple[0]
            ln = nameTuple[1]
            dep = nameTuple[2]
            email = nameTuple[3]
            grader = bool(nameTuple[4])
            if grader == True:
                graderString = "Grader"
            else:
                graderString = "Non-Grader"
            print(fn, ln + ",", dep+ ",", email, "-", statusSearch, "-", graderString)
            hasNames = True
        if hasNames == False:
            print("No faculty members found with this name.")

# Add member 
elif sys.argv[1] == "addMember":
    firstNameAdd = sys.argv[2]
    lastNameAdd = sys.argv[3]
    departmentAdd = sys.argv[4]
    emailAdd = sys.argv[5]
    if len(sys.argv) == 9:
        if sys.argv[8] == "professors":
            officeBuildingAdd = sys.argv[6]
            officeNumberAdd = int(sys.argv[7])
            sql_statement = "INSERT INTO tblProfessorList (firstName, lastName, department,"\
                        + " email, officeBuilding, officeRoomNumber) VALUES (%s, %s, %s, %s, %s, %s);"
            values = (firstNameAdd, lastNameAdd, departmentAdd, emailAdd,
                  officeBuildingAdd, officeNumberAdd)
        elif sys.argv[8] == "admin":
            officeBuildingAdd = sys.argv[6]
            officeNumberAdd = int(sys.argv[7])
            sql_statement = "INSERT INTO tblAdminList (firstName, lastName, department,"\
                        + " email, officeBuilding, officeRoomNumber) VALUES (%s, %s, %s, %s, %s, %s);"
            values = (firstNameAdd, lastNameAdd, departmentAdd, emailAdd,
                  officeBuildingAdd, officeNumberAdd)
    else:
        isGraderAdd = int(sys.argv[6])
    if sys.argv[7] == "TA":
        sql_statement = "INSERT INTO tblTAList (firstName, lastName, department,"\
                    + " email, isGrader) VALUES (%s, %s, %s, %s, %s);"
        values = (firstNameAdd, lastNameAdd, departmentAdd, emailAdd, isGraderAdd)
    cursor.execute(sql_statement, values)
    facultyDb.commit()

# Remove member
elif sys.argv[1] == "removeMember":
    firstNameRemove = sys.argv[2]
    lastNameRemove = sys.argv[3]
    statusRemove = sys.argv[4]
    if statusRemove == "professors":
        countStatement = "SELECT COUNT(*) FROM tblProfessorList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)
        cursor.execute(countStatement, names)
        numberDeletions = cursor.fetchone()
        sql_statement = "DELETE FROM tblProfessorList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)    
        cursor.execute(sql_statement, names)
        facultyDb.commit()
    elif statusRemove == "admin":
        countStatement = "SELECT COUNT(*) FROM tblAdminList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)
        cursor.execute(countStatement, names)
        numberDeletions = cursor.fetchone()
        sql_statement = "DELETE FROM tblAdminList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)    
        cursor.execute(sql_statement, names)
        facultyDb.commit()
    elif statusRemove == "TA":
        countStatement = "SELECT COUNT(*) FROM tblTAList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)
        cursor.execute(countStatement, names)
        numberDeletions = cursor.fetchone()
        sql_statement = "DELETE FROM tblTAList WHERE firstName = %s AND lastName = %s;"
        names = (firstNameRemove, lastNameRemove)    
        cursor.execute(sql_statement, names)
        facultyDb.commit()
    
    if numberDeletions[0] > 0:
        print("\n" + firstNameRemove, lastNameRemove, "was removed.\n")
    else:
        print("\n" + firstNameRemove, lastNameRemove, "was not found.\n")
    
# Update local Faculty vectors
elif sys.argv[1] == "updateVectors":
    professorList = open("professorList.txt", "w")
    cursor.execute("SELECT * FROM tblProfessorList;")
    profResults = cursor.fetchall()
    for prof in profResults:
        printStatement = prof[0] + " " + prof[1] + " " + prof[2] + " " + prof[3] + " " + prof[4] + " " + str(prof[5]) + "\n"
        professorList.write(printStatement)
    professorList.close()
    adminList = open("adminList.txt", "w")
    cursor.execute("SELECT * FROM tblAdminList")
    adminResults = cursor.fetchall()
    for admin in adminResults:
        printStatement = admin[0] + " " + admin[1] + " " + admin[2] + " " + admin[3] + " " + admin[4] + " " + str(admin[5]) + "\n"
        adminList.write(printStatement)
    adminList.close()
    TAList = open("TAList.txt", "w")
    cursor.execute("SELECT * FROM tblTAList")
    TAResults = cursor.fetchall()
    for TA in TAResults:
        printStatement = TA[0] + " " + TA[1] + " " + TA[2] + " " + TA[3] + " " + str(TA[4]) + "\n"
        TAList.write(printStatement)
    TAList.close()
    
