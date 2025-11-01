// cliente.cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ===== Utilidades locales (sin .h) =====
static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\x1B[2J\x1B[H"; // ANSI: limpia y mueve cursor a 1,1
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

// Leer enteros usando getline + stoi (evita mezclar >> con getline)
static int readInt(const string& prompt) {
    for (;;) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) return 0;
        try { return stoi(s); }
        catch (...) { cout << "Entrada invalida. Intente de nuevo.\n"; }
    }
}
// =======================================

// Prototipos (definidos en envio.cpp)
int crearPedido(const string& cliente, const string& direccion, float peso, const string& metodoPago);
void listarPedidosPorCliente(const string& cliente);
void mostrarResumenUltimoPedido();

void menuCliente(const string& usuarioActual) {
    int op;
    do {
        clearScreen();
        header("MENU CLIENTE (" + usuarioActual + ")");

        cout << "1. Crear nuevo pedido\n";
        cout << "2. Ver mis pedidos\n";
        cout << "3. Ver resumen del ultimo pedido\n";
        cout << "0. Volver\n";

        op = readInt("Seleccione: ");

        if (op == 1) {
            string direccion, metodo;
            float peso = 0.0f;

            cout << "Direccion de recoleccion: "; getline(cin, direccion);

            cout << "Peso (libras): ";
            {
                string s; getline(cin, s);
                try { peso = stof(s); } catch (...) { peso = 0.0f; }
            }

            cout << "Metodo de pago: "; getline(cin, metodo);

            int id = crearPedido(usuarioActual, direccion, peso, metodo);
            cout << "Pedido creado con ID: " << id << "\n";
            pauseEnter();
        }
        else if (op == 2) {
            listarPedidosPorCliente(usuarioActual);
            pauseEnter();
        }
        else if (op == 3) {
            mostrarResumenUltimoPedido();
            pauseEnter();
        }
        else if (op == 0) {
            // salir del submenú
        }
        else {
            cout << "Opcion invalida.\n";
            pauseEnter();
        }

    } while (op != 0);
}
