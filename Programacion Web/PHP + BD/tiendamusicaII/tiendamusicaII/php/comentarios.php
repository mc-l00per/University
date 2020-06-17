
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
                        echo '<form action="comentarios.php" method="post" accept-charset="utf-8">
                            <h1>DISCO</h1>
                            <article class = "dato">
                                <h1>Nombre</h1><input size="20" maxlength="200" type="text" name="nombre" value="">
                            </article>
                            <article class = "dato">
                                <h1>Comentario</h1><textarea name="comentarios" rows="10" cols="30">Escribe aquí tus comentarios</textarea>
                            </article> 
                            <button class = "botton_aceptar"><img class = "botton" src="../img/enviar.png" alt=""></button>   
                        </form>';
                        
                        if(count($_POST)>1){
                            $numero2 = count($_POST);
                            $tags2 = array_keys($_POST); 
                            $valores2 = array_values($_POST);

                            // crea las variables y les asigna el valor
                            for($i=0;$i<$numero2;$i++){ 
                            $$tags2[$i]=$valores2[$i]; 
                            }
                            
                            echo '<img class = "exito" src="../img/exito.png" alt="">';
                            $discoTMP=Control::obtenerIdDeDisco($nombre);
                            echo $discoTMP;
                            Control::insertarComentario($discoTMP, $comentarios);
                        }
                    ?>
                </article>
            </section>

            </div>
            <aside class = "public">
                <?php                   
                    Control::publicidad();
                    //Persistence::generarComentariosTMP();
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