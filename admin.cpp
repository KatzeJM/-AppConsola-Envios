#include <iostream>
#include <string>

using namespace std;

// Prototipos (funciones de otros módulos)
void listarUsuarios();
void listarEnvios();
bool cambiarEstadoEnvio(int id, const string& nuevoEstado);

// Simulacion de tarifa (solo un dato ejemplo)
static double tarifaBase = 10.0; // moneda arbitraria

// Mostrar resumen rapido (reportes simples)
void reporteResumen() {
    cout << "\n=== Reporte resumen (Admin) ===\n";

    // Cantidad de usuarios
    // No tenemos acceso directo al vector desde aqui sin header,
    // asi que pedimos al main/menu que muestre usuarios (listarUsuarios).
    cout << "-> Usuarios registrados (ver lista completa con 'listar usuarios')\n";

    // Cantidad de envios (llamamos a listarEnvios para mostrar detalle)
    cout << "-> Envios registrados (detalle):\n";
    listarEnvios();

    cout << "-> Tarifa base actual: " << tarifaBase << "\n";
}

// Asignar envio: preguntar ID y asignarlo (cambia estado)
void asignarEnvioAdmin() {
    int id;
    cout << "Ingrese ID del envio a asignar: ";
    cin >> id;
    cin.ignore();
    bool ok = cambiarEstadoEnvio(id, "Asignado");
    if (ok) cout << "Se asigno el envio ID " << id << ". Estado = Asignado\n";
    else cout << "No se encontro envio con ID " << id << "\n";
}
