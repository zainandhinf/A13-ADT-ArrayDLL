#ifndef arrdll_H
#define arrdll_H
#include "boolean.h"
#include "linked.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next

#define MAX_NAME_LENGTH 50

typedef struct Warga *addresswg;
typedef struct Kota *addresskt;
typedef struct Kota {
	 char *kt;
	 addresswg p;
} Kota;

typedef struct Warga {
	 char *nm;
	 addresswg q;
} Warga;

typedef struct {
    Kota *data;
    int count;
    int capacity;
} ArrayKota;

// Modul

// Modul untuk inisialisai array
void initArrayKota(ArrayKota *arr, int capacity);

// Modul untuk menambah node kota
void addKota(ArrayKota *arr, const char *namaKota);

// Modul untuk menghapus node kota
void deleteKota(ArrayKota *arr, const char *namaKota);

// Modul untuk menambah node warga
void addWarga(Kota *kota, const char *namaWarga);

// Modul untuk menambah node warga
void deleteWarga(Kota *kota, const char *namaWarga);

// Modul untuk mencari kota
boolean findKota(ArrayKota *arr, const char *namaKota);

// Modul untuk mencari index kota
int findIndexKota(ArrayKota *arr, const char *namaKota);

// Modul untuk menampilkan linked list
void displayAll(ArrayKota arr);

// End Modul

#endif
