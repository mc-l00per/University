
<?php 

    /**
    * clase que contiene las propiedades del indice
    */
    class Index {
        /*
        muestra las tres novedades en la cabecera del titulo
        */        
        public static function areaNoticia(){
            $ultimosTresDiscos = Control::ultimosDiscos(3);
            for ($i=0; $i < 3; $i++) { 
                echo '<!-- Primer disco -->
                <article class ="disco">';
                    Index::disco($ultimosTresDiscos[$i], 8);
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

        function nuevaNoticia(){

        }

        function tabla(){
            echo '<article class ="disco">
                <table>
                    <!-- Titulo de la tabla -->
                    <thead>
                        <tr>
                            <th>Nuevas Noticias</th>
                        </tr>
                    </thead>

                    <!-- Cuerpo de la tabla -->
                    <tbody>';
                    $noticias=Control::obtenerNoticias(5);
                    for ($i=0; $i < 5; $i++) { 
                        echo '<tr>
                            <td>';
                                echo $noticias[$i];
                            echo '</td>
                        </tr>';
                    }
                    echo '</tbody>
                </table>
            </article>';
        }

        function disco_area(){
            $ultimosTresDiscos = Control::ultimosDiscos(3);
            for ($i=0; $i < 3; $i++) { 
                echo '<article class = "area_noticia">
                        <article class ="disco">
                            <article class = "caratula">
                                <img class = "mediana" src="'.$ultimosTresDiscos[$i]->caratula.'" alt="">
                            </article>
                            <article class ="play">
                                <a href="disco.php?idDisco='.$ultimosTresDiscos[$i]->idDisco.'">
                                    <img class = "pequeña" src="../img/ir_play.png" alt="">
                                </a>
                            </article>
                        </article>  
                    </article>';
            }
        }

        function ultimosDiscosGenero($genero){
            $ultimosTresDiscos=Control::ultimosDiscosGenero($genero, 3);
            for ($i=0; $i < 3; $i++) { 
                echo '<article class ="disco">';
                    Index::disco($ultimosTresDiscos[$i], 5);
                echo '</article>';
            }
        }

        function ultimosDiscosNoticias($genero){
            $ultimosTresDiscos=Control::ultimosDiscosGenero($genero, 5);
            for ($i=0; $i < 3; $i++) { 
                echo '<article class ="disco">';
                    Index::discoNoticias($ultimosTresDiscos[$i], 1);
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

    } 

?>