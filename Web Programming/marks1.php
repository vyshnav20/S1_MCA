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
    <center><h1 style="background-color: aqua;">Marks</h1>
        <form action="marks1.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
        <tr>
                <td id="r">Semester: </td>
                <?php echo "<td colspan='2'><input type='text' name='sem' value=".$_POST['sem']."></td>"?>
            </tr>
            <tr>
                <td id="r">KTU ID: </td>
                <td colspan="2"><select name="id">
                    <option value="">Select ktu id</option>
                    <?php
                        $conn=mysqli_connect("localhost","root","cetmca","student");
                        $p=mysqli_query($conn,"select ktuid from ktu where sem=".$_POST['sem']);
                        while($r=mysqli_fetch_array($p))
                        {

                            echo"<option value=".$r['ktuid'].">".$r['ktuid']."</option>";
                        }
                    ?>
                    </td></td>
            </tr>
            <tr>
                <td id="r">Series 1: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for series 1" name="s1"></td>
            </tr>
            <tr>
                <td id="r">Series 2: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for series 2" name="s2"></td>
            </tr>
            <tr>
                <td id="r">Assignment 1: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for Assignment 1" name="a1"></td>
            </tr>
            <tr>
                <td id="r">Assignment 2: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for Assignment 1" name="a2"></td>
            </tr>
            <tr>
                <td id="r">Attendance: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for Attendance" name="att"></td>
            </tr>
            <tr>
                <td id="r">End Semester: </td>
                <td colspan="2"><input type="text" placeholder="Enter marks for End Semester" name="sem_mark"></td>
            </tr>
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks"></td>
                </tr>
        </table>
        </form>
    </body>
</html>
<?php
$id=$_POST['id'];
$sem=$_POST['sem'];
$s1=$_POST['s1'];
$s2=$_POST['s2'];
$a1=$_POST['a1'];
$a2=$_POST['a2'];
$att=$_POST['att'];
$sem_mark=$_POST['sem_mark'];
$conn=mysqli_connect("localhost","root","cetmca","student");
$s="insert into marks values ('$id','$sem','$s1','$s2','$a1','$a2','$att','$sem_mark')";
if(mysqli_query($conn,$s))
    echo "<script>alert('Marks Inserted');</script>";
?>