# -AppConsola-Envios
Esta es una aplicación de consola que busca emular un sistema de envio de paquetes, este es un proyecto de practica por lo que se manejam aspectos basicos de C++ 

|Credenciales de usuarios segun el rol, estas son credenciales por defecto con fin de poder manipular y probar el proyecto|

| Rol               | Usuario   | Contraseña | Descripción                                                           |
| ----------------- | --------- | ---------- | --------------------------------------------------------------------- |
| **Administrador** | `admin`   | `123`     | Puede configurar tarifas y ver todos los pedidos.                     |
| **Controlador**   | `control` | `123`     | Asigna pedidos a pilotos y cambia estado a “En curso” o “Finalizado”. |
| **Piloto**        | `piloto`  | `123`     | Ve los pedidos que tiene asignados.                                   |
| **Cliente**       | `cliente` | `123`     | Registra nuevos pedidos.                                              |


###  Compilación

Antes de compilar, asegúrate de estar ubicado en la carpeta raíz del proyecto.  
Luego, ejecuta el siguiente comando en tu terminal:

```bash
g++ *.cpp -o main.exe


| Parte      | Descripción                                                                                      |
| ---------- | ------------------------------------------------------------------------------------------------ |
| `g++`      | Es el compilador de C++ (parte del paquete GCC).                                                 |
| `*.cpp`    | Indica que deben compilarse **todos los archivos con extensión `.cpp`** en el directorio actual. |
| `-o`       | Opción que especifica el **nombre del archivo de salida (output)**.                              |
| `main.exe` | Es el **nombre del ejecutable generado** después de la compilación.                              |


Una vez complilado ejecutamos el .exe que se ha generado. 