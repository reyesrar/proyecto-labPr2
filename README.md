### Sistema Administrativo para Biblioteca
---

#### Sistema de Inicio de Sesion
- Archivo .csv donde se almacenan los usuarios y contrasenas y tipo de usuario.
    - Cliente.
    - Empleado.
    - Administrador.
- Implementacion de funion login para inicio de sesion.
    - Compara usuario y contrasena con la fila de usuario y su contrasena en users.csv.
- Comprobacion de tipo de usuario.

#### Sistema de Creacion de Usuarios
- Usuario puede contener mayusculas y minusculas.
    - Usuario no puede contener caracteres especiales, exceptuando (_).
- Contrasena minimo debe contener 8 caracteres.
    - Contrasena puede contener letras y numeros.
    - Contrasena no puede contener caracteres especiales, exceptuando (_).

#### Funciones de Usuario: Cliente
- Compra de libros.
    - Libro debe ser introducido usando "_" para separar espacios en el titulo.
- Retiro de libros.
    - Mismas instrucciones al momento de comprar un libro.
    - Tipo de usuario reemplazado a "s" para suspender al cliente al no devolver al libro.
    - Cada usuario solo puede poseer un libro a la vez.
    - Para retirar otro libro, debe devolver el libro retirado anteriormente.
- Devolucion de libros.
    - Sistema regresa automaticamente el libro retirado.
    - No es necesario introducir nombre de el libro, sistema retorna libro almacenado en users.csv.
- Suspension de cliente.
    - Al no devolver un libro antes de cerrar sesion, el cliente es suspendido;

#### Funciones de Usuario: Empleado
- Agregar Libros.
    - Titulo y Autor deben ser introducidos sin caracteres especiales y separados por "_".
- Eliminar Libros.
    - Al ingresar el nombre de el libro, este es eliminado del sistema.
- Modificar Libros.
    - Modificacion de titulo, autor y estado de el libro.
    - Espacios deben ser reemplazados con "_".

#### Funciones de Administrador
- Funciones de Empleado.
- Funciones de Cliente.
- Funciones Unicas.
    - Creacion de usuarios tipo empleado y tipo administrador.
    - Eliminacion de usuarios tipo empleado, cliente y suspendido.

#### Problemas Conocidos
- Al un cliente devolver un libro sin este tener un libro almacenado.
    - Archivo Temporal no se borra.
    - Archivo Temporal al ser creado con mismo nombre y ser sobreescrito, no parece generar errores.
- No hay aviso sobre Usuario y Contrasena no deben poseer caracteres especiales.