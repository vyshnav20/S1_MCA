<html>
<head>
    <title>Registration Form</title>
    <style>
        body{
            background-image: url("https://wallpapercave.com/wp/wp2055835.jpg");
            background-repeat: no-repeat;
            background-size: cover;
        }
        #r{
            text-align: right;
        }
        input[type="text"],input[type="password"],input[type="email"]{
            background-color:rgba(0,0, 0,0.5);
            color: aqua;
            font-size: 15;
            width: 100%;
        }
        table{
            color: white;
            font-size: 20;
        }
        select{
            background-color:rgb(0,0, 0);
            color: aqua;
            font-size: 15;
        }
    </style>
</head>
<body>
    <marquee style="background-color: aqua;" behavior="scroll" onmouseover="this.stop()" onmouseout="this.start()"><h1>Student Registration!!</h1></marquee>
    <hr>
    <center>
        <div class="form" style="background-color: rgb(0, 0, 0);">
            <form method="post" action="studentregister.php">
            <table border="1" cellspacing="0" cellpadding="5" width="75%" >
                <tr>
                    <td colspan="3" style="text-align: center;"><h2 style="color: aqua;">Regitration Form</h2></td>
                </tr>
                <tr>
                    <td id="r">Name: </td>
                    <td colspan="2"><input type="text" placeholder="Enter full name" name="fname"></td>
                </tr>
                <tr>
                    <td id="r">Age: </td>
                    <td colspan="2">
                        <select name="age">
                            <option value="">Select Age</option>
                            <?php
                            for($i=19;$i<31;$i++)
                            {
                                echo"<option value=".$i.">".$i."</option>";
                            }
                            ?>
                        </select></td>
                </tr>
                <tr>
                    <td id="r">Password: </td>
                    <td colspan="2"><input type="password" placeholder="Enter password" name="pass"></td>
                </tr>
                <tr>
                    <td id="r">Re-enter Password: </td>
                    <td colspan="2"><input type="password" placeholder="Re-enter password" name="repass"></td>
                </tr>
                <tr>
                    <td id="r">KTU ID: </td>
                    <td colspan="2"><input type="text" placeholder="Enter KTU ID" name="ktuid"></td>
                </tr>
                <tr>
                    <td id="r">Roll Number: </td>
                    <td colspan="2"><input type="text" placeholder="Enter Roll Number" name="rno"></td>
                </tr
                >
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
                <tr>
                    <td id="r">Email ID: </td>
                    <td colspan="2"><input type="email" placeholder="Enter email id" name="email" ></td>
                </tr>
                <tr>
                    <td id="r">Phone Number: </td>
                    <td colspan="2"><input type="text" placeholder="Enter phone number" name="phno" ></td>
                </tr>
                <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="insert"></td>
                </tr>
            </table>
        </form>
        </div>
        
    </center>
    
</body>
<?php
$conn=mysqli_connect("localhost","root","cetmca","student");
if(!$conn) 
{
    echo mysqli_connect_error();
} 
else 
{        
    $name = $_POST['fname'];
    $age = $_POST['age'];
    $pass = $_POST['pass'];
    $repass = $_POST['repass'];
    $ktuid = $_POST['ktuid'];
    $sem = $_POST['sem'];
    $rno = $_POST['rno'];
    $email = $_POST['email'];
    $phno = $_POST['phno'];

    // Check if passwords match
    if ($pass != $repass) {
        echo "<script>alert('Retyped password does not match');</script>";
        
    } else {
        $q = "insert into ktu values('$name', '$age', '$pass', '$ktuid', '$phno', '$sem', '$rno', '$email')";
        $p = mysqli_query($conn, $q);

        if ($p) {
            header("location: studentlogin.php");
        }
    }
} 


?>