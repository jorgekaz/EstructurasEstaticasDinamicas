#include <stdio.h>
#include <stdlib.h>
#define ESC 27

typedef struct{
    char nombre[30];
    char genero;
    int edad;
}stPersona;

///Estructura PILA
typedef struct{
    int valores[100];
    int posTope;
}Pila;

typedef struct {
  int matricula;
  char nombre[30];
} stAlumno;

typedef struct {
  int codigo;
  char nombreMat[20];
} stMateria ;

typedef struct {
  int matricula;
  int codigo;
  int nota;
} stNota;

/// 1
char cargarGenero(); ///a
int deseaContinuar(); ///a
int cargarArregloPersonas(stPersona personas[], int dimension); ///a
int calcularCantidadPorGenero(stPersona personas[], int validos, char* genero); ///b
void crearArregloSegunGenero(stPersona personas[], stPersona personasPorGenero[], int validos, char genero); ///c
void mostrarArreglo(stPersona personas[], int validos);
/// 2
int posicionMenor(stPersona personas[], int validos, int pos);
void intercambioValores(stPersona* personaA, stPersona* personaB);
void ordenarPorSeleccion(stPersona personas[], int validos);

///3 PILA
void apilar(Pila* p, int valor);
int desapilar(Pila* p);
int tope(Pila* p);
int pilavacia(Pila* p);
void mostrar(Pila* p);
void leer(Pila* p);
void inicPila(Pila* p);

///4
Pila unirPilasOrdenadas(Pila pilaA, Pila pilaB);

///5
int insertarOrdenado(int arregloNumeros[], int validos, int nuevoValor);
void mostrarArregloNumeros(int arregloNumeros[], int validos);
///6
void insertar(int arregloNumeros[], int validos, int nuevoValor);
void ordenarInsercion(int arregloNumeros[], int validos);
///7
void eliminarElemento(int arreglo[], int* validos, int elemento);

///8
int materiaExiste(stMateria mats[], int codigo, int validos);
int nombreValido(stMateria mats[], char nombre[], int validos);
void cargarMateria(stMateria mats[], int indice);
int matriculaExiste(stAlumno alus[], int matricula, int validos);
void cargarAlumno(stAlumno alus[], int indice);
int agregarNota(stAlumno alus[],stMateria mats[],stNota notas[],int validosAlus,int validosMats,int validosNotas);
int obtenerMatricula(stAlumno alus[],int validosAlus, char alumno[]);
int buscarNombreMateria(stMateria mats[], int validosMats, int codigo);
void mostrarDetallesAlumno(stAlumno alus[],stMateria mats[],stNota notas[],char alumno[],int validosAlus,int validosMats,int validosNotas);

int main()
{
    printf("\n --------------------------------\n");
    printf("  EJERCICIO 1");
    printf("\n --------------------------------\n");
    const int dimension = 30;
    stPersona personas[dimension];
    int validos;
    int cantidadSegunGenero;
    char genero;
    validos = cargarArregloPersonas(personas,dimension);

    printf("\n");
    printf(" CANTIDAD DE PERSONAS SEGUN GENERO\n");
    cantidadSegunGenero = calcularCantidadPorGenero(personas,validos,&genero);
    printf("\n");

    printf(" LA CANTIDAD DE PERSONAS DEL GENERO %c es %i: \n\n", genero, cantidadSegunGenero);
    printf(" CREAR ARREGLO DINAMICO DE PERSONAS SEGUN GENERO\n");

    cantidadSegunGenero = calcularCantidadPorGenero(personas, validos, &genero);
    printf("\n ARREGLO\n\n");
    if (cantidadSegunGenero > 0){
        stPersona* personasPorGenero = (stPersona*) malloc( cantidadSegunGenero * (sizeof(stPersona)));
        crearArregloSegunGenero(personas, personasPorGenero, validos, genero);
        mostrarArreglo(personasPorGenero, cantidadSegunGenero);
    }

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 2");
    printf("\n --------------------------------\n");
    ordenarPorSeleccion(personas, validos);
    printf("\n ARREGLO ORDENADO\n\n");
    mostrarArreglo(personas, validos);

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 3");
    printf("\n --------------------------------\n");
    printf(" FUNCIONES");

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 4");
    printf("\n --------------------------------\n");
    Pila pila, otraPila, pilaOrdenada;
    inicPila(&pila);
    inicPila(&otraPila);
    inicPila(&pilaOrdenada);
    apilar(&pila, 10);
    apilar(&pila, 11);
    apilar(&pila, 12);
    apilar(&pila, 15);
    apilar(&pila, 16);
    apilar(&pila, 18);
    apilar(&otraPila, 7);
    apilar(&otraPila, 8);
    apilar(&otraPila, 9);
    apilar(&otraPila, 13);
    apilar(&otraPila, 14);
    apilar(&otraPila, 17);
    //leer(&pila);
    //leer(&pila);
    //mostrar(&pila);
    //printf("El tope de la pila es %i \n", tope(&pila));
    //desapilar(&pila);
    mostrar(&pila);
    mostrar(&otraPila);

    pilaOrdenada = unirPilasOrdenadas(pila, otraPila);
    mostrar(&pilaOrdenada);
    //printf("El tope de la pila es %i \n", tope(&pila));
    //if (pilavacia(&pila)){
    //    printf("La pila esta vacia.");
    //} else {
    //    printf("Pila con datos.");
    //}

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 5");
    printf("\n --------------------------------\n");
//    int validos = 5;
    int arregloNumeros[10] = {1,4,6,9,12};
    insertar(arregloNumeros, validos, 0);
    mostrarArregloNumeros(arregloNumeros, validos+1);

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 6");
    printf("\n --------------------------------\n");
    validos = 6;
    int otroArregloNumeros[10] = {4,1,3,6,11,0};
    ordenarInsercion(otroArregloNumeros, validos);
    mostrarArregloNumeros(otroArregloNumeros, validos);

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 7");
    printf("\n --------------------------------\n");
    eliminarElemento(otroArregloNumeros, &validos, 6);
    mostrarArregloNumeros(otroArregloNumeros, validos);
    printf("\n");

    printf("\n --------------------------------\n");
    printf("  EJERCICIO 8");
    printf("\n --------------------------------\n");

    const int dimAlus = 20;
    const int dimMats = 5;
    const int dimNotas = 100;
    int validosAlus = 0;
    int validosMats = 0;
    int validosNotas = 0;
    stAlumno alus[dimAlus]; // para almacenar los datos de los 20 alumnos.
    stMateria mats[dimMats]; // para almacenar los códigos y nombres de las 5 materias.
    stNota notas[dimNotas]; // para almacenar todas las notas de los alumnos.

    char alumno[30];

    /// menu
    char opcion;
    do {
        system("cls");
        printf("SISTEMA NOTAS ALUMNOS\n");
        printf("Menu de opciones: \n\n");
        printf("1.- Cargar Materias.\n");
        printf("2.- Cargar Alumnos. \n");
        printf("3.- Cargar Notas.  \n");
        printf("4.- Mostrar detalles de un Alumno: \n");
        printf("\n\n\nESC.- Salir. \n");
        fflush(stdin);
        opcion = getch();

        switch (opcion) {
        case '1':
            if (validosMats < dimMats) {
                cargarMateria(mats, validosMats);
                validosMats++;
            } else {
                printf("\nHa llegado al maximo de materias\n\n\n");
                system("pause");
            }
            break;
        case '2':
            if (validosAlus < dimAlus) {
                cargarAlumno(alus, validosAlus);
                validosAlus++;
            } else {
                printf("\nHa llegado al maximo de alumnos\n\n\n");
                system("pause");
            }
            break;
        case '3':
            if (validosNotas < dimNotas) {
                int notaAgregada = agregarNota(alus, mats, notas, validosAlus, validosMats, validosNotas);
                if (notaAgregada) {
                    printf("\n\nSe agrego la nota en forma satisfactoria.\n");
                    validosNotas++;
                } else {
                    printf("\n\nNo se logro agregar la nota.\n");
                }
            } else {
                printf("\nHa llegado al maximo de notas\n\n\n");
            }
            system("pause");
            break;
        case '4':
            printf("Ingrese el nombre del alumno por el cual consulta: ");
            scanf("%s", alumno);
            mostrarDetallesAlumno(alus, mats, notas, alumno, validosAlus, validosMats, validosNotas);
            break;
        }
    } while (opcion != ESC);

    return 0;
}

char cargarGenero(){
    char opcionGenero;
    do{
        printf("\n INGRESE EL GENERO (F/ M/ O)");
        fflush(stdin);
        scanf("%c", &opcionGenero);
    }while(opcionGenero != 'F' && opcionGenero != 'M' && opcionGenero != 'O');

    return opcionGenero;
}

int deseaContinuar(){
    char opcion;
    printf("\n DESEA CARGAR OTRA PERSONA? (S/N)");
    fflush(stdin);
    scanf("%c", &opcion);
    if(opcion=='S' || opcion == 's'){
        return 1;
    }

    return 0;
}

int cargarArregloPersonas(stPersona personas[], int dimension){
    int i=0;
    do{
        system("cls");
        printf(" INGRESE EL NOMBRE DE LA PERSONA: ");
        fflush(stdin);
        scanf("%s", personas[i].nombre);

        personas[i].genero = cargarGenero();
        printf("\n");
        printf(" INGRESE LA EDAD: ");
        fflush(stdin);
        scanf("%i", &personas[i].edad);
        i++;
    }while (i< dimension && deseaContinuar());

    return i;
}

int calcularCantidadPorGenero(stPersona personas[], int validos, char* genero){
    int cantidad=0;
    *genero = cargarGenero();

    for(int i=0; i<validos; i++){
        if(personas[i].genero == *genero){
            cantidad++;
        }
    }
    return cantidad;
}

void crearArregloSegunGenero(stPersona personas[], stPersona personasPorGenero[], int validos, char genero){
    int j=0;
    for(int i=0; i< validos; i++){
        if(personas[i].genero == genero){
            personasPorGenero[j]=personas[i];
            j++;
        }
    }
}

void mostrarArreglo(stPersona personas[], int validos){
    for(int i=0;i<validos;i++){
        printf(" NOMBRE: %s\n", personas[i].nombre);
        printf(" GENEROS: %c\n", personas[i].genero);
        printf(" EDAD: %i\n", personas[i].edad);
        printf("--------------------------------\n");
    }
}

int posicionMenor(stPersona personas[], int validos, int pos){
    int menor = personas[pos].edad;
    int posMenor = pos;
    int indice = pos+1;
    while(indice<validos){
        if(menor>personas[indice].edad){
            menor = personas[indice].edad;
            posMenor = indice;
        }
        indice++;
    }
    return posMenor;
}

void intercambioValores(stPersona* personaA, stPersona* personaB){
    stPersona personaAux;
    personaAux = *personaA;
    *personaA = *personaB;
    *personaB = personaAux;
}

void ordenarPorSeleccion(stPersona personas[], int validos){
    int posMenor;
    int i=0;
    while(i<validos-1){
        posMenor = posicionMenor(personas, validos,i);
        intercambioValores(&personas[posMenor],&personas[i]);
        i++;
    }
}

/// FUNCIONES PILAS
void apilar(Pila* p, int valor){
    p->valores[p->posTope] = valor;
    p->posTope++;
}

int desapilar(Pila* p){
    int ultimoValor = p->valores[p->posTope-1];
    p->posTope--;

    return ultimoValor;
}

int tope(Pila* p){
    return p->valores[p->posTope - 1];
}

int pilavacia(Pila* p){
    if(p->posTope==0){
        return 1;
    }
    return 0;
}

void mostrar(Pila* p){
    for(int i=0; i<p->posTope; i++){
        printf("| %i |\n", p->valores[i]);
    }
}

void leer(Pila* p){
    printf(" INGRESE UN ELEMENTO A LA PILA: ");
    fflush(stdin);
    scanf("%i", &p->valores[p->posTope]);
    p->posTope++;
}

void inicPila(Pila* p){
    p->posTope = NULL;
}

///4
Pila unirPilasOrdenadas(Pila pilaA, Pila pilaB){
    Pila pilaOrdenada;
    Pila pilaAAux;
    Pila pilaBAux;
    inicPila(&pilaOrdenada);
    inicPila(&pilaAAux);
    inicPila(&pilaBAux);

    while(!pilavacia(&pilaA) && !pilavacia(&pilaB)){
        if(tope(&pilaA)>tope(&pilaB)){
            apilar(&pilaAAux, tope(&pilaA));
            apilar(&pilaOrdenada, desapilar(&pilaA));
        }else if(tope(&pilaA)<tope(&pilaB)){
            apilar(&pilaBAux, tope(&pilaB));
            apilar(&pilaOrdenada, desapilar(&pilaB));
        }else{
            apilar(&pilaAAux, tope(&pilaA));
            apilar(&pilaOrdenada, desapilar(&pilaA));
            apilar(&pilaBAux, tope(&pilaB));
            apilar(&pilaOrdenada, desapilar(&pilaB));
        }
    }
        ///CORTA EL CICLO CUANDO UNA DE LAS DOS PILAS ESTA VACIA
    while(!pilavacia(&pilaA)){
        apilar(&pilaAAux, tope(&pilaA));
        apilar(&pilaOrdenada,desapilar(&pilaA));
    }

    while(!pilavacia(&pilaB)){
        apilar(&pilaBAux, tope(&pilaB));
        apilar(&pilaOrdenada,desapilar(&pilaB));
    }

        /// RECUPERO LAS DOS PILAS ORIGINALES, NO HAY PERDIDA DE DATOS.
    while(!pilavacia(&pilaAAux)){
        apilar(&pilaA, desapilar(&pilaAAux));
    }
    while(!pilavacia(&pilaBAux)){
        apilar(&pilaB, desapilar(&pilaBAux));
    }

        /// DOY VUELTA LA PILA ORDENADA, UTILIZANDO UN AUXILIAR DE OTRA PILA QUE AHORA ESTA VACIO
    while(!pilavacia(&pilaOrdenada)){
        apilar(&pilaAAux,desapilar(&pilaOrdenada));
    }

    return pilaAAux;
}

///5
int insertarOrdenado(int arregloNumeros[], int validos, int nuevoValor){
    int flag = 0;
    for (int i = validos - 1; i >= 0 && flag == 0; i--){
        if (nuevoValor >= arregloNumeros[i]) {
            arregloNumeros[i+1] = nuevoValor;
            flag=1;
        } else {
            arregloNumeros[i+1] = arregloNumeros[i];
        }
    }
    if (flag == 0) { // Nunca corto por mayor, es decir es el mas chico de los numeros y nunca se copio al arreglo
        arregloNumeros[0] = nuevoValor;
    }
    validos++;
    return validos;
}

void mostrarArregloNumeros(int arregloNumeros[], int validos){
    for (int i = 0; i < validos; i++){
        printf("%i ", arregloNumeros[i]);
    }
}

void insertar(int arregloNumeros[], int validos, int nuevoValor){
    int i = validos - 1;
    while (i >= 0 && nuevoValor < arregloNumeros[i]){
        arregloNumeros[i+1] = arregloNumeros[i];
        i--;
    }
    arregloNumeros[i+1] = nuevoValor;
}

void ordenarInsercion(int arregloNumeros[], int validos){
    int indice = 0;
    while (indice < validos){
        insertar(arregloNumeros, indice, arregloNumeros[indice]);
        indice++;
    }
}

void eliminarElemento(int arreglo[], int* validos, int elemento){
    int cantVal = *validos;
    for (int i = 0; i < cantVal; i++){
        if (arreglo[i] == elemento){
            for (int j=i; j < cantVal - 1; j++){
                arreglo[j] = arreglo[j+1];
            }
            cantVal--;
            i--; // Vuelvo hacia atras para que compare el numero que corri, y evitar que no borre un duplicado
        }
    }
    *validos = cantVal;
}

///8
int materiaExiste(stMateria mats[], int codigo, int validos){
    int indice = 0;
    int codigoExiste = 0;
    while (!codigoExiste && indice < validos) {
        if (mats[indice].codigo == codigo){
            codigoExiste = 1;
        } else {
            codigoExiste = 0;
        }
        indice++;
    }
    return codigoExiste;
}

int nombreValido(stMateria mats[], char nombre[], int validos){
    int indice = 0;
    int nombreValido = 0;
    while (!nombreValido && (indice < validos || validos == 0)) {
        if (strlen(nombre) != 0){
            if (strcmpi(mats[indice].nombreMat, nombre) != 0){
                nombreValido = 1;
            } else  {
                nombreValido = 0;
            }
        }
        indice++;
    }
    return nombreValido;
}

void cargarMateria(stMateria mats[], int indice){
    int codigo;
    char nombre[20];
    do {
        printf("\nIngrese codigo de la materia: ");
        scanf("%i", &codigo);
    } while (indice > 0 && materiaExiste(mats, codigo, indice));

    do {
        printf("\nIngrese nombre de la materia: ");
        scanf("%s", &nombre);
    } while (indice > 0 && !nombreValido(mats, nombre, indice));

    mats[indice].codigo = codigo;
    strcpy(mats[indice].nombreMat, nombre);
}

int matriculaExiste(stAlumno alus[], int matricula, int validos){
    int indice = 0;
    int matExiste = 0;
    while (!matExiste && indice < validos) {
        if (alus[indice].matricula == matricula){
            matExiste = 1;
        } else {
            matExiste = 0;
        }
        indice++;
    }
    return matExiste;
}

void cargarAlumno(stAlumno alus[], int indice){
    int matricula;
    char nombre[30];
    do {
        printf("\nIngrese numero de matricula: ");
        scanf("%i", &matricula);
    } while (indice > 0 && matriculaExiste(alus, matricula, indice));

    do {
        printf("\nIngrese nombre del alumno: ");
        scanf("%s", &nombre);
    } while (strlen(nombre)<=0);

    alus[indice].matricula = matricula;
    strcpy(alus[indice].nombre, nombre);
}

int agregarNota(stAlumno alus[],stMateria mats[],stNota notas[],int validosAlus,int validosMats,int validosNotas){
    int matricula;
    int codigo;
    int nota;
    printf("\nIngrese numero de matricula: ");
    scanf("%i", &matricula);
    printf("\nIngrese codigo de la materia: ");
    scanf("%i", &codigo);
    printf("\nIngrese nota: ");
    scanf("%i", &nota);

    if (materiaExiste(mats, codigo, validosMats) && matriculaExiste(alus, matricula, validosAlus)) {
        int indice = 0;
        int itemCargado = 0;
        while (indice <= validosNotas && !itemCargado){
            if (notas[indice].codigo == codigo && notas[indice].matricula == matricula){
                itemCargado = 1;
            }
            indice++;
        }
        if (!itemCargado){
            notas[validosNotas].codigo = codigo;
            notas[validosNotas].matricula = matricula;
            notas[validosNotas].nota = nota;
            return 1;
        }
    }
    return 0;
}
int obtenerMatricula(stAlumno alus[],int validosAlus, char alumno[]){
    int indice = 0;
    int matricula = -1;
    while (indice < validosAlus && matricula == -1){
        if (strcmp(alus[indice].nombre, alumno) == 0){
            matricula = alus[indice].matricula;
        }
        indice++;
    }
    return matricula;
}

int buscarNombreMateria(stMateria mats[], int validosMats, int codigo){
    int indice = 0;
    int flag = 0;
    while (indice < validosMats && flag == 0){
        if (mats[indice].codigo == codigo){
            flag = 1;
        }
        indice++;
    }
    return indice - 1;
}

void mostrarDetallesAlumno(stAlumno alus[],stMateria mats[],stNota notas[],char alumno[],int validosAlus,int validosMats,int validosNotas){
    int matricula = obtenerMatricula(alus, validosAlus, alumno);
    system("cls");
    printf("DETALLE DEL ALUMNO:\n");
    printf("Alumno: %s \n", alumno);
    if (matricula != -1){
        int indice = 0;
        while (indice < validosNotas){
            if (notas[indice].matricula == matricula){
                int indiceMateria = buscarNombreMateria(mats, validosMats, notas[indice].codigo);
                printf("Materia: %s - Nota: %i \n", mats[indiceMateria].nombreMat, notas[indice].nota);
            }
            indice++;
        }
    } else {
        printf("\n\nEl alumno no existe.\n");
    }
    system("pause");
}


