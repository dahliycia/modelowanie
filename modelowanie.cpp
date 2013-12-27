#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  srand(time(0));
  int c=0;   //chwila 0;
  
  int pieczywo;
  int wedliny;
  int nabial;
  
  int p=30;
  int w=6;   //s na dag
  int n=20;

  int iloscklientow=rand()%19+1;
    
  int czasw[iloscklientow+1];
  int czaso[iloscklientow+1];
  int ck[iloscklientow+1];
  int cp[iloscklientow+1];
  
  czasw[0]=0;
  czaso[0]=0;
  int cr[iloscklientow+1];
  
  for (int i=1; i<iloscklientow+1; i++)
  {
  pieczywo = rand()%5;
  wedliny = rand()%3;
  int masaw [wedliny];
  nabial = rand ()%8;
  ck[i]= rand ()%150; //zakladam, ze minimalny okres pojawiania sie klienow wynosi 150s
  c +=ck[i];
  cout << "Klient " << i << " przyszedl w chwili: " << c << endl << "Zakupil: \n" << pieczywo << " sztuk pieczywa \n";
  cout << wedliny << " rodzajow wedlin";
  czasw[i] = p*pieczywo + n * nabial;
  if (wedliny!=0) 
  {
  cout<< " w ilosci: \n";

  for (int j=0; j<wedliny; j++)
  {
  masaw[j] = rand()%50;
  czasw[i] += w*masaw[j];
  cout << masaw[j] << " dag;" << endl;
  }
}
  else cout << endl;
  cp[i] =c + czasw[i];
  int ip = pieczywo+wedliny+nabial;
  if (ip!=0) czaso[i] = ip*6+20;
  else czaso[i]=0;
  
  
  cout << "oraz " << nabial << " sztuk nabialu." << endl<< endl;
  cout << "Czas wybierania towarow z polek: " << czasw[i] << " sekund. \n";
  cout << "Klient dotarl do kasy o czasie: " << cp[i] << endl;
  cout << "Przewidywany czas obslugi klienta przy kasie: " << czaso[i] << " sekund." << endl<< endl << endl <<endl;
}

//ustawiam kolejke:
int temp=0;
int kolejka[iloscklientow];

for (int z=0; z<iloscklientow; z++)
{
kolejka[z]=z+1;	
	
}


	for(int v=1; v<iloscklientow+1; v++)
	{for (int m=1; m<iloscklientow; m++)
	{
	temp=m;	
		if (cp[m]>cp[m+1])
			{
				temp=kolejka[m-1];
				kolejka[m-1]=kolejka[m];
				kolejka[m]=temp;
				temp=cp[m]; cp[m]=cp[m+1]; cp[m+1]=temp;
				temp=czaso[m]; czaso[m]=czaso[m+1]; czaso[m+1]=temp;
			}
	}}
	
cout<< "Kolejnosc obslugi klientow przy kasie: ";
for (int l=0; l<iloscklientow; l++)
{cout << kolejka[l] << "  ";
}

cout <<endl << endl << endl;
cr[0]=0;
cp[0]=0;
czaso[0]=0;

for (int b=0; b<iloscklientow; b++)
{
if (cp[b+1]<cp[b]+cr[b]+czaso[b]) cr[b+1]=cp[b]+cr[b]+czaso[b]-cp[b+1];
else cr[b+1]=0;
cout << "Klient " << kolejka[b] << " przyszedl do kasy o czasie: " << cp[b+1] <<endl;
cout << "Jego przewidywany czas obslugi to: " << czaso[b+1]<< endl;
cout << "Czas oczekiwania na obsluge: " << cr[b+1] << endl;
cout << "Wyjscie ze sklepu: " << cp[b+1]+cr[b+1]+czaso[b+1] << endl << endl << endl;
	
	
	
}
  system("PAUSE");   
  return 0;
}
