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
    <form action="formsubmit.php" method="post">
        <table style="color: aqua; font-size: 24px; text-align:right">
            <tr>
                <td>ID:</td>
                <td><input type="text" placeholder="Enter ID" name="rno"></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" placeholder="Enter Password" name="pass"></td>
            </tr>
            <tr>
                <td><input type="submit" name="display" value="Login"><br></td>
                <td><a style="color: red;   " href="registersubmit.php">Register Here?</a></td>
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

function insert()
{
    $name=$_POST['fname'];
    
    $id=generateID();    
    
    
    
    $home=$_POST['home'];
    $office=$_POST['office'];
    $conn=mysqli_connect("localhost","root","cetmca","student");
    if(!$conn) {
        echo mysqli_connect_error();
    } else {
        if (
            isset($_POST['fname']) && !empty($_POST['fname']) &&
            isset($_POST['age']) && !empty($_POST['age']) &&
            isset($_POST['password']) && !empty($_POST['password']) &&
            isset($_POST['repass']) && !empty($_POST['repass']) &&
            isset($_POST['ques']) && !empty($_POST['ques']) &&
            isset($_POST['secq_ans']) && !empty($_POST['secq_ans']) &&
            isset($_POST['email']) && !empty($_POST['email']) &&
            isset($_POST['lang']) && !empty($_POST['lang'])
        ) 
        {
            $name = $_POST['fname'];
            $age = $_POST['age'];
            $pass = $_POST['password'];
            $repass = $_POST['repass'];
            $sq = $_POST['ques'];
            $sq_ans = $_POST['secq_ans'];
            $email = $_POST['email'];
            $lang = $_POST['lang'];
    
            // Check if passwords match
            if ($pass != $repass) {
                echo "<script>alert('Retyped password does not match');</script>";
            } else {
                $l = implode(" ", $lang); // Convert array to string
                $q = "insert into register values('$name', '$id', '$age', '$pass', '$sq', '$sq_ans', '$email', '$l', '$home', '$office')";
                $p = mysqli_query($conn, $q);
    
                if ($p) {
                    echo "<script>alert('Inserted details into the database. Username is " . $id . "');</script>";
                }
            }
        } else {
            echo "<script>alert('Please fill in all the required fields.');</script>";
        }
    }
    
}

function generateID()
{
    
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $result = mysqli_query($conn, "SELECT MAX(ID) FROM register" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result))
        {
            return $row['MAX(ID)']+1;
        }
    }
    else
        return 1;
    
}


  
function display()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $rno=$_POST['rno'];
    $p=$_POST['pass'];
    $result = mysqli_query($conn, "SELECT * FROM register where ID='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result))
        {
            if($row['Password']!=$p)
                echo "<script>alert('Incorrect Password');</script>";
            else{
            
                    echo "<center><h1  style='color: aqua;'>REGISTERD DETAILS</h1><br><table width='75%' cellspacing='0' border='1' style=' text-align:center; color: white; font-size: 24px;'><tr><td>Name</td><td>ID</td><td>Age</td><td>Email</td><td>Languages</td><td>Home Phone Number</td><td>Office Phone Number</td></tr>";
                    
        
                    echo "<tr><td>".$row['Name']."</td><td>".$row['ID']."</td><td>".$row['Age']."</td><td> ". $row['Email']."</td><td>".$row['Languages']."</td><td>".$row['HomePh']."</td><td>".$row['OfficePh']."</td></tr>";
                    
                }
                echo "</center></table>";
        } 
    }  
    else
    {
        echo "<script>alert('Please Register brfore login');</script>";
    }
}
?>