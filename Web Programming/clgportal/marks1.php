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
                        $conn=mysqli_connect("localhost","root","Vyshnav@2002","student");
                        $p=mysqli_query($conn,"select ktuid from ktu where sem=".$_POST['sem']);
                        while($r=mysqli_fetch_array($p))
                        {

                            echo"<option value=".$r['ktuid'].">".$r['ktuid']."</option>";
                        }
                    ?>
                    </td></td>
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
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks1"></td>
                </tr>
        </table>
        </form>
    </body>
</html>
<?php
if (array_key_exists('marks1', $_POST)) {
    display();
}
function display() {
$id=$_POST['id'];
$sem=$_POST['sem'];
$sub=$_POST['sub'];
$s1=$_POST['s1'];
$s2=$_POST['s2'];
$a1=$_POST['a1'];
$a2=$_POST['a2'];
$att=$_POST['att'];
$internal=(($s1+$s2)*0.2)+(($a1+$a2)/2.0);
if($att>90)
    $internal+=8;
elseif($att>80)
    $internal+=7;
elseif($att>70)
    $internal+=6;
else
    $internal+=0;
$conn=mysqli_connect("localhost","root","cetmca","student");
$s="insert into marks values ('$id','$sem','$sub','$s1','$s2','$a1','$a2','$att','$internal')";
if(mysqli_query($conn,$s))
    echo "<script>alert('Marks Inserted');</script>";    
}          
?>