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
    <marquee style="background-color: aqua;" behavior="scroll" onmouseover="this.stop()" onmouseout="this.start()"><h1>WELCOME TO FRESHERS WORLD!!</h1></marquee>
    <hr>
    <center>
        <div class="form" style="background-color: rgb(0, 0, 0);">
            <form method="post" action="formsubmit.php" autocomplete="off">
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
                    <td colspan="2"><input type="password" placeholder="Enter password" name="password" ></td>
                </tr>
                <tr>
                    <td id="r">Re-enter Password: </td>
                    <td colspan="2"><input type="password" placeholder="Re-enter password" name="repass" ></td>
                </tr>
                <tr>
                    <td  id="r" rowspan="4">Select your security question: </td>
                    <td colspan="2"><input type="radio" name="ques" value="Pet name">What is your pet name?</td>
                </tr>
                <tr>
                    <td colspan="2"><input type="radio" name="ques" value="Best friend">Who is your best friend?</td>
                </tr>
                <tr>
                    <td colspan="2"><input type="radio" name="ques" value="Favourite colour">What is your favourite colour?</td>
                </tr>
                <tr>
                    <td colspan="2"><input type="radio" name="ques" value="Favourite sports team">Which is your favourite sports team?</td>
                </tr>
                <tr>
                    <td id="r">Answer of security question: </td>
                    <td colspan="2"><input type="text" placeholder="Enter answer" name="secq_ans"></td>
                </tr>
                <tr>
                    <td id="r">Email ID: </td>
                    <td colspan="2"><input type="email" placeholder="Enter email id" name="email" ></td>
                </tr>
                <tr>
                    <td id="r">Languages Known: </td>
                    <td colspan="2"><input type="checkbox" name="lang[]"value="English">English <input type="checkbox" name="lang[]" value="Malayalam">Malayalam <input type="checkbox" name="lang[]" value="Hindi">Hindi</td>
                </tr>
                <tr>
                    <td id="r" rowspan="2">Phone Number: </td>
                    <td style="text-align: center;"><b>Home</b></td>
                    <td style="text-align: center;"><b>Office</b></td>
                </tr>
                <tr>
                    <td><input type="text" name="home"></td>
                    <td><input type="text" name="office"></td>
                </tr>
                <tr>
                    <td id="r">Upload CV: </td>
                    <td colspan="2"><input type="file" name="f"></td>
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
</html>
