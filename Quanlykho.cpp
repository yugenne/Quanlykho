#include <iostream>  
#include <fstream>   // Thư viện để thao tác với tệp văn bản (Đọc/Ghi File)
#include <string>    // Thư viện cho kiểu dữ liệu chuỗi
#include <vector>    // Thư viện cho cấu trúc dữ liệu vector
#include <iomanip>   // Thư viện cho định dạng đầu ra (setw và setprecision)
#include <sstream>   // Thư viện cho xây dựng và xử lý chuỗi đầu vào/đầu ra
using namespace std;
void trolai() {
    cout << "\033[32m|========================================|\033[0m" << endl;
    cout << "\033[32m|\033[0m\033[31m1. Hien thi chi tiet thong tin laptop\033[0m   \033[32m|\033[0m" << endl;
    cout << "\033[32m|\033[0m\033[31m2. Tro lai menu\033[0m                         \033[32m|\033[0m" << endl;
    cout << "\033[32m|========================================|\033[0m" << endl << endl;
    cout << "Nhap lua chon cua ban: ";
}
class laptop {
private:
    string ten;
    string hang;
    string manhinh;
    string CPU;
    string Card;
    string Pin;
    string Khoiluong;
    double soluong;
    double giaban;
    double giamua;
public:
    laptop(string ten, string hang, string CPU, double soluong, double giaban, double giamua)
        : ten(ten), hang(hang), CPU(CPU), soluong(soluong), giaban(giaban), giamua(giamua) {}
    laptop() : soluong(0), giaban(0), giamua(0) {}
    void SetSoLuong(double newSoLuong) {
        soluong = newSoLuong;
    }
    void SetGiaBan(double newGiaBan) {
        giaban = newGiaBan;
    }
    void SetGiamua(double GM) {
        giamua = GM;
    }
    void SetTen(string newten) {
        ten = newten;
    }
    void Sethang(string newhang) {
        hang = newhang;
    }
    void Setmanhinh(string newmahinh) {
        manhinh = newmahinh;
    }
    void SetCard(string card) {
        Card = card;
    }
    void SetKL(string kl) {
        Khoiluong = kl;
    }
    void Setsoluong(double SL) {
        soluong = SL;
    }
    void SetCPU(string cpu) {
        CPU = cpu;
    }
    void SetPin(string pin) {
        Pin = pin;
    }
    string GetTen() const {
        return ten;
    }
    string GetHang() const {
        return hang;
    }
    string Getmanhinh() const {
        return manhinh;
    }
    string GetCard() const {
        return Card;
    }
    string GetPin() const {
        return Pin;
    }
    string GetKhoiluong() const {
        return Khoiluong;
    }
    string GetCPU() const {
        return CPU;
    }
    double GetSoLuong() const {
        return soluong;
    }
    double GetGiaBan() const {
        return giaban;
    }
    double GetGiaMua() const {
        return giamua;
    }
    void NhapThongTin() {
        cout << "Nhap ten laptop: ";
        getline(cin, ten);
        cout << "Nhap hang: ";
        getline(cin, hang);
        cout << "Nhap man hinh :";
        getline(cin, manhinh);
        cout << "Nhap CPU: ";
        getline(cin, CPU);
        cout << "Nhap lai Card: ";
        getline(cin, Card);
        cout << "Nhap loai Pin: ";
        getline(cin, Pin);
        cout << "Nhap khoi luong: ";
        getline(cin, Khoiluong);
        cout << "Nhap so luong :";
        cin >> soluong;
        cout << "Nhap gia ban :";
        cin >> giaban;
        cout << "Nhap gia mua: ";
        cin >> giamua;
        cin.ignore();
    }
    void XuatThongTinlaptop()const {
        cout << setw(6) << "      #====================================#======================================#" << endl;
        cout << setw(43) << left << "      |   Ten laptop: " << setw(3) << "|" << setw(36) << ten << "|" << endl;
        cout << setw(43) << "      |   Hang: " << setw(3) << "|" << setw(36) << hang << "|" << endl;
        cout << setw(43) << "      |   Man hinh: " << setw(3) << "|" << setw(36) << manhinh << "|" << endl;
        cout << setw(43) << "      |   CPU: " << setw(3) << "|" << setw(36) << CPU << "|" << endl;
        cout << setw(43) << "      |   Card: " << setw(3) << "|" << setw(36) << Card << "|" << endl;
        cout << setw(43) << "      |   Pin: " << setw(3) << "|" << setw(36) << Pin << "|" << endl;
        cout << setw(43) << "      |   Khoi luong: " << setw(3) << "|" << setw(36) << Khoiluong << "|" << endl;
        cout << setw(43) << "      |   So luong hien co trong kho: " << setw(3) << "|" << "" << setw(36) << soluong << "|" << endl;
        cout << setw(43) << "      |   Gia mua: " << fixed << setprecision(0) << setw(3) << "|" << setw(36) << giamua << "|" << endl;
        cout << setw(43) << "      |   Gia ban: " << fixed << setprecision(0) << setw(3) << "|" << setw(36) << giaban << "|" << endl;
        cout << setw(6) << "      #====================================#======================================#" << endl;
    }
};
class Quanlikho {
private:
    vector<laptop> kho;
    vector<laptop>laptopnhap;
    vector<laptop>laptopxuat;
public:
    void CapNhatFileTXT() {
        // Mở tệp văn bản để ghi
        ofstream fs("D:\\New folder\\Project2\\laptop23.txt", ios::out);
        // Kiểm tra xem tệp có mở thành công không
        if (!fs.is_open()) {
            cout << "Không thể mở tệp để cập nhật!" << endl;
            return;
        }
        // Ghi thông tin của từng laptop từ vector kho vào tệp văn bản
        for (const auto& lt : kho) {
            fs << lt.GetTen() << "," << lt.GetHang() << "," << lt.Getmanhinh() << "," << lt.GetCPU() << "," << lt.GetCard() << "," << lt.GetPin() << "," << lt.GetKhoiluong() << "," << lt.GetSoLuong() << "," << fixed << setprecision(0) << lt.GetGiaBan() << "," << fixed << setprecision(0) << lt.GetGiaMua() << '\n';
        }
        // Đóng tệp văn bản
        fs.close();
        // Xóa tệp cũ
        remove("D:\\New folder\\Project2\\laptop22.txt");
        // Đổi tên tệp mới thành tên tệp cũ
        rename("D:\\New folder\\Project2\\laptop23.txt", "D:\\New folder\\Project2\\laptop22.txt");
    }
    void DocFile() {
        ifstream fs;
        fs.open("D:\\New folder\\Project2\\laptop22.txt", ios::in);
        laptop lt;
        kho.clear(); // Xóa nội dung của danh sách laptop trước khi đọc từ file
        string line;
        while (getline(fs, line)) { // Đọc từng dòng của tệp
            stringstream ss(line); // Tạo stringstream từ dòng đọc được
            string ten, hang, manhinh, CPU, Card, Pin, Khoiluong, soluong, giaban, giamua;
            getline(ss, ten, ',');
            getline(ss, hang, ',');
            getline(ss, manhinh, ',');
            getline(ss, CPU, ',');
            getline(ss, Card, ',');
            getline(ss, Pin, ',');
            getline(ss, Khoiluong, ',');
            getline(ss, soluong, ',');
            getline(ss, giaban, ',');
            getline(ss, giamua, '\n');
            lt.SetTen(ten);
            lt.Sethang(hang);
            lt.Setmanhinh(manhinh);
            lt.SetCPU(CPU);
            lt.SetCard(Card);
            lt.SetPin(Pin);
            lt.SetKL(Khoiluong);
            lt.SetSoLuong(stod(soluong));
            lt.SetGiaBan(stod(giaban));
            lt.SetGiamua(stod(giamua));
            kho.push_back(lt);  //Thêm đối tượng vừa đọc vào vector kho
        }
    }
    void xuatlaptoptheoSTT(int& STT) {
        kho[STT - 1].XuatThongTinlaptop();
    }
    int nhapSTT() {
        int STT;
        cout << "Nhap STT laptop : ";
        cin >> STT;
        while (STT <= 0 || STT > kho.size()) {
            cout << "STT laptop khong hop le, vui long nhap lai !" << endl;
            cout << "Nhap STT laptop: ";
            cin >> STT;
        }
        return STT;
    }
    void HienThiDanhSachLaptop() const {
        cout << setw(75) << "\033[32m|_______________________________|\033[0m" << endl;
        cout << setw(75) << "\033[32m|                               |\033[0m" << endl;
        cout << setw(75) << "\033[32m|  DANH SACH LAPTOP TRONG KHO   |\033[0m" << endl;
        cout << setw(75) << "\033[32m|_______________________________|\033[0m" << endl;
        cout << "\n     #=====#=========================================================#===========#=================#" << endl;
        cout << "     | \033[31mSTT\033[0m | " << "             " << "\033[31mTen Laptop\033[0m" << "                                " << " | \033[31mSo luong\033[0m  | " << "      \033[31mGia ban\033[0m   | " << endl;
        cout << "     #=====#=========================================================#===========#=================#" << endl;
        int stt = 1;
        for (int i = 0; i < kho.size(); i++) {
            cout << right << setw(8) << "|  " << setw(2) << stt++ << setw(6) << "|    " << setw(42) << left << kho[i].GetTen()
                << right << setw(12) << "  |" << right << setw(7) << kho[i].GetSoLuong() << setw(5) << "|"
                << setw(13) << right << fixed << setprecision(0) << kho[i].GetGiaBan() << setw(5) << "|" << endl;
        }
        cout << "     #=====#=========================================================#===========#=================#" << endl;
        cout << "\033[31m---------------------------------------------------------------------------------------------------------\033[0m" << endl;
    }
    void Hienthidanhsachlaptopnhapxuat()const {
        cout << "\033[32m                           |==================================|\033[0m" << endl;
        cout << "\033[32m                           |DANH SACH LAPTOP DA NHAP VAO KHO  | \033[0m" << endl;
        cout << "\033[32m                           |==================================|\033[0m" << endl;
        cout << "\n     #=====#=========================================================#===========#=================#" << endl;
        cout << "     | \033[31mSTT\033[0m | " << "             " << "\033[31mTen Laptop\033[0m" << "                                " << " | \033[31mSo luong\033[0m  | " << "      \033[31mGia mua\033[0m   | " << endl;
        cout << "     #=====#=========================================================#===========#=================#" << endl;
        int stt = 1;
        for (int i = 0; i < laptopnhap.size(); i++) {
            cout << right << setw(8) << "|  " << setw(2) << stt++ << setw(6) << "|    " << setw(42) << left << laptopnhap[i].GetTen()
                << right << setw(12) << "  |" << right << setw(7) <<laptopnhap[i].GetSoLuong() << setw(5) << "|"
                << setw(13) << right << fixed << setprecision(0) << laptopnhap[i].GetGiaMua() << setw(5) << "|" << endl;
        }
        cout << "     #=====#=========================================================#===========#=================#" << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\033[31m                           |==================================|\033[0m" << endl;
        cout << "\033[31m                           |DANH SACH LAPTOP DA XUAT KHOI KHO |\033[0m" << endl;
        cout << "\033[31m                           |==================================|\033[0m" << endl;
        cout << "\n     #=====#=========================================================#===========#=================#" << endl;
        cout << "     | \033[31mSTT\033[0m | " << "             " << "\033[31mTen Laptop\033[0m" << "                                " << " | \033[31mSo luong\033[0m  | " << "      \033[31mGia ban\033[0m   | " << endl;
        cout << "     #=====#=========================================================#===========#=================#" << endl;
        int stt1 = 1;
        for (int i = 0; i < laptopxuat.size(); i++) {
            cout << right << setw(8) << "|  " << setw(2) << stt1++ << setw(6) << "|    " << setw(42) << left << laptopxuat[i].GetTen()
                << right << setw(12) << "  |" << right << setw(7) << laptopxuat[i].GetSoLuong() << setw(5) << "|"
                << setw(13) << right << fixed << setprecision(0) << laptopxuat[i].GetGiaBan() << setw(5) << "|" << endl;
        }
        cout << "     #=====#=========================================================#===========#=================#" << endl << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
    }
    double tinhdoanhthu() {
        double doanhthu = 0;
        for (int i = 0; i < laptopxuat.size(); i++) {
            doanhthu += laptopxuat[i].GetGiaBan() * laptopxuat[i].GetSoLuong();
        }
        return doanhthu;
    }
    double tinhchiphi() {
        double chiphi = 0;
        for (int i = 0; i < laptopnhap.size(); i++) {
            chiphi += laptopnhap[i].GetGiaMua() * laptopnhap[i].GetSoLuong();
        }
        return chiphi;
    }
    double tinhloinhuan() {
        double DT = tinhdoanhthu();
        double CP = tinhchiphi();
        double loinhuan = DT - CP;
        return loinhuan;
    }
    void XuatLaptoprakhoikho(int& STT) {
        cout << "\033[32mTHONG TIN LAP TOP BAN MUON XUAT KHOI KHO :\033[0m " << endl;
        kho[STT - 1].XuatThongTinlaptop();
        cout << "------------------------------------------" << endl;
        double soluongXuat;
        cout << "Nhap so luong laptop ban muon xuat : ";
        cin >> soluongXuat;
        while (soluongXuat <= 0) {
            cout << "So luong xuat khong hop le. Vui long nhap lai " << endl;
            cout << "Nhap so luong xuat :";
            cin >> soluongXuat;
        }
        while (soluongXuat > kho[STT - 1].GetSoLuong()) {
            cout << "\033[32mKhong du so luong de xuat laptop nay ra khoi kho\033[0m" << endl;
            cout << "Vui long nhap lai so luong xuat :";
            cin >> soluongXuat;
        }
        if (kho[STT - 1].GetSoLuong() >= soluongXuat) {
            kho[STT - 1].SetSoLuong(kho[STT - 1].GetSoLuong() - soluongXuat);
            laptopxuat.push_back(laptop(kho[STT - 1].GetTen(), kho[STT - 1].GetHang(), kho[STT - 1].GetCPU(), soluongXuat, kho[STT - 1].GetGiaBan(), kho[STT - 1].GetGiaMua()));
            CapNhatFileTXT();
            cout << "\033[32mXuat thanh cong " << soluongXuat << " laptop " << kho[STT - 1].GetTen() << " ra kho.\033[0m" << endl;
        }
    }
    void Nhaplaptopvaokho(int& STT) {

        cout << "\033[32mTHONG TIN LAPTOP BAN MUON THEM VAO KHO :\033[0m" << endl;
        kho[STT - 1].XuatThongTinlaptop();
        cout << "-----------------------------------------" << endl;
        double soluongThem;
        cout << "Nhap so luong laptop ban muon them: ";
        cin >> soluongThem;
        while (soluongThem <= 0) {
            cout << "So luong them khong hop le. Vui long nhap lai " << endl;
            cout << "Nhap so luong them :";
            cin >> soluongThem;
        }
        kho[STT - 1].SetSoLuong(kho[STT - 1].GetSoLuong() + soluongThem);
        laptopnhap.push_back(laptop(kho[STT - 1].GetTen(), kho[STT - 1].GetHang(), kho[STT - 1].GetCPU(), soluongThem, kho[STT - 1].GetGiaBan(), kho[STT - 1].GetGiaMua()));
        CapNhatFileTXT();
        cout << "\033[32mNhap thanh cong " << soluongThem << " laptop " << kho[STT - 1].GetTen() << " vao kho.\033[0m" << endl;
    }
    void XoaLaptop(int& STT) {
        cout << "---------------------------------" << endl;
        cout << "\033[32mTHONG TIN LAPTOP BAN MUON XOA :\033[0m" << endl;
        kho[STT - 1].XuatThongTinlaptop();
        cout << "---------------------------------" << endl << endl;
        if (kho[STT - 1].GetSoLuong() > 0) {
            cout << "\033[31mKhong the xoa laptop nay.\033[0m" << endl;
            return;
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << "|Ban co chac muon xoa laptop nay chu?  |" << endl;
        cout << "|1. Vang                               |" << endl;
        cout << "|2. Khong                              |" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Nhap lua chon cua ban (1 hoac 2): ";
        int luachon;
        cin >> luachon;
        switch (luachon) {
        case 1:
            system("cls");
            kho.erase(kho.begin() + STT - 1);
            CapNhatFileTXT();
            cout << "\033[32mDa xoa thanh cong laptop khoi kho.\033[0m" << endl;
            break;
        case 2:
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    }
    void ThemLaptopMoiVaoKho(const laptop& lt) {
        for (int i = 0; i < kho.size(); i++) {
            if (kho[i].GetTen() == lt.GetTen()) {
                kho[i].SetSoLuong(kho[i].GetSoLuong() + lt.GetSoLuong());
                cout << "\033[32mDa them " << kho[i].GetSoLuong() << " laptop" << lt.GetTen() << " vao trong kho trong kho.\033[0m" << endl;
                return;
            }
        }
        kho.push_back(lt);
        laptopnhap.push_back(lt);
        CapNhatFileTXT();
        cout << "\033[32mDa them thanh cong laptop " << lt.GetTen() << " vao kho.\033[0m" << endl;
    }
    void SuaThongTinLaptop(int& STT) {
        cout << "\033[31mCHI CHO PHEP SUA GIA BAN CUA LAPTOP.\033[0m" << endl;
        cout << "\033[32mTHONG TIN LAPTOP BAN MUON SUA:\033[0m" << endl;
        kho[STT - 1].XuatThongTinlaptop();
        cout << "-----------------------------------------------------------" << endl;
        cout << "|Ban co chac muon sua thong tin cho laptop nay chu ?       |" << endl;
        cout << "|1. Vang                                                   |" << endl;
        cout << "|2. Khong.                                                 |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        int luaChon;
        cout << "Nhap lua chon cua ban (1 hoac 2): ";
        cin >> luaChon;
        cin.ignore();
        switch (luaChon) {
        case 1:
            double newGiaBan;
            cout << "Nhap gia ban moi cho laptop: ";
            cin >> newGiaBan;
            while (newGiaBan <= 0) {
                cout << "Gia ban khong hop le. Vui long nhap lai: ";
                cin >> newGiaBan;
            }
            kho[STT - 1].SetGiaBan(newGiaBan);
            CapNhatFileTXT();
            cout << "\033[32mSua thanh cong gia ban cua laptop.\033[0m" << endl;
            break;
        case 2:
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    }
    void SapXepLaptopTheoGiaTangDan() {
        for (int i = 0; i < kho.size() - 1; ++i) {
            for (int j = 0; j < kho.size() - i - 1; ++j) {
                if (kho[j].GetGiaBan() > kho[j + 1].GetGiaBan()) {
                    laptop temp = kho[j];
                    kho[j] = kho[j + 1];
                    kho[j + 1] = temp;
                }
            }
        }
    }
    void SapXepLaptopTheoGiaGiamDan() {
        for (int i = 0; i < kho.size() - 1; ++i) {
            for (int j = 0; j < kho.size() - i - 1; ++j) {
                if (kho[j].GetGiaBan() < kho[j + 1].GetGiaBan()) {
                    laptop temp = kho[j];
                    kho[j] = kho[j + 1];
                    kho[j + 1] = temp;
                }
            }
        }
    }
    void Loclaptoptheohang(string& hang) {
        int Choice5; double p;
        vector<laptop> laptop1;
        for (int i = 0; i < kho.size(); i++) {
            if (kho[i].GetHang() == hang) {
                laptop1.push_back(kho[i]);
            }
        }
        do {
            if (laptop1.empty()) {
                cout << "Khong co laptop nao cua hang " << hang << " trong kho." << endl;
                cout << "Nhap 1 so bat ki de quay lai menu :";
                cin >> p;
                system("cls");
                break;
            }
            else {
                cout << "                           |==========================|" << endl;
                cout << "                           |DANH SACH LAPTOP TRONG KHO| " << endl;
                cout << "                           |==========================|" << endl;
                cout << "\n     #=====#=========================================================#==================#===========#=================#" << endl;
                cout << "     | STT | " << "             " << "Ten Laptop" << "                                " << " |        CPU       | " << "So luong  | " << "      Gia ban   | " << endl;
                cout << "     #=====#=========================================================#==================#===========#=================#" << endl;
                int stt = 1;
                for (int i = 0; i < laptop1.size(); i++) {
                    cout << right << setw(8) << "|  " << setw(2) << stt++ << setw(6) << "|    " << setw(42) << left << laptop1[i].GetTen()
                        << right << setw(12) << "  |" << setw(16) << laptop1[i].GetCPU()
                        << right << "  |" << right << setw(7) << laptop1[i].GetSoLuong() << setw(5) << "|"
                        << setw(13) << right << fixed << setprecision(0) << laptop1[i].GetGiaBan() << setw(5) << "|" << endl;
                }
                cout << "     #=====#=========================================================#==================#===========#=================#" << endl;
                cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;
            }
            trolai();
            cin >> Choice5;
            switch (Choice5) {
            case 1:
                xemthongtinchitietlaptop();
                break;
            case 2:
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        } while (Choice5 != 2);
    }
    void LocLaptopTheoCPU(const string& core) {
        int Choice5;
        vector<laptop> laptop2;
        for (int i = 0; i < kho.size(); i++) {
            if (kho[i].GetCPU() == core) {
                laptop2.push_back(kho[i]);
            }
        }
        do {
            if (laptop2.empty()) {
                cout << "Khong co laptop nao cua CPU " << core << " trong kho." << endl;
            }
            else {
                cout << "                           |==========================|" << endl;
                cout << "                           |DANH SACH LAPTOP TRONG KHO| " << endl;
                cout << "                           |==========================|" << endl;
                cout << "\n     #=====#=========================================================#==================#===========#=================#" << endl;
                cout << "     | STT | " << "             " << "Ten Laptop" << "                                " << " |        CPU       | " << "So luong  | " << "      Gia ban   | " << endl;
                cout << "     #=====#=========================================================#==================#===========#=================#" << endl;
                int stt = 1;
                for (int i = 0; i < laptop2.size(); i++) {
                    cout << right << setw(8) << "|  " << setw(2) << stt++ << setw(6) << "|    " << setw(42) << left << laptop2[i].GetTen()
                        << right << setw(12) << "  |" << setw(16) << laptop2[i].GetCPU()
                        << right << "  |" << right << setw(7) << laptop2[i].GetSoLuong() << setw(5) << "|"
                        << setw(13) << right << fixed << setprecision(0) << laptop2[i].GetGiaBan() << setw(5) << "|" << endl;
                }
                cout << "     #=====#=========================================================#==================#===========#=================#" << endl;
                cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;
            }
            trolai();
            cin >> Choice5;
            switch (Choice5) {
            case 1:
                xemthongtinchitietlaptop();
                break;
            case 2:
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        } while (Choice5 != 2);
    }
    void xemthongtinchitietlaptop() {
        int STT1 = nhapSTT();
        system("cls");
        cout << "\n\n\t\t\t\033[32mTHONG TIN CHI TIET CUA LAPTOP\033[0m\n" << endl;
        xuatlaptoptheoSTT(STT1); cout << endl;
        cout << "     |------------------------------------------------------|" << endl;
        cout << "     |    Ban co muon xuat hoac nhap lap top nay khong ?    |" << endl;
        cout << "     |    1.Co                                              |" << endl;
        cout << "     |    2.Khong                                           |" << endl;
        cout << "     |------------------------------------------------------|" << endl << endl;
        int lc;
        cout << "   Moi ban nhap lua chon (1 hoac 2) :";
        cin >> lc;
        switch (lc) {
        case 1:
            cout << "     |---------------------------------------------------|" << endl;
            cout << "     |    Ban muon xuat hay nhap laptop ?                |" << endl;
            cout << "     |    1. Nhap laptop                                 |" << endl;
            cout << "     |    2. Xuat laptop                                 |" << endl;
            cout << "     |---------------------------------------------------|" << endl << endl;
            int lc1;
            cout << "   Moi ban nhap lua chon (1 hoac 2) :";
            cin >> lc1;
            switch (lc1) {
            case 1:
                system("cls");
                cout << "\033[31mBan da chon nhap lap top nay vao kho !\033[0m" << endl << endl;
                cout << "-----------------------------------" << endl;
                Nhaplaptopvaokho(STT1);
                cout << "Nhap 1 so bat ki de quay lai :";
                double i; cin >> i;
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "\033[31mBan da chon xuat laptop nay ra khoi kho!\033[0m" << endl << endl;
                cout << "------------------------------------" << endl;
                XuatLaptoprakhoikho(STT1);
                cout << "Nhap 1 so bat ki de quay lai :";
                double j; cin >> j;
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
};
void Menu() {
    cout << "\n\033[32m         \tCHAO MUNG BAN DEN VOI KHO LAPTOP" << endl;
    cout << "\033[31m\t#=================================================#" << endl;
    cout << "\033[31m\t|\033[33m                 CAC TINH NANG                   \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  1. Hien thi danh sach laptop trong kho         \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  2. Xoa laptop ra khoi kho                      \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  3. Them laptop moi vao kho                     \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  4. Sua thong tin laptop trong kho              \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  5. Sap xep laptop theo gia tien                \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  6. Tim kiem laptop                             \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  7. Tinh doanh thu va loi nhuan                 \033[31m|" << endl;
    cout << "\033[31m\t|\033[33m  8. Thoat                                       \033[31m|" << endl;
    cout << "\033[31m\t#=================================================#\033[0m" << endl;
}
int main() {
    Quanlikho qlk;
    qlk.DocFile();
    int choice;
    do {
        Menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
        {
            system("cls");
            int Choice1;
            do {
                system("cls");
                qlk.HienThiDanhSachLaptop();
                trolai();
                cin >> Choice1;
                switch (Choice1) {
                case 1:
                    qlk.xemthongtinchitietlaptop();
                    break;
                case 2:
                    system("cls");
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
                    break;
                }
            } while (Choice1 != 2);
        }
        break;
        case 2:
        {
            system("cls");
            int choice2;
            do {
                qlk.HienThiDanhSachLaptop();
                cout << endl;
                cout << "\033[31mCHI CHO PHEP XOA LAPTOP CO SO LUONG BANG 0.\033[0m" << endl;
                int STT3 = qlk.nhapSTT();
                system("cls");
                qlk.XoaLaptop(STT3);
                cout << "|----------------------------------------------|" << endl;
                cout << "|Ban co muon tiep tuc xoa laptop?              |" << endl;
                cout << "|1. Co                                         |" << endl;
                cout << "|2. Khong                                      |" << endl;
                cout << "|----------------------------------------------|" << endl << endl;
                cout << "Nhap lua chon cua ban: ";
                cin >> choice2;
                switch (choice2) {
                case 1:
                    system("cls");
                    cout << "\033[32mBan da chon tiep tuc xoa laptop.\033[0m" << endl << endl;
                    break;
                case 2:
                    system("cls");
                    cout << "\033[32mBan da quay lai menu chinh.\033[0m" << endl;
                    break;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le. Quay ve menu chinh." << endl;
                    break;
                }
            } while (choice2 != 2);
        }
        break;
        case 3:
        {
            laptop lt;
            system("cls");
            int choice3;
            do {
                lt.NhapThongTin();
                system("cls");
                cout << "---------------------------------------------" << endl;
                cout << "THONG TIN LAPTOP BAN MUON THEM:" << endl << endl;
                lt.XuatThongTinlaptop();
                cout << "---------------------------------------------" << endl;
                qlk.ThemLaptopMoiVaoKho(lt);
                cout << "---------------------------------------------" << endl;
                cout << "Ban co muon tiep tuc them laptop khong?" << endl;
                cout << "1. Co" << endl;
                cout << "2. Khong" << endl;
                cout << "Nhap lua chon cua ban: ";
                cin >> choice3;
                switch (choice3) {
                case 1:
                    system("cls");
                    cout << "Ban da chon tiep tuc them laptop moi." << endl;
                    cin.ignore();
                    break;
                case 2:
                    system("cls");
                    cout << "Ban da quay lai menu chinh." << endl;
                    break;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le. Quay ve menu chinh." << endl;
                    break;
                }
            } while (choice3 != 2);
        }
        break;
        case 4:
        {
            system("cls");
            int choice4;
            do {
                qlk.HienThiDanhSachLaptop();
                int STT6 = qlk.nhapSTT();
                system("cls");
                qlk.SuaThongTinLaptop(STT6);
                cout << "|-----------------------------------------|" << endl;
                cout << "|Ban co muon tiep tuc sua laptop khong?   |" << endl;
                cout << "|1. Co                                    |" << endl;
                cout << "|2. Khong                                 |" << endl;
                cout << "|-----------------------------------------|" << endl;
                cout << "Nhap lua chon cua ban: ";
                cin >> choice4;
                switch (choice4) {
                case 1:
                    system("cls");
                    cout << "Ban da chon tiep tuc sua laptop." << endl;
                    cin.ignore();
                    break;
                case 2:
                    system("cls");
                    cout << "Ban da quay lai menu chinh." << endl;
                    break;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le. Quay ve menu chinh." << endl;
                    break;
                }
            } while (choice4 != 2);
        }
        break;
        case 5:
        {
            system("cls");
            int choice5;
            cout << "|--------------------------------------------------|" << endl;
            cout << "|                 \033[31mCAC TUY CHON\033[0m                     |" << endl;
            cout << "|--------------------------------------------------|" << endl;
            cout << "|\033[32m1. Sap xep laptop theo gia tien tang dan.\033[0m         |" << endl;
            cout << "|\033[32m2. Sap xep laptop theo gia tien giam dan.\033[0m         |" << endl;
            cout << "|\033[32m3. Tro ve menu\033[0m                                    |" << endl;
            cout << "|--------------------------------------------------|" << endl << endl;
            cout << "Moi ban nhap lua chon (1, 2 hoac 3): ";
            cin >> choice5;
            switch (choice5) {
            case 1:
            {
                system("cls");
                qlk.SapXepLaptopTheoGiaTangDan();
                int Choice51;
                do {
                    qlk.HienThiDanhSachLaptop();
                    trolai();
                    cin >> Choice51;
                    switch (Choice51) {
                    case 1:
                        qlk.xemthongtinchitietlaptop();
                        break;
                    case 2:
                        system("cls");
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                } while (Choice51 != 2);
            }
            break;
            case 2:
            {
                system("cls");
                qlk.SapXepLaptopTheoGiaGiamDan();
                int Choice52;
                do {
                    qlk.HienThiDanhSachLaptop();
                    trolai();
                    cin >> Choice52;
                    switch (Choice52) {
                    case 1:
                        qlk.xemthongtinchitietlaptop();
                        break;
                    case 2:
                        system("cls");
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                } while (Choice52 != 2);
            }
            break;
            case 3:
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
        break;
        case 6:
        {
            system("cls");
            cout << "          \033[32mCAC TUY CHON\033[0m" << endl;
            cout << "|-----------------------------|" << endl;
            cout << "|\033[31m1. Tim kiem laptop theo hang \033[0m|" << endl;
            cout << "|\033[31m2. Tim kiem laptop theo CPU  \033[0m|" << endl;
            cout << "|\033[31m3. Tro lai menu chinh        \033[0m|" << endl;
            cout << "|-----------------------------|" << endl;
            cout << "Nhap lua chon cua ban: ";
            int lc6;
            cin >> lc6;
            switch (lc6) {
            case 1:
            {
                system("cls");
                cout << "\033[32mChon hang ban muon tim:\033[0m " << endl << endl;
                cout << "|-----------------------|" << endl;
                cout << "|1. Dell                |" << endl;
                cout << "|2. Asus                |" << endl;
                cout << "|3. HP                  |" << endl;
                cout << "|4. MSI                 |" << endl;
                cout << "|5. Lenovo              |" << endl;
                cout << "|6. Acer                |" << endl;
                cout << "|7. LG                  |" << endl;
                cout << "|-----------------------|" << endl;
                cout << "Moi ban nhap STT ung voi moi hang:  ";
                int hangChoice;
                cin >> hangChoice;
                string hang;
                switch (hangChoice) {
                case 1: hang = "Dell"; break;
                case 2: hang = "Asus"; break;
                case 3: hang = "HP"; break;
                case 4: hang = "MSI"; break;
                case 5: hang = "Lenovo"; break;
                case 6: hang = "Acer"; break;
                case 7: hang = "LG"; break;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le! Tro ve menu chinh" << endl;
                    break;
                }
                if (!hang.empty()) {
                    qlk.Loclaptoptheohang(hang);
                }
            }
            break;
            case 2:
            {
                system("cls");
                cout << "\033[32mChon loai CPU muon tim:\033[0m " << endl << endl;
                cout << "|-----------------------|" << endl;
                cout << "|1. i3                  |" << endl;
                cout << "|2. i5                  |" << endl;
                cout << "|3. i7                  |" << endl;
                cout << "|4. i9                  |" << endl;
                cout << "|5. Ryzen 7             |" << endl;
                cout << "|6. Ultra 9             |" << endl;
                cout << "|-----------------------|" << endl;
                cout << "Moi ban nhap STT ung voi moi loai CPU: ";
                int coreChoice;
                cin >> coreChoice;
                system("cls");
                string core;
                switch (coreChoice) {
                case 1: core = "i3"; break;
                case 2: core = "i5"; break;
                case 3: core = "i7"; break;
                case 4: core = "i9"; break;
                case 5:core = "Ryzen 7"; break;
                case 6:core = "Ultra 9"; break;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le! Tro ve menu chinh" << endl;
                    break;
                }
                if (!core.empty()) {
                    qlk.LocLaptopTheoCPU(core);
                }
            }
            break;
            case 3:
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
        break;
        case 7:
        {
            system("cls");
            double DT, LN, CP;
            double j;
            qlk.Hienthidanhsachlaptopnhapxuat();
            cout << endl << endl;
            cout << "|--------------------------------------------|" << endl;
            cout << "|           CAC TUY CHON                     |" << endl;
            cout << "|1. Tinh doanh thu va loi nhuan.             |" << endl;
            cout << "|2. Tro lai menu                             |" << endl;
            cout << "|--------------------------------------------|" << endl;
            cout << "Hay nhap lua chon cua ban (1 hoac 2): ";
            int choice7;
            cin >> choice7;
            cout << endl;
            switch (choice7) {
            case 1:
                DT = qlk.tinhdoanhthu();
                CP = qlk.tinhchiphi();
                LN = qlk.tinhloinhuan();
                cout << "|------------------------------------------|" << endl;
                cout << "|DOANH THU TU VIEC XUAT LAPTOP: " << DT << "          |" << endl;
                cout << "|CHI PHI TU VIEC NHAP LAPTOP: " << CP << "            |" << endl;
                cout << "|TONG LOI NHUAN: " << LN << "                         |" << endl;
                cout << "|------------------------------------------|" << endl << endl;
                cout << "\033[32mNhap 1 so bat ki de quay tro lai:\033[0m  ";
                cin >> j;
                system("cls");
                break;
            case 2:
                system("cls");
                break;
            }
        }
        break;
        case 8:
            system("cls");
            cout << "\033[31m                                                        oo               " << endl;
            cout << "                                                       o  o              " << endl;
            cout << "ooooooooo    ooooo    o       o       oooooo   ooooo  oooooo  ooooooooo  " << endl;
            cout << "    o       o     o   o o   o o       o     o    o    o           o      " << endl;
            cout << "    o      o       o  o  o o  o       o    o     o    o           o      " << endl;
            cout << "    o      o       o  o   o   o       ooooo      o    oooooo      o      " << endl;
            cout << "    o      ooooooooo  o   o   o       o    o     o    o           o      " << endl;
            cout << "    o      o       o  o       o       o     o    o    o           o      " << endl;
            cout << "    o      o       o  o       o       oooooo   ooooo  oooooo      o      " << endl;
            cout << "               o                                         o            \033[0m" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice < 8);
    return 0;
}
