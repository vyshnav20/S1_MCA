<html>
<body>
    <center>
    <?php 
        session_start();
        echo "<h1>Welcome ".$_SESSION['username']."</h1>"
    ?>
    <h2>Place order</h2>
    <form method="post" action="orderbook.php" onsubmit="return validate()">
        Book ID<input type="text" name="book_id" id="book_id" required><br>
        Book Name<input type="text" name="bname" id="bname" required><br>
        Book Authour<input type="text" name="author" id="author" required><br>
        No of copies<select name='n' id='n'>
            <option value="">Select No:of copies</option>
            <?php 
                for ($i=1;$i<10;$i++)
                    echo"<option value=".$i.">".$i."</option>";
            ?>
        </select><br>
        <input type="submit" onclick="display()" name='insert'>
    </form>
    <a href="order.php">Orders</a>
    </center>
</body>
<script>
    function validateid() 
    {
        n=document.getElementById("book_id").value;
        if (/[^0-9]/.test(n))
            {
                alert("id conatians only numbers")
                return false;
            }
        else return true;
    }
    function validatename() 
    {
        n=document.getElementById("bname").value;
        if (/[^a-z]/.test(n))
            {
                alert("name conatians only alphabets")
                return false;
            }
        else return true;
    }
    function validateauthor() 
    {
        n=document.getElementById("author").value;
        if (/[^a-z]/.test(n))
            {
                alert("authour conatians only alphabets")
                return false;
            }
        else return true;
    }
    function validaten() 
    {
        n=document.getElementById("n").value;
        if (n=="")
            {
                alert("select no:of copies");
                return false;
            }
        else return true;
    }
    function validate() 
    {
        if(validateid()&&validatename()&&validateauthor()&&validaten())
            return true;
        else return false;
    }
</script>
</html>
<?php
if(array_key_exists('insert',$_POST))
{
    insert();
}



function insert() {
    $con=mysqli_connect('localhost','root','password','student');
    $id=$_POST['book_id'];
    $name=$_POST['bname'];
    $author=$_POST['author'];
    $n=$_POST['n'];
    $u=$_SESSION['username'];
    $s1=mysqli_query($con,"select * from book where username='$u' and bookid='$id'");
    if(mysqli_num_rows($s1)==0)
    {
        $s=mysqli_query($con,"insert into book values('$u','$id','$name','$author','$n')");
        echo "<script>alert('Added Order');</script>";
    }
    else
    {
        $s=mysqli_query($con,"update book set numcopies='$n' where username='$u' and bookid='$id'");
        echo "<script>alert('Already ordered!!!updated no:of copies');</script>";
    }
}
?>