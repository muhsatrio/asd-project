#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#define listkk(L) (L)->lkk
#define listanggotakk(L) (L)->l_anggota_kk

using namespace std;


struct info_rt {
    string no_rt;
    string alamat;
    string ketua_rt;
};

struct info_kk  {
    string nkk;
    string alamat;
};

struct info_anggota_kk {
    string nik;
    string nama;
    string tempat_lahir;
    string tanggal_lahir;
    string jenis_kelamin;
    string status;
    string pekerjaan;
};

typedef struct elmlist_rt *address_rt;
typedef struct elmlist_kk *address_kk;
typedef struct elmlist_anggota_kk *address_anggota_kk;

//List Anggota Keluarga

struct elmlist_anggota_kk {
    info_anggota_kk info;
    address_anggota_kk next;
    address_anggota_kk prev;
};

struct list_anggota_kk {
    address_anggota_kk first;
    address_anggota_kk last;
};



// List Keluarga

struct elmlist_kk {
    info_kk info;
    list_anggota_kk l_anggota_kk;
    address_kk next;
    address_kk prev;
};

struct list_kk {
    address_kk first;
    address_kk last;
};

//List RT

struct elmlist_rt {
    info_rt info;
    list_kk lkk;
    address_rt next;
    address_rt prev;
};

struct list_rt {
    address_rt first;
    address_rt last;
};

void createListRT(list_rt &LRT);
void createListKK(list_kk &LKK);
void createListAnggotaKK(list_anggota_kk &LanggotaKK);
address_anggota_kk alokasiAnggotaKK(info_anggota_kk infoAnggotaKK);
address_kk alokasiKK(info_kk infoKK);
address_rt alokasiRT(info_rt infoRT);
void insertRT(list_rt &LRT, info_rt x);
void insertKK(list_kk &LKK, info_kk x);
void insertAnggotaKK(list_anggota_kk &LAnggotaKK, info_anggota_kk x);
address_rt searchRT(list_rt LRT, info_rt x);
address_kk searchKK(list_kk LKK, info_kk x);
address_anggota_kk searchAnggotaKK(list_anggota_kk LAnggotaKK, info_anggota_kk x);
void updateRT(address_rt p, info_rt x);
void updateKK(address_kk p, info_kk x);
void updateAnggotaKK(address_anggota_kk p, info_anggota_kk x);
void deleteRT(list_rt &LRT, info_rt x);
void deleteKK(list_kk &LKK, info_kk x);
void deleteAnggotaKK(list_anggota_kk &LAnggotaKK, info_anggota_kk x);
void viewRT(list_rt LRT);
void viewKK(list_kk LKK);
void viewAnggotaKK(list_anggota_kk LAnggotaKK);
#endif // HEADER_H_INCLUDED
