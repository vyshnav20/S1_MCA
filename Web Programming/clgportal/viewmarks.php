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
    <center><h1 style="background-color: aqua;">Select Semester</h1>
    <form action="viewmarks1.php" method="post">
        <table  style="color: aqua;">
            <tr>
                <td id="r">Semester: </td>
                <td colspan="2"><select name="sem">
                    <option value="">Select Semester</option>
                    <option value="1">1</option>
                    <option value="2">2</option>
                    <option value="3">3</option>
                    <option value="4">4</option>
                </select></td></td>
            </tr>
            </tr>
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks" value="Next"></td>
                </tr>
        </table>
        </form>
    

</center>
</body>
</html>
