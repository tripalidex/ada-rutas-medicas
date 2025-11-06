# ada-rutas-medicas
Actividad grupal de la semana 12 del curso Análisis y Diseño de Algoritmos.
https://github.com/tripalidex/ada-rutas-medicas.git

### Modulo: Nodos (Centros medicos) Participante: Juan Pablo Zavala Valle

Mi trabajo en el proyecto fue básicamente implementar la gestión de agregar y eliminar centros médicos(nodos) dentro del código del grafo. 

Funcionalidades implementadas:

**Función `estaVacio`**
* Comprueba si el grafo tiene al menos un centro médico registrado.
* Retorna verdadero si no existen vértices creados.
* Complejidad: O(1). Solo compara un puntero con nullptr.

**Función `insertarVertice`**
* Crea un nuevo vértice con los datos del centro médico (ID, nombre, tipo y dirección).
* Verifica que el ID no exista y lo agrega al final de la lista de vértices.
* Complejidad: O(v). LLama a buscarVerice(id), reccoriendo todos los vertices para verificar duplicados (V).

**Función `buscarVertice`**
* Recorre la lista de vértices para localizar un centro médico por su ID.
* Devuelve el vértice encontrado o `nullptr` si no existe.
* Complejidad: O(v). Recorre también toda la lista de vertices hasta encontrar coincidencias (V).

**Función `eliminarVertice`**
* Localiza y elimina un centro médico según su ID, junto con todas las rutas que lo referencian.
* Ajusta los punteros de los vértices y libera la memoria correspondiente.
* Complejidad: O(v). Recorre también todos los vertices

**Función `mostrarCentros`**
* Recorre la lista de vértices del grafo.
* Muestra el ID, nombre, tipo y dirección de cada centro médico.
* Complejidad: O(v). Recorre también todos los vertices



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
