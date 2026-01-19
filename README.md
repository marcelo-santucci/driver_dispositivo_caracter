# Driver para Dispositivo de Caracter

Un controlador de dispositivo funciona como un traductor entre el sistema operativo y los dispositivos de hardware.  En esencia, permite que el kernel interactúe con el hardware sin necesidad de comprender los detalles complejos del dispositivo. Existen varios tipos de controladores de dispositivo en Linux:

+Controladores de caracteres: Interactúan con dispositivos que leen y escriben datos en un flujo de caracteres.
+Controladores de bloque: Trabajan con dispositivos que gestionan bloques de datos, como discos duros.
+Controladores de red: Gestionan la comunicación entre el sistema operativo y los dispositivos de red.

A continuación podras efectuar el proceso de compilación, carga y verificación de un Driver para con Controlador de caracteres.

## Compilación del Driver

Primero debes preparar el ambiente para poder compilar el Driver, para ello debes instalar los paquetes y librerias necesarias a la versión de sistema operativo donde estas trabajando, mediante el comando:
+sudo apt-get install build-essential linux-headers-$(uname -r)

Para compilar el driver usa el comando:
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

### Desinstalación del Driver
Para desinstalar el driver se hace uso del comando:
+sudo rmmod driver_dispositivo_simple_de_caracter
