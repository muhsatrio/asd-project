#include "header.h"

using namespace std;

int main() {
    int menu1=-1,menu2=-1;
    list_kk LKK;
    list_rt LRT;
    list_anggota_kk LAnggotaKK;
    address_rt art;
    address_kk akk;
    address_anggota_kk aakk;
    info_rt irt;
    info_kk ikk;
    info_anggota_kk iakk;
    createListRT(LRT);
    while (menu1!=0) {
        cout << "Aplikasi Sistem Informasi Kependudukan Sipil\n";
        cout << "==================================\n";
        cout << "1. Input Data RT, Keluarga, dan Anggota Keluarga\n";
        cout << "2. Update Data RT, Keluarga, dan Anggota Keluarga\n";
        cout << "3. Hapus Data RT, Keluarga, dan Anggota Keluarga\n";
        cout << "4. View Data RT, Keluarga, dan Anggota Keluarga\n";
        cout << "5. Search Data RT, Keluarga, dan Anggota Keluarga\n";
        cout << "6. Bantuan\n";
        cout << "0. Exit\n";
        cin >> menu1;
        if (menu1==1) {
            cout << "Menu Input\n";
            cout << "===================\n";
            cout << "1. Input RT\n";
            cout << "2. Input Keluarga\n";
            cout << "3. Input Anggota Keluarga\n";
            cout << "0. Kembali ke Menu Sebelumnya\n";
            cin >> menu2;
            if (menu2==1) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                cout << "Masukkan Ketua RT:\n";
                cin >> irt.ketua_rt;
                cout << "Masukkan Alamat Kantor Sekretariat RT:\n";
                cin >> irt.alamat;
                art = searchRT(LRT,irt);
                if (art==Nil) {
                    insertRT(LRT,irt);
                    cout << "Data berhasil diinput\n";
                }
                else
                    cout << "Nomor RT yang anda inputkan sudah ada di daftar\n";
                //cout << "a\n";
            }
            else if (menu2==2) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Silahkan Input Data Keluarga\n";
                    cout << "=====================\n";
                    cout << "Masukkan Nomor Keluarga:\n";
                    cin >> ikk.nkk;
                    cout << "Masukkan Alamat:\n";
                    cin >> ikk.alamat;
                    if (searchKK(listkk(art),ikk)==Nil) {
                        insertKK(listkk(art),ikk);
                        cout << "Data Kartu Keluarga Berhasil Ditambah\n";
                    }
                    //cout << first(listkk(art)) << endl;
                }
                else
                    cout << "Nomor RT tidak ditemukan\n";
                //cout << "b\n";
            }
            else if (menu2==3) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor Kartu Keluarga:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Silahkan Masukkan Data Anggota Keluarga\n";
                        cout << "====================";
                        cout << "Masukkan NIK\n";
                        cin >> iakk.nik;
                        cout << "Masukkan Nama:\n";
                        cin >> iakk.nama;
                        cout << "Masukkan Tempat Lahir:\n";
                        cin >> iakk.tempat_lahir;
                        cout << "Masukkan Tanggal Lahir (Format = DD-MM-YYYY):\n";
                        cin >> iakk.tanggal_lahir;
                        cout << "Masukkan Jenis Kelamin:\n";
                        cin >> iakk.jenis_kelamin;
                        cout << "Masukkan Status Dalam Keluarga\n";
                        cin >> iakk.status;
                        cout << "Masukkan Pekerjaan:\n";
                        cin >> iakk.pekerjaan;
                        if (searchAnggotaKK(listanggotakk(akk),iakk)==Nil) {
                            insertAnggotaKK(listanggotakk(akk),iakk);
                            cout << "Data Anggota Keluarga Berhasil Ditambah\n";
                        }
                        else
                            cout << "Nomor Induk Keluarga sudah ada\n";
                    }
                    else
                        cout << "Nomor Kartu Keluarga tidak ditemukan\n";
                }
                else
                    cout << "Nomor RT tidak ditemukan\n";
                //cout << "c\n";
            }
        }
        else if (menu1==2) {
            cout << "Menu Update\n";
            cout << "===================\n";
            cout << "1. Update RT\n";
            cout << "2. Update Keluarga\n";
            cout << "3. Update Anggota Keluarga\n";
            cout << "0. Kembali ke Menu Sebelumnya\n";
            cin >> menu2;
            if (menu2==1) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Data Yang Ingin Diubah\n";
                    cout << "Jika ada data yang tidak diubah, cukup isikan '-'\n";
                    cout << "=========================\n";
                    cout << "Masukkan Nomor RT:\n";
                    cin >> irt.no_rt;
                    cout << "Masukkan Ketua RT:\n";
                    cin >> irt.ketua_rt;
                    cout << "Masukkan Alamat Kantor Sekretariat RT:\n";
                    cin >> irt.alamat;
                    updateRT(art,irt);
                    cout << "Data Telah Sukses Diubah\n";
                    //cout << "a\n";
                }
                else
                    cout << "Nomor RT Tidak Ditemukan\n";

            }
            else if (menu2==2) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Masukkan data yang ingin diubah.\n";
                        cout << "Jika ada data yang tidak diubah, cukup tekan '-'\n";
                        cout << "=============================\n";
                        cout << "Masukkan Nomor Kartu Keluarga:\n";
                        cin >> ikk.nkk;
                        cout << "Masukkan Alamat Rumah:\n";
                        cin >> ikk.alamat;
                        updateKK(akk,ikk);
                        cout << "Data telah sukses diubah\n";
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data tidak ditemukan.\n";
            }
            else if (menu2==3) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Masukkan Nomor Induk Keluarga:\n";
                        cin >> iakk.nik;
                        aakk = searchAnggotaKK(listanggotakk(akk),iakk);
                        if (aakk!=Nil) {
                            cout << "Masukkan data yang ingin diubah.\n";
                            cout << "Jika ada data yang tidak diubah, cukup tekan '-'\n";
                            cout << "=============================\n";
                            cout << "Masukkan NIK\n";
                            cin >> iakk.nik;
                            cout << "Masukkan Nama:\n";
                            cin >> iakk.nama;
                            cout << "Masukkan Tempat Lahir:\n";
                            cin >> iakk.tempat_lahir;
                            cout << "Masukkan Tanggal Lahir (Format = DD-MM-YYYY):\n";
                            cin >> iakk.tanggal_lahir;
                            cout << "Masukkan Jenis Kelamin:\n";
                            cin >> iakk.jenis_kelamin;
                            cout << "Masukkan Status Dalam Keluarga\n";
                            cin >> iakk.status;
                            cout << "Masukkan Pekerjaan:\n";
                            updateAnggotaKK(aakk,iakk);
                            cout << "Data telah sukses diubah.\n";
                        }
                        else
                            cout << "Data tidak ditemukan.\n";
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data tidak ditemukan.\n";
                //cout << "c\n";
            }
        }
        else if (menu1==3) {
            cout << "Menu Hapus\n";
            cout << "===================\n";
            cout << "1. Hapus RT\n";
            cout << "2. Hapus Keluarga\n";
            cout << "3. Hapus Anggota Keluarga\n";
            cout << "0. Kembali ke Menu Sebelumnya\n";
            cin >> menu2;
            if (menu2==1) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    deleteRT(LRT,irt);
                }
                else
                    cout << "Data Tidak Ditemukan\n";
                //cout << "a\n";
            }
            else if (menu2==2) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        deleteKK(listkk(art),ikk);
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data Tidak Ditemukan\n";
                //cout << "b\n";
            }
            else if (menu2==3) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Masukkan Nomor Anggota Keluarga:\n";
                        cin >> iakk.nik;
                        aakk = searchAnggotaKK(listanggotakk(akk),iakk);
                        if (aakk!=Nil) {
                            deleteAnggotaKK(listanggotakk(akk),iakk);
                        }
                        else
                            cout << "Data tidak ditemukan.\n";
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data Tidak Ditemukan\n";
                //cout << "c\n";
            }
        }
        else if (menu1==4) {
            cout << "Menu View\n";
            cout << "===================\n";
            cout << "1. View RT\n";
            cout << "2. View Keluarga\n";
            cout << "3. View Anggota Keluarga\n";
            cout << "0. Kembali ke Menu Sebelumnya\n";
            cin >> menu2;
            if (menu2==1) {
                viewRT(LRT);
            }
            else if (menu2==2) {
                cout << "Masukkan RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    viewKK(listkk(art));
                }
                else
                    cout << "Data tidak ditemukan.\n";
            }
            else if (menu2==3) {
                cout << "Masukkan RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        viewAnggotaKK(listanggotakk(akk));
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data tidak ditemukan.\n";
                //cout << "c\n";
            }
        }
        else if (menu1==5) {
            cout << "Menu Pencarian\n";
            cout << "===================\n";
            cout << "1. Pencarian RT\n";
            cout << "2. Pencarian Keluarga\n";
            cout << "3. Pencarian Anggota Keluarga\n";
            cout << "0. Kembali ke Menu Sebelumnya\n";
            cin >> menu2;
            if (menu2==1) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Data ditemukan.\n";
                    cout << "Nomor RT: " << info(art).no_rt << endl;
                    cout << "Ketua RT: " << info(art).ketua_rt << endl;
                    cout << "Alamat Sekretariat RT: " << irt.alamat << endl;
                }
                else
                    cout << "Data tidak ditemukan.\n";
            }
            else if (menu2==2) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Data ditemukan.\n";
                        cout << "Nomor KK: " << info(akk).nkk << endl;
                        cout << "Alamat Rumah: " << info(akk).alamat << endl;
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data tidak ditemukan.\n";
                //cout << "b\n";
            }
            else if (menu2==3) {
                cout << "Masukkan Nomor RT:\n";
                cin >> irt.no_rt;
                art = searchRT(LRT,irt);
                if (art!=Nil) {
                    cout << "Masukkan Nomor KK:\n";
                    cin >> ikk.nkk;
                    akk = searchKK(listkk(art),ikk);
                    if (akk!=Nil) {
                        cout << "Masukkan Nomor Induk Keluarga:\n";
                        cin >> iakk.nik;
                        aakk = searchAnggotaKK(listanggotakk(akk),iakk);
                        if (aakk!=Nil) {
                            cout << "Data ditemukan.\n";
                            cout << "Nomor Induk Keluarga: " << info(aakk).nik << endl;
                            cout << "Nama: " << info(aakk).nama << endl;
                            cout << "Tempat, Tanggal Lahir: " << info(aakk).tempat_lahir << ", " << info(aakk).tanggal_lahir << endl;
                            cout << "Status Keluarga: " << info(aakk).status;
                            cout << "Jenis Kelamin: " << info(aakk).jenis_kelamin;
                            cout << "Pekerjaan: " << info(aakk).pekerjaan;
                        }
                        else
                            cout << "Data tidak ditemukan.\n";
                    }
                    else
                        cout << "Data tidak ditemukan.\n";
                }
                else
                    cout << "Data tidak ditemukan.\n";
                cout << "c\n";
            }
        }
        else if (menu1==6) {
            cout << "Bantuan\n";
            cout << "===================\n";
            cout << "Coming Soon\n";
        }
    }
}
