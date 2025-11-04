#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vertice; // Declaración adelantada, ya que Arista hace referencia a Vertice

class Arista {
private:
    double distancia;       // Distancia (km)
    string tipoRuta;        // Tipo de ruta (vehicular, peatonal, ambulancia, etc.)
    bool estadoRuta;        // Estado de la ruta (true para activa, false para inactiva)

    // Punteros para la estructura del grafo
    Arista *sig;   // Siguiente arista para el mismo vértice de origen
    Vertice *dest; // Puntero al vértice de destino

    friend class Grafo; // La clase Grafo tendrá acceso a los miembros privados de Arista

public:
    // Constructor
    Arista(Vertice *_dest, double _distancia, string _tipoRuta, bool _estadoRuta = true);

    // Getters para acceder a los datos
    Vertice *getDestino() const { return dest; }
    double getDistancia() const { return distancia; }
    string getTipoRuta() const { return tipoRuta; }
    bool getEstadoRuta() const { return estadoRuta; }

    // Setters para modificar el estado si es necesario
    void setEstadoRuta(bool nuevoEstado) { estadoRuta = nuevoEstado; }
    void setDistancia(double nuevaDistancia) { distancia = nuevaDistancia; }
};

// Implementación del constructor
Arista::Arista(Vertice *_dest, double _distancia, string _tipoRuta, bool _estadoRuta)
{
    dest = _dest;
    distancia = _distancia;
    tipoRuta = _tipoRuta;
    estadoRuta = _estadoRuta; // Por defecto, una ruta es activa
    sig = NULL;
}