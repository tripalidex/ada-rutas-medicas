#include "grafo.h"

int main() {
    Grafo g;

    g.insertarVertice("C001", "Hospital Nacional", "Hospital", "Av. Salud 123");
    g.insertarVertice("C002", "Laboratorio Central", "Laboratorio", "Jr. Biología 456");
    g.insertarVertice("C003", "Clinica Primavera", "Clínica", "Av. Flores 789");

    g.mostrarCentros();

    vector<string> idsEliminar = {"C001", "C003"};

    for(const string &id : idsEliminar) {

        cout << "\n--- Eliminando centro " << id << "---\n";
        g.eliminarVertice(id);
    }

    cout << endl;
    g.mostrarCentros();

    return 0;
}
