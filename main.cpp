// main.cpp
#include <iostream>
#include <string>
using namespace std;

// Prototipos de funciones (definidas en otros archivos)
void inicializarUsuariosDemo();
string autenticarYObtenerRol(const string& nombre, const string& contrasena);

// Menús por rol
void menuAdmin(const string& usuarioActual);
void menuControlador(const string& usuarioActual);
void menuPiloto(const string& usuarioActual);
void menuCliente(const string& usuarioActual);

// Funciones de envio
int crearPedido(const string& cliente, const string& direccion, float peso, const string& metodoPago);
void mostrarResumenUltimoPedido();
void listarPedidos();
void listarUsuariosSimple();

int main() {
    inicializarUsuariosDemo();

    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "=====================================\n";
        cout << "      MENU PRINCIPAL DEL SISTEMA     \n";
        cout << "=====================================\n";
        cout << "1. Registrar nuevo pedido (sin login)\n";
        cout << "2. Ver resumen del ultimo pedido\n";
        cout << "3. Vista Administrador (login)\n";
        cout << "4. Vista Controlador (login)\n";
        cout << "5. Vista Piloto (login)\n";
        cout << "6. Vista Cliente (login)\n";
        cout << "7. Listar usuarios de prueba\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string cliente, direccion, metodo;
            float peso;
            cout << "Nombre cliente: "; getline(cin, cliente);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Peso (libras): "; cin >> peso; cin.ignore();
            cout << "Metodo de pago: "; getline(cin, metodo);
            int id = crearPedido(cliente, direccion, peso, metodo);
            cout << "Pedido creado con ID: " << id << "\n";
            continue;
        } else if (opcion == 2) {
            mostrarResumenUltimoPedido();
            continue;
        }

        switch (opcion) {
            case 3: { // Admin
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "admin") menuAdmin(u);
                else cout << "Credenciales invalidas o no es admin.\n";
                break;
            }
            case 4: { // Controlador
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "controlador") menuControlador(u);
                else cout << "Credenciales invalidas o no es controlador.\n";
                break;
            }
            case 5: { // Piloto
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "piloto") menuPiloto(u);
                else cout << "Credenciales invalidas o no es piloto.\n";
                break;
            }
            case 6: { // Cliente
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "cliente") menuCliente(u);
                else cout << "Credenciales invalidas o no es cliente.\n";
                break;
            }
            case 7:
                listarUsuariosSimple();
                break;
            case 0:
                salir = true;
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
