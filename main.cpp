#include "Item.h"
#include <fstream>

//Posibilidad de añadir la opción tirar (el item) e implementar un algortimo de búsqueda para eliminar el objeto
//Añadir una introducción tipo videojuego, ej. bienvenido, hoy haremos tu inventario.... (debe ir más allá en cuanto a funcionalidad)
int main() {
    std::string name;
    int cant, type, orden, menu;
    int opcion=1;
    ItemList<int> Inventory;
    
    std::ifstream File("Archivo.txt");
    
    std::cout<<"Extrayendo...\n";
    
    while (File>>name>>cant>>type){
        Inventory.add(name,cant,type);
    };
    std::cout<<"Terminado\n";
    File.close();

    /*-------Menú-------*/
    while (opcion!=0){
        std::cout<<"\nInventario: "<<std::endl;
std::cout<<"\t 0. Cerrar\n\t 1. Mostrar Inventario completo\n\t 2. Agregar Item\n\t 3. Ordenar\n\t 4. Ajustes\n\t"<<std::endl;
        std::cin>>opcion;
        if (opcion==1)
        {
            std::cout<<"\t1. Imprimir al derecho\n\t2. Imprimir al reves\n";
            std::cin>>menu;
            if (menu==1){
                Inventory.print();    
            }
            else if(menu==2){
                Inventory.printContrario();
            }
            else{
                std::cout<<"Opcion no valida, regresando al menu...";
            }
            
        }
        else if (opcion==2)
        {
            std::cout<<"¿Que item desea agregar? (Nombre): "<<std::endl;
            std::cin>>name;
            std::cout<<"¿Cuantos desea agregar?: "<<std::endl;
            std::cin>>cant;
            std::cout<<"¿De que tipo es?\n\t1. Herramienta\n\t2. Utilidad (Arrojadizo)\n\t3. Comida "<<std::endl;
            std::cin>>type;
            Inventory.add(name,cant,type);
            std::ofstream File("Archivo.txt",std::ios::app);
            if(File){
                File<<"\n"<<name<<" "<<cant<<" "<<type;
            }
            File.close();
            std::cout<<"Listo!! Item '"<<name<<"' ha sido agregado\n";
        }
        else if (opcion ==3)
        {
            std::cout<<"A partir de que atributo lo quieres ordenar?\n\t1.Nombre (Alfabeticamente)\n\t2. Cantidad\n\t3. Tipo\n Selecccion: ";
            std::cin>>orden;
            if (orden == 1)
            {
                Inventory.sortAlfabetic();
            }
            if (orden==2)
            {
                Inventory.sortQuant();
            }
            if (orden==3)
            {
                Inventory.sortPriority();
            }        
        }
        else if(opcion==4){
            std::cout<<"\t 1. Buscar un objeto (Nombre)\n\t 2. Mostrar segun 1 tipo\n\t 3. Elminar progreso\n:\t";
            std::cin>>menu;
            if (menu==1){
                std::cout<<"Segun que nombre quiere buscar?: ";
                std::cin>>name;
                if(Inventory.searchName(name)){
                    std::cout<<"Si existe el elemento"<<std::endl;
                }
            }
            else if(menu==2){
                std::cout<<"Segun que tipo quiere buscar?: ";
                std::cin>>type;
                Inventory.filterType(type);
            }
            else if(menu==3){
                std::cout<<"ESTA OPCION ES PERMANENTE, ELIMINARA TODOS LOS OBJETOS DEL INVENTARIO, DESEA CONTINUAR?\n 1. SI\n2. NO";
                std::cin>>orden;
                if(orden==1){
                    std::cout<<"ULTIMA OPORTUNIDAD, ESTAS SEGURO?\n1. SI\n2. NO";
                    std::cin>>orden;
                    if (orden==1){
                        std::cout<<"No te arrepientas...";
                        Inventory.clear();
                        std::ofstream File("Archivo.txt");
                        File.close();
                        std::cout<<"Los datos han sido borrados de forma exitosa.";
                    }
                }
            }
        }
        else if (opcion>4||opcion<0)
        {
            std::cout<<"Opcion no valida, favor de escoger otra"<<std::endl;
        }
    }
    return 0;
}
