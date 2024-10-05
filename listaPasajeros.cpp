#include <iostream>
using namespace std;

struct nodo {
    string nombrePasajero;
    int numeroDocumento;
    char destino;
    nodo *sig;
};

nodo *cab = NULL, *aux, *aux2;
void registrarPasajero(){

    aux=(struct nodo*) malloc(sizeof(nodo));
    cout<<"Ingrese el primer nombre del pasajero: "<<endl;
    cin>>aux->nombrePasajero;
    cout<<"Ingrese numero de documento: "<<endl;
    cin>>aux->numeroDocumento;
    cout<<"Ingrese su destino: "<<endl;
    cout<<"1. La bocana"<<endl;
    cout<<"2. Pianguita"<<endl;
    cout<<"3. Ladrilleros"<<endl;
    cin>>aux->destino;

    
    aux->sig = NULL;

    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=NULL){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }

}
void mostrarListaPasajeros(){
    aux=cab;
    cout<<"-------" <<endl;
    while(aux!=NULL){
        cout<<"Primer nombre: "<<aux->nombrePasajero<<endl;
        cout<<"Documento: "<<aux->numeroDocumento<<endl;
        cout<<"Destino: "<<aux->destino<<endl;
        cout<<"-------"<<endl;

        aux = aux->sig;
    }

}


int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Resgistrar datos de los pasajeros"<<endl<<"2. Mostrar los pasajeros en la lista"<<endl<<"3. Salir del programa"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrarPasajero();
        break;
        case 3:
            cout << "Saliendo del programa"<<endl;
        break;
         }
    }while(opcion!=3);
}
