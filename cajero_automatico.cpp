#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

struct cajero_automatico
{
    string nombre;
    string contrasena;
    int depositar;
    float saldo;
};
void datos( vector<cajero_automatico>& usuario, int cantidad){
    
    for (int i = 0; i < cantidad; i++)
    {
        cout<<"\nNombre:";
        cin>>usuario[i].nombre;
        cout<<"ingrese PIN: ";
        cin>>usuario[i].contrasena;
        
    }
}

void plata(vector<cajero_automatico>& usuario, int cantidad){
    srand(time(nullptr));
    for (int i = 0; i < cantidad; i++){

    usuario[i].saldo= 1000 + rand() % 30000;
    cout<<"\nSaldo: $"<<usuario[i].saldo;
    char opcion;

    cout<<"\nDesea retirar efectivo? (s/n)\n";
    cin>>opcion;
    while (opcion=='s'||opcion=='S'){
        if (usuario[i].saldo<=1000)
        {
            cout<<"\nNose pude retirara efectivo."<<
            "\n Debe ser mayor a $1000 para pode retirar efectivo"<<endl;
            break;
        }else{
            int efectivo;
            cout<<"\nCuanto desea retirar? \n$";
            cin>>efectivo;
           
            while (efectivo>usuario[i].saldo && efectivo<=0)
            {
                cout<<"\nEl monto ingresado es mayor al disponible o menor a $1000."
                <<"\n Ingrese otro monto a retirar."<<endl;
                cin>>efectivo;

            }
                float saldo_disponible=usuario[i].saldo-=efectivo;
                cout<<"\nSaldo $"<<saldo_disponible<<endl;
                if (saldo_disponible<=0)
                {
                    cout<<"\nNo tiene mas saldo disponible";
                    
                }else{
                   
                    cout<<"saldo disponible: $"<<saldo_disponible<<endl;
                    cout << "\nDesea hacer otra extraccion? (s/n): ";
                    cin >> opcion;
                   
                }
            } 
        }
        
    }
        
}
    
        



void verificar(vector<cajero_automatico>& usuario, int cantidad){
    bool encontrado=false;
    for (int i = 0; i < 3; i++)
    {
        string buscar, cons;
        cout<<"\nIntento#"<<i+1<<endl;
        cout << "Nombre: ";
        cin >> buscar;
        cout << "Contrasena: ";
        cin >> cons;
        for (int i = 0; i < cantidad; i++){
            if (usuario[i].contrasena == cons && usuario[i].nombre==buscar){
                cout << "\nBienvenido..." << usuario[i].nombre<<endl;
                plata(usuario, cantidad);
                encontrado = true;
                break;
            }
        }
        if (encontrado){
            break; //para que salga del bucle si lo encuentra

        }else{
            cout<<"\nNose encontro el usuario.";
        }
        
    }
    if (!encontrado) {
        cout << "\nAcceso denegado. Superaste el límite de intentos.\n";
    }
    
}

int main(){
    int cantidad;
    cout<<"Usuarios#: ";
    cin>>cantidad;
    vector<cajero_automatico> usuario(cantidad);
    datos(usuario,cantidad);
    verificar(usuario,cantidad);

    system("pause");
    return 0;
}