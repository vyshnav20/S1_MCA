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
    <center><h1 style="background-color: aqua;">LogIn</h1>
    <form action="studentupdate.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
            <tr>
                <td>KTU ID:</td>
                <td><input type="text" placeholder="Enter ID" name="rno"></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" placeholder="Enter Password" name="pass"></td>
            </tr>
            <tr>
                <td><input type="submit" name="display" value="Login"><br></td>
                <td><a style="color: red;   " href="studentregister.php">Register Here?</a></td>
            </tr>
        </table>        
    </form>    
    <hr>

</center>
</body>
</html>

<?php
if (array_key_exists('display',$_POST))
{
    display();
}

function display()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $rno=$_POST['rno'];
    $p=$_POST['pass'];
    $result = mysqli_query($conn, "SELECT * FROM `ktu` WHERE ktuid='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result))
        {
            if($row['Password']!=$p)
                echo "<script>alert('Incorrect Password');</script>";
            else{
            
                echo "<center><form action='update.php' method='post'><label style='color: white;'>KTU ID: <input type='text' name='ktuid' value=".$rno."></label><br><label style='color: white;'>New Password: </label><input type='password' placeholder='Enter new password' name='pass'><br><label style='color: white;'>Phone Number: </label><input type='text' name='phno' value=".$row['Phno']." ><br><input type='submit' value='Update' name='update'></form></center>";
                }
        } 
    }  
    else
    {
        echo "<script>alert('Please Register brfore login');</script>";
    }
}
?>