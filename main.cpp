#include <iostream>
#include <string>

using namespace std;

// --- Prototipos (funciones que están en otros .cpp) ---
// Usuarios
void crearUsuario();
void listarUsuarios();
bool autenticarUsuario(const string& nombre, const string& contrasena);

// Envios
void crearEnvio();
void listarEnvios();
void listarEnviosPorUsuario(const string& nombre);

// Admin
void reporteResumen();
void asignarEnvioAdmin();

int main() {
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n===== ENVIOS GARANTIZADOS S.A. (CONSOLa) =====\n";
        cout << "1. Registrar usuario\n";
        cout << "2. Listar usuarios\n";
        cout << "3. Crear solicitud de envio\n";
        cout << "4. Listar todos los envios\n";
        cout << "5. Listar envios por usuario\n";
        cout << "6. Iniciar sesion (usuario) - para ver sus envios\n";
        cout << "7. Menu admin (reportes y asignar)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar newline

        switch (opcion) {
            case 1:
                crearUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
                crearEnvio();
                break;
            case 4:
                listarEnvios();
                break;
            case 5: {
                string nombre;
                cout << "Ingrese nombre de usuario para listar sus envios: ";
                getline(cin, nombre);
                listarEnviosPorUsuario(nombre);
                break;
            }
            case 6: {
                string nombre, pass;
                cout << "Usuario: ";
                getline(cin, nombre);
                cout << "Contrasena: ";
                getline(cin, pass);
                if (autenticarUsuario(nombre, pass)) {
                    cout << "Login correcto. Envios del usuario:\n";
                    listarEnviosPorUsuario(nombre);
                } else {
                    cout << "Credenciales invalidas.\n";
                }
                break;
            }
            case 7:
                cout << "\n--- Menu Admin ---\n";
                reporteResumen();
                cout << "¿Desea asignar un envio ahora? (1=si / 0=no): ";
                int r; cin >> r; cin.ignore();
                if (r == 1) asignarEnvioAdmin();
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
