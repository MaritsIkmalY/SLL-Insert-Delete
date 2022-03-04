#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char nama[25];
    float nilai;
}mahasiswa;

typedef struct simpul node;
struct simpul{
    mahasiswa student;
    node *next;
};

node *head = NULL, *p;

void menu();
void masukkan();
void menghapus();
void alokasi();
void input(mahasiswa *);
void awal();
void akhir();
void setelah();
void sebelum();
void menghapus_awal();
void menghapus_akhir();
void menghapus_tertentu();
void tampil();

int main(){
    menu();

    return 0;

}

void menu(){
    int pilihan;

    do{
        puts("\nMenu SLL");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);
        if(head == NULL && pilihan == 2)
            puts("Tidak Bisa Melakukan Delete karena Data Kosong");
        else{
             switch(pilihan){
                case 1 :
                    masukkan();
                    break;
                case 2 :
                    menghapus();
                    break;
                case 3 :
                    exit(0);
                    break;
                default :
                    puts("Pilih yang benar");
            }
        }
        tampil();
    }while(pilihan != 3);
}

void masukkan(){
    int pilih;

    puts("Menu Insert");
    puts("1. Insert di Awal");
    puts("2. Insert di Akhir");
    puts("3. Insert Sebelum Node Tertentu");
    puts("4. Insert Sesudah Node Tertentu");
insert:
    printf("Masukkan Pilihan Anda : ");
    scanf("%d",&pilih);
    if(head == NULL && pilih == 3 || head == NULL && pilih == 4){
        puts("Data masih kosong tidak bisa melakukan insert sebelum atau sesudah");
        goto insert;
    }
    else{
         switch(pilih){
            case 1 :
                alokasi();
                awal();
                break;
            case 2 :
                alokasi();
                akhir();
                break;
            case 3 :
                alokasi();
                sebelum();
                break;
            case 4 :
                alokasi();
                setelah();
                break;
            default :
                puts("Pilih yang benar");
                goto insert;
        }
    }
}

void menghapus(){
    int jawab;

    puts("Menu Delete");
    puts("1. Delete di Awal");
    puts("2. Delete di Akhir");
    puts("3. Delete Node Tertentu");
hapus:
    printf("Masukkan Pilihan Anda : ");
    scanf("%d",&jawab);
    switch(jawab){
        case 1 :
            menghapus_awal();
            break;
        case 2 :
            menghapus_akhir();
            break;
        case 3 :
            menghapus_tertentu();
            break;
        default :
            puts("Pilih yang benar");
            goto hapus;
    }

}

void menghapus_tertentu(){
    int key;
    node *hapus, *phapus;

input:
    printf("Masukkan Node berapa yang ingin dihapus : ");
    scanf("%d", &key);
    hapus = head;
    if(hapus->student.id == key){
        head = hapus->next;
    }
    else{
        while(hapus->student.id != key){
            if(hapus->next != NULL){
                phapus = hapus;
                hapus = hapus->next;
            }
            else{
                printf("%d tidak ada di dalam SLL\n", key);
                goto input;
            }
        }
        phapus->next = hapus->next;
    }
    free(hapus);
    hapus == NULL;
}

void menghapus_akhir(){
    node *hapus, *phapus;

    hapus = head;
    while(hapus->next != NULL){
        phapus = hapus;
        hapus = hapus->next;
    }
    if(hapus == head)
        head = NULL;
    else
        phapus->next = NULL;
    free(hapus);
    hapus == NULL;
}

void menghapus_awal(){
    node *hapus;

    hapus = head;
    head = hapus->next;
    free(hapus);
    hapus == NULL;
}

void alokasi(){
    mahasiswa murid;

    input(&murid);
    p=(node *)malloc(sizeof(node));
    if(p == NULL)
        exit(0);
    else{
        p->student.id = murid.id;
        strcpy(p->student.nama, murid.nama);
        p->student.nilai = murid.nilai;
        p->next=NULL;
    }
}

void input(mahasiswa *student){
    int x, y;

    printf("No\t : ");
    scanf("%d",&student->id);
    fflush(stdin);
    printf("Nama\t : ");
    gets(student->nama);
    fflush(stdin);
    printf("Nilai\t : ");
    scanf("%f",&student->nilai);
}

void awal(){
    if(head != NULL)
        p->next = head;
    head = p;
}

void akhir(){
    node *tail;

    if(head == NULL)
        head = p;
    else{
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
}

void setelah(){
    int key;
    node *after;

sesudah:
    printf("Disisipkan setelah data berapa ? ");
    scanf("%d",&key);
    after = head;
    while(after->student.id != key){
        if(after->next == NULL){
            printf("%d tidak ditemukan di dalam SLL\n",key);
            goto sesudah;
        }
        else{
            after = after->next;
        }
    }
        p->next = after->next;
        after->next = p;
}

void sebelum(){
    int key;
    node *bef, *pbef;

before:
    printf("Disisipkan sebelum data berapa ? ");
    scanf("%d",&key);
    bef = head;
    while(bef->student.id != key){
        if(bef->next == NULL){
            printf("%d tidak ditemukan di dalam SLL\n",key);
            goto before;
        }
        else{
            pbef = bef;
            bef = bef->next;
        }
    }
    if(bef == head){
        p->next = bef;
        head = p;
    }
    else{
        p->next = bef;
        pbef->next = p;
    }
}

void tampil(){
    node *baca;

    baca = head;
    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");
    while(baca != NULL){
        printf("%d\t",baca->student.id);
        printf("%s\t", baca->student.nama);
        printf("%g\t", baca->student.nilai);
        puts("");
        baca=baca->next;
    }
    if(head == NULL)
        puts("Kosong");

}

