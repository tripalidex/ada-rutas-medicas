#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Arista; // Declaración adelantada para evitar problemas de dependencia circular

// Estructura para representar las especialidades
struct Especialidad {
    string nombre;
    // Podrías añadir más detalles si quisieras, como una descripción o un código
};

class Vertice {
private:
    // Datos del centro médico
    string idCentro;                                // ID del centro (numérico o alfanumérico)
    string nombreCentro;                            // Nombre del centro médico
    string tipoCentro;                              // Tipo de centro (consultorio, hospital, laboratorio, etc.)
    string direccion;                               // Dirección o ubicación
    vector<Especialidad> especialidadesDisponibles; // Lista de especialidades médicas
    string horarioAtencion;                         // Horario de atención (e.g., "L-V 9-18")

    // Punteros para la estructura del grafo
    Vertice *sig; // Siguiente vértice en la lista de vértices
    Arista *ari;  // Primera arista que sale de este vértice

    friend class Grafo; // La clase Grafo tendrá acceso a los miembros privados de Vertice

public:
    // Constructor
    Vertice(string id, string nombre, string tipo, string dir);

    // Métodos para añadir y obtener información (opcional, pero buena práctica)
    void addEspecialidad(const Especialidad &esp);
    void setHorarioAtencion(const string &horario);

    // Getters para acceder a los datos
    string getIdCentro() const { return idCentro; }
    string getNombreCentro() const { return nombreCentro; }
    string getTipoCentro() const { return tipoCentro; }
    string getDireccion() const { return direccion; }
    const vector<Especialidad> &getEspecialidadesDisponibles() const { return especialidadesDisponibles; }
    string getHorarioAtencion() const { return horarioAtencion; }
};

// Implementación del constructor
Vertice::Vertice(string id, string nombre, string tipo, string dir) {
    idCentro = id;
    nombreCentro = nombre;
    tipoCentro = tipo;
    direccion = dir;
    sig = NULL;
    ari = NULL;
    // Las especialidades y el horario se inicializan vacíos por defecto
}

// Implementación de los métodos adicionales
void Vertice::addEspecialidad(const Especialidad &esp) {
    especialidadesDisponibles.push_back(esp);
}

void Vertice::setHorarioAtencion(const string &horario) {
    horarioAtencion = horario;
}