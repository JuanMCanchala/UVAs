/*

Juan Manuel Canchala 
8983809
Carlos Ramirez
Complejidad: O(n) donde n es el tamño de la cadena de entrada

*/
/*

De lo que me acuerdo basicamente es que tengo la clase nodo que tiene el valor que queramos en este caso un string por lo que es texto y tiene sus hijos el nodo derecho y el nodo izquierdo y luego creo las dos funciones que dijo el profe que son importantes es decir la de construccion y lectura y la de impresion segun el patro que creo ver hay que imprimir del ultimo nivel mas a la dderecha hasta la root es decir que siempre se mira el que este mas a la derecha en su ultimo nivel para estos dos pasos importantes usare pilas y colas

1No mire el caso base cuando es 1 letra 

*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Nodo {
public:
    string valor;
    Nodo* izq;
    Nodo* der;

    // Constructor que toma un string como argumento
    Nodo(string val) {
        valor = val;
        izq = NULL;
        der = NULL;
    }
};

Nodo* construirArbol(string texto) {
    //para el ejemplo xyPzwIM la lectura seria x y y y se apilan en el stack al encontrar P mayuscula y asi sucesivamente hasta encontrar M que queda con hijos P y M
    stack<Nodo*> s;
    //puntero a la raiz del arbol
    Nodo* root = NULL;

    if(texto.size() > 1){
    for (int i = 0; i < texto.size(); i++) {
        char a = texto[i];
        
        // Convertir el carácter a una cadena de longitud 1
        string valorNodo;
        valorNodo += a; // Añadir el caracter a la cadena

        // Crear un nuevo nodo con el valor de la cadena
        Nodo* nuevoNodo = new Nodo(valorNodo);
        
        if (a >= 'A' && a <= 'Z') { // Verificar si el carácter es una letra mayúscula
            Nodo* derNodo = NULL;
            Nodo* izqNodo = NULL;

            // Sacar los dos nodos de la s para asignarlos como hijos
            if (!s.empty()) {
                derNodo = s.top();
                s.pop();
            }
            if (!s.empty()) {
                izqNodo = s.top();
                s.pop();
            }

            nuevoNodo->izq = izqNodo;
            nuevoNodo->der = derNodo;

            s.push(nuevoNodo);
            root = nuevoNodo;
        } else {
            s.push(nuevoNodo);
        }
    }
    }

    // Si quedan nodos en la s y no tienen padre los asigno como hijos de la raíz
    while (!s.empty()) {
        Nodo* act = s.top();
        s.pop();
        if (root->der == NULL) {
            root->der = act;
        } else if (root->izq == NULL) {
            root->izq = act;
        }
    }

    return root;
}

void printArbol(Nodo* root) {
    if (root != NULL) {
        queue<Nodo*> q;
        stack<Nodo*> s;
        q.push(root);

        while (!q.empty()) {
            Nodo* act = q.front();
            q.pop();
            s.push(act);
            if (act->izq != NULL) {
                q.push(act->izq);
            }
            if (act->der != NULL) {
                q.push(act->der);
            }
        }

        while (!s.empty()) {
            Nodo* act = s.top();
            s.pop();
            cout << act->valor;
        }
    }
}


int main() {
    int numcasos;
    cin >> numcasos;
    while (numcasos--) {
        string texto;
        cin >> texto;
        // Creación del árbol

        Nodo* root = construirArbol(texto);
        printArbol(root);
        cout << endl;

    }

    return 0;
}
