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
    <form action="registermarks.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
            <tr>
                <td>ID:</td>
                <td><input type="text" placeholder="Enter ID" name="rno"></td>
            </tr>
            <tr>
                <td>Marks:</td>
                <td><input type="text" placeholder="Enter Marks" name="mark"></td>
            </tr>
            <tr>
                <td><input type="submit" name="addmark" value="ADD Marks"><br></td>
                <td><a style="color: red;   " href="registersubmit.php">Register Here?</a></td>
            </tr>
        </table>        
    </form>    
    <hr>

</center>
</body>
</html>