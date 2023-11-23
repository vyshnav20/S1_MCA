<html>
<head>
    <title>Student Registration</title>
</head>
<body>
    <center><h1>Register</h1>
    <form action="searchroll.php" method="post">
        Roll No:<input type="text" placeholder="Enter Roll Number" name="rno"><br>
        <input type="submit" name="display" value="Display Details">
    </form>    

<?php
if (array_key_exists('display',$_POST))
{
    display();
}
function insert()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $name=$_POST['name'];
    $rno=$_POST['rno'];
    $mark=$_POST['mark'];
    if(!$conn)
        echo mysqli_connect_error();
    else
    {
        $q= "insert into stud values('$rno','$name','$mark')";
        $p= mysqli_query($conn,$q);
        if($p)
        {
            echo "<script>alert('Inserted details to database');</script>";
        }
        else
        {
            $s="Duplicate";
            if(strpos(mysqli_error($conn),$s)==false)
            {
                echo "<script>alert('Cannot insert student with Duplicate Roll Number');</script>";
            }
        }
    }
}
    


function display()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $rno=$_POST['rno'];
    echo "<table border='1'><tr><td>Roll Number</td><td>Name</td><td>Marks</td></tr>";
    $result = mysqli_query($conn, "SELECT * FROM stud where RollNo='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result)) {

            echo "<tr><td>".$row{'RollNo'}."</td><td>".$row{'Name'}."</td><td> ". $row{'Mark'}."</td></tr>";
            
            }
    }
    else
    {
        echo "<script>alert('Student Not Registered');</script>";
    }
    

}
?>
</center>
</body>
</html>