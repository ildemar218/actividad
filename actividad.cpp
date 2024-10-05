#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int documento;
    char destino;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

void registrar(){ // funcion para agregar un nuevo estudiante a la lista 
    aux = new nodo;
    cout<<"ingrese el nombre: ";
    cin>>aux->nombre;
    cout<<"documento: ";
    cin>>aux->documento;
    cout<<"elija su destino: "<< endl;
    cout<<"1:bocana:" << endl;
    cout<<"2:pianguita:" << endl;
    cout<<"3:ladrilleros:";
    cin>>aux->destino;
    aux->sig = nullptr;
    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=nullptr){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
    
}



int main(){
    int opcion;
    char respuesta;
    do {
        cout << "Menu" << endl
            << "1. Registrar pasajero" << endl
            << "2. Mostrar pasajero" << endl
            //<< "3. Ordenar en base a codigos" << endl
            //<< "4. Ordenar en base a notas" << endl
            //<< "5. clacular mayor y menor" << endl
            << "6. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                do {
                    registrar();
                    cout << "Desea agregar otro pasajero? (s/n): ";
                    cin >> respuesta;
                } while (respuesta == 's' || respuesta == 'S');
                break;

        }
    } while(opcion != 6);

    return 0;
}