// admin.cpp
#include <iostream>
#include <string>
using namespace std;

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
        cout << "\n--- MENU ADMINISTRADOR (" << usuarioActual << ") ---\n";
        cout << "1. Ver todos los pedidos\n";
        cout << "2. Configurar tarifas\n";
        cout << "3. Crear usuario de prueba\n";
        cout << "4. Ver usuarios\n";
        cout << "0. Volver\n";
        cout << "Seleccione: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            listarPedidos();
        } else if (op == 2) {
            cout << "Tarifa base actual: Q" << getTarifaBase() << "\n";
            cout << "Limite libras actual: " << getLimiteLibras() << "\n";
            cout << "Precio por libra extra actual: Q" << getPrecioPorLibraExtra() << "\n";

            cout << "Ingrese nueva tarifa base (o 0 para mantener): ";
            float t; cin >> t; cin.ignore();
            if (t > 0) setTarifaBase(t);

            cout << "Ingrese nuevo limite de libras (o 0 para mantener): ";
            float l; cin >> l; cin.ignore();
            if (l > 0) setLimiteLibras(l);

            cout << "Ingrese nuevo precio por libra extra (o 0 para mantener): ";
            float p; cin >> p; cin.ignore();
            if (p > 0) setPrecioPorLibraExtra(p);

            cout << "Configuracion actualizada.\n";
        } else if (op == 3) {
            string nombre, pass, rol;
            cout << "Nombre nuevo usuario: "; getline(cin, nombre);
            cout << "Contrasena: "; getline(cin, pass);
            cout << "Rol (admin/controlador/piloto/cliente): "; getline(cin, rol);
            if (agregarUsuario(nombre, pass, rol)) cout << "Usuario creado.\n";
            else cout << "Error: el usuario ya existe.\n";
        } else if (op == 4) {
            listarUsuariosSimple();
        } else if (op == 0) {
            cout << "Volviendo al menu principal...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (op != 0);
}
