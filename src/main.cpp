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
    state_scrolling_2 = mostrar_texto;
    
    for(u_int i=0;i<=max_length;i++)
    {
        espacios+=" ";//espacios= espacios+" "
    }
    texto1=espacios+texto1;
    texto2=espacios+texto2;

    text1_length= texto1.length();
    text2_length= texto2.length();
}

void loop() {




switch (state_scrolling_1)
{
case mostrar_texto:

    Serial.println(subTexto1);
    state_scrolling_1=esperar;
    espera1=millis();
    break;

case esperar:
    
    millis()>=(espera1+500) ? state_scrolling_1=scroll:state_scrolling_1=esperar;

    break;

case scroll:
    offset1++;
    if(offset1>text1_length-max_length)offset1=0;
    subTexto1= texto1.substring(offset1,min(offset1+max_length, text1_length));
    state_scrolling_1=mostrar_texto;
    break;

default:
    Serial.print("ha ocurrido un error");
    break;
}  

//aca empieza la segunda máquina

switch (state_scrolling_2)
{
case mostrar_texto:

    Serial.println(subTexto2);
    // Serial.println(texto1);
    state_scrolling_2=esperar;
    // espera_flag_1=false;
    espera2=millis();
    break;

case esperar:
    
    millis()>=(espera2+1000) ? state_scrolling_2=scroll:state_scrolling_2=esperar;

    break;

case scroll:
    offset2++;
    if(offset2>text2_length-max_length)offset2=0;
    subTexto2= texto2.substring(offset2,min(offset2+max_length, text2_length));
    state_scrolling_2=mostrar_texto;
    break;

default:
    Serial.print("ha ocurrido un error");
    break;
}  
//esto es un comentario de prueba 

}
