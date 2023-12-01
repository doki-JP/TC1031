#ifndef ITEM_H
#define ITEM_H
/*
Referencias: en este proyecto existe una funciones que no son de mi autoría, que es el sort utilizado, 
se modificó para que se pudiera utilizar de acuerdo a las necesidades de mi proyecto mas no fue un cambio radical, es por esto que los
3 sorts dentro del proyecto tienen la misma estructura.
Según varias universidades e instituciones, referenciar un código debe de ser de la siguiente manera: Autor, Fecha de publicación, 
Título, versión, tipo y la url del código.

Referencia: ckebar, 5/Nov/2019, SO58573297 Initial solution of bubblesort with re-wiring of the double-linked list, versión desconocida
recuperado el 29 de Noviembre de 2023 de: https://github.com/ckebar/SO58573297

Referencia: University of Cincinatti (n.d.). Research guides: Citing your sources: citing computer code. https://guides.libraries.uc.edu/citing/code

*/

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

//----------------Obtenido mediante investigación, este código NO es de mi autoría, sino que lo referencio para que se conozca el origen (abajo)
template <class T>
void ItemList<T>::sortQuant() {//bubblesort() - O(n)
bool is_sorted = false;
	ItemLink<T> *temp = head;
	while (!is_sorted)
	{
		is_sorted = true;
		temp = head;
		while (temp->next != NULL)
		{
			if(temp->next->cantidad < temp->cantidad)
			{
				is_sorted = false;
				if(temp == head)
				{
					//temp->prev->next = temp->next; // 1. (impossible)
					temp->next->previous = NULL;         // 2.
					head = temp->next;
				}
				else
				{
					temp->previous->next = temp->next;   // 1.
					temp->next->previous = temp->previous;   // 2.
				}
				temp->previous = temp->next;             // 3.
				if(temp->next == tail)
				{
					temp->next = NULL;               // 4.
					tail = temp;
					//temp->next->prev = temp2;      // 5. (impossible)
				}
				else
				{
					temp->next = temp->next->next;   // 4.
					temp->next->previous = temp;         // 5.
				}
				temp->previous->next = temp;             // 6.
				temp = temp->previous;
			}
			temp = temp->next;
		}
	}
}
//----------https://stackoverflow.com/questions/58573297/bubble-sort-doubly-link-list

template <class T>
void ItemList<T>::sortAlfabetic() {
bool is_sorted = false;
	ItemLink<T> *temp = head;
	while (!is_sorted)
	{
		is_sorted = true;
		temp = head;
		while (temp->next != NULL)
		{
			if(temp->next->value < temp->value)
			{
				is_sorted = false;
				if(temp == head)
				{
					//temp->prev->next = temp->next; // 1. (impossible)
					temp->next->previous = NULL;         // 2.
					head = temp->next;
				}
				else
				{
					temp->previous->next = temp->next;   // 1.
					temp->next->previous = temp->previous;   // 2.
				}
				temp->previous = temp->next;             // 3.
				if(temp->next == tail)
				{
					temp->next = NULL;               // 4.
					tail = temp;
					//temp->next->prev = temp2;      // 5. (impossible)
				}
				else
				{
					temp->next = temp->next->next;   // 4.
					temp->next->previous = temp;         // 5.
				}
				temp->previous->next = temp;             // 6.
				temp = temp->previous;
			}
			temp = temp->next;
		}
	}
}

template <class T>
void ItemList<T>::sortPriority() {
bool is_sorted = false;
	ItemLink<T> *temp = head;
	while (!is_sorted)
	{
		is_sorted = true;
		temp = head;
		while (temp->next != NULL)
		{
			if(temp->next->prioridad < temp->prioridad)
			{
				is_sorted = false;
				if(temp == head)
				{
					//temp->prev->next = temp->next; // 1. (impossible)
					temp->next->previous = NULL;         // 2.
					head = temp->next;
				}
				else
				{
					temp->previous->next = temp->next;   // 1.
					temp->next->previous = temp->previous;   // 2.
				}
				temp->previous = temp->next;             // 3.
				if(temp->next == tail)
				{
					temp->next = NULL;               // 4.
					tail = temp;
					//temp->next->prev = temp2;      // 5. (impossible)
				}
				else
				{
					temp->next = temp->next->next;   // 4.
					temp->next->previous = temp;         // 5.
				}
				temp->previous->next = temp;             // 6.
				temp = temp->previous;
			}
			temp = temp->next;
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
