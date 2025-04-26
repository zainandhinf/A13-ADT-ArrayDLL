#include <limits.h>
#include <malloc.h>
#include "dll.h"

// Modul

// Modul untuk inisialisai array
void initListKota(ListKota *L)
{
	L->First = Nil;
    L->count = 0;
}

// Modul untuk menambah node kota
void addKota(ListKota *L, const char *namaKota)
{
	addresskt current, last, q;
	
	current = L->First;
	while (current != Nil) {
        if (strcmp(current->kt, namaKota) == 0) {
            printf("Kota %s sudah ada!\n", namaKota);
            return;
        }
        current = current->r;
    }
    
    q = (addresskt)malloc(sizeof(struct Kota));
    if (!q) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    
    q->kt = strdup(namaKota);
    q->p = Nil;
    q->r = Nil;
    
	if (L->First == Nil) {
        L->First = q;
    } else {
        last = L->First;
        while (last->r != Nil) {
            last = last->r;
        }
        last->r = q;
    }
    
    L->count++;
    printf("Kota %s berhasil ditambahkan\n", namaKota);
}

// Modul untuk menghapus node kota
void deleteKota(ListKota *L, const char *namaKota)
{
    addresskt current, prev;
	
	current = L->First;
	prev = Nil;
    
	while (current != Nil) {
        if (strcmp(current->kt, namaKota) == 0) {
            if (prev == Nil) {
                L->First = current->r;
            } else {
                prev->r = current->r;
            }
            
            addresswg currentWarga = current->p;
            while (currentWarga != Nil) {
                addresswg tempWarga = currentWarga;
                currentWarga = currentWarga->q;
                free(tempWarga->nm);
                free(tempWarga);
            }

            free(current->kt);
            free(current);

            L->count--;
            printf("Kota %s berhasil dihapus\n", namaKota);
            return;
        }

        prev = current;
        current = current->r;
    }

    printf("Kota %s tidak ditemukan!\n", namaKota);
}

// Modul untuk menambah node warga
void addWarga(Kota *kota, const char *namaWarga)
{
    addresswg namaBaru, current;

    namaBaru = (addresswg)malloc(sizeof(Warga));
    if (namaBaru == Nil) {
        printf("Gagal alokasi memori!\n");
        return;
    }

    namaBaru->nm = (char*)malloc(strlen(namaWarga) + 1);
    if (namaBaru->nm == Nil) {
        printf("Gagal alokasi memori untuk nama!\n");
        free(namaBaru);
        return;
    }

    strcpy(namaBaru->nm, namaWarga);
    namaBaru->q = Nil;

    if (kota->p == Nil) {
        kota->p = namaBaru;
    } else {
        current = kota->p;

        while (current != Nil) {
            if (strcmp(current->nm, namaWarga) == 0) {
                printf("Warga %s sudah ada di kota %s!\n", namaWarga, kota->kt);
                free(namaBaru->nm);
                free(namaBaru);
                return;
            }
            if (current->q == Nil) break;
            current = current->q;
        }

        current->q = namaBaru;
    }

    printf("Warga %s berhasil ditambahkan ke kota %s\n", namaWarga, kota->kt);
}


// Modul untuk menambah node warga
void deleteWarga(Kota *kota, const char *namaWarga)
{
    addresswg current = kota->p;
    addresswg prev = Nil;

    while (current != Nil) {
        if (strcmp(current->nm, namaWarga) == 0) {
            if (prev == Nil) {
                kota->p = current->q;
            } else {
                prev->q = current->q;
            }

            free(current->nm);
            free(current);
            printf("Warga %s berhasil dihapus dari kota %s\n", namaWarga, kota->kt);
            return;
        }

        prev = current;
        current = current->q;
    }

    printf("Warga %s tidak ditemukan di kota %s!\n", namaWarga, kota->kt);
}


// Modul untuk mencari kota
boolean findKota(ListKota *L, const char *namaKota)
{
	addresskt current;
	
	current = L->First;
    while (current != Nil) {
        if (strcmp(current->kt, namaKota) == 0) {
            return true;
        }
        current = current->r;
    }
    return false;
}

// Modul untuk menampilkan linked list
void displayAll(ListKota L)
{
    addresskt currentKota = L.First;
    
    if (currentKota == Nil) {
        printf("List Kota Kosong\n");
        return;
    }
    
    printf("\nDaftar Kota dan Warga:\n");
    
    while (currentKota != Nil) {
        printf("%s -> ", currentKota->kt);
        addresswg currentWarga = currentKota->p;
        
        if (currentWarga == Nil) {
            printf("NIL");
        } else {
            while (currentWarga != Nil) {
                printf("%s", currentWarga->nm);
                currentWarga = currentWarga->q;
                printf(currentWarga ? " -> " : " -> NIL");
            }
        }
        
        if (currentKota->r != Nil) {
            printf("\n    |\n    V\n");
        }
        
        currentKota = currentKota->r;
    }
    printf("\n");
}

addresskt searchKota(ListKota *L, const char *namaKota) 
{
    addresskt current = L->First;
    while (current != Nil) {
        if (strcmp(current->kt, namaKota) == 0) {
            return current;
        }
        current = current->r;
    }
    return Nil;
}

// End Modul

