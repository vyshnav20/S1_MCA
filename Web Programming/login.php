<html>
<head>
    <title>Student Registration</title>
</head>
<body>
    <center><h1>Register</h1>
    <form action="login.php" method="post">
        ID:<input type="text" placeholder="Enter ID" name="rno"><br>
        Password:<input type="text" placeholder="Enter Password" name="pass"><br>
        <input type="submit" name="display" value="Login">
    </form>    

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
    $result = mysqli_query($conn, "SELECT * FROM register where ID='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result))
        {
            if($row{'Password'}!=$p)
                echo "<script>alert('Incorrect Password');</script>";
                else{
            
                    echo "<table border='1'><tr><td>Name</td><td>ID</td><td>Age</td><td>Email</td><td>Languages</td><td>Home Phone Number</td><td>Office Phone Number</td></tr>";
                    
                    {
        
                    echo "<tr><td>".$row{'Name'}."</td><td>".$row{'ID'}."</td><td>".$row{'Age'}."</td><td> ". $row{'Email'}."</td><td>".$row{'Languages'}."</td><td>".$row{'HomePh'}."</td><td>".$row{'OfficePh'}."</td></tr>";
                    
                    }
                }
        } 
    }
    
        
            
        
        
}
  


?>
</center>
</body>
</html>