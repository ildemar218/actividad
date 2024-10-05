#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct nodo {
    string nombre;
    int documento;
    char destino;
    nodo *sig;
};

nodo *cab=nullptr, *aux, *aux2;

void registrar(){ // funcion para agregar un nuevo pasajero a la lista 
    aux = (struct nodo *) malloc (sizeof(nodo));
    cout<<"ingrese el nombre: ";
    cin>>aux->nombre;
    cout<<"documento: ";
    cin>>aux->documento;
    cout<<"elija el numero de su destino: "<< endl;
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
void mostrar(){ // recorre la lista para mostrar los estudiantes codigos y notas
    aux=cab;
    cout<<"--------- "<<endl;
    while(aux!=nullptr){
        cout<<"nombre: "<<aux->nombre<<endl;
        cout<<"documento: "<<aux->documento<<endl;
        cout<<"destino: "<<aux->destino<<endl;
        cout<<"--------- "<<endl;
        aux = aux->sig;
    }
}


int main(){
    int opcion;

    do {
        cout << "Menu" << endl
            << "1. Registrar pasajero" << endl
            << "2. Mostrar pasajero" << endl
            //<< "3. Ordenar en base a codigos" << endl
            //<< "4. Ordenar en base a notas" << endl
            //<< "5. clacular mayor y menor" << endl
            << "3. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                    registrar();
                break;
            case 2:
                mostrar();
                break;    
        }
    } while(opcion != 3);

    return 0;
}