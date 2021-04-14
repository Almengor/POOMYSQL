#pragma once
#include "Persona.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Cliente : Persona {
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idcliente, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del Cliente que desea modificar: ";
			cin >> idcliente;
			string consulta = "select * from Clientes where id_cliente=" + idcliente + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "IdCliente: " << fila[0] << endl;
					cout << ("Nit: ") << fila[1] << endl;
					cout << ("Nombres: ") << fila[2] << endl;
					cout << ("Apellidos: ") << fila[3] << endl;
					cout << ("Direccion: ") << fila[4] << endl;
					cout << ("Telefono: ") << fila[5] << endl;
					cout << ("Fecha de nacimiento: ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo nit de cliente: ";
						cin >> nit;
						string modificar = "update Clientes set nit = '" + nit + "' where id_cliente =" + idcliente +"";
						cin.ignore();
						cout << "\nIngrese el nombre de cliente: ";
						getline(cin, nombres);
						string modificar = "update Clientes set nombres = '" + nombres + "' where id_cliente =" + idcliente + "";
						cout << "\nIngrese los apellidos de cliente: ";
						getline(cin, apellidos);
						string modificar = "update Clientes set apellidos = '" + apellidos + "' where id_cliente =" + idcliente + "";
						cout << "\nIngrese la nueva direccion de cliente: ";
						getline(cin, direccion);
						string modificar = "update Clientes set direccion = '" + direccion + "' where id_cliente =" + idcliente + "";
						cout << "\nIngrese el nuevo telefono de cliente: ";
						getline(cin, telefono);
						string modificar = "update Clientes set telefono = '" + telefono + "' where id_cliente =" + idcliente + "";
						cout << "\nIngrese la fecha de nacimiento de cliente: ";
						getline(cin, fecha_nacimiento);
						string modificar = "update Clientes set fecha_nacimiento = '" + fecha_nacimiento + "' where id_cliente =" + idcliente + "";
						cin >> fecha_nacimiento;
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idcliente;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> idcliente;
			string eliminar = "delete from Clientes where id_cliente = (" + idcliente + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};