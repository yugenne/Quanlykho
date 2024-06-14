using System;

namespace CotExample
{
    class Cot
    {
        // Các thuộc tính
        public string MaHieuCot { get; set; }
        protected double ChieuCao { get; set; }
        protected double ChieuRong { get; set; }
        protected double ChieuDai { get; set; }
        public double TheTich
        {
            get { return TinhTheTich(); }
        }

        // Hàm tạo mặc định
        public Cot()
        {
            MaHieuCot = "CH001";
            ChieuCao = 0;
            ChieuRong = 0;
            ChieuDai = 0;
        }

        // Hàm tạo với tham số
        public Cot(string maHieuCot, double chieuCao, double chieuRong, double chieuDai)
        {
            MaHieuCot = maHieuCot;
            ChieuCao = chieuCao;
            ChieuRong = chieuRong;
            ChieuDai = chieuDai;
        }

        // Phương thức thiết lập giá trị cho các thuộc tính kích thước
        public void SetKichThuoc(double chieuCao, double chieuRong, double chieuDai)
        {
            ChieuCao = chieuCao;
            ChieuRong = chieuRong;
            ChieuDai = chieuDai;
        }

        // Phương thức ảo tính thể tích
        public virtual double TinhTheTich()
        {
            return ChieuCao * ChieuRong * ChieuDai;
        }

        // Phương thức ảo xuất thông tin cột ra màn hình
        public virtual void XuatThongTin()
        {
            Console.WriteLine("Mã Hiệu Cột: " + MaHieuCot);
            Console.WriteLine("Chiều Cao: " + ChieuCao);
            Console.WriteLine("Chiều Rộng: " + ChieuRong);
            Console.WriteLine("Chiều Dài: " + ChieuDai);
            Console.WriteLine("Thể Tích: " + TheTich);
        }
    }

    class CotTron : Cot
    {
        // Thuộc tính riêng của CotTron
        private double DuongKinh { get; set; }

        // Hàm tạo với tham số
        public CotTron(string maHieuCot, double chieuCao, double duongKinh)
            : base(maHieuCot, chieuCao, duongKinh, duongKinh)
        {
            DuongKinh = duongKinh;
        }

        // Ghi đè phương thức tính thể tích
        public override double TinhTheTich()
        {
            return ChieuCao * Math.PI * (DuongKinh / 2) * (DuongKinh / 2);
        }

        // Ghi đè phương thức xuất thông tin cột ra màn hình
        public override void XuatThongTin()
        {
            Console.WriteLine("Mã Hiệu Cột: " + MaHieuCot);
            Console.WriteLine("Chiều Cao: " + ChieuCao);
            Console.WriteLine("Đường Kính: " + DuongKinh);
            Console.WriteLine("Thể Tích: " + TheTich);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Tạo ba đối tượng cột lớp Cot
            Cot[] cotList = new Cot[3];
            for (int i = 0; i < 3; i++)
            {
                cotList[i] = new Cot();
                Console.WriteLine($"Nhập thông tin cho cột thứ {i + 1}:");
                Console.Write("Mã Hiệu Cột: ");
                cotList[i].MaHieuCot = Console.ReadLine();
                Console.Write("Chiều Cao: ");
                double chieuCao = double.Parse(Console.ReadLine());
                Console.Write("Chiều Rộng: ");
                double chieuRong = double.Parse(Console.ReadLine());
                Console.Write("Chiều Dài: ");
                double chieuDai = double.Parse(Console.ReadLine());
                cotList[i].SetKichThuoc(chieuCao, chieuRong, chieuDai);
            }

            // Tạo đối tượng cột tròn
            Console.WriteLine("Nhập thông tin cho cột tròn:");
            Console.Write("Mã Hiệu Cột: ");
            string maHieuCotTron = Console.ReadLine();
            Console.Write("Chiều Cao: ");
            double chieuCaoCotTron = double.Parse(Console.ReadLine());
            Console.Write("Đường Kính: ");
            double duongKinhCotTron = double.Parse(Console.ReadLine());
            CotTron cotTron = new CotTron(maHieuCotTron, chieuCaoCotTron, duongKinhCotTron);

            // In ra thông tin của 4 cột đã tạo
            Console.WriteLine("\nThông tin các cột:");
            for (int i = 0; i < 3; i++)
            {
                cotList[i].XuatThongTin();
                Console.WriteLine();
            }
            cotTron.XuatThongTin();
        }
    }
}
