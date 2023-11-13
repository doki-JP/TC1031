#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>

//NO SE HA IMPLEMENTADO PRINT()
//NO SE HA IMPLEMENTADO INSERTIONSORT()

template <class T> class ItemLink;
template <class T> class ItemList;

template <class T>
class ItemLink{
    private:

    ItemLink(std::string);
	ItemLink(std::string, T, T, ItemLink<T>*, ItemLink<T>*);
	ItemLink(const ItemLink<T>&);

	std::string value; //Nombre
	T cantidad;
	T prioridad;
	ItemLink<T> *previous;
	ItemLink<T> *next;

	friend class ItemList<T>;

    public:
    
};

template <class T>
ItemLink<T>::ItemLink(std::string val) : value(val), cantidad(1),prioridad(1) ,previous(0), next(0) {}

template <class T>
ItemLink<T>::ItemLink(std::string val, T quantity, T priority, ItemLink *prev, ItemLink* nxt) : value(val), previous(prev), next(nxt), cantidad(1) {}

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


	T    getFirst() const ;
	T    get(int) const;
	T	 getLast() const ;

	T    removeFirst() ;
	T    removeLast() const;
	
	int  length() const;
	bool contains(std::string) const;
	bool empty() const;
	void clear();

	void print(); //NO HA SIDO IMPLEMENTADO
	void operator= (const ItemList&);


	bool set(int, T);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);
	void Insertionsort();

private:
	ItemLink<T> *head;
	ItemLink<T> *tail;
	int 	 size;
};

template <class T>
void ItemList<T>::print(){

	ItemLink<T> *p;
	p = head;
	while (p != 0) {
		std::cout<<"Nombre: "<< p->value<<"\n";
		std::cout<<"Cantidad: "<< p->cantidad<<"\n";
		if (p->prioridad==1){
			std::cout<<"Herramienta\n";
		}
		else if(p->prioridad==2){
			std::cout<<"Utilidad\n";
		}
		else if (p->prioridad==3){
			std::cout<<"Comida\n";
		}
		p = p->next;
	}
} // SIN IMPLEMENTAR

template <class T>
void ItemList<T>::Insertionsort(){ //SIN IMPLEMENTAR
	if (head == 0 || head->next == 0) {
        // La lista está vacía o tiene un solo elemento, ya está "ordenada".
        return;
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
T ItemList<T>::getFirst() const{
	if (empty()) {
		std::cout<<"\n===|===|No existe el valor|===|===\n";
	}
	return head->value;
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

	newLink = new ItemLink<T>(val);
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
T ItemList<T>::removeFirst(){
	T val;
	ItemLink<T> *p;

	if (empty()) {
		std::cout<<"\n===|===|No existe el elemento|===|===\n";
	}
	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return val;
}

template <class T>
T ItemList<T>::get(int index) const {
	int pos;
	ItemLink<T> *p;
	if (index < 0 || index >= size) {
		std::cout<<"===|===|Indice no valido|===|===\n";
	}
	if (index == 0) {
		return getFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
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
T ItemList<T>::remove(int index) {
	int pos;
	T val;
	ItemLink<T> *p;

	if (index < 0 || index >= size) {
		std::cout<<"===|===|Indice no valido|===|===\n";
	}

	if (index == 0) {
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;

	return val;
}

template <class T>
bool ItemList<T>::removeFirstOcurrence(T val) {
	ItemLink<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			break;
		}
		p = p->next;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
}

template <class T>
bool ItemList<T>::removeLastOcurrence(T val) {
	ItemLink<T> *p;

	p = tail;
	while (p != 0) {
		if (p->value == val) {
			break;
		}
		p = p->previous;
	}

	if (p != 0) {
		if (p->previous == 0) {
			head = p->next;
			p->next->previous = 0;
		} else {
			p->previous->next = p->next;
			if (p->next != 0) {
				p->next->previous = p->previous;
			}
		}
		size--;
		return true;
	}

	return false;
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
