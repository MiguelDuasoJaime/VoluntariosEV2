#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int **(mx(int **nums,int c)){
	int *res[c];
	for (int p=0;p<c;p++){
		*(*(res+p))=*(*(nums+p));
		cout<<*(*(res+p))<<endl;
	}
	return res;
}

int main(){
	int i=4;
	int *n_plh[i];
	int stn;
	int n1;
	
	for (int ct=0;ct<i;ct++){
		cout<<"Introduce el numero entero "<<(ct+1)<<": ";
		cin>>n1;
		n_plh[ct]=(int *)malloc(sizeof(int));
		*(*(n_plh+ct))=n1;
	}
	
	for (int cont=0;cont<i;cont++){
		for (int t=0;t<(i-1);t++){
			if (*(*(n_plh+t))<*(*(n_plh+t+1))){
				stn=*(*(n_plh+t));
				*(*(n_plh+t))=*(*(n_plh+t+1));
				*(*(n_plh+t+1))=stn;
			}
		}	
	}
	for(int c=0;c<i;c++){
		cout<<"Numero "<<c+1<<": "<<*(*(n_plh+c))<<endl;
	}
	int m=3;
	int *list3[m];
	for (int c=0;c<m;c++){
	    cout<<"Esto no va :("<<endl;
	    cout<<*(*(mx(n_plh,m)+c));
	}
	cout<<*(*(list3+1));
	
	return 0;
}
