#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
    char nombrePasajero[30];
    int numeroDocumento;
    int destino;
    nodo *sig;
};

nodo *cab, *aux, *aux2;
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
void ordenarListaPorDestino(){

    int temporalDe;
    int temporalDo;
    char temporalNo[30];

    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->destino > aux->sig->destino){
                temporalDe = aux->destino;
                aux->destino = aux->sig->destino;
                aux->sig->destino = temporalDe;
                }
            
                if(aux->numeroDocumento>aux->sig->numeroDocumento){
                temporalDo = aux->numeroDocumento;
                aux->numeroDocumento = aux->sig->numeroDocumento;
                aux->sig->numeroDocumento = temporalDo;

                for (int i = 0; i < 30; i++) {
                    temporalNo[i] = aux->nombrePasajero[i];
                    aux->nombrePasajero[i] = aux->sig->nombrePasajero[i];
                    aux->sig->nombrePasajero[i] = temporalNo[i];
                }
            }
            
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }

    cout<<"Lista ordenada por destino y documento: "<<endl;
    aux = cab;  
    while (aux != NULL) {  
        cout<< "Nombre: " <<aux->nombrePasajero <<endl;
        cout<< "Documento: " <<aux->numeroDocumento <<endl;
        cout<< "Destino: " <<aux->destino <<endl;
        cout<< "----------" <<endl;
        aux = aux->sig;
    }
}    

int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Resgistrar datos de los pasajeros"<<endl<<"2. Mostrar los pasajeros en la lista"<<endl<<"3. Lista ordenada por destino y documento"<<endl<<"4. Salir del programa"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrarPasajero();
        break;
        case 2:
            mostrarListaPasajeros();
        break;
        case 3:
            ordenarListaPorDestino();
        break;
        case 4:
            cout << "Saliendo del programa"<<endl;
        break;
        }
    
    }while(opcion!=4);

}
