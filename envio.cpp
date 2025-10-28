#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para envio
struct Envio {
    int id;
    string cliente;     // nombre de usuario que solicita
    string direccion;
    string descripcion;
    string estado;      // "Pendiente", "Asignado", "En Transito", "Entregado"
};

// almacenamiento en memoria
static vector<Envio> envios;
static int siguienteId = 1;

// Prototipo de función que usa envio para validar usuario (está definido en usuario.cpp)
// Declaramos para poder usarlo sin header
bool autenticarUsuario(const string& nombre, const string& contrasena);

// Crear solicitud de envio
void crearEnvio() {
    Envio e;
    e.id = siguienteId++;
    cout << "\n=== Crear solicitud de envio ===\n";
    cout << "Nombre de usuario (cliente): ";
    getline(cin, e.cliente);
    if (e.cliente.empty()) {
        cout << "Cliente no puede estar vacio.\n";
        return;
    }
    cout << "Direccion de recoleccion: ";
    getline(cin, e.direccion);
    cout << "Descripcion del paquete: ";
    getline(cin, e.descripcion);

    e.estado = "Pendiente";
    envios.push_back(e);
    cout << "✅ Solicitud creada. ID = " << e.id << " Estado = " << e.estado << "\n";
}

// Listar todos los envios
void listarEnvios() {
    cout << "\n=== Lista de envios ===\n";
    if (envios.empty()) {
        cout << "No hay envios registrados.\n";
        return;
    }
    for (const auto &e : envios) {
        cout << "ID: " << e.id
             << " | Cliente: " << e.cliente
             << " | Direccion: " << e.direccion
             << " | Estado: " << e.estado << "\n    Desc: " << e.descripcion << "\n";
    }
}

// Listar envios por usuario
void listarEnviosPorUsuario(const string& nombre) {
    cout << "\n=== Envios de " << nombre << " ===\n";
    bool found = false;
    for (const auto &e : envios) {
        if (e.cliente == nombre) {
            found = true;
            cout << "ID: " << e.id
                 << " | Direccion: " << e.direccion
                 << " | Estado: " << e.estado << "\n    Desc: " << e.descripcion << "\n";
        }
    }
    if (!found) cout << "No se encontraron envios para ese usuario.\n";
}

// Cambiar estado de un envio (usado por admin)
bool cambiarEstadoEnvio(int id, const string& nuevoEstado) {
    for (auto &e : envios) {
        if (e.id == id) {
            e.estado = nuevoEstado;
            return true;
        }
    }
    return false;
}
