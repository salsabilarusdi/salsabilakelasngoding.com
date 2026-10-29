
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define JUMLAH_ALAT 5
#define MAKS_TRANSAKSI 10

/* Data peralatan camping */
char *namaAlat[JUMLAH_ALAT] = {
    "Tenda Kapasitas 4 Orang",
    "Sleeping Bag",
    "Kompor Portable",
    "Matras Camping",
    "Lampu Camping"
};

long hargaAlat[JUMLAH_ALAT] = {
    50000, 15000, 20000, 10000, 12000
};

/* Struktur untuk menyimpan satu transaksi */
struct Transaksi {
    char namaPenyewa[100];
    int jumlahBarang[JUMLAH_ALAT];
    int lamaSewa;
    long subtotal;
    long diskon;
    long totalBayar;
    int persenDiskon;
};

struct Transaksi riwayat[MAKS_TRANSAKSI];
int jumlahTransaksi = 0;

/* Fungsi validasi input angka */
int inputAngka(const char *pesan, int min, int max) {
    char buffer[100];
    char tambahan;
    int angka;
    int hasil;

    while (1) {
        printf("%s", pesan);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\nInput berakhir. Program dihentikan.\n");
            exit(0);
        }

        hasil = sscanf(buffer, " %d %c", &angka, &tambahan);

        if (hasil == 1 && angka >= min && angka <= max) {
            return angka;
        }

        printf("Input tidak valid! Masukkan angka %d sampai %d.\n",
               min, max);
    }
}

/* Fungsi menampilkan daftar peralatan */
void tampilkanPeralatan(void) {
    int i;

    printf("\n================================================\n");
    printf("              DAFTAR PERALATAN\n");
    printf("================================================\n");
    printf("%-5s %-28s %s\n", "No.", "Nama Peralatan", "Harga/Hari");
    printf("------------------------------------------------\n");

    for (i = 0; i < JUMLAH_ALAT; i++) {
        printf("%-5d %-28s Rp%ld\n",
               i + 1, namaAlat[i], hargaAlat[i]);
    }

    printf("================================================\n");
}

/* Fungsi menampilkan struk penyewaan */
void tampilkanStruk(struct Transaksi t) {
    int i;
    int adaBarang = 0;

    printf("\n================================================\n");
    printf("                ADVENTURE CAMP\n");
    printf("                 STRUK SEWA\n");
    printf("================================================\n");
    printf("Nama Penyewa : %s\n", t.namaPenyewa);
    printf("Lama Sewa    : %d hari\n", t.lamaSewa);
    printf("------------------------------------------------\n");
    printf("%-28s %5s %12s\n", "Nama Peralatan", "Jumlah", "Subtotal");
    printf("------------------------------------------------\n");

    for (i = 0; i < JUMLAH_ALAT; i++) {
        if (t.jumlahBarang[i] > 0) {
            long biaya = hargaAlat[i]
                       * t.jumlahBarang[i]
                       * t.lamaSewa;

            printf("%-28s %5d Rp%10ld\n",
                   namaAlat[i], t.jumlahBarang[i], biaya);

            adaBarang = 1;
        }
    }

    if (!adaBarang) {
        printf("Tidak ada barang.\n");
    }

    printf("------------------------------------------------\n");
    printf("Subtotal       : Rp%ld\n", t.subtotal);
    printf("Diskon (%d%%)   : Rp%ld\n",
           t.persenDiskon, t.diskon);
    printf("------------------------------------------------\n");
    printf("TOTAL BAYAR    : Rp%ld\n", t.totalBayar);
    printf("================================================\n");
    printf("Terima kasih telah menggunakan\n");
    printf("layanan Adventure Camp!\n");
}

/* Fungsi melakukan penyewaan beberapa jenis barang */
void sewaPeralatan(void) {
    struct Transaksi t;
    char buffer[100];
    char pilihan;
    int i;
    int totalJenis = 0;

    if (jumlahTransaksi >= MAKS_TRANSAKSI) {
        printf("\nMaaf, kapasitas transaksi sudah penuh.\n");
        printf("Maksimal %d transaksi.\n", MAKS_TRANSAKSI);
        return;
    }

    /* Inisialisasi data transaksi */
    memset(&t, 0, sizeof(t));

    printf("\n================================================\n");
    printf("             FORM PENYEWAAN\n");
    printf("================================================\n");

    /* Input nama penyewa */
    while (1) {
        printf("Nama penyewa: ");

        if (fgets(t.namaPenyewa, sizeof(t.namaPenyewa), stdin) == NULL) {
            printf("\nInput berakhir. Program dihentikan.\n");
            exit(0);
        }

        t.namaPenyewa[strcspn(t.namaPenyewa, "\n")] = '\0';

        if (strlen(t.namaPenyewa) > 0) {
            break;
        }

        printf("Nama tidak boleh kosong!\n");
    }

    /* Menampilkan daftar barang */
    tampilkanPeralatan();

    printf("\nMasukkan jumlah setiap barang yang ingin disewa.\n");
    printf("Masukkan 0 jika barang tidak ingin disewa.\n\n");

    /* Input jumlah masing-masing jenis barang */
    do {
        totalJenis = 0;

        for (i = 0; i < JUMLAH_ALAT; i++) {
            char pesan[120];

            snprintf(pesan, sizeof(pesan),
                     "Jumlah %s: ", namaAlat[i]);

            t.jumlahBarang[i] = inputAngka(pesan, 0, 100000);

            if (t.jumlahBarang[i] > 0) {
                totalJenis++;
            }
        }

        if (totalJenis == 0) {
            printf("\nAnda belum memilih barang apa pun.\n");
            printf("Silakan pilih minimal satu jenis barang.\n\n");
        }

    } while (totalJenis == 0);

    /* Input lama penyewaan */
    t.lamaSewa = inputAngka(
        "\nLama penyewaan (hari): ", 1, 100000
    );

    /* Menghitung total seluruh barang */
    t.subtotal = 0;

    for (i = 0; i < JUMLAH_ALAT; i++) {
        t.subtotal += hargaAlat[i]
                    * t.jumlahBarang[i]
                    * t.lamaSewa;
    }

    /* Menentukan diskon berdasarkan lama sewa */
    if (t.lamaSewa >= 5) {
        t.persenDiskon = 15;
    } else if (t.lamaSewa >= 3) {
        t.persenDiskon = 10;
    } else {
        t.persenDiskon = 0;
    }

    t.diskon = t.subtotal * t.persenDiskon / 100;
    t.totalBayar = t.subtotal - t.diskon;

    /* Menampilkan struk pembayaran */
    tampilkanStruk(t);

    /* Menyimpan transaksi ke riwayat */
    riwayat[jumlahTransaksi] = t;
    jumlahTransaksi++;

    /* Pilihan kembali ke menu utama */
    while (1) {
        printf("\nKembali ke menu utama? (Y/T): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\nInput berakhir. Program dihentikan.\n");
            exit(0);
        }

        pilihan = (char)toupper((unsigned char)buffer[0]);

        if (pilihan == 'Y' || pilihan == 'T') {
            break;
        }

        printf("Pilihan tidak valid! Masukkan Y atau T.\n");
    }

    if (pilihan == 'T') {
        printf("\nTerima kasih telah menggunakan Adventure Camp!\n");
        printf("Program selesai.\n");
        exit(0);
    }
}

/* Fungsi menampilkan riwayat transaksi */
void tampilkanRiwayat(void) {
    int i, j;
    long totalPendapatan = 0;

    printf("\n================================================\n");
    printf("               RIWAYAT TRANSAKSI\n");
    printf("================================================\n");

    if (jumlahTransaksi == 0) {
        printf("Belum ada transaksi penyewaan.\n");
        printf("================================================\n");
        return;
    }

    for (i = 0; i < jumlahTransaksi; i++) {
        printf("\nTransaksi ke-%d\n", i + 1);
        printf("Nama Penyewa : %s\n",
               riwayat[i].namaPenyewa);
        printf("Lama Sewa    : %d hari\n",
               riwayat[i].lamaSewa);
        printf("Barang yang disewa:\n");

        for (j = 0; j < JUMLAH_ALAT; j++) {
            if (riwayat[i].jumlahBarang[j] > 0) {
                printf("- %-28s : %d unit\n",
                       namaAlat[j],
                       riwayat[i].jumlahBarang[j]);
            }
        }

        printf("Subtotal     : Rp%ld\n", riwayat[i].subtotal);
        printf("Diskon       : Rp%ld\n", riwayat[i].diskon);
        printf("Total Bayar  : Rp%ld\n",
               riwayat[i].totalBayar);
        printf("------------------------------------------------\n");

        totalPendapatan += riwayat[i].totalBayar;
    }

    printf("\nJumlah Transaksi : %d\n", jumlahTransaksi);
    printf("Total Pendapatan : Rp%ld\n", totalPendapatan);
    printf("================================================\n");
}

/* Fungsi utama program */
int main(void) {
    int menu;

    do {
        printf("\n================================================\n");
        printf("                ADVENTURE CAMP\n");
        printf("          SISTEM PENYEWAAN PERALATAN\n");
        printf("================================================\n");
        printf("1. Lihat Daftar Peralatan\n");
        printf("2. Sewa Peralatan\n");
        printf("3. Lihat Riwayat Transaksi\n");
        printf("4. Keluar\n");
        printf("================================================\n");

        menu = inputAngka("Pilih menu [1-4]: ", 1, 4);

        switch (menu) {
            case 1:
                tampilkanPeralatan();
                break;

            case 2:
                sewaPeralatan();
                break;

            case 3:
                tampilkanRiwayat();
                break;

            case 4:
                printf("\nTerima kasih telah menggunakan\n");
                printf("layanan Adventure Camp!\n");
                printf("Program selesai.\n");
                break;
        }

    } while (menu != 4);

    return 0;
}
