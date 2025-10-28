// piloto.cpp
#include <iostream>
#include <string>
using namespace std;

// Prototipos (envio.cpp)
void listarPedidosPorPiloto(const string& piloto);
bool cambiarEstadoPedido(int id, const string& nuevoEstado);

void menuPiloto(const string& usuarioActual) {
    int op;
    do {
        cout << "\n--- MENU PILOTO (" << usuarioActual << ") ---\n";
        cout << "1. Ver pedidos asignados\n";
        cout << "2. Marcar pedido como Finalizado\n";
        cout << "0. Volver\n";
        cout << "Seleccione: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            listarPedidosPorPiloto(usuarioActual);
        } else if (op == 2) {
            int id;
            cout << "ID del pedido a finalizar: "; cin >> id; cin.ignore();
            if (cambiarEstadoPedido(id, "Finalizado")) cout << "Pedido " << id << " puesto en Finalizado.\n";
            else cout << "No se encontro el pedido o no esta asignado a usted.\n";
        } else if (op == 0) {
            cout << "Volviendo...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (op != 0);
}
