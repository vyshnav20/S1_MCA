<html>
<head>
   <title>Links</title>
   <style>            
    a {
        text-decoration: none;
        color: #4800ff;
        font-weight: bold;
        display: flex;
        align-items: center; 
    }
    a:hover{
        text-decoration: underline;
        color: #ff0000;
        font-weight: bold;
        display: flex;
        align-items: center; 
    }
    
    </style>
</head>
<body style="background-image: url('https://st4.depositphotos.com/3930503/30199/i/450/depositphotos_301993772-stock-photo-light-blue-gradient-background-blue.jpg');background-repeat: no-repeat;
background-size: cover;">
    <div style="position: fixed; top: 0; right:0;padding: 20px;">
        <table cellpadding="5">
            <?php
            session_start();
            $conn = mysqli_connect("localhost", "root", "cetmca", "student");
            $rno = isset($_SESSION['rno']) ? $_SESSION['rno'] : '';
            $p=mysqli_query($conn,"select Name from ktu where ktuid='$rno'");
            while($r=mysqli_fetch_array($p))
                echo "<tr><td><h4  style='color: black;'>".$rno." ".$r['Name']."</h4></td></tr>";
            ?>
            <tr><td><a href="portalhome.html" target="display1" class="link">Home</a></td></tr>
            <tr><td><a href="sdetails.php" target="display1" class="link">Details/Marks</a></td></tr>
            <tr><td><a href="studentupdate.php" target="display1" class="link">Update Details</a></td></tr>
            </tr>

        </table>
    </div>
</body>
</html>         