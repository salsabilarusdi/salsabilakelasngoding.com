#include <stdio.h>
int main() {
int jumlahSiswa;
// Input jumlah siswa
printf("Masukkan jumlah siswa: ");
if (scanf("%d", &jumlahSiswa) != 1 || jumlahSiswa <= 0) {
printf("Input jumlah siswa tidak valid.\n");
return 1;
}
// Deklarasi array sesuai jumlah siswa
char nama[jumlahSiswa][50];
int nilai[jumlahSiswa];
float totalNilai = 0;
// Input data siswa
for (int i = 0; i < jumlahSiswa; i++) {
printf("\nSiswa ke-%d\n", i + 1);
printf("Nama: ");
// Menggunakan scanf dengan %[^\n] agar bisa membaca nama dengan spasi
scanf(" %[^\n]s", nama[i]);
printf("Nilai: ");
scanf("%d", &nilai[i]);
// Akumulasi total nilai
totalNilai += nilai[i];
}
// Menampilkan hasil
printf("\n=== HASIL ===\n");
for (int i = 0; i < jumlahSiswa; i++) {
printf("%s - %d - %s\n",
nama[i],
nilai[i],
(nilai[i] >= 75 ? "LULUS" : "TIDAK LULUS"));
}
// Menampilkan rata-rata

printf("\nRata-rata kelas: %.2f\n", totalNilai / jumlahSiswa);
return 0;
}
