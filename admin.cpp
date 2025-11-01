// admin.cpp
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

// Prototipos (envio.cpp)
void listarPedidos();
void setTarifaBase(float t);
void setLimiteLibras(float l);
void setPrecioPorLibraExtra(float p);
float getTarifaBase();
float getLimiteLibras();
float getPrecioPorLibraExtra();
bool agregarUsuario(const string& nombre, const string& contrasena, const string& rol);
void listarUsuariosSimple();

void menuAdmin(const string& usuarioActual) {
    int op;
    do {
        clearScreen();
        header("MENU ADMINISTRADOR (" + usuarioActual + ")");

        cout << "1. Ver todos los pedidos\n";
        cout << "2. Configurar tarifas\n";
        cout << "3. Crear usuario de prueba\n";
        cout << "4. Ver usuarios\n";
        cout << "0. Volver\n";

        op = readInt("Seleccione: ");

        if (op == 1) {
            listarPedidos();
            pauseEnter();
        } 
        else if (op == 2) {
            cout << "Tarifa base actual: Q" << getTarifaBase() << "\n";
            cout << "Limite libras actual: " << getLimiteLibras() << "\n";
            cout << "Precio por libra extra actual: Q" << getPrecioPorLibraExtra() << "\n";

            cout << "Ingrese nueva tarifa base (o vacio/0 para mantener): ";
            { string s; getline(cin, s); if (!s.empty()) try{ float v=stof(s); if(v>0) setTarifaBase(v);}catch(...){} }

            cout << "Ingrese nuevo limite de libras (o vacio/0 para mantener): ";
            { string s; getline(cin, s); if (!s.empty()) try{ float v=stof(s); if(v>0) setLimiteLibras(v);}catch(...){} }

            cout << "Ingrese nuevo precio por libra extra (o vacio/0 para mantener): ";
            { string s; getline(cin, s); if (!s.empty()) try{ float v=stof(s); if(v>0) setPrecioPorLibraExtra(v);}catch(...){} }

            cout << "Configuracion actualizada.\n";
            pauseEnter();
        } 
        else if (op == 3) {
            string nombre, pass, rol;
            cout << "Nombre nuevo usuario: "; getline(cin, nombre);
            cout << "Contrasena: "; getline(cin, pass);
            cout << "Rol (admin/controlador/piloto/cliente): "; getline(cin, rol);
            if (agregarUsuario(nombre, pass, rol)) cout << "Usuario creado.\n";
            else cout << "Error: el usuario ya existe.\n";
            pauseEnter();
        } 
        else if (op == 4) {
            listarUsuariosSimple();
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
