
<!DOCTYPE html>

<!-- Cabecera de la pagina -->
<html>

    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="../styles.css"/>
        <link rel="shortcut icon" href="../img/head.png">
        <title>Music</title>
        <!-- Includes de php para simplificar el codigo -->
        <?php
            session_start();
            include('classControl.php');
            include('classRegistrarDisco.php')
        ?>
    </head> 

    <body>
        <section class = "principal">
        <div class = "cabecera">
            <header class ="header">
                <section class = "titulo">
                    <?php
                        Control::titulo();
                    ?>
                </section>
            </header><!-- /header -->

            <nav class = "menu">
                <?php
                    Control::menu();
                ?>
            </nav>

            <section class = "cartel">
                <article class ="text_titulo">
                    <h1>Insertar Disco</h1>
                </article>
            </section>

            <section class = "registro">
                <article>
                    <?php                                             
                        if($_GET){
                            echo '<form action="registrarDisco.php" method="post" accept-charset="utf-8">
                                <h1>DISCO</h1>
                                <article class = "dato">
                                    <h1>Nombre</h1><input size="20" maxlength="200" type="text" name="nombre" value="" onblur="validaNombre()>
                                </article>
                                <article class = "dato">
                                    <h1>Genero</h1><input size="20" maxlength="200" type="text" name="genero" value="">
                                </article>
                                <article class = "dato">
                                    <h1>Fecha</h1><input size="20" maxlength="200" type="text" name="fecha" value="(0000-00-00)">
                                </article>
                                <article class = "dato">
                                    <h1>Caratula</h1><input size="20" maxlength="200" type="text" name="caratula" value="">
                                </article>
                                <article class = "dato">
                                    <h1>URL</h1><input size="0" maxlength="200" type="text" name="url" value="">
                                </article>
                                <article class = "dato">
                                    <h1>Valoracion</h1><input size="20" maxlength="200" type="text" name="valoracion" value="0">
                                </article>
                                <h1>CACIONES</h1>';
                                for($i=0;$i<$_GET['numCan']; $i++){
                                    echo '<article class = "dato">
                                        <h1>Cancion '.$i.'</h1><input size="20" maxlength="200" type="text" name="can'.$i.'" value="">
                                    </article>
                                    <article class = "dato">
                                        <h1>Pista '.$i.'</h1><input size="20" maxlength="200" type="text" name="pista'.$i.'" value="">
                                    </article>
                                    <article class = "dato">
                                        <h1>URL '.$i.'</h1><input size="20" maxlength="200" type="text" name="urls'.$i.'" value="">
                                    </article>';
                                }
                                echo '<article class = "botones_login">
                                    <button class = "botton_aceptar"><img class = "botton" src="../img/regi_save.png" alt=""></button>
                                </article>';
                            echo '</form>';
                        }else{
                            echo '<form action="registrarDisco.php" method="get" accept-charset="utf-8">
                                <article class = "dato">
                                    <h1>Numero de canciones</h1><input size="20" maxlength="200" type="text" name="numCan" value="0">
                                </article>
                                <input type="hidden" name="almacenar" value="0">                           
                                <article class = "botones_login">
                                    <button class = "botton_aceptar"><img class = "botton" src="../img/regi_save.png" alt=""></button>
                                </article>
                            </form>';    
                        }
                        if(count($_POST)>1){
                            $numero2 = count($_POST);
                            $tags2 = array_keys($_POST); 
                            $valores2 = array_values($_POST);

                            // crea las variables y les asigna el valor
                            for($i=0;$i<6;$i++){ 
                            $$tags2[$i]=$valores2[$i]; 
                            }
                            for($i=6;$i<$numero2;$i=$i+3){ 
                            $canciones[]=$valores2[$i]; 
                            }
                            for($i=7;$i<$numero2;$i=$i+3){ 
                            $pistas[]=$valores2[$i]; 
                            }
                            for($i=8;$i<$numero2;$i=$i+3){ 
                            $urls[]=$valores2[$i]; 
                            }
                            echo '<img class = "exito" src="../img/exito.png" alt="">';
                            Control::almacenarRegistroDisco($nombre, $genero, $fecha, $caratula, $url, $valoracion, $canciones, $pistas, $urls);
                            Persistence::generarComentarios($idDisco);
                        }
                    ?>
                </article>
            </section>

            </div>
            <aside class = "public">
                <?php                   
                    Control::publicidad();
                    //
                ?>
            </aside>
        </section>
        
        <footer class ="pie_pagina">
            <?php               
                Control::aniadir_pie();
            ?>     
        </footer>
    </body>

</html>