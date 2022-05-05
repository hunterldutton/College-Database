<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="author" content="Hunter Dutton">
        <?php
            include("connect-database.php");
        ?>    
        <title>Faculty Tables</title>
        <meta name="description" content="This page displays three tables from the database: Professors, Administrators, and TAs.">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen">
    </head>
    <body>
        <header>
            <h1>Faculty Data Tables</h1>
            <h2>View Tables of the Professors, Administrators and TAs</h2>
        </header>

        <table>
            <h2>Professors:</h2>
            <tr>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Department</th>
                <th>Email</th>
                <th>Office Building</th>
                <th>Room Number</th>
            </tr>
            <?php
                $sql = 'SELECT firstName, lastName, department, email, officeBuilding, officeRoomNumber FROM tblProfessorList';
                $statement = $pdo->prepare($sql);
                $statement->execute();
                $results = $statement->fetchAll();
                foreach ($results as $result) {
                    print '<tr>';
                    print '<td>' . $result['firstName'] . '</td>';
                    print '<td>' . $result['lastName'] . '</td>';
                    print '<td>' . $result['department'] . '</td>';
                    print '<td>' . $result['email'] . '</td>';
                    print '<td>' . $result['officeBuilding'] . '</td>';
                    print '<td>' . $result['officeRoomNumber'] . '</td>';
                    print '</tr>' . PHP_EOL;
                }
            ?>
        </table>

        <table>
            <h2>Administrators:</h2>
            <tr>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Department</th>
                <th>Email</th>
                <th>Office Building</th>
                <th>Room Number</th>
            </tr>
            <?php
                $sql = 'SELECT firstName, lastName, department, email, officeBuilding, officeRoomNumber FROM tblAdminList';
                $statement = $pdo->prepare($sql);
                $statement->execute();
                $results = $statement->fetchAll();
                foreach ($results as $result) {
                    print '<tr>';
                    print '<td>' . $result['firstName'] . '</td>';
                    print '<td>' . $result['lastName'] . '</td>';
                    print '<td>' . $result['department'] . '</td>';
                    print '<td>' . $result['email'] . '</td>';
                    print '<td>' . $result['officeBuilding'] . '</td>';
                    print '<td>' . $result['officeRoomNumber'] . '</td>';
                    print '</tr>' . PHP_EOL;
                }
            ?>
        </table>

        <table>
            <h2>TAs:</h2>
            <tr>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Department</th>
                <th>Email</th>
                <th>Are they a grader?</th>
            </tr>
            <?php
                $sql = 'SELECT firstName, lastName, department, email, isGrader FROM tblTAList';
                $statement = $pdo->prepare($sql);
                $statement->execute();
                $results = $statement->fetchAll();
                foreach ($results as $result) {
                    $grader = '';
                    if ($result['isGrader'] == 1){
                        $grader = "YES";
                    }
                    else {
                        $grader = "NO";
                    }
                    print '<tr>';
                    print '<td>' . $result['firstName'] . '</td>';
                    print '<td>' . $result['lastName'] . '</td>';
                    print '<td>' . $result['department'] . '</td>';
                    print '<td>' . $result['email'] . '</td>';
                    print '<td>' . $grader .'</td>';
                    print '</tr>' . PHP_EOL;
                }
            ?>
        </table>
    </body>
</html>