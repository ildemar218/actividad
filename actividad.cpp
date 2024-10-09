#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct nodo {
    char nombre[15];
    int documento;
    int destino;
    nodo *sig;
};

nodo *cab = nullptr, *aux, *aux2;

void registrar() { // Función para agregar un nuevo pasajero a la lista 
    aux = (struct nodo *) malloc(sizeof(nodo));
    cout << "Ingrese el nombre: ";
    cin >> aux->nombre;
    cout << "Documento: ";
    cin >> aux->documento;
    cout << "Elija el numero de su destino: " << endl;
    cout << "1: bocana" << endl;
    cout << "2: pianguita" << endl;
    cout << "3: ladrilleros" << endl;
    cin >> aux->destino;
    aux->sig = nullptr;

    if (!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != nullptr) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}

void mostrar() { // Recorre la lista para mostrar los pasajeros
    aux = cab;
    cout << "--------- " << endl;
    while (aux != nullptr) {
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Documento: " << aux->documento << endl;
        cout << "Destino: " << aux->destino << endl;
        cout << "--------- " << endl;
        aux = aux->sig;
    }
}

void ordenar() { // Ordena los pasajeros por destino y luego por documento
    int tempDocumento, tempDestino;
    char tempNombre[15];

    aux2 = cab; 
    while (aux2 != nullptr) {
        aux = cab; 

        while (aux->sig != nullptr) { 
            if (aux->destino > aux->sig->destino || 
                (aux->destino == aux->sig->destino && aux->documento > aux->sig->documento)) {

                tempDestino = aux->destino;
                aux->destino = aux->sig->destino;
                aux->sig->destino = tempDestino;


                tempDocumento = aux->documento;
                aux->documento = aux->sig->documento;
                aux->sig->documento = tempDocumento;


                for (int i = 0; i < 15; i++) {
                    tempNombre[i] = aux->nombre[i];
                    aux->nombre[i] = aux->sig->nombre[i];
                    aux->sig->nombre[i] = tempNombre[i];
                }
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

int main() {
    int opcion;

    do {
        cout << "Menu" << endl
            << "1. Registrar pasajero" << endl
            << "2. Mostrar pasajeros" << endl
            << "3. Ordenar pasajeros" << endl
            << "4. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                ordenar();
                break;
        }
    } while (opcion != 4); 

    return 0;
}
