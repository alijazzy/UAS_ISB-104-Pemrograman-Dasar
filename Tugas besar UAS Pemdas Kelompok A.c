/*
Tugas Besar UAS - ISB 104 Pemrograman Dasar
Kelompok A
162022015, 162022021, 162022028
Program Layanan Rawat Jalan RS Sejahtera
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct dataAdmin{
    char id_adm[20];
    char nama_adm[40];
    char usnm_adm[30];
    char pass_adm[20];
};

struct dataPasien{
    char nama_pasien[40];
    char no_hp[15];
    char alamat_pasien[60];
    char jenis_kelamin[15];
    char lahir_pasien[15];
    char kerja_pasien[30];
};

struct poliklinik{
    char nama_poli[30];
    char kode_poli[20];
};

struct dataDokter{
    char kode_dokter[20];
    char nama_dokter[40];
    char spesialis[30];
    char poli_dokter[30];
};

struct registrasiUlang{
    char tgl_regis[15];
    char no_regis[15];
    char nama_regis[40];
    char jk_regis[15];
    char lahir_regis[15];
    char poli_tujuan[30];
    char dokter_sem[40];
    char asuransi[30];
};

struct notaPasien{
    char tgl_bayar[15];
    char no_nota[15];
    char biaya[40];
    char total_bayar[40];
};

char namaAdminLogin[20];
struct registrasiUlang regis;
char noHp_regis[15];

void registrasi();
int login_adm();
void tambahData(int jenis);
void tampilData(int jenis);
int hitungJumlah();
void editData(int jenis);
void hapusData(int jenis);
void regisUlang();
int cekData(char tempNama[], char noHP[]);
void cekDokter(char tempPoli[]);
void filterTampilan();
void tampilDataRegis();
void tampilDataByTanggal();
void tampilDataByPoli();
void tampilDataByDokter();
void transaksi();
void cetakNota();
void daftarTransaksi();
void cariDataPasien();
void cariDataSehat(int jenis);


int main(){
    int pilihanMenuUtama=0,hasilLogin=0,menu2=0,backMenu=0,pilihanMenu=0;
    int jenis=0;
    //Menu Login
    do
        {
        system("cls");
        printf("==============================\n");
        printf("SISTEM INFORMASI RS SEJAHTERA");
        printf("\n-----------------------------\n");
        printf("Program Layanan Rawat Jalan\n");
        printf("-----------------------------\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("3. Keluar\n");
        printf("-----------------------------\n");
        printf("Masukkan Pilihan: ");
        scanf("%d",&pilihanMenuUtama);

        switch(pilihanMenuUtama){
            case 1: registrasi();break;
            case 2: hasilLogin = login_adm();break;
            case 3:
                printf("\nTerima kasih telah menggunakan\nprogram ini. Sampai jumpa!\n");
                printf("-----------------------------\n");exit(0);break;
            default: printf("Masukkan angka yang benar!\n");break;
        }
        //Keluar Loop
        if(hasilLogin==1){
            break;
        }

    }while(pilihanMenuUtama!=3);

    while(pilihanMenu!=5){
        menu2 = 0;

        system("cls");
        printf("============================\nHai, %s, Selamat Datang di\nProgram Layanan Rawat Jalan^^\n============================\n",namaAdminLogin);
        printf("1. Data Pasien\n");
        printf("2. Data Dokter\n");
        printf("3. Data Poli\n");
        printf("4. Data Registrasi\n");
        printf("5. Keluar\n");
        printf("-----------------------\n");
        printf("Pilih Menu : ");
        scanf("%d",&pilihanMenu);

        switch(pilihanMenu){
            case 1: menu2 = 1;break;
            case 2: menu2 = 2;break;
            case 3: menu2 = 3;break;
            case 4: menu2 = 4;break;
            case 5: printf("\nTerima kasih telah menggunakan\nprogram ini. Sampai jumpa!\n");exit(0);break;
        }

        //Menu Data Pasien
        if(menu2==1){
            do{
                system("cls");
                printf("============================\n\tHai, %s\nApa yang ingin kamu lakukan?\n============================\n",namaAdminLogin);
                printf("1. Tambah Data Pasien\n");
                printf("2. Tampilkan Data Pasien\n");
                printf("3. Pencarian Data Pasien\n");
                printf("4. Edit Data Pasien\n");
                printf("5. Hapus Data Pasien\n");
                printf("6. Kembali\n");
                printf("-----------------------\n");
                printf("Pilih Menu : ");
                scanf("%d",&pilihanMenu);

                switch(pilihanMenu){
                    case 1: tambahData(1);break;
                    case 2: tampilData(1);break;
                    case 3: cariDataPasien();break;
                    case 4: editData(1);break;
                    case 5: hapusData(1);break;
                    case 6: backMenu = 1;break;
                    default: printf("Masukkan angka yang benar!!\n");
                }
                if(backMenu==1){
                    break;
                }
            }while(pilihanMenu!=6);
        }


        //Menu Data Dokter
        else if(menu2==2){
            do{
                system("cls");
                printf("============================\n\tHai, %s\nApa yang ingin kamu lakukan?\n============================\n",namaAdminLogin);
                printf("1. Tambah Data Dokter\n");
                printf("2. Tampilkan Data Dokter\n");
                printf("3. Pencarian Data Dokter\n");
                printf("4. Edit Data Dokter\n");
                printf("5. Hapus Data Dokter\n");
                printf("6. Kembali\n");
                printf("-----------------------\n");
                printf("Pilih Menu : ");
                scanf("%d",&pilihanMenu);

                switch(pilihanMenu){
                    case 1: tambahData(2);break;
                    case 2: tampilData(2);break;
                    case 3: cariDataSehat(1);break;
                    case 4: editData(2);break;
                    case 5: hapusData(2);break;
                    case 6: backMenu = 1;break;
                    default: printf("Masukkan angka yang benar!!\n");
                }
                if(backMenu==1){
                    break;
                }
            }while(pilihanMenu!=6);
        }

        //Menu Data Poli
        else if(menu2==3){
            do{
                system("cls");
                printf("============================\n\tHai, %s\nApa yang ingin kamu lakukan?\n============================\n",namaAdminLogin);
                printf("1. Tambah Data Poli\n");
                printf("2. Tampilkan Data Poli\n");
                printf("3. Pencarian Data Poli\n");
                printf("4. Edit Data Poli\n");
                printf("5. Hapus Data Poli\n");
                printf("6. Kembali\n");
                printf("-----------------------\n");
                printf("Pilih Menu : ");
                scanf("%d",&pilihanMenu);

                switch(pilihanMenu){
                    case 1: tambahData(3);break;
                    case 2: tampilData(3);break;
                    case 3: cariDataSehat(2);break;
                    case 4: editData(3);break;
                    case 5: hapusData(3);break;
                    case 6: backMenu = 1;break;
                    default: printf("Masukkan angka yang benar!!\n");
                }
                if(backMenu==1){
                    break;
                }
            }while(pilihanMenu!=6);
        }

        //Menu Data Registrasi
        else if(menu2==4){
            do{
                system("cls");
                printf("============================\n\tHai, %s\nApa yang ingin kamu lakukan?\n============================\n",namaAdminLogin);
                printf("1. Registrasi Ulang\n");
                printf("2. Tampilkan Data Registrasi\n");
                printf("3. Pencarian Data Registrasi\n");
                printf("4. Buat Nota\n");
                printf("5. Cetak Nota\n");
                printf("6. Daftar Transaksi\n");
                printf("7. Kembali\n");
                printf("-----------------------\n");
                printf("Pilih Menu : ");
                scanf("%d",&pilihanMenu);

                switch(pilihanMenu){
                    case 1: regisUlang();break;
                    case 2: filterTampilan();break;
                    case 3: cariDataSehat(3);break;
                    case 4: transaksi();break;
                    case 5: cetakNota();break;
                    case 6: daftarTransaksi();break;
                    case 7: backMenu = 1;break;
                    default: printf("Masukkan angka yang benar!!\n");
                }
                if(backMenu==1){
                    break;
                }
            }while(pilihanMenu!=7);
        }

    }
}

void registrasi(){
    system("cls");
    FILE *fpoin;
    fpoin = fopen("admin.txt","a+");

    char usnm_temp[30];
    struct dataAdmin adm;
    struct dataAdmin temp;

    printf("======================\n\tREGISTER\n======================\n");
    tambah_username: //goto
    printf("Masukkan Username : ");
    scanf("%s",adm.usnm_adm);

    //Cek username yg sudah ada
    while(fscanf(fpoin,"%s %s %s %[^\n]\n",temp.id_adm,temp.usnm_adm,temp.pass_adm,temp.nama_adm)!=EOF){
        if(strcmp(adm.usnm_adm,temp.usnm_adm)==0){
            printf("Username Sudah Ada!\n");
            printf("Silahkan masukkan username lain. \n\n");
            goto tambah_username;
        }
    }
    printf("Masukkan Password : ");
    scanf("%s",adm.pass_adm);

    printf("Masukkan ID Admin : ");
    scanf("%s",adm.id_adm);

    printf("Masukkan Nama Admin : ");
    fflush(stdin);
    gets(adm.nama_adm);

    //Menulis ke file
    fprintf(fpoin, "%s %s %s %s\n",adm.id_adm,adm.usnm_adm,adm.pass_adm,adm.nama_adm);
    fclose(fpoin);

    printf("--------------------\n");
    printf("Register Berhasil.\n");
    printf("Tekan untuk melanjutkan . . .\n");
    getch();

}

int login_adm(){
    system("cls");
    FILE *fpoin;
    fpoin = fopen("admin.txt","r");

    struct dataAdmin adm;
    int tanda=0,status;
    char userTemp[30];
    char passTemp[20];

    printf("======================\n\tLOGIN\n======================\n");
    printf("Masukkan Username : ");
    scanf("%s",userTemp);
    printf("Masukkan Password : ");
    scanf("%s",passTemp);

    //Cek database
    while(fscanf(fpoin, "%s %s %s %[^\n]\n",adm.id_adm,adm.usnm_adm,adm.pass_adm,adm.nama_adm)!=EOF){
        if(strcmp(userTemp,adm.usnm_adm) ==0){
            tanda+=1;
            if(strcmp(passTemp,adm.pass_adm) ==0){
                tanda+=1;
                break;
            }
        }
    }

    if(tanda==2){
        printf("--------------------\n");
        printf("Login Berhasil . . .\n");
        status = 1;
    }
    else{
        printf("Akun tidak tersedia, silahkan register terlebih dahulu . . .\n");
    }

    //Nama admin yang login
    strcpy(namaAdminLogin, adm.nama_adm);

    fclose(fpoin);
    getch();

    return status;
}

void tambahData(int jenis){
    system("cls");
    FILE *fpoin;

    struct dataPasien pasien;
    struct dataDokter dokter;
    struct poliklinik poli;

    //Tipe data
    if(jenis==1){
        fpoin = fopen("datapasien.txt","a+");
        printf("=========================\n    Tambah Data Pasien\n=========================\n");
        printf("Nama Pasien     : ");
        fflush(stdin);
        scanf("%[^\n]",pasien.nama_pasien);

        printf("No Handphone    : ");
        scanf("%s",pasien.no_hp);

        printf("Alamat          : ");
        fflush(stdin);
        scanf("%[^\n]",pasien.alamat_pasien);

        fflush(stdin);
        printf("Jenis Kelamin   : ");
        scanf("%s",pasien.jenis_kelamin);

        printf("Pekerjaan       : ");
        scanf("%s",pasien.kerja_pasien);

        printf("Tanggal Lahir   : ");
        scanf("%s",pasien.lahir_pasien);

        //Menulis ke file
        fprintf(fpoin, "%s\n", pasien.nama_pasien);
        fprintf(fpoin, "%s\n", pasien.no_hp);
        fprintf(fpoin, "%s\n", pasien.alamat_pasien);
        fprintf(fpoin, "%s\n", pasien.jenis_kelamin);
        fprintf(fpoin, "%s\n", pasien.kerja_pasien);
        fprintf(fpoin, "%s\n", pasien.lahir_pasien);
        fclose(fpoin);

    }
    else if(jenis==2){
        fpoin = fopen("datadokter.txt","a+");
        printf("=========================\n    Tambah Data Dokter\n=========================\n");
        printf("Nama Dokter : ");
        fflush(stdin);
        scanf("%[^\n]",dokter.nama_dokter);

        printf("Kode Dokter : ");
        scanf("%s",dokter.kode_dokter);

        printf("Spesialis   : ");
        fflush(stdin);
        scanf("%[^\n]",dokter.spesialis);

        printf("Poli        : ");
        fflush(stdin);
        scanf("%[^\n]",dokter.poli_dokter);

        //Menulis ke file
        fprintf(fpoin, "%s\n%s\n%s\n%s\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter);
        fclose(fpoin);

    }
    else if(jenis==3){
        fpoin = fopen("datapoli.txt","a+");
        printf("=========================\n    Tambah Data Poli\n=========================\n");

        printf("Nama Poli  : ");
        fflush(stdin);
        scanf("%[^\n]",poli.nama_poli);

        printf("Kode Poli  : ");
        scanf("%s",poli.kode_poli);

        fprintf(fpoin, "%s %s\n",poli.kode_poli,poli.nama_poli);
        fclose(fpoin);
    }

    printf("---------------------------\n");
    printf("\nData berhasil ditambahkan . . .\n");
    getch();

}

void tampilData(int jenis){
    system("cls");
    FILE *fpoin;

    struct dataPasien pasien;
    struct dataDokter dokter;
    struct poliklinik poli;

    if(jenis==1){
        fpoin = fopen("datapasien.txt","r");

        printf("\t\t\tDaftar Pasien\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("| No. |   Nama Pasien    | No Handphone  |      Alamat       | Jenis Kelamin | Pekerjaan | Tanggal Lahir |\n");
        printf("----------------------------------------------------------------------------------------------------------\n");

        int no=1;
        while(fscanf(fpoin,"%[^\n]\n%s\n%[^\n]\n%s\n%s\n%s\n",
                     pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien)!=EOF){
            printf("| %-3d | %-16s | %-13s | %-17s | %-13s | %s |   %s  |\n",
                   no, pasien.nama_pasien, pasien.no_hp, pasien.alamat_pasien, pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien);
            no++;
        }
        printf("----------------------------------------------------------------------------------------------------------\n");
    }
    else if(jenis==2){
        fpoin = fopen("datadokter.txt","r");
        printf("====================== Data Dokter ======================\n");
        printf("-----------------------------------------------------------\n");

        while(fscanf(fpoin,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter)!=EOF){
            printf("Kode Dokter     : %s\n",dokter.kode_dokter);
            printf("Nama            : Dr. %s\n",dokter.nama_dokter);
            printf("Spesialis       : %s\n",dokter.spesialis);
            printf("Poli            : %s\n",dokter.poli_dokter);
            printf("-----------------------------------------------------------\n");
        }
    }
    else if(jenis==3){
        fpoin = fopen("datapoli.txt","r");
        printf("====================== Data Poli ======================\n");
        printf("-----------------------------------------------------------\n");

        while(fscanf(fpoin, "%s %[^\n]\n", poli.kode_poli,poli.nama_poli)!=EOF){
            printf("Kode Poli  : %s\n",poli.kode_poli);
            printf("Nama Poli  : %s\n",poli.nama_poli);
            printf("-----------------------------------------------------------\n");
        }
    }

    fclose(fpoin);
    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

int hitungJumlah(char tempPoli[]){
    FILE *tempa;
    tempa = fopen("datadokter.txt","r");
    struct dataDokter temp;
    int counter;

    counter=0;
    while(fscanf(tempa,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",temp.kode_dokter,temp.spesialis,temp.poli_dokter,temp.nama_dokter)!=EOF){
        if(strcmp(tempPoli,temp.poli_dokter)==0){
            counter++;
        }
    }

    fclose(tempa);

    return counter;
}

void editData(int jenis){
    system("cls");

    int kode,flag=0;
    FILE *fpoin, *temp;
    struct dataPasien pasien,sem;
    struct dataDokter dokter,dem;
    struct poliklinik poli;
    char oldNama[20];
    char newNama[20];
    char tempKode[10];

    if(jenis==1){
        tampilData(jenis);
        fpoin = fopen("datapasien.txt","r");
        temp = fopen("temppasien.txt","w");
        printf("===============================\n\tEdit Data Pasien\n===============================\n");
        printf("-------------------------------------\n");
        printf("Pilih Nomor Pasien yang ingin dirubah: ");
        scanf("%d",&kode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "temppasien.txt");
        strcpy(newNama, "datapasien.txt");

        int no=1;
        while(fscanf(fpoin,"%[^\n]\n %s\n %[^\n]\n %s\n %s\n %s\n",
                     pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien)!=EOF){
            if(kode==no){
                printf("Nama Pasien     : ");
                fflush(stdin);
                scanf("%[^\n]",sem.nama_pasien);

                printf("No Handphone    : ");
                scanf("%s",sem.no_hp);

                printf("Alamat          : ");
                fflush(stdin);
                scanf("%[^\n]",sem.alamat_pasien);

                fflush(stdin);
                printf("Jenis Kelamin   : ");
                scanf("%s",sem.jenis_kelamin);

                printf("Pekerjaan       : ");
                scanf("%s",sem.kerja_pasien);

                printf("Tanggal Lahir   : ");
                scanf("%s",sem.lahir_pasien);

                fprintf(temp,"%s\n%s\n%s\n%s\n%s\n%s\n",sem.nama_pasien,sem.no_hp,sem.alamat_pasien,sem.jenis_kelamin,sem.kerja_pasien,sem.lahir_pasien);
                flag = 1;
            }
            else{
                fprintf(temp,"%s\n%s\n%s\n%s\n%s\n%s\n",
                        pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien);
            }
            no++;
        }
    }
    else if(jenis==2){
        fpoin = fopen("datadokter.txt","r");
        temp = fopen("tempdokter.txt","w");

        printf("===============================\n\tEdit Data Dokter\n===============================\n");
        printf("-------------------------------------\n");
        printf("Masukkan Kode Dokter yang ingin dirubah: ");
        scanf("%s",tempKode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "tempdokter.txt");
        strcpy(newNama, "datadokter.txt");

        while(fscanf(fpoin,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter)!=EOF){
            if(strcmp(tempKode,dokter.kode_dokter)==0){
                printf("Nama Dokter : ");
                fflush(stdin);
                scanf("%[^\n]",dem.nama_dokter);

                printf("Kode Dokter : ");
                scanf("%s",dem.kode_dokter);

                printf("Spesialis   : ");
                scanf("%s",dem.spesialis);

                printf("Poli        : ");
                fflush(stdin);
                scanf("%[^\n]",dem.poli_dokter);

                fprintf(temp,"%s\n%s\n%s\n%s\n",dem.kode_dokter,dem.spesialis,dem.poli_dokter,dem.nama_dokter);
                flag = 1;
            }
            else{
                fprintf(temp,"%s\n%s\n%s\n%s\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter);
            }
        }
    }
    else if(jenis==3){
        fpoin = fopen("datapoli.txt","r");
        temp = fopen("temppoli.txt","w");

        printf("===============================\n\tEdit Data Poli\n===============================\n");
        printf("-------------------------------------\n");
        printf("Masukkan Kode Poli yang ingin dirubah: ");
        scanf("%s",tempKode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "temppoli.txt");
        strcpy(newNama, "datapoli.txt");

        while(fscanf(fpoin, "%s %[^\n]\n", poli.kode_poli,poli.nama_poli)!=EOF){
            if(strcmp(tempKode,poli.kode_poli)==0){
                printf("Nama Poli  : ");
                fflush(stdin);
                scanf("%[^\n]",poli.nama_poli);

                printf("Kode Poli  : ");
                scanf("%s",poli.kode_poli);

                fprintf(temp, "%s %s\n",poli.kode_poli,poli.nama_poli);
                flag = 1;
            }
            else{
                fprintf(temp, "%s %s\n",poli.kode_poli,poli.nama_poli);
            }
        }
    }
    if(flag==0){
        printf("Data tidak ditemukan!\nKembali ke menu utama . . .\n");
        getch();
        return;
    }

    fclose(fpoin);
    fclose(temp);

    remove(newNama);
    rename(oldNama, newNama);

    printf("------------------------------------\n");
    printf("Data Berhasil diubah.\n");
    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

void hapusData(int jenis){
    system("cls");

    int kode,flag=1,no;
    FILE *fpoin, *temp;
    struct dataPasien pasien;
    struct dataDokter dokter;
    struct poliklinik poli;
    char oldNama[20];
    char newNama[20];
    char tempKode[10];

    if(jenis==1){
        tampilData(jenis);
        fpoin = fopen("datapasien.txt","r");
        temp = fopen("temppasien.txt","w");
        printf("===============================\n\tHapus Data Pasien\n===============================\n");
        printf("-------------------------------------\n");
        printf("Pilih Nomor Pasien yang ingin dihapus: ");
        scanf("%d",&kode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "temppasien.txt");
        strcpy(newNama, "datapasien.txt");

        no=1;
        while(fscanf(fpoin,"%[^\n]\n %s\n %[^\n]\n %s\n %s\n %s\n",
                     pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien)!=EOF){
            if(kode!=no){
                fprintf(temp,"%s\n%s\n%s\n%s\n%s\n%s\n",
                        pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien);
                flag++;
            }
            no++;
        }
    }
    else if(jenis==2){
        fpoin = fopen("datadokter.txt","r");
        temp = fopen("tempdokter.txt","w");
        printf("===============================\n\tHapus Data Dokter\n===============================\n");
        printf("-------------------------------------\n");
        printf("Masukkan Kode Dokter yang ingin dihapus: ");
        scanf("%s",tempKode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "tempdokter.txt");
        strcpy(newNama, "datadokter.txt");

        no = 1;
        while(fscanf(fpoin,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter)!=EOF){
            if(strcmp(tempKode,dokter.kode_dokter)!=0){
                fprintf(temp,"%s\n%s\n%s\n%s\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter);
                flag++;
            }
            no++;
        }
    }
    else if(jenis==3){
        fpoin = fopen("datapoli.txt","r");
        temp = fopen("temppoli.txt","w");
        printf("===============================\n\tHapus Data Poli\n===============================\n");
        printf("-------------------------------------\n");
        printf("Masukkan Kode Poli yang ingin dihapus: ");
        scanf("%s",tempKode);
        printf("-------------------------------------\n");
        strcpy(oldNama, "temppoli.txt");
        strcpy(newNama, "datapoli.txt");

        no = 1;
        while(fscanf(fpoin, "%s %[^\n]\n", poli.kode_poli,poli.nama_poli)!=EOF){
            if(strcmp(tempKode,poli.kode_poli)!=0){
                fprintf(temp, "%s %s\n",poli.kode_poli,poli.nama_poli);
                flag++;
            }
            no++;
        }
    }
    if(flag==no){
        printf("Data tidak ditemukan!\n");
    }
    else{
        printf("Data Berhasil dihapus.\n");
    }

    fclose(fpoin);
    fclose(temp);

    remove(newNama);
    rename(oldNama, newNama);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

void regisUlang(){
    system("cls");
    FILE *fpoin;
    fpoin = fopen("registrasi.txt","a+");
    char tempNama[40];
    char noHp[15];

    printf("===============================\n\tRegistrasi Ulang\n===============================\n");
    printf("-------------------------------------\n");
    printf("Masukkan Nama Pasien        : ");
    fflush(stdin);
    scanf("%[^\n]",tempNama);
    printf("Masukkan No Handphone       : ");
    scanf("%s",noHp);

    //Cek data pasien
    int flag = cekData(tempNama,noHp);
    if(flag==0){
        printf("Data Pasien tidak ditemukan!\nSilahkan Masukkan Data Pasien yang benar . . .\nKembali ke menu utama . . .\n\n");
        getch();
        return;
    }

    printf("Masukkan No Registrasi      : ");
    scanf("%s",regis.no_regis);
    printf("Masukkan Tanggal Registrasi : ");
    scanf("%s",regis.tgl_regis);
    printf("Masukkan Poli Tujuan        : ");
    fflush(stdin);
    scanf("%[^\n]",regis.poli_tujuan);

    //Cek data dokter
    cekDokter(regis.poli_tujuan);

    printf("Masukkan Asuransi           : ");
    scanf("%s",regis.asuransi);

    fprintf(fpoin,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
            regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi);
    fclose(fpoin);

    printf("\nData sudah tersimpan . . .\n");
    getch();
}

int cekData(char tempNama[], char noHP[]){
    FILE *fpoin;
    fpoin = fopen("datapasien.txt","r");

    struct dataPasien pasien;
    int flag=0;

    while(fscanf(fpoin,"%[^\n]\n %s\n %[^\n]\n %s\n %s\n %s\n",
                 pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien)!=EOF){
        if((strcmp(tempNama,pasien.nama_pasien)==0) && (strcmp(noHP,pasien.no_hp)==0)){
            strcpy(regis.nama_regis,pasien.nama_pasien);
            strcpy(regis.lahir_regis,pasien.lahir_pasien);
            strcpy(regis.jk_regis,pasien.jenis_kelamin);
            strcpy(noHp_regis,pasien.no_hp);
            flag = 1;
        }
    }
    fclose(fpoin);
    return flag;
}

void cekDokter(char tempPoli[]){
    FILE *fpoin;
    fpoin = fopen("datadokter.txt","r");

    int jumlah = hitungJumlah(tempPoli);
    struct dataDokter dokter[jumlah];
    struct dataDokter a;
    int kode;
    int i=0;
    while(fscanf(fpoin,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",a.kode_dokter,a.spesialis,a.poli_dokter,a.nama_dokter)!=EOF){
        if(strcmp(tempPoli,a.poli_dokter)==0){
            strcpy(dokter[i].kode_dokter,a.kode_dokter);
            strcpy(dokter[i].nama_dokter,a.nama_dokter);
            strcpy(dokter[i].spesialis,a.spesialis);
            strcpy(dokter[i].poli_dokter,a.poli_dokter);

            i++;
        }
    }

    printf("\n\t\tDaftar Dokter\n");
    printf("-------------------------------------------------------\n");
    printf("|No.|  Nama Dokter   | Kode Dokter | Spesialis | Poli |\n");
    printf("-------------------------------------------------------\n");

    for(int j=0; j<jumlah; j++){
        printf("| %d | Dr. %s | %-10s  | %-9s | %s |\n",j+1,dokter[j].nama_dokter,dokter[j].kode_dokter,dokter[j].spesialis,dokter[j].poli_dokter);
    }
    printf("-------------------------------------------------------\n");
    printf("\nPilih Dokter : ");
    scanf("%d",&kode);
    strcpy(regis.dokter_sem,dokter[kode-1].nama_dokter);
    fclose(fpoin);
}

void filterTampilan(){
    system("cls");
    int pilihanTampilan = 0;

    printf("===================== Filter Tampilan =====================\n");
    printf("--------------------------------------------------------\n");
    printf("Pilihan Tampilan Data Berdasarkan:\n");
    printf("--------------------------------------------------------\n");
    printf("1. Semua Data Registrasi\n");
    printf("2. Tanggal Registrasi\n");
    printf("3. Poli\n");
    printf("4. Nama Dokter\n");
    printf("5. Kembali\n");
    printf("-----------------------\n");
    printf("Pilih Opsi: ");
    scanf("%d", &pilihanTampilan);
    printf("-----------------------\n");

    switch(pilihanTampilan){
        case 1: tampilDataRegis();break;
        case 2: tampilDataByTanggal();break;
        case 3: tampilDataByPoli();break;
        case 4: tampilDataByDokter();break;
        case 5: return;
        default: printf("Masukkan Angka yang Benar!!\n");
    }
}

void tampilDataRegis(){
    system("cls");
    FILE *fpoin;
    fpoin = fopen("registrasi.txt","r");

    printf("\n\t\tDaftar Pasien\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| No. |   Nama Pasien    | No Registrasi | Tanggal Registrasi | Poli Tujuan |    Dokter      | Asuransi |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
        regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
        printf("| %-3d | %-16s | %-12s  | %-18s | %-11s | Dr. %-10s | %-8s |\n",
        no,regis.nama_regis,regis.no_regis, regis.tgl_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi);
        no++;
    }
    printf("---------------------------------------------------------------------------------------------------------\n");

    fclose(fpoin);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();

}

void tampilDataByTanggal() {
    FILE *fpoin;
    fpoin = fopen("registrasi.txt", "r");
    char tanggal[15];
    int found = 0;
    printf("Masukkan Tanggal: ");
    scanf("%s", tanggal);
    printf("Hasil Pencarian : \n");

    printf("\t\t\tDaftar Pasien\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| No. |   Nama Pasien    | No Registrasi | Tanggal Registrasi | Poli Tujuan |    Dokter      | Asuransi |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while (fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
            regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF) {
        if (strcmp(tanggal, regis.tgl_regis) == 0) {
            printf("| %-3d | %-16s | %-12s  | %-18s | %-11s | Dr. %-10s | %-8s |\n",
                no,regis.nama_regis,regis.no_regis, regis.tgl_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi);
            found = 1;
            no++;
        }
    }
    printf("---------------------------------------------------------------------------------------------------------\n");

    if (found == 0) {
        printf("Data Tidak Ditemukan!\n");
    }

    fclose(fpoin);

    getch();
}

void tampilDataByPoli(){
    FILE *fpoin;
    fpoin = fopen("registrasi.txt", "r");
    char poli[20];
    int found = 0;
    printf("Masukkan Poli   : ");
    scanf("%s", poli);
    printf("Hasil Pencarian : \n");

    printf("\t\t\tDaftar Pasien\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| No. |   Nama Pasien    | No Registrasi | Tanggal Registrasi | Poli Tujuan |    Dokter      | Asuransi |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
        regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
        if (strcmp(poli, regis.poli_tujuan) == 0) {
            printf("| %-3d | %-16s | %-12s  | %-18s | %-11s | Dr. %-10s | %-8s |\n",
                no,regis.nama_regis,regis.no_regis, regis.tgl_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi);
            found = 1;
            no++;
        }
    }
    printf("---------------------------------------------------------------------------------------------------------\n");

    if (found == 0) {
        printf("Data Tidak Ditemukan!\n");
    }

    fclose(fpoin);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

void tampilDataByDokter(){
    FILE *fpoin;
    fpoin = fopen("registrasi.txt", "r");
    char nama[50];
    int found = 0;
    printf("Masukkan Nama Dokter : ");
    fflush(stdin);
    scanf("%[^\n]", nama);
    printf("Hasil Pencarian      : \n");

    printf("\t\t\tDaftar Pasien\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| No. |   Nama Pasien    | No Registrasi | Tanggal Registrasi | Poli Tujuan |    Dokter      | Asuransi |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
        regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
        if (strcmp(nama, regis.dokter_sem) == 0) {
            printf("| %-3d | %-16s | %-12s  | %-18s | %-11s | Dr. %-10s | %-8s |\n",
            no,regis.nama_regis,regis.no_regis, regis.tgl_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi);
            found = 1;
            no++;
        }
    }
    printf("---------------------------------------------------------------------------------------------------------\n");

    if (found == 0) {
        printf("Data Tidak Ditemukan!\n");
    }

    fclose(fpoin);

    getch();
}

void transaksi(){
    system("cls");
    FILE *fpoin,*byr;
    fpoin = fopen("registrasi.txt","r");
    byr = fopen("notapasien.txt","a+");

    struct notaPasien nota;
    char tempKode[20];
    int flag=0;

    printf("===================== Nota Bayar =====================\n");
    printf("-------------------------------------\n");
    printf("Masukkan No Registrasi : ");
    scanf("%s",tempKode);
    printf("\n\tData Pengobatan \n");
    printf("-------------------------------------\n");

    while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
                 regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
        if(strcmp(tempKode,regis.no_regis)==0){
            printf("No Registrasi         : %s\n",regis.no_regis);
            printf("Tanggal Registrasi    : %s\n",regis.tgl_regis);
            printf("Nama Pasien           : %s\n",regis.nama_regis);
            printf("Jenis Kelamin         : %s\n",regis.jk_regis);
            printf("Tanggal Lahir         : %s\n",regis.lahir_regis);
            printf("No Handphone          : %s\n",noHp_regis);
            printf("Poli Tujuan           : %s\n",regis.poli_tujuan);
            printf("Dokter yang Menangani : %s\n",regis.dokter_sem);
            printf("Asuransi              : %s\n",regis.asuransi);
            flag = 1;
            break;
        }
    }
    printf("-------------------------------------\n");
    if(flag==0){
        printf("Data tidak ditemukan!\n");
        getch();
        return;
    }

    printf("Masukkan Tanggal      : ");
    scanf("%s",nota.tgl_bayar);
    printf("No Nota               : ");
    scanf("%s",nota.no_nota);
    printf("Biaya Pelayanan       : ");
    scanf("%s",nota.biaya);
    printf("Total Bayar           : ");
    scanf("%s",nota.total_bayar);

    fprintf(byr,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",nota.no_nota,nota.tgl_bayar,regis.no_regis,regis.tgl_regis,regis.nama_regis,
            regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi,nota.biaya,nota.total_bayar);
    printf("-------------------------------------\n");
    printf("Nota Berhasil Dibuat!\n");

    fclose(fpoin);
    fclose(byr);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

void cetakNota() {
    system("cls");
    FILE *fpoin, *temp;
    char newNama[20];
    char tempKode[10];
    char no_nota[20];
    struct notaPasien nota;
    int kode;

    fpoin = fopen("notapasien.txt", "r");
    temp = fopen("transaksi.txt", "a+");

    printf("=============================== Cetak Nota ===============================\n\n");
    printf("Masukkan Nomor Nota: ");
    scanf("%s", no_nota);
    printf("--------------------------------------------\n");
    printf("\t\tNota Bayar\n");
    printf("--------------------------------------------\n");

    while(fscanf(fpoin,"%s\n%s\n%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n",
        nota.no_nota,nota.tgl_bayar,regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,
        regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi,nota.biaya,nota.total_bayar)!=EOF) {
        if (strcmp(no_nota, nota.no_nota) == 0) {
            printf("Tanggal                     : %s\n", regis.tgl_regis);
            printf("No nota                     : %s\n", nota.no_nota);
            printf("Nama Pasien                 : %s\n", regis.nama_regis);
            printf("No Handphone                : %s\n", noHp_regis);
            printf("Jenis Kelamin               : %s\n", regis.jk_regis);
            printf("Tanggal Lahir               : %s\n", regis.lahir_regis);
            printf("Nama Dokter                 : Dr. %s\n", regis.dokter_sem);
            printf("Nama Poli                   : %s\n", regis.poli_tujuan);
            printf("Asuransi                    : %s\n",regis.asuransi);
            printf("Biaya Konsultasi            : Rp %s\n", nota.biaya);
            printf("============================================\n");
            printf("Total Biaya                 : Rp %s\n", nota.total_bayar);

            printf("--------------------------------------------\n");
            printf("Konfirmasi Pembayaran (0:False/1:True) : ");
            scanf("%d",&kode);
            if(kode==0){
                printf("--------------------------------------------\n");
                printf("Transaksi Dibatalkan!\nKembali Ke Menu Utama . . .\n");
                getch();
                return;
            }
            else{
                printf("--------------------------------------------\n");
                printf("Transaksi Berhasil!\n");
                fprintf(temp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", regis.tgl_regis, nota.no_nota, regis.nama_regis, noHp_regis, regis.jk_regis,
                regis.lahir_regis, regis.dokter_sem, regis.poli_tujuan, nota.biaya, nota.total_bayar);
                break;
            }
        }

    }

    fclose(fpoin);
    fclose(temp);

    printf("Tekan untuk melanjutkan . . .\n");
    getch();
}

void daftarTransaksi(){
    system("cls");
    FILE *fpoin;
    fpoin = fopen("transaksi.txt", "r");
    struct notaPasien nota;

    printf("=============================== Daftar Transaksi ===============================\n\n");
    printf("\t\t\tDaftar Pasien\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("| No. |   Nama Pasien    | No Nota | Tanggal Registrasi | Poli Tujuan | Nama Dokter | Total Bayar |\n");
    printf("---------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while(fscanf(fpoin, "%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n%s\n",
        regis.tgl_regis, nota.no_nota, regis.nama_regis, noHp_regis, regis.jk_regis, regis.lahir_regis, regis.dokter_sem, regis.poli_tujuan, nota.biaya, nota.total_bayar) != EOF) {
        printf("| %-3d | %-16s | %-7s | %-18s | %-11s | %-10s  | Rp %-8s |\n", no, regis.nama_regis, nota.no_nota, regis.tgl_regis, regis.poli_tujuan, regis.dokter_sem, nota.total_bayar);
        no++;
    }
    printf("---------------------------------------------------------------------------------------------------\n");

    fclose(fpoin);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}

void cariDataPasien(){
    system("cls");
    FILE *fpoin;

    struct dataPasien pasien;
    char tempNama[40];
    char tempLahir[15];
    int flag=0;

    fpoin = fopen("datapasien.txt","r");
    printf("===============================\n  Pencarian Data Pasien\n===============================\n");
    printf("Masukkan Nama Pasien    : ");
    fflush(stdin);
    scanf("%[^\n]",tempNama);
    printf("Masukkan Tanggal Lahir  : ");
    scanf("%s",tempLahir);

    printf("\nHasil Pencarian: \n");

    while(fscanf(fpoin,"%[^\n]\n %s\n %[^\n]\n %s\n %s\n %s\n",
        pasien.nama_pasien,pasien.no_hp,pasien.alamat_pasien,pasien.jenis_kelamin,pasien.kerja_pasien,pasien.lahir_pasien)!=EOF){
        if((strcmp(tempNama,pasien.nama_pasien)==0) && (strcmp(tempLahir,pasien.lahir_pasien)==0)){
            printf("-------------------------------------\n");
            printf("Nama Pasien     : %s\n",pasien.nama_pasien);
            printf("Tanggal Lahir   : %s\n",pasien.lahir_pasien);
            printf("Jenis Kelamin   : %s\n",pasien.jenis_kelamin);
            printf("No Handphone    : %s\n",pasien.no_hp);
            printf("Alamat          : %s\n",pasien.alamat_pasien);
            printf("Pekerjaan       : %s\n",pasien.kerja_pasien);

            flag = 1;
        }
    }
    if(flag==0){
        printf("Data tidak ditemukan!\n\nKembali ke menu utama . . .\n");
        getch();
        return;
    }
    printf("-------------------------------------\n");

    fclose(fpoin);
    printf("\nTekan untuk melanjutkan . . .");
    getch();
}

void cariDataSehat(int jenis){
    system("cls");
    FILE *fpoin,*temp;

    struct dataDokter dokter;
    struct poliklinik poli;
    char tempNama[40];
    char tempLahir[15];
    char tempDokter[40];
    char tempPoli[30];
    int flag = 0;

    //Cari data dokter
    if(jenis==1){
        fpoin = fopen("registrasi.txt","r");
        temp = fopen("datadokter.txt","r");

        printf("===============================\n  Pencarian Data Dokter\n===============================\n");
        printf("Masukkan Nama Pasien    : ");
        fflush(stdin);
        scanf("%[^\n]",tempNama);
        printf("Masukkan Tanggal Lahir  : ");
        scanf("%s",tempLahir);

        printf("--------------------------------------------\n");
        printf("\nHasil Pencarian: \n");

        //Loop untuk mencocokan nama & tgl lahir inputan
        while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n",
        regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem)!= EOF){
            if((strcmp(tempNama,regis.nama_regis)==0) && (strcmp(tempLahir,regis.lahir_regis)==0)){
                strcpy(tempDokter,regis.dokter_sem);
                flag++;
            }
        }

        //Loop untuk mencocokan nama dokter
        while(fscanf(temp,"%s\n%[^\n]\n%[^\n]\n%[^\n]\n",dokter.kode_dokter,dokter.spesialis,dokter.poli_dokter,dokter.nama_dokter)!=EOF){
            if(strcmp(tempDokter,dokter.nama_dokter)==0){
                printf("--------------------------------------------\n");
                printf("Pasien ditangani oleh Dokter: \n");
                printf("Kode Dokter     : %s\n",dokter.kode_dokter);
                printf("Nama            : Dr. %s\n",dokter.nama_dokter);
                printf("Spesialis       : %s\n",dokter.spesialis);
                printf("Poli            : %s\n",dokter.poli_dokter);
                printf("--------------------------------------------\n");
            }
        }

        //Pengecekan apakah datanya ada
        if(flag==0){
            printf("Data tidak ditemukan!\nPasien belum registrasi!\n");
        }
    }

    //Cari data poli
    else if(jenis==2){
        fpoin = fopen("registrasi.txt","r");
        temp = fopen("datapoli.txt","r");

        printf("===============================\n  Pencarian Data Poli\n===============================\n");
        printf("Masukkan Nama Pasien    : ");
        fflush(stdin);
        scanf("%[^\n]",tempNama);
        printf("Masukkan Tanggal Lahir  : ");
        scanf("%s",tempLahir);

        printf("--------------------------------------------\n");
        printf("\nHasil Pencarian: \n");

        //Loop untuk mencocokan nama & tgl lahir inputan
        while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
            regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
            if((strcmp(tempNama,regis.nama_regis)==0) && (strcmp(tempLahir,regis.lahir_regis)==0)){
                strcpy(tempPoli,regis.poli_tujuan);
                flag++;
            }
        }

        //Loop untuk mencocokan nama poli
        while(fscanf(temp, "%s %[^\n]\n", poli.kode_poli,poli.nama_poli)!=EOF){
            if(strcmp(tempPoli,poli.nama_poli)==0){
                printf("--------------------------------------------\n");
                printf("Pasien berada dalam Poli \n\n");
                printf("Kode Poli  : %s\n",poli.kode_poli);
                printf("Nama Poli  : %s\n",poli.nama_poli);
                printf("--------------------------------------------\n");
            }
        }

        //Pengecekan apakah datanya ada
        if(flag==0){
            printf("Data tidak ditemukan!\nPasien belum registrasi!\n");
        }
    }

    //Cari data registrasi ulang
    else if(jenis==3){
        fpoin = fopen("registrasi.txt","r");

        printf("===============================\n  Pencarian Data Registrasi\n===============================\n");
        printf("Masukkan Nama Pasien    : ");
        fflush(stdin);
        scanf("%[^\n]",tempNama);
        printf("Masukkan Tanggal Lahir  : ");
        scanf("%s",tempLahir);

        printf("--------------------------------------------\n");
        printf("\nHasil Pencarian: \n");

        //Loop untuk mencocokan nama & tgl lahir inputan
        while(fscanf(fpoin,"%s\n%s\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n%s\n",
                 regis.no_regis,regis.tgl_regis,regis.nama_regis,regis.jk_regis,regis.lahir_regis,noHp_regis,regis.poli_tujuan,regis.dokter_sem,regis.asuransi)!= EOF){
            if((strcmp(tempNama,regis.nama_regis)==0) && (strcmp(tempLahir,regis.lahir_regis)==0)){
                printf("--------------------------------------------\n");
                printf("\tData Registrasi\n");
                printf("Kode Registrasi         : %s\n",regis.no_regis);
                printf("Tanggal Registrasi      : %s\n",regis.tgl_regis);
                printf("Nama Pasien             : %s\n",regis.nama_regis);
                printf("Jenis Kelamin           : %s\n",regis.jk_regis);
                printf("Tanggal Lahir           : %s\n",regis.lahir_regis);
                printf("Poli Tujuan             : %s\n",regis.poli_tujuan);
                printf("Dokter yang Menangani   : Dr. %s\n",regis.dokter_sem);
                printf("Asuransi                : %s\n",regis.asuransi);
                printf("--------------------------------------------\n");
                flag++;
            }
        }

        //Pengecekan apakah datanya ada
        if(flag==0){
            printf("Data tidak ditemukan!\nPasien belum registrasi!\n");
        }
    }

    fclose(fpoin);
    fclose(temp);

    printf("\nTekan untuk melanjutkan . . .\n");
    getch();
}
