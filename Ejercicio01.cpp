#include "pch.h"
#include "Estudiante.h"
#include "Tablet.h"
#include "Prestamo.h"
#include "ServicioPrestamoTablets.h"

using namespace std;
using namespace System;

void menu(int& op) {
	cout << "\tMenu de opciones" << endl;
	cout << "1. Registrar estudiantes" << endl;
	cout << "2. Registrar tablets" << endl;
	cout << "3. Registrar prestamos " << endl;
	cout << "4. Listar todos los estudiantes " << endl;
	cout << "5. Listar todos los prestamos por estudiante" << endl;
	cout << "6. Listar todos los prestamos" << endl;
	cout << "7. Listar todas las tablets" << endl;
	cout << "0. SALIR" << endl;
	
    do
    {
        cout << "Seleccione una opcion: ";
        cin >> op;
    } while (op < 0 || op > 7);
	
}
void registrarEstudianteMenu(ServicioPrestamoTablets* servicio) {
    int codigo;
    string nombre;
    cout << "Ingrese el codigo del estudiante: "; cin >> codigo;
    cout << "Ingrese el nombre del estudiante: "; cin >> nombre;
    Estudiante* estudianteX = new Estudiante(codigo, nombre);
	servicio->registrarEstudiante(estudianteX);
	delete estudianteX;

}
void registrarTabletMenu(ServicioPrestamoTablets* servicio) {
    
    string modelo;
    cout << "Ingrese el modelo de la tablet: "; cin >> modelo;
    Tablet* tabletX = new Tablet(modelo);
    servicio->registrarTablet(tabletX);
	delete tabletX;

}
void registrarPrestamoMenu(ServicioPrestamoTablets* servicio) {

    int codigoEstudiante;
    string modeloTablet;
	string fechaInicio;
	string fechaFin;
    cout << "Ingrese el codigo de estudiante: "; cin >> codigoEstudiante;
    cout << "Ingrese el modelo de la tablet: "; cin >> modeloTablet;
    cout << "Ingrese la fecha de inicio: "; cin >> fechaInicio;
    cout << "Ingrese la fecha de fin: "; cin >> fechaFin;
    Prestamo* prestamoX = new Prestamo(servicio->obtenerEstudiantePorCodigo(codigoEstudiante), servicio->obtenerTabletPorModelo(modeloTablet), fechaInicio, fechaFin);
    servicio->registrarPrestamo(prestamoX);
	delete prestamoX;

}
void listarEstudiantesMenu(ServicioPrestamoTablets* servicio) {
    servicio->listarEstudiantes();
}
void listarPrestamosPorEstudianteMenu(ServicioPrestamoTablets* servicio) {
    int codigoEstudiante;
    cout << "Ingrese el codigo de estudiante: "; cin >> codigoEstudiante;
    servicio->listarPrestamosPorEstudiante(codigoEstudiante);
}
void listarTodosPrestamosMenu(ServicioPrestamoTablets* servicio) {
    servicio->listarPrestamosTotal();
}
void listarTabletsMenu(ServicioPrestamoTablets* servicio) {
    servicio->listarTablets();
}
int main() {
    

    //servicio de prestamo de tablet
    ServicioPrestamoTablets* servicio = new ServicioPrestamoTablets();

    //menu
    int op = -1;
    bool salir = true;
    //TODO: Un menu de opcion | listar todos los estudiantes | listar todos los prestamos | listar todas tablets
    do
    {
        menu(op);
        switch (op)
        {
        case 1: registrarEstudianteMenu(servicio); break;
        case 2: registrarTabletMenu(servicio); break;
        case 3: registrarPrestamoMenu(servicio); break;
        case 4: listarEstudiantesMenu(servicio); break;
        case 5: listarPrestamosPorEstudianteMenu(servicio); break;
        case 6: listarTodosPrestamosMenu(servicio); break;
        case 7: listarTabletsMenu(servicio); break;
        default:
            salir = false;
            break;
        }
    } while (salir);

    servicio->deleteAll();
    delete servicio;
    system("pause>0");
    return 0;
}




















































































































