#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class klient{
public:
int numer;
int numerw;
int pieczywo;
int wedliny;
int nabial;	
int napoje;
int masaw[3];
int szybkosc; //klient moze podejmowac decyzje szybko lub wolno
int p;
int n;
int na;
int w;

int czasw; //czas spędzony na wybieraniu produktów
int czaso; //czas obsługi przy kasie
int ck; // czas przyjscia klienta do sklepu
int cp; //czas dotarcia do kasy
int cr; //czas roznicy - oczekiwania na obsluge przy wedlinach
int crr; //czas oczekiwania na obsluge przy kasie
int cw; //czas na stoisku z wedlinami
	
klient();
void wybor();	
void obsluga();	
};

klient::klient()
{

numer=0;
pieczywo = rand()%5;
wedliny = rand()%3;
nabial = rand ()%8;
napoje = rand ()%5;	
szybkosc = rand ()%1;
ck = rand ()%1800; // badamy przedział 0.5 godziny
cw=0;
w=6;
if (wedliny!=0)
for (int g=0; g<wedliny; g++)
	{
	masaw[g]=rand()%4+1*10;
	cw +=masaw[g]*w;
	}
}

void klient::wybor(){
	if (szybkosc==1)
		{
		p=rand()%35+20;
		n=rand()%20+20;
		na=rand()%20+20;
		}
	
	else 
		{
		p=rand()%45+30;
		n=rand()%40+30;
		na=rand()%30+30;
		}
	
czasw = p*pieczywo + n * nabial +ck;

}	
	
	
	
void klient::obsluga (){

int ip = pieczywo+wedliny+nabial+napoje;
  if (ip!=0) czaso = ip*6+40;
  else czaso=0;
	
}


main()
{
srand(time(0));	
	
int il = rand ()%25;
	
klient kl[il];

//ustawiam kolejnosc wejscia
klient temp;	
	for(int v=0; v<il; v++)
	{for (int m=0; m<il-1; m++)	
		if (kl[m].ck>kl[m+1].ck)
		{temp=kl[m];
		kl[m]=kl[m+1];
		kl[m+1]=temp;
		}
	}
	
for (int a=0; a<il; a++)
{
kl[a].numer=a+1;
kl[a].wybor();
kl[a].obsluga();
}

//ustawiam kolejnosc dojscia do stoiska z wedlinami
	for(int q=0; q<il; q++)
	{for (int qq=0; qq<il-1; qq++)	
		
		if (kl[qq].czasw>kl[qq+1].czasw)
		{temp=kl[qq];
		kl[qq]=kl[qq+1];
		kl[qq+1]=temp;
		}
	}	

kl[0].cr=0;


for (int b=0; b<il-1; b++)
{
if (kl[b+1].wedliny!=0)
{if (kl[b+1].czasw<kl[b].czasw+kl[b].cr+kl[b].cw) kl[b+1].cr=kl[b].czasw+kl[b].cr+kl[b].cw-kl[b+1].czasw;
else kl[b+1].cr=0;
}
else kl[b+1].cr=0;
}


for (int aa=0; aa<il; aa++)
{
kl[aa].czasw+=kl[aa].napoje*kl[aa].na;  //stoisko z napojami znajduje się za stoiskiem z wędlinami
kl[aa].cp=kl[aa].czasw+kl[aa].cr+kl[aa].cw;
kl[aa].numerw=aa+1;
}

for(int ff=0; ff<il; ff++)
	{for (int f=0; f<il-1; f++)	
		
		if (kl[f].cp>kl[f+1].cp)
		{temp=kl[f];
		kl[f]=kl[f+1];
		kl[f+1]=temp;
		}
	}	

kl[0].crr=0;


for (int bb=0; bb<il-1; bb++)
{
if (kl[bb+1].cp<kl[bb].cp+kl[bb].crr+kl[bb].czaso) kl[bb+1].crr=kl[bb].cp+kl[bb].crr+kl[bb].czaso-kl[bb+1].cp;
else kl[bb+1].crr=0;
}





//ustawiam klientow kolejnoscia wejscia aby wyswietlic wyniki:

	for(int x=0; x<il; x++)
	{for (int xx=0; xx<il-1; xx++)	
		
		if (kl[xx].numer>kl[xx+1].numer)
		{temp=kl[xx];
		kl[xx]=kl[xx+1];
		kl[xx+1]=temp;
		}
	}	




for (int zz=0; zz<il; zz++)
{
cout << "Klient " << kl[zz].numer << " przyszedl w chwili: " << kl[zz].ck << endl; 
cout << "Zakupil: \n" << kl[zz].pieczywo << " sztuk pieczywa \n";
cout << kl[zz].nabial << " sztuk nabialu \n" << kl[zz].napoje << " sztuk napojow oraz \n";
cout << kl[zz].wedliny << " rodzajow wedlin";
if (kl[zz].wedliny!=0) 
  {
  cout << " w ilosci: \n";

  for (int j=0; j<kl[zz].wedliny; j++)
  {
  cout << kl[zz].masaw[j] << " dag;" << endl;
  }
}

 else cout << endl;
 
cout << "Klient dotarl do stoiska z wedlinami o czasie: " << kl[zz].czasw << " sekund."<<endl;
cout << "Na obsluge przy stoisku klient oczekiwal: " << kl[zz].cr << " sekund." << endl;
cout << "a obsluzony zostal w: " << kl[zz].cw << " sekund. \n";
cout << "Klient dotarl do kasy o czasie: " << kl[zz].cp << " sekund." << endl;
cout << "gdzie oczekiwal na obsluge: " << kl[zz].crr << " sekund \n";
cout << "a obsluzony zostal w: " << kl[zz].czaso << " sekund. \n";
cout << "Klient wyszedl ze sklepu o czasie: " << kl[zz].czaso+kl[zz].cp+kl[zz].crr << " sekund";
cout << " jako " << kl[zz].numerw << endl << endl <<endl << endl;
	
}




	return 0;
}
