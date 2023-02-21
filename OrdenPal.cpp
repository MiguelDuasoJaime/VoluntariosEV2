#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int cuentalet(char *pnom){
	int cont=0;
	while((*(pnom+cont))!='\0'){
		cont++;}
	return cont;
	}

int main(){
	int i=4;
	char *plh[i];
	char *orden[i];
	int *n_plh[i];
	int stn;
	char s;
	char n1[16];
	
	for (int ct=0;ct<i;ct++){
		cout<<"Introduce la palabra "<<(ct+1)<<": ";
		cin>>n1;
		int len=(cuentalet(n1));
		n_plh[ct]=(int *)malloc(sizeof(int));
		*(*(n_plh+ct))=len;
		plh[ct]=(char *)malloc((len+1)*sizeof(char));
		cout<<"Longitud: "<<*(*(n_plh+ct))<<endl;
		for(int ct2=0;ct2<=len;ct2++){
				printf("%c\n",*(n1+ct2));
				*(*(plh+ct)+ct2)=n1[ct2];
				//cout<<" -Traslado: ("<<*(*(plh+ct)+ct2)<<") "<<endl;	
				}
	}
	
	int maxlen;
	int m;
	for (int nn=0;nn<i;nn++){
		m=0;
		for (int n2=0;n2<i;n2++){
			if (*(*(n_plh+nn))>=*(*(n_plh+n2))){
				m=m+1;
			}
		}
		if (m==i){
			maxlen=*(*(n_plh+nn));
		}
	}
	for (int nnn=0;nnn<i;nnn++){
		orden[nnn]=(char *)malloc((maxlen+1)*sizeof(char));
		for (int q=0;q<maxlen+1;q++){
			*(*(orden+nnn)+q)=*(*(plh+nnn)+q);
		}
	}
	for (int cont=0;cont<i;cont++){
		for (int t=0;t<(i-1);t++){
			if (*(*(n_plh+t))>*(*(n_plh+t+1))){
				stn=*(*(n_plh+t));
				for (int p=0;p<(*(*(n_plh+t)));p++){
					s=*(*(orden+t)+p);
					*(*(orden+t)+p)=*(*(orden+t+1)+p);
					*(*(orden+t+1)+p)=s;
				}
				*(*(n_plh+t))=*(*(n_plh+t+1));
				*(*(n_plh+t+1))=stn;
			}
		}	
	}
	for(int c=0;c<i;c++){
		cout<<"Longitud "<<c+1<<": "<<*(*(n_plh+c))<<endl;
		cout<<orden[c]<<endl;
	}
	return 0;
}


