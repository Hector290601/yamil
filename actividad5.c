#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct birthDate{
        int dia;
        int mes;
        int year;
}fechaDeNacimiento;

typedef struct personalInfo{
        char nombre[30];
        int edad;
        float altura;
        float peso;
        fechaDeNacimiento date;
}informacionPersonal;

typedef struct employee{
        informacionPersonal info;
        float salario;
        float horasTrabajadas;
}empleado;

int main(){
        int SIZE = 3;
        empleado empresa[SIZE];
        int opc;
        int registrados = 0;
        int addNew = 0;
        do{
                printf("Seleccione una opción\n");
                printf("1\tAgregar empleados\n");
                printf("2\tMostrar empleados\n");
                printf("3\tSalir\n");
                scanf("%d", &opc);
                switch(opc){
                        case 1:
                                if(registrados < SIZE){
                                        printf("Creando empleado\n");
                                        printf("\t\tINFORMACIÓN PERSONAL\n");
                                        printf("Nombre: ");
                                        scanf("%s", (((empresa[registrados]).info).nombre));
                                        fflush(stdin);
                                        printf("Edad: ");
                                        scanf("%d", &(((empresa[registrados]).info).edad));
                                        fflush(stdin);
                                        printf("Altura: ");
                                        scanf("%f", &(((empresa[registrados]).info).altura));
                                        fflush(stdin);
                                        printf("Peso: ");
                                        scanf("%f", &(((empresa[registrados]).info).peso));
                                        fflush(stdin);
                                        printf("\t\tFECHA DE NACIMIENTO\n");
                                        printf("Dia: ");
                                        scanf("%d", &(((empresa[registrados]).info).date).dia);
                                        fflush(stdin);
                                        printf("Mes: ");
                                        scanf("%d", &(((empresa[registrados]).info).date).mes);
                                        fflush(stdin);
                                        printf("Año: ");
                                        scanf("%d", &(((empresa[registrados]).info).date).year);
                                        fflush(stdin);
                                        registrados += 1;
                                }else{
                                        printf("No se pueden registrar más empleados\n");
                                        printf("Desea agregar otro empleado?\n");
                                        printf("1\tSí\n");
                                        printf("2\tNo\n");
                                        scanf("%d", &addNew);
                                        if(addNew == 1){
                                                SIZE += 1;
                                                empleado empresa2[SIZE];
                                                strcpy(empresa2, empresa);
                                                empleado empresa[SIZE];
                                                strcpy(empresa, empresa2);
                                        }
                                }
                        break;
                        case 2:
                                if(registrados > 0){
                                        for(int i = 0; i < registrados; i ++){
                                                printf("Empleado %d\n", i);
                                                printf("Nombre: %s, Tiene %d años, mide %.2f metros, pesa %.2f Kg, nacido el %d/%d/%d\n", (((empresa[i]).info).nombre), (((empresa[i]).info).edad), (((empresa[i]).info).altura), (((empresa[i]).info).peso), (((empresa[i]).info).date).dia, (((empresa[i]).info).date).mes, (((empresa[i]).info).date).year);
                                        }
                                }
                        break;
                }
        }while(opc != 3);
        return 0;
}
