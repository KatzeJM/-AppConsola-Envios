// main.cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ===== Utilidades locales =====
static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\x1B[2J\x1B[H";
#endif
}

static void pauseEnter(const string& msg = "Presione ENTER para continuar...") {
    cout << "\n" << msg;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static void header(const string& title) {
    string barra(title.size() + 8, '=');
    cout << barra << "\n"
         << "   " << title << "\n"
         << barra << "\n";
}

static int readInt(const string& prompt) {
    for (;;) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) return 0;
        try { return stoi(s); }
        catch (...) { cout << "Entrada invalida. Intente de nuevo.\n"; }
    }
}
// =================================

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

    bool salir = false;

    while (!salir) {
        clearScreen();
        header("MENU PRINCIPAL DEL SISTEMA");

        cout << "1. Registrar nuevo pedido (sin login)\n";
        cout << "2. Ver resumen del ultimo pedido\n";
        cout << "3. Vista Administrador (login)\n";
        cout << "4. Vista Controlador (login)\n";
        cout << "5. Vista Piloto (login)\n";
        cout << "6. Vista Cliente (login)\n";
        cout << "7. Listar usuarios de prueba\n";
        cout << "0. Salir\n";

        int opcion = readInt("\n Seleccione una opcion: ");
        cout << " \n";

        if (opcion == 1) {
            string cliente, direccion, metodo;
            float peso;
            cout << "---NUEVO PEDIDO---\n";
            cout << "Nombre cliente: "; getline(cin, cliente);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Peso (libras): ";
            {
                string s; getline(cin, s);
                try { peso = stof(s); } catch (...) { peso = 0; }
            }
            cout << "Metodo de pago: "; getline(cin, metodo);
            int id = crearPedido(cliente, direccion, peso, metodo);
            cout << "Pedido creado con ID: " << id << "\n";
            pauseEnter("Presione ENTER para volver al menu principal...");
            continue;
        } else if (opcion == 2) {
            mostrarResumenUltimoPedido();
            pauseEnter("Presione ENTER para volver al menu principal...");
            continue;
        }

        switch (opcion) {
            case 3: {
                string u, p;
                cout << "---LOGIN ADMIN---\n";
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "admin") menuAdmin(u);
                else { cout << "Credenciales invalidas o no es admin.\n"; pauseEnter(); }
                break;
            }
            case 4: {
                cout << "---LOGIN CONTROLADOR---\n";
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "controlador") menuControlador(u);
                else { cout << "Credenciales invalidas o no es controlador.\n"; pauseEnter(); }
                break;
            }
            case 5: {
                cout << "---LOGIN PILOTO---\n";
                string u, p;
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "piloto") menuPiloto(u);
                else { cout << "Credenciales invalidas o no es piloto.\n"; pauseEnter(); }
                break;
            }
            case 6: {
                string u, p;
                cout << "---LOGIN CLIENTE---\n";
                cout << "Usuario: "; getline(cin, u);
                cout << "Contrasena: "; getline(cin, p);
                string rol = autenticarYObtenerRol(u, p);
                if (rol == "cliente") menuCliente(u);
                else { cout << "Credenciales invalidas o no es cliente.\n"; pauseEnter(); }
                break;
            }
            case 7:
                listarUsuariosSimple();
                pauseEnter();
                break;
            case 0:
                salir = true;
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                pauseEnter();
        }
    }

    return 0;
}
