#include <Arduino.h>
#include <LiquidCrystal.h>

#define DISPLAY_LENGTH 16
//ESTO ES UN COMENTARIO PARA MOSTRAR EL USO DE GITHUB
typedef enum {mostrar_texto, esperar, scroll}states_scrolling;
states_scrolling state_scrolling_1, state_scrolling_2;
String texto1="hola, estoy scroleando wiiiiiiiiiii aaaaa", texto2="debería ir pa' lotro lado ooooooohhhhhhh(sic) pero voy a la mitad de la velocidad";
String subTexto1, subTexto2;

int text1_length, text2_length;

int max_length= DISPLAY_LENGTH;

int offset1=0, offset2=0;


unsigned long espera1, espera2;

String espacios;

void setup() {

    Serial.begin(9600);
    state_scrolling_1 = mostrar_texto;
    // state_scrolling_2 = mostrar_texto;
    
    for(u_int i=0;i<=max_length;i)
    {
        espacios+=" ";//espacios= espacios+" "
    }
    texto1=espacios+texto1;
    texto2=espacios+texto2;

    text1_length= texto1.length();
    text2_length= texto2.length();
}

void loop() {




s
    break;

default:
    Serial.print("ha ocurrido un error");
    break;
}  
//esto es un comentario de prueba 

}
