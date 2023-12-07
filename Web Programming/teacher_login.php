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
    <script type="text/javascript">
 function showHide() {
   var div = document.getElementById('a1');
   if (div.style.display == 'none') {
     div.style.display = '';
   }
   else {
     div.style.display = 'none';
   }
 }
</script>
</head>
<body>
    <center><h1 style="background-color: aqua;">LogIn</h1>
    <form action="teacher_login.php" method="post" onsubmit="showHide(); return false;">
        <table style="color: aqua; font-size: 24px; text-align:right">
            <tr>
                <td>Username:</td>
                <td><input type="text" placeholder="Enter ID" name="rno"></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" placeholder="Enter Password" name="pass"></td>
            </tr>
            <tr>
                <td colspan="2" align="center"><input type="submit"  name="display" value="Login"/><br></td>
            </tr>
        </table>        
    </form>    
    <hr>

    <div id='a1' style="display:none">
    <form action="marks1.php" method="post">
        <table  style="color: aqua;">
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
            </tr>
            <tr style="text-align: center;">
                    <td><input type="reset"></td>
                    <td colspan="2"><input type="submit" name="marks"></td>
                </tr>
        </table>
        </form>
    </div>

</center>
</body>
</html>
