<html>
<head>
    <title>Student Registration</title>
</head>
<body>
    <center><h1>Register</h1>
    <form action="" method="post">
        Roll No:<input type="text" placeholder="Enter Roll Number" name="rno"><br>
        <input type="submit" name="display" value="Display Details">
    </form>    

<?php
if (array_key_exists('display',$_POST))
{
    display();
}
if (array_key_exists('update', $_POST)) {
    update();
}

function display()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $rno=$_POST['rno'];
    echo "<form method='post'>";
    $result = mysqli_query($conn, "SELECT * FROM stud where RollNo='$rno'" );
    if(mysqli_num_rows($result))
    {
        while ($row = mysqli_fetch_assoc($result)) {

            echo "Roll NO: <input type='text' value=".$row['RollNo']." disabled> Name: <input type='text' value=".$row['Name']." disabled> Mark: <input type='text' value=".$row['Marks']." name='up_mark'><input type='hidden' value=".$row['RollNo']." name='rno'><input type='submit' value='Update' name='update'> ";
            
            }
        } else {
            echo "<script>alert('Student Not Registered');</script>";
        }
    }
    
    function update() {
        $conn=mysqli_connect("localhost","root","cetmca","student");
        $rno=$_POST['rno'];
        $new_mark = $_POST['up_mark'];
        $update_query = "UPDATE stud SET Marks='$new_mark' WHERE RollNo='$rno'";
        if(mysqli_query($conn, $update_query)) {
            echo "Marks updated successfully";
        } else {
            echo "Error updating record: " . mysqli_error($conn);
        }
    }
?>
</center>
</body>
</html>
