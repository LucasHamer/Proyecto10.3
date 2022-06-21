#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    float precio;
    char desc[51];
}Sproducto;

//void generar();
void modificar(char []);
void leer(char []);
int buscar(Sproducto [],int);

int main()
{
    Sproducto producto[100];

    //generar();

    leer("productos.dat");

    modificar("productos.dat");

    leer("productos.dat");

    return 0;
}
void generar()
{
    Sproducto producto;
    int x=0;
    FILE*fp;

    fp=fopen("productos.dat","wb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(1);
    }
    for(x=0;x<5;x++)
    {
    printf("Ingrese producto: ");
    scanf("%d",&producto.codigo);
    printf("Ingrese precio: ");
    scanf("%f",&producto.precio);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(producto.desc);

    fwrite(&producto,sizeof(Sproducto),1,fp);
    }

    fclose(fp);
}

void leer(char archivo[])
{
    int x=0;
    FILE*fp;
    Sproducto producto[100];

    fp=fopen("productos.dat","rb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(2);
    }
    fread(&producto,sizeof(Sproducto),1,fp);
    printf("Codigo          Precio          Descripcion \n");
    while(!feof(fp))
    {
    printf("%d              %.2f              %s \n",producto[x].codigo,producto[x].precio,producto[x].desc);
    fread(&producto,sizeof(Sproducto),1,fp);
    }
    fclose(fp);
}
void modificar(char archivo[])
{
    Sproducto producto[100];
    int pos,codig;
    float preciom;
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
        scanf("%f",&preciom);
        producto[pos].precio=preciom;

        fwrite(&producto,sizeof(Sproducto),1,fp);
        fwrite(&producto,sizeof(Sproducto),1,fe);
    }
    else
    {
        printf("No existe ese codigo: \n");
    }
    printf("Ingrese codigo a modificar: ");
    scanf("%d",&codig);
    }

    fclose(fp);
    fclose(fe);
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
};
