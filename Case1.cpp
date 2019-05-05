/*	Nama program	: Case1
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 05 05 2019
	Deskripsi		: Penukaran k antrian awal dengan k antrian akhir
********************************************************************/
#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Queue{
    char isi[maxElemen];
    int head;
    int tail; 
};

void enQueue(Queue& Q, char elemen) {
    if (Q.tail==maxElemen-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}
void deQueue(Queue& Q, char& elemenHapus){
    cout<<"Delete Queue (Antrian) "<<endl;
    if (Q.head>Q.tail){ 
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        for (int i=0;i<Q.tail;i++){ 
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}
int size(int n){
    return n;
}
int front(Queue Q){
    return Q.isi[Q.head];
}
int main(){
    Queue Q;
    char elemen;
    int n,k;

    Q.head = 0;
    Q.tail = -1;
    cout<<"Banyak data : ";cin>>n;
    for (int i=0;i<n;i++){
        enQueue(Q,elemen);
        cout<<"Input : ";cin>>Q.isi[Q.tail];
    }
    cout<<"k(maksimal n/2)= ";cin>>k;
    cout<<"Input: Q = [ ";
    for (int i=0;i<n;i++){
        if(i==n-1){
            cout<<Q.isi[i]<<" ";
        }
        else{
            cout<<Q.isi[i]<<",";
        }
    }
    cout<<"]"<<endl;
    cout<<"k(maksimal n/2)= "<<k<<endl;
    cout<<"Output: Q = [ ";
    for(int i=n-k;i<n;i++){
        cout<<Q.isi[i]<<",";
    }
    for(int i=k;i<n-k;i++){
        cout<<Q.isi[i]<<",";
    }
    for(int i=0;i<k;i++){
        if(i==k-1){
             cout<<Q.isi[i]<<" ";
        }
        else{
              cout<<Q.isi[i]<<",";
        }
    }
    cout<<"]";
}