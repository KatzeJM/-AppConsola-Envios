// cliente.cpp
#include <iostream>
#include <string>
using namespace std;

// Prototipos (envio.cpp)
int crearPedido(const string& cliente, const string& direccion, float peso, const string& metodoPago);
void listarPedidosPorCliente(const string& cliente);
void mostrarResumenUltimoPedido();

void menuCliente(const string& usuarioActual) {
    int op;
    do {
        cout << "\n--- MENU CLIENTE (" << usuarioActual << ") ---\n";
        cout << "1. Crear nuevo pedido\n";
        cout << "2. Ver mis pedidos\n";
        cout << "3. Ver resumen del ultimo pedido\n";
        cout << "0. Volver\n";
        cout << "Seleccione: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            string direccion, metodo;
            float peso;
            cout << "Direccion de recoleccion: "; getline(cin, direccion);
            cout << "Peso (libras): "; cin >> peso; cin.ignore();
            cout << "Metodo de pago: "; getline(cin, metodo);
            int id = crearPedido(usuarioActual, direccion, peso, metodo);
            cout << "Pedido creado con ID: " << id << "\n";
        } else if (op == 2) {
            listarPedidosPorCliente(usuarioActual);
        } else if (op == 3) {
            mostrarResumenUltimoPedido();
        } else if (op == 0) {
            cout << "Volviendo...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (op != 0);
}
