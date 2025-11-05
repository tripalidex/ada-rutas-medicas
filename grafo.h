#pragma once
#include <iostream>
#include <string>
#include "vertice.h"
#include "arista.h"
using namespace std;

class Grafo {
private:
    Vertice *primero; // primer vértice del grafo

public:
    Grafo() { primero = nullptr; }

    bool estaVacio() const { return primero == nullptr; }

    // ? Insertar nuevo centro médico
    void insertarVertice(string id, string nombre, string tipo, string dir) {
        // Verificar si ya existe
        if (buscarVertice(id) != nullptr) {
            cout << "El centro con ID " << id << " ya existe.\n";
            return;
        }

        Vertice *nuevo = new Vertice(id, nombre, tipo, dir);

        if (estaVacio()) {
            primero = nuevo;
        } else {
            Vertice *aux = primero;
            while (aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nuevo;
        }
        cout << "Centro medico agregado correctamente: " << nombre << endl;
    }

        // Agregar una ruta entre dos centros medicos
    void agregarRuta(string idOrigen, string idDestino, double distancia, string tipoRuta, bool estadoRuta = true) {
        Vertice *origen = buscarVertice(idOrigen);
        Vertice *destino = buscarVertice(idDestino);

        if (origen == nullptr || destino == nullptr) {
            cout << "Error: uno o ambos centros no existen.\n";
            return;
        }

        // Crear la nueva arista (ruta)
        Arista *nueva = new Arista(destino, distancia, tipoRuta, estadoRuta);

        // Si el origen no tiene rutas aún
        if (origen->ari == nullptr) {
            origen->ari = nueva;
        } else {
            // Ir hasta el final de la lista de rutas del origen
            Arista *aux = origen->ari;
            while (aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nueva;
        }

        cout << "Ruta agregada: " << origen->nombreCentro << " -> "
             << destino->nombreCentro << " (" << distancia << " km, tipo: "
             << tipoRuta << ")\n";
    }


    Vertice* buscarVertice(string id) {
        Vertice *aux = primero;
        while (aux != nullptr) {
            if (aux->idCentro == id)
                return aux;
            aux = aux->sig;
        }
        return nullptr;
    }

    void eliminarVertice(string id) {
        if (estaVacio()) {
            cout << "No hay centros para eliminar.\n";
            return;
        }

        Vertice *actual = primero;
        Vertice *anterior = nullptr;

        while (actual != nullptr && actual->idCentro != id) {
            anterior = actual;
            actual = actual->sig;
        }

        if (actual == nullptr) {
            cout << "No se encontro un centro con ID " << id << ".\n";
            return;
        }

        Vertice *v = primero;
        while (v != nullptr) {
            Arista *a = v->ari;
            Arista *prevA = nullptr;
            while (a != nullptr) {
                if (a->getDestino() == actual) {
                    if (prevA == nullptr)
                        v->ari = a->sig;
                    else
                        prevA->sig = a->sig;
                    delete a;
                    break;
                }
                prevA = a;
                a = a->sig;
            }
            v = v->sig;
        }

        if (anterior == nullptr)
            primero = actual->sig;
        else
            anterior->sig = actual->sig;

        delete actual;
        cout << "Centro medico eliminado correctamente.\n";
    }

        // Eliminar una ruta entre dos centros medicos
    void eliminarRuta(string idOrigen, string idDestino) {
        Vertice *origen = buscarVertice(idOrigen);
        Vertice *destino = buscarVertice(idDestino);

        if (origen == nullptr || destino == nullptr) {
            cout << "Error: uno o ambos centros no existen.\n";
            return;
        }

        if (origen->ari == nullptr) {
            cout << "El centro origen no tiene rutas registradas.\n";
            return;
        }

        Arista *actual = origen->ari;
        Arista *anterior = nullptr;

        // Buscar la arista que conecta origen -> destino
        while (actual != nullptr && actual->getDestino() != destino) {
            anterior = actual;
            actual = actual->sig;
        }

        if (actual == nullptr) {
            cout << "No se encontró una ruta entre " << idOrigen << " y " << idDestino << ".\n";
            return;
        }

        // Eliminar la arista encontrada
        if (anterior == nullptr)
            origen->ari = actual->sig;
        else
            anterior->sig = actual->sig;

        delete actual;
        cout << "Ruta eliminada correctamente: " << idOrigen << " -> " << idDestino << endl;
    }


    void mostrarCentros() {
        if (estaVacio()) {
            cout << "No hay centros registrados.\n";
            return;
        }

        Vertice *aux = primero;
        cout << endl;
        cout << "Lista de centros medicos:\n";
        while (aux != nullptr) {
            cout << " - [" << aux->idCentro << "] " << aux->nombreCentro
                 << " (" << aux->tipoCentro << "), " << aux->direccion << endl;
            aux = aux->sig;
        }
    }
};
