
# ADVENTURE CAMP
## Sistem Penyewaan Peralatan Camping

### 1. Identitas Mahasiswa

- **Nama:** Salsabila Rusdi
- **NIM:** C2583207040
- **Nama program:** ADVENTURE CAMP
- **Mata Kuliah:** Algoritma dan Pemrograman Lanjutan
- **Tahun:** 2026

### 2. Deskripsi Program

Adventure Camp adalah program aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C untuk membantu proses penyewaan peralatan camping.

Program ini memungkinkan pengguna untuk melihat daftar peralatan, menyewa beberapa jenis barang dalam satu transaksi, menghitung biaya penyewaan secara otomatis, mendapatkan diskon berdasarkan lama penyewaan, melihat struk pembayaran, dan memeriksa riwayat transaksi.

Program ini dibuat untuk menerapkan konsep pemrograman terstruktur dalam menyelesaikan permasalahan sederhana.

### 3. Tujuan Program

1. Mempermudah proses penyewaan peralatan camping.
2. Menghitung biaya penyewaan secara otomatis.
3. Menerapkan percabangan dan perulangan dalam bahasa C.
4. Menggunakan fungsi dan array untuk mengelola data.
5. Menerapkan validasi input.
6. Menyimpan dan menampilkan riwayat transaksi.

### 4. Daftar Peralatan dan Harga Sewa

| No. | Nama Peralatan | Harga Sewa per Hari |
|---|---|---:|
| 1 | Tenda Kapasitas 4 Orang | Rp50.000 |
| 2 | Sleeping Bag | Rp15.000 |
| 3 | Kompor Portable | Rp20.000 |
| 4 | Matras Camping | Rp10.000 |
| 5 | Lampu Camping | Rp12.000 |

### 5. Fitur Program

1. **Lihat Daftar Peralatan**  
   Menampilkan lima jenis peralatan camping beserta harga sewanya.

2. **Sewa Peralatan**  
   Memasukkan nama penyewa, memilih beberapa jenis barang, menentukan jumlah setiap barang, dan memasukkan lama penyewaan.

3. **Perhitungan Biaya Otomatis**  
   Menghitung biaya berdasarkan harga sewa, jumlah unit, dan lama penyewaan.

4. **Diskon Penyewaan**  
   - Penyewaan 1–2 hari: diskon 0%.
   - Penyewaan 3–4 hari: diskon 10%.
   - Penyewaan 5 hari atau lebih: diskon 15%.

5. **Struk Penyewaan**  
   Menampilkan rincian barang, jumlah unit, subtotal, diskon, dan total pembayaran.

6. **Riwayat Transaksi**  
   Menyimpan maksimal 10 transaksi selama program berjalan.

7. **Total Pendapatan**  
   Menghitung jumlah transaksi dan total pendapatan.

8. **Validasi Input**  
   Memeriksa masukan pengguna agar sesuai dengan ketentuan program.

### 6. Rumus Perhitungan

**Subtotal:**

Subtotal = Harga Sewa × Jumlah Unit × Lama Penyewaan

**Diskon:**

Diskon = Subtotal × Persentase Diskon / 100

**Total Pembayaran:**

Total Bayar = Subtotal − Diskon

### 7. Contoh Perhitungan

Seorang penyewa menyewa:
- 2 tenda selama 3 hari.
- 3 sleeping bag selama 3 hari.
- 1 kompor portable selama 3 hari.

Perhitungan biaya:

- Tenda: Rp50.000 × 2 × 3 = Rp300.000
- Sleeping Bag: Rp15.000 × 3 × 3 = Rp135.000
- Kompor Portable: Rp20.000 × 1 × 3 = Rp60.000

Subtotal = Rp495.000

Diskon 10% = Rp49.500

**Total Pembayaran = Rp445.500**

### 8. Konsep Pemrograman yang Digunakan

- **Variabel:** menyimpan data penyewaan.
- **Array:** menyimpan daftar peralatan dan riwayat transaksi.
- **Struct:** mengelompokkan informasi transaksi.
- **Fungsi:** membagi program menjadi beberapa bagian.
- **If-else:** menentukan diskon penyewaan.
- **Switch-case:** mengatur pilihan menu.
- **For:** menampilkan daftar barang dan riwayat transaksi.
- **Do-while:** mengulang menu utama.
- **Validasi input:** memeriksa masukan pengguna.

### 9. Cara Menjalankan Program

1. Buka Code::Blocks.
2. Buat proyek Console Application menggunakan bahasa C.
3. Masukkan kode program ke file `main.c`.
4. Simpan file.
5. Tekan `F9` atau klik **Build and Run**.
6. Gunakan menu yang tersedia untuk menjalankan program.

### 10. Screenshot Hasil Program

Tambahkan screenshot asli hasil eksekusi program pada bagian ini.

Screenshot yang disarankan:
- Tampilan menu utama.
- Tampilan daftar peralatan.
- Tampilan penyewaan beberapa jenis barang.
- Tampilan struk pembayaran.
- Tampilan riwayat transaksi.

Contoh susunan file screenshot:

- `screenshot/menu-utama.png`
- `screenshot/daftar-peralatan.png`
- `screenshot/penyewaan.png`
- `screenshot/struk.png`
- `screenshot/riwayat.png`

### 11. Struktur Repository

```text
Adventure-Camp/
├── main.c
├── README.md
└── screenshot/
    ├── menu-utama.png
    ├── daftar-peralatan.png
    ├── penyewaan.png
    ├── struk.png
    └── riwayat.png
```

### 12. Kesimpulan

Program Adventure Camp merupakan aplikasi penyewaan peralatan camping sederhana yang dibuat menggunakan bahasa C. Program ini dapat menampilkan daftar peralatan, menerima penyewaan beberapa jenis barang dalam satu transaksi, menghitung biaya dan diskon secara otomatis, menampilkan struk, serta menyimpan riwayat transaksi selama program berjalan.

Pembuatan program ini membantu mahasiswa memahami penerapan konsep pemrograman terstruktur, fungsi, array, percabangan, perulangan, dan validasi input.

---

**Program Studi Pendidikan Teknologi Informasi**  
**Universitas Muhammadiyah Tasikmalaya**  
**2026**
