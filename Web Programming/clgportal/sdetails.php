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
     <script type="text/javascript">
 function showHide() {
   var div = document.getElementById('marks1');
   if (div.style.display == 'none') {
     div.style.display = '';
   }
   else {
     div.style.display = 'none';
   }
 }
 </script>
</head>

</html>

<?php
    session_start();
    $conn = mysqli_connect("localhost", "root", "cetmca", "student");
    $rno = isset($_SESSION['rno']) ? $_SESSION['rno'] : '';
    $result = mysqli_query($conn, "SELECT * FROM `ktu` WHERE ktuid='$rno'");
    if (mysqli_num_rows($result)) {
        while ($row = mysqli_fetch_assoc($result)) {
            
                echo "<center><h1  style='color: aqua;'>REGISTERED DETAILS</h1><br>
                <table width='75%' cellspacing='0' border='1' style=' text-align:center; color: white; font-size: 24px;'>
                <tr>
                <td>Name</td>
                <td>ID</td>
                <td>Age</td>
                <td>Email</td>
                <td>Semester</td>
                <td>Phone Number</td>
                <td>Roll NUmber</td>
                <td>View Marks</td></tr>";

                echo "<tr><td>" . $row['Name'] . "</td><td>" . $row['ktuid'] . "</td><td>" . $row['Age'] . "</td><td> " . $row['email'] . "</td><td>" . $row['sem'] . "</td><td>" . $row['Phno'] . "</td><td>" . $row['RollNo'] . "</td><td><button type='button' onclick='showHide()'>View Marks</button></td></tr>";

                echo "</table>
                <div id='marks1' style='display:none'>
                <h1  style='color: aqua;'>MARKS</h1><br>
                <table width='75%' cellspacing='0' border='1' style=' text-align:center; color: white; font-size: 24px;'>
                    <tr>
                        <td>Subject</td>
                        <td>Series 1</td>
                        <td>Series 2</td>
                        <td>Assignment 1</td>
                        <td>Assignment 2</td>
                        <td>Attendance(%)</td>
                        <td>Internal Marks</td>
                    </tr>";
                    $m = mysqli_query($conn, "SELECT * FROM `marks` WHERE ID='$rno'");
                    if (mysqli_num_rows($m)) {
                        while ($row = mysqli_fetch_assoc($m)) {
                            echo "<tr>
                                    <td>" . $row['subject'] . "</td>
                                    <td>" . $row['s1'] . "</td>
                                    <td>" . $row['s2'] . "</td>
                                    <td>" . $row['a1'] . "</td>
                                    <td>" . $row['a2'] . "</td>
                                    <td>" . $row['att'] . "</td>
                                    <td>" . $row['internal'] . "</td>
                                </tr>";
                            
                            }}
                "</div>";
            
        }
    }


?>
