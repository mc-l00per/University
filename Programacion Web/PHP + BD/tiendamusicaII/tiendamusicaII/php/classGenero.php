
<?php 

    /**
    * clase que recoge toda la informacion para desarrollar las web de genero
    */
    class Genero
    {
        function ultimosDiscosNoticias($genero){
            $ultimosTresDiscos=Control::ultimosDiscosGeneroDiscos($genero, 5);
            echo '<h1>NOVEDADES</h1><br/>';
            for ($i=0; $i < 5; $i++) { 
                echo '<article class ="disco">';
                    Genero::discoNoticias($ultimosTresDiscos[$i], 1);
                echo '</article>';
            }
        }

        function discoNoticias($disco, $num_com){
            echo '<article class = "caratula">
                <img class = "mediana" src="'.$disco->caratula.'" alt="">
            </article>
            <article class ="play">
                <a href="disco.php?idDisco='.$disco->idDisco.'">
                    <img class = "pequeña" src="../img/ir_play.png" alt="">
                </a>
            </article>';    
        }

        function discoMasValorado($disco){
            echo '<img class = "grande" src="'.$disco->caratula.'" alt="">';
            echo '<article class ="comentarios">
                <ol>';
                $comentarios=Control::obtenerComentarios($disco->idDisco, 5);
                for ($i=0; $i < 5; $i++) { 
                    echo "<li>".$comentarios[$i]."</li>";
                }
                echo '</ol>
            </article>';
        }

        function masValorado($genero){
            $disco=Control::masValorado($genero);
            Genero::discoMasValorado($disco);
        }

        function ultimosDiscosGenero($genero){
            $ultimosDiscos=Control::ultimosDiscosGeneroDiscos($genero, 6);
            for ($i=0; $i < 6; $i++) { 
                echo '<article class ="disco">';
                    Genero::disco($ultimosDiscos[$i], 5);
                echo '</article>';
            }
        }

        function disco($disco, $num_com){
            echo '<article class = "caratula">
                <img class = "mediana" src="'.$disco->caratula.'" alt="">
            </article>
            <article class ="comentarios">
                <ol>';
                $comentarios=Control::obtenerComentarios($disco->idDisco, $num_com);
                for ($i=0; $i < $num_com; $i++) { 
                    echo "<li>".$comentarios[$i]."</li>";
                }
                echo '</ol>
            </article>
            <article class ="play">
                <a href="disco.php?idDisco='.$disco->idDisco.'">
                    <img class = "pequeña" src="../img/ir_play.png" alt="">
                </a>
            </article>';    
        }
        
    } 

?>