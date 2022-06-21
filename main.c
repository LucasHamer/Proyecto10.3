#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    float precio;
    char desc[51];
}Sproducto;

void generar();
void modificar(Sproducto []);
void leer(char []);
int buscar(Sproducto [],int);
int leer2(char [],Sproducto []);

int main()
{
    Sproducto producto[100];
    int cant;

    cant=leer2("productos.dat",producto);

    //generar();

    modificar(producto);

    leer("productos.dat");

    return 0;
}
void generar()
{
    Sproducto producto[5];
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
    scanf("%d",&producto[x].codigo);
    printf("Ingrese precio: ");
    scanf("%f",&producto[x].precio);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(producto[x].desc);

    fwrite(&producto[x],sizeof(Sproducto),1,fp);
    }

    fclose(fp);
}
void modificar(Sproducto P[])
{
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
    pos=buscar(P,codig);
    if(pos!=-1)
    {
        printf("El precio actual es: %.2f\n",P[pos].precio);
        printf("Ingrese el nuevo precio: ");
        fflush(stdin);
        scanf("%f",&preciom);
        P[pos].precio=preciom;

        fwrite(&P[pos],sizeof(Sproducto),1,fp);
        fwrite(&P[pos],sizeof(Sproducto),1,fe);
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
int leer2(char archivo[],Sproducto P[])
{
    int x=0;
    FILE*fp;
   // Sproducto producto[100];

    fp=fopen("productos.dat","rb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(2);
    }
    fread(&P[x],sizeof(Sproducto),1,fp);
    printf("Codigo          Precio          Descripcion \n");
    while(!feof(fp))
    {
     printf("%d              %.2f              %s \n",P[x].codigo,P[x].precio,P[x].desc);
     x++;
    fread(&P[x],sizeof(Sproducto),1,fp);
    }
    fclose(fp);
  return x;
}
void leer(char archivo[])
{
    int x=0;
    FILE*fp;
    Sproducto P;

    fp=fopen(archivo,"rb");
    if(fp==NULL)
    {
        printf("Error al abrir");
        system("pause");
        exit(2);
    }
    fread(&P,sizeof(Sproducto),1,fp);
    printf("Codigo          Precio          Descripcion \n");
    while(!feof(fp))
    {
    printf("%d              %.2f              %s \n",P.codigo,P.precio,P.desc);
    fread(&P,sizeof(Sproducto),1,fp);
    }
    fclose(fp);
}
