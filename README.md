Tercer proyecto - Reproductor Multimedia 
----

En esta ocasión veremos algunas de las capacidades multimedia de Qt5. Esta práctica permitirá reforzar los conocimientos adquiridos hasta ahora al tiempo que experimentamos con las características multimedia de Qt5.

Como mínimo, implementaremos las siguientes funcionalidades:

* Ventana con espacio para mostrar vídeo
* Botones básicos para abrir y controlar la reproducción de contenidos.
* Barra para navegar a lo largo del contenido.
* Control de volumen.

Modus operandi
----

1. Hacer un Fork de este proyecto para usarlo como referencia.
* Leer, probar y entender el código propuesto.
* Modificar el código para adaptarlo al estilo de cada uno.
* Estudiar la implementación de Qt para manejar sockets
* Descanso de 15 minutos
* Realizar las tareas propuestas para la clase

Tareas propuestas para realizar en clase
----

Se propone realizar las siguientes tareas:

* Añadir menú "Archivo" con opción para "Abrir" un archivo
* Añadir menú "Ayuda" con opción "Acerca de" (Heredar de QDialog)
* Añadir menú "Ver" con opción "Pantalla completa"
* Añadir opción "Recientes" al menú "Archivo"
* Añadir opción "Metadatos" en el menú "Ver"
* Añadir soporte para reproducir fuentes de streaming

Entrega
----

Todo el trabajo realizado en clase y/o en casa, debe ser subido a [GitHub].

Para subir nota, proponemos las siguientes tareas para casa:

* Añadir soporte para cargar y mostrar listas de reproducción [M3U] y/o [PLS]
* Añadir funciones de reproducción en bucle, reproducción aleatoria
* Implementar lo necesario para que el reproductor se minimize en la bandeja del sistema
* Añadir menú contextual al icono de bandeja del sistema
* Agregar menú "editar" con opción "imagen", que haga que aparezca un diálogo en el que se pueda modificar el brillo, constraste y saturación del vídeo
* Soporte para subtítulos Subrip (Srt)


*Nota: Se valorará el simple hecho de haberlo intentado, no tiene que ser todo perfecto, lo importante es que aprendas a "buscarte la vida" con la documentación de QT al tiempo que practicas el desarrollo con este framework.* 

Material de referencia
----

* [Documentación oficial de QT]
* [GIT - La guía sencilla]
* [GIT challenges]
* [GIT Cheat Sheet]


[Documentación oficial de QT]:http://qt-project.org/doc/
[GIT challenges]:http://try.github.io/levels/1/challenges/1
[GIT Cheat Sheet]:http://www.cheat-sheets.org/saved-copy/git-cheat-sheet.pdf
[GIT - La guía sencilla]:http://rogerdudler.github.io/git-guide/index.es.html
[GitHub]:https://github.com
[M3U]:http://en.wikipedia.org/wiki/M3U
[PLS]:http://en.wikipedia.org/wiki/PLS_(file_format)
