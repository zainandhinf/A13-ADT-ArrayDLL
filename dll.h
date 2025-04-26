#ifndef dll_H
#define dll_H
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
	 addresskt r;
} Kota;

typedef struct Warga {
	 char *nm;
	 addresswg q;
} Warga;

typedef struct {
    addresskt First;
    int count;
} ListKota;

// Modul

// Modul untuk inisialisai list
void initListKota(ListKota *L);

// Modul untuk menambah node kota
void addKota(ListKota *L, const char *namaKota);

// Modul untuk menghapus node kota
void deleteKota(ListKota *L, const char *namaKota);

// Modul untuk menambah node warga
void addWarga(Kota *kota, const char *namaWarga);

// Modul untuk menambah node warga
void deleteWarga(Kota *kota, const char *namaWarga);

// Modul untuk mencari kota
boolean findKota(ListKota *L, const char *namaKota);

// Modul untuk menampilkan linked list
void displayAll(ListKota L);

addresskt searchKota(ListKota *L, const char *namaKota);

// End Modul

#endif
