#include <stdio.h>

#define PI 3.14 // konstanta dengan #define

int main() {
const int TAHUN_SEKARANG = 2025; // konstanta dengan const
int umur = 17;
float tinggi = 165.5;
char hurufAwal = 'R';

printf("=== Data Siswa ===\n");
printf("Huruf awal nama : %c\n", hurufAwal);
printf("Umur : %d tahun\n", umur);
printf("Tinggi badan : %.2f cm\n", tinggi);
printf("Tahun sekarang : %d\n", TAHUN_SEKARANG);
printf("Nilai PI : %.2f\n", PI);

return 0;
}
