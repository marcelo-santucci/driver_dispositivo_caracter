# Driver para Dispositivo de Caracter

Ejemplo para creación de un driver de dispositivo de caracteres simple.

## Compilación del Driver:
+ make

El proceso de compilación debe funcionar y no generar ningún error.  Luego puedes efectuar la verificación de que el proceso de compilación haya generado los archivos de resultado, deber encontrar un archivo con nombre "driver_dispositivo_simple_de_caracter.ko" al ejecutar el comando:
+ ls -ltrh

## Drivers Existentes

Tu sistema operativo ya tiene cargados varios drivers, para listarlos ejecuta el comando:
+cat /proc/devices

### Instalación del Driver
Para instalar el driver que acabas de crear ejecuta el comando:
+sudo insmod driver_dispositivo_simple_de_caracter.ko

Luego verifica nuevamente los drivers que esten cargados ahora en el sistema mediante el comando:
+cat /proc/devices

### Creación del dispositivo 
Para poder acceder a un dispositivo que haga uso del driver.  Primero, se crea el archivo del dispositivo dentro el directorio /dev
mediante el comando que se muestra a continuación donde el parámetro <Max_number> se determina de la información desplegada con el último comando.

+sudo mknod /dev/driver_dispositivo_simple_de_caracter c <Max_Number> 0

### Escritura en el dispositivo
Antes de poder escribir algo en el dispositivo necesitas verificar los permisos del archivo mediante el comando:
+ls -ltrh /dev/driver_dispositivo_simple_de_caracter

¿Que permisos notas que tiene el archivo?  Antes de poder escribir en el necesitas modificar los permisos mediante el comando:
+sudo chmod 666 /dev/driver_dispositivo_simple_de_caracter

#### Escribir en el dispositivo
Para escribir algo dentro del dispositivo (archivo) puedes hacer uso del comando:
+echo 'Hola Dispositivo' > /dev/driver_dispositivo_simple_de_caracter

Para verificar si efectivamente se consiguió escribir algo en el driver ejecuta el comando:
+cat /dev/driver_dispositivo_simple_de_caracter

```c

struct values{
  float num1;
  float num2;
  char operation;
};

/*Programa, versión y definición de procedimiento*/

program CALCULADORA{
  version CALCULADORA_VERS{
  float ADD(values)=1;
  float SUB(values)=2;
  float MUL(values)=3;
  float DIV(values)=4;
  } = 6; 
} = 456123789;
```
