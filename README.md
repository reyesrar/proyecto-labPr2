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

#### Funciones de Usuario: Cliente
- Compra de libros.
    - Libro debe ser introducido usando "_" para separar espacios en el titulo.
- Retiro de libros.
    - Mismas instrucciones al momento de comprar un libro.
    - Tipo de usuario reemplazado a "s" para suspender al cliente al no devolver al libro.

#### Por Implementar
- Acciones de sistema.
    - Guardar.
    - Modificar.
    - Eliminar.
- Funciones unicas por tipo de usuario.
    - Cliente: Suspencion al no Devolver el Libro.
- Registro de nuevos usuarios.