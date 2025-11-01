// controlador.cpp
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
void listarPedidos();
bool asignarPedidoA(int id, const string& piloto);
void listarUsuariosSimple();
void listarPedidosPorPiloto(const string& piloto);

void menuControlador(const string& usuarioActual) {
    int op;
    do {
        clearScreen();
        header("MENU CONTROLADOR (" + usuarioActual + ")");

        cout << "1. Ver todos los pedidos\n";
        cout << "2. Ver pedidos iniciales\n";
        cout << "3. Asignar pedido a piloto\n";
        cout << "4. Ver pilotos y sus pedidos\n";
        cout << "0. Volver\n";

        op = readInt("Seleccione: ");

        if (op == 1) {
            listarPedidos();
            pauseEnter();
        }
        else if (op == 2) {
            cout << "\nPedidos con estado Inicial:\n";
            // En esta versión base mostramos todos; el usuario ve el estado "Inicial" en el listado.
            // Si luego quieres filtrar estrictamente, lo hacemos en envio.cpp.
            listarPedidos();
            pauseEnter();
        }
        else if (op == 3) {
            int id = 0;
            string piloto;
            id = readInt("ID del pedido a asignar: ");
            cout << "Nombre del piloto a asignar: ";
            getline(cin, piloto);

            if (asignarPedidoA(id, piloto))
                cout << "Pedido asignado a " << piloto << ".\n";
            else
                cout << "No se encontro el pedido con ID " << id << ".\n";

            pauseEnter();
        }
        else if (op == 4) {
            cout << "Pilotos registrados:\n";
            listarUsuariosSimple();
            cout << "Ingrese nombre del piloto para ver sus pedidos: ";
            {
                string p; getline(cin, p);
                cout << "\nPedidos del piloto " << p << ":\n";
                listarPedidosPorPiloto(p);
            }
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
