function validarCamposRegistroUser() {    
    if (!validarNombre()) {
        alert("Nombre incorrecto.");
    }else if (!validarApellidos()) {
        alert("Apellidos incorrectos");
    } else if (!validarNick()) {
        alert("El nick no es correcto");
    } else if (!validarKey()) {
        alert("Contraseña incorrecta");
    } else if (!validarCiudad()) {
        alert("Ciudad incorrecta");
    } else if (!validarCodPos()) {
        alert("Codigo postal incorrecto");
    } else if (!validarCorreo()) {
        alert("Email incorrecto");
    } else if (!validarDNI()) {
        alert("DNI incorrecto");
    } else if (!validaCard1()) {
        alert("CAR1 incorrecto");
    } else if (!validaCard2()) {
        alert("CAR2 incorrecto");
    } else if (!validaCard3()) {
        alert("CAR3 incorrecto");
    } else if (!validaCard4()) {
        alert("CAR4 incorrecto");
    } else if (!validarEnvio()) {
        alert("Envio incorrecto");
    } else if (!validarCondiciones()) {
        alert("Condiciones no aceptadas");
    } else {
        alert("Todos los datos introducidos son correctos.");
    }
}
            
function validarNombre(){
    var nombre = document.getElementById("nombre").value;
    if( nombre === null || nombre.length === 0 ) {
      return false;
    }else{
        return true;
    } 
}

function validarApellidos(){
    var apellidos = document.getElementById("apellidos").value;
    if( apellidos === null || apellidos.length === 0 ) {
      return false;
    }else{
        return true;
    } 
}

function validarNick(){
    var nick = document.getElementById("nick").value;
    if( nick === null || nick.length === 0 ) {
      return false;
    }else{
        return true;
    } 
}

function validarKey(){
    var key = document.getElementById("key").value;
    if( key === null || key.length === 0 ) {
      return false;
    }else{
        return true;
    } 
}

function validarCiudad(){
    var ciudad = document.getElementById("ciudad").value;
    if( ciudad === null || ciudad.length === 0 ) {
      return false;
    }else{
        return true;
    } 
}

function validarCodPos() {   
    var postal = document.getElementById("postal").value;
    var xpostal = /\d{5}$/g;
            
    if (xpostal.test(postal)) {
        return true;
    } else {
        return false;
    }
}
        
function validarCorreo() {
    var email = document.getElementById("email").value;
    var erCorreo = /^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/g;
    
    if (erCorreo.test(email)) {
        return true;
    } else {
        return false;
    }
}

function validarDNI() {
    valor = document.getElementById("dni").value;
    var letras = ['T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E', 'T'];
     
    if( !(/\d{8}[A-Z]$/.test(valor)) ) {
        return true;
    }
     
    if(valor.charAt(8) != letras[(valor.substring(0, 8))%23]) {
        return false;
      }else{
        return true;
}
}

function validaCard1() {
    var car1 = document.getElementById("car1").value;
    var xcar1 = /\d{2}$/g;
            
    if (xcar1.test(car1)) {
        return true;
    } else {
        return false;
    }
}

function validaCard2() {
    var car2 = document.getElementById("car2").value;
    var xcar2 = /\d{4}$/g;
            
    if (xcar2.test(car2)) {
        return true;
    } else {
        return false;
    }
}

function validaCard3() {
    var car3 = document.getElementById("car3").value;
    var xcar3 = /\d{3}$/g;
            
    if (xcar3.test(car3)) {
        return true;
    } else {
        return false;
    }
}

function validaCard4() {
    var car4 = document.getElementById("car4").value;
    var xcar4 = /\d{6}$/g;
            
    if (xcar4.test(car4)) {
        return true;
    } else {
        return false;
    }
}
    
function validarCondiciones(){
    var condicones = document.getElementById("transporte");
    if (condicones.checked) {
        return true;
    } else {
        return false;
    }
}

function validarEnvio() { 
    opciones = document.getElementsByName("envio");
    var seleccionado = false;
    for(var i=0; i<opciones.length; i++) {    
        if(opciones[i].checked) {
            seleccionado = true;
            break;
        }
    }
     
    if(!seleccionado) {
        return false;     
    }
    else
        return true;   
}
