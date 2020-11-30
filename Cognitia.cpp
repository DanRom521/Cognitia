#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void pausa();
void error();
void modo();

class BaseDeDatos
{
private:
    string nombre;
    string ApellidoP;
    string ApellidoM;
    string domicilio;
    string celular;
    string Cuenta;
    string Correo;
    string Carnet;

public:
    void registrarCliente() {
        ofstream escribir;
        ifstream verificar;
        string auxCuenta;
        bool coincidencia = false;
        verificar.open("clientes.txt", ios::in);
        escribir.open("clientes.txt", ios::app);
        if (escribir.is_open() && verificar.is_open())
        {
            fflush(stdin);
            cout << "           ---Registrar un cliente---" << endl << endl << endl;
            cout << "Ingresa el numero de cuenta del cliente: ";
            getline(cin, auxCuenta);
            getline(cin, auxCuenta);
            if (auxCuenta.empty() || auxCuenta == " ") {
                do
                {
                    cout << "Numero de cuenta no valido!" << endl << "Intentalo nuevamente: ";
                    getline(cin, auxCuenta);
                } while (auxCuenta.empty() || auxCuenta == " ");
            }
            do {
                verificar.seekg(0);
                while (!verificar.eof()) {
                    getline(verificar, Cuenta);
                    getline(verificar, nombre);
                    getline(verificar, ApellidoP);
                    getline(verificar, ApellidoM);
                    getline(verificar, domicilio);
                    getline(verificar, celular);
                    getline(verificar, Correo);
                    getline(verificar, Carnet);
                    if (Cuenta == auxCuenta) {
                        do {
                            coincidencia = true;
                            cout << endl << "Ya existe un cliente con ese numero de cuenta!" << endl;
                            cout << "El cliente con ese numero de cuenta es: " << nombre << " " << ApellidoP << " " << ApellidoM << endl;
                            cout << "Ingresa un codigo valido: ";
                            getline(cin, auxCuenta);
                            if (auxCuenta.empty() || auxCuenta == " ") {
                                do
                                {
                                    cout << "Numero de cuenta no valido!" << endl << "Intentalo nuevamente: ";
                                    getline(cin, auxCuenta);
                                } while (auxCuenta.empty() || auxCuenta == " ");
                            }
                        } while (Cuenta == auxCuenta);
                    }
                }

                if (verificar.eof() && auxCuenta != Cuenta) {
                    coincidencia = false;
                }
            } while (coincidencia == true);
            system("cls");
            Cuenta = auxCuenta;
            cout << "           ---Registrar un cliente---" << endl << endl << endl;
            cout << "Ingresa el numero de cuenta del cliente: ";
            cout << Cuenta;
            cout << endl << endl;
            cout << "Ingresa el nombre del cliente: ";
            getline(cin, nombre);
            cout << endl;
            cout << "Ingresa el apellido paterno del cliente: ";
            getline(cin, ApellidoP);
            cout << endl;
            cout << "Ingresa el apellido materno del cliente: ";
            getline(cin, ApellidoM);
            cout << endl;
            cout << "Ingresa el domicilio del cliente: ";
            getline(cin, domicilio);
            cout << endl;
            cout << "Ingresa el numero de telefono del cliente: ";
            getline(cin, celular);
            cout << endl;
            cout << "Ingresa el correo del cliente: ";
            getline(cin, Correo);
            cout << endl;
            cout << "Ingresa el carnet del cliente: ";
            getline(cin, Carnet);
            cout << endl;
            fflush(stdin);

            escribir << Cuenta << endl << nombre << endl << ApellidoP << endl << ApellidoM << endl << domicilio <<
                endl << celular << endl << Correo << endl << Carnet << endl;

            cout << "El registro se ha completado correctamente.\n\n";
        }

        else
        {
            error();
        }

        escribir.close();
        verificar.close();
        pausa();
    }
    void eliminarCliente() {
        ifstream leer;
        ofstream auxiliar;
        bool encontrado = false;
        string auxCuenta;
        string respuesta;
        bool respondio;
        leer.open("clientes.txt", ios::in);
        auxiliar.open("auxiliar.txt", ios::out);
        cout << "           ---Dar de baja un cliente" << endl << endl << endl;
        if (leer.is_open() && auxiliar.is_open())
        {
            fflush(stdin);
            cout << "Ingresa el numero de cuenta del cliente que deseas eliminar: ";
            getline(cin, auxCuenta);
            getline(cin, auxCuenta);
            while (!leer.eof()) {
                getline(leer, Cuenta);
                getline(leer, nombre);
                getline(leer, ApellidoP);
                getline(leer, ApellidoM);
                getline(leer, domicilio);
                getline(leer, celular);
                getline(leer, Correo);
                getline(leer, Carnet);
                if (Cuenta.empty()) {
                    break;
                }

                if (auxCuenta == Cuenta)
                {
                    encontrado = true;
                    cout << endl << endl << "Registro Encontrado" << endl;
                    cout << "Numero de cuenta: " << Cuenta << endl;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Apellido Paterno: " << ApellidoP << endl;
                    cout << "Apellido Materno: " << ApellidoM << endl;
                    cout << "Domicilio: " << domicilio << endl;
                    cout << "Celular: " << celular << endl;
                    cout << "Coreo: " << Correo << endl;
                    cout << "Carnet: " << Carnet << endl;
                    cout << endl;
                    do {
                        cout << "Realmente deseas dar de baja a: " << nombre << " " << ApellidoP << " " << ApellidoM << " (s/n)?: ";
                        getline(cin, respuesta);
                        if (respuesta == "s" || respuesta == "S")
                        {
                            cout << endl << "El cliente se ha eliminado correctamente" << endl;
                            respondio = true;
                        }

                        else if (respuesta == "n" || respuesta == "N")
                        {

                            cout << endl << "Cliente conservado" << endl;
                            auxiliar << Cuenta << endl << nombre << endl << ApellidoP << endl << ApellidoM << endl
                                << domicilio << endl << celular << endl << Correo << endl << Carnet << endl;
                            respondio = true;
                        }
                        else
                        {
                            cout << "Respuesta no aceptada, recuerde responder s/n" << endl;
                            respondio = false;
                        }
                    } while (!respondio);
                }
                else
                {
                    auxiliar << Cuenta << endl << nombre << endl << ApellidoP << endl << ApellidoM << endl << domicilio
                        << endl << celular << endl << Correo << endl << Carnet << endl;
                }
            }
            if (encontrado == false)
            {
                cout << endl << "No se encontro el numero de cuenta: " << auxCuenta << endl;
            }

        }
        else
        {
            error();
        }
        leer.close();
        auxiliar.close();
        remove("clientes.txt");
        rename("auxiliar.txt", "clientes.txt");
        pausa();
    }
    void modificarCliente() {
        ifstream leer;
        ifstream verificar;
        ifstream mostrar;
        ofstream auxiliar;
        string auxCuenta;
        string CuentaN;
        string auxNombre;
        string auxApellidoP;
        string auxApellidoM;
        string auxDomicilio;
        string auxCelular;
        string auxCorreo;
        string auxCarnet;
        bool encontrado = false;
        bool coincidencia = false;
        bool mismoCodigo = false;
        leer.open("clientes.txt", ios::in);
        verificar.open("clientes.txt", ios::in);
        mostrar.open("clientes.txt", ios::in);
        auxiliar.open("auxiliar.txt", ios::out);
        cout << "           ---Modificar los datos de un cliente---" << endl << endl << endl;
        if (leer.is_open() && verificar.is_open() && auxiliar.is_open() && mostrar.is_open())
        {
            fflush(stdin);
            cout << "Ingresa el numero de cuenta del cliente que deseas modificar: ";
            getline(cin, auxCuenta);
            getline(cin, auxCuenta);
            if (auxCuenta.empty() || auxCuenta == " ")
            {
                do
                {
                    cout << "Numero de cuenta no valido!" << endl << "Intente nuevamente: ";
                    getline(cin, auxCuenta);
                } while (auxCuenta.empty() || auxCuenta == " ");
            }
            while (!leer.eof())
            {
                getline(leer, Cuenta);
                getline(leer, nombre);
                getline(leer, ApellidoP);
                getline(leer, ApellidoM);
                getline(leer, domicilio);
                getline(leer, celular);
                getline(leer, Correo);
                getline(leer, Carnet);
                if (Cuenta.empty()) {
                    break;
                }
                if (auxCuenta == Cuenta)
                {
                    cout << endl << "Registro Encontrado" << endl;
                    cout << "Numero de cuenta: " << Cuenta << endl;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Apellido Paterno: " << ApellidoP << endl;
                    cout << "Apellido Materno: " << ApellidoM << endl;
                    cout << "Domicilio: " << domicilio << endl;
                    cout << "Celular: " << celular << endl;
                    cout << "Correo: " << Correo << endl;
                    cout << "Carnet: " << Carnet << endl;
                    cout << endl;
                    cout << endl << endl;
                    cout << "Ingresa la nueva informacion para el cliente" << endl << endl;
                    cout << "Ingresa el nuevo numero de cuenta del cliente: ";
                    getline(cin, CuentaN);
                    if (auxCuenta != CuentaN)
                    {
                        do
                        {
                            verificar.seekg(0);
                            while (!verificar.eof())
                            {
                                getline(verificar, Cuenta);
                                getline(verificar, nombre);
                                getline(verificar, ApellidoP);
                                getline(verificar, ApellidoM);
                                getline(verificar, domicilio);
                                getline(verificar, celular);
                                getline(verificar, Correo);
                                getline(verificar, Carnet);
                                if (Cuenta.empty()) {
                                    break;
                                }

                                if (CuentaN == Cuenta)
                                {
                                    coincidencia = true;
                                    cout << endl << "Ya existe un cliente con ese codigo!" << endl;
                                    cout << "El cliente con ese numero de cuenta es: " << nombre << " " << ApellidoP << " " <<
                                        ApellidoM << endl;
                                    cout << "Ingresa un numero de cuenta valido: ";
                                    getline(cin, CuentaN);

                                    if (CuentaN.empty() || CuentaN == " ")
                                    {
                                        do
                                        {
                                            cout << "Numero de cuenta no valido!" << endl << "Intentalo nuevamente: ";
                                            getline(cin, CuentaN);
                                        } while (CuentaN.empty() || CuentaN == " ");
                                    }
                                }
                            }

                            if (verificar.eof() && auxCuenta != Cuenta)
                            {
                                coincidencia = false;
                            }

                        } while (coincidencia == true);
                    }
                    cout << endl;
                    cout << "Ingresa el nombre del cliente: ";
                    getline(cin, auxNombre);
                    cout << endl;
                    cout << "Ingresa el Apellido Paterno: ";
                    getline(cin, auxApellidoP);
                    cout << endl;
                    cout << "Ingresa el Apellido Materno: ";
                    getline(cin, auxApellidoM);
                    cout << endl;
                    cout << "Ingresa el domicilio del cliente: ";
                    getline(cin, auxDomicilio);
                    cout << endl;
                    cout << "Ingresa el numero de telefono del cliente: ";
                    getline(cin, auxCelular);
                    cout << endl;
                    cout << "Ingresa el correo: ";
                    getline(cin, auxCorreo);
                    cout << endl;
                    cout << "Ingresa el carnet: ";
                    getline(cin, auxCarnet);
                    cout << endl;
                    fflush(stdin);
                    auxiliar << auxCuenta << endl << auxNombre << endl << auxApellidoP << endl << auxApellidoM << endl
                        << auxDomicilio << endl << auxCelular << endl << auxCorreo << endl << auxCarnet << endl;
                    cout << "El Registro se ha modificado correctamente." << endl;
                }

                else
                {

                    auxiliar << Cuenta << endl << nombre << endl << ApellidoP << endl << ApellidoM << endl << domicilio << endl
                        << celular << endl << Correo << endl << Carnet << endl;
                }
            }
        }
        else
        {
            error();
        }

        
        leer.close();
        verificar.close();
        mostrar.close();
        auxiliar.close();
        remove("clientes.txt");
        rename("auxiliar.txt", "clientes.txt");
        pausa();
    }
    void listarClientes() {
        int i = 0;
        ifstream lectura;
        lectura.open("clientes.txt", ios::in);
        if (lectura.is_open())
        {
            cout << "           ---Listado de todos los clientes---" << endl << endl << endl;
            while (!lectura.eof())
            {
                getline(lectura, Cuenta);
                getline(lectura, nombre);
                getline(lectura, ApellidoP);
                getline(lectura, ApellidoM);
                getline(lectura, domicilio);
                getline(lectura, celular);
                getline(lectura, Correo);
                getline(lectura, Carnet);
                i++;
                if (Cuenta.empty()) {
                    break;
                }
                cout << "Cuenta: " << Cuenta << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Apellido Paterno: " << ApellidoP << endl;
                cout << "Apellido Materno: " << ApellidoM << endl;
                cout << "Domicilio: " << domicilio << endl;
                cout << "Celular: " << celular << endl;
                cout << "Correo: " << Correo << endl;
                cout << "Carnet: " << Carnet << endl;
                cout << endl;
            }
            i--;
            if (i == 1)
                cout << "Hay un solo cliente registrado" << endl << endl;

            else

                cout << "Hay un total de " << i << " clientes registrados" << endl << endl;
        }
        else
        {
            error();
        }
        lectura.close();
        pausa();
    }
    void detallesCliente() {
        string auxCuenta;
        ifstream mostrar;
        bool encontrado = false;
        mostrar.open("clientes.txt", ios::in);
        if (mostrar.is_open())
        {
            fflush(stdin);
            cout << "           ---Consultar detalles de un cliente---" << endl << endl << endl;
            cout << "Ingresa el numero de cuenta del cliente que deseas consultar detalles: ";
            getline(cin, auxCuenta);
            getline(cin, auxCuenta);
            while (!mostrar.eof())
            {
                getline(mostrar, Cuenta);
                getline(mostrar, nombre);
                getline(mostrar, ApellidoP);
                getline(mostrar, ApellidoM);
                getline(mostrar, domicilio);
                getline(mostrar, celular);
                getline(mostrar, Correo);
                getline(mostrar, Carnet);
                if (Cuenta.empty()) {
                    break;
                }
                if (auxCuenta == Cuenta)
                {
                    encontrado = true;
                    cout << endl << "Registro Encontrado" << endl;
                    cout << "Numero de Cuenta: " << Cuenta << endl;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Apellido Paterno: " << ApellidoP << endl;
                    cout << "Apellido Materno: " << ApellidoM << endl;
                    cout << "Domicilio: " << domicilio << endl;
                    cout << "Celular: " << celular << endl;
                    cout << "Correo: " << Correo << endl;
                    cout << "Carnet: " << Carnet << endl;
                    cout << endl;
                }
            }

            if (encontrado == false)
            {
                cout << endl << "No se encontro el registro: " << auxCuenta << endl;
            }
        }

        else
        {
            error();
        }

        mostrar.close();
        pausa();
    }
    void menuPrincipal() {
        int opcion;
        do
        {
            cout << "               ---Registro de clientes---" << endl << endl;
            cout << "1. Registrar un cliente" << endl;
            cout << "2. Mostrar detalles de un cliente" << endl;
            cout << "3. Listar clientes" << endl;
            cout << "4. Eliminar un cliente" << endl;
            cout << "5. Modificar un cliente" << endl;
            cout << "6. Salir" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            default:
                cout << "Ha ingresado una opcion no valida!" << endl;
                break;

            case 1:
                registrarCliente();
                break;

            case 2:
                detallesCliente();
                break;

            case 3:
                listarClientes();
                break;

            case 4:
                eliminarCliente();
                break;

            case 5:
                modificarCliente();
                break;

            case 6:
                break;
            }
        } while (opcion != 6);
    }

};


int main()
{
    modo();
    BaseDeDatos datos;
    ofstream crear;
    crear.open("clientes.txt", ios::app);
    crear.close();
    datos.menuPrincipal();
    return 0;
}

void pausa()
{
    system("pause");
    system("cls");
}

void error()
{
    cout << "No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en" << endl;
    cout << "la misma ubicacion que el programa o que el archivo de texto se llame:" << endl;
    cout << "clientes.txt, si el archivo tiene otro nombre renombrelo al ya mencionado" << endl;
}

void modo() {
    int color;
    do {
        cout << "1. Modo oscuro" << endl;
        cout << "2. Modo Claro" << endl;
        cout << "Opcion: ";
        cin >> color;

        switch (color)
        {
        case 1:
            system("color 0f");
            break;
        case 2:
            system("color f0");
            break;
        default:
            cout << "Opcion invalida" << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (color != 1 && color != 2);
    system("cls");
}