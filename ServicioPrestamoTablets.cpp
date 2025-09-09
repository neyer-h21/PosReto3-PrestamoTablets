#include "pch.h"
#include "ServicioPrestamoTablets.h"

int ServicioPrestamoTablets::obtenerPosEstuCodigo(int codigo) {
	int pos = -1; //-1 significa que el dato no se encontro
	for (int i = 0; i < estudiantes.size(); i++)
	{
		if (estudiantes[i].getCodigoEstudiante() == codigo) {
			pos = i;
			break;
		}
	}
	return pos;
}

int ServicioPrestamoTablets::obtenerPosTabletModelo(string modelo) {
	int pos = -1; //-1 significa que el dato no se encontro
	for (int i = 0; i < tablets.size(); i++)
	{
		if (tablets[i].getModelo() == modelo) {
			pos = i;
			break;
		}
	}
	return pos;
}

void ServicioPrestamoTablets::registrarEstudiante(Estudiante* estudiante) {
	if(obtenerPosEstuCodigo(estudiante->getCodigoEstudiante())>0) return;			
	estudiantes.agregar(*estudiante);
	cout << "Estudiante registrado con exito" << endl;

}

void ServicioPrestamoTablets::registrarTablet(Tablet* tablet) {
	if (obtenerPosTabletModelo(tablet->getModelo())> 0) return;
	tablets.agregar(*tablet);
	cout << "Tablet registrado con exito" << endl;
}

void ServicioPrestamoTablets::registrarPrestamo(Prestamo* prestamo) {
	int posEst = obtenerPosEstuCodigo(prestamo->getEstudiante()->getCodigoEstudiante());
	if (posEst < 0) {
		cout << "El estudiante no existe" << endl;
		return;
	}		

	int posTablet = obtenerPosTabletModelo(prestamo->getTablet()->getModelo());
	if (posTablet < 0) {
		cout << "La tablet no existe" << endl;
		return;
	}		

	Prestamo nuevoPrestamo (&estudiantes[posEst], &tablets[posTablet], prestamo->getFechaInicio(),
		prestamo->getFechaFin());
	
	//verifique que un estudiante en una fecha de inicio no pueda prestar mas de una vez
	//int contPrestamosEstudiante = funcion....

	prestamos.agregar(nuevoPrestamo);


	tablets[posTablet].setEstado("Prestado");
	cout << "Prestamos registrado con exito" << endl;
}


void ServicioPrestamoTablets::listarPrestamosPorEstudiante(int codigoEstudiante) {

	for (int i = 0; i < prestamos.size(); i++)
	{
		Estudiante* e = prestamos[i].getEstudiante();

		if (e != nullptr && e->getCodigoEstudiante() == codigoEstudiante) {

			//imprimir los prestamos realizados - tablet modelo
			Tablet* t = prestamos[i].getTablet();
			cout << "\tReporte de prestamos solicitados por estudiante" << endl;
			cout << "==========================================" << endl;
			cout << "Estudiante: " << e->getNombre() << endl;
			cout << "Fecha Inicio: " << prestamos[i].getFechaInicio() << endl;
			cout << "Fecha Fin: " << prestamos[i].getFechaFin() << endl;
			cout << "Tablet: " << t->getModelo() << endl;
		}
		else
		{
			cout << "\t ****    El estudiante no tiene prestamos registrados    **** " << endl;
		}
	}
}

void ServicioPrestamoTablets::listarPrestamosTotal() {
	if (prestamos.size() > 0)
	{
		cout << endl << "\t PRESTAMOS TOTALES" << endl;
		for (int i = 0; i < prestamos.size(); i++)
		{
			cout << "==========================================" << endl;
			cout << "\tPrestamo" << i + 1 << endl;
			cout << "Estudiante: " << prestamos[i].getEstudiante()->getNombre() << endl;
			cout << "Codigo de Estudiante: " << prestamos[i].getEstudiante()->getCodigoEstudiante() << endl;
			cout << "Fecha Inicio: " << prestamos[i].getFechaInicio() << endl;
			cout << "Fecha Fin: " << prestamos[i].getFechaFin() << endl;
			cout << "Tablet: " << prestamos[i].getTablet()->getModelo() << endl;
		}
	}
	else
	{
		cout << "\t ***   No hay prestamos registrados    ***" << endl;
	}
	
}

void ServicioPrestamoTablets::listarEstudiantes() {
	if (estudiantes.size()>0)
	{
		cout << endl << "\tLISTADO DE TODOS LOS ESTUDIANTES" << endl;

		for (int i = 0; i < estudiantes.size(); i++)
		{
			cout << "==========================================" << endl;
			cout << "Codigo:" << estudiantes[i].getCodigoEstudiante() << endl;
			cout << "Nombre:" << estudiantes[i].getNombre() << endl;
		}
	}
	else
	{
		cout << "\t ***   No hay estudiantes registrados    ***" << endl;
	}
	
}

void ServicioPrestamoTablets::listarTablets() {
	if (tablets.size() > 0)
	{
		cout << endl << "\t LISTADO DE TABLETS REGISTRADOS" << endl;

		for (int i = 0; i < tablets.size(); i++)
		{
			cout << "==========================================" << endl;
			cout << "Modelo:" << tablets[i].getModelo() << endl;
			cout << "Estado:" << tablets[i].getEstado() << endl;

		}
	}
	else
	{
		cout << "\t ***   No hay tablets registrados    ***" << endl;
	}
	
}
Estudiante* ServicioPrestamoTablets::obtenerEstudiantePorCodigo(int codigo) {
	int pos = obtenerPosEstuCodigo(codigo);
	if (pos >= 0) {
		return &estudiantes[pos];
	}
	return nullptr;
}
Tablet* ServicioPrestamoTablets::obtenerTabletPorModelo(string modelo) {
	int pos = obtenerPosTabletModelo(modelo);
	if (pos >= 0) {
		return &tablets[pos];
	}
	return nullptr;
}
