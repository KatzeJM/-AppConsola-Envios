// controlador.cpp
#include <iostream>
#include <string>
using namespace std;

// Prototipos (envio.cpp)
void listarPedidos();
bool asignarPedidoA(int id, const string& piloto);
void listarUsuariosSimple();
void listarPedidosPorPiloto(const string& piloto);

void menuControlador(const string& usuarioActual) {
    int op;
    do {
        cout << "\n--- MENU CONTROLADOR (" << usuarioActual << ") ---\n";
        cout << "1. Ver todos los pedidos\n";
        cout << "2. Ver pedidos iniciales\n";
        cout << "3. Asignar pedido a piloto\n";
        cout << "4. Ver pilotos y sus pedidos\n";
        cout << "0. Volver\n";
        cout << "Seleccione: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            listarPedidos();
        } else if (op == 2) {
            cout << "\nPedidos con estado Inicial:\n";
            // Mostramos todos y el usuario verá el estado "Inicial"
            listarPedidos();
        } else if (op == 3) {
            int id;
            string piloto;
            cout << "ID del pedido a asignar: "; cin >> id; cin.ignore();
            cout << "Nombre del piloto a asignar: "; getline(cin, piloto);
            if (asignarPedidoA(id, piloto)) cout << "Pedido asignado a " << piloto << "\n";
            else cout << "No se encontro el pedido con ID " << id << "\n";
        } else if (op == 4) {
            cout << "Pilotos registrados (ver lista):\n";
            listarUsuariosSimple();
            cout << "Ingrese nombre del piloto para ver sus pedidos: ";
            string p; getline(cin, p);
            listarPedidosPorPiloto(p);
        } else if (op == 0) {
            cout << "Volviendo...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (op != 0);
}
