<html>
    <body>
    <select Name='ddlSelectYear'>
            <option value="">--- Select ---</option>

            <?php
            for ($x=date("Y"); $x>1900; $x--)
              {
                echo'<option value="'.$x.'">'.$x.'</option>'; 
              } 
            ?> 
        </select>
    </body>
</html>
