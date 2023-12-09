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
<body>
    <center>
        <h1 style="background-color: aqua;">LogIn</h1>
        <form action="sdetails.php" method="post">
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
                    <td><a style="color: red;" href="studentregister.php">Register Here?</a></td>
                </tr>
            </table>
        </form>
        <hr>
    </center>
</body>
</html>
