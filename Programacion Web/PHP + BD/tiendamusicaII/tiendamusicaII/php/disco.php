
<!DOCTYPE html>

<!-- Cabecera de la pagina -->
<html>

    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="../styles.css"/>
        <link rel="shortcut icon" href="../img/head.png">
        <title src="img/head.png">Music</title>
        <!-- Includes de php para simplificar el codigo -->
        <?php
            session_start();            
            include('classControl.php');
            include('classAlbum.php');
            $disco=Control::obtenerIdDisco($_GET['idDisco']);
        ?>
    </head> 

    <body>
        <section class = "principal">
            <article class = "cabecera">
                <header class = "header">
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
                    <article class ="img">
                        <?php echo '<img class = "pequeña_cartel" src="../img/'.$disco->genero.'.png" alt="">'; ?>
                    </article>
                    <article class ="text_titulo">
                        <h1><?php echo '"'.$disco->genero.'"';?></h1>
                    </article>
                </section>
                <section class = "cuerpoAlbum">
                    <article>
                        <article class = "cartel">
                            <article class ="img">
                                <img class = "pequeña_cartel" src=<?php echo '"'.$disco->caratula.'"';?> alt="">
                            </article>
                            <article class ="text_titulo">
                                <h1><?php echo $disco->nombre;?></h1>
                            </article>
                        </article>
                        <article class = "discos">
                            <article class ="discoAlbum">
                                <article class = "caratula">
                                    <?php echo '<img class = "mediana" src="'.$disco->caratula.'" alt="">'; ?>
                                </article>
                                <article class ="lista">
                                    <form action="descarga.php" id="cancion">
                                        <?php
                                        for ($i=0; $i < count($disco->canciones); $i++) { 
                                            echo '<article class = "cancion">
                                                <input type="radio" name="transporte" value="1">"'.$disco->canciones[$i]->pista.'" 
                                                <audio class = "cancion" src="'.$disco->canciones[$i]->nombre.'" autobuffer autoloop loop controls></audio><br>
                                            </article>';
                                        }
                                            
                                        ?>
                                    </form>
                                </article>
                            </article>
                            <article class = "valor_descarga">
                                <?php Album::valorarDescarga() ?>
                            </article>
                        </article>
                    </article>
                    <article class = "novedadesDisco">                       
                        <?php  
                            echo '<!-- Ultimo disco -->
                            <article class ="discoNovedades">';
                            Album::ultimosDiscosNoticias($disco->genero);
                            echo '</article>';
                        ?>
                    </article>
                </section>
            </article>
            <aside class = "public">
                <?php                   
                    Control::publicidad();
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