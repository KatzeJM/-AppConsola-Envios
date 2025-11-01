// envio.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  Estructuras y datos globales compartidos por todos los modulos.
  Todo en memoria (vectors).
*/

// ====== Estructuras ======
struct Usuario {
    string nombre;
    string contrasena;
    string rol; // "admin", "controlador", "piloto", "cliente"
};

struct Pedido {
    int id;
    string cliente;
    string direccion;
    float peso;           // libras
    string metodoPago;
    float total;
    string estado;        // "Inicial", "En curso", "Finalizado"
    string pilotoAsignado; // nombre del piloto o "" si no asignado
};

// ====== Datos globales ======
static vector<Usuario> usuarios;
static vector<Pedido> pedidos;
static int siguienteId = 1;

// Tarifas configurables
static float tarifaBase = 30.0f;         // Q30 por defecto
static float limiteLibras = 25.0f;       // umbral en libras
static float precioPorLibraExtra = 5.0f; // Q5 por libra extra

// ====== Utilidades locales de impresión (solo estético) ======
static void printHeader(const string& title) {
    string barra(title.size() + 8, '=');
    cout << barra << "\n"
         << "   " << title << "\n"
         << barra << "\n";
}

// ====== Usuarios ======
void inicializarUsuariosDemo() {
    if (!usuarios.empty()) return;
    usuarios.push_back({"admin", "123", "admin"});
    usuarios.push_back({"controlador", "123", "controlador"});
    usuarios.push_back({"piloto", "123", "piloto"});
    usuarios.push_back({"cliente", "123", "cliente"});
}

bool agregarUsuario(const string& nombre, const string& contrasena, const string& rol) {
    for (const auto &u : usuarios) {
        if (u.nombre == nombre) return false;
    }
    usuarios.push_back({nombre, contrasena, rol});
    return true;
}

string autenticarYObtenerRol(const string& nombre, const string& contrasena) {
    for (const auto &u : usuarios) {
        if (u.nombre == nombre && u.contrasena == contrasena) return u.rol;
    }
    return "";
}

// ====== Tarifas / Cálculo ======
float calcularPrecio(float peso) {
    if (peso <= limiteLibras) return tarifaBase;
    float extra = peso - limiteLibras;
    return tarifaBase + (extra * precioPorLibraExtra);
}

// ====== Pedidos (CRUD y vistas) ======
int crearPedido(const string& cliente, const string& direccion, float peso, const string& metodoPago) {
    Pedido p;
    p.id = siguienteId++;
    p.cliente = cliente;
    p.direccion = direccion;
    p.peso = peso;
    p.metodoPago = metodoPago;
    p.total = calcularPrecio(peso);
    p.estado = "Inicial";
    p.pilotoAsignado = "";
    pedidos.push_back(p);
    return p.id;
}

void listarPedidos() {
    printHeader("LISTA DE PEDIDOS");
    if (pedidos.empty()) {
        cout << "No hay pedidos registrados.\n";
        return;
    }
    for (const auto &p : pedidos) {
        cout << "ID: " << p.id
             << " | Cliente: " << p.cliente
             << " | Peso: " << p.peso << " lb"
             << " | Total: Q" << p.total
             << " | Estado: " << p.estado
             << " | Piloto: " << (p.pilotoAsignado.empty() ? "Sin asignar" : p.pilotoAsignado) << "\n"
             << "    Direccion: " << p.direccion << "\n"
             << "    Pago: " << p.metodoPago << "\n";
    }
}

void listarPedidosPorCliente(const string& cliente) {
    printHeader("MIS PEDIDOS");
    bool found = false;
    for (const auto &p : pedidos) {
        if (p.cliente == cliente) {
            found = true;
            cout << "ID: " << p.id
                 << " | Peso: " << p.peso << " lb"
                 << " | Total: Q" << p.total
                 << " | Estado: " << p.estado
                 << " | Piloto: " << (p.pilotoAsignado.empty() ? "Sin asignar" : p.pilotoAsignado) << "\n";
        }
    }
    if (!found) cout << "No se encontraron pedidos para " << cliente << ".\n";
}

void listarPedidosPorPiloto(const string& piloto) {
    printHeader("PEDIDOS ASIGNADOS AL PILOTO");
    bool found = false;
    for (const auto &p : pedidos) {
        if (p.pilotoAsignado == piloto) {
            found = true;
            cout << "ID: " << p.id
                 << " | Cliente: " << p.cliente
                 << " | Peso: " << p.peso << " lb"
                 << " | Estado: " << p.estado
                 << " | Total: Q" << p.total << "\n"
                 << "    Direccion: " << p.direccion << "\n";
        }
    }
    if (!found) cout << "No hay pedidos asignados al piloto " << piloto << ".\n";
}

bool asignarPedidoA(int id, const string& piloto) {
    for (auto &p : pedidos) {
        if (p.id == id) {
            p.pilotoAsignado = piloto;
            p.estado = "En curso";
            return true;
        }
    }
    return false;
}

bool cambiarEstadoPedido(int id, const string& nuevoEstado) {
    for (auto &p : pedidos) {
        if (p.id == id) {
            p.estado = nuevoEstado;
            return true;
        }
    }
    return false;
}

void mostrarResumenUltimoPedido() {
    printHeader("RESUMEN DEL ULTIMO PEDIDO");
    if (pedidos.empty()) {
        cout << "No hay pedidos para mostrar.\n";
        return;
    }
    const Pedido &p = pedidos.back();
    cout << "ID: " << p.id << "\n"
         << "Cliente: " << p.cliente << "\n"
         << "Direccion: " << p.direccion << "\n"
         << "Peso: " << p.peso << " lb\n"
         << "Total: Q" << p.total << "\n"
         << "Estado: " << p.estado << "\n"
         << "Piloto: " << (p.pilotoAsignado.empty() ? "Sin asignar" : p.pilotoAsignado) << "\n";
}

// ====== Set/Get de tarifas ======
void setTarifaBase(float t) { tarifaBase = t; }
void setLimiteLibras(float l) { limiteLibras = l; }
void setPrecioPorLibraExtra(float p) { precioPorLibraExtra = p; }

float getTarifaBase() { return tarifaBase; }
float getLimiteLibras() { return limiteLibras; }
float getPrecioPorLibraExtra() { return precioPorLibraExtra; }

// ====== Listar usuarios (simple) ======
void listarUsuariosSimple() {
    printHeader("USUARIOS REGISTRADOS");
    if (usuarios.empty()) {
        cout << "No hay usuarios.\n";
        return;
    }
    for (const auto &u : usuarios) {
        cout << "- " << u.nombre << " (" << u.rol << ")\n";
    }
}
