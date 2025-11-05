# ada-rutas-medicas
Actividad grupal de la semana 11 del curso Análisis y Diseño de Algoritmos

### Modulo: Aristas (Rutas Medicas) Participante: Moises Sacsara Munaylla

Mi parte del proyecto consistió en implementar la gestión de **rutas médicas** dentro del grafo.  
Cada **ruta (arista)** conecta dos **centros medicos (vértices)** y almacena información relevante como distancia, tipo de ruta y estado (activa o inactiva).

### Funcionalidades implementadas:

1. **Agregar una ruta (`agregarRuta`)**
   - Crea una conexión entre dos centros medicos.
   - Registra la distancia y el tipo de ruta (vehicular, peatonal, ambulancia, etc.).
   - Inserta la nueva arista al final de la lista de rutas del centro origen.
   - Complejidad: **O(v + a)**.

2. **Eliminar una ruta (`eliminarRuta`)**
   - Busca y elimina la conexión entre dos centros existentes.
   - Libera la memoria de la arista eliminada y ajusta los punteros.
   - Complejidad: **O(v + a)**.

###  Resumen
Mi implementación permite gestionar las rutas entre centros medicos, garantizando la correcta creacion y eliminación de las conexiones entre nodos del grafo.
