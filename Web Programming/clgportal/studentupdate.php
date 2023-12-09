<html>
<head>
    <title>Student Registration</title>
    <style>
        body{
            background-image: url("https://wallpapercave.com/wp/wp2055835.jpg");
            background-repeat: no-repeat;
            background-size: cover;
        }
    </style>
</head>
<body>
   
</body>
</html>

<?php
     session_start();
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $rno = isset($_SESSION['rno']) ? $_SESSION['rno'] : '';
    $result = mysqli_query($conn, "SELECT * FROM `ktu` WHERE ktuid='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result))
        {
            
                echo "<center><h1  style='color: aqua;'>UPDATE DETAILS</h1><br>
                <table>
                <form action='update.php' method='post'>
                <tr>
                    <td><label style='color: white;'>KTU ID:</label></td>
                    <td><input type='text' name='ktuid' value=".$rno."></td>
                </tr>
                <tr>
                    <td></label><label style='color: white;'>New Password: </label></td>
                    <td><input type='password' placeholder='Enter new password' name='pass'></td>
                </tr>
                <tr>
                    <td><label style='color: white;'>Phone Number: </label></td>
                    <td><input type='text' name='phno' value=".$row['Phno']." ></td>
                </tr>
                <tr>
                    <td colspan='2' align='center'><input type='submit' value='Update' name='update'></td>
                </tr>
                </form></table></center>";
                
        } 
    }

?>