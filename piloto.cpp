// piloto.cpp
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
void listarPedidosPorPiloto(const string& piloto);
bool cambiarEstadoPedido(int id, const string& nuevoEstado);

void menuPiloto(const string& usuarioActual) {
    int op;
    do {
        clearScreen();
        header("MENU PILOTO (" + usuarioActual + ")");

        cout << "1. Ver pedidos asignados\n";
        cout << "2. Marcar pedido como Finalizado\n";
        cout << "0. Volver\n";

        op = readInt("Seleccione: ");

        if (op == 1) {
            listarPedidosPorPiloto(usuarioActual);
            pauseEnter();
        }
        else if (op == 2) {
            int id = readInt("ID del pedido a finalizar: ");
            if (cambiarEstadoPedido(id, "Finalizado"))
                cout << "Pedido " << id << " puesto en Finalizado.\n";
            else
                cout << "No se encontro el pedido o no esta asignado a usted.\n";
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
