#pragma once
#include <iostream>
#include <string>

#include "Estudiante.h"
#include "Tablet.h"
#include "Prestamo.h"
#include "ArregloDinamico.h"

class ServicioPrestamoTablets {
private:
	ArregloDinamico<Estudiante> estudiantes;
	ArregloDinamico<Tablet> tablets;
	ArregloDinamico<Prestamo> prestamos;
public:
	int obtenerPosEstuCodigo(int codigo);
	int obtenerPosTabletModelo(string modelo);

	void registrarEstudiante(Estudiante* estudiante);
	void registrarTablet(Tablet* tablet);
	void registrarPrestamo(Prestamo* prestamo);
	void listarEstudiantes();
	void listarTablets();
	void listarPrestamosPorEstudiante(int codigoEstudiante);
	void listarPrestamosTotal();
	Estudiante* obtenerEstudiantePorCodigo(int codigo);
	Tablet* obtenerTabletPorModelo(string modelo);
	

};
