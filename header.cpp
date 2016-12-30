#include "header.h"

using namespace std;

void createListRT(list_rt &LRT) {
    first(LRT) = Nil;
    last(LRT) = Nil;
}
void createListKK(list_kk &LKK) {
    first(LKK) = Nil;
    last(LKK) = Nil;
}
void createListAnggotaKK(list_anggota_kk &LanggotaKK) {
    first(LanggotaKK) = Nil;
    last(LanggotaKK) = Nil;
}
address_anggota_kk alokasiAnggotaKK(info_anggota_kk infoAnggotaKK) {
    address_anggota_kk p;
    p = new elmlist_anggota_kk;
    info(p) = infoAnggotaKK;
    return p;
}
address_kk alokasiKK(info_kk infoKK) {
    address_kk p;
    p = new elmlist_kk;
    info(p) = infoKK;
    return p;
}
address_rt alokasiRT(info_rt infoRT) {
    address_rt p;
    p = new elmlist_rt;
    info(p) = infoRT;
    return p;
}
void insertRT(list_rt &LRT, info_rt x) {
    address_rt p;
    p = alokasiRT(x);
    //cout << info(p).no_rt << endl;
    if (first(LRT)==Nil && last(LRT)==Nil) {
        first(LRT) = p;
        last(LRT) = p;
    }
    else {
        prev(p) = last(LRT);
        next(last(LRT)) = p;
        last(LRT) = p;
    }
}
void insertKK(list_kk &LKK, info_kk x) {
    address_kk p;
    p = alokasiKK(x);
    if (first(LKK)==Nil && last(LKK)==Nil) {
        first(LKK) = p;
        last(LKK) = p;
    }
    else {
        prev(p) = last(LKK);
        next(last(LKK)) = p;
        last(LKK) = p;

    }
}
void insertAnggotaKK(list_anggota_kk &LAnggotaKK, info_anggota_kk x) {
    address_anggota_kk p;
    p = alokasiAnggotaKK(x);
    if (first(LAnggotaKK)==Nil && last(LAnggotaKK)==Nil) {
        first(LAnggotaKK) = p;
        last(LAnggotaKK) = p;
    }
    else {
        prev(p) = last(LAnggotaKK);
        next(last(LAnggotaKK)) = p;
        last(LAnggotaKK) = p;
    }
}
address_rt searchRT(list_rt LRT, info_rt x) {
    if (first(LRT)==Nil && last(LRT)==Nil) {
        //cout << "List Kosong\n";
        return Nil;
    }
    else {
        address_rt p = first(LRT);
        while (info(p).no_rt!=x.no_rt && next(p)!=Nil)
            p = next(p);
        if (info(p).no_rt==x.no_rt)
            return p;
        else {
            //cout << "Data tidak ditemukan\n";
            return Nil;
        }
    }
}
address_kk searchKK(list_kk LKK, info_kk x) {
    if (first(LKK)==Nil && last(LKK)==Nil) {
        //cout << "List Kosong\n";
        return Nil;
    }
    else {
        address_kk p = first(LKK);
        while (info(p).nkk!=x.nkk && next(p)!=Nil)
            p = next(p);
        if (info(p).nkk==x.nkk)
            return p;
        else {
            //cout << "Data tidak ditemukan\n";
            return Nil;
        }
    }
}
address_anggota_kk searchAnggotaKK(list_anggota_kk LAnggotaKK, info_anggota_kk x) {
    if (first(LAnggotaKK)==Nil && last(LAnggotaKK)==Nil) {
        //cout << "List Kosong\n";
        return Nil;
    }
    else {
        address_anggota_kk p;
        p = first(LAnggotaKK);
        while (info(p).nik!=x.nik && next(p)!=Nil)
            p = next(p);
        if (info(p).nik == x.nik)
            return p;
        else {
            //cout << "Data tidak ditemukan\n";
            return Nil;
        }
    }
}

void updateRT(address_rt p, info_rt x) {
    if (x.no_rt!="-")
        info(p).no_rt = x.no_rt;
    if (x.ketua_rt!="-")
        info(p).ketua_rt = x.ketua_rt;
    if (x.alamat!="-")
        info(p).alamat = x.alamat;
}
void updateKK(address_kk p, info_kk x) {
    if (x.nkk!="-")
        info(p).nkk = x.nkk;
    if (x.alamat!="-")
        info(p).alamat = x.alamat;
}
void updateAnggotaKK(address_anggota_kk p, info_anggota_kk x) {
    if (x.nik!="-")
        info(p).nik = x.nik;
    if (x.nama!="-")
        info(p).nama = x.nama;
    if (x.jenis_kelamin!="-")
        info(p).jenis_kelamin = x.jenis_kelamin;
    if (x.tempat_lahir!="-")
        info(p).tempat_lahir = x.tempat_lahir;
    if (x.tanggal_lahir!="-")
        info(p).tanggal_lahir = x.tanggal_lahir;
    if (x.pekerjaan!="-")
        info(p).pekerjaan = x.pekerjaan;
    if (x.status!="-")
        info(p).status = x.status;
}

void deleteRT(list_rt &LRT, info_rt x) {
    address_rt p = searchRT(LRT,x);
    if (p!=Nil) {
        if (p==first(LRT)) {
            first(LRT) = next(first(LRT));
            next(p) = Nil;
            prev(first(LRT)) = Nil;
        }
        else if (p==last(LRT)) {
            last(LRT) = prev(last(LRT));
            prev(p) = Nil;
            next(last(LRT)) = Nil;
        }
        else {
            address_rt q = next(p);
            next(prev(p)) = q;
            prev(q) = prev(p);
            next(p) = Nil;
            prev(p) = Nil;
        }
        cout << "Data dengan Nomor RT " << x.no_rt << " berhasil dihapus.\n";
    }
    else
        cout << "Data dengan Nomor RT " << x.no_rt << " tidak bisa dihapus\n";
}
void deleteKK(list_kk &LKK, info_kk x) {
    address_kk p = searchKK(LKK,x);
    if (p!=Nil) {
        if (p==first(LKK)) {
            first(LKK) = next(first(LKK));
            next(p) = Nil;
            prev(first(LKK)) = Nil;
        }
        else if (p==last(LKK)) {
            last(LKK) = prev(last(LKK));
            prev(p) = Nil;
            next(last(LKK)) = Nil;
        }
        else {
            address_kk q = next(p);
            next(prev(p)) = q;
            prev(q) = prev(p);
            next(p) = Nil;
            prev(p) = Nil;
        }
        cout << "Data dengan Nomor KK " << x.nkk << " berhasil dihapus.\n";
    }
    else
        cout << "Data dengan Nomor KK " << x.nkk << " tidak bisa dihapus\n";

}
void deleteAnggotaKK(list_anggota_kk &LAnggotaKK, info_anggota_kk x) {
    address_anggota_kk p = searchAnggotaKK(LAnggotaKK, x);
    if (p!=Nil) {
        if (p==first(LAnggotaKK)) {
            first(LAnggotaKK) = next(first(LAnggotaKK));
            next(p) = Nil;
            prev(first(LAnggotaKK)) = Nil;
        }
        else if (p==last(LAnggotaKK)) {
            last(LAnggotaKK) = prev(last(LAnggotaKK));
            prev(p) = Nil;
            next(last(LAnggotaKK)) = Nil;
        }
        else {
            address_anggota_kk q = next(p);
            next(prev(p)) = q;
            prev(q) = prev(p);
            next(p) = Nil;
            prev(p) = Nil;
        }
        cout << "Data dengan Nomor Induk Keluarga " << x.nik << " berhasil dihapus.\n";
    }
    else
        cout << "Data dengan Nomor Induk Keluarga " << x.nik << " tidak bisa dihapus\n";
}
void viewRT(list_rt LRT) {
    address_rt p = first(LRT);
    while (p!=Nil) {
        cout << "Nomor RT: " << info(p).no_rt << endl;
        cout << "Ketua RT: " << info(p).ketua_rt << endl;
        cout << "Alamat Kantor RT: " << info(p).alamat << endl;
        cout << "=====================\n";
        p=next(p);
    }
}
void viewKK(list_kk LKK) {
    address_kk p = first(LKK);
    while (p!=Nil) {
        cout << "Nomor KK: " << info(p).nkk << endl;
        cout << "Alamat: " << info(p).alamat << endl;
        cout << "=====================\n";
        p=next(p);
    }
}
void viewAnggotaKK(list_anggota_kk LAnggotaKK) {
    address_anggota_kk p = first(LAnggotaKK);
    while (p!=Nil) {
        cout << "Nomor Induk Keluarga: " << info(p).nik << endl;
        cout << "Nama: " << info(p).nama << endl;
        cout << "Tempat, Tanggal Lahir: " << info(p).tempat_lahir << ", " << info(p).tanggal_lahir;
        cout << "Status: " << info(p).status << endl;
        cout << "Jenis Kelamin: " << info(p).jenis_kelamin << endl;
        cout << "Pekerjaan: " << info(p).pekerjaan << endl;
        cout << "=====================\n";
        p=next(p);
    }
}
