#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    float precio;
    char desc[51];
}Sproducto;

/*void generar();*/
void modificar(char []);
void leer(char []);
int buscar(Sproducto [],int);

int main()
{
    Sproducto producto[100];
    int x;

    leer("productos.dat");

    modificar("productos.dat");
    FILE*fp;
    FILE*fe;

    fp=fopen("productos.dat","wb");
    fe=fopen("productos.csv","wt");
    if(fp==NULL||fe==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(1);
    }

    for(x=0;x<5;x++)
    {
       fwrite(&producto[x],sizeof(producto),1,fp);
    }

    fclose(fp);
    fclose(fe);

    leer("productos.dat");

    return 0;
}
/*void generar()
{
    Sproducto producto[100];
    int x=0;
    FILE*fp;

    fp=fopen("productos.dat","wb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(1);
    }
    while(x<5)
    {
    printf("Ingrese producto: ");
    scanf("%d",&producto[x].codigo);
    printf("Ingrese precio: ");
    scanf("%f",&producto[x].precio);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(producto[x].desc);

    x++;
    }

    fwrite(&producto,sizeof(producto),1,fp);

    fclose(fp);
}*/

void leer(char archivo[])
{
    Sproducto producto[100];
    FILE*fp;
    int x=0;

    fp=fopen("productos.dat","rb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(2);
    }
    fread(&producto,sizeof(producto),1,fp);
    printf("Codigo          Precio          Descripcion \n");
    while(!feof(fp))
    {
        for(x=0;x<5;x++)
        {
    printf("%d              %.2f              %s \n",producto[x].codigo,producto[x].precio,producto[x].desc);
    fread(&producto,sizeof(producto),1,fp);
        }
    }
    fclose(fp);
}
void modificar(char archivo[])
{
    Sproducto producto[100];
    int pos,codig;
/*    FILE*fp;
    FILE*fe;

    fp=fopen("productos.dat","wb");
    fe=fopen("productos.csv","wt");
    if(fp==NULL||fe==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(1);
    }*/
    printf("Ingrese codigo a modificar: ");
    scanf("%d",&codig);
    while(codig!=0)
    {
    pos=buscar(producto,codig);
    if(pos!=-1)
    {
        printf("El precio actual es: %.2f\n",producto[pos].precio);
        printf("Ingrese el nuevo precio: ");
        fflush(stdin);
        scanf("%f",&producto[pos].precio);
    }
    else
    {
        printf("No existe ese codigo: \n");
    }
    printf("Ingrese codigo a modificar: ");
    scanf("%d",&codig);
    }

/*    fwrite(&producto,sizeof(producto),1,fp);
    fwrite(&producto,sizeof(producto),1,fe);

    fclose(fp);
    fclose(fe);*/
}
int buscar(Sproducto prodi[],int cod)
{
    int pos,x;
    x=0;
    pos=-1;
    while(pos==-1&&x<5)
    {
        if(prodi[x].codigo==cod)
        {
           pos=x;
        }
        else
        {
        x++;
        }
    }

    return pos;
}






