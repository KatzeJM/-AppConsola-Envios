#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para usuario
struct Usuario {
    string nombre;
    string contrasena;
};

// almacenamiento en memoria
static vector<Usuario> usuarios;

// Crear usuario
void crearUsuario() {
    Usuario u;
    cout << "\n=== Crear nuevo usuario ===\n";
    cout << "Nombre de usuario: ";
    getline(cin, u.nombre);
    if (u.nombre.empty()) {
        cout << "Nombre no puede estar vacio.\n";
        return;
    }

    // verificar existencia
    for (const auto &x : usuarios) {
        if (x.nombre == u.nombre) {
            cout << "⚠ El usuario ya existe.\n";
            return;
        }
    }

    cout << "Contrasena: ";
    getline(cin, u.contrasena);
    if (u.contrasena.empty()) {
        cout << "Contrasena no puede estar vacia.\n";
        return;
    }

    usuarios.push_back(u);
    cout << "Usuario creado: " << u.nombre << "\n";
}

// Listar todos los usuarios (solo para pruebas)
void listarUsuarios() {
    cout << "\n=== Usuarios registrados ===\n";
    if (usuarios.empty()) {
        cout << "No hay usuarios.\n";
        return;
    }
    for (size_t i = 0; i < usuarios.size(); ++i) {
        cout << i+1 << ". " << usuarios[i].nombre << "\n";
    }
}

// Autenticar (nombre + contrasena)
bool autenticarUsuario(const string& nombre, const string& contrasena) {
    for (const auto &u : usuarios) {
        if (u.nombre == nombre && u.contrasena == contrasena) return true;
    }
    return false;
}
