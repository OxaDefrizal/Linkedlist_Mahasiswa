#include <iostream>
#include <stdlib.h>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    int score[5];
    float ipk;
    
};
//! Linked List
struct Node
{
    Mahasiswa mhs;
    Node *next;
};

Node *headNode = NULL;
Node *tailNode;
Node *currentNode = NULL;
Node *TempNode;
Node *newNode;

bool isEmpty()
{
    return (headNode == NULL);
}
Node *insertNode(Mahasiswa mhs)
{
    newNode = new Node;
    newNode->mhs = mhs;
    newNode->next = NULL;  
    return newNode;
}

void push(Node *note)
{
    if (headNode == NULL)
    {
        headNode = note;
    }
    else
    {
        TempNode = headNode;
        headNode = note;
        headNode->next = TempNode;
    }
}
void pop()
{
    if (headNode == NULL)
    {
        cout << "Stack Kosong!" << endl;
    }
    else
    {
        TempNode = headNode;
        headNode = headNode->next;
        delete TempNode;
        cout << "Data teratas telah dihapus" <<endl <<endl;
    }
}
void deleteAll()
{
    Node *bantu, *hapusNode;
    bantu = headNode; 
    while (bantu->next != currentNode)
    {
        hapusNode = bantu;
        bantu = bantu->next; 
        delete hapusNode;
    }
    headNode = NULL;
    currentNode = NULL;
    cout << "Node berhasil dikosongkan" << endl << endl;
}
void printNode()
{
    // deklarasi pointer awal node untuk menampung head node
    Node *awalNode = headNode;
    int i = 1;
    while (awalNode != NULL)
    {
        cout << "Data pada node #" << i << " = " << awalNode->mhs.nama << endl;
        awalNode = awalNode->next;         
        i++;          
    }  
    cout << endl;      
}

void input(Mahasiswa &mhs,int count)
{
    // Deklarasi variabel lokal
	string matkul[5] = {"Pemrograman","Sistem Operasi","Struktur Data",
						"Bahasa Inggris","Hardware/Software"};		
    float total;

	cout<<endl;
	cout << "Mahasiswa ke-" << count <<endl;
	total=0;
    cin.ignore();
	cout << "Inputkan Nama Mahasiswa: ";
	getline(cin, mhs.nama);
        
    cout << "Inputkan NIM Mahasiswa: ";
	cin >> mhs.nim;
	cout << endl;
		
	for(int j=0; j<5; j++)
	{
		cout << "Nilai Mata kuliah "<<matkul[j]<<": ";
		cin >> mhs.score[j];
		total += mhs.score[j];	
	}
	mhs.ipk = total/5/25;
    newNode = insertNode(mhs);
    push(newNode);
    
}
void sorting(Mahasiswa &mhs,int count)
{
    int jika;
    string tempnama, tempnim;
	float sort;

    balik:
    cout<<"Metode sorting"<<endl;
	cout<<"1. Bubble Sort\n2. Insertion sort\n3. selection Sort"<<endl<<endl;
	cout<<"Inputkan Metode yang ingin digunakan dari 1-3: ";
	cin>>jika;
    if(jika==1)
    {
        
		
        cout<<"\nData sudah disortir menggunakan metode bubble sort";
    }
    else if(jika==2)
    {
        
        cout<<"\nData sudah disortir menggunakan metode Insertion Sort";
    }
    else if(jika==3)
    {

        cout<<"\nData sudah disortir menggunakan metode Selection sort"; 	
	}	
    else
    {
        cout<<"Input yang anda masukan tidak sesuai, silahkan di input ulang"<<endl;
        goto balik;  
    }
}
void searching (Mahasiswa *mhs, Node *awal, int count)
{
    string cari, posisinama,posisinim;
	float posisiipk;	
	cout<<"\nMasukan nama Mahasiswa yang ingin dicari: ";
	cin>>cari;
	int ketemu=0;
	for(int i=0; i<=count; i++){
		if(mhs[i].nama == cari)
		{
			ketemu = 1;
			posisinama = (mhs + i)->nama;
			posisinim = (mhs + i)->nim;
			posisiipk = (mhs + i)->ipk;
			i = count;
		}
	}
	if(ketemu == 0)
	{
	cout<<"Data Mahasiswa tidak ditemukan";
	}
	else
	{
	// Menampilkan nama,nim,ipk yang dicari
	cout<<"\nMenampilkan data Mahasiswa yang dicari"<<endl<<endl;
	cout <<"Nama Mahasiswa: "<< posisinama<<endl;
	cout << "NIM: "<<posisinim<<endl;	
    cout<<"IPK : "<<posisiipk<<endl<<endl;
    }
}

int main()
{
    Mahasiswa mhs;
	int pil,count=0;
    do
    {	
		// swicth case tampilan menu
		cout << "--------Program Mahasiswa--------"<<endl<<endl;
        cout << "1. Input data Mahasiswa\n2. Hapus data Mahasiswa\n3. Tampil data Mahasiswa\n4. ";
        cout << "Bersihkan semua data Mahasiswa \n5. Mengurutkan Peringkat Mahasiswa \n6. Mencari Data Mahasiswa\n7. ";
		cout << "Keluar Program Mahasiswa\n\nMasukkan pilihan :";
        cin >> pil;
        switch(pil)
        {
            case 1: 	// swicth case Input data mahasiswa
            count++;
            input(mhs, count);
		    break;

            case 2: 	// swicth case Hapus data mahasiswa
            pop();
            break;

            case 3:     // swicth case Tampil data mahasiswa
		    if (isEmpty()){
                cout << "Stack masih kosong!" <<endl;
            }else{
                printNode();
            }
            break;

            case 4:		// swicth case Membersihkan semua data mahasiswa
            deleteAll();
            break;

            case 5: 	// swicth case Mengurutkan data Mahasiswa secara Descending
		    sorting(mhs, count);
		    break;

	    	case 6:		// swicth case Mencari data Mahasiswa
		    searching (&mhs, headNode, count);		
		    break;

	   		case 7:		// swicth case Keluar dari program
		    cout << "-----Terimakasih telah menggunakan program data Mahasiswa-----"; 
        }
    getchar();			// meminimalisir error jika terdapat input selain int
    cout<<endl<<endl;
    }
    while(pil!=7);
	return 0;  
}