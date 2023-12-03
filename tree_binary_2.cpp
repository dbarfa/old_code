#include<iostream.h>

struct nod{int info;
           nod*s,*d;};

void creare(nod*&rad)
{
	int x;
	cin>>x;
	if(x!=NULL)
		{
			rad=new nod;
 			rad->info=x;
   			creare(rad->s);
   			creare(rad->d);
   		}
else rad=NULL;
}

void RSD(nod*rad)
{
	if(rad!=NULL)
		{
			cout<<rad->info<<" ";
      			RSD(rad->s);
     			RSD(rad->d);
     		}	
}

void SRD(nod*rad)
{
	if(rad!=NULL)
		{
			SRD(rad->s);
			cout<<rad->info<<" ";
     			SRD(rad->d);
     		}	
}

void SDR(nod*rad)
{
	if(rad!=NULL)
		{
			SDR(rad->s);
			SDR(rad->d);
			cout<<rad->info<<" ";
     		}	
}
int inaltime(nod*rad)
{
	int x=0;
	int y=0;
	if(rad==NULL) return 0;
	else
		{
			x=inaltime(rad->s);
			y=inaltime(rad->d);
	 		if(x>y ||  x==y ) return x+1;
			else return y+1;
		}
}

void main()
{
	nod*rad;
	rad=NULL;
	creare(rad);
	RSD(rad);
	cout<<endl;
	SRD(rad);
	cout<<endl;
	SDR(rad);
	cout<<endl;
        cout<<inaltime(rad);
}
