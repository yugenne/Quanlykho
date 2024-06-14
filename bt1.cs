using System;

namespace MatrixMultiplicationExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Nhập kích thước của ma trận A
            Console.Write("Nhập số hàng của ma trận A (m): ");
            int m = int.Parse(Console.ReadLine());
            Console.Write("Nhập số cột của ma trận A (n): ");
            int n = int.Parse(Console.ReadLine());

            // Khởi tạo ma trận A
            double[,] A = new double[m, n];
            Console.WriteLine("Nhập các phần tử của ma trận A:");
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"A[{i + 1},{j + 1}] = ");
                    A[i, j] = double.Parse(Console.ReadLine());
                }
            }

            // Khởi tạo mảng B
            double[] B = new double[n];
            Console.WriteLine("Nhập các phần tử của mảng B:");
            for (int i = 0; i < n; i++)
            {
                Console.Write($"B[{i + 1},1] = ");
                B[i] = double.Parse(Console.ReadLine());
            }

            // Tính tích ma trận C = AB
            double[] C = new double[m];
            for (int i = 0; i < m; i++)
            {
                C[i] = 0;
                for (int j = 0; j < n; j++)
                {
                    C[i] += A[i, j] * B[j];
                }
            }

            // Xuất ma trận C ra màn hình
            Console.WriteLine("Ma trận C = AB là:");
            for (int i = 0; i < m; i++)
            {
                Console.WriteLine($"C[{i + 1},1] = {C[i]}");
            }
        }
    }
}
