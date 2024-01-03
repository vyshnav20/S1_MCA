<html>
<body>
    <center>
        <h1>Login</h1>
        <form action="login.php" method="post">
            Username: <input type="text" name="u" id="u"><br>
            Password: <input type="password" name="pass" id="pass"><br>
            <input type="submit" name='submit'>
        </form>
    </center>
</body>
</html>
<?php 
if (array_key_exists('submit', $_POST)) {
    submit();
}
function submit() 
{
    session_start();
    $u=$_POST['u'];
    $pass=$_POST['pass'];
    $_SESSION['username']=$u;
    $con=mysqli_connect('localhost','root','password','student');
    $r=mysqli_query($con,"select * from user where username='$u'");
    if(!mysqli_num_rows($r))
        echo "<script>alert('Invalid username');</script>";
    else
        {
            $row=mysqli_fetch_array($r);
            if($pass!==$row['password'])
                echo "<script>alert('Incorrect password');</script>";
            else echo header('location:orderbook.php');
        }
}

?>
