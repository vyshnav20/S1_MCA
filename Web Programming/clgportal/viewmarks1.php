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
</script>
</head>
<body>
    <center><h1 style="background-color: aqua;">Select ID & Subject</h1>
    <form action="viewmarks2.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
        <tr>
                <td id="r">Semester: </td>
                <?php echo "<td colspan='2'><input type='text' name='sem' value=".$_POST['sem']."></td>"?>
            </tr>
            <tr>
                <td id="r">Subject: </td>
                <td colspan="2"><select name="sub">
                    <option value="">Select subject</option>
                    <?php
                        $conn=mysqli_connect("localhost","root","cetmca","student");
                        $p=mysqli_query($conn,"select * from subject where sem=".$_POST['sem']);
                        while($r=mysqli_fetch_array($p))
                        {

                            echo"<option value=".$r['name'].">".$r['name']."</option>";
                        }
                    ?>
                    </td>
            </tr>
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks" value="Next"></td>
                </tr>
            </table>
        </form>
    </body>
</html>