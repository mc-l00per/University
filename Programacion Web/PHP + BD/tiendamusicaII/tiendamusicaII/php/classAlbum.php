
<?php 
/**
* clase para generar el desarrollo de los discos
*/
class Album
{
    function ultimosDiscosNoticias($genero){
            $ultimosTresDiscos=Control::ultimosDiscosGeneroDiscos($genero, 5);
            echo '<h1>NOVEDADES</h1><br/>';
            for ($i=0; $i < 3; $i++) { 
                echo '<article class ="disco">';
                    Album::discoNoticias($ultimosTresDiscos[$i], 1);
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

        function valorarDescarga(){
            echo '<article class = "valor">
                <input class = "valor" type="checkbox" name="transporte" value="1">
                <br>
                <input class = "valor" type="checkbox" name="transporte" value="2">
                <br>
                <input class = "valor" type="checkbox" name="transporte" value="3">
                <input class = "valor" type="checkbox" name="transporte" value="4">
                <input class = "valor" type="checkbox" name="transporte" value="5">
            </article>
            <article class = "descarga">
                <button class = "botton_aceptar"><img class = "botton" src="../img/download.png" alt="hola"></button>
            </article>';
        }
    
}
?>