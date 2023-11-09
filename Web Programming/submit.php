<html>
    <head>
    <style>
        body{
            background-image: url("https://wallpapercave.com/wp/wp2055835.jpg");
            background-repeat: no-repeat;
            background-size: cover;
        }
        table{
            color: white;
            font-size: 20;
        }
    </style>
    </head>
    <body>
    <center>
    <table border="1" cellspacing="0" cellpadding="5" width="75%" >
        <tr>
            <td>Name</td>
            <td> <?php
            $name=$_POST['fname'];
            echo "".$name;
            ?>
            </td>
        </tr>
        <tr>
            <td>Age</td>
            <td> <?php
            $age=$_POST['age'];
            echo "".$age;
            ?></td>
        </tr>
        <tr>
            <td>Security question</td>
            <td> <?php
            $sq=$_POST['ques'];
            echo "".$sq;
            ?></td>
        </tr>
        <tr>
            <td>Security answer</td>
            <td> <?php
            $sq_ans=$_POST['secq_ans'];
            echo "".$sq_ans;
            ?></td>
        </tr>
        <tr>
            <td>Email ID</td>
            <td> <?php
            $email=$_POST['email'];
            echo "".$email;
            ?></td>
        </tr>
        <tr>
            <td>Languages Known</td>
            <td> <?php
            $lang=$_POST['lang'];
            for ($i=0;$i<=2;$i++)
                echo "".$lang[$i]."  ";
            ?></td>
        </tr>
        <tr>
            <td>Home Phone Number</td>
            <td> <?php
            $home=$_POST['home'];
            echo "".$home;
            ?></td>
        </tr>
        <tr>
            <td>Office Phone Number</td>
            <td> <?php
            $office=$_POST['office'];
            echo "".$office;
            ?></td>
        </tr>
    </table>
    </center>
    
    
    </body>
</html>
