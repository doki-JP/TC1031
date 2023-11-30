#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>

template <class T> class ItemLink;
template <class T> class ItemList;

template <class T>
class ItemLink{
    private:

    ItemLink(std::string);
	ItemLink(std::string, T,T);
	ItemLink(std::string, T, T, ItemLink<T>*, ItemLink<T>*);
	ItemLink(const ItemLink<T>&);

	std::string value; //Nombre
	T cantidad;
	T prioridad;
	ItemLink<T> *previous;
	ItemLink<T> *next;

	friend class ItemList<T>;
};

template <class T>
ItemLink<T>::ItemLink(std::string val) : value(val), cantidad(1),prioridad(1) ,previous(0), next(0) {}

template <class T>
ItemLink<T>::ItemLink(std::string val, T quantity, T type) : value(val), cantidad(quantity),prioridad(type) ,previous(0), next(0) {}

template <class T>
ItemLink<T>::ItemLink(std::string val, T quantity, T priority, ItemLink *prev, ItemLink* nxt) : value(val), previous(prev), next(nxt), prioridad(priority),cantidad(quantity) {}

template <class T>
ItemLink<T>::ItemLink(const ItemLink<T> &source) : value(source.value), previous(source.previous), next(source.next), cantidad(source.cantidad), prioridad(source.prioridad) {}

template <class T>
class ItemList{
	public:
	ItemList();
	ItemList(const ItemList<T>&);
	~ItemList();

	void addFirst(std::string, T, T);
	void add(std::string,T,T);
	
	int  length() const;
	bool contains(std::string) const;
	bool empty() const;
	void clear();

	void print();
	void printContrario();
	void operator= (const ItemList&);

	bool searchName(std::string);
	void filterType(T);

	void swapPointers(ItemLink<T>* p1, ItemLink<T>* p2);
	void sortAlfabetic();
	void sortQuant();
	void sortPriority();

private:
	ItemLink<T> *head;
	ItemLink<T> *tail;
	int 	 size;
};

template <class T>
void ItemList<T>::filterType(T type){
	ItemLink<T> *p;
	p = head;
	while (p!=0)
	{
		if (p->prioridad==type){
			std::cout<<"Objeto: "<<p->value<<" Cantidad: "<<p->cantidad<<std::endl;
		}
		p=p->next;
	}
	
};

template <class T>
bool ItemList<T>::searchName(std::string search){ //O(n+3), el ciclo while recorrerá todo el arreglo en el peor de los casos. k=3
	ItemLink<T> *p;
	p=head;
	while (p!=0){
		if (p->value==search){
			return true;
		}
		else{
			return false;
		}
		p=p->next;
	}
}

template <class T>
void ItemList<T>::printContrario(){ // O(n+5), en este caso, el ciclo while DEBE recorrer toda la lista.
	ItemLink<T> *p;
	p = tail;
	while (p != 0) {
		std::cout<<"\nNombre: "<< p->value<<"\n";
		if (p->prioridad==1){
			std::cout<<"Herramienta\n";
		}
		else if(p->prioridad==2){
			std::cout<<"Utilidad\n";
		}
		else if (p->prioridad==3){
			std::cout<<"Comida\n";
		}
		if (p->prioridad!=0)
		{
			std::cout<<"Cantidad: "<< p->cantidad<<"\n";
		}
		
		p = p->previous;
	}
}

template <class T>
void ItemList<T>::print(){
	ItemLink<T> *p;
	p = head;
	while (p != 0) {
		std::cout<<"\nNombre: "<< p->value<<"\n";
		if (p->prioridad==1){
			std::cout<<"Herramienta\n";
		}
		else if(p->prioridad==2){
			std::cout<<"Utilidad\n";
		}
		else if (p->prioridad==3){
			std::cout<<"Comida\n";
		}
		if (p->prioridad!=0)
		{
			std::cout<<"Cantidad: "<< p->cantidad<<"\n";
		}
		p = p->next;
	}
}
/*------------------Código de Diego Isaac Fuentes Juvera con modificaciones muy ligeras------------------*/
template <class T>
void ItemList<T>::swapPointers(ItemLink<T>* p1, ItemLink<T>* p2) {
    // Intercambiar las direcciones de los dos Pokémon utilizando intercambio de apuntadores
    ItemLink<T> *p;
		if (p1 == p2) {
			return;  // No se necesita intercambiar el mismo nodo
		}

		if (head == nullptr || head->next == nullptr) {
			return; // Lista vacía o con un solo elemento, ya está "ordenada".
		}

		p = p1->next;
		p1->next = p2->next;
		p2->next = p;

		if (p1->next != NULL){
			p1->next->previous = p1;
		}
		if (p2->next != NULL){
			p2->next->previous = p2;
		}


		p = p1->previous;
		p1->previous = p2->previous;
		p2->previous = p;

		if (p1->previous != NULL){
			p1->previous->next = p1;
		}
		if (p2->previous != NULL){
			p2->previous->next = p2;
		}

		if(p1 == head){
			head = p2;
		}
		else if (p2 == head){
			head = p1;
		};

		if(p1 == tail){
			tail = p2;
		}
		else if (p2 == tail){
			tail = p1;
		};
	}
/*------------------Fin del código de diego------------------*/

template <class T>
void ItemList<T>::sortQuant() { //O(2n^3) hay 3 for's anidados, resultado en la n^3, dentro del segundo for hay otros dos,
  ItemLink<T>* p1;				// por eso se le asigna el 2n.
  ItemLink<T>* p2;
  p1 = head;
  p2 = p1->next;
  for(int i = 0; i <=size; i++){ 
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->cantidad > p2->cantidad) {
        swapPointers(p1, p2);
  		}
		}
	}
}

template <class T>
void ItemList<T>::sortAlfabetic() {
  ItemLink<T>* p1;
  ItemLink<T>* p2;
  p1 = head;
  p2 = p1->next;
  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->value > p2->value) {
        swapPointers(p1, p2);
  		}
		}
	}
}

template <class T>
void ItemList<T>::sortPriority() {
  ItemLink<T>* p1;
  ItemLink<T>* p2;
  p1 = head;
  p2 = p1->next;
  for(int i = 0; i <=size; i++){
    for (int f = 0; f <(size-i-1); f++ ) {
			p1 = head;
			for (int k = 0; k<i; k++){
				p1 = p1->next;
			}
			p2 = p1->next;
			for (int m = 0; m<f; m++){
				p2 = p2->next;
			}
      if (p1->prioridad > p2->prioridad) {
        swapPointers(p1, p2);
  		}
		}
	}
}

template <class T>
ItemList<T>::ItemList() : head(0), tail(0), size(0) {}

template <class T>
ItemList<T>::~ItemList() {
	clear();
}

template <class T>
bool ItemList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
int ItemList<T>::length() const {
	return size;
}

template <class T>
bool ItemList<T>::contains(std::string val) const {
	ItemLink<T> *p;
	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void ItemList<T>::addFirst(std::string val, T quantity, T priority){
	ItemLink<T> *newLink;
	newLink = new ItemLink<T>(val);
	if (newLink == 0) {
		std::cout<<"\n===|===|No hay memoria|===|===\n";
	}
	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		newLink->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}

template <class T>
void ItemList<T>::add(std::string val, T quantity, T priority){
	ItemLink<T> *newLink;

	newLink = new ItemLink<T>(val, quantity, priority);
	if (newLink == 0) {
		std::cout<<"\n===|===|No hay memoria|===|===\n";
	}
	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
void ItemList<T>::clear() {
	ItemLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
ItemList<T>::ItemList(const ItemList<T> &source){
	ItemLink<T> *p, *q;
	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new ItemLink<T>(p->value);
		if (head == 0) {
			std::cout<<"===|===|No existe el elemento|===|===\n";
		}
		q = head;
		p = p->next;
		while(p != 0) {
			q->next = new ItemLink<T>(p->value, q, 0);
			if (q->next == 0) {
				std::cout<<"===|===|No hay memoria disponible|===|===\n";
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
void ItemList<T>::operator=(const ItemList<T> &source){
	ItemLink<T> *p, *q;

	clear();
	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new ItemLink<T>(p->value);
		if (head == 0) {
			std::cout<<"===|===|No hay memoria disponible|===|===\n";
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new ItemLink<T>(p->value, q, 0);
			if (q->next == 0) {
				std::cout<<"===|===|No hay memoria disponible|===|===\n";
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

#endif
