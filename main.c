#include <stdio.h>
#include "dll.h"

int main() {

	int choice;
	ListKota kota;
    initListKota(&kota);
    char namaKota[MAX_NAME_LENGTH];
    char warga[MAX_NAME_LENGTH];
    addresskt foundCity; 
				
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Warga\n");
        printf("3. Hapus Kota\n");
        printf("4. Hapus Warga\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: {
                printf("Nama Kota: ");
			    fgets(namaKota, MAX_NAME_LENGTH, stdin);
			    namaKota[strcspn(namaKota, "\n")] = '\0';
			    addKota(&kota, namaKota);
			    break;
            }
                
            case 2: {
                printf("Nama Kota: ");
			    fgets(namaKota, MAX_NAME_LENGTH, stdin);
			    namaKota[strcspn(namaKota, "\n")] = '\0';
			
				foundCity = searchKota(&kota, namaKota);
			    if (foundCity != NULL) {
                    printf("Nama Warga: ");
                    fgets(warga, MAX_NAME_LENGTH, stdin);
                    warga[strcspn(warga, "\n")] = '\0';
                    addWarga(foundCity, warga);
                } else {
                    printf("Kota %s tidak ditemukan!\n", namaKota);
                }
			
			    break;
			}
                
            case 3: {
            	printf("Nama Kota yang akan dihapus: ");
			    fgets(namaKota, MAX_NAME_LENGTH, stdin);
			    namaKota[strcspn(namaKota, "\n")] = '\0';
			
			    deleteKota(&kota, namaKota);
                
                break;
            }
                
            case 4: {
                printf("Nama Kota: ");
			    fgets(namaKota, MAX_NAME_LENGTH, stdin);
			    namaKota[strcspn(namaKota, "\n")] = '\0';
			
				foundCity = searchKota(&kota, namaKota);
			    if (foundCity != NULL) {
                    printf("Nama Warga yang akan dihapus: ");
                    fgets(warga, MAX_NAME_LENGTH, stdin);
                    warga[strcspn(warga, "\n")] = '\0';
                    deleteWarga(foundCity, warga);
                } else {
                    printf("Kota %s tidak ditemukan!\n", namaKota);
                }
			
			    break;
			}
                
            case 5: {
                displayAll(kota);
                break;
            }
            
            case 6: {
                printf("Program selesai.\n");
                break;
            }
			    
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 6);

    return 0;
}




