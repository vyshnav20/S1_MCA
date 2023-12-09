<html>
<head>
    <title>Student Registration</title>
    <style>
        body {
            background-image: url("https://wallpapercave.com/wp/wp2055835.jpg");
            background-repeat: no-repeat;
            background-size: cover;
        }
    </style>
 </script>
</head>

</html>

<?php
    session_start();
    $conn = mysqli_connect("localhost", "root", "cetmca", "student");
    $sem=$_POST['sem'];
    $sub=$_POST['sub'];
    $result = mysqli_query($conn, "SELECT * FROM marks,ktu WHERE marks.ID=ktu.ktuid and marks.subject ='$sub'");
    echo "<center><h1  style='color: aqua;'>MARKS</h1><br>
                <table width='75%' cellspacing='0' border='1' style=' text-align:center; color: white; font-size: 24px;'>
                <tr>
                        <td>Name</td>
                        <td>Roll No:</td>
                        <td>KTU ID</td>
                        <td>Series 1</td>
                        <td>Series 2</td>
                        <td>Assignment 1</td>
                        <td>Assignment 2</td>
                        <td>Attendance(%)</td>
                        <td>Internal Marks</td>
                    </tr>";
    if (mysqli_num_rows($result)) {
        while ($row = mysqli_fetch_assoc($result)) {
            
                

                echo "<tr><td>" . $row['Name'] . "</td><td>" . $row['RollNo'] . "</td><td>" . $row['ID'] . "</td><td>" . $row['s1'] . "</td><td>" . $row['s2'] . "</td><td> " . $row['a1'] . "</td><td>" . $row['a2'] . "</td><td>" . $row['att'] . "</td><td>" . $row['internal'] . "</td></tr>";

                
            
        }
    }
    echo "</table>";


?>
