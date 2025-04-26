#include <limits.h>
#include <malloc.h>
#include "arrdll.h"

// Modul

// Modul untuk inisialisai array
void initArrayKota(ArrayKota *arr, int capacity)
{
	int i;
	
    arr->data = (Kota*)malloc(capacity * sizeof(Kota));
    arr->capacity = capacity;
    arr->count = 0;
    
    for (i = 0; i < capacity; i++) {
        arr->data[i].kt = Nil;
        arr->data[i].p = Nil;
    }
}

// Modul untuk menambah node kota
void addKota(ArrayKota *arr, const char *namaKota)
{
	int i;
	
	if (arr->count >= arr->capacity) {
        printf("Array kota penuh!\n");
        return;
    }
    
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i].kt && strcmp(arr->data[i].kt, namaKota) == 0) {
            printf("Kota %s sudah ada!\n", namaKota);
            return;
        }
    }
    
    arr->data[arr->count].kt = strdup(namaKota);
    if (!arr->data[arr->count].kt) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    
    arr->data[arr->count].p = Nil;
    arr->count++;
    printf("Kota %s berhasil ditambahkan\n", namaKota);
}

// Modul untuk menghapus node kota
void deleteKota(ArrayKota *arr, const char *namaKota)
{
	int idx, i;
	
	idx = findIndexKota(arr, namaKota);
    
    printf("%d", idx);
    
    DelAll((List*)&arr->data[idx].p);
    
    free(arr->data[idx].kt);
    
    for (i = idx; i < arr->count - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->count--;
    arr->data[arr->count].kt = Nil;
    arr->data[arr->count].p = Nil;
    printf("Kota %s berhasil dihapus\n", namaKota);
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
    addresswg sebelum = Nil;

    while (current != Nil) {
        if (strcmp(current->nm, namaWarga) == 0) {
            if (sebelum == Nil) {
                kota->p = current->q;
            } else {
                sebelum->q = current->q;
            }

            free(current->nm);
            free(current);
            printf("Warga %s berhasil dihapus dari kota %s\n", namaWarga, kota->kt);
            return;
        }

        sebelum = current;
        current = current->q;
    }

    printf("Warga %s tidak ditemukan di kota %s!\n", namaWarga, kota->kt);
}


// Modul untuk mencari kota
boolean findKota(ArrayKota *arr, const char *namaKota)
{
	int i;
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i].kt && strcmp(arr->data[i].kt, namaKota) == 0) {
            return true;
        }
    }
    return false;
}

// Modul untuk mencari index kota
int findIndexKota(ArrayKota *arr, const char *namaKota) 
{
    int i;
	for (i = 0; i < arr->count; i++) {
        if (arr->data[i].kt && strcmp(arr->data[i].kt, namaKota) == 0) {
            return i;
        }
    }
    return -1;
}

// Modul untuk menampilkan linked list
void displayAll(ArrayKota arr) 
{
    int i;
    addresswg current;
    
    if (arr.count == 0) {
        printf("Daftar Kota Kosong\n");
        return;
    }
    
    printf("\nDaftar Kota dan Warga:\n");
    for (i = 0; i < arr.count; i++) {
        printf("%s -> ", arr.data[i].kt);
        
        current = arr.data[i].p;
        if (current == Nil) {
            printf("NIL\n");
        } else {
            while (current != Nil) {
                printf("%s", current->nm);
                current = current->q;
                printf(current ? " -> " : " -> NIL\n");
            }
        }
    }
}

// End Modul

