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
    <center><h1 style="background-color: aqua;">Update Marks</h1>
        <form action="updatemarks4.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
        <tr>
                <td id="r">Semester: </td>
                <?php echo "<td colspan='2'><input type='text' name='sem' value=".$_POST['sem']."></td>"?>
            </tr>
            <tr>
                <td id="r">KTU ID: </td>
                <?php echo "<td colspan='2'><input type='text' name='id' value=".$_POST['id']."></td>"?>
                    </td></td>
            </tr>
            <tr>
                <td id="r">Subject: </td>
                <?php echo "<td colspan='2'><input type='text' name='sub' value=".$_POST['sub']."></td>";?>
                    </td></td>
            </tr>
            
            
            <?php
            $id=$_POST['id'];
            $sub=$_POST['sub'];
            $conn=mysqli_connect("localhost","root","cetmca","student");
            $s="select * from marks where ID='$id' and subject= '$sub'";
            $p=mysqli_query($conn,$s);
            while($r=mysqli_fetch_array($p))
            {
                echo "<tr><td>Series 1: </td><td colspan='2'><input type='text' name='s1' value=".$r['s1']."></td></tr>";
                echo "<tr><td>Series 2: </td><td colspan='2'><input type='text' name='s2' value=".$r['s2']."></td></tr>";
                echo "<tr><td>Assignment 1: </td><td colspan='2'><input type='text' name='a1' value=".$r['a1']."></td></tr>";
                echo "<tr><td>Assignment 2: </td><td colspan='2'><input type='text' name='a2' value=".$r['a2']."></td></tr>";
                echo "<tr><td>Attendance: </td><td colspan='2'><input type='text' name='att' value=".$r['att']."></td></tr>";
            }?>
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks" value="Update"></td>
                </tr>    
        </table>
        </form>
    </body>
</html>
            
