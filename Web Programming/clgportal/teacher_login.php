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
    if((document.getElementById('pass').value)=="123")
    {
        var div = document.getElementById('a1');
        if (div.style.display == 'none') {
            div.style.display = '';
        }
        else {
            div.style.display = 'none';
        }
    }
    else
        alert('Incorrect Password');
 }
</script>
</head>
<body>
    <center><h1 style="background-color: aqua;">LogIn</h1>
    <form action="tframe.php" method="post" onsubmit="showHide(); return false;">
        <table style="color: aqua; font-size: 24px; text-align:right">
            <tr>
                <td>Username:</td>
                <td><input type="text" placeholder="Enter ID" name="rno"></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" placeholder="Enter Password" id="pass"></td>
            </tr>
            <tr>
                <td colspan="2" align="center"><input type="submit"  name="display" value="Login"/><br></td>
            </tr>
        </table>        
    </form>    
</center>
</body>
</html>
