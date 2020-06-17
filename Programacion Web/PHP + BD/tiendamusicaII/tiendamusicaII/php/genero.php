
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
            include('classGenero.php')
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
                <article class ="img">
                    <?php echo '<img class = "pequeña_cartel" src="../img/'.$_GET['genero'].'.png" alt="">'; ?>
                </article>
                <article class ="text_titulo">
                    <h1><?php echo '"'.$_GET['genero'].'"';?></h1>
                </article>
            </section>

            <section class = "portal">
                <article>
                    <article class ="mas_vendido">
                        <?php
                            Genero::masValorado($_GET['genero']);
                        ?>
                    </article>

                    <article class = "discos">
                        <?php
                            Genero::ultimosDiscosGenero($_GET['genero']);
                        ?>
                        
                    </article>

                </article>

                <article class = "novedades">
                    <?php  
                        echo '<!-- Ultimo disco -->
                        <article class ="discoNovedades">';

                            Genero::ultimosDiscosNoticias($_GET['genero']);
                        
                        echo '</article>';
                    ?>
                </article>

            </section>

            </div>
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